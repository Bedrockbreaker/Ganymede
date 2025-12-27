---
aliases:
  - GDD
  - Game Design Document
tags:
  - TODO
---
# Ganymede - GDD

> Copyright ©️ 2024-2026 Bedrockbreaker. All Rights Reserved.

*High-tech blood magic.*

---

## Game Overview

### Summary

Ganymede is all about strategy, tactics, and control. The better a team can work together to execute a tactical plan, the better they'll perform. Controlling the battlefield is both an exercise in outmaneuvering your opponents, as well as understanding the details of moment-to-moment combat. Every decision from loadout tuning to mid-fight spellcasting should carry risk. Trading off health for mana is a key part of this risk assessment, where health will be consumed if a spell costs too much, trading tempo for advantage.

Many of the sections in the overview outline and allude to various design elements or systems, which are then explained in more detail in their respective section later. There will be some repeated information, particularly the most important details. See also the terminology section in the appendix at the end of this document.

### Genre

First person, sci-fi tactics shooter, with an initial focus on capture the flag gameplay to emphasize the tactics in its design.

After beta testing completes for CTF, work will shift toward additional gameplay modes, inspired by early entries in the Halo and Unreal Tournament series:

- Deathmatch / Team Deathmatch
- King of the Hill
- Last Man Standing / Assassin
- Push-the-Objective / Siege
- Mutant / Infection
- Gun Game
- Hot Potato
- Prop Hunt
- etc.

This is not a promise of modes that will be implemented, nor necessarily an exhaustive list. The primary goal of Ganymede is emphasize tactical thinking and well-executed strategies, which some of these modes as seen in other games work against. Specific deviations in their original designs (or outright removal from the game design) will need to be considered.

Additionally, an offline campaign mode will be considered alongside these additional modes, as the story and worldbuilding would be able to support such a feature.

### Similar Titles

There's no one game that neatly overlaps with everything Ganymede is attempting. Instead, it sits at the intersection of several design traditions, and thinking of similar titles in terms of design lineage rather than straight genre is a more useful analysis here.

1. Tactical/Ability-Driven FPS

These titles mix gunplay with build expression and tactical timing:

**Destiny 2** - Not because of its loot or MMO structure, but because its subclass tuning and ability economy mirror what Ganymede is doing with spell modulations. Players mentally track cooldown states, resource tradeoffs, and tempo windows.

**Valorant** - Primarily a shooter, but its emphasis on composition, pre-round planning, and "economic rhythm" maps well to Ganymede's mana/health resource trade. The idea of committing resources for tempo advantage is structurally similar.

**The Finals** - Not in tone or theme, but because it emphasizes player-driven builds assembled from modular ability pieces, which create emergent tactics.

2. Arena Shooters With Strong Mobility + Macro Layer

Ganymede's CTF-first approach and older-shooter inspirations intentionally lean in this direction.

**Halo CE/Halo 2** - Particularly in the interplay of shield/health pacing and alternating safe/danger zones. The risk of mana burn is reminiscent of Halo's shield system, except more systemic and player-controlled.

**Unreal Tournament 2004** - Specifically the way weapons had alt-fires that altered range/tempo. Loadout optimization and tuning in Ganymede is partially derived from UT's ability to modulate playstyle through weapon mastery.

3. Ability-Centric, Build-Driven Hybrids

Games that use resource tradeoffs or flexible loadouts.

**GunZ: The Duel** - Not thematically comparable, but it's a prime example of a shooter where the player self-inflicts vulnerability to gain tempo. The game's "K-style" movement tech gives an interesting analog to Ganymede -- players voluntarily damage themselves (fall cancels, guard breaks) to increase mobility and pace.

**Magicka/Mages of Mystralia** - For modular spellcraft specifically. Obviously not shooter games, but very few games do spell parameter tuning at this granularity. Magicka also murders the player as a natural consequence of miscasting, which is tonally similar to Ganymede's mana burn mechanic.

4. Aesthetic Parallels

Not mechanical matches, but in terms of the look and feel of Ganymede. They don't connect to the gameplay in any way, but they do help to provide anchors to the tone and worldbuilding.

**Halo 3** - The Forerunner ruin aesthetic (grimy, gritty sci-fi).

**The Irregular at Magic High School** - For its modernized magic with technical framing.

**Portal 2** - Overgrown industrial structures that contribute to environmental decay.

**Shadowrun** - It's not a coherent, combined mix of sci-fi and magic, but has a similar philosophical core where major powers monetize and militarize the use of magic, but Ganymede removes the social layer in the narrative.

### Platform

Ganymede is designed for both PC (Windows, Linux), as well as consoles (PS5, Xbox Series S | X). This means use of a kernel-level anti-cheat will not be considered to maintain Linux compatibility (allowing play on the Steam Deck as well).

The minimum target specs would be the steam deck: 1280x800p @ 60 FPS on low quality settings.

While the game on recommended hardware is designed to take advantage of its modern hardware capabilities (ray tracing, TAA, HDR), these will not be critical to the gameplay.

Consumers with next-gen hardware (PC enthusiasts, owners of the currently mythical PS6) would be able to enjoy the game on its highest settings with minimal reduction in resolution or frame rate: 4K @ 60 FPS on highest quality.

Essentially, the game is built with only current modern hardware capabilities in mind, and is not trying to guess and use theoretical capabilities of hardware in the future.

### Key Selling Points

1. Risk-For-Tempo Combat Loop

The mana/health trade system ("mana burn") is the number one thing that sets Ganymede apart. It's a crisp, demonstrable hook that frames the game as a place where decision making is as lethal as the bullets themselves.

- Casting spells drains mana; when empty, it carves directly from health instead.
- Entering mana-burn creates a fragile but high-output state.
- Skilled play involves intentionally operating at low health to secure tempo advantages (faster assault, interception, or escape).

2. Customizable Spell Crafting

Instead of fixed weapon categories, players are able to build their own offensive toolkit. All players will be given a default loadout upon first startup, but are heavily encourage to experiment (particularly if they want to be competitive).

- Ability to tune damage, projectile behavior, spread, charge, cooldown, mana cost, and other factors of a spell.
- Players can optimize around their own personal style (burst, control, suppression, mobility, skirmishing, etc.).
- Loadout building becomes a pre-match mind game and mid-match identity.
- This also ensures a high skill ceiling and theorycrafting longevity.

3. Team-Oriented Tactical Objectives

Capture the flag is emphasized first for very particular reasons. The game's goal is for players to "outthink" more than they "outshoot."

- CTF exposes mana burn better than deathmatch.
- It forces role differentiation where no roles were explicitly created to begin with (runner, support, disruptor, anchor, etc.).
- Build synergy becomes more valuable than raw aim, particularly as a match progresses and character progression occurs.
- Decision clarity is easily understand by both casuals and competitive players.

4. High-Skill Sandbox with Classic Shooter DNA

Ganymede pulls from older titles, but structurally and not nostalgically. The noise of modern ability/hero shooters is removed here.

- Predictable projectile behavior instead of hyper-assist hit scan.
- Emphasis on map control, movement, and encounter pacing.
- No hero shooter "ultimates" or slot-locked roles; builds emerge from player choices.

5. A Sci-Fi Arcane Aesthetic

Other shooters typically fall into one of two camps: historical or far-future. While Ganymede does utilize the sci-fi aesthetic, the addition of magic into its setting is notably unique and would be easy to create recognizable brand style and merchandising identity for.

- Gritty industrial sci-fi reminiscent of early-2000s shooters.
- Crossed with modern arcane-tech sensibilities.
- Overgrown, reclaimed environments to ground the world's decay.

### Target Audience

**Primary Audience**: Competitive Strategy-Minded FPS Players

These are the Halo, Valorant, and early Destiny players who care about resource management, tempo plays, team coordination, build identity, and map control. They appreciate the mechanics that reward knowledge and discipline rather than just twitch reactions.

**Secondary Audience**: "Theorycrafters"

Players who enjoy tuning builds, discovering breakpoints, debating spell parameters, or creating meta-optimizing tools or spreadsheets. These players become unofficial evangelists, and would be able to generate the meta discussion that keeps Ganymede viable. They're also likely to be some of the loudest players and the most sensitive to systems/balance changes. Theorycrafting playtesters would be essential throughout development.

**Tertiary Audience**: Arena Shooter Veterans

People who group with UT99/2004, Halo 2/3, or Quake Live. They want readable combat, movement agency, and fewer random variables. Ganymede's design ethos would be generally consistent with their wants, even though it modernizes the formula.

**Adjacent Audience**: Fantasy-Sci-Fi Hybrid Fans

These aren't strictly FPS fans. They're instead drawn in by spell-guns, arcane technology, and the game's worldbuilding. This does significantly matter for transmedia or long-tail engagement, even if they're not the core competitive audience (In fact, the main designer of Ganymede would consider themself primarily part of this group.).

## Core Gameplay Mechanics

### Core Loop

On the broadest scale, the long-term loop in Ganymede is the skill progression a player goes through in learning and utilizing its mechanics. This includes tuning loadouts, responding to metas, gaining elo, improving their statistics over time, etc. Over many months, players can become recognized for "that weird low-health overcast trapper build" or "the zero-mana duelist kit designed by player X". Instead of relying on shallow progression mechanics (battle passes, XP grinding, etc.), the modular spell system is leveraged to create a social progression, rather than numerical. Players will also be able to share their builds with others. Notably, any form of XP/battlepass/cosmetic grinding has no part in Ganymede's design. Many of the engagement loops found in modern shooters like this are mechanically shallow, and mostly exist to drive engagement. While that's not inherently a bad thing, this does behave antithetically to the older-shooter inspirations of Ganymede. Rather, the game relies on mastery, community, and meta-strategy for its long-term engagement.

