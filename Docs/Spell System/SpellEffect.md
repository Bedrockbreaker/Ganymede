---
aliases:
  - Spell Effect
  - UGSpellEffect
tags:
  - TODO
  - design
  - spell_system
---
# Spell Effect

`UGSpellEffect` is really just a wrapper around Unreal's own Gameplay Effects, and can only perform the same actions they can (applying tags). However, that doesn't mean these are weak by any means:

- Force the target to activate an ability (think involuntary knockback)
- Change the targets attributes and status effects (`Status.Stunned` or `Data.Damage` with a value of 20)
- Spawn Gameplay Cues for VFX and SFX

```cpp
class UGSpellEffect : UGameplayEffect
{
	
}
```

## Interaction with Spell Mappings

