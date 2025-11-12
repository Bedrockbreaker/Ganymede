---
aliases:
 - Blink Anchor2
tags:
  - TODO
---
# Blink Anchor2

**Purpose**: Controlled repositioning and flag-running tool. Powerful for flag steals or feints, but mana-intensive and punishable if chased.

**Cost**: 40 Mana (initial) / X Mana (on recall)

**Constants**:
- `Tag` Spell.Constants.BlackboardTag1 = "Spell.Delivery.Anchor.Location"
- `Tag` Spell.Constants.BlackboardTag2 = "Spell.Delivery.Anchor.LookDirection"
- `Tag` Spell.Constants.BlackboardTag3 = "Spell.Calculated.Distance"
- `Tag` Spell.Constants.BlackboardTag4 = "Spell.Calculated.bRequirementsMet"
- `float` Spell.Constants.MaximumDistance = 4000.0f
- `TagContainer` Spell.Constants.TagsBlocked = { "Status.ChaosState" }
- `Tag` Spell.Constants.BlackboardTag5 = "Spell.Calculated.bFailure"
- `bool` Spell.Constants.bSweep = false
- `FVector` Spell.Constants.Offset = { 0.0f, 0.0f, 0.0f }
- `float` Spell.Constants.ManaDrain = 0.0333f // Mana cost per cm, ~=3.33 mana/m
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to anchor asset>
- `float` Spell.Constants.Lifetime = -1.0f
- `float` Spell.Constants.Health = 100.0f
- `float` Spell.Constants.ManaCost = 40.0f
- `Tag` Spell.Constants.BlackboardTag6 = "Spell.Delivery.Anchor.Actor"
- `SoftPtr` Spell.Constants.Sound = \<soft reference to failure sound>

## PrimaryRoot

**Delivery**: Anchor
- **Type**: Instant
- **Inputs**:
	- `ActorHandle` Spell.Delivery.Anchor.Owner
- **Behavior**
	- OnStart
		1. If Actor Blackboard has Spell.Delivery.Anchor.Actor
			1. AddOutput `ActorHandle` Spell.Delivery.Anchor.Actor
			2. AddOutput `FVector` Spell.Delivery.Anchor.Location
			3. AddOutput `FVector` Spell.Delivery.Anchor.LookDirection
			4. AddCallback Spell.Delivery.Success
		2. else
			1. AddCallback Spell.Delivery.Failure

**Effects**:
1. Spell.Delivery.Success
	1. BlackboardWriteVector
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Delivery.Anchor.Location
		- `FVector` Spell.Effect.BlackboardWrite.Vector
	2. BlackboardWriteVector
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Delivery.Anchor.LookDirection
		- `FVector` Spel.Effect.BlackboardWrite.Vector
	3. BlackboardWriteFloat
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Calculated.Distance
		- `float` Spel.Effect.BlackboardWrite.Float
	4. BlackboardWriteBool
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Calculated.bRequirementsMet
		- `bool` Spell.Effect.BlackboardWrite.Bool // If within maximum distance && caster does not have Status.ChaosState
2. Spell.Delivery.Failure
	1. ManaBurn
		- `ActorHandle` Spell.Effect.ManaBurn.Target
		- `float` Spell.Effect.ManaBurn.Magnitude
	2. BlackboardWriteBool
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Calculated.bFailure
		- `bool` Spell.Effect.BlackboardWrite.Bool

**Mappings**:
- Spell.Context.Caster -> Spell.Delivery.Anchor.Owner
1. Spell.Delivery.Success
	- Spell.Context.SpellBlackboard -\[0]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag1 -\[0]> Spell.Effect.BlackboardWrite.Tag
	- Spell.Delivery.Anchor.Location -\[0]> Spell.Effect.BlackboardWrite.Vector
	- Spell.Context.SpellBlackboard -\[1]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag2 -\[1]> Spell.Effect.BlackboardWrite.Tag
	- Spell.Delivery.Anchor.LookDireciton -\[1]> Spell.Effect.BlackboardWrite.Vector
	- Spell.Context.SpellBlackboard -\[2]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag3 -\[2]> Spell.Effect.BlackboardWrite.Tag
	- Spell.Context.CasterLocation,
	  Spell.Delivery.GetAnchor.Location -> Distance(a, b) -\[2]> Spell.Effect.BlackboardWrite.Float
	- Spell.Context.SpellBlackboard -\[3]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag4 -\[3]> Spell.Effect.BlackboardWrite.Tag
	- Blackboard, Outputs -> CustomFunction(Spell.Calculated.Distance <= Spell.Constants.MaximumDistance && Spell.Context.CasterTags.HasNone(Spell.Constants.TagsBlocked)) -\[3]> Spell.Effect.BlackboardWrite.Bool
