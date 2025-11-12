---
aliases:
  - Spell Mapping
  - FGSpellMapping
  - Spell Mappings
tags:
  - TODO
  - spell_system
  - design
  - programming
---
# Spell Mapping

`FGSpellMapping` is a lightweight "glue" that allows modifying the data a [`UGSpellDelivery`](./SpellDelivery.md) produces, and then plugging those values into a [`UGSpellEffect`](./SpellEffect.md).

```cpp
enum class EGSpellMappingType : uint8
{
	Direct,
	Linear,
	Inverse,
	Curve,
	Custom
}

class FGSpellMapping
{
public:
	FGameplayTag TagIn;
	FGameplayTag TagOut;
	EGSpellMappingType Type = EGSpellMappingType::Direct;
	float TransformScale = 1.0f;
	float TransformOffset = 0.0f;
	float TransformInverseOffset = 0.0f;
	TSoftObjectPtr<UCurveFloat> TransformCurve;
	TSoftObjectPtr<UGSpellValueCalculation> TransformCalculation;
}
```

The `EGSpellMappingType` specified controls how values are transformed from the delivery into the effect:

| Type      | Description                                                     | Example                                                                               | Parameters                                                                                                              |
| --------- | --------------------------------------------------------------- | ------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| `Direct`  | Directly maps the output value to the input.                    | `DeliveryLocation`<br>-><br>`TeleportLocation`                                        | N/A                                                                                                                     |
| `Linear`  | Performs a linear transformation ($mx+b$) on the input.         | `NumTargets`<br>-><br>$1.5\cdot\text{NumTargets}+0$<br>-><br>`FuseTime`               | `m`: Scale the input by this amount first.<br>`b`: Add this to the scaled amount.                                       |
| `Inverse` | Performs an inverse transformation (`1/(mx+b)+c`) on the input. | `SphereRadius`<br>-><br>$\frac{1}{0.5\cdot\text{SphereRadius}+1}+5$<br>-><br>`Damage` | `m`: Scale the input by this amount first.<br>`b`: Add this to the scaled amount.<br>`c`: Add this to the final result. |
| `Curve`   | Allows passing in a Float Curve for transformation              | `DistanceTravelled`<br>-><br>*designer noises*<br>-><br>`ManaBurn`                    | `Curve`: Maps the input using the provided float curve.                                                                 |
| `Custom`  | In case the other options aren't enough.                        | --                                                                                    | `Spell Value Calculation`: Maps the input, with the full delivery context and optional per-target actor as parameters.  |

## Editor Visualization

These structs have their own Slate rendering, via an Editor module that registers a custom property type layout.

**GENERATED WITH AI, DO NOT TRUST.**

### 🧩 Step 1 — Create an `IPropertyTypeCustomization` for `FGSpellMapping`

You’ll need a module (typically `Editor` or `EditorWidgets`) and register it in its `StartupModule()` via:

```cpp
FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
PropertyModule.RegisterCustomPropertyTypeLayout(
    "GSpellMapping",
    FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FGSpellMappingCustomization::MakeInstance)
);
```

Then, in your customizer:

```cpp
class FGSpellMappingCustomization : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance() { return MakeShareable(new FGSpellMappingCustomization()); }

    virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, 
                                 IPropertyTypeCustomizationUtils& CustomizationUtils) override;
    
    virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& ChildBuilder,
                                   IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
    TSharedPtr<IPropertyHandle> TagInHandle;
    TSharedPtr<IPropertyHandle> TagOutHandle;
    TSharedPtr<IPropertyHandle> MappingTypeHandle;
};
```

---

### 🪄 Step 2 — Build dynamic UI logic (the “renderer” part)

Inside `CustomizeChildren`, you can dynamically show/hide properties or replace them entirely with custom Slate widgets:

