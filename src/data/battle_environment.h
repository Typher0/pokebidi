#include "battle_anim_scripts.h"

#define ENVIRONMENT_BACKGROUND(Background)             \
{                                                      \
    .tileset = gBattleEnvironmentTiles_##Background,   \
    .tilemap = gBattleEnvironmentTilemap_##Background, \
}

const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT] =
{

    [BATTLE_ENVIRONMENT_GRASS] =
    {
        .name = _("Grass"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_STUN_SPORE,
    #endif
        .secretPowerAnimation = gBattleAnimMove_NeedleArm,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_SLEEP : MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(12, 24, 2),
        .entry = ENVIRONMENT_ENTRY(TallGrass),
        .background = ENVIRONMENT_BACKGROUND(TallGrass),
        .palette = gBattleEnvironmentPalette_TallGrass,
        .battleIntroSlide = BattleIntroSlide1,
    },
    
    [BATTLE_ENVIRONMENT_ARENA] =
    {
        .name = _("Long Grass"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_RAZOR_LEAF,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NeedleArm : gBattleAnimMove_MagicalLeaf,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(0, 15, 2),
        .entry = ENVIRONMENT_ENTRY(LongGrass),
        .background = ENVIRONMENT_BACKGROUND(LongGrass),
        .palette = gBattleEnvironmentPalette_LongGrass,
        .battleIntroSlide = BattleIntroSlide1,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST] =
    {
        .name = _("Sand"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_6 ? MOVE_EARTH_POWER : MOVE_EARTHQUAKE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudShot,
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Sand),
        .background = ENVIRONMENT_BACKGROUND(Sand),
        .palette = gBattleEnvironmentPalette_Sand,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .name = _("Underwater"),
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_6 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Waterfall,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_6 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(0, 0, 18),
        .entry = ENVIRONMENT_ENTRY(Underwater),
        .background = ENVIRONMENT_BACKGROUND(Underwater),
        .palette = gBattleEnvironmentPalette_Underwater,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_WATER] =
    {
        .name = _("Water"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Surf,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(11, 22, 31),
        .entry = ENVIRONMENT_ENTRY(Water),
        .background = ENVIRONMENT_BACKGROUND(Water),
        .palette = gBattleEnvironmentPalette_Water,
        .battleIntroSlide = BattleIntroSlide2,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST_E] =
    {
        .name = _("Pond"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_BUBBLE_BEAM,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_BubbleBeam,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(11, 22, 31),
        .entry = ENVIRONMENT_ENTRY(PondWater),
        .background = ENVIRONMENT_BACKGROUND(PondWater),
        .palette = gBattleEnvironmentPalette_PondWater,
        .battleIntroSlide = BattleIntroSlide1,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST_N] =
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
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
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
    
    [BATTLE_ENVIRONMENT_BRIDGE_E] =
    {
        .naturePower = MOVE_BRICK_BREAK,
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(BridgeE),
    },
    
    [BATTLE_ENVIRONMENT_BRIDGE_N] =
    {
        .naturePower = MOVE_BRICK_BREAK,
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(BridgeN),
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
    
    [BATTLE_ENVIRONMENT_CAVE_DARK] =
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
    
    [BATTLE_ENVIRONMENT_CITY_E] =
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
    
    [BATTLE_ENVIRONMENT_CITY_N] =
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
    
    [BATTLE_ENVIRONMENT_CRAG] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .background = ENVIRONMENT_BACKGROUND(Crag),
    },
    
    [BATTLE_ENVIRONMENT_CRAG_E] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .background = ENVIRONMENT_BACKGROUND(CragE),
    },
    
    [BATTLE_ENVIRONMENT_CRAG_N] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_FLYING,
        .background = ENVIRONMENT_BACKGROUND(CragN),
    },
    
    [BATTLE_ENVIRONMENT_DESERT] =
    {
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_GROUND,
        .background = ENVIRONMENT_BACKGROUND(Desert),
    },
    
    [BATTLE_ENVIRONMENT_DESERT_E] =
    {
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_GROUND,
        .background = ENVIRONMENT_BACKGROUND(DesertE),
    },
    
    [BATTLE_ENVIRONMENT_DESERT_N] =
    {
        .naturePower = MOVE_SCORCHING_SANDS,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_GROUND,
        .background = ENVIRONMENT_BACKGROUND(DesertN),
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
    
    [BATTLE_ENVIRONMENT_INDOOR] =
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
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_LAB] =
    {
        .name = _("Sky Pillar"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = gBattleAnimMove_Gust,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .name = _("Burial Ground"),
        .naturePower = MOVE_SHADOW_BALL,
        .secretPowerAnimation = gBattleAnimMove_ShadowSneak,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_GHOST,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_ROCKY_E] =
    {
        .name = _("Puddle"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_5 ? gBattleAnimMove_MudShot : gBattleAnimMove_MudSlap,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_5 ? MOVE_EFFECT_SPD_MINUS_1 : MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_ROCKY_N] =
    {
        .name = _("Marsh"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_ROUTE_E] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_ROUTE_N] =
    {
        .naturePower = MOVE_TRAILBLAZE,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GRASS,
        .background = ENVIRONMENT_BACKGROUND(RouteN),
    },
    
    [BATTLE_ENVIRONMENT_SAFARI] =
    {
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_GRASS,
        .background = ENVIRONMENT_BACKGROUND(Safari),
    },
    
    [BATTLE_ENVIRONMENT_SAFARI_E] =
    {
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_GRASS,
        .background = ENVIRONMENT_BACKGROUND(SafariE),
    },
    
    [BATTLE_ENVIRONMENT_SAFARI_N] =
    {
        .naturePower = MOVE_GRASSY_GLIDE,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_GRASS,
        .background = ENVIRONMENT_BACKGROUND(SafariN),
    },
    
    [BATTLE_ENVIRONMENT_SEA] =
    {
        .naturePower = MOVE_SURF,
        .secretPowerEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(Sea),
    },
    
    [BATTLE_ENVIRONMENT_SEA_E] =
    {
        .naturePower = MOVE_SURF,
        .secretPowerEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(SeaE),
    },
    
    [BATTLE_ENVIRONMENT_SEA_N] =
    {
        .naturePower = MOVE_SURF,
        .secretPowerEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(SeaN),
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
    
    [BATTLE_ENVIRONMENT_SWAMP_N] =
    {
        .name = _("Ice"),
        .naturePower = MOVE_ICE_BEAM,
        .secretPowerAnimation = gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(Underwater),
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER_E] =
    {
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(UnderwaterE),
    },
    
    [BATTLE_ENVIRONMENT_UNDERWATER_N] =
    {
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(UnderwaterN),
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO] =
    {
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO_E] =
    {
        .name = _("Distortion World"),
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerAnimation = gBattleAnimMove_Pound,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
    
    [BATTLE_ENVIRONMENT_VOLCANO_N] =
    {
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .background = ENVIRONMENT_BACKGROUND(VolcanoN),
    },
    
    [BATTLE_ENVIRONMENT_MOOSE] =
    {
        .naturePower = MOVE_DRACO_METEOR,
        .secretPowerAnimation = gBattleAnimMove_Swift,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_DRAGON,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_ULTRA_SPACE] =
    {
        .name = _("Ultra Space"),
        .naturePower = MOVE_PSYSHOCK,
        .secretPowerAnimation = gBattleAnimMove_Psywave,
        .secretPowerEffect = MOVE_EFFECT_DEF_MINUS_1,
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