2. Spell.Delivery.Failure
	- Spell.Context.Caster -> Spell.Effect.ManaBurn.Target
	- Spell.Context.ManaCost -> Spell.Effect.ManaBurn.Magnitude
	- Spell.Constants.BlackboardTag5 -\[1]> Spell.Effect.BlackboardWrite.Tag
	- (default: false) -\[1]> Spell.Effect.BlackboardWrite.Bool

**Transitions**:
1. Spell.Calculated.bRequirementsMet (implicit exists) -> Teleport
2. Spell.Calculated.bFailure (implicit exists) -> CreateAnchor
3. !Spell.Calculated.bRequirementsMet (implicit exists) -> TeleportFailed

## Teleport

**Delivery**: Instant
- **Type**: Instant
- **Inputs**: N/A
- **Behavior**
	- OnStart
		1. AddCallback Spell.Delivery.Success

**Effects**:
1. Spell.Delivery.Success
	1. Teleport
		- `ActorHandle` Spell.Effect.Teleport.Target
		- `FVector` Spell.Effect.Teleport.Location
		- `FVector` Spell.Effect.Teleport.LookDirection
		- `bool` Spell.Effect.Teleport.bSweep
		- // KAMO: Spell.Effect.Teleport.bSnapToGround
	2. SetVelocity
		- `ActorHandle` Spell.Effect.SetVelocity.Target
		- `FVector` Spell.Effect.SetVelocity.InVelocity
	3. ManaBurn
		- `ActorHandle` Spell.Effect.ManaBurn.Target
		- `float` Spell.Effect.ManaBurn.Magnitude
	4. Kill
		- `ActorHandle` Spell.Effect.Kill.Target

**Mappings**:
1. Spell.Delivery.Success
	- Spell.Context.Caster -> Spell.Effect.Teleport.Target
	- Spell.Delivery.Anchor.Location -> Spell.Effect.Teleport.Location
	- Spell.Delivery.Anchor.LookDirection -> Spell.Effect.Teleport.LookDirection
	- Spell.Constants.bSweep -> Spell.Effect.Teleport.bSweep
	- Spell.Context.Caster -> Spell.Effect.SetVelocity.Target
	- Spell.Constants.Offset -> Spell.Effect.SetVelocity.InVelocity
	- Spell.Context.Caster -> Spell.Effect.ManaBurn.Target
	- Spell.Constants.ManaDrain,
	  Spell.Calculated.Distance -> x * y -> Spell.Effect.ManaBurn.Magnitude
	- Spell.Delivery.Anchor.Actor -> Spell.Effect.Kill.Target

**Transitions**: N/A

## CreateAnchor

**Delivery**: CreateAnchor (derived from SpellInstance)
- **Type**: Instant
- **Inputs**:
	- `SoftPtr` Spell.Delivery.CreateAnchor.Asset
	- `FVector` Spell.Delivery.CreateAnchor.Location
	- `FVector` Spell.Delivery.CreateAnchor.LookDirection
	- `float` Spell.Delivery.CreateAnchor.Lifetime
	- `float` Spell.Delivery.CreateAnchor.Health
- **Behavior**
	- OnStart
		1. AddOutput `ActorHandle` Spell.Delivery.CreateAnchor.Asset
		2. AddCallback Spell.Delivery.Success
	- OnOwnerDestroyed
		1. AddCallback Spell.Delivery.Instance.OwnerDestroyed
	- OnDestroyed
		1. AddCallback Spell.Delivery.Instance.Destroyed