In the mid-long term, players are able to unlock new spell components they can tinker around with. To avoid option fatigue, players are given a relatively narrow set of spell components to use at the start of the game. By mastering specific skill-based achievements, they slowly unlock additional components. The number of combinations explodes exponentially with more options, but given the player's growing comfort with the mechanics, the slower unlocking allows them to ease into making more discerning choices. In non-ranked gameplay, all options are available to players from the beginning, to avoid high-ranking players from creating a positive feedback loop where the good players gatekeep the newer players.

The mid-term loop drops to a more simplistic representation of an individual gaming session with multiple matches. There is no explicit reward at this level of the loop. While there very much could be an addition of daily quests at this level, that would require the addition of a longer-term XP loop, which Ganymede is specifically designed to avoid, as mentioned.

The short-term loop is defined within a match, and encompasses all the micro-decisions during the moment-to-moment. "Should I rush or hold my position?" "Can I grab that pickup in time?" "How do I respond to this sudden suppression fire?" etc. These decisions slowly build up over time to inform the long-term strategies and tactics of whole teams, which are then refined over team to create and shape metas, theories, and the community as a whole.

### Key Mechanics

The two most important mechanics of Ganymede are mana burn and modular spells.

When a player attempts to cast a spell they don't have enough mana for, the remaining cost is consumed from their health. This puts them in a mana burned state, which reduces their mana regen, and forces all spells to exclusively use health until their mana fully regenerates. Players are fully capable of killing themselves if not careful. This can provide opportunities to trade advantage for tempo, creating a high-lethality decision economy. Notably, passive health regen does not occur. This means decisions to burn health are otherwise permanent (at least, until they respawn), and leave a lasting impact on the strategy of the match.

Modular spells are designed to support the build creation, theorycrafting, and loadout flexibility. Spells are composed of a series of "modules," where each module has a specific delivery mechanism and a variety of effects. For example, a fireball-type spell can be made out of two modules: one with a projectile delivery, and another with an instantaneous delivery and explosion effect. Each module has a list of tunable parameters (projectile velocity, damage, etc.), and players are heavily encourage to explore their options. No explicit character classes are given by the system. Rather, players are supposed to communicate with their team to identify their own role, and create a build accordingly. Players can save "blueprints" of their loadouts for easy editing and retrieval.

Everything else is ancillary and exists to support these mechanics.

### Objectives & Goals

For many players, their ultimate goal in Ganymede would be to become a "global champion" of sorts -- become the highest skilled competitive player.

However, there exist many smaller and intermediate goals, and not every player wants to be competitively ranked either. The mid-long-term goal is unlock all modular spell components and complete all achievements. For theorycrafters, their goal is to continually evolve the game's metas and refine or create new builds. Others would likely find solace in meeting new people and gaining friends through the teams they form.

Beyond the intrinsic goals of players, the objective for any individual capture the flag match in Ganymede is to win a best 2 out of 3 rounds, which are 12 minutes long each. Winning a round involves scoring more flag captures than the opposing team at the end of the 12 minutes. Each team has a flag in their base, which the enemy team will pick up and bring back to their home base to capture. A player's own flag and teammates are always highlighted and visible through walls via marker dots in the UI layer. Once a flag is picked up, an announcement is made to all players, and the corresponding team is always aware of its location (and consequently the enemy flag carrier) due to its location marker. The flag carrier is unable to use spells while carrying the flag, and needs to rely on their teammates for defense. Once a flag is captured, the flag respawns back in the enemy base and can be immediately picked up again. To prevent a flag capture, players need to adequately defend their flag or kill the flag carrier before they make it back to their base to capture the flag. The flag is dropped by the flag carrier's corpse when they're killed, and one of the flag's team members needs to stand by the flag for a small duration of time to instantly teleport it back to their base. In the meantime, the flag is still vulnerable to being picked up again by the enemy team.

Using a time limit for matches is intended rather than first-to-X captures to avoid early wins leading to turtling strategies in the endgame (Although this does lead to alternate turtling strategies, it would be better to avoid the former rather than the latter.). In the case of a tie at the end of a round, whichever team had the shortest average pickup-to-capture time wins. If neither team has any captures (or somehow both teams have the exact same average time), the round goes into overtime and respawn timers slowly start increasing (particularly for deaths which occurred while mana burnt).

The internal elo ranking algorithm scores on a wider gamut of activities, however, which is invisible to players. It primarily takes into account winning matches and rounds, but also gives small weighting to side activities. This includes (multi-)kills, assists, flag returns, killing flag carriers, defending, escorting, use of mana burn without dying, high stat-to-mana-use ratios (damage-to-mana, etc.), and frequent use of rare spell combinations. Negative weight is given to dying due to mana burn (specifically casting a spell that consumed the rest of your health). Not very many penalties are given to avoid accidentally penalizing specific builds or playstyles. The exact weightings are also tuned with the frequency of occurrence across all matches in mind, to avoid giving preferential treatment to specific builds and playstyle. Like other ranked games, all partcipants' elo is updated after the match, regardless of winning or losing. Players who carried a losing team may still end up gaining elo, depending on their exact performance and calculated likelihood of the match outcome. Theoretically, players could abuse the mana burn penalty to keep their elo low, but that's a strategy that's also possible in other games through just throwing matches. No specific restraint will be placed on this behavior.

### Game Progression

Game progression is marked on two levels: winning a match, and unlocking spell components.

Winning a match encompasses the standard goals of a capture the flag game, and is described in the section above. 

Unlocking spell components, however, involves obtaining specific achievements or gaining a certain level of proficiency with their existing components. Achievements which unlock spell components are typically tied to tasks which demonstrate some level of mastery of a mechanic within the game. For example, an achievement obtained through killing 5 players while mana burnt would reward a spell component that further empowers abilities while in mana burn. Or, an achievement might unlock a tunable parameter of an existing spell component (ability to balance damage vs. mana cost for being the player with the highest damage-to-mana-spent ratio in a match). In addition to achievements, practicing with a specific component enough may gradually unlock other components or parameters (i.e. "Use a projectile component 200 times" -> unlocks no-gravity projectile component). This does partially feed into a "success to the successful" loop, but as players gain access to better components, their ranking will also naturally increase, until they reach a point where they need to actually learn how to use the new components rather than abuse them in matches with lower ranked players.

At the beginning of the game, about a small subset of about 10-12 components are immediately available for use. A few pre-defined loadouts are built using each of those components (generic, high mobility flag runner, damage-focused suppressor, etc.). Players can expect to unlock ~50-70% of all spell components within the game after about 40-80 hours, following a loosely logarithmic time between unlocks. The final 10-15% is specifically designed for more hardcore players or achievement-hunters, and requires completion of very specific challenges, mastery requirements, or performance-based conditions. In total, there will be about 40-60+ total spell components at release. I

Unrelated to the above two explicit progression mechanics, players are also likely to progress through their loadout knowledge as a form of implicit meta progression. Players can discover new spell combinations by reverse-engineering their death cam (or through match recordings after the fact), in-world discoveries, seasonal playlists, or watching high-skilled players. Players can then store their loadouts for specific map conditions, enemy compositions, or tactical goals. Over time, these become a tangible expression of their mastery as a form of progression.

### Player Actions & Control Scheme

Ganymede is a large game and its interactions have been split across 8 categories, depending on context.

1. Core Combat Actions
	- Fire Primary Action (cast spell primary ability)
		- Left Mouse Button
		- R2 / Right Trigger
	- Fire Secondary Action (unlocked after an achievement for advanced builds. Casts spell secondary ability)
		- Right Mouse Button
		- L2 / Left Trigger
	- Select Spell Slot 1
		- 1
		- D-Pad Left
	- Select Spell Slot 2
		- 2
		- D-Pad Up
	- Select Spell Slot 3
		- 3
		- D-Pad Right
	- Next Spell
		- Mouse Wheel Up
		- RB / Right Bumper
	- Previous Spell
		- Mouse Wheel Down
		- LB / Left Bumper
	- Melee Attack (rifle-butt equivalent. Always available, even while carrying the flag, which makes it a flag-butt).
		- V
		- R3 / Right Stick Button
	- Drop Flag
		- G
		- North Face Button (Y / Triangle)