```cpp
void FGSpellMappingCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructHandle, IDetailChildrenBuilder& Builder,
                                                    IPropertyTypeCustomizationUtils& Utils)
{
    TagInHandle = StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGSpellMapping, TagIn));
    TagOutHandle = StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGSpellMapping, TagOut));
    MappingTypeHandle = StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FGSpellMapping, MappingType));

    // Draw a row for MappingType
    Builder.AddProperty(MappingTypeHandle.ToSharedRef());

    // Create a custom section depending on the selected type
    uint8 CurrentTypeValue = 0;
    MappingTypeHandle->GetValue(CurrentTypeValue);
    const auto MappingType = static_cast<EGSpellMappingType>(CurrentTypeValue);

    switch (MappingType)
    {
        case EGSpellMappingType::Direct:
            // Just show tag connections
            Builder.AddProperty(TagInHandle.ToSharedRef());
            Builder.AddProperty(TagOutHandle.ToSharedRef());
            break;
        case EGSpellMappingType::Linear:
            Builder.AddCustomRow(FText::FromString("Linear Params"))
            .NameContent()[ SNew(STextBlock).Text(FText::FromString("Linear Parameters")) ]
            .ValueContent()[
                SNew(SHorizontalBox)
                +SHorizontalBox::Slot()
                [ Builder.GenerateStructValueWidget(StructHandle->GetChildHandle("LinearParams").ToSharedRef()) ]
            ];
            break;
        // … etc for Curve, Custom
    }
}
```

You can also use **`MappingTypeHandle->SetOnPropertyValueChanged`** to force a UI refresh when the enum changes, so designers see the new controls immediately.

---

### 🧠 Step 3 — The dropdowns for `TagIn` / `TagOut`

This is where it gets fun: you can replace those fields with your own **SComboBox** or **STextComboBox**.

When building, you’d pull your tag list dynamically:

- For `TagIn`:  
    Ask the currently selected `UGSpellDelivery` class (via your parent `FGSpellSpec`) for its available output tags.
    
- For `TagOut`:  
    Aggregate all selected `UGSpellEffect` classes’ input tags.
    

You can access parent context via:

```cpp
TArray<UObject*> OuterObjects;
StructHandle->GetOuterObjects(OuterObjects);
```

Then from those, find your `FGSpellSpec`, get its Delivery/Effects, and query their tag lists.

Example snippet for a tag dropdown:

```cpp
Builder.AddCustomRow(FText::FromString("Tag In"))
.NameContent()[ StructHandle->CreatePropertyNameWidget(FText::FromString("Tag In")) ]
.ValueContent()[
    SNew(SComboBox<TSharedPtr<FName>>)
    .OptionsSource(&AvailableTags)
    .OnGenerateWidget_Lambda([](TSharedPtr<FName> Item) {
        return SNew(STextBlock).Text(FText::FromName(*Item));
    })
    .OnSelectionChanged_Lambda([this](TSharedPtr<FName> NewSelection, ESelectInfo::Type) {
        TagInHandle->SetValue(*NewSelection);
    })
    .Content()[ SNew(STextBlock).Text_Lambda([this] {
        FName Current;
        TagInHandle->GetValue(Current);
        return FText::FromName(Current);
    }) ]
];
```

---

### ⚙️ Step 4 — Handling custom data per mapping type

For your “Linear”, “Inverse”, etc., you have two nice options:

- Add nested structs like `FLinearMappingParams` and show them conditionally.
    
- Or build custom rows with fields for “m” and “b” directly via Slate (using `NumericEntryBox<float>`).
    

Example of a float entry:

```cpp
SNew(SNumericEntryBox<float>)
.MinValue(-10.f)
.MaxValue(10.f)
.Value(this, &FGSpellMappingCustomization::GetLinearM)
.OnValueCommitted(this, &FGSpellMappingCustomization::OnLinearMCommitted);
```

---

### 🎨 Step 5 — Optional: Inline Layout Polish

You can totally put your TagIn → TagOut mapping on one row:

```cpp
Builder.AddCustomRow(FText::FromString("Mapping"))
[
    SNew(SHorizontalBox)
    + SHorizontalBox::Slot()
    [ /* TagIn dropdown */ ]
    + SHorizontalBox::Slot()
    [ SNew(STextBlock).Text(FText::FromString("→")) ]
    + SHorizontalBox::Slot()
    [ /* TagOut dropdown */ ]
];
```

---

### TL;DR – You’ll need:

|Feature|Tool|
|---|---|
|Custom UI for struct|`IPropertyTypeCustomization`|
|Hide/show depending on enum|Dynamic widget building + `SetOnPropertyValueChanged`|
|Custom dropdowns|`SComboBox` with dynamic list|
|Nested fields (like m, b)|Custom Slate rows or child struct properties|
|Context awareness (deliveries/effects)|`GetOuterObjects()` from handle|