**Effects**:
1. Spell.Delivery.Success
	1. ManaBurn
		- `ActorHandle` Spell.Effect.ManaBurn.Target
		- `float` Spell.Effect.ManaBurn.Magnitude
	2. BlackboardWriteActor
		- `int` Spell.Effect.BlackboardWrite.Level // Actor Blackboard
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Delivery.Anchor.Actor
		- `ActorHandle` Spell.Effect.BlackboardWrite.Actor
2. Spell.Delivery.Instance.OwnerDestroyed
	1. Kill
		- `ActorHandle` Spell.Effect.Kill.Target
3. Spell.Delivery.Instance.Destroyed
	1. BlackboardClear
		- `int` Spell.Effect.BlackboardClear.Level // Actor Blackboard
		- `Tag` Spell.Effect.BlackboardClear.Tag // Spell.Delivery.Anchor.Actor

**Mappings**:
- Spell.Constants.SummonedActor -> Spell.Delivery.CreateAnchor.Asset
- Spell.Context.CasterLocation -> Spell.Delivery.CreateAnchor.Location
- Spell.Context.CasterLookDirection -> Spell.Delivery.CreateAnchor.LookDirection
- Spell.Constants.Lifetime -> Spell.Delivery.CreateAnchor.Lifetime
- Spell.Constants.Health -> Spell.Delivery.CreateAnchor.Health
1. Spell.Delivery.Success
	- Spell.Context.Caster -> Spell.Effect.ManaBurn.Target
	- Spell.Constants.ManaCost -> Spell.Effect.ManaBurn.Magnitude
	- Spell.Context.ActorBlackboard -> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag6 -> Spell.Effect.BlackboardWrite.Tag
	- Spell.Delivery.CreateAnchor.Actor -> Spell.Effect.BlackboardWrite.Actor
2. Spell.Delivery.Instance.OwnerDestroyed
	- Spell.Delivery.Anchor.Actor -> Spell.Effect.Kill.Target
3. Spell.Delivery.Instance.Destroyed
	- Spell.Context.ActorBlackboard -> Spell.Effect.BlackboardClear.Level
	- Spell.Constants.BlackboardTag6 -> Spell.Effect.BlackboardClear.Tag

**Transitions**: N/A

## TeleportFailed

**Delivery**: Instant
- **Type**: Instant
- **Inputs**: N/A
- **Behavior**
	- OnStart
		1. AddCallback Spell.Delivery.Success

**Effects**:
1. Spell.Delivery.Success
	1. PlayClientSound
		- `SoftPtr` Spell.Effect.PlayClientSound.Asset

**Mappings**:
1. Spell.Delivery.Success
	- Spell.Constants.Sound -> Spell.Effect.PlayClientSound.Asset

**Transitions**: N/A

## SecondaryRoot

**Delivery**: Anchor
- **Type**: Instant
- **Inputs**:
	- `ActorHandle` Spell.Delivery.Anchor.Owner
- **Behavior**
	- OnStart
		1. If Actor Blackboard has Spell.Delivery.Anchor.Actor
			1. AddOutput `ActorHandle` Spell.Delivery.Anchor.Actor
			2. AddOutput `FVector` Spell.Delivery.Anchor.Location
			3. AddOutput `FVector` Spell.Delivery.Anchor.LookDirection
			4. AddCallback Spell.Delivery.Success
		2. else
			1. AddCallback Spell.Delivery.Failure

**Effects**:
1. Spell.Delivery.Success
	1. Kill
		- `ActorHandle` Spell.Effect.Kill.Target
2. Spell.Delivery.Failure
	1. PlayClientSound
		- `SoftPtr` Spell.Effect.PlayClientSound.Asset

**Mappings**:
- Spell.Context.Caster -> Spell.Delivery.Anchor.Owner
1. Spell.Delivery.Success
	- Spell.Delivery.Anchor.Actor -> Spell.Effect.Kill.Target
2. Spell.Delivery.Failure
	- Spell.Constants.Sound -> Spell.Effect.PlayClientSound.Asset

**Transitions**: N/A