2. Locomotion
	- Move
		- WASD
		- Left Stick
	- Look / Aim
		- Mouse
		- Right Stick
	- Jump
		- Space
		- South Face Button (A / Cross)
	- Sprint
		- Shift (hold/toggle)
		- L3 / Left Stick Button (toggle/hold)
	- Crouch (toggle or hold)
		- Ctrl (toggle/hold)
		- East Face Button (B / Circle)
	- Slide / Crouch-slide (crouch while sprinting)
	- Vault (context-sensitive, jump near ledge)
	- Mantle (context-sensitive, jump near ledge)
	- Walk (slow modifier)
		- Q (toggle/hold)
		- (No binding on gamepad. Just don't push the stick to the edge.)
3. World Interaction
	- Interact (triggers doors, buttons, vehicle mounts, etc.)
		- E
		- West Face Button (X / Square)
	- Pickups are automatic, so no device-bound button exists for them.
	- Pick Up Flag (automatic on collision)
	- Return Flag (stand near dropped flag briefly)
4. Communication
	- Open Ping / Emote Wheel
		- Middle Mouse Button (tap to open menu, or hold/release to close menu immediately if an option is hovered)
		- D-Pad Down (hold)
	- Select Ping Type (location, enemy spotted, pickup, flag-related, tactical commands, emotes)
		- Left Mouse Button (or hold Middle Mouse Button, hover over ping type, and release)
		- Right Stick
5. Match Flow
	- View Kill Cam (automatic after death)
	- Cycle Teammate Cameras (when dead)
		- Q / E, Left Mouse Button / Right Mouse Button
		- LB / RB
	- Open Respawn Radial Spell Menu (when dead)
		- Middle Mouse Button (toggle only)
		- D-Pad Down (toggle only)
	- Select/Deselect Spell for Loadout
		- Left Mouse Button
		- Left Stick / Right Stick for hover, South Face Button (A / Cross) for select/deselect
	- Confirm Respawn (player cannot respawn until confirming if they are still editing spells)
		- Middle Mouse Button (close respawn radial spell menu)
		- D-Pad Down
	- Open Player List (also shows stats, like kill count)
		- Tab (hold/toggle)
		- Menu (hold/toggle)
6. Spellcrafting UI
	- Open Spell Library
	- Create New Spell
	- Cursor Mode Toggle (non-keyboard and mouse)
		- L3 / Left Stick Button
	- Filter/Search Components
		- Right Mouse Button (on background)
		- Right Stick Button
	- Add Module
		- N (shortcut)
		- West Face Button (X / Square)
	- Connect Module Nodes
		- (click and drag)
		- South Face Button (A / Cross)
	- Delete Module
		- D / Backspace / Delete (shortcut)
		- North Face Button (Y / Triangle)
	- Adjust Parameters (sliders, numeric fields, toggles)
		- (click and drag / type / click)
		- Right Stick / D-Pad / South Face Button (A / Cross)
	- Save Spell (Overwrite)
		- Ctrl + S (shortcut)
		- Menu
	- Save Spell As New
		- Ctrl + Shift + S (shortcut)
		- Menu
	- Cancel Edits
		- Escape (shortcut)
		- Menu
	- Rename Spell
		- R / F2 (shortcut)
		- West Face Button (X / Square)
	- Duplicate Spell
	- Delete Spell
	- Toggle Locked Components Visibility
		- Tab (toggle)
		- LT / Left Trigger
7. Loadout Management
	- Rename Loadout
		- R / F2 (shortcut)
		- West Face Button (X / Square)
	- Duplicate Loadout
	- Delete Loadout
	- Favorite Loadout
		- Middle Mouse Button (shortcut)
		- Right Stick Button
	- Change Loadout Color Tag
		- (click menus)
		- LB / RB
	- Assign Spell to Loadout Slot
8. Test Range
	- Enter/Exit Test Range (quick shortcut from spellcrafting UI)
		- Enter / F1
		- Start (tap)
	- Reset Test Range State
		- \` (grave/tilde, hold)
		- Start (hold)
	- View Stat Readouts (DPS, speed, mana/s, etc.)
		- Tab (hold/toggle)
		- Menu (hold/toggle)
	- Open Radial Spell Menu (shows all spell slots in loadout, not just the selected 3. Replaces ping wheel)
		- Middle Mouse Button (toggle only)
		- D-Pad Down (toggle only)

## Narrative

### Story Summary

The world of Ganymede is defined by the collision of precision engineered sci-fi infrastructure and volatile arcane power. Nothing here feels mystical in the folkloric sense; magic is treated as an industrialized resource (extracted, weaponized, regulated, and classically misunderstood by all corporations and governmental powers). The atmosphere should always feel like a civilization that advanced too fast in one direction and neglected everything else. However, the decay is not total collapse of society. It's only erosion at the edges, with overgrown relay towers, flickering arcane conduits, and idle militarized foundries abandoned mid-project.

The environments are not ruins of the distant past. They're simply the leftovers of yesterday's ambition.

Industrial sci-fi is a major component of the architecture, but with the grime turned up: mineral-stained alloys, scuffed plating, misaligned panels, and machine systems that are functional but exhausted. Arcane technology has been integrated everywhere, as if it were a natural evolution of engineering. Runic and alchemical glyphs act like circuit traces, mana reservoirs as battery housings, and spell matrices have been embedded into weapons with the same casual pragmatism as a rifle's fire selector. Vegetation is reclaiming the forgotten edges of society, but never replacing the sense of hard geometry underlying everything. Overgrowth is only a symptom of abandonment, not nature "winning." The aesthetic and narrative should evoke competence, not wonder. However, a faint note of regret should run beneath the bravado of militarized spellcraft, and the world should feel like its own brilliance created self-inflicted fractures.

Maps should reflect their prior function, their abandonment, and the current tactical value. Here's a few examples:
- Orbital uplink spires whose broken antenna arrays still pulse with dormant arcane fields.
- Mana refinement yards overtaken by vegetation, their conveyor tracks frozen mid-cycle.
- Transit exchange hubs with suspended rail lines, their guidance crystals flickering in idle modes.
- Arcane coolant reservoirs leaking vitrified residue, creating hazardous crystal formations.

Every area should tell three silent stories simultaneously.
1. What it was built for originally.
2. Why it was abandoned.
3. Why it matters again now.

The modular spell system here isn't necessarily just a fun abstraction for gameplay either. Because it's a direct consequence of military doctrine during the arcane-industrial arms race, standardized modules made it easier to train conscripts, manufacture parts, and deploy operatives with wildly different physiological profiles. Over time, modules proliferated in nearly all business sectors. Many civilian-grade components were created and mass produced. However, the military-grade components were wildly sanctioned, sold on the black-market, stolen from experiments in derelict facilities, and used illegal field-modified components whose safety margins don't even exist on paper.

As a result, spellcraft in this era is heterogeneous ecosystem of:
- Legacy modules still in circulation decades after production ended
- Modern, risk-averse components standardized by current enclaves
- High-risk prototypes scavenged from old facilities that no faction publicly admits to using.

Additionally, although Ganymede is multiplayer-first, the world should always feel like something larger is happening just off-screen. Important ideas:
- Combatants are not "heroes" or "champions." They're specialists, operatives, volunteers, or contractors operating under limited objectives.
- Capture the flag is recontextualized as control over data cores, mana spools, crystal seeds, or tactical AI keys. All "flag objects" should represent the infrastructure contest. The flag metaphor should align with gameplay clarity, but fictionally tie into these techno-arcane assets.
- Respawn systems are actually diegetic. Field emitters are able to reconstruct operatives from preserved arcane imprints, a standardized (and ethically dubious) practice adopted after the infrastructure collapse.
- The tone avoids melodrama. The world is grounded, professional, and shaped by the pragmatic brutality of arcane-industrial warfare. That doesn't mean this should be prioritized over gameplay, however. Rocket-jumping, b-hopping, or other "unrealistic" actions fit right within the world, but the story should never treat these as comedic.

### World Building

**The Arcane-Industrial Era**

In Ganymede's universe, magic is not a spiritual or ancient tradition. It's actually a relatively recent discovered physical phenomenon which has been mercilessly exploited. Decades before the present, a breakthrough collapsed the divide between crackpot conspiracy theorist "arcane theory" and scientific engineering. In fact, mana was discovered to be quantifiable, reproducible, and manipulable through matrixed crystalline structures. The corporations, defense agencies, and technocratic states of the era treated this discovery exactly how you'd expect. They industrialized it.

Mana become everything it needed to be. A power source more compact than fusion. A weapon delivery medium more flexible than ballistics. A computational substrate capable of Turing-complete self-modifiable behavior. A commodity controlled by institutions grown complacent with their dominance.

The public message was to build a world where arcane energy supported every layer of infrastructure, from transit to agriculture to orbital defense That pretense lasted about five years before the cracks formed.

**The Strategic Arms Spiral**

Once mana matrices became viably weapon-grade, two things happened in rapid succession. First, modularity led to an arms race. Spell modules followed the same path as gun components, chemical propellants, and later smart-munitions -- rapid evolution, unregulated adaptation, and unpredictable emergent use. Every major power began creating personalized spell arsenals tuned to their operatives. Second, overcasting proved far more dangerous than predicted. The discovery that mana depletion causes the body to consume itself (consuming the body's proteins, lipids, and carbs to finish the casting) should have been a global red flag. Instead, it was framed as a "skill expression." No one dared abandon the technology and risk falling behind in the race. Militaries rebranded self-harm casting as "crisis expenditure," complete with training manuals, performance charts, and safety disclaimers no one read.

"Advantage is worth any cost if someone else pays the bill later."

**The Slow Failure of Arcane Infrastructure**

The world didn't end in a single disaster. It merely rotted from the inside. Mana reactors destabilized under prolonged overuse and minimal safety regulations. Arcane cooling towers cluttered cities with residual crystallization. Entire manufacturing districts were shut down. Though, they certainly didn't run out of business due to lack of war. They were just too unpredictable to insure. Once the safety margins vanished, maintenance personal refused to work inside arcane-industrial facilities without hazard pay that companies refused to provide.

Regions became dotted with half-finished structures, automated defense systems stuck in liminal alert states, and sealed research vaults' internal systems still hum with latent crystalline matrices. There was never an apocalypse. But the consequences on civilization were no less dire.

**Splintered Powers**

The present-day conflicts of Ganymede revolve around three pressure points. These conflicts aren't world wars, however. They're small raids, skirmishes, tactical contests, raids, and maneuvers over infrastructure nodes.

First, many of the lost facilities still hide valuable prototype tech. Functional mana systems, half-finished experiments, and encrypted spell-matrix archives are no less valuable today. Controlling these facilities means controlling the future direction of spell technology.

Second, no single faction has the legitimacy or stability to rebuild the old arcane infrastructure. What remains are splinter groups (primarily paramilitary outfits, sovereign enclaves, and contractor guilds), each with partial authority and incompatible philosophies.

Third, rumors of a second breakthrough in mana stabilization -- far safer, far more powerful -- still circulate from the old days. Whoever verifies or disproves it changes the balance of power immediately.

Generations have grown up around this technology. People don't see spellcasting as magical. They see it the same way we see microelectronics. They're complex, standardized, and mostly opaque unless you work in the field. This does mean civilian-grade components exist and are plentiful, but high-grade matrices are tightly restricted. Students even learn basic spell theory in school the same way ours learn circuit theory. For most people within the Ganymede universe, they have never seen high-risk casting, and often misunderstand the physical consequences of burning oneself. Today, there's a quiet cultural anxiety about the arcane-industrial past. An uneasy recognition that everyone is still living inside the skeleton of an unresolved experiment. But time marches forward, and society can't stand still.

### Themes

1. Power is Consumable

The central mechanic -- mana burn that trades health for output -- ripples through the world's logic. Society routinely sacrifices long-term well-being for short-term advantage. Individuals internalize that philosophy whether they admit it or not.

2. Tools That Outlived Their Purpose

Every object on the battlefield (collapsed conduits, reinforced casting guns, half-functional mana regulators, etc.) feel like there were designed for something larger than present society can sustain.

3. Ambition Exceeds Stability

Everything technologically impressive in this world also carries the potential for failure. Energy sources destabilize, spell matrices oscillate, overgrowth fights for space where humans retreated.

4. Legacy Systems Dictate Modern Conflict

The playable arenas are not symmetric sports fields. They are real strategic sites being contested by factions who can't afford open war.

### Offline Campaign?

Ganymede's narrative and gameplay is fully capable of supporting an offline campaign (whether that's strictly singleplayer or allows co-op, doesn't matter). However, the focus for development will be on capture the flag only, until that feature is in beta. At that point, and only then, other game modes (and yes, an offline campaign) will be considered.

## Mechanics & Systems

### Combat System

Combat is governed by a dual-resource loop of mana (primary ability resource) and health (fallback resource with major tactical implications). Spells, not guns, are the primary form of damage delivery. Players manage tempo by deciding when to overspend their mana to secure advantage. Stamina is a secondary resource primarily used for movement.

Key points:
- No passive health regen. Health is permanently lost until death. No healing spells or health pickups either.
- Mana regenerates, but at fixed rates determined by loadout tuning, map conditions, and the mana burn state.
- All spells are active abilities constructed from modular components.
- Damage model is deterministic. Predictable projectiles, consistent hitboxes, minimal randomization.

When a player attempts to cast a spell which costs more mana than they have available, the player will enter a "mana burn" state.
- Before casting the spell, the UI clearly indicates they will become mana burnt.
- The remaining cost is subtracted from health (with additional modifiers depending on environment and status effects). Overcasting permanently mortgages future fights.
- Mana regen is diminished until mana returns to full, which introduces starvation windows and counterpoints
- All subsequence spells cost health directly until that recovery completes.
- Self-kill is possible and common when optimizations fail.
- Effectively adds a voluntary high-output, low-survivability mode, which strong players weaponize for tempo spikes.

Every spell has a primary action, and secondary action is enabled. Firing triggers cooldowns, global animation locks, charge/cast phases, or other module-driven timing windows.
- Projectile behavior (velocity, arc, drag, lifetime, collision) is fully deterministic and module-controlled.
- Hitscan modules exist but are limited and balanced through high mana costs or narrow use cases.
- Many other kinds of modules also exist, and follow the same general logic. Some modules are informational (detecting the presence of enemies), others are pure (de-)buffs, and some create interactable objects when cast.

Melee is an action that is always available, even when carrying objective items. However, it is intended only as a panic tool, not a primary damage path. It can secure kills on vulnerable mana-burnt players to punish over-extensions. Melee attacks consume stamina instead of mana, to allow them to be viable for low-mana or mana-burnt players.

Stamina regenerates relatively quickly, and is consumed for most movements actions, including jump. Running out of stamina will safely conclude the ongoing action (if applicable, such as mantling), and leave the player in an exhausted state. While exhausted, the stamina regeneration rate is reduced until it recovers to full, the player's base speed is reduced, and they cannot take any stamina-consuming actions until they recover to at least a quarter of their max stamina.

During gameplay, pickups can spawn around the map. These pickups only exist in the form of spell modifiers, which apply additional layers of modifiers to the parameters of the player's selected spell. These modifiers are randomized, but not necessarily completely random. The closer a pickup spawns next to a particular player, the more likely its modifiers are relevant to the player's loadout. Pickups will also be distributed non-uniformly to teams to lightly rubber-band the losing team.

### Spellcrafting

Spells consist of chained components ("modules"). A module defines:
- Delivery method (projectile, beam, AoE, trap, charge-release, instant, etc.)
- Effects (damage shapes, DoT, suppression, mobility pulses, shields, etc.)
- Parameter set (velocity, charge time, cost multipliers, AoE radius, cooldown mod, etc.)

The player assembles modules via node connections in the Spellcrafting UI, similar to a drag-and-drop node-based programming interface.

Each module has a specific "complexity" and mana cost associated with it. Any individual spell cannot exceed a total complexity or mana cost to avoid creating "super spells" that kill the caster but have enough impact on the match to not matter. Alt-fire is unlockable but optional, allowing advanced builds.

Tuning parameters for a module can influence the complexity and cost (either upwards or downwards). Players can customize:
- Damage
- Projectile weight, gravity, and spread
- Cooldown scaling
- Effect intensities
- Charge-time multipliers
- Conditional effects (on-hit detonate, proximity arming, sticky, ricochet, etc.)
- And many more...

These tunings push players toward self-authored identities and roles instead of hero-class constraints.

Players can create loadouts of 6 spells. Players can save these loadouts as named collections of these spells, with color tags, favorites, and duplicate/rename utilities for fast iteration. However, players only have 3 spell slots during a match, meaning they can only actively use 3 spells during gameplay. Swapping spells can only happen during respawn, enforcing commitment, but allowing strategies to evolve.

During a match, there are no weapon pickups. A player's loadout is their identity.

### Player Progression

Players begin with a small, readable set of components, along with a few default profiles for example usage. New components can unlock through:
- Skill-based achievements
- Mastery thresholds (using a module enough times, performing actions with specific efficiency)
- Performance-based awards (e.g. high damage-to-mana efficiency ratios)

50%~70% of components are unlockable via normal play within 40~80 hours. A final 10%~15% are reserved for mastery challenges.

Notably, there is no XP, no battle pass, and no cosmetic grind. Progression revolves around mechanical mastery, not time spent.

However, in unranked gameplay, the full library of components are available from day one to prevent mismatch in competitive equity. Otherwise, players unlock components in ranked play gradually via achievements.

### Locomotion

- Standard FPS movement (walk, sprint, crouch, slide)
- Mantling and vaulting are contextual
- Movement is purposefully readable, with limited momentum exploits.
- Crouch-sliding timing interacts with the sprint state to maintain traversal rhythm.
- Jump height and vault thresholds are tuned to minimize map-break vectors.
- No supernatural mobility unless explicitly created through spell modules.
- Modules may provide dash effects, blast-jump equivalents, momentum pulses, reactive shields enabling aggressive peeks, etc. However, these are deliberate tradeoffs and rarely free in mana efficiency.

### Interaction System

Interactables include objects like terminals, doors, lifts, extraction devices, defense systems, etc. Some interactable may also be created through spell modules. Interaction is fast and readable (single button taps); no long-hold actions should exist unless intentional.

Some objects don't require explicit interaction, such as objective items. Flags and pickups auto-pickup. Returning a flag only requires standing near the dropped flag for a small amount of time. Flag carriers cannot cast spells, however, forcing reliance on teammates. Dropped flags do inherent momentum and positional risk. Any ongoing spells cast by the flag carrier or status effects applied are not dispelled.

For communicating, the ping wheel (tactical pings, enemy spotted, objective call outs, emotes, etc.) is the only method in-game. Players are otherwise expected to use Discord for voice communication. The gestures/emotes are intentionally as frictionless as possible, reinforcing team coordination. Certain pings will show a location marker in the HUD layer that can be seen through walls.

### Match Progression

For capture the flag, matches are conducted in a best 2 out of 3 rounds, each 12 minutes long. Ties are resolved via the fastest average capture time; otherwise, overtime with rising respawn timers.

When a player dies, the killcam shows the enemy perspective briefly, before switching over to a teammate. Players can edit their selected spells during respawn, but respawn does not occur until spell changes are confirmed. If no editing takes place, they will be respawned automatically. Respawn timers also escalate during overtime and are longer for mana-burn deaths.

The elo ranking algorithm is invisible to players and considers:
- Wins, captures, flag returns
- Kills, assists, multi-kills
- Damage efficiency (damage per mana)
- Responsible management of mana burn
- Use of rare of high-skill spell combinations
- Penalty only for self-inflicted mana-burn deaths

The elo system avoids incentivizing specific metas. Although players will absolutely reverse engineer the elo ranking algorithm, their specific elo will intentionally never be shown to them.

### AI Behavior

While not central to the initial multiplayer, the design supports AI entities for training or future scenarios.

Test range dummies perform:
- Looped movement patterns (strafe, peek, hold-position, rush)
- Hitbox consistency for DPS testing
- Predictable behaviors to validate tracking, projectile timing, or AoE tuning

More advanced combat AI would be reserved for a future campaign mode.
- AI evaluates engagements on mana-vs-health risk similar to players.
- Behavior trees include:
	- Cover selection
	- Flanking decision
	- Mana-conservative vs. mana-aggressive styles
	- Spell module usage identical to players
	- Automatic role dispersal and switching among team members
- AI doesn't use perfect information to maintain fairness; perception cones and audible cues are its main sensors.
- Potential archetypes for roles include:
	- Suppressor (area denial)
	- Skirmisher (hit-and-run)
	- Anchor (positionally rigid, efficiency-focused)
	- Pursuer (anti-runner logic for CTF)
- All use the same spell system players do. No bespoke cheat abilities.

### Environmental Mechanics

Levels are designed around a variety of high sightline lines, close-quarters flank routes, vertical travel opportunities, and contested resource nodes (traversal utilities, pickup areas, temporary hazards, etc.)

Map hazards themselves don't necessarily need to deal damage or be strictly negative either.
- Residual crystal aerosols causing damage over time
- Arcane flux fields altering projectile trajectories
- Cooling leaks that slow players
- Dormant defense mechanisms that reactive under match variants
- Automatic conveyor belts or gravity zones
- Mana-rich zones that increase regen and reduce costs
- etc.

These hazards may also respond to nearby interactables, such as pressing a button to toggle the presence of a hazard.

## Visual & Audio Design

### Art Style

The overall style is a modified physically-based realism, but stylized in material exaggeration rather than in form. Think Halo 3's gritty forerunner tech combined with Portal 2's industrial decay and modern technical magic, but grounded in a pragmatic tone.

1. Industrial Sci-Fi First, Arcane Second

Magic isn't mystical in this world. It's infrastructure. Visuals should frame spellcasting as the illegitimate child of engineering and arcana.

2. Everything is Competent, but Exhausted

Surfaces are functional but worn. The world's decline is slow and unromantic.

3. Readable Silhouettes, Harsh Geometry

Players must instantly identify players, spells, important props, routes, and interactables.

4. Aesthetic Tightness, Environmental Looseness

Characters and equipment are controlled, engineered shapes; the world around them is frayed, fractured, oxidized, and overgrown.

5. Arcane Tech Glows Only When Active

No constant neon. Glows exist as signals of energy flows -- feedback, telegraphing, danger, or instability.

Other notes:
- Characters are mid-to-high poly, have clean topology, sharp angles, and segmented hard-surface plating.
- Environments involve heavy wear, chipped coatings, exposed conduits, mineral deposits, plat intrusion, and other signs of abandonment.
- Spells should look like mechanical abstractions of energy flow, not fantasy flourishes.

Lighting:
- Strong directional light where relevant, but high contrast overall.
- Localized bloom only for high-pressure mana spikes or unstable matrices.
- Indirect lighting reads cold, desaturated, and utilitarian.

Materials:
- Matte composite armor polymers
- Scuffed aluminum-titanium alloys
- Cracked mana glass (semi-translucent crystalline composites, very slight blue hue)
- Ceramic plating with thermal scoring
- Rubberized conduit bundles
- Vitrified residue from arcane coolant leaks

### Color & Shape Language

**Shapes**

Players:
- Hard-edged, wedge-like silhouette
- No ornamental ornamentation. Every piece should look manufacturable.
- Center mass slightly widened for readability at distance.
- Arcane elements appear as embedded lines or "circuit glyphs" following mechanical logic.

Environmental:
- Architecture: Cuboids, chamfers, beveled industrial structure
- Arcane nodes: Triangular or hexagonal matrices with symmetry broken by decay
- Overgrowth: Vine-dense, opportunistic, creeping through seams

Spells:
- Projectile: Condensed geometric cores (tetrahedrons, prisms, or spheres) wrapped in regulated energy fields.
- Hits: Sharp crystalline fractures, not fiery explosions
- AoE: Circular or triangular glyph arrays projected as temporary field overlays.

**Color**

Base World:
- Steel blue
- Graphite gray
- Industrial yellow
- Oxide red
- Pale concrete
- Desaturated greens for overgrowth

Arcane Tech:
- Avoid rainbow magic. Narrow the palette per energy family.
- Mana (general): Cyan-white or cerulean
- Overcast/burned mana: Deep crimson with black-body flicker
- Stabilized crystalline: Violet with subtle refraction
- Prototype/unstable: Sickly green, jittery light patterns

Faction Color Markers:
- Use highly saturated accents only, not full armor dyes.
- Should be easily readable but never overwhelm the base materials.

### Character Design

Narratively, the players are specialists, not heroes. Design them as such.

More specifically, they are operators equipped with manufactured mana-tech. They feel like a fusion of tactical gear, industrial PPE, and arcane conduits.

Visual Identity:
- Full-body suits with modular slot points for spell matrices.
- Helmets with opaque visors, no faces. Combatants are deliberately depersonalized.
- Arcane reservoirs integrated into their forearms, spine, or thighs. Visibly pulsing only at high mana throughput.
- Subtle mechanical servo elements, but no overdesigned exosuits.

Silhouette Rules:
- Mid-profile, slightly bulky around chest/back.
- Distinct silhouette from the environment so players never blend in.
- Should read at 40-60 meters with no ambiguity.

Movement:
- Efficient, functional. No parkour flair unless gameplay demands it.
- Mantling is quick and deliberate. No flourish.
- Sliding is low, weighty, and friction-forward.

Combat:
- Spells cast through arm movements that feel almost like toggling machinery:
	- Small primes
	- Wrist flips
	- Triggering matrices
	- Grabbing and redirecting energy.
- They should never look like wizards waving wands. More like engineers routing power.

Mana Burn State:
- Player animation staggers slightly, breath becomes strained, posture tightens.
- Reservoirs flicker irregularly
- Subtly distortion shader around the torso suggests metabolic overdraw

### Environment & Prop Design

Architectural Tone:
- Built for function: platforms, ducts, conduits, gantries. Of course, this is video game logic. They don't actually need to make perfect real world sense.
- Arcane systems retrofitted onto older structures. Mismatched layers of technology should be apparent.
- Overgrowth isn't beautiful. It's opportunistic and unpleasant.

Environmental Storytelling:
- What is the location's original purpose? (control room, cooling towers, transit hubs, etc.)
- What is its reason for abandonment? (crystallization leaks, scorched conduits, sagging supports, etc.)
- Why does area matter now? (tactical chokepoints, resource nodes, CTF routes, etc.)

Surface Treatment:
- Arcane coolant crystallization = frosted blue glass-like deposits.
- Mana overflows leave scorched glyph imprints on walls.
- Decay shows through misaligned panels, exposed wiring, rust bleeding down concrete.

Prop Examples:
- Mana Reactor: Stacked, hexagonal casings with slow-beating light pulses synchronized with hum tone.
- Spell Module Crates: Industrial, pelican-case style, color-coded for module class. Holographic label projection when in range.
- Flag: Data Core. A compact crystalline lattice suspended in a carrying case with hard-surface handles. When picked up, its internal lattice flickers into a "transport mode" with reduced light output (for readability).
- Scattered mana capsules that look like battery cartridges.
- Metabolic stabilizers near emergency exits instead of medkits.

### UI/UX

**Style Guide**

UI in Ganymede is a technical instrument panel for an industrialized magic system. Use clean typography, restrained color, and no "shiny gamer UI noise." (I swear I will unglue myself from this seat if you do that.)

The primary typeface should be a condensed grotesk or technical sans-serif (e.g. Eurostile-inspired but not ornamental).

Color logic:
- Primary accents: cyan, white, orange
- Alarm/error: red, but only for severe warnings
- Low mana: cyan -> magenta shift before sudden deep crimson
- HUD elements sit on very subtle blurred panels to maintain readability without clutter

Shape language:
- Rectangles and chamfered corners for tech elements
- Runic/alchemical glyph overlays, but only as thin-line schematic accents. Don't overdo it.

HUD elements:
- Reticle: minimalist, no animation unless mana burn or cast charge thresholds
- Mana Bar: Horizontal bar at center-bottom of screen with ampere-like tick marks
- Health: Thin vertical bar at bottom-left
- Spell Slots:
	- Only 3 shown at once, in bottom-right
	- Secondary casting indicator appears around the reticle if available
- Location Markers:
	- Through-wall markers with distance, noting teammates and flag
	- Color-coded per team and softened when occluded
- Stamina: Black vignette that closes in when getting low, accompanied by labored breathing sfx.
- Match Timer: Top-center timer ticking down; hh:mm:ss/mm:ss format (no leading zeroes).
- Kill Board: Text which announces deaths, flag captures, and other notices in the top-right. Names/teams are color-coded. New lines appear at the top and scroll downward.
- Stat Board: When opened, takes up the majority of the screen in the center. Shows a list of players with their kills, assists, deaths, flag captures, and other stats. Grouped by team.

State indicators:
- Damage: Clean screen-edge vignette, color-shifted by enemy/friendly fire.
- Mana Burn: Screen-space chromatic shear and heartbeat-linked pulse.

**Spellcrafting UI**

This is the most UX-critical system in the entire game. Yes, even more so than the HUD.

Layout:
- Node-based left section (module graph).
- Right panel: numeric tuning parameters, slider controls, validation warnings.
- Top bar: save, duplicate, test range shortcuts.

Feedback Principles:
- Every module shows its computational cost and mana profile visually.
- Connection lines glow brighter as throughput increases.
- Invalid or dangerous configurations display flicker or geometric instability.
- Loadout blueprint card displays predicted mana burn risk.

Accessibility & Clarity:
- Full keyboard + mouse parity with controller modes.
- Sliders support numeric input for precision.

**Matchmaking UI**

Follows a fairly standard UI for most other competitive shooter games. Of particular note here, however, is how player loadouts are communicated to their teammates. The loadout name is displayed prominently, with a quick overview of spell stats (types of effects across movement, damage, utility, etc.; theoretical max damage; mana cost). Focusing a particular spell will show a more detailed preview of that spell's components. In essence, this UI element is designed to communicate the critical details of teammates' capabilities as quickly as possible, so that players can make informed decisions about their own loadouts and team role.

### Audio Design

1. Industrial Clarity, Arcane Volatility

Mechanical grounding layered with crystalline harmonic distortion.

2. Every Sound Must Communicate Game State

Ability telegraphs, mana burn risk, incoming projectiles, flag status -- all with distinct timbre.

3. Avoid Magical Flourish Cliches

No fairy dust, no fantasy chimes. Arcane effects should sound like stressed electronics, overstimulated capacitors, vibrating glass, and pressure equalization.

**Sound Effects**

Spells:
- Projectile Launch: A compressed crack + crystalline resonance. Charge variations deepen the resonance and lengthen tail decay.
- Impact: Sharp, glass-on-concrete fracture snap follow by short grit scatter.
- AoE: Multi-source harmonic burst, similar to collapsing EM fields.

Mana Burn:
- Heavy low-end rumble layered under heart-like pulses.
- Slight "vacuum collapse" sound when entering burn state.
- Continuous irregular flicker reminiscent of unstable power lines.

Movement:
- Armor clinks subdued. Combatants are trained, gear is well-maintained.
- Sliding: gritty, metallic friction.
- Mantling: dull composite thuds, glove friction.

UI SFX:
- Crisp, short blips.
- No cheesy sci-fi beeps.
- Spellcrafting node connections use a clean "capacitor latch" sound.

**Music**

Tone:
- Cold, restrained, rhythmic.
- Minimal melody. Emphasis on tone clusters, percussive industrial hits, and synthetic drones.

Instrumentation Palette:
- Hybrid synths with distorted granular edges
- Metallic percussion (processed field recordings)
- Subharmonic pulses representing mana flow
- Sparse string-like textures for tension (treated heavily to avoid orchestral cliches)

Dynamic Scoring:
- Lobby: Slow mechanical hum + evolving pads
- Match Start: Low-frequency attack pulse
- Flag Capture: Sharp tonal cluster rising upward, recontextualized per team. Keep it non-intrusive. Ganymede isn't a power fantasy shooter.

## Level Design

### Level Layout

Ganymede's levels must do three things simultaneously:
1. Create predictable tactical geometry that rewards teams who understand sightlines, flanks, and tempo windows.
2. Reinforce the mana/health economy through spatial pressure, not gimmicks.
3. Tell a grounded environmental story about arcane-industrial collapse without distracting from combat clarity.

Levels are never designed like a hero shooter map, nor like a Quake arena. The geometry must support deliberate pacing and team strategy. Pure mechanical chaos is bad.

In particular, most other shooters place the burden of tempo on weapon availability, power positions, and mobility curves. Ganymede's tempo is self-inflicted by the players via casting decisions. That means:
- Level pacing must breathe enough to let mana regen matter
- Safe zones must exist but never trivialize retreat
- Choke points must force fraught decisions about mana burn
- Flanking must be readable (like Halo) but less escapist than Quake.

Maps must intentionally create moments where burning health feels necessary.

This creates roughly 3 spatial tiers:

1. Tactical Chokepoints

Narrow, high-value intersections where mana burn becomes common because teams commit resources to break through. They reinforce verticality but keep complexity readable. Sightlines are short-to-mid-range, and these areas are purposeful tempo sinks where teamfighting decisions matter.

2. Rotational Arteries

Wide, semi-safe traversal lanes enabling macro flanking. They have minimal cover and high exposure, with sightlines long enough to punish overextension. These arteries embody Ganymede's abandoned industrial infrastructure: straight, functional, and decaying.

3. Staging Zones

Areas where teams group, regen mana, wait for pushes, or prep ambushes. Their size fits between the two types of above, with medium cover density to provide intentional pockets for breathing. These zones must exist or mana regen loses relevance, but cannot be too safe to avoid turtling or encouraging retreating over mana burn.

Because spells are also highly modular and are combinatoric as more components are defined and implemented, this creates aiming difficulty that varies with spell types, playstyles, and loadouts. Maps should avoid extremes to counteract the "swinginess" in spell variety. No ultra-long sniper lanes; Ganymede doesn't have precision hitscan heroes. No hyper-compact areas either; too many spell components rely on mid-range engagement tuning. The ideal combat radius is 12-32 meters, adjusted to suit each map and its theme.

Verticality must also be tactical, not parkour enabling. Use single or double vertical layers max. However, use the height to create power positions worth burning mana for. But be careful to avoid advanced-movement chokepoints so mobility builds don't dominate. Thank Halo 2 Lockout, not Titanfall or Quake.

Ultimately, each CTF map should follow a consistent structural blueprint for readability while allowing thematic variety.

1. Base Zone
	- 2-3 entry routes
	- One high route, one low, one neutral
	- Flag placed in a semi-open, defensible position
	- Defenders get rotational advantage, but attackers get crossfire routes
2. Midfield
	- This is where mana burn spikes
	- Symmetric in macro geometry
	- Asymmetric in micro cover
	- Dominated by the longest sightlines
	- The "identity space" for each map. This is where the arcane-industrial narrative is most visible.
3. Side Lanes
	- Gives teams alternative flag runner paths, but are slower or riskier
	- More cover, tighter geometry
	- Good for mobility or skirmisher builds
4. Power Zones
	- Not power weapons. These are power positions.
	- Slight height advantages
	- Good mid-range vantage
	- Require resource commitment to hold
	- Accessible from multiple angles to prevent hard locking
5. Spawn and Exfil Spaces
	- These are non-combat pockets behind the base
	- Resets tempo and lets teams regroup
	- Large enough to prevent spawn trapping
	- Feed cleanly into the base defenses

### Environmental Storytelling

This is where Ganymede should be able to outshine the typical shooter, but only if the maps express these three silent stories consistently:

1. What was this area originally created for?
2. How did it fail or become abandoned?
3. Why is it strategically contested now?

Because Ganymede is also a shooter, the story of each area must be readable in 1-3 seconds of peripheral vision. There should be zero clutter that disrupts hit readability or cover silhouettes. Decay must also be structural, not merely decorative.

For example:
- Large-scale industrial machinery frozen mid-task
- Mana conduits flickering in half-active states
- Vitrified arcane coolant glassifying surfaces
- Overgrowth reclaiming edges, never center-path routes
- Damaged signage giving hints to old facility function
- Corporate logos half-scraped off
- Arcane lacerations on architecture from past experiments

Even more explicitly, consider a collapsed refinery corridor. Props should not be strewn about everywhere. Instead:
- Conveyor rails just from walls
- Arcane coolant crystallization forms unstable floors
- Broken matrix cores cast intermittent soft light (good for readability)
- The tactical path is clean, but the edges tell the story

### Environment Types

Consider these like "biomes" that fit Ganymede's aesthetic, provide mechanical variety, and express different facets of the arcane-industrial collapse. This is not an exhaustive list of what's allowed, so get creative!

1. Mana Refineries / Processing Yards

Heavy machinery, crystallization hazards, slow industrial decay. Features large midfields, predictable and blocky geometry, with conveyor-based rotational lanes.

Abandoned mid-production, the machines have now fallen out-of-sync with arcane regulators.

2. Arcane Relay Towers / Uplink Sites

Tall, thin structures with unstable mana conduits and exposed metal catwalks. Chokepoints are vertical areas with risky high grounds. Side lanes pass through maintenance tunnels.

Once part of orbital comms, the towers have begun collapsing after instability in the mana matrices surfaced.

3. Transit Hubs / Suspended Rail Stations

Rails, platforms, switching towers. Long, open arteries for strong lane identity. Rotational depth is given for coordinated pushes.

The civilian logistics network has been ruined by mana contamination.

4. Cooling Reservoirs / Cryo-Arcane Plants

Frozen coolant lakes, vitrified residue, refractive crystalline hazards. Surfaces are slippery, low-traction. Low cover density throughout, with dome-like interior geometry.

A core failure froze the facilities in arcane glass.

### Key Challenges

Enemy players are obviously the main threat in Ganymede, but good levels will still have passive pressures that influence tactical decisions.

Resource pressure zones are areas where players should habitually enter low-mana or mana burn states. They are long open pushes, midfield stand-offs, or high-value crossing points. Make entering these zones a meaningful decision. Why does this location matter, tactically?

Second, commitment corridors are essential for level design. Routes where you go in, and retreat becomes costly. These are narrow tunnels, collapsed maintenance shafts, and chokes in the overgrowth. Amplify tactical commitment and encourage team coordination.

Rotational baits are small power positions that seem valuable but are traps if overcommited to. They should provide good sightlines but no escape, with cover that breaks under pressure. These challenge inexperienced teams while savvy players should be encouraged to exploit them.

Finally, use terrain to reinforce these build choices. Have high ledges that are only accessible with mobility spells (but not valuable enough to make mobility loadouts a dominant strategy). Have low-value shortcuts that save seconds but require perfect execution.

### Pacing

Ganymede's pacing model should be a deliberate wave pattern:
1. Spawn regroup (low tempo)
2. Lane advance (rising tempo)
3. Midfield collision (peak tempo)
4. Post-fight recovery / mana regen (low tempo)
5. Flag contest (high tempo spike)
6. Escape or reset (variable)

Maps (and and consequently gameplay) should breathe. Do not let them collapse into non-stop brawls. The mana system only works if teams naturally cycle between committing, surviving, recovering, and re-engaging. Geometry must make space for this.

## Monetization

### Business Model

Unfortunately, Ganymede is particularly difficult to monetize. The biggest tension it that it intentionally rejects almost every modern monetization vector that the market has normalized (e.g. no XP/battle pass/cosmetic grinding).

However, that isn't to say purchasable cosmetics *can't* be implemented in general. The basic strategy for monetization will be a free PvP base game, with some specific kinds of cosmetics for sale, and the potential of a premium narrative or PvE expansions. This is mostly because similar games follow the same pattern, and Ganymede doesn't necessarily have any strong reasons to break from that mold. The initial source of income (to have servers online at game release) will be obtained through a partnership publishing deal.

Of great importance here as well is the technical requirements around servers and hosting. In particular, server binaries will be freely available for self-hosting, and server owners can choose to run in a default authenticated mode which relies on central hosting managed by the game publisher, or in an "offline" mode which grants them full freedom over the server, but zero guantees or validation of purchases. This is similar to how Source, Quake, or Minecraft servers are able to run. Authenticated servers would be able to use the central API for account identity, cosmetic entitlements, anti-cheat posture, ranking, and matchmaking. Non-authenticated servers are effectively a formalized definition for cracked servers, and cannot be policed. The choice to follow this format is based on the grounds that no central servers are required to guarantee monetization through battle pass-like methods, as well as the want for long-term longevity or archival of the game.

The header sections below will elaborate more on the kinds of funding Ganymede plan on supporting. The rest of this section will focus more on going over the pros and cons of various monetization paths, laying out the total design considerations. In general though, selling spell components is a hard no (undermines fairness and the entire progression philosophy), as well as anything resembling a power boost, battle passes or XP tracks, or gacha systems (the game's target audiences lean slightly older, and they don't tolerate gambling mechanics as well).

First, the traditional cosmetics-only model does have a number of strengths. It's non-intrusive and doesn't disrupt the mechanical purity of the matches. The most successful cosmetic economies also tend to live in shooters with strong competitive audiences, and it works well with the sci-fi/arcane-tech aesthetic because the game's base materials have strong visual identity. However, there are many weaknesses to including paid cosmetics in Ganymede. The narrative deliberately depersonalizes players with full-face helmets, standardized operators, and industrial pragmatism. The battle pass loop which would normally act as the backbone and psychological anchor for cosmetic FOMO is explicitly denounced. Additionally, the game's tone is hostile to flashiness. Many players who would purchase cosmetics in other games would expect expressive, showy, or meme-like cosmetics. The aesthetic language here actively avoids that, and narrows the market reach dramatically. Finally, pure cosmetic models usually require a very large player base or heavy social signaling (post-match screens, lobbies, etc.), and Ganymede's identity doesn't currently emphasize those.

Second, paid expansions in the form of maps or campaign chapter packs could potentially be viable, but only if an offline campaign becomes a pillar of the project. As of now, this potential source of revenue is otherwise nonexistent. This method does have some of the cleanest alignment the game's design values, however. It works well for story-driven players (the adjacent audience), and doesn't fracture the competitive pool if PvP maps are free while the campaign maps are paid. This would also be able to fund high-production worldbuilding without compromising the core play. Unfortunately, campaign development is expensive, and taking this path would necessitate committing to a multi-year narrative road map.

A subset of cosmetics for spellcrafting could include specialized cosmetic modules. Not mechanical additions, just purely visual augmentations such as alternative VFX, cast animations, impact styles, sound sets, and so on. This allows the game to use the most unique part of the game as the monetizable layer and lets players express identity without undermining fairness. It even fits the narrative fiction well, allowing different in-universe manufacturers, illicit prototypes, or corporate catalog variants to be created. On the other hand, this does require extremely disciplined art direction to avoid degenerating into Fortnite-tier noise, and there's a risk of VFX clutter interfering with PvP clarity. If not careful, it could also accidentally create pay-to-readability advantages (such as quieter or less distracting VFX).

Players could also publish spell builds with specific cosmetic signatures (colors, VFX themes, "maker marks," etc.), with the purchasable cosmetic bundles tied to the blueprint. This leverages the theorycrafter audience well, and builds community engagement loops with introducing grind. However, this requires fairly scrutinous moderation to ensure the marketplace is never able to sell a mechanical advantage (i.e. a particular cosmetic combination that exploits a competitive advantage) or violates IP regulations of others. Implementing these curation tools, moderation, and revenue sharing streams significantly increases complexity, and its likely only theorycrafters would engage with the system anyway. Casual players are likely to ignore it entirely. It's very niche, but thematically on brand, at least. Possibly a good supplement source of income, but not core.

Another way to monetize is possibly through finite-time thematic bundles dropped every few months (founders packs, seasonal drops, etc.). These don't form any kind of battle pass, but do attempt to catch the FOMO aspect on a larger timescale. Bundles can be anchored to the aesthetic narrative ("Arcane Industrial Overhaul Set," "Legacy Prototype Kit," etc.). However, compared to a standard battlepass, revenue would be more lumpy and inconsistent, and would require a strong marketing cadence to be sustainable. Moreover, without hero characters to anchor themes, the bundles must rely on environmental or spell-tech motifs, which are definitely harder to make emotionally impactful.

Adjacent to an offline campaign, there could be small narrative-driven tactical scenarios sold as premium challenges. They could similarly explore the game's worldbuilding and introduce new environments, props, and storytelling without fracturing the main PvP modes. There would also likely be high replayability through introducing scenario modifiers, variant goals, or randomization. In terms of technical requirements, this would require the AI systems become robust enough to be interesting. The current AI design only accounts for a test range mode with no combative viability.

The least aligned option with the game's design to just release skins, armor sets, and other cosmetics like other normal games. It's a familiar monetization path, but as mentioned, the narrative fiction completely resists personalization. The operators are meant to be faceless, standardized specialists with no heroic framing. Selling identity customization directly contradicts the worldbuilding tone. If the art direction is bent just to sell cosmetics, the game loses coherence, and development will end up fighting itself constantly. Style guidelines would end up saying "no ornamentation," but monetization says "ornamentation sells." While doing this is "physically" possibly, it will damage the identity of the game more than anything else here.

Finally, as another subset of cosmetics, there could be arms designs that feature "industrial-grade variants" manufactured by different fictional companies. These separate from the spell cosmetics, and instead utilize these companies to create different styles of operatives that still perfectly fit within the sci-fi arcane-industrial world. For example, a theoretical "Arkos Systems" company would utilize matte composite finishes and sharp cyan VFX in their cosmetic design, whereas "Vortexia R&D" would use unstable green flicker VFX and crystalline fractures. The only downsides are the creation of a fictional manufacturer ecosystem (not that difficult, considering the worldbuilding that's already taken place), and the risk players saying "everything looks the same" because of the restrained aesthetic. Given a variety of manufacturers though with contrasting enough styles, that seems manageable.

### In-App Purchases

Specific kinds of cosmetics would be sold through an in-game store. The goal here is not to take a Fortnite-esque approach and have an "anything goes!" policy. Rather, a relatively narrow combination of spell VFX and "cosmetic lines" sold by in-universe industrial manufacturers will be the path forward. It aligns with the game's aesthetics, mechanical fairness, general audience values, and utilizes one of the strongest unique parts of the game through its spellcrafting system. New bundles can be released over time to keep engagement and revenue consistent. This becomes the game's main store, and likely primary source of revenue.

For spell VFX, it's not limited to only visuals. Consider things like:
- Cast animations
- Impact styles
- Sound sets
- etc.

For the cosmetic lines, they should be narratively justified by an in-universe company selling those products. Communicate with the narrative team when adding cosmetics that don't align with a preexisting company. Example companies (not necessarily ones that are solidly planned and thought-out):
- Arkos Systems: matte composite finishes and sharp cyan VFX
- Vortexia R&D: unstable green flicker VFX and crystalline fractures
- Thermax Assembly: thermal-reactive armor coating and orange accents
- etc.

Care should be taken not to misconstrue this as a live service game. Regular releases of cosmetics should not be considered as new content. After release, the game should not be experiencing major game design changes.

### Premium Features

This section only becomes viable if an offline campaign or PvE expansions become a primary pillar of Ganymede's design.

Premium features would include DLC separate from the base, free parts of the online multiplayer experience, as fragmentation of PvP would otherwise kill adoption. A full offline campaign would require writing a narrative, designing custom maps, programming the new features, the and the rest of the development work needed to support it.

Because this path toward monetization is actually so strong (especially long-term), this may even become a requirement before release. The funding from cosmetics only may not be enough to cover all development and marketing (particularly due to the narrow kinds of cosmetics and the already smaller audience).

## Technical Requirements

### Engine

Unreal Engine 5 presents the best path forward. It already supports great network replication, headless server operation, and rendering that easily integrates the stylized materials in a mostly photorealism-based aesthetic.

Pre-production will adopt a single engine version (i.e. 5.7), and after moving into full production, the engine will be upgraded again, since no features are likely to have been implemented that require significant refactoring between the two versions.

### Platform-Specific Features

Cross-platform play is a requirement for release, so keeping parity and gameplay determinism between platforms is essential. However, to aid in the UX on an individual platform, some additional features may be implemented.

For UI, every screen should have all features accessible on any input device. This includes cursor mode toggles for gamepads (particularly for the spellcrafting UI), and no reliance on text-input-only workflows. Steam Deck clients will need their own compatibilty layer here. Radial menus should also be considered a first-class UI, as they're used fairly extensively in gameplay. Text should also readable at TV resolutions and distances. Hover-only affordances should not be relied on (opt for moving the information elsewhere, or using a focus affordance that remain compatible with gamepads).

On PCs, there is **no** kernel-level anticheat to maintain compatibility with Linux.

On consoles, they will need to handle suspend/resume gracefully (to the console OS menu) to meet certification.

About the spellcrafting UI specifically:
- Analog stick driven node selection (when not in cursor mode)
- Snapping, auto-routing, and focus prediction
- Dead-zone aware slider tuning
- Deterministic parameter increments (no float drifts across platforms)

If console spellcrafting feels even slightly worse than PC, than the theorycrafting audience will exclusively use PC (filtering out theorycrafter console players), casual console players will import/copy builds instead of authoring them, and worst of alll, build expression becomes platform-gated.

On consoles, rotational aim assist is minimal. Because hitscan spell components are relatively limited and projectiles are deterministic, the assist would otherwise need to take into account projectile travel time. This does favor mouse precision, but to counter this, it will require bespoke gamepad tuning. Ganymede cannot borrow Destiny/CoD-like aim assist without breaking its design.

Accessibility between the platforms will also stay relatively the same. Colorblind filters will be tuned for TV vs monitor, however, along with different text scaling. There will be a default-off option for visualizing audio sources on all platforms (indicating the direction, distance, and category of audio through a ring on the HUD, very similar to Fortnite). Key rebinding will allow remapping most keys (just a simple button replacement scheme), but some UI-only actions may not be remappable (moving between UI elements, for example). Some actions may also be always mapped to the same key (such as the ping wheel and spell selection wheel during respawn).

For rendering on platforms, they will generally have the same options for configuring quality (ignoring hardware limits, in the case of unsupported HDR, TAA, etc.). The priority for rendering should be stable frame pacing (particularly for signaling mana burn timing) and no hitching during UI transitions (i.e. respawning). There will need to be platform-specific scalability buckets, with perhaps even aggressive CPU budgeting on consoles. Competitive needs the experience to stay the same on both PC and console.

For networking, a central server authority is required to validate gameplay actions and perform anticheat. These needs platform-agnostic server releases, with client-side predication that is tuned per input method. Lag compensation should not favor hitscan (especially since most spell components aren't hitscan). There must also be robust disconnect/rejoin handling, as well as NAT traversal that works for nearly any client network setup. Crossplay will be supported and is on by default (configurable in the settings). However, a separate setting for input-based matchmaking pools (segregating between keyboard and mouse vs. gamepad) will be on by default as well. Ranked crossplay without input filtering will cause resentment (console players are likely to blame PC when losing, regardless of validity). This isn't so much of a technical choice as it is a social choice.

As for players self-hosting, servers will support clients on any platform, but the server binaries themself will only run on Windows/Linux (in particular, Linux is actually the first-class citizen here, since it's easier to manage). Any client (including consoles) will have a setting that allows them to change the IP to which server they connect to, allowing them to change to community-run servers. This will be accompanied by an explicit acknowledgment UI flow that absolves responsibility or support.

Spell blueprints, loadouts, and replays are also exportable from in-game on all platforms. On PC, blueprints and loadouts can be exported in a text file format (though not necessarily human readable). These can be reimported on PC. On both PCs and consoles, blueprints/loadouts can be also have an 8-character, base-64 id generated for them (alphanumeric, -, \_), hiccupcan be used elsewhere for importing it (effectively creates a database entry accessible through an HTTP request to the game server that just holds the same serialized text data). Replays will be exported and placed in their platform-specific folders.

### Multiplayer Requirements

- Authoritative central servers

Ganymede requires a central server authority to validate gameplay actions and perform anticheat. Server binaries will also be freely available so players can self-host in an "offline" mode. Authenticated servers can call central APIs for identity/entitlements/ranking, while non-authenticated servers can run independently. Servers must also run in a headless mode on either Windows or Linux (Linux is first-class, though).

- Anticheat

**No** kernel-level anticheat will be used to maintain Linux compatibility. Servers must be able to perform their own authoritative checks, including behavioral heuristics and telemetry analysis. User-space anticheat will still be used (but cannot be relied on), and active moderation will be required. Client binaries will also be signed, and authenticated servers (both official and self-hosted) will reqdivergeification.

- Crossplatform

Determinism and parity between platforms is also essential. A native Steam Deck port is planned, and special consideration needs to be taken into account for it (Linux, gamepad with mouse-like controls, less performance).

- Input-based Matchmaking

Segregating input methods (keyboard/mouse vs. gamepad) into separate matchmaking pools will be available and default-on to avoid perceived fairness issues.

- Client-Side Prediction

There must be client prediction tuned per input method with lag compensation that doesn't necessarily favor hitscan. Although the older titles that Ganymede is inspired from did not use client prediction in this way (actions were performed on the server when the packet arrived, with no timestamps or rollback), this has largely been abandoned by all modern titles, and players will expect no different.

- Client Disconnect/Rejoin

Players must be able to stay within a match, even if their network experiences a hiccup. Longer hiccups will kick the player, however, and the ranking algorithm must accommodate.

- NAT Traversal

Clients can have nearly NAT setup on their end, and the central servers must be able to handle those. NAT punch-through workarounds are unlikely to be maintainable long-term.

- Ranking / Elo System

An invisible elo algorithm scores wins, captures, and other performance metrics. Capture the flag matches also follow a best 2/3 format in 12-minute rounds, with tie-breaking. Matchmaking must account for the same player switching between input devices (make sure the same elo translates well across different matchmaking pools).

- Spellcrafting Validation

The modular spell system must validate player-created spells (complexity/mana cost caps, allowed parameter ranges) to prevent cheating or authoritative-breaking spells. This includes the schema for spell blueprints, deterministic serialization/versioning, and runtime validation for allowing a spell to be used in PvP.

- Determinism & Tick Model

A specific tick rate on the server must be decided early. Simulation must be deterministic so client prediction and server reconciliation don't diverge frequently. The highest level of competitive players will be able to intuitively feel the tick rate. A hybrid rollback-based reconciliation model will be the default, but prototyping should account for transitioning for other methods.

- Telemetry, Logging, & Replay Support

For systems tuning, elo calculations, and dispute/cheat analysis, servers must log relevant events with sufficient fidelity (timestamps, authoritative outcomes, spell blueprints used, etc.). Matches effectively need to be fully replayable end-to-end.

- Scalability

Autoscaling for match servers, lobby services, and matchmaking. DDoS protection must also exist, with built-in rate limiting for servers (eases the maintenance of self-hosting). A per-player bandwidth budget (KB/s) must also be created and regularly tested against during development (prepare for worst-case spell spam).

- Live Ops Tools

Even for self-hosting, managing servers requires UIs and dashboards for server lists, player reports, live logs, bans, map rotations, and server config.

- Legal Data Retention & Regional Compliance

Because Ganymede collects telemetry and users create accounts, there must be compliance with GDPR/COPPA/etc. in all regions the game is officially released in. This includes PII handling, retention windows, export tools, etc.

- Third-Party Services

For official servers, the exact services used for matchmaking, auth, leaderboards, etc. need to defined (likely AWS). Tools must be created for easy migration and self-hosted options to allow self-hosted servers to be easily created. Consider running own orchestration through something like Kubernetes as well.

## Appendix

### Terminology

Most of these terms have specific meanings and should be used consistently throughout the project to align discussions and reduce ambiguity. This terminology should be treated as a living reference. New terms should be added when systems or language patterns stabilize across disciplines.

**Arcane-Industrial Era**

The current technological age of the setting, defined by industrialized, weaponized mana systems.

**Blueprint**

A saved, named configuration of a loadout (including spells, tuning, and metadata such as tags or color). Blueprints are shareable and editable, and act as the primary unit of theorycrafting.

**Build**

An informal term referring to the functional expression of a loadout or blueprint in play. Often used when discussing meta strategies rather than saved data.

**Capture the Flag** (CTF)

The primary competitive mode. Teams contest infrastructure assets referred to as flags (data cores, crystalline mana matrices, etc.).

**Commitment**

A point of no easy retreat created by level geometry, resource expenditure, or objective pressure. Commitment is intentionally reinforced by mana burn mechanics.

**Complexity**

An abstract budget representing the structural and computational cost of a spell. Total complexity limits prevent the creation of single-cast match-deciding spells that ignore survivability tradeoffs.

**Component Unlock**

The acquisition of new spell modules or parameters through achievements or master conditions.

**Flag Carrier**

A player currently holding the objective. Flag carriers cannot cast spells and must rely on teammates for protection.

**Flag Return**

The act of reclaiming a dropped friendly flag by standing near it briefly, teleporting it back to base.

**Health**

A non-regenerating resource representing physical survivability. Health is permanently lost until death. Health can be consumed directly through overcasting (mana burn) or taking damage.

**Infrastructure Asset**

A diegetic interpretation of objectives (flags), such as data cores, mana spools, or passkeys, representing strategic control rather than symbolic trophies.

**Loadout**

A collection of six spells authored by the player. A loadout represents a tactical identity or role concept (e.g. runner, suppressor, anchor).

**Mana Burn** (Mana Overcasting State)

A high-risk state entered when the player casts a spell without sufficient mana. The remaining cost is paid with health, mana regeneration rate is reduced until full recovery, and all subsequent spell costs draw from health while in this state. Mana burn is a core skill-expression mechanic, not a failure state.

**Mana**

The primary resource used to cast spells. Mana regenerates over time based on loadout tuning, environment, and current state. Mana is intentionally volatile and meant to be overspent.

**Mastery**

Proficiency demonstrated through repeated effective use of mechanics or modules, often tied to unlock conditions.

**Meta**

The evolving ecosystem of dominant strategies, builds, and counterplays shaped by player behavior rather than explicit progression systems.

**Module Parameters**

Tunable numeric or boolean values on a module (damage, velocity, cost multipliers, cooldown scaling, etc.). Adjusting parameters affects spell behavior, mana cost, and complexity.

**Module**

A discrete building block of a spell. Modules define delivery methods, effects, and tunable parameters. Modules are chained together via node connection in the Spellcrafting UI, very similar to node-based visual editors for programming.

**Operator**

The narrative framing for player characters. Trained specialists or contractors, not heroes or champions.

**Overtime**

A sudden-death extension triggered by tied rounds. Respawn timers escalate to force resolution.

**Power Position**

A spatial advantage point that offers strong sightlines or control but requires sustained resource commitment to hold.

**Primary Action**

The default cast behavior of a spell, bound to the primary fire input.

**Resource Pressure Zone**

Level areas designed to encourage mana expenditure and overcasting, such as midfields, chokepoints, or long sightline pushes.

**Respawn Window**

The downtime after death during which players may edit their active spell slots before re-entering the match.

**Role**

An informal, emergent team function (runner, support, disruptor, anchor, skirmisher, etc.). Roles are not system-defined and arise from loadout choices and team coordination.

**Rotational Lane**

A traversal route enabling macro repositioning, flanking, or flag running. Typically higher risk and longer exposure.

**Round**

A single timed segment of a match. Matches are best two out of three rounds.

**Secondary Action** (Alt-Fire)

An optional, unlockable secondary cast mode for a spell. Used for advanced builds and higher skill ceilings.

**Spell Library**

The UI surface where alll authored spells are stored, edited, duplicated, and tested.

**Spell Matrix**

An in-universe term for the structured, engineered framework that enables modular spellcasting.

**Spell Slot**

An active slot during gameplay. Players may only equip three spells at a time, enforcing commitment and identity during a life.

**Spell**

A player-authored active ability constructed from multiple modules. Spells define all offensive, defensive, mobility, and utility actions in the game.

**Staging Zone**

Semi-safe areas where teams regroup, regenerate mana, and prepare coordinated actions.

**Stamina**

A secondary resource used for movement actions (sprinting, jumping, sliding, mantling, etc.). Stamina regenerates quickly but imposes penalties when exhausted.

**Tempo**

A tactical concept describing short-term advantage gained by spending resources aggressively (mana and/or health). High tempo often trades survivability for positional, timing, or objective advantage.

**Test Range**

A player-facing controlled sandbox environment used to validate spell behaviors, DPS, mana efficiency, and mechanical tuning without match pressure.

**Theorycrafting**

The analytical practice of optimizing spells, loadouts, and strategies through experimentation, math, and meta discussion.
