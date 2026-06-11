#include "battle_anim_scripts.h"

#define ENVIRONMENT_BACKGROUND(Background)             \
{                                                      \
    .tileset = gBattleEnvironmentTiles_##Background,   \
    .tilemap = gBattleEnvironmentTilemap_##Background, \
}

#define ENVIRONMENT_ENTRY(Background)                      \
{                                                          \
    .tileset = gBattleEnvironmentAnimTiles_##Background,   \
    .tilemap = gBattleEnvironmentAnimTilemap_##Background, \
}

#define DEFAULT_CAMOUFLAGE_BLEND RGB_WHITE

// Cave values. Used for BATTLE_ENVIRONMENT_CAVE as well as BATTLE_ENVIRONMENT_GROUDON and BATTLE_ENVIRONMENT_KYOGRE
#if B_NATURE_POWER_MOVES >= GEN_6
    #define CAVE_NATURE_POWER MOVE_POWER_GEM
#elif B_NATURE_POWER_MOVES >= GEN_4
    #define CAVE_NATURE_POWER MOVE_ROCK_SLIDE
#else
    #define CAVE_NATURE_POWER MOVE_SHADOW_BALL
#endif
#define CAVE_SECRET_POWER_ANIMATION B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_Bite
#define CAVE_SECRET_POWER_EFFECT    MOVE_EFFECT_FLINCH
#define CAVE_CAMOUFLAGE_TYPE        TYPE_ROCK
#define CAVE_CAMOUFLAGE_BLEND       RGB(14, 9, 3)
#define CAVE_BATTLE_INTRO_SLIDE     BattleIntroSlide1

// Building values. Used for BATTLE_ENVIRONMENT_BUILDING as well as the environments that come from the vanilla MAP_BATTLE_SCENEs: BATTLE_ENVIRONMENT_PLAIN, BATTLE_ENVIRONMENT_FRONTIER, BATTLE_ENVIRONMENT_GYM, BATTLE_ENVIRONMENT_LEADER, BATTLE_ENVIRONMENT_MAGMA, BATTLE_ENVIRONMENT_AQUA, BATTLE_ENVIRONMENT_SIDNEY, BATTLE_ENVIRONMENT_PHOEBE, BATTLE_ENVIRONMENT_GLACIA, BATTLE_ENVIRONMENT_DRAKE, BATTLE_ENVIRONMENT_CHAMPION
#define BUILDING_NATURE_POWER        B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT
#if B_SECRET_POWER_ANIMATION >= GEN_7
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_SpitUp
#elif B_SECRET_POWER_ANIMATION >= GEN_4
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_BodySlam
#else
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_Strength
#endif
#define BUILDING_SECRET_POWER_EFFECT MOVE_EFFECT_PARALYSIS
#define BUILDING_CAMOUFLAGE_TYPE     TYPE_NORMAL
#define BUILDING_CAMOUFLAGE_BLEND    RGB_WHITE
#define BUILDING_BATTLE_INTRO_SLIDE  BattleIntroSlide3

// Plain values. USED for BATTLE_ENVIRONMENT_PLAIN as well as BATTLE_ENVIRONMENT_RAYQUAZA
// (BATTLE_ENVIRONMENT_SKY_PILLAR wasn't introduced until Gen6, so Sky Pillar's roof counts as a Route which uses Plain)
#if B_NATURE_POWER_MOVES >= GEN_6
    #define PLAIN_NATURE_POWER MOVE_TRI_ATTACK
#elif B_NATURE_POWER_MOVES >= GEN_4
    #define PLAIN_NATURE_POWER MOVE_EARTHQUAKE
#else
    #define PLAIN_NATURE_POWER MOVE_SWIFT
#endif
#if B_SECRET_POWER_ANIMATION >= GEN_7
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_SpitUp
#elif B_SECRET_POWER_ANIMATION == GEN_6
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_BodySlam
#elif B_SECRET_POWER_ANIMATION >= GEN_4
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_MudSlap
#else
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_Slam
#endif
#define PLAIN_SECRET_POWER_EFFECT (B_SECRET_POWER_EFFECT == GEN_4 || B_SECRET_POWER_EFFECT == GEN_5) ? MOVE_EFFECT_ACC_MINUS_1 : MOVE_EFFECT_PARALYSIS
#define PLAIN_CAMOUFLAGE_TYPE     (B_CAMOUFLAGE_TYPES == GEN_4 || B_CAMOUFLAGE_TYPES == GEN_5) ? TYPE_GROUND : TYPE_NORMAL
#define PLAIN_CAMOUFLAGE_BLEND    RGB_WHITE
#define PLAIN_BATTLE_INTRO_SLIDE  BattleIntroSlide3

