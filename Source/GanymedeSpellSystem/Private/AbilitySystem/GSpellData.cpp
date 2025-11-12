// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GSpellData.h"

#include "AbilitySystem/GSpellSpec.h"

FGSpellSpec UGSpellData::MakeSpellSpec() const
{
	FGSpellSpec Spec;
	Spec.Name = Name;
	Spec.GameplayCueTags = GameplayCueTags;
	Spec.DeliveryMechanism = DeliveryMechanism;
	Spec.SpellEffects = SpellEffects;
	Spec.ContextMappings = ContextMappings;
	return Spec;
}
