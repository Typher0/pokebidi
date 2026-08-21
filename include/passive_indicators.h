#ifndef GUARD_PASSIVE_INDICATORS_H
#define GUARD_PASSIVE_INDICATORS_H
 
#include "constants/passive.h"
 
extern const u8 *const gPassiveIndicatorGfx[PASSIVES_COUNT];
extern const struct SpritePalette gSpritePalette_PassiveIndicator; // NEW - was static in passive_indicator
 
// Palette tag for the per-Passive battle indicator graphics above. Defined
// locally here rather than pulled from battle_interface.h (where
// TAG_TERA_INDICATOR_PAL/TAG_MEGA_INDICATOR_PAL live) - that dependency
// chain drags in battle_controllers.h, which assumes battle.h is already
// included by whatever file reaches it, and passive_indicators.c doesn't
// need any of that just for a tag constant. Value just needs to be unique
// among concurrently-loaded palette tags - swap it if it collides with
// something else in your project.
#define TAG_PASSIVE_INDICATOR_PAL 0xD77B
 
// Summary screen badge sprite tile tag - distinct from TAG_PASSIVE_INDICATOR_PAL
// above (that one's a palette tag, this one reserves a VRAM tile slot on the
// summary screen specifically, not the battle HUD). Value just needs to be
// unique among concurrently-loaded sprite tile tags - swap it if it collides
// with something else in your project.
#define TAG_PASSIVE_BADGE 0xD1B0
 
#endif // GUARD_PASSIVE_INDICATORS_H