const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT] =
{
    
    [BATTLE_ENVIRONMENT_ARENA] =
    {
        .name = _("Arena"),
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(0, 15, 2),
        .entry = ENVIRONMENT_ENTRY(Arena),
        .background = ENVIRONMENT_BACKGROUND(Arena),
        .palette = gBattleEnvironmentPalette_Arena,
        .battleIntroSlide = BattleIntroSlide1,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST] =
    {
        .name = _("Autumn Forest"),
        .naturePower = MOVE_MAGICAL_LEAF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NeedleArm : gBattleAnimMove_NeedleArm,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(0, 15, 2),
        .entry = ENVIRONMENT_ENTRY(LongGrass),
        .background = ENVIRONMENT_BACKGROUND(LongGrass),
        .palette = gBattleEnvironmentPalette_LongGrass,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_SAND] =
    {
        .name = _("Sand"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_6 ? MOVE_EARTH_POWER : MOVE_EARTHQUAKE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(AutumnForest),
        .background = ENVIRONMENT_BACKGROUND(AutumnForest),
        .palette = gBattleEnvironmentPalette_AutumnForest,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST_E] =
    {
        .name = _("Autumn Forest"),
        .naturePower = MOVE_MAGICAL_LEAF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NeedleArm : gBattleAnimMove_NeedleArm,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(AutumnForestE),
        .background = ENVIRONMENT_BACKGROUND(AutumnForestE),
        .palette = gBattleEnvironmentPalette_AutumnForestE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST_N] =
    {
        .name = _("Autumn Forest"),
        .naturePower = MOVE_MAGICAL_LEAF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NeedleArm : gBattleAnimMove_NeedleArm,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(AutumnForestN),
        .background = ENVIRONMENT_BACKGROUND(AutumnForestN),
        .palette = gBattleEnvironmentPalette_AutumnForestN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BEACH] =
    {
        .name = _("Beach"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Beach),
        .background = ENVIRONMENT_BACKGROUND(Beach),
        .palette = gBattleEnvironmentPalette_Beach,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BEACH_E] =
    {
        .name = _("Beach"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(BeachE),
        .background = ENVIRONMENT_BACKGROUND(BeachE),
        .palette = gBattleEnvironmentPalette_BeachE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BEACH_N] =
    {
        .name = _("Beach"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(BeachN),
        .background = ENVIRONMENT_BACKGROUND(BeachN),
        .palette = gBattleEnvironmentPalette_BeachN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BRIDGE] =
    {
        .name = _("Bridge"),
        .naturePower = MOVE_VACUUM_WAVE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_KarateChop : gBattleAnimMove_KarateChop,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_FIGHTING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Bridge),
        .background = ENVIRONMENT_BACKGROUND(Bridge),
        .palette = gBattleEnvironmentPalette_Bridge,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BRIDGE_E] =
    {
        .name = _("Bridge"),
        .naturePower = MOVE_VACUUM_WAVE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_KarateChop : gBattleAnimMove_KarateChop,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_FIGHTING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(BridgeE),
        .background = ENVIRONMENT_BACKGROUND(BridgeE),
        .palette = gBattleEnvironmentPalette_BridgeE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_BRIDGE_N] =
    {
        .name = _("Bridge"),
        .naturePower = MOVE_VACUUM_WAVE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_KarateChop : gBattleAnimMove_KarateChop,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_FIGHTING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(BridgeN),
        .background = ENVIRONMENT_BACKGROUND(BridgeN),
        .palette = gBattleEnvironmentPalette_BridgeN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CAVE] =
    {
        .name = _("Cave"),
        .naturePower = MOVE_POWER_GEM,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_RockThrow,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Cave),
        .background = ENVIRONMENT_BACKGROUND(Cave),
        .palette = gBattleEnvironmentPalette_Cave,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_DARK] =
    {
        .name = _("Cave Dark"),
        .naturePower = MOVE_ANCIENT_POWER,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_RockThrow,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CaveDark),
        .background = ENVIRONMENT_BACKGROUND(CaveDark),
        .palette = gBattleEnvironmentPalette_CaveDark,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_MAGMA] =
    {
        .name = _("Cave Magma"),
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_Incinerate : gBattleAnimMove_Incinerate,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CaveMagma),
        .background = ENVIRONMENT_BACKGROUND(CaveMagma),
        .palette = gBattleEnvironmentPalette_CaveMagma,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_SNOW] =
    {
        .name = _("Cave Snow"),
        .naturePower = MOVE_FROST_BREATH,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IceShard : gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CaveSnow),
        .background = ENVIRONMENT_BACKGROUND(CaveSnow),
        .palette = gBattleEnvironmentPalette_CaveSnow,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CITY] =
    {
        .name = _("City"),
        .naturePower = MOVE_WRING_OUT,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(City),
        .background = ENVIRONMENT_BACKGROUND(City),
        .palette = gBattleEnvironmentPalette_City,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_CITY_E] =
    {
        .name = _("City"),
        .naturePower = MOVE_WRING_OUT,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CityE),
        .background = ENVIRONMENT_BACKGROUND(CityE),
        .palette = gBattleEnvironmentPalette_CityE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CITY_N] =
    {
        .name = _("City"),
        .naturePower = MOVE_WRING_OUT,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CityN),
        .background = ENVIRONMENT_BACKGROUND(CityN),
        .palette = gBattleEnvironmentPalette_CityN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CRAG] =
    {
        .name = _("Crag"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_AirCutter : gBattleAnimMove_AirCutter,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Crag),
        .background = ENVIRONMENT_BACKGROUND(Crag),
        .palette = gBattleEnvironmentPalette_Crag,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CRAG_E] =
    {
        .name = _("Crag"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_AirCutter : gBattleAnimMove_AirCutter,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CragE),
        .background = ENVIRONMENT_BACKGROUND(CragE),
        .palette = gBattleEnvironmentPalette_CragE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_CRAG_N] =
    {
        .name = _("Crag"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_AirCutter : gBattleAnimMove_AirCutter,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(CragN),
        .background = ENVIRONMENT_BACKGROUND(CragN),
        .palette = gBattleEnvironmentPalette_CragN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_DESERT] =
    {
        .name = _("Desert"),
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudSlap,
        .secretPowerEffect = MOVE_EFFECT_ACC_DOWN_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Desert),
        .background = ENVIRONMENT_BACKGROUND(Desert),
        .palette = gBattleEnvironmentPalette_Desert,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_DESERT_E] =
    {
        .name = _("Desert"),
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudSlap,
        .secretPowerEffect = MOVE_EFFECT_ACC_DOWN_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(DesertE),
        .background = ENVIRONMENT_BACKGROUND(DesertE),
        .palette = gBattleEnvironmentPalette_DesertE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_DESERT_N] =
    {
        .name = _("Desert"),
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudSlap,
        .secretPowerEffect = MOVE_EFFECT_ACC_DOWN_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(DesertN),
        .background = ENVIRONMENT_BACKGROUND(DesertN),
        .palette = gBattleEnvironmentPalette_DesertN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_GYM] =
    {
        .name = _("Gym"),
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Gym),
        .background = ENVIRONMENT_BACKGROUND(Gym),
        .palette = gBattleEnvironmentPalette_Gym,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_INDOOR] =
    {
        .name = _("Indoor"),
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Indoor),
        .background = ENVIRONMENT_BACKGROUND(Indoor),
        .palette = gBattleEnvironmentPalette_Indoor,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_LAB] =
    {
        .name = _("Lab"),
        .naturePower = MOVE_CHARGE_BEAM,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_ThunderShock : gBattleAnimMove_ThunderShock,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Lab),
        .background = ENVIRONMENT_BACKGROUND(Lab),
        .palette = gBattleEnvironmentPalette_Lab,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .name = _("Mountain"),
        .naturePower = MOVE_ROCK_SLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_RockThrow,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Mountain),
        .background = ENVIRONMENT_BACKGROUND(Mountain),
        .palette = gBattleEnvironmentPalette_Mountain,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN_E] =
    {
        .name = _("Mountain"),
        .naturePower = MOVE_ROCK_SLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_RockThrow,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(MountainE),
        .background = ENVIRONMENT_BACKGROUND(MountainE),
        .palette = gBattleEnvironmentPalette_MountainE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN_N] =
    {
        .name = _("Mountain"),
        .naturePower = MOVE_ROCK_SLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_RockThrow,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(MountainE),
        .background = ENVIRONMENT_BACKGROUND(MountainN),
        .palette = gBattleEnvironmentPalette_MountainN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN_SNOW] =
    {
        .name = _("Mountain Snow"),
        .naturePower = MOVE_AVALANCHE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IceShard : gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(MountainSnow),
        .background = ENVIRONMENT_BACKGROUND(MountainSnow),
        .palette = gBattleEnvironmentPalette_MountainSnow,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN_SNOW_E] =
    {
        .name = _("Mountain Snow"),
        .naturePower = MOVE_AVALANCHE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IceShard : gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(MountainSnowE),
        .background = ENVIRONMENT_BACKGROUND(MountainSnowE),
        .palette = gBattleEnvironmentPalette_MountainSnowE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN_SNOW_N] =
    {
        .name = _("Mountain Snow"),
        .naturePower = MOVE_AVALANCHE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IceShard : gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(MountainSnowN),
        .background = ENVIRONMENT_BACKGROUND(MountainSnowN),
        .palette = gBattleEnvironmentPalette_MountainSnowN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROCKY] =
    {
        .name = _("Rocky"),
        .naturePower = MOVE_STONE_EDGE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockSlide : gBattleAnimMove_RockSlide,
        .secretPowerEffect = MOVE_EFFECT_DEF_DOWN_1,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Rocky),
        .background = ENVIRONMENT_BACKGROUND(Rocky),
        .palette = gBattleEnvironmentPalette_Rocky,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROCKY_E] =
    {
        .name = _("Rocky"),
        .naturePower = MOVE_STONE_EDGE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockSlide : gBattleAnimMove_RockSlide,
        .secretPowerEffect = MOVE_EFFECT_DEF_DOWN_1,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(RockyE),
        .background = ENVIRONMENT_BACKGROUND(RockyE),
        .palette = gBattleEnvironmentPalette_RockyE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROCKY_N] =
    {
        .name = _("Rocky"),
        .naturePower = MOVE_STONE_EDGE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_DEF_DOWN_1,
        .camouflageType = TYPE_ROCK,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(RockyN),
        .background = ENVIRONMENT_BACKGROUND(RockyN),
        .palette = gBattleEnvironmentPalette_RockyN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROUTE] =
    {
        .name = _("Route"),
        .naturePower = MOVE_TRAILBLAZE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Route),
        .background = ENVIRONMENT_BACKGROUND(Route),
        .palette = gBattleEnvironmentPalette_Route,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROUTE_E] =
    {
        .name = _("Route"),
        .naturePower = MOVE_TRAILBLAZE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(RouteE),
        .background = ENVIRONMENT_BACKGROUND(RouteE),
        .palette = gBattleEnvironmentPalette_RouteE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_ROUTE_N] =
    {
        .name = _("Route"),
        .naturePower = MOVE_TRAILBLAZE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(RouteN),
        .background = ENVIRONMENT_BACKGROUND(RouteN),
        .palette = gBattleEnvironmentPalette_RouteN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SAFARI] =
    {
        .name = _("Safari"),
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Safari),
        .background = ENVIRONMENT_BACKGROUND(Safari),
        .palette = gBattleEnvironmentPalette_Safari,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SAFARI_E] =
    {
        .name = _("Safari"),
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SafariE),
        .background = ENVIRONMENT_BACKGROUND(SafariE),
        .palette = gBattleEnvironmentPalette_SafariE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SAFARI_N] =
    {
        .name = _("Safari"),
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SpitUp : gBattleAnimMove_SpitUp,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SafariN),
        .background = ENVIRONMENT_BACKGROUND(SafariN),
        .palette = gBattleEnvironmentPalette_SafariN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SEA] =
    {
        .name = _("Sea"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_DOWN_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Sea),
        .background = ENVIRONMENT_BACKGROUND(Sea),
        .palette = gBattleEnvironmentPalette_Sea,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SEA_E] =
    {
        .name = _("Sea"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_DOWN_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SeaE),
        .background = ENVIRONMENT_BACKGROUND(SeaE),
        .palette = gBattleEnvironmentPalette_SeaE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SEA_N] =
    {
        .name = _("Sea"),
        .naturePower = MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_WaterPulse,
        .secretPowerEffect = MOVE_EFFECT_ATK_DOWN_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SeaN),
        .background = ENVIRONMENT_BACKGROUND(SeaN),
        .palette = gBattleEnvironmentPalette_SeaN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SNOW] =
    {
        .name = _("Snow"),
        .naturePower = MOVE_BLIZZARD,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IcyWind : gBattleAnimMove_IcyWind,
        .secretPowerEffect = MOVE_EFFECT_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Snow),
        .background = ENVIRONMENT_BACKGROUND(Snow),
        .palette = gBattleEnvironmentPalette_Snow,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SNOW_E] =
    {
        .name = _("Snow"),
        .naturePower = MOVE_BLIZZARD,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IcyWind : gBattleAnimMove_IcyWind,
        .secretPowerEffect = MOVE_EFFECT_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SnowE),
        .background = ENVIRONMENT_BACKGROUND(SnowE),
        .palette = gBattleEnvironmentPalette_SnowE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SNOW_N] =
    {
        .name = _("Snow"),
        .naturePower = MOVE_BLIZZARD,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_IcyWind : gBattleAnimMove_IcyWind,
        .secretPowerEffect = MOVE_EFFECT_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SnowN),
        .background = ENVIRONMENT_BACKGROUND(SnowN),
        .palette = gBattleEnvironmentPalette_SnowN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SWAMP] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SludgeBomb : gBattleAnimMove_SludgeBomb,
        .secretPowerEffect = MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Swamp),
        .background = ENVIRONMENT_BACKGROUND(Swamp),
        .palette = gBattleEnvironmentPalette_Swamp,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SWAMP_E] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SludgeBomb : gBattleAnimMove_SludgeBomb,
        .secretPowerEffect = MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SwampE),
        .background = ENVIRONMENT_BACKGROUND(SwampE),
        .palette = gBattleEnvironmentPalette_SwampE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_SWAMP_N] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_SludgeBomb : gBattleAnimMove_SludgeBomb,
        .secretPowerEffect = MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(SwampN),
        .background = ENVIRONMENT_BACKGROUND(SwampN),
        .palette = gBattleEnvironmentPalette_SwampN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .name = _("Underwater"),
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_6 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Waterfall,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_6 ? SECRET_POWER_ATK_MINUS_1 : SECRET_POWER_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Underwater),
        .background = ENVIRONMENT_BACKGROUND(Underwater),
        .palette = gBattleEnvironmentPalette_Underwater,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER_E] =
    {
        .name = _("Water"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Surf,
        .secretPowerEffect = SECRET_POWER_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(UnderwaterE),
        .background = ENVIRONMENT_BACKGROUND(UnderwaterE),
        .palette = gBattleEnvironmentPalette_UnderwaterE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER_N] =
    {
        .name = _("Pond"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_BUBBLE_BEAM,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_BubbleBeam,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? SECRET_POWER_ATK_MINUS_1 : SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(11, 22, 31),
        .entry = ENVIRONMENT_ENTRY(PondWater),
        .background = ENVIRONMENT_BACKGROUND(PondWater),
        .palette = gBattleEnvironmentPalette_PondWater,
        .battleIntroSlide = BattleIntroSlide1,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .name = _("Mountain"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_EARTH_POWER,
    #elif B_NATURE_POWER_MOVES >= GEN_5
        .naturePower = MOVE_EARTHQUAKE,
    #else
        .naturePower = MOVE_ROCK_SLIDE,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_5 ? gBattleAnimMove_MudSlap : gBattleAnimMove_RockThrow,
    #if B_SECRET_POWER_EFFECT >= GEN_5
        .secretPowerEffect = SECRET_POWER_ACC_MINUS_1,
    #elif B_SECRET_POWER_EFFECT == GEN_4
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
    #else
        .secretPowerEffect = MOVE_EFFECT_CONFUSION,
    #endif
        .camouflageType = B_CAMOUFLAGE_TYPES >= GEN_5 ? TYPE_GROUND : TYPE_ROCK,
        .camouflageBlend = RGB(22, 16, 10),
        .entry = ENVIRONMENT_ENTRY(Rock),
        .background = ENVIRONMENT_BACKGROUND(Rock),
        .palette = gBattleEnvironmentPalette_Rock,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_CAVE] =
    {
        .name = _("Cave"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Cave),
        .background = ENVIRONMENT_BACKGROUND(Cave),
        .palette = gBattleEnvironmentPalette_Cave,
        .battleIntroSlide = CAVE_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_BUILDING] =
    {
        .name = _("Building"),
        .naturePower = BUILDING_NATURE_POWER,
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Building,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_PLAIN] =
    {
        .name = _("Plain"),
        .naturePower = PLAIN_NATURE_POWER,
        .secretPowerAnimation = PLAIN_SECRET_POWER_ANIMATION,
        .secretPowerEffect = PLAIN_SECRET_POWER_EFFECT,
        .camouflageType = PLAIN_CAMOUFLAGE_TYPE,
        .camouflageBlend = PLAIN_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Plain,
        .battleIntroSlide = PLAIN_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_FRONTIER] =
    {
        .name = _("Frontier"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Frontier,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GYM] =
    {
        .name = _("Gym"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_BuildingGym,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },
    
    [BATTLE_ENVIRONMENT_LEADER] =
    {
        .name = _("Leader"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_BuildingLeader,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_MAGMA] =
    {
        .name = _("Magma"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumMagma,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_AQUA] =
    {
        .name = _("Aqua"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumAqua,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_SIDNEY] =
    {
        .name = _("Sidney"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumSidney,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_PHOEBE] =
    {
        .name = _("Phoebe"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumPhoebe,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GLACIA] =
    {
        .name = _("Glacia"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumGlacia,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_DRAKE] =
    {
        .name = _("Drake"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumDrake,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_CHAMPION] =
    {
        .name = _("Champion"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumWallace,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GROUDON] =
    {
        .name = _("Groudon"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Cave),
        .background = ENVIRONMENT_BACKGROUND(Cave),
        .palette = gBattleEnvironmentPalette_Groudon,
        .battleIntroSlide = CAVE_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_KYOGRE] =
    {
        .name = _("Kyogre"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Underwater),
        .background = ENVIRONMENT_BACKGROUND(Water),
        .palette = gBattleEnvironmentPalette_Kyogre,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_RAYQUAZA] =
    {
        .name = _("Rayquaza"),
        .naturePower = PLAIN_NATURE_POWER,
        .secretPowerAnimation = PLAIN_SECRET_POWER_ANIMATION,
        .secretPowerEffect = PLAIN_SECRET_POWER_EFFECT,
        .camouflageType = PLAIN_CAMOUFLAGE_TYPE,
        .camouflageBlend = PLAIN_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Rayquaza),
        .background = ENVIRONMENT_BACKGROUND(Rayquaza),
        .palette = gBattleEnvironmentPalette_Rayquaza,
        .battleIntroSlide = PLAIN_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_SOARING] =
    {
        .name = _("Soaring"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = gBattleAnimMove_Gust,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_SKY_PILLAR] =
    {
        .name = _("Sky Pillar"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = gBattleAnimMove_Gust,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_BURIAL_GROUND] =
    {
        .name = _("Burial Ground"),
        .naturePower = MOVE_SHADOW_BALL,
        .secretPowerAnimation = gBattleAnimMove_ShadowSneak,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_GHOST,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_PUDDLE] =
    {
        .name = _("Puddle"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_5 ? gBattleAnimMove_MudShot : gBattleAnimMove_MudSlap,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_5 ? SECRET_POWER_SPD_MINUS_1 : SECRET_POWER_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_MARSH] =
    {
        .name = _("Marsh"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SWAMP] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SNOW] =
    {
        .name = _("Snow"),
    #if B_NATURE_POWER_MOVES >= GEN_7
        .naturePower = MOVE_ICE_BEAM,
    #elif B_NATURE_POWER_MOVES == GEN_6
        .naturePower = MOVE_FROST_BREATH,
    #else
        .naturePower = MOVE_BLIZZARD,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_7 ? gBattleAnimMove_IceShard : gBattleAnimMove_Avalanche,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_ICE] =
    {
        .name = _("Ice"),
        .naturePower = MOVE_ICE_BEAM,
        .secretPowerAnimation = gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO] =
    {
        .name = _("Volcano"),
        .naturePower = MOVE_ERUPTION,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_Incinerate : gBattleAnimMove_Incinerate,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Volcano),
        .background = ENVIRONMENT_BACKGROUND(Volcano),
        .palette = gBattleEnvironmentPalette_Volcano,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO_E] =
    {
        .name = _("Volcano"),
        .naturePower = MOVE_ERUPTION,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_Incinerate : gBattleAnimMove_Incinerate,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(VolcanoE),
        .background = ENVIRONMENT_BACKGROUND(VolcanoE),
        .palette = gBattleEnvironmentPalette_VolcanoE,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO_N] =
    {
        .name = _("Volcano"),
        .naturePower = MOVE_ERUPTION,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_Incinerate : gBattleAnimMove_Incinerate,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(VolcanoN),
        .background = ENVIRONMENT_BACKGROUND(VolcanoN),
        .palette = gBattleEnvironmentPalette_VolcanoN,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_MOOSE] =
    {
        .name = _("Moose"),
        .naturePower = MOVE_AURA_SPHERE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MegaPunch : gBattleAnimMove_MegaPunch,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIGHTING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Moose),
        .background = ENVIRONMENT_BACKGROUND(Moose),
        .palette = gBattleEnvironmentPalette_Moose,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_TIFFANY] =
    {
        .name = _("Tiffany"),
        .naturePower = MOVE_AERIAL_ACE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_Gust : gBattleAnimMove_Gust,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Tiffany),
        .background = ENVIRONMENT_BACKGROUND(Tiffany),
        .palette = gBattleEnvironmentPalette_Tiffany,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_TINKER] =
    {
        .name = _("Tinker"),
        .naturePower = MOVE_FLASH_CANNON,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_GearGrind : gBattleAnimMove_GearGrind,
        .secretPowerEffect = MOVE_EFFECT_CONFUSION,
        .camouflageType = TYPE_STEEL,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Tinker),
        .background = ENVIRONMENT_BACKGROUND(Tinker),
        .palette = gBattleEnvironmentPalette_Tinker,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_TOBIAS] =
    {
        .name = _("Tobias"),
        .naturePower = MOVE_FOUL_PLAY,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NightShade : gBattleAnimMove_NightShade,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GHOST,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Tobias),
        .background = ENVIRONMENT_BACKGROUND(Tobias),
        .palette = gBattleEnvironmentPalette_Tobias,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_GWEN] =
    {
        .name = _("Gwen"),
        .naturePower = MOVE_DRACO_METEOR,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NightDaze : gBattleAnimMove_NightDaze,
        .secretPowerEffect = MOVE_EFFECT_RAPID_SPIN,
        .camouflageType = TYPE_DRAGON,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_ULTRA_SPACE] =
    {
        .name = _("Ultra Space"),
        .naturePower = MOVE_PSYSHOCK,
        .secretPowerAnimation = gBattleAnimMove_Psywave,
        .secretPowerEffect = SECRET_POWER_DEF_MINUS_1,
        .camouflageType = TYPE_PSYCHIC,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
};

static const struct {
    u8 mapScene;
    u8 battleEnvironment;
} sMapBattleSceneMapping[] = {
    {MAP_BATTLE_SCENE_GYM,           BATTLE_ENVIRONMENT_GYM},
    {MAP_BATTLE_SCENE_SIDNEY,        BATTLE_ENVIRONMENT_THOMAS},
    {MAP_BATTLE_SCENE_PHOEBE,        BATTLE_ENVIRONMENT_TOBIAS},
    {MAP_BATTLE_SCENE_GLACIA,        BATTLE_ENVIRONMENT_TINKER},
    {MAP_BATTLE_SCENE_DRAKE,         BATTLE_ENVIRONMENT_MOOSE},
    {MAP_BATTLE_SCENE_FRONTIER,      BATTLE_ENVIRONMENT_ARENA},
};
