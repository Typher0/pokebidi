#include "constants/abilities.h"
#include "species_info/shared_dex_text.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                  \
    .overworldPalette = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL(...)
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD(picTable, _size, shadow, _tracks, ...)                                    \
.overworldData = {                                                                          \
    .tileTag = TAG_NONE,                                                                    \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                         \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                             \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                               \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                              \
    .paletteSlot = PALSLOT_NPC_1,                                                           \
    .shadowSize = shadow,                                                                   \
    .inanimate = FALSE,                                                                     \
    .compressed = COMP,                                                                     \
    .tracks = _tracks,                                                                      \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64), \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),         \
    .anims = sAnimTable_Following,                                                          \
    .images = picTable,                                                                     \
    .affineAnims = gDummySpriteAffineAnimTable,                                             \
},                                                                                          \
    OVERWORLD_PAL(__VA_ARGS__)
#else
#define OVERWORLD(picTable, _size, shadow, _tracks, ...)
#endif //OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

#if POKEMON_NAME_LENGTH >= 12
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(DEFAULT(_name, __VA_ARGS__))
#else
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(_name)
#endif

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gFallbackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_None,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
    #if OW_POKEMON_OBJECT_EVENTS
        .overworldData = {
            .tileTag = TAG_NONE,
            .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
            .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
            .size = 512,
            .width = 32,
            .height = 32,
            .paletteSlot = PALSLOT_NPC_1,
            .shadowSize = SHADOW_SIZE_M,
            .inanimate = FALSE,
            .compressed = COMP,
            .tracks = TRACKS_FOOT,
            .oam = &gObjectEventBaseOam_32x32,
            .subspriteTables = sOamTables_32x32,
            .anims = sAnimTable_Following,
            .images = sPicTable_Substitute,
            .affineAnims = gDummySpriteAffineAnimTable,
        },
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .eggMoveLearnset = sNoneEggMoveLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    /* You may add any custom species below this point based on the following structure: */

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        //.frontPicFemale = gMonFrontPic_CircledQuestionMark,
        //.frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        //.backPicFemale = gMonBackPic_CircledQuestionMarkF,
        //.backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        //.paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        //.iconSpriteFemale = gMonIcon_QuestionMarkF,
        //.iconPalIndexFemale = 1,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        .allPerfectIVs = TRUE,
    },
    */

#if P_FAMILY_HAMSNUG
    [SPECIES_HAMSNUG] =
    {
        .baseHP        = 54,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_ICE),
        .catchRate = 255,
        .expYield = 50,
        .evYield_HP    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_COZY, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hamsnug"),
        .cryId = CRY_HAMSNUG,
        .natDexNum = NATIONAL_DEX_HAMSNUG,
        .categoryName = _("Hampster"),
        .height = 3,
        .weight = 59,
        .description = COMPOUND_STRING(
            "Its fur helps keep it warm in\n"
            "frigid climates. Because it is so\n"
            "soft and warm, they are often kept\n"
            "as pets or used as makeshift hats."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hamsnug,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Hamsnug,
	.frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Hamsnug,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Hamsnug,
	.shinyPalette = gMonShinyPalette_Hamsnug,
        .iconSprite = gMonIcon_Hamsnug,
        .iconPalIndex = 3,
	FOOTPRINT(Hamsnug)
        OVERWORLD(
            sPicTable_Hamsnug,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Hamsnug,
            gShinyOverworldPalette_Hamsnug
        )
        .levelUpLearnset = sHamsnugLevelUpLearnset,
        .teachableLearnset = sHamsnugTeachableLearnset,
	.eggMoveLearnset = sHamsnugEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_SNUGGYBARA}),
},

    [SPECIES_SNUGGYBARA] =
    {
        .baseHP        = 100,
        .baseAttack    = 65,
        .baseDefense   = 80,
        .baseSpeed     = 73,
        .baseSpAttack  = 82,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_ICE),
        .catchRate = 127,
        .expYield = 144,
        .evYield_HP    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_COZY, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Snuggybara"),
        .cryId = CRY_SNUGGGYBARA,
        .natDexNum = NATIONAL_DEX_SNUGGYBARA,
        .categoryName = _("Capybara"),
        .height = 11,
        .weight = 375,
        .description = COMPOUND_STRING(
            "It sheds its fur according to its\n"
            "climate. It can stay warm in temps\n"
            "as cold as -12ºF. Its teeth can chew\n"
            "through solid rock."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snuggybara,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Snuggybara,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        .backPic = gMonBackPic_Snuggybara,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Snuggybara,
	.shinyPalette = gMonShinyPalette_Snuggybara,
        .shinyPalette = gMonShinyPalette_Snuggybara,
        .iconSprite = gMonIcon_Snuggybara,
        .iconPalIndex = 3,
        FOOTPRINT(Snuggybara)
        OVERWORLD(
            sPicTable_Snuggybara,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Snuggybara,
            gShinyOverworldPalette_Snuggybara
        )
        .levelUpLearnset = sSnuggybaraLevelUpLearnset,
        .teachableLearnset = sSnuggybaraTeachableLearnset,
},
#endif //P_FAMILY_HAMSNUG

#if P_FAMILY_PINGLOO
    [SPECIES_PINGLOO] =
    {
        .baseHP        = 60,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 56,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 255,
        .expYield = 54,
        .evYield_HP    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_1),
        .abilities = {ABILITY_SLUSH_RUSH, ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pingloo"),
        .cryId = CRY_PINGLOO,
        .natDexNum = NATIONAL_DEX_PINGLOO,
        .categoryName = _("Glacier"),
        .height = 4,
        .weight = 52,
        .description = COMPOUND_STRING(
            "The snow on its face is not\n"
            "inherently part of its body.\n"
            "Pingloo goes on a life\n"
            "journey acquiring face snow."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pingloo,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pingloo,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Pingloo,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Pingloo,
        .shinyPalette = gMonShinyPalette_Pingloo,
        .iconSprite = gMonIcon_Pingloo,
        .iconPalIndex = 3,
        FOOTPRINT(Pingloo)
        OVERWORLD(
            sPicTable_Pingloo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pingloo,
            gShinyOverworldPalette_Pingloo
        )
        .levelUpLearnset = sPinglooLevelUpLearnset,
        .teachableLearnset = sPinglooTeachableLearnset,
	.eggMoveLearnset = sPinglooEggMoveLeanset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_PENGLACIER}),
},

    [SPECIES_PENGLACIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 65,
        .baseDefense   = 75,
        .baseSpeed     = 96,
        .baseSpAttack  = 100,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ICE, TYPE_FIGHTING),
        .catchRate = 185,
        .expYield = 204,
        .evYield_HP    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_1),
        .abilities = {ABILITY_SLUSH_RUSH, ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Penglacier"),
        .cryId = CRY_PENGLACIER,
        .natDexNum = NATIONAL_DEX_PENGLACIER,
        .categoryName = _("Glacier"),
        .height = 24,
        .weight = 3049,
        .description = COMPOUND_STRING(
            "The snow on its face has\n"
            "hardened to solid ice.\n"
            "Males hold many Pingloo\n"
            "to protect them."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Penglacier,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Penglacier,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .backPic = gMonBackPic_Penglacier,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Penglacier,
        .shinyPalette = gMonShinyPalette_Penglacier,
        .iconSprite = gMonIcon_Penglacier,
        .iconPalIndex = 3,
        FOOTPRINT(Penglacier)
        OVERWORLD(
            sPicTable_Penglacier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Penglacier,
            gShinyOverworldPalette_Penglacier
        )
        .levelUpLearnset = sPenglacierLevelUpLearnset,
        .teachableLearnset = sPenglacierTeachableLearnset,
},
#endif //P_FAMILY_PINGLOO

#if P_FAMILY_CABOB
    [SPECIES_CABOB] =
    {
        .baseHP        = 40,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ICE, TYPE_DARK),
        .catchRate = 255,
        .expYield = 54,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_RUN_AWAY, ABILITY_RIVALRY, ABILITY_SLUSH_RUSH},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Cabob"),
        .cryId = CRY_CABOB,
        .natDexNum = NATIONAL_DEX_CABOB,
        .categoryName = _("Lynx"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "Its developing fangs are created\n"
            "by its frigid breath. It enjoys\n"
            "skewering its food like a kebab\n"
            "before eating."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cabob,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Cabob,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Cabob,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Cabob,
        .shinyPalette = gMonShinyPalette_Cabob,
        .iconSprite = gMonIcon_Cabob,
        .iconPalIndex = 0,
        FOOTPRINT(Cabob)
        OVERWORLD(
            sPicTable_Cabob,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Cabob,
            gShinyOverworldPalette_Cabob
        )
        .levelUpLearnset = sCabobLevelUpLearnset,
        .teachableLearnset = sCabobTeachableLearnset,
	.eggMoveLearnset = sCabobEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_LYNXSKEW}),
},

    [SPECIES_LYNXSKEW] =
    {
        .baseHP        = 80,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_ICE, TYPE_DARK),
        .catchRate = 127,
        .expYield = 150,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_INTIMIDATE, ABILITY_RIVALRY, ABILITY_SLUSH_RUSH},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Lynxskew"),
        .cryId = CRY_LYNXSKEW,
        .natDexNum = NATIONAL_DEX_LYNXSKEW,
        .categoryName = _("Lynx"),
        .height = 15,
        .weight = 790,
        .description = COMPOUND_STRING(
            "Its ferocious fangs are cold enough\n"
            "to give humans frostbite on contact.\n"
            "It has excellent night-vision, and\n"
            "prefers this time for hunting."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Lynxskew,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Lynxskew,
        .frontAnimId = ANIM_V_STRETCH_BOTH_ENDS_SLOW,
        .backPic = gMonBackPic_Lynxskew,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Lynxskew,
        .shinyPalette = gMonShinyPalette_Lynxskew,
        .iconSprite = gMonIcon_Lynxskew,
        .iconPalIndex = 0,
        FOOTPRINT(Lynxskew)
        OVERWORLD(
            sPicTable_Lynxskew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Lynxskew,
            gShinyOverworldPalette_Lynxskew
        )
        .levelUpLearnset = sLynxskewLevelUpLearnset,
        .teachableLearnset = sLynxskewTeachableLearnset,
},
#endif //P_FAMILY_CABOB

#if P_FAMILY_PUMACH
    [SPECIES_PUMACH] =
    {
        .baseHP        = 46,
        .baseAttack    = 45,
        .baseDefense   = 30,
        .baseSpeed     = 61,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 255,
        .expYield = 46,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_STATIC, ABILITY_KEEN_EYE, ABILITY_SLANDER},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pumach"),
        .cryId = CRY_PUMACH,
        .natDexNum = NATIONAL_DEX_PUMACH,
        .categoryName = _("Puma"),
        .height = 6,
        .weight = 53,
        .description = COMPOUND_STRING(
            "Its fur attracts static\n"
            "electricity, so watch out\n"
            "if you want to hug it! They are\n"
            "friendly and are popular pets."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pumach,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pumach,
        .frontAnimId = ANIM_GLOW_YELLOW,
        .backPic = gMonBackPic_Pumach,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Pumach,
        .shinyPalette = gMonShinyPalette_Pumach,
        .iconSprite = gMonIcon_Pumach,
        .iconPalIndex = 1,
        FOOTPRINT(Pumach)
        OVERWORLD(
            sPicTable_Pumach,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pumach,
            gShinyOverworldPalette_Pumach
        )
        .levelUpLearnset = sPumachLevelUpLearnset,
        .teachableLearnset = sPumachTeachableLearnset,
	.eggMoveLearnset = sPumachEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_JAGWIRE),
},

    [SPECIES_JAGWIRE] =
    {
        .baseHP        = 91,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 80,
        .baseSpDefense = 101,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DARK),
        .catchRate = 127,
        .expYield = 162,
        .evYield_Speed    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_STATIC, ABILITY_KEEN_EYE, ABILITY_SLANDER},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Jagwire"),
        .cryId = CRY_JAGWIRE,
        .natDexNum = NATIONAL_DEX_JAGWIRE,
        .categoryName = _("Jaguar"),
        .height = 9,
        .weight = 952,
        .description = COMPOUND_STRING(
            "Jagwire's legs are incredibly strong.\n"
            "It can run at 60mph, and jump\n"
            "12ft off the ground. When they jump,\n"
            "it makes a sound like thunder."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Jagwire,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Jagwire,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW,
        .backPic = gMonBackPic_Jagwire,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Jagwire,
        .shinyPalette = gMonShinyPalette_Jagwire,
        .iconSprite = gMonIcon_Jagwire,
        .iconPalIndex = 1,
        FOOTPRINT(Jagwire)
        OVERWORLD(
            sPicTable_Jagwire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Jagwire,
            gShinyOverworldPalette_Jagwire
        )
        .levelUpLearnset = sJagwireLevelUpLearnset,
        .teachableLearnset = sJagwireTeachableLearnset,
},
#endif //P_FAMILY_PUMACH

#if P_FAMILY_SKULLARVA
    [SPECIES_SKULLARVA] =
    {
        .baseHP        = 44,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 46,
        .baseSpAttack  = 30,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_BUG, TYPE_DARK),
        .catchRate = 255,
        .expYield = 50,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = {ABILITY_SWARM, ABILITY_SHIELD_DUST, ABILITY_RUN_AWAY},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Skullarva"),
        .cryId = CRY_SKULLARVA,
        .natDexNum = NATIONAL_DEX_SKULLARVA,
        .categoryName = _("Bone Bug"),
        .height = 2,
        .weight = 52,
        .description = COMPOUND_STRING(
            "This odd bug Pokémon has a\n"
            "bone covering on its head that\n"
            "resembles a skull mask. They\n"
            "have become a mascot of Halloween."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skullarva,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Skullarva,
	.frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Skullarva,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Skullarva,
	.shinyPalette = gMonShinyPalette_Skullarva,
        .iconSprite = gMonIcon_Skullarva,
        .iconPalIndex = 3,
	FOOTPRINT(Skullarva)
        OVERWORLD(
            sPicTable_Skullarva,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Skullarva,
            gShinyOverworldPalette_Skullarva
        )
	.tmIlliterate = TRUE,
        .levelUpLearnset = sSkullarvaLevelUpLearnset,
        .teachableLearnset = sSkullarvaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 7, SPECIES_KAKONE}),
},

    [SPECIES_KAKONE] =
    {
        .baseHP        = 44,
        .baseAttack    = 20,
        .baseDefense   = 56,
        .baseSpeed     = 25,
        .baseSpAttack  = 25,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_BUG, TYPE_DARK),
        .catchRate = 120,
        .expYield = 80,
        .evYield_Defense    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = {ABILITY_SHED_SKIN, ABILITY_SHIELD_DUST, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kakone"),
        .cryId = CRY_KAKONE,
        .natDexNum = NATIONAL_DEX_KAKONE,
        .categoryName = _("Bone Bug"),
        .height = 6,
        .weight = 91,
        .description = COMPOUND_STRING(
            "Its cacoon also bears a\n"
            "mask made of bone up front.\n"
            "They used to be hunted for\n"
            "Halloween masks."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kakone,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Kakone,
	.frontAnimFrames = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Kakone,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Kakone,
	.shinyPalette = gMonShinyPalette_Kakone,
        .iconSprite = gMonIcon_Kakone,
        .iconPalIndex = 5,
	FOOTPRINT(Kakone)
        OVERWORLD(
            sPicTable_Kakone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Kakone,
            gShinyOverworldPalette_Kakone
        )
        .levelUpLearnset = sKakoneLevelUpLearnset,
        .teachableLearnset = sKakoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 23, SPECIES_MORTASQUE}),
},

    [SPECIES_MORTASQUE] =
    {
        .baseHP        = 114,
        .baseAttack    = 60,
        .baseDefense   = 66,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_DARK),
        .catchRate = 60,
        .expYield = 120,
        .evYield_HP    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = {ABILITY_INTIMIDATE, ABILITY_SHIELD_DUST, ABILITY_PRESSURE},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mortasque"),
        .cryId = CRY_MORTASQUE,
        .natDexNum = NATIONAL_DEX_MORTASQUE,
        .categoryName = _("Mortis"),
        .height = 9,
        .weight = 191,
        .description = COMPOUND_STRING(
            "Mortasque is drawn to dead\n"
            "bodies like a moth to light.\n"
            "They have been labelled as a\n"
            "bad omen."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mortasque,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Mortasque,
	.frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Mortasque,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Mortasque,
	.shinyPalette = gMonShinyPalette_Mortasque,
        .iconSprite = gMonIcon_Mortasque,
        .iconPalIndex = 3,
	FOOTPRINT(Mortasque)
        OVERWORLD(
            sPicTable_Mortasque,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Mortasque,
            gShinyOverworldPalette_Mortasque
        )
        .levelUpLearnset = sMortasqueLevelUpLearnset,
        .teachableLearnset = sMortasqueTeachableLearnset,
},
#endif //P_FAMILY_SKULLARVA

#if P_FAMILY_TOTTER
    [SPECIES_TOTTER] =
    {
        .baseHP        = 46,
        .baseAttack    = 38,
        .baseDefense   = 55,
        .baseSpeed     = 84,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 50,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_WATER_VEIL, ABILITY_TECHNICIAN},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Totter"),
        .cryId = CRY_TOTTER,
        .natDexNum = NATIONAL_DEX_TOTTER,
        .categoryName = _("Otter"),
        .height = 4,
        .weight = 101,
        .description = COMPOUND_STRING(
            "Totter cannot walk very well.\n"
            "Domesticated ones are taught\n"
            "to walk, eat, and are even\n"
            "potty trained by humans."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Totter,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Totter,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Totter,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Totter,
        .shinyPalette = gMonShinyPalette_Totter,
        .iconSprite = gMonIcon_Totter,
        .iconPalIndex = 0,
        FOOTPRINT(Totter)
        OVERWORLD(
            sPicTable_Totter,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Totter,
            gShinyOverworldPalette_Totter
        )
        .levelUpLearnset = sTotterLevelUpLearnset,
        .teachableLearnset = sTotterTeachableLearnset,
	.eggMoveLearnset = sTotterEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_CASCOTTA}),
},

    [SPECIES_CASCOTTA] =
    {
        .baseHP        = 58,
        .baseAttack    = 41,
        .baseDefense   = 65,
        .baseSpeed     = 94,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 180,
        .expYield = 100,
        .evYield_Speed    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_WATER_VEIL, ABILITY_TECHNICIAN},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cascotta"),
        .cryId = CRY_CASCOTTA,
        .natDexNum = NATIONAL_DEX_CASCOTTA,
        .categoryName = _("Otter"),
        .height = 14,
        .weight = 437,
        .description = COMPOUND_STRING(
            "Cascotta are very quick\n"
            "swimmers. They can out-swim\n"
            "a speedboat when going at\n"
            "full speed."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cascotta,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Cascotta,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE,
        .backPic = gMonBackPic_Cascotta,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        .palette = gMonPalette_Cascotta,
        .shinyPalette = gMonShinyPalette_Cascotta,
        .iconSprite = gMonIcon_Cascotta,
        .iconPalIndex = 0,
        FOOTPRINT(Cascotta)
        OVERWORLD(
            sPicTable_Cascotta,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Cascotta,
            gShinyOverworldPalette_Cascotta
        )
        .levelUpLearnset = sCascottaLevelUpLearnset,
        .teachableLearnset = sCascottaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL_RAIN, 34, SPECIES_LUTRAJET}),
},

    [SPECIES_LUTRAJET] =
    {
        .baseHP        = 72,
        .baseAttack    = 68,
        .baseDefense   = 72,
        .baseSpeed     = 113,
        .baseSpAttack  = 96,
        .baseSpDefense = 108,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 90,
        .expYield = 150,
        .evYield_Speed    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_WATER_VEIL, ABILITY_TECHNICIAN},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lutrajet"),
        .cryId = CRY_LUTRAJET,
        .natDexNum = NATIONAL_DEX_LUTRAJET,
        .categoryName = _("Otter"),
        .height = 18,
        .weight = 454,
        .description = COMPOUND_STRING(
            "Lutrajet are phenomenal\n"
            "swimmers. They can out-swim\n"
            "a speedboat when going at\n"
            "full speed."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lutrajet,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Lutrajet,
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_Lutrajet,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Lutrajet,
        .shinyPalette = gMonShinyPalette_Lutrajet,
        .iconSprite = gMonIcon_Lutrajet,
        .iconPalIndex = 0,
        FOOTPRINT(Lutrajet)
        OVERWORLD(
            sPicTable_Lutrajet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Lutrajet,
            gShinyOverworldPalette_Lutrajet
        )
        .levelUpLearnset = sLutrajetLevelUpLearnset,
        .teachableLearnset = sLutrajetTeachableLearnset,
},
#endif //P_FAMILY_TOTTER

#if P_FAMILY_TENROCK
    [SPECIES_TENROCK] =
    {
        .baseHP        = 51,
        .baseAttack    = 60,
        .baseDefense   = 65,
        .baseSpeed     = 54,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 54,
        .evYield_Defense    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_FIELD),
        .abilities = {ABILITY_PICKUP, ABILITY_SAND_RUSH, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Tenrock"),
        .cryId = CRY_TENROCK,
        .natDexNum = NATIONAL_DEX_TENROCK,
        .categoryName = _("Pangolin"),
        .height = 4,
        .weight = 296,
        .description = COMPOUND_STRING(
            "Generations of moving slowly in\n"
            "caves looking for ants to eat has\n"
            "caused Tenrock to merge with its rocky\n"
            "surroundings."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tenrock,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Tenrock,
        .frontAnimId = ANIM_TIP_HOP_FORWARD,
        .backPic = gMonBackPic_Tenrock,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Tenrock,
        .shinyPalette = gMonShinyPalette_Tenrock,
        .iconSprite = gMonIcon_Tenrock,
        .iconPalIndex = 2,
        FOOTPRINT(Tenrock)
        OVERWORLD(
            sPicTable_Tenrock,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Tenrock,
            gShinyOverworldPalette_Tenrock
        )
        .levelUpLearnset = sTenrockLevelUpLearnset,
        .teachableLearnset = sTenrockTeachableLearnset,
	.eggMoveLearnset = sTenrockEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_SHREWEL}),
},

    [SPECIES_SHREWEL] =
    {
        .baseHP        = 71,
        .baseAttack    = 80,
        .baseDefense   = 85,
        .baseSpeed     = 74,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ROCK, TYPE_NORMAL),
        .catchRate = 185,
        .expYield = 116,
        .evYield_Defense    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_FIELD),
        .abilities = {ABILITY_PICKUP, ABILITY_SAND_RUSH, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Shrewel"),
        .cryId = CRY_SHREWEL,
        .natDexNum = NATIONAL_DEX_SHREWEL,
        .categoryName = _("Pangolin"),
        .height = 10,
        .weight = 510,
        .description = COMPOUND_STRING(
            "The jewels on its back reflect its\n"
            "health. When they change to black,\n"
            "it should be taken to a Pokémon\n"
            "doctor immediately."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shrewel,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Shrewel,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Shrewel,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Shrewel,
        .shinyPalette = gMonShinyPalette_Shrewel,
        .iconSprite = gMonIcon_Shrewel,
        .iconPalIndex = 5,
        FOOTPRINT(Shrewel)
        OVERWORLD(
            sPicTable_Shrewel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Shrewel,
            gShinyOverworldPalette_Shrewel
        )
        .levelUpLearnset = sShrewelLevelUpLearnset,
        .teachableLearnset = sShrewelTeachableLearnset,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_PANGOLEM},
				{EVO_ITEM, ITEM_LINKING_CORD, SPECIES_PANGOLEM}),
},

    [SPECIES_PANGOLEM] =
    {
        .baseHP        = 89,
        .baseAttack    = 106,
        .baseDefense   = 114,
        .baseSpeed     = 94,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_NORMAL),
        .catchRate = 105,
        .expYield = 186,
        .evYield_Defense    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_FIELD),
        .abilities = {ABILITY_SIMPLE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pangolem"),
        .cryId = CRY_PANGOLEM,
        .natDexNum = NATIONAL_DEX_PANGOLEM,
        .categoryName = _("Pangolin"),
        .height = 13,
        .weight = 1055,
        .description = COMPOUND_STRING(
            "They were the primary predator\n"
            "of Durant before it developed\n"
            "its metal coating. Some theorize\n"
            "they evolved into Heatmor after."),
        .pokemonScale = 267,
        .pokemonOffset = 0,
        .trainerScale = 286,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pangolem,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pangolem,
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Pangolem,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Pangolem,
        .shinyPalette = gMonShinyPalette_Pangolem,
        .iconSprite = gMonIcon_Pangolem,
        .iconPalIndex = 5,
        FOOTPRINT(Pangolem)
        OVERWORLD(
            sPicTable_Pangolem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pangolem,
            gShinyOverworldPalette_Pangolem
        )
        .levelUpLearnset = sPangolemLevelUpLearnset,
        .teachableLearnset = sPangolemTeachableLearnset,
},
#endif //P_FAMILY_TENROCK

#if P_FAMILY_SHELFUR
    [SPECIES_SHELFUR] =
    {
        .baseHP        = 63,
        .baseAttack    = 64,
        .baseDefense   = 75,
        .baseSpeed     = 25,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 220,
        .expYield = 70,
        .evYield_Defense    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_STURDY, ABILITY_FLAME_BODY, ABILITY_SOLID_ROCK},
        .bodyColor = BODY_COLOR_ORANGE,
        .speciesName = _("Shelfur"),
        .cryId = CRY_SHELFUR,
        .natDexNum = NATIONAL_DEX_SHELFUR,
        .categoryName = _("Igneous"),
        .height = 8,
        .weight = 428,
        .description = COMPOUND_STRING(
            "Shelfur's shell is made of\n"
            "solid lava rock. It hides\n"
            "in its shell to defend\n"
            "against predators."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shelfur,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Shelfur,
        .frontAnimId = ANIM_FLICKER,
        .backPic = gMonBackPic_Shelfur,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Shelfur,
        .shinyPalette = gMonShinyPalette_Shelfur,
        .iconSprite = gMonIcon_Shelfur,
        .iconPalIndex = 3,
        FOOTPRINT(Shelfur)
        OVERWORLD(
            sPicTable_Shelfur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Shelfur,
            gShinyOverworldPalette_Shelfur
        )
        .levelUpLearnset = sShelfurLevelUpLearnset,
        .teachableLearnset = sShelfurTeachableLearnset,
	.eggMoveLearnset = sShelfurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_IGNOISE}),
},

    [SPECIES_IGNOISE] =
    {
        .baseHP        = 76,
        .baseAttack    = 81,
        .baseDefense   = 97,
        .baseSpeed     = 20,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 155,
        .expYield = 135,
        .evYield_Defense    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_STURDY, ABILITY_FLAME_BODY, ABILITY_SOLID_ROCK},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ignoise"),
        .cryId = CRY_IGNOISE,
        .natDexNum = NATIONAL_DEX_IGNOISE,
        .categoryName = _("Igneous"),
        .height = 11,
        .weight = 828,
        .description = COMPOUND_STRING(
            "The flames in Ignoise's\n"
            "body causes its shell to\n"
            "be hot enough to give a\n"
            "first degree burn."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ignoise,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Ignoise,
        .frontAnimId = ANIM_SHAKE_GLOW_RED,
        .backPic = gMonBackPic_Ignoise,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Ignoise,
        .shinyPalette = gMonShinyPalette_Ignoise,
        .iconSprite = gMonIcon_Ignoise,
        .iconPalIndex = 0,
        FOOTPRINT(Ignoise)
        OVERWORLD(
            sPicTable_Ignoise,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Ignoise,
            gShinyOverworldPalette_Ignoise
        )
        .levelUpLearnset = sIgnoiseLevelUpLearnset,
        .teachableLearnset = sIgnoiseTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_MOLTORTOISE}),
},

    [SPECIES_MOLTORTOISE] =
    {
        .baseHP        = 92,
        .baseAttack    = 90,
        .baseDefense   = 132,
        .baseSpeed     = 15,
        .baseSpAttack  = 86,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 90,
        .expYield = 160,
        .evYield_Defense    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_STURDY, ABILITY_FLAME_BODY, ABILITY_SOLID_ROCK},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Moltortoise"),
        .cryId = CRY_MOLTORTOISE,
        .natDexNum = NATIONAL_DEX_MOLTORTOISE,
        .categoryName = _("Igneous"),
        .height = 18,
        .weight = 1828,
        .description = COMPOUND_STRING(
            "Moltortoise's shell can\n"
            "withstand 110 bars of water\n"
            "pressure. However, it does not\n"
            "take to water well."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Moltortoise,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Moltortoise,
        .frontAnimId = ANIM_SHAKE_GLOW_RED_SLOW,
        .backPic = gMonBackPic_Moltortoise,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Moltortoise,
        .shinyPalette = gMonShinyPalette_Moltortoise,
        .iconSprite = gMonIcon_Moltortoise,
        .iconPalIndex = 0,
        FOOTPRINT(Moltortoise)
        OVERWORLD(
            sPicTable_Moltortoise,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Moltortoise,
            gShinyOverworldPalette_Moltortoise
        )
        .levelUpLearnset = sMoltortoiseLevelUpLearnset,
        .teachableLearnset = sMoltortoiseTeachableLearnset,
},
#endif //P_FAMILY_SHELFUR

#if P_FAMILY_CHIHAHA
    [SPECIES_CHIHAHA] =
    {
        .baseHP        = 63,
        .baseAttack    = 55,
        .baseDefense   = 43,
        .baseSpeed     = 68,
        .baseSpAttack  = 55,
        .baseSpDefense = 43,
        .types = MON_TYPES(TYPE_SOUND, TYPE_DARK),
        .catchRate = 255,
        .expYield = 52,
        .evYield_Speed     = 1,
        .itemRare = ITEM_BRIGHT_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_JESTER, ABILITY_NONE, ABILITY_PRANKSTER},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Chihaha"),
        .cryId = CRY_CHIHAHA,
        .natDexNum = NATIONAL_DEX_CHIHAHA,
        .categoryName = _("Jester"),
        .height = 5,
        .weight = 115,
        .description = COMPOUND_STRING(
            "Chihaha loves to make laugh.\n"
            "It will spend its entire day\n"
            "doing its best to earn even\n"
            "a single chuckle."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chihaha,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chihaha,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Chihaha,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Chihaha,
        .shinyPalette = gMonShinyPalette_Chihaha,
        .iconSprite = gMonIcon_Chihaha,
        .iconPalIndex = 0,
        FOOTPRINT(Chihaha)
        OVERWORLD(
            sPicTable_Chihaha,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chihaha,
            gShinyOverworldPalette_Chihaha
        )
        .levelUpLearnset = sChihahaLevelUpLearnset,
        .teachableLearnset = sChihahaTeachableLearnset,
	.eggMoveLearnset = sChihahaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_HOWLEQUIN}),
    },

    [SPECIES_HOWLEQUIN] =
    {
        .baseHP        = 83,
        .baseAttack    = 85,
        .baseDefense   = 73,
        .baseSpeed     = 108,
        .baseSpAttack  = 95,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_SOUND, TYPE_DARK),
        .catchRate = 105,
        .expYield = 192,
        .evYield_Speed     = 2,
        .itemRare = ITEM_BRIGHT_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_JESTER, ABILITY_NONE, ABILITY_PRANKSTER},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Howlequin"),
        .cryId = CRY_HOWLEQUIN,
        .natDexNum = NATIONAL_DEX_HOWLEQUIN,
        .categoryName = _("Jester"),
        .height = 10,
        .weight = 275,
        .description = COMPOUND_STRING(
            "Howlequin's desperation for\n"
            "laughter has become pitiful.\n"
            "It has resorted to self-\n"
            "deprication and harm."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Howlequin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Howlequin,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Howlequin,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Howlequin,
        .shinyPalette = gMonShinyPalette_Howlequin,
        .iconSprite = gMonIcon_Howlequin,
        .iconPalIndex = 0,
        FOOTPRINT(Howlequin)
        OVERWORLD(
            sPicTable_Howlequin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Howlequin,
            gShinyOverworldPalette_Howlequin
        )
        .levelUpLearnset = sHowlequinLevelUpLearnset,
        .teachableLearnset = sHowlequinTeachableLearnset,
    },
#endif //P_FAMILY_CHIHAHA

#if P_FAMILY_PALLECTRON
    [SPECIES_PALLECTRON] =
    {
        .baseHP        = 46,
        .baseAttack    = 48,
        .baseDefense   = 45,
        .baseSpeed     = 62,
        .baseSpAttack  = 68,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 200,
        .expYield = 45,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Pallectron"),
        .cryId = CRY_PALLECTRON,
        .natDexNum = NATIONAL_DEX_PALLECTRON,
        .categoryName = _("Chameleon"),
        .height = 2,
        .weight = 53,
        .description = COMPOUND_STRING(
            "Pallectron are hard to spot\n"
            "thanks to their tremendous\n"
            "camoflauge. They are known\n"
            "to love Oran Berries."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pallectron,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pallectron,
        .frontAnimId = ANIM_H_PIVOT,
        .backPic = gMonBackPic_Pallectron,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Pallectron,
        .shinyPalette = gMonShinyPalette_Pallectron,
        .iconSprite = gMonIcon_Pallectron,
        .iconPalIndex = 0,
        FOOTPRINT(Pallectron)
        OVERWORLD(
            sPicTable_Pallectron,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pallectron,
            gShinyOverworldPalette_Pallectron
        )
        .levelUpLearnset = sPallectronLevelUpLearnset,
        .teachableLearnset = sPallectronTeachableLearnset,
	.eggMoveLearnset = sPallectronEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_CALLUMMOTOR}),
},

    [SPECIES_CALLUMMOTOR] =
    {
        .baseHP        = 66,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 88,
        .baseSpAttack  = 94,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 140,
        .expYield = 90,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Callummotor"),
        .cryId = CRY_CALLUMMOTOR,
        .natDexNum = NATIONAL_DEX_CALLUMMOTOR,
        .categoryName = _("Chameleon"),
        .height = 9,
        .weight = 295,
        .description = COMPOUND_STRING(
            "They charge their tongues\n"
            "with electricity to make\n"
            "kisses more arousing. It\n"
            "is also used defensively."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Callummotor,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Callummotor,
        .frontAnimId = ANIM_H_DIP,
        .backPic = gMonBackPic_Callummotor,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Calummotor,
        .shinyPalette = gMonShinyPalette_Callummotor,
        .iconSprite = gMonIcon_Calummotor,
        .iconPalIndex = 0,
        FOOTPRINT(Callummotor)
        OVERWORLD(
            sPicTable_Callummotor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Callummotor,
            gShinyOverworldPalette_Callummotor
        )
        .levelUpLearnset = sCallummotorLevelUpLearnset,
        .teachableLearnset = sCallummotorTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_ELECTRIOCEROS}),
},

    [SPECIES_ELECTRIOCEROS] =
    {
        .baseHP        = 86,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 98,
        .baseSpAttack  = 121,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 60,
        .expYield = 211,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Electrioceros"),
        .cryId = CRY_ELECTRIOCEROS,
        .natDexNum = NATIONAL_DEX_ELECTRIOCEROS,
        .categoryName = _("Chameleon"),
        .height = 16,
        .weight = 604,
        .description = COMPOUND_STRING(
            "The horns on its head store\n"
            "around 8,000W of electricity.\n"
            "A man survived the desert heat\n"
            "in a fridge with its help."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Electrioceros,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Electrioceros,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_FAST,
        .backPic = gMonBackPic_Electrioceros,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Electrioceros,
        .shinyPalette = gMonShinyPalette_Electrioceros,
        .iconSprite = gMonIcon_Electrioceros,
        .iconPalIndex = 4,
        FOOTPRINT(Electrioceros)
        OVERWORLD(
            sPicTable_Electrioceros,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Electrioceros,
            gShinyOverworldPalette_Electrioceros
        )
        .levelUpLearnset = sElectriocerosLevelUpLearnset,
        .teachableLearnset = sElectriocerosTeachableLearnset,
},
#endif //P_FAMILY_PALLECTRON

#if P_FAMILY_CHIMPOCA
    [SPECIES_CHIMPOCA] =
    {
        .baseHP        = 53,
        .baseAttack    = 71,
        .baseDefense   = 60,
        .baseSpeed     = 76,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 205,
        .expYield = 64,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_DEFIANT, ABILITY_MAGICIAN, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Chimpoca"),
        .cryId = CRY_CHIMPOCA,
        .natDexNum = NATIONAL_DEX_CHIMPOCA,
        .categoryName = _("Mayan"),
        .height = 10,
        .weight = 318,
        .description = COMPOUND_STRING(
            "Chimpoca are energetic\n"
            "and mischievous. They\n"
            "tend to steal items from\n"
            "trainers and travelers."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chimpoca,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chimpoca,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Chimpoca,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Chimpoca,
        .shinyPalette = gMonShinyPalette_Chimpoca,
        .iconSprite = gMonIcon_Chimpoca,
        .iconPalIndex = 0,
        FOOTPRINT(Chimpoca)
        OVERWORLD(
            sPicTable_Chimpoca,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chimpoca,
            gShinyOverworldPalette_Chimpoca
        )
        .levelUpLearnset = sChimpocaLevelUpLearnset,
        .teachableLearnset = sChimpocaTeachableLearnset,
	.eggMoveLearnset = sChimpocaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_SIMAYAN}),
},

    [SPECIES_SIMAYAN] =
    {
        .baseHP        = 83,
        .baseAttack    = 102,
        .baseDefense   = 95,
        .baseSpeed     = 106,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 135,
        .expYield = 188,
        .evYield_Speed    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_DEFIANT, ABILITY_MAGICIAN, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Simayan"),
        .cryId = CRY_SIMAYAN,
        .natDexNum = NATIONAL_DEX_SIMAYAN,
        .categoryName = _("Mayan"),
        .height = 15,
        .weight = 460,
        .description = COMPOUND_STRING(
            "Chimpoca are energetic\n"
            "and mischievous. They\n"
            "tend to steal items from\n"
            "trainers and travelers."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Simayan,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Simayan,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Simayan,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Simayan,
        .shinyPalette = gMonShinyPalette_Simayan,
        .iconSprite = gMonIcon_Simayan,
        .iconPalIndex = 0,
        FOOTPRINT(Simayan)
        OVERWORLD(
            sPicTable_Simayan,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Simayan,
            gShinyOverworldPalette_Simayan
        )
        .levelUpLearnset = sSimayanLevelUpLearnset,
        .teachableLearnset = sSimayanTeachableLearnset,
},
#endif //P_FAMILY_CHIMPOCA

#if P_FAMILY_ICETOPE
    [SPECIES_ICETOPE] =
    {
        .baseHP        = 80,
        .baseAttack    = 45,
        .baseDefense   = 60,
        .baseSpeed     = 44,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_POISON, TYPE_ICE),
        .catchRate = 190,
        .expYield = 56,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_ICE_BODY, ABILITY_CORROSION},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Icetope"),
        .cryId = CRY_ICETOPE,
        .natDexNum = NATIONAL_DEX_ICETOPE,
        .categoryName = _("Frozen Waste"),
        .height = 7,
        .weight = 111,
        .description = COMPOUND_STRING(
            "Icetope seems to be the\n"
            "result of a mutation that\n"
            "occurred in a polluted lake\n"
            "after it froze over."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Icetope,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Icetope,
        .frontAnimId = ANIM_SHAKE_GLOW_WHITE_SLOW,
        .backPic = gMonBackPic_Icetope,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Icetope,
        .shinyPalette = gMonShinyPalette_Icetope,
        .iconSprite = gMonIcon_Icetope,
        .iconPalIndex = 0,
        FOOTPRINT(Icetope)
        OVERWORLD(
            sPicTable_Icetope,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Icetope,
            gShinyOverworldPalette_Icetope
        )
        .levelUpLearnset = sIcetopeLevelUpLearnset,
        .teachableLearnset = sIcetopeTeachableLearnset,
	.eggMoveLearnset = sIcetopeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_CHILLNOBYL}),
    },

    [SPECIES_CHILLNOBYL] =
    {
        .baseHP        = 120,
        .baseAttack    = 57,
        .baseDefense   = 85,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_POISON, TYPE_ICE),
        .catchRate = 60,
        .expYield = 201,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_ICE_BODY, ABILITY_CORROSION},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Chillnobyl"),
        .cryId = CRY_CHILLNOBYL,
        .natDexNum = NATIONAL_DEX_CHILLNOBYL,
        .categoryName = _("Frozen Waste"),
        .height = 15,
        .weight = 777,
        .description = COMPOUND_STRING(
            "A natural disaster\n"
            "destroyed a nuclear power\n"
            "plant in the tundra, and\n"
            "thus, Chillnobyl was born."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chillnobyl,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chillnobyl,
        .frontAnimId = ANIM_GROW_STUTTER_TWICE,
        .backPic = gMonBackPic_Chillnobyl,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Chillnobyl,
        .shinyPalette = gMonShinyPalette_Chillnobyl,
        .iconSprite = gMonIcon_Chillnobyl,
        .iconPalIndex = 0,
        FOOTPRINT(Chillnobyl)
        OVERWORLD(
            sPicTable_Chillnobyl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chillnobyl,
            gShinyOverworldPalette_Chillnobyl
        )
        .levelUpLearnset = sChillnobylLevelUpLearnset,
        .teachableLearnset = sChillnobylTeachableLearnset,
#endif //P_FAMILY_ICETOPE

#if P_FAMILY_MAGROPLEX
    [SPECIES_MAGROPLEX] =
    {
        .baseHP        = 80,
        .baseAttack    = 90,
        .baseDefense   = 120,
        .baseSpeed     = 60,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 80,
        .expYield = 189,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGG_GROUP_DISCOVERED),
        .abilities = {ABILITY_STEAM_ENGINE, ABILITY_NONE, ABILITY_HEATPROOF},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Magroplex"),
        .cryId = CRY_MAGROPLEX,
        .natDexNum = NATIONAL_DEX_MAGROPLEX,
        .categoryName = _("Steam Engine"),
        .height = 16,
        .weight = 1008,
        .description = COMPOUND_STRING(
            "Magroplex is a friendly\n"
            "steam-powered creature.\n"
            "It loves to eat berries\n"
            "after they've gone bad."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magroplex,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Magroplex,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Magroplex,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Magroplex,
        .shinyPalette = gMonShinyPalette_Magroplex,
        .iconSprite = gMonIcon_Magroplex,
        .iconPalIndex = 5,
        FOOTPRINT(Magroplex)
        OVERWORLD(
            sPicTable_Magroplex,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Magroplex,
            gShinyOverworldPalette_Magroplex
        )
        .levelUpLearnset = sMagroplexLevelUpLearnset,
        .teachableLearnset = sMagroplexTeachableLearnset,
#endif //P_FAMILY_MAGROPLEX

#if P_FAMILY_PSYYNEN
    [SPECIES_PSYYNEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 80,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 225,
        .expYield = 57,
        .evYield_SpDefense    = 1,
	.itemRare = ITEN_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_INSOMNIA, ABILITY_RUN_AWAY, ABILITY_BERSERK},
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Psyynen"),
        .cryId = CRY_PSYYNEN,
        .natDexNum = NATIONAL_DEX_PSYYNEN,
        .categoryName = _("Angora"),
        .height = 9,
        .weight = 408,
        .description = COMPOUND_STRING(
            "Its psychic powers exceed its\n"
            "ability to control them. It will\n"
            "unleash them if frightened or\n"
            "threatened."),
        .pokemonScale = 306,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Psyynen,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Psyynen,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Psyynen,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Psyynen,
        .shinyPalette = gMonShinyPalette_Psyynen,
        .iconSprite = gMonIcon_Psyynen,
        .iconPalIndex = 2,
        FOOTPRINT(Psyynen)
        OVERWORLD(
            sPicTable_Psyynen,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Psyynen,
            gShinyOverworldPalette_Psyynen
        )
        .levelUpLearnset = sPsyynenLevelUpLearnset,
        .teachableLearnset = sPsyynenTeachableLearnset,
	.eggMoveLearnset = sPsyynenEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_AANCHGORA}),
    },

    [SPECIES_AANCHGORA] =
    {
        .baseHP        = 80,
        .baseAttack    = 67,
        .baseDefense   = 95,
        .baseSpeed     = 45,
        .baseSpAttack  = 113,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 100,
        .expYield = 184,
        .evYield_SpDefense    = 2,
	.itemRare = ITEN_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_INSOMNIA, ABILITY_FUR_COAT, ABILITY_BERSERK},
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Aanchgora"),
        .cryId = CRY_AANCHGORA,
        .natDexNum = NATIONAL_DEX_AANCHGORA,
        .categoryName = _("Angora"),
        .height = 12,
        .weight = 907,
        .description = COMPOUND_STRING(
            "In an attempt to control its immense\n"
            "power, it rid its mind of thoughts.\n"
            "When left unchecked, its psychic\n"
            "power can level cities."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Aanchgora,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Aanchgora,
        .frontAnimId = ANIM_FLICKER,
        .backPic = gMonBackPic_Aanchgora,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Aanchgora,
        .shinyPalette = gMonShinyPalette_Aanchgora,
        .iconSprite = gMonIcon_Aanchgora,
        .iconPalIndex = 1,
        FOOTPRINT(Aanchgora)
        OVERWORLD(
            sPicTable_Aanchgora,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Aanchgora,
            gShinyOverworldPalette_Aanchgora
        )
        .levelUpLearnset = sAanchgoraLevelUpLearnset,
        .teachableLearnset = sAanchgoraTeachableLearnset,
    },
#endif //P_FAMILY_PSYYNEN

#if P_FAMILY_FOLTERGEIST
    [SPECIES_FOLTERGEIST] =
    {
        .baseHP        = 54,
        .baseAttack    = 47,
        .baseDefense   = 40,
        .baseSpeed     = 82,
        .baseSpAttack  = 80,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 180,
        .expYield = 71,
        .evYield_Speed    = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_MIST_RIDER, ABILITY_NONE, ABILITY_NONE}, //Surge Surfer but for Misty Terrain
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Foltergeist"),
        .cryId = CRY_FOLTERGEIST,
        .natDexNum = NATIONAL_DEX_FOLTERGEIST,
        .categoryName = _("Misty Rider"),
        .height = 10,
        .weight = 413,
        .description = COMPOUND_STRING(
            "Foltergeist look up to\n"
            "their mothers on how to\n"
            "live their afterlives.\n"
            "Stars lurk in their eyes."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Foltergeist,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Foltergeist,
        .frontAnimId = ANIM_JOLT_RIGHT,
        .backPic = gMonBackPic_Foltergeist,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Foltergeist,
        .shinyPalette = gMonShinyPalette_Foltergeist,
        .iconSprite = gMonIcon_Foltergeist,
        .iconPalIndex = 2,
        FOOTPRINT(Foltergeist)
        OVERWORLD(
            sPicTable_Foltergeist,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Foltergeist,
            gShinyOverworldPalette_Foltergeist
        )
        .levelUpLearnset = sFoltergeistLevelUpLearnset,
        .teachableLearnset = sFoltergeistTeachableLearnset,
	.eggMoveLearnset = sFoltergeistEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_FANTASMARE}),
},

    [SPECIES_FANTASMARE] =
    {
        .baseHP        = 74,
        .baseAttack    = 67,
        .baseDefense   = 65,
        .baseSpeed     = 122,
        .baseSpAttack  = 135,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 70,
        .expYield = 282,
        .evYield_Speed    = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_MIST_RIDER, ABILITY_NONE, ABILITY_NONE}, //Surge Surfer but for Misty Terrain
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Fantasmare"),
        .cryId = CRY_FANTASMARE,
        .natDexNum = NATIONAL_DEX_FANTASMARE,
        .categoryName = _("Misty Rider"),
        .height = 25,
        .weight = 1013,
        .description = COMPOUND_STRING(
            "It is said Fantasmare's\n"
            "riders will follow them\n"
            "into the afterlife within\n"
            "four years."),
        .pokemonScale = 491,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fanstasmare,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fantasmare,
        .frontAnimId = ANIM_H_REPEATED_SPRING_FAST,
        .backPic = gMonBackPic_Fantasmare,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        .palette = gMonPalette_Fantasmare,
        .shinyPalette = gMonShinyPalette_Fantasmare,
        .iconSprite = gMonIcon_Fantasmare,
        .iconPalIndex = 0,
        FOOTPRINT(Fantasmare)
        OVERWORLD(
            sPicTable_Fantasmare,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Fantasmare,
            gShinyOverworldPalette_Fantasmare
        )
        .levelUpLearnset = sFantasmareLevelUpLearnset,
        .teachableLearnset = sFantasmareTeachableLearnset,
},
#endif //P_FAMILY_FOLTERGEIST

#if P_FAMILY_CUPPY
    [SPECIES_CUPPY] =
    {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 20,
        .baseSpeed     = 80,
        .baseSpAttack  = 15,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 43,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_MOODY},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cuppy"),
        .cryId = CRY_CUPPY,
        .natDexNum = NATIONAL_DEX_CUPPY,
        .categoryName = _("Guppy"),
        .height = 2,
        .weight = 1,
        .description = COMPOUND_STRING(
            "This Pokémon is not very strong.\n"
            "As such, it made itself useful\n"
            "to humans as a teacup for\n"
            "protection from predators."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cuppy,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Cuppy,
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Cuppy,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Cuppy,
        .shinyPalette = gMonShinyPalette_Cuppy,
        .iconSprite = gMonIcon_Cuppy,
        .iconPalIndex = 2,
        FOOTPRINT(Cuppy)
        OVERWORLD(
            sPicTable_Cuppy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Cuppy,
            gShinyOverworldPalette_Cuppy
        )
	.tmIlliterate = TRUE,
        .levelUpLearnset = sCuppyLevelUpLearnset,
        .teachableLearnset = sCuppyTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_FETTLEKISH}),
    },

    [SPECIES_FETTLEKISH] =
    {
        .baseHP        = 95,
        .baseAttack    = 60,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = 125,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_WATER, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 189,
        .evYield_SpAttack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = {ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_MOODY},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Fettlekish"),
        .cryId = CRY_FETTLEKISH,
        .natDexNum = NATIONAL_DEX_FETTLEKISH,
        .categoryName = _("Kettle Fish"),
        .height = 6,
        .weight = 104,
        .description = COMPOUND_STRING(
            "The water it stores in its body can\n"
            "reach temperatures of 220ºF.\n"
            "As such, people will often use\n"
            "it to boil their tea."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fettlekish,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fettlekish,
        .frontAnimId = ANIM_SHAKE_GLOW_RED_SLOW,
        .backPic = gMonBackPic_Fettlekish,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Fettlekish,
        .shinyPalette = gMonShinyPalette_Fettlekish,
        .iconSprite = gMonIcon_Fettlekish,
        .iconPalIndex = 0,
        FOOTPRINT(Fettlekish)
        OVERWORLD(
            sPicTable_Fettlekish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Fettlekish,
            gShinyOverworldPalette_Fettlekish
        )
        .levelUpLearnset = sFettlekishLevelUpLearnset,
        .teachableLearnset = sFettlekishTeachableLearnset,
    },
#endif //P_FAMILY_CUPPY

#if P_FAMILY_NECTRI
    [SPECIES_NECTRI] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 255,
        .expYield = 49,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_GRASS),
        .abilities = {ABILITY_EARLY_BIRD, ABILITY_SAP_SIPPER, ABILITY_HONEY_GATHER},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Nectri"),
        .cryId = CRY_NECTRI,
        .natDexNum = NATIONAL_DEX_NECTRI,
        .categoryName = _("Hummingbird"),
        .height = 1,
        .weight = 1,
        .description = COMPOUND_STRING(
            "This Pokémon is so small, you\n"
            "might miss it! It loves\n"
            "to drink the nectar from Bellossom's\n"
            "flowers."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nectri,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Nectri,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Nectri,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Nectri,
        .shinyPalette = gMonShinyPalette_Nectri,
        .iconSprite = gMonIcon_Nectri,
        .iconPalIndex = 4,
        FOOTPRINT(Nectri)
        OVERWORLD(
            sPicTable_Nectri,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Nectri,
            gShinyOverworldPalette_Nectri
        )
        .levelUpLearnset = sNectriLevelUpLearnset,
        .teachableLearnset = sNectriTeachableLearnset,
	.eggMoveLearnset = sNectriEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_HUMMISCUS}),
    },

    [SPECIES_HUMMISCUS] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 95,
        .baseSpAttack  = 65,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 120,
        .expYield = 120,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_GRASS),
        .abilities = {ABILITY_EARLY_BIRD, ABILITY_SAP_SIPPER, ABILITY_HONEY_GATHER},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Hummiscus"),
        .cryId = CRY_HUMMISCUS,
        .natDexNum = NATIONAL_DEX_HUMMISCUS,
        .categoryName = _("Hummingbird"),
        .height = 2,
        .weight = 1,
        .description = COMPOUND_STRING(
            "Hummiscus fascinates researchers\n"
            "with its ability to fly backward.\n"
            "It uses this ability to evade\n"
            "attacking predators."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hummiscus,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Hummiscus,
        .frontAnimId = ANIM_ZIGZAG_FAST,
        .backPic = gMonBackPic_Hummiscus,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Hummiscus,
        .shinyPalette = gMonShinyPalette_Hummiscus,
        .iconSprite = gMonIcon_Hummiscus,
        .iconPalIndex = 1,
        FOOTPRINT(Hummiscus)
        OVERWORLD(
            sPicTable_Hummiscus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Hummiscus,
            gShinyOverworldPalette_Hummiscus
        )
        .levelUpLearnset = sHummiscusLevelUpLearnset,
        .teachableLearnset = sHummiscusTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_NECTRIARY}),
    },

    [SPECIES_NECTRIARY] =
    {
        .baseHP        = 87,
        .baseAttack    = 55,
        .baseDefense   = 63,
        .baseSpeed     = 121,
        .baseSpAttack  = 104,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 220,
        .evYield_Speed    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_GRASS),
        .abilities = {ABILITY_EARLY_BIRD, ABILITY_SAP_SIPPER, ABILITY_HONEY_GATHER},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Nectriary"),
        .cryId = CRY_NECTRIARY,
        .natDexNum = NATIONAL_DEX_NECTRIARY,
        .categoryName = _("Hummingbird"),
        .height = 3,
        .weight = 2,
        .description = COMPOUND_STRING(
            "Nectriary beats its wings 4,000\n"
            "times per minute.\n"
            "If its wings stop beating, it\n"
            "will die."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nectriary,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Nectriary,
        .frontAnimId = ANIM_ZIGZAG_FAST,
        .backPic = gMonBackPic_Nectriary,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Nectriary,
        .shinyPalette = gMonShinyPalette_Nectriary,
        .iconSprite = gMonIcon_Nectriary,
        .iconPalIndex = 4,
        FOOTPRINT(Nectriary)
        OVERWORLD(
            sPicTable_Nectriary,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Nectriary,
            gShinyOverworldPalette_Nectriary
        )
        .levelUpLearnset = sNectriaryLevelUpLearnset,
        .teachableLearnset = sNectriaryTeachableLearnset,
    },
#endif //P_FAMILY_NECTRI

#if P_FAMILY_CARDINITE
    [SPECIES_CARDINITE] =
    {
        .baseHP        = 49,
        .baseAttack    = 45,
        .baseDefense   = 30,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 255,
        .expYield = 52,
        .evYield_Speed     = 1,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = {ABILITY_EARLY_BIRD, ABILITY_NONE, ABILITY_FLASH_FIRE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Cardinite"),
        .cryId = CRY_CARDINITE,
        .natDexNum = NATIONAL_DEX_CARDINITE,
        .categoryName = _("Cardinal"),
        .height = 3,
        .weight = 1,
        .description = COMPOUND_STRING(
            "They arise early in the morning\n"
            "to absorb sunlight during the day.\n"
            "They can store the heat inside\n"
            "to keep warm in frigid climates."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cardinite,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Cardinite,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .backPic = gMonBackPic_Cardinite,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Cardinite,
        .shinyPalette = gMonShinyPalette_Cardinite,
        .iconSprite = gMonIcon_Cardinite,
        .iconPalIndex = 0,
        FOOTPRINT(Cardinite)
        OVERWORLD(
            sPicTable_Cardinite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Cardinite,
            gShinyOverworldPalette_Cardinite
        )
        .levelUpLearnset = sCardiniteLevelUpLearnset,
        .teachableLearnset = sCardiniteTeachableLearnset,
	.eggMoveLearnset = sCardiniteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_CHARDINAL}),
    },

    [SPECIES_CHARDINAL] =
    {
        .baseHP        = 79,
        .baseAttack    = 100,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 90,
        .expYield = 155,
        .evYield_Speed     = 2,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = {ABILITY_EARLY_BIRD, ABILITY_NONE, ABILITY_FLASH_FIRE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Chardinal"),
        .cryId = CRY_CHARDINAL,
        .natDexNum = NATIONAL_DEX_CHARDINAL,
        .categoryName = _("Cardinal"),
        .height = 10,
        .weight = 120,
        .description = COMPOUND_STRING(
            "The excess solar heat in its body\n"
            "is released as flames during the\n"
            "day. Storing heat for too long will\n"
            "cause internal burns."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chardinal,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chardinal,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Chardinal,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Chardinal,
        .shinyPalette = gMonShinyPalette_Chardinal,
        .iconSprite = gMonIcon_Chardinal,
        .iconPalIndex = 3,
        FOOTPRINT(Chardinal)
        OVERWORLD(
            sPicTable_Chardinal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chardinal,
            gShinyOverworldPalette_Chardinal
        )
        .levelUpLearnset = sChardinalLevelUpLearnset,
        .teachableLearnset = sChardinalTeachableLearnset,
    },
#endif //P_FAMILY_CARDINITE

#if P_FAMILY_SALAGUADE
    [SPECIES_SALAGUADE] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 59,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = {ABILITY_POISON_POINT, ABILITY_HYDRATION, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Salaguade"),
        .cryId = CRY_SALAGUADE,
        .natDexNum = NATIONAL_DEX_SALAGUADE,
        .categoryName = _("Salamander"),
        .height = 2,
        .weight = 8,
        .description = COMPOUND_STRING(
            "Its sweat is toxic to humans.\n"
            "When traveling in humid places,\n"
            "people should check their clothing\n"
            "because it loves to cling to clothes."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Salaguade,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Salaguade,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Salaguade,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Salaguade,
        .shinyPalette = gMonShinyPalette_Salaguade,
        .iconSprite = gMonIcon_Salaguade,
        .iconPalIndex = 0,
        FOOTPRINT(Salaguade)
        OVERWORLD(
            sPicTable_Salaguade,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Salaguade,
            gShinyOverworldPalette_Salaguade
        )
        .levelUpLearnset = sSalaguadeLevelUpLearnset,
        .teachableLearnset = sSalaguadeTeachableLearnset,
	.eggMoveLearnset = sSalaguadeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_IGUASH}),
    },

    [SPECIES_IGUASH] =
    {
        .baseHP        = 75,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 90,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 120,
        .expYield = 135,
        .evYield_Speed        = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = {ABILITY_POISON_POINT, ABILITY_HYDRATION, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Iguash"),
        .cryId = CRY_IGUASH,
        .natDexNum = NATIONAL_DEX_IGUASH,
        .categoryName = _("Iguana"),
        .height = 21,
        .weight = 90,
        .description = COMPOUND_STRING(
            "Iguash can often be found\n"
            "roughhousing in rivers.\n"
            "They practice dragging\n"
            "prey underwater."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Iguash,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Iguash,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Iguash,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Iguash,
        .shinyPalette = gMonShinyPalette_Iguash,
        .iconSprite = gMonIcon_Iguash,
        .iconPalIndex = 0,
        FOOTPRINT(Iguash)
        OVERWORLD(
            sPicTable_Iguash,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Iguash,
            gShinyOverworldPalette_Iguash
        )
        .levelUpLearnset = sIguashLevelUpLearnset,
        .teachableLearnset = sIguashTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_JUGGERCROC}),
    },

    [SPECIES_JUGGERCROC] =
    {
        .baseHP        = 100,
	.baseAttack    = 90,
        .baseDefense   = 75,
        .baseSpeed     = 105,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 229,
        .evYield_Speed        = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = {ABILITY_POISON_POINT, ABILITY_HYDRATION, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Juggercroc"),
        .cryId = CRY_JUGGERCROC,
        .natDexNum = NATIONAL_DEX_JUGGERCROC,
        .categoryName = _("Crocodile"),
        .height = 48,
        .weight = 9500,
        .description = COMPOUND_STRING(
            "They are extremely territorial.\n"
            "Their preferred method of attack\n"
            "is a body check, but they also\n"
            "drown their prey."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Juggercroc,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Juggercroc,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
	.frontAnimId = 30,
        .backPic = gMonBackPic_Juggercroc,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Juggercroc,
        .shinyPalette = gMonShinyPalette_Juggercroc,
        .iconSprite = gMonIcon_Juggercroc,
        .iconPalIndex = 0,
        FOOTPRINT(Juggercroc)
        OVERWORLD(
            sPicTable_Juggercroc,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Juggercroc,
            gShinyOverworldPalette_Juggercroc
        )
        .levelUpLearnset = sJuggercrocLevelUpLearnset,
        .teachableLearnset = sJuggercrocTeachableLearnset,
    },
#endif //P_FAMILY_SALAGUADE

#if P_FAMILY_ARROWBIN
    [SPECIES_ARROWBIN] =
    {
        .baseHP        = 54,
        .baseAttack    = 63,
        .baseDefense   = 40,
        .baseSpeed     = 64,
        .baseSpAttack  = 42,
        .baseSpDefense = 41,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = 61,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_KEEN_EYE, ABILITY_HARVEST},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Arrowbin"),
        .cryId = CRY_ARROWBIN,
        .natDexNum = NATIONAL_DEX_ARROWBIN,
        .categoryName = _("Ottawa"),
        .height = 5,
        .weight = 21,
        .description = COMPOUND_STRING(
            "From a very young age, Arrowbin\n"
            "are taught archery. They use\n"
            "their feathers to make their\n"
            "arrows."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Arrowbin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Arrowbin,
        .frontAnimId = ANIM_V_SPRING,
        .backPic = gMonBackPic_Arrowbin,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Arrowbin,
        .shinyPalette = gMonShinyPalette_Arrowbin,
        .iconSprite = gMonIcon_Arrowbin,
        .iconPalIndex = 0,
        FOOTPRINT(Arrowbin)
        OVERWORLD(
            sPicTable_Arrowbin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Arrowbin,
            gShinyOverworldPalette_Arrowbin
        )
        .levelUpLearnset = sArrowbinLevelUpLearnset,
        .teachableLearnset = sArrowbinTeachableLearnset,
	.eggMoveLearnset = sArrowbinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_HAWTCHET}),
    },

    [SPECIES_HAWTCHET] =
    {
        .baseHP        = 71,
        .baseAttack    = 85,
        .baseDefense   = 53,
        .baseSpeed     = 86,
        .baseSpAttack  = 54,
        .baseSpDefense = 56,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 120,
        .expYield = 120,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_KEEN_EYE, ABILITY_HARVEST},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hawtchet"),
        .cryId = CRY_HAWTCHET,
        .natDexNum = NATIONAL_DEX_HAWTCHET,
        .categoryName = _("Ottawa"),
        .height = 7,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Hawtchet are skilled scavengers.\n"
            "They have also learned to plant\n"
            "seeds to grow their favorite\n"
            "berries."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hawtchet,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Hawtchet,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Hawtchet,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Hawtchet,
        .shinyPalette = gMonShinyPalette_Hawtchet,
        .iconSprite = gMonIcon_Hawtchet,
        .iconPalIndex = 5,
        FOOTPRINT(Hawtchet)
        OVERWORLD(
            sPicTable_Hawtchet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Hawtchet,
            gShinyOverworldPalette_Hawtchet
        )
        .levelUpLearnset = sHawtchetLevelUpLearnset,
        .teachableLearnset = sHawtchetTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CHIEFTURK}),
    },

    [SPECIES_CHIEFTURK] =
    {
        .baseHP        = 96,
        .baseAttack    = 111,
        .baseDefense   = 66,
        .baseSpeed     = 106,
        .baseSpAttack  = 74,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 220,
        .evYield_Speed    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_KEEN_EYE, ABILITY_HARVEST},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Chiefturk"),
        .cryId = CRY_CHIEFTURK,
        .natDexNum = NATIONAL_DEX_CHIEFTURK,
        .categoryName = _("Ottawa"),
        .height = 18,
        .weight = 410,
        .description = COMPOUND_STRING(
            "In an effort to preserve nature,\n"
            "Chiefturk has learned to paint\n"
            "with all the colors of the wind.\n"
            "Its arrows look like rainbows."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chiefturk,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chiefturk,
        .frontAnimId = ANIM_GROW_TWICE,
	.frontAnimDelay = 10,
        .backPic = gMonBackPic_Chiefturk,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Chiefturk,
        .shinyPalette = gMonShinyPalette_Chiefturk,
        .iconSprite = gMonIcon_Chiefturk,
        .iconPalIndex = 3,
        FOOTPRINT(Chiefturk)
        OVERWORLD(
            sPicTable_Chiefturk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chiefturk,
            gShinyOverworldPalette_Chiefturk
        )
        .levelUpLearnset = sChiefturkLevelUpLearnset,
        .teachableLearnset = sChiefturkTeachableLearnset,
    },
#endif //P_FAMILY_ARROWBIN

#if P_FAMILY_NEUREKA
    [SPECIES_NEUREKA] = //LIGHTBULB POKÉMON
    {
        .baseHP        = 30,
        .baseAttack    = 41,
        .baseDefense   = 30,
        .baseSpeed     = 35,
        .baseSpAttack  = 79,
        .baseSpDefense = 79,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GHOST),
        .catchRate = 225,
        .expYield = 59,
        .evYield_SpAttack    = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 0,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_STATIC, ABILITY_ILLUMINATE, ABILITY_LIGHTNING_ROD},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Neureka"),
        .cryId = CRY_NEUREKA,
        .natDexNum = NATIONAL_DEX_NEUREKA,
        .categoryName = _("Lightbulb"),
        .height = 2,
        .weight = 5,
        .description = COMPOUND_STRING(
            "Legend claims that Neureka are\n"
            "failed inventors who committed\n"
            "suicide before they could design\n"
            "their big breakthrough invention."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Neureka,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Neureka,
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Neureka,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Neureka,
        .shinyPalette = gMonShinyPalette_Neureka,
        .iconSprite = gMonIcon_Neureka,
        .iconPalIndex = 3,
        FOOTPRINT(Neureka)
        OVERWORLD(
            sPicTable_Neureka,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Neureka,
            gShinyOverworldPalette_Neureka
        )
        .levelUpLearnset = sNeurekaLevelUpLearnset,
        .teachableLearnset = sNeurekaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDERSTONE, SPECIES_EDISYNAPSE}),
    },

    [SPECIES_EDISYNAPSE] = //EVOLVE VIA THUNDERSTONE
    {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 145,
        .baseSpDefense = 140,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 159,
        .evYield_SpAttack    = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 0,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_STATIC, ABILITY_ILLUMINATE, ABILITY_LIGHTNING_ROD},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Edisynapse"),
        .cryId = CRY_EDISYNAPSE,
        .natDexNum = NATIONAL_DEX_EDISYNAPSE,
        .categoryName = _("Lightbulb"),
        .height = 5,
        .weight = 15,
        .description = COMPOUND_STRING(
            "It is said that the transmitters\n"
            "on Edisynapses' arms are able to\n"
            "transfer data in a similar manner\n"
            "to the internet."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Edisynapse,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Edisynapse,
        .frontAnimId = ANIM_TIP_HOP_FORWARD,
        .backPic = gMonBackPic_Edisynapse,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Edisynapse,
        .shinyPalette = gMonShinyPalette_Edisynapse,
        .iconSprite = gMonIcon_Edisynapse,
        .iconPalIndex = 0,
        FOOTPRINT(Edisynapse)
        OVERWORLD(
            sPicTable_Edisynapse,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Edisynapse,
            gShinyOverworldPalette_Edisynapse
        )
        .levelUpLearnset = sEdisynapseLevelUpLearnset,
        .teachableLearnset = sEdisynapseTeachableLearnset,
    },
#endif //P_FAMILY_NEUREKA

#if P_FAMILY_SCLICK
    [SPECIES_SCLICK] = //COMPUTER MOUSE+SCORPION POKÉMON
    {
        .baseHP        = 50,
        .baseAttack    = 57,
        .baseDefense   = 45,
        .baseSpeed     = 67,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_BUG),
        .catchRate = 190,
        .expYield = 64,
        .evYield_Speed    = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = {ABILITY_MOTOR_DRIVE, ABILITY_NONE, ABILITY_PROPELLER_TAIL},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Sclick"),
        .cryId = CRY_SCLICK,
        .natDexNum = NATIONAL_DEX_SCLICK,
        .categoryName = _("CPU Mouse"),
        .height = 5,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Sclick's tail conducts electricity\n"
            "into its internal motor.\n"
            "It can often be found feeding on\n"
            "power lines."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sclick,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Sclick,
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Sclick,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Sclick,
        .shinyPalette = gMonShinyPalette_Sclick,
        .iconSprite = gMonIcon_Sclick,
        .iconPalIndex = 5,
        FOOTPRINT(Sclick)
        OVERWORLD(
            sPicTable_Sclick,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Sclick,
            gShinyOverworldPalette_Sclick
        )
        .levelUpLearnset = sSclickLevelUpLearnset,
        .teachableLearnset = sSclickTeachableLearnset,
	.eggMoveLearnset = sSclickEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_VECTRION}),
    },

    [SPECIES_VECTRION] = //EVOLVE AT LEVEL 30
    {
        .baseHP        = 70,
        .baseAttack    = 87,
        .baseDefense   = 70,
        .baseSpeed     = 108,
        .baseSpAttack  = 85,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_BUG),
        .catchRate = 80,
        .expYield = 122,
        .evYield_Speed    = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = {ABILITY_MOTOR_DRIVE, ABILITY_NONE, ABILITY_PROPELLER_TAIL},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Vectrion"),
        .cryId = CRY_VECTRION,
        .natDexNum = NATIONAL_DEX_VECTRION,
        .categoryName = _("CPU Mouse"),
        .height = 11,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Vectrion is only capable of moving\n"
            "in a straight line.\n"
            "It will often use electricity\n"
            "to immobilize prey before chasing."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vectrion,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Vectrion,
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Vectrion,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Vectrion,
        .shinyPalette = gMonShinyPalette_Vectrion,
        .iconSprite = gMonIcon_Vectrion,
        .iconPalIndex = 5,
        FOOTPRINT(Vectrion)
        OVERWORLD(
            sPicTable_Vectrion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Vectrion,
            gShinyOverworldPalette_Vectrion
        )
        .levelUpLearnset = sVectrionLevelUpLearnset,
        .teachableLearnset = sVectrionTeachableLearnset,
    },
#endif //P_FAMILY_SCLICK

#if P_FAMILY_FAWNPIRE
    [SPECIES_FAWNPIRE] = //CHINESE WATER DEER POKÉMON
    {
        .baseHP        = 55,
        .baseAttack    = 62,
        .baseDefense   = 45,
        .baseSpeed     = 48,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 225,
        .expYield = 54,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_VAMPIRISM, ABILITY_RIVALRY, ABILITY_SWIFT_SWIM}, //VAMPIRISM: BITING MOVES BECOME HP DRAINING MOVES
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Fawnpire"),
        .cryId = CRY_FAWNPIRE,
        .natDexNum = NATIONAL_DEX_FAWNPIRE,
        .categoryName = _("Water Deer"),
        .height = 9,
        .weight = 174,
        .description = COMPOUND_STRING(
            "Fawnpire feeds off of the nutrients\n"
            "in the blood of other Pokémon.\n"
            "Their teeth have suction and\n"
            "are used for drinking."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fawnpire,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fawnpire,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Fawnpire,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Fawnpire,
        .shinyPalette = gMonShinyPalette_Fawnpire,
        .iconSprite = gMonIcon_Fawnpire,
        .iconPalIndex = 2,
        FOOTPRINT(Fawnpire)
        OVERWORLD(
            sPicTable_Fawnpire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Fawnpire,
            gShinyOverworldPalette_Fawnpire
        )
        .levelUpLearnset = sFawnpireLevelUpLearnset,
        .teachableLearnset = sFawnpireTeachableLearnset,
	.eggMoveLearnset = sFawnpireEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_ALPACULA}),
},

    [SPECIES_ALPACULA] = // EVOLVE AT LEVEL 28
    {
        .baseHP        = 73,
        .baseAttack    = 95,
        .baseDefense   = 63,
        .baseSpeed     = 78,
        .baseSpAttack  = 92,
        .baseSpDefense = 94,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 100,
        .expYield = 170,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_VAMPIRISM, ABILITY_RIVALRY, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Alpacula"),
        .cryId = CRY_ALPACULA,
        .natDexNum = NATIONAL_DEX_ALPACULA,
        .categoryName = _("Water Deer"),
        .height = 18,
        .weight = 1704,
        .description = COMPOUND_STRING(
            "Alpacula travel in herds.\n"
            "The leader of the herd is the\n"
            "female that manages to suck the\n"
            "blood of the largest male."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Alpacula,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Alpacula,
        .frontAnimId = ANIM_H_SPRING_FAST,
        .backPic = gMonBackPic_Alpacula,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Alpacula,
        .shinyPalette = gMonShinyPalette_Alpacula,
        .iconSprite = gMonIcon_Alpacula,
        .iconPalIndex = 4,
        FOOTPRINT(Alpacula)
        OVERWORLD(
            sPicTable_Alpacula,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Alpacula,
            gShinyOverworldPalette_Alpacula
        )
        .levelUpLearnset = sAlpaculaLevelUpLearnset,
        .teachableLearnset = sAlpaculaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_MOOSEFERATU}),
},

    [SPECIES_MOOSEFERATU] =
    {
        .baseHP        = 73,
        .baseAttack    = 105,
        .baseDefense   = 63,
        .baseSpeed     = 88,
        .baseSpAttack  = 95,
        .baseSpDefense = 94,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 100,
        .expYield = 170,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_VAMPIRISM, ABILITY_RIVALRY, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mooseferatu"),
        .cryId = CRY_MOOSEFERATU,
        .natDexNum = NATIONAL_DEX_MOOSEFERATU,
        .categoryName = _("Moose"),
        .height = 21,
        .weight = 4536,
        .description = COMPOUND_STRING(
            "Mooseferatu are playful\n"
            "creatures. Unfortunately for\n"
            "humans, they like to play with\n"
            "cars, toppling them over."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mooseferatu,
	.frontPicFemale = gMonFrontPic_MooseferatuF,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
	.frontPicSizeFemale = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Mooseferatu,
        .frontAnimId = ANIM_CONVEX_DOUBLE_ARC_SLOW,
        .backPic = gMonBackPic_Mooseferatu,
	.backPicFemale = gMonBackPic_MooseferatuF,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Mooseferatu,
        .shinyPalette = gMonShinyPalette_Mooseferatu,
        .iconSprite = gMonIcon_Mooseferatu,
        .iconPalIndex = 2,
        FOOTPRINT(Mooseferatu)
        OVERWORLD(
            sPicTable_Mooseferatu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Mooseferatu,
            gShinyOverworldPalette_Mooseferatu
        )
        .levelUpLearnset = sMooseferatuLevelUpLearnset,
        .teachableLearnset = sMooseferatuTeachableLearnset,
},
#endif //P_FAMILY_FAWNPIRE

#if P_FAMILY_PLATYPOW
    [SPECIES_PLATYPOW] = //BOXING PLATYPUS POKÉMON
    {
        .baseHP        = 44,
        .baseAttack    = 78,
        .baseDefense   = 66,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_WATER),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack    = 1,
	.itemRare = ITEN_PUNCHING_GLOVE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_POISON_TOUCH, ABILITY_IRON_FIST, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BROWN,
          .speciesName = _("Platypow"),
        .cryId = CRY_PLATYPOW,
        .natDexNum = NATIONAL_DEX_PLATYPOW,
        .categoryName = _("Platypus"),
        .height = 5,
        .weight = 15,
        .description = COMPOUND_STRING(
            "Platypow has poisonous barbs on\n"
            "its ankles. They consider these\n"
            "barbs dishonorable to use in combat,\n"
            "so they learned to box."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Platypow,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Platypow,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Platypow,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Platypow,
        .shinyPalette = gMonShinyPalette_Platypow,
        .iconSprite = gMonIcon_Platypow,
        .iconPalIndex = 5,
        FOOTPRINT(Platypow)
        OVERWORLD(
            sPicTable_Platypow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Platypow,
            gShinyOverworldPalette_Platypow
        )
        .levelUpLearnset = sPlatypowLevelUpLearnset,
        .teachableLearnset = sPlatypowTeachableLearnset,
	.eggMoveLearnset = sPlatypowEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_PLATYPUNCH}),
    },

    [SPECIES_PLATYPUNCH] = // EVOLVE AT LEVEL 32
    {
        .baseHP        = 74,
        .baseAttack    = 114,
        .baseDefense   = 80,
        .baseSpeed     = 75,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_WATER),
        .catchRate = 100,
        .expYield = 121,
        .evYield_Attack    = 2,
	.itemRare = ITEN_PUNCHING_GLOVE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_POISON_TOUCH, ABILITY_IRON_FIST, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Platypunch"),
        .cryId = CRY_PLATYPUNCH,
        .natDexNum = NATIONAL_DEX_PLATYPUNCH,
        .categoryName = _("Platypus"),
        .height = 10,
        .weight = 70,
        .description = COMPOUND_STRING(
            "Platypunch are excellent swimmers.\n"
            "They use their tail to propel\n"
            "themselves through the water, and\n"
            "they punch the water to turn."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Platypunch,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Platypunch,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Platypunch,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Platypunch,
        .shinyPalette = gMonShinyPalette_Platypunch,
        .iconSprite = gMonIcon_Platypunch,
        .iconPalIndex = 5,
        FOOTPRINT(Platypunch)
        OVERWORLD(
            sPicTable_Platypunch,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Platypunch,
            gShinyOverworldPalette_Platypunch
        )
        .levelUpLearnset = sPlatypunchLevelUpLearnset,
        .teachableLearnset = sPlatypunchTeachableLearnset,
    },
#endif //P_FAMILY_PLATYPOW

#if P_FAMILY_SILKINDER
    [SPECIES_SILKINDER_MALE] =
    {
        .baseHP        = 47,
        .baseAttack    = 37,
        .baseDefense   = 47,
        .baseSpeed     = 67,
        .baseSpAttack  = 77,
        .baseSpDefense = 67,
        .types = MON_TYPES(TYPE_BUG, TYPE_FAIRY),
        .catchRate = 200,
        .expYield = 45,
        .evYield_SpAttack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 30,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_FRISK, ABILITY_COSTAR, ABILITY_SHED_SKIN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Silkinder"),
        .cryId = CRY_SILKINDER_MALE,
        .natDexNum = NATIONAL_DEX_SILKINDER,
        .categoryName = _("Schoolkid"),
        .height = 7,
        .weight = 162,
        .description = COMPOUND_STRING(
            "Silkinder is a very curious\n"
            "Pokémon. It always wants to\n"
            "learn new things, and so it\n"
            "follows Sensilk around."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SilkinderMale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Silkinder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SilkinderMale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_SilkinderMale,
        .shinyPalette = gMonShinyPalette_SilkinderMale,
        .iconSprite = gMonIcon_SilkinderMale,
        .iconPalIndex = 4,
        FOOTPRINT(Silkinder)
        OVERWORLD(
            sPicTable_SilkinderMale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_SilkinderMale,
            gShinyOverworldPalette_SilkinderMale
        )
        .levelUpLearnset = sSilkinderLevelUpLearnset,
        .teachableLearnset = sSilkinderTeachableLearnset,
	.eggMoveLearnset = sSilkinderEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_SENSILK_MALE}),
    },

    [SPECIES_SILKINDER_FEMALE] =
    {
        .baseHP        = 47,
        .baseAttack    = 37,
        .baseDefense   = 47,
        .baseSpeed     = 67,
        .baseSpAttack  = 77,
        .baseSpDefense = 67,
        .types = MON_TYPES(TYPE_BUG, TYPE_FAIRY),
        .catchRate = 200,
        .expYield = 45,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 30,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_FRISK, ABILITY_SERENE_GRACE, ABILITY_SHED_SKIN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Silkinder"),
        .cryId = CRY_SILKINDER_FEMALE,
        .natDexNum = NATIONAL_DEX_SILKINDER,
        .categoryName = _("Schoolkid"),
        .height = 6,
        .weight = 132,
        .description = COMPOUND_STRING(
            "Silkinder is a very curious\n"
            "Pokémon. It always wants to\n"
            "learn new things, and so it\n"
            "follows Sensilk around."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SilkinderFemale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Silkinder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SilkinderFemale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_SilkinderFemale,
        .shinyPalette = gMonShinyPalette_SilkinderFemale,
        .iconSprite = gMonIcon_SilkinderFemale,
        .iconPalIndex = 1,
        FOOTPRINT(Silkinder)
        OVERWORLD(
            sPicTable_SilkinderFemale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_SilkinderFemale,
            gShinyOverworldPalette_SilkinderFemale
        )
        .levelUpLearnset = sSilkinderLevelUpLearnset,
        .teachableLearnset = sSilkinderTeachableLearnset,
	.eggMoveLearnset = sSilkinderEggMoveLearnset
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_SENSILK_FEMALE}),
    },

    [SPECIES_SENSILK_MALE] =
    {
        .baseHP        = 77,
        .baseAttack    = 67,
        .baseDefense   = 77,
        .baseSpeed     = 97,
        .baseSpAttack  = 107,
        .baseSpDefense = 97,
        .types = MON_TYPES(TYPE_BUG, TYPE_FAIRY),
        .catchRate = 100,
        .expYield = 155,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 30,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_MINUS, ABILITY_COSTAR, ABILITY_SHED_SKIN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Sensilk"),
        .cryId = CRY_SENSILK_MALE,
        .natDexNum = NATIONAL_DEX_SENSILK,
        .categoryName = _("Sensei"),
        .height = 17,
        .weight = 782,
        .description = COMPOUND_STRING(
            "It loves to teach. You\n"
            "can often find it with a\n"
            "group of Pokémon around it.\n"
            "It is very affectionate."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SensilkMale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Sensilk,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_SensilkMale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_SensilkMale,
        .shinyPalette = gMonShinyPalette_SensilkMale,
        .iconSprite = gMonIcon_SensilkMale,
        .iconPalIndex = 4,
        FOOTPRINT(Sensilk)
        OVERWORLD(
            sPicTable_SensilkMale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_SensilkMale,
            gShinyOverworldPalette_SensilkMale
        )
        .levelUpLearnset = sSensilkLevelUpLearnset,
        .teachableLearnset = sSensilkTeachableLearnset,
    },

    [SPECIES_SENSILK_FEMALE] =
    {
        .baseHP        = 77,
        .baseAttack    = 67,
        .baseDefense   = 77,
        .baseSpeed     = 97,
        .baseSpAttack  = 107,
        .baseSpDefense = 97,
        .types = MON_TYPES(TYPE_BUG, TYPE_FAIRY),
        .catchRate = 100,
        .expYield = 155,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 30,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_PLUS, ABILITY_SERENE_GRACE, ABILITY_SHED_SKIN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Sensilk"),
        .cryId = CRY_SENSILK_FEMALE,
        .natDexNum = NATIONAL_DEX_SENSILK,
        .categoryName = _("Sensei"),
        .height = 16,
        .weight = 632,
        .description = COMPOUND_STRING(
            "It loves to teach. You\n"
            "can often find it with a\n"
            "group of Pokémon around it.\n"
            "It is very affectionate."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SensilkFemale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Sensilk,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_SensilkFemale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_SensilkFemale,
        .shinyPalette = gMonShinyPalette_SensilkFemale,
        .iconSprite = gMonIcon_SensilkFemale,
        .iconPalIndex = 1,
        FOOTPRINT(Sensilk)
        OVERWORLD(
            sPicTable_SensilkFemale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_SensilkFemale,
            gShinyOverworldPalette_SensilkFemale
        )
        .levelUpLearnset = sSensilkLevelUpLearnset,
        .teachableLearnset = sSensilkTeachableLearnset,
    },
#endif //P_FAMILY_SILKINDER

#if P_FAMILY_DALTOM
    [SPECIES_DALTOM] =
    {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 58,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_PSYCHIC),
        .catchRate = 125,
        .expYield = 59,
        .evYield_SpAttack    = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_PLUS, ABILITY_MINUS, ABILITY_AFTERMATH},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Daltom"),
        .cryId = CRY_DALTOM,
        .natDexNum = NATIONAL_DEX_DALTOM,
        .categoryName = _("Atomic"),
        .height = 1,
        .weight = 1080,
        .description = COMPOUND_STRING(
            "Daltom is incredibly dense.\n"
            "When its integrity collapses,\n"
            "it has the power to level\n"
            "entire cities."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Daltom,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Daltom,
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Daltom,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Daltom,
        .shinyPalette = gMonShinyPalette_Daltom,
        .iconSprite = gMonIcon_Daltom,
        .iconPalIndex = 3,
        FOOTPRINT(Daltom)
        OVERWORLD(
            sPicTable_Daltom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Daltom,
            gShinyOverworldPalette_Daltom
        )
        .levelUpLearnset = sDaltomLevelUpLearnset,
        .teachableLearnset = sDaltomTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 45, SPECIES_OPPENHION}),
    },

    [SPECIES_OPPENHION] =
    {
        .baseHP        = 60,
        .baseAttack    = 63,
        .baseDefense   = 98,
        .baseSpeed     = 103,
        .baseSpAttack  = 108,
        .baseSpDefense = 101,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 150,
        .evYield_SpAttack    = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_PLUS, ABILITY_MINUS, ABILITY_AFTERMATH},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Oppenhion"),
        .cryId = CRY_OPPENHION,
        .natDexNum = NATIONAL_DEX_OPPENHION,
        .categoryName = _("Atomic"),
        .height = 3,
        .weight = 1107,
        .description = COMPOUND_STRING(
            "Prolonged exposure to an aged\n"
            "Oppenhion can have alarming side-\n"
            "effects. It was used to end the\n"
            "Great War in Kanto."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Oppenhion,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Oppenhion,
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Oppenhion,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Oppenhion,
        .shinyPalette = gMonShinyPalette_Oppenhion,
        .iconSprite = gMonIcon_Oppenhion,
        .iconPalIndex = 0,
        FOOTPRINT(Oppenhion)
        OVERWORLD(
            sPicTable_Oppenhion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Oppenhion,
            gShinyOverworldPalette_Oppenhion
        )
        .levelUpLearnset = sOppenhionLevelUpLearnset,
        .teachableLearnset = sOppenhionTeachableLearnset,
    },
#endif //P_FAMILY_DALTOM

#if P_FAMILY_GOLTERRA
    [SPECIES_GOLTERRA] = //GOLEM THAT GUARDS ALL OF NATURE POKÉMON (PRIMARILY GRASS/GROUND/ROCK/WATER/PSYCHIC MOVES. FORCES OF NATURE, GAIA HAMMER EXCLUSIVE MOVE)
    {
        .baseHP        = 75,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 73,
        .evYield_HP    = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_CLOUD_NINE, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Golterra"),
        .cryId = CRY_GOLTERRA,
        .natDexNum = NATIONAL_DEX_GOLTERRA,
        .categoryName = _("Guardian"),
        .height = 10,
        .weight = 900,
        .description = COMPOUND_STRING(
            "Golterra has a deep connection to\n"
            "the divine forces of nature.\n"
            "It is believed that they guard\n"
            "the balance of nature itself."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Golterra,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Golterra,
        .frontAnimId = ANIM_FOUR_PETAL,
        .backPic = gMonBackPic_Golterra,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Golterra,
        .shinyPalette = gMonShinyPalette_Golterra,
        .iconSprite = gMonIcon_Golterra,
        .iconPalIndex = 4,
        FOOTPRINT(Golterra)
        OVERWORLD(
            sPicTable_Golterra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Golterra,
            gShinyOverworldPalette_Golterra
        )
        .levelUpLearnset = sGolterraLevelUpLearnset,
        .teachableLearnset = sGolterraTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_GAIOLEM}),
    },

    [SPECIES_GAIOLEM] = // EVOLVE AT LEVEL 37
    {
        .baseHP        = 125,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 67,
        .baseSpAttack  = 73,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GRASS),
        .catchRate = 80,
        .expYield = 161,
        .evYield_HP    = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_CLOUD_NINE, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gaiolem"),
        .cryId = CRY_GAIOLEM,
        .natDexNum = NATIONAL_DEX_GAIOLEM,
        .categoryName = _("Guardian"),
        .height = 22,
        .weight = 2750,
        .description = COMPOUND_STRING(
            "Gaiolem was blessed by Regigigas\n"
            "to be guardians of the Regis.\n"
            "They did not originally have moss\n"
            "coverings, but they like the warmth."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gaiolem,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Gaiolem,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
	.frontAnimDelay = 15,
        .backPic = gMonBackPic_Gaiolem,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Gaiolem,
        .shinyPalette = gMonShinyPalette_Gaiolem,
        .iconSprite = gMonIcon_Gaiolem,
        .iconPalIndex = 4,
        FOOTPRINT(Gaiolem)
        OVERWORLD(
            sPicTable_Gaiolem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Gaiolem,
            gShinyOverworldPalette_Gaiolem
        )
        .levelUpLearnset = sGaiolemLevelUpLearnset,
        .teachableLearnset = sGaiolemTeachableLearnset,
    },
#endif //P_FAMILY_GOLTERRA

#if P_FAMILY_RELLADUNE
    [SPECIES_RELLADUNE] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FIGHTING),
        .catchRate = 175,
        .expYield = 74,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 60,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_HUSTLE},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Relladune"),
        .cryId = CRY_RELLADUNE,
        .natDexNum = NATIONAL_DEX_RELLADUNE,
        .categoryName = _("Morelladon"),
        .height = 11,
        .weight = 586,
        .description = COMPOUND_STRING(
            "Relladune will headbutt\n"
            "everything it sees at\n"
            "least once. If it doesn't\n"
            "hurt, it'll headbutt again."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Relladune,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Relladune,
        .frontAnimId = ANIM_TIP_HOP_FORWARD,
        .backPic = gMonBackPic_Relladune,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Relladune,
        .shinyPalette = gMonShinyPalette_Relladune,
        .iconSprite = gMonIcon_Relladune,
        .iconPalIndex = 3,
        FOOTPRINT(Relladune)
        OVERWORLD(
            sPicTable_Relladune,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Relladune,
            gShinyOverworldPalette_Relladune
        )
        .levelUpLearnset = sRelladuneLevelUpLearnset,
        .teachableLearnset = sRelladuneTeachableLearnset,
	.eggMoveLearnset = sRelladuneEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_HEAD_SMASH, SPECIES_CAMORELLA}),
    },

    [SPECIES_CAMORELLA] =
    {
        .baseHP        = 115,
        .baseAttack    = 125,
        .baseDefense   = 95,
        .baseSpeed     = 75,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FIGHTING),
        .catchRate = 65,
        .expYield = 164,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 60,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_GUTS},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Camorella"),
        .cryId = CRY_CAMORELLA,
        .natDexNum = NATIONAL_DEX_CAMORELLA,
        .categoryName = _("Morelladon"),
        .height = 20,
        .weight = 1883,
        .description = COMPOUND_STRING(
            "No one knows how it's\n"
            "not gone extinct yet.\n"
            "Their picky diet doesn't\n"
            "give them enough energy."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Camorella,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Camorella,
        .frontAnimId = ANIM_SHRINK_GROW_SLOW,
        .backPic = gMonBackPic_Camorella,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Camorella,
        .shinyPalette = gMonShinyPalette_Camorella,
        .iconSprite = gMonIcon_Camorella,
        .iconPalIndex = 1,
        FOOTPRINT(Camorella)
        OVERWORLD(
            sPicTable_Camorella,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Camorella,
            gShinyOverworldPalette_Camorella
        )
        .levelUpLearnset = sCamorellaLevelUpLearnset,
        .teachableLearnset = sCamorellaTeachableLearnset,
    },
#endif //P_FAMILY_RELLADUNE

#if P_FAMILY_COBOE
    [SPECIES_COBOE] =
    {
        .baseHP        = 70,
        .baseAttack    = 50,
        .baseDefense   = 55,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_POISON, TYPE_SOUND),
        .catchRate = 150,
        .expYield = 58,
        .evYield_HP    = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = {ABILITY_SAPERA, ABILITY_NONE, ABILITY_NONE}, //SAPERA IS A SNAKE CHARMER. COME UP WITH ABILITY BASED ON THAT.
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Coboe"),
        .cryId = CRY_COBOE,
        .natDexNum = NATIONAL_DEX_COBOE,
        .categoryName = _("Snake Charmer"),
        .height = 15,
        .weight = 30,
        .description = COMPOUND_STRING(
            "Coboe conducts wind through the\n"
            "holes in its body to produce\n"
            "hypnotic melodies that entrance\n"
            "its prey."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Coboe,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Coboe,
        .frontAnimId = ANIM_V_STRETCH_BOTH_ENDS,
        .backPic = gMonBackPic_Coboe,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Coboe,
        .shinyPalette = gMonShinyPalette_Coboe,
        .iconSprite = gMonIcon_Coboe,
        .iconPalIndex = 5,
        FOOTPRINT(Coboe)
        OVERWORLD(
            sPicTable_Coboe,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Coboe,
            gShinyOverworldPalette_Coboe
        )
        .levelUpLearnset = sCoboeLevelUpLearnset,
        .teachableLearnset = sCoboeTeachableLearnset,
	.eggMoveLearnset = sCoboeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_PUNGRIYADH}),
    },

    [SPECIES_PUNGRIYADH] =
    {
        .baseHP        = 119,
        .baseAttack    = 70,
        .baseDefense   = 75,
        .baseSpeed     = 101,
        .baseSpAttack  = 90,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_POISON, TYPE_SOUND),
        .catchRate = 150,
        .expYield = 58,
        .evYield_HP    = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = {ABILITY_SAPERA, ABILITY_NONE, ABILITY_NONE}, //SAPERA IS A SNAKE CHARMER. COME UP WITH ABILITY BASED ON THAT.
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pungriyadh"),
        .cryId = CRY_PUNGRIYADH,
        .natDexNum = NATIONAL_DEX_PUNGRIYADH,
        .categoryName = _("Snake Charmer"),
        .height = 20,
        .weight = 91,
        .description = COMPOUND_STRING(
            "Pungriyadh's holes can produce\n"
            "polyphonic sound that can\n"
            "hypnotize humans. Curiously,\n"
            "humans use it commercially."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pungriyadh,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pungriyadh,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Pungriyadh,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Pungriyadh,
        .shinyPalette = gMonShinyPalette_Pungriyadh,
        .iconSprite = gMonIcon_Pungriyadh,
        .iconPalIndex = 3,
        FOOTPRINT(Pungriyadh)
        OVERWORLD(
            sPicTable_Pungriyadh,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pungriyadh,
            gShinyOverworldPalette_Pungriyadh
        )
        .levelUpLearnset = sPungriyadhLevelUpLearnset,
        .teachableLearnset = sPungriyadhTeachableLearnset,
    },
#endif //P_FAMILY_COBOE

#if P_FAMILY_SEDIRROT
    [SPECIES_SEDIRROT] =
    {
        .baseHP        = 59,
        .baseAttack    = 71,
        .baseDefense   = 73,
        .baseSpeed     = 60,
        .baseSpAttack  = 38,
        .baseSpDefense = 41,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 90,
        .expYield = 67,
        .evYield_Defense    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_MINERAL),
        .abilities = {ABILITY_BATTLE_ARMOR, ABILITY_MOLD_BREAKER, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Sedirrot"),
        .cryId = CRY_SEDIRROT,
        .natDexNum = NATIONAL_DEX_SEDIRROT,
        .categoryName = _("Condor"),
        .height = 10,
        .weight = 617,
        .description = COMPOUND_STRING(
            "Sedirrot's primary means\n"
            "of acquiring food is by\n"
            "scavenging. It camoflauges\n"
            "with the rocky canyon."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sedirrot,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Sedirrot,
        .frontAnimId = ANIM_V_REPEATED_SPRING,
        .backPic = gMonBackPic_Sedirrot,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Sedirrot,
        .shinyPalette = gMonShinyPalette_Sedirrot,
        .iconSprite = gMonIcon_Sedirrot,
        .iconPalIndex = 0,
        FOOTPRINT(Sedirrot)
        OVERWORLD(
            sPicTable_Sedirrot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Sedirrot,
            gShinyOverworldPalette_Sedirrot
        )
        .levelUpLearnset = sSedirrotLevelUpLearnset,
        .teachableLearnset = sSedirrotTeachableLearnset,
	.eggMoveLearnset = sSedirrotEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_CONDESA}),
    },

    [SPECIES_CONDESA] =
    {
        .baseHP        = 81,
        .baseAttack    = 103,
        .baseDefense   = 118,
        .baseSpeed     = 80,
        .baseSpAttack  = 61,
        .baseSpDefense = 69,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 90,
        .expYield = 67,
        .evYield_Defense    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_MINERAL),
        .abilities = {ABILITY_BATTLE_ARMOR, ABILITY_MOLD_BREAKER, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Condesa"),
        .cryId = CRY_CONDESA,
        .natDexNum = NATIONAL_DEX_CONDESA,
        .categoryName = _("Condor"),
        .height = 15,
        .weight = 1232,
        .description = COMPOUND_STRING(
            "Condesa spends years\n"
            "chiseling its body with\n"
            "rocks to create the\n"
            "perfect design."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Condesa,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Condesa,
        .frontAnimId = ANIM_H_DIP_FAST,
        .backPic = gMonBackPic_Condesa,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Condesa,
        .shinyPalette = gMonShinyPalette_Condesa,
        .iconSprite = gMonIcon_Condesa,
        .iconPalIndex = 2,
        FOOTPRINT(Condesa)
        OVERWORLD(
            sPicTable_Condesa,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Condesa,
            gShinyOverworldPalette_Condesa
        )
        .levelUpLearnset = sCondesaLevelUpLearnset,
        .teachableLearnset = sCondesaTeachableLearnset,
    },
#endif //P_FAMILY_SEDIRROT

#if P_FAMILY_NOBUNATA
    [SPECIES_NOBUNATA] =
    {
        .baseHP        = 134,
        .baseAttack    = 93,
        .baseDefense   = 55,
        .baseSpeed     = 82,
        .baseSpAttack  = 76,
        .baseSpDefense = 94,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 182,
        .expYield = 134,
        .evYield_HP    = 2,
        .itemCommon = ITEM_HEALTH_MOCHI,
        .itemRare = ITEM_HARD_FRESH_START_MOCHI,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_NO_GUARD},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Nobunata"),
        .cryId = CRY_NOBUNATA,
        .natDexNum = NATIONAL_DEX_NOBUNATA,
        .categoryName = _("Pinata"),
        .height = 6,
        .weight = 9,
        .description = COMPOUND_STRING(
            "According to legend, Nobunata\n"
            "has Mochi stuffed in its body.\n"
            "Ancient people used to wear\n"
            "blindfolds and swing at them."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nobunata,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Nobunata,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Nobunata,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Nobunata,
        .shinyPalette = gMonShinyPalette_Nobunata,
        .iconSprite = gMonIcon_Nobunata,
        .iconPalIndex = 5,
        FOOTPRINT(Nobunata)
        OVERWORLD(
            sPicTable_Nobunata,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Nobunata,
            gShinyOverworldPalette_Nobunata
        )
        .levelUpLearnset = sNobunataLevelUpLearnset,
        .teachableLearnset = sNobunataTeachableLearnset,
	.eggMoveLearnset = sNobunataEggMoveLearnset,
},
#endif //P_FAMILY_NOBUNATA

#if P_FAMILY_SOMBERO
    [SPECIES_SOMBERO] =
    {
        .baseHP        = 67,
        .baseAttack    = 80,
        .baseDefense   = 60,
        .baseSpeed     = 86,
        .baseSpAttack  = 103,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_GHOST, TYPE_GROUND),
        .catchRate = 70,
        .expYield = 142,
        .evYield_HP    = 2,
        .itemCommon = ITEM_QUICK_CLAW,
        .itemRare = ITEM_METRONOME,
        .genderRatio = MON_MALE,
        .eggCycles = 55,
        .friendship = 15,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS, EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_QUICK_DRAW, ABILITY_GUNSLINGER, ABILITY_SHADOW_TAG}, //Powers up ballistic moves
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sombero"),
        .cryId = CRY_SOMBERO,
        .natDexNum = NATIONAL_DEX_SOMBERO,
        .categoryName = _("Gunslinger"),
        .height = 13,
        .weight = 137,
        .description = COMPOUND_STRING(
            "An outlaw of the wild west lost\n"
            "his standoff and became a Sombero.\n"
            "Now, as a ghost, he practices his\n"
            "shooting so he never loses again."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sombero,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Sombero,
        .frontAnimId = ANIM_GLOW_BLACK,
        .backPic = gMonBackPic_Sombero,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Sombero,
        .shinyPalette = gMonShinyPalette_Sombero,
        .iconSprite = gMonIcon_Sombero,
        .iconPalIndex = 3,
        FOOTPRINT(Sombero)
        OVERWORLD(
            sPicTable_Sombero,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Sombero,
            gShinyOverworldPalette_Sombero
        )
        .levelUpLearnset = sSomberoLevelUpLearnset,
        .teachableLearnset = sSomberoTeachableLearnset,
	.eggMoveLearnset = sSomberoEggMoveLearnset,
},
#endif //P_FAMILY_SOMBERO

#if P_FAMILY_MINARAC
    [SPECIES_MINARAC] = //MINING TARANTULA WITH A BIG DRILL BUTT
    {
        .baseHP        = 45,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_BUG, TYPE_GROUND),
        .catchRate = 150,
        .expYield = 58,
        .evYield_SpDefense    = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_MINERAL),
        .abilities = {ABILITY_SAND_VEIL, ABILITY_SWARM, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Minarac"),
        .cryId = CRY_MINARAC,
        .natDexNum = NATIONAL_DEX_MINARAC,
        .categoryName = _("Tarantula"),
        .height = 5,
        .weight = 200,
        .description = COMPOUND_STRING(
            "They drill holes with their butt.\n"
            "They are preyed upon by Coboe\n"
            "and Pungriyadh, so they drill\n"
            "complex mazes to evade them."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Minarac,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Minarac,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Minarac,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Minarac,
        .shinyPalette = gMonShinyPalette_Minarac,
        .iconSprite = gMonIcon_Minarac,
        .iconPalIndex = 3,
        FOOTPRINT(Minarac)
        OVERWORLD(
            sPicTable_Minarac,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Minarac,
            gShinyOverworldPalette_Minarac
        )
        .levelUpLearnset = sMinaracLevelUpLearnset,
        .teachableLearnset = sMinaracTeachableLearnset,
	.eggMoveLearnset = sMinaracEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_TARENCHULA}),
    },

    [SPECIES_TARENCHULA] =  // EVOLVE AT LEVEL 37
    {
        .baseHP        = 85,
        .baseAttack    = 135,
        .baseDefense   = 60,
        .baseSpeed     = 87,
        .baseSpAttack  = 50,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_BUG, TYPE_GROUND),
        .catchRate = 45,
        .expYield = 132,
        .evYield_Speed    = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_SWARM, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Tarenchula"),
        .cryId = CRY_TARENCHULA,
        .natDexNum = NATIONAL_DEX_TARENCHULA,
        .categoryName = _("Tarantula"),
        .height = 11,
        .weight = 444,
        .description = COMPOUND_STRING(
            "Despite being much smaller,\n"
            "Tarenchula has evolved to be\n"
            "able to drill through the body\n"
            "of Pungriyadh and prey on them."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tarenchula,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Tarenchula,
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Tarenchula,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Tarenchula,
        .shinyPalette = gMonShinyPalette_Tarenchula,
        .iconSprite = gMonIcon_Tarenchula,
        .iconPalIndex = 2,
        FOOTPRINT(Tarenchula)
        OVERWORLD(
            sPicTable_Tarenchula,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Tarenchula,
            gShinyOverworldPalette_Tarenchula
        )
        .levelUpLearnset = sTarenchulaLevelUpLearnset,
        .teachableLearnset = sTarenchulaTeachableLearnset,
    },
#endif //P_FAMILY_MINARAC

#if P_FAMILY_CARBITE
    [SPECIES_CARBITE] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 30,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 105,
        .expYield = 53,
        .evYield_Defense    = 1,
	    .itemRare = ITEN_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_STURDY, ABILITY_NONE, ABILITY_ROCK_HEAD},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Carbite"),
        .cryId = CRY_CARBITE,
        .natDexNum = NATIONAL_DEX_CARBITE,
        .categoryName = _("Carbon"),
        .height = 9,
        .weight = 1406,
        .description = COMPOUND_STRING(
            "Carbite's bodies are immensely\n"
            "tough. They can typically be\n"
            "found teething on large rocks\n"
            "or people."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Carbite,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Carbite,
        .frontAnimId = ANIM_SWING_CONVEX,
        .backPic = gMonBackPic_Carbite,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Carbite,
        .shinyPalette = BACK_ANIM_CONCAVE_ARC_LARGE,
        .iconSprite = gMonIcon_Carbite,
        .iconPalIndex = 0,
        FOOTPRINT(Carbite)
        OVERWORLD(
            sPicTable_Carbite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Carbite,
            gShinyOverworldPalette_Carbite
        )
        .levelUpLearnset = sCarbiteLevelUpLearnset,
        .teachableLearnset = sCarbiteTeachableLearnset,
	.eggMoveLearnset = sCarbiteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_PRESSAUR}),
    },

    [SPECIES_PRESSAUR] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 120,
        .baseSpeed     = 20,
        .baseSpAttack  = 35,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 75,
        .expYield = 133,
        .evYield_Defense    = 2,
	.itemRare = ITEN_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_WELL_BAKED_BODY, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pressaur"),
        .cryId = CRY_PRESSAUR,
        .natDexNum = NATIONAL_DEX_PRESSAUR,
        .categoryName = _("Carbon"),
        .height = 14,
        .weight = 1905,
        .description = COMPOUND_STRING(
            "Pressaur has endured intense flames\n"
            "of 1400ºF to harden its body.\n"
            "Its shell can withstand 11\n"
            "tons of force."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pressaur,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pressaur,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Pressaur,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Pressaur,
        .shinyPalette = gMonShinyPalette_Pressaur,
        .iconSprite = gMonIcon_Pressaur,
        .iconPalIndex = 0,
        FOOTPRINT(Pressaur)
        OVERWORLD(
            sPicTable_Pressaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pressaur,
            gShinyOverworldPalette_Pressaur
        )
        .levelUpLearnset = sPressaurLevelUpLearnset,
        .teachableLearnset = sPressaurTeachableLearnset,
        .evolutions = EVOLUTION({EVO_MAPSEC, MAPSEC_MT_CHIMNEY, SPECIES_DIAMAW}),
    },

    [SPECIES_DIAMAW] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 150,
        .baseSpeed     = 80,
        .baseSpAttack  = 40,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 45,
        .expYield = 203,
        .evYield_Defense    = 3,
	    .itemRare = ITEN_ROCK_GEM,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_MONSTER),
        .abilities = {ABILITY_STURDY, ABILITY_NONE, ABILITY_ROCK_HEAD},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Diamaw"),
        .cryId = CRY_DIAMAW,
        .natDexNum = NATIONAL_DEX_DIAMAW,
        .categoryName = _("Diamond"),
        .height = 18,
        .weight = 3629,
        .description = COMPOUND_STRING(
            "Its body has endured the pressure\n"
            "and produced beautiful diamonds.\n"
            "One bite produces 4 tons of\n"
            "force on the victim."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Diamaw,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Diamaw,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Diamaw,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Diamaw,
        .shinyPalette = gMonShinyPalette_Diamaw,
        .iconSprite = gMonIcon_Diamaw,
        .iconPalIndex = 0,
        FOOTPRINT(Diamaw)
        OVERWORLD(
            sPicTable_Diamaw,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Diamaw,
            gShinyOverworldPalette_Diamaw
        )
        .levelUpLearnset = sDiamawLevelUpLearnset,
        .teachableLearnset = sDiamawTeachableLearnset,
    },
#endif //P_FAMILY_CARBITE

#if P_FAMILY_GILLA
    [SPECIES_GILLA] =
    {
        .baseHP        = 66,
        .baseAttack    = 81,
        .baseDefense   = 90,
        .baseSpeed     = 36,
        .baseSpAttack  = 22,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 64,
        .evYield_Defense    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_MOXIE, ABILITY_NONE, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gilla"),
        .cryId = CRY_GILLA,
        .natDexNum = NATIONAL_DEX_GILLA,
        .categoryName = _("Ankylo"),
        .height = 6,
        .weight = 427,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil.\n"
            "It is a curious Pokémon that\n"
            "puts anything in its mouth."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gilla,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Gilla,
        .frontAnimId = ANIM_H_PIVOT,
        .backPic = gMonBackPic_Gilla,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Gilla,
        .shinyPalette = gMonShinyPalette_Gilla,
        .iconSprite = gMonIcon_Gilla,
        .iconPalIndex = 2,
        FOOTPRINT(Gilla)
        OVERWORLD(
            sPicTable_Gilla,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Gilla,
            gShinyOverworldPalette_Gilla
        )
        .levelUpLearnset = sGillaLevelUpLearnset,
        .teachableLearnset = sGillaTeachableLearnset,
	.eggMoveLearnset = sGillaEggMoveLearnset
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ANODONTOR}),
},

    [SPECIES_ANODONTOR] =
    {
        .baseHP        = 86,
        .baseAttack    = 91,
        .baseDefense   = 100,
        .baseSpeed     = 56,
        .baseSpAttack  = 27,
        .baseSpDefense = 84,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Defense    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_MOXIE, ABILITY_NONE, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Anodontor"),
        .cryId = CRY_ANODONTOR,
        .natDexNum = NATIONAL_DEX_ANODONTOR,
        .categoryName = _("Ankylo"),
        .height = 10,
        .weight = 1023,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil.\n"
            "It will bite anything it\n"
            "can fit in its mouth."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Anodontor,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Anodontor,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Anodontor,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Anodontor,
        .shinyPalette = gMonShinyPalette_Anodontor,
        .iconSprite = gMonIcon_Anodontor,
        .iconPalIndex = 5,
        FOOTPRINT(Anodontor)
        OVERWORLD(
            sPicTable_Anodontor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Anodontor,
            gShinyOverworldPalette_Anodontor
        )
        .levelUpLearnset = sAnodontorLevelUpLearnset,
        .teachableLearnset = sAnodontorTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_ANKILLOSAUR}),
},

    [SPECIES_ANKILLOSAUR] =
    {
        .baseHP        = 106,
        .baseAttack    = 121,
        .baseDefense   = 125,
        .baseSpeed     = 44,
        .baseSpAttack  = 36,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 223,
        .evYield_Defense    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_MOXIE, ABILITY_NONE, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Ankillosaur"),
        .cryId = CRY_ANKILLOSAUR,
        .natDexNum = NATIONAL_DEX_ANKILLOSAUR,
        .categoryName = _("Ankylo"),
        .height = 14,
        .weight = 1610,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil.\n"
            "Ankillosaur's mighty tail\n"
            "can pierce through metal armor."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ankillosaur,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Ankillosaur,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Ankillosaur,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Ankillosaur,
        .shinyPalette = gMonShinyPalette_Ankillosaur,
        .iconSprite = gMonIcon_Ankillosaur,
        .iconPalIndex = 5,
        FOOTPRINT(Ankillosaur)
        OVERWORLD(
            sPicTable_Ankillosaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Ankillosaur,
            gShinyOverworldPalette_Ankillosaur
        )
        .levelUpLearnset = sAnkillosaurLevelUpLearnset,
        .teachableLearnset = sAnkillosaurTeachableLearnset,
},
#endif //P_FAMILY_GILLA

#if P_FAMILY_BAZILISK
    [SPECIES_BAZILISK] =
    {
        .baseHP        = 36,
        .baseAttack    = 81,
        .baseDefense   = 66,
        .baseSpeed     = 90,
        .baseSpAttack  = 22,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GRASS),
        .catchRate = 45,
        .expYield = 64,
        .evYield_Speed    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_TOXIC_BOOST, ABILITY_NONE, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bazilisk"),
        .cryId = CRY_BAZILISK,
        .natDexNum = NATIONAL_DEX_BAZILISK,
        .categoryName = _("Basil"),
        .height = 5,
        .weight = 368,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil. The herbs on\n"
            "Bazilisk's head are thought\n"
            "to have made it common prey."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bazilisk,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Bazilisk,
        .frontAnimId = ANIM_TIP_HOP_FORWARD,
        .backPic = gMonBackPic_Bazilisk,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Bazilisk,
        .shinyPalette = gMonShinyPalette_Bazilisk,
        .iconSprite = gMonIcon_Bazilisk,
        .iconPalIndex = 1,
        FOOTPRINT(Bazilisk)
        OVERWORLD(
            sPicTable_Bazilisk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Bazilisk,
            gShinyOverworldPalette_Bazilisk
        )
        .levelUpLearnset = sBaziliskLevelUpLearnset,
        .teachableLearnset = sBaziliskTeachableLearnset,
	.eggMoveLearnset = sBaziliskEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ORITHAUR}),
},

    [SPECIES_ORNITHAUR] =
    {
        .baseHP        = 56,
        .baseAttack    = 91,
        .baseDefense   = 86,
        .baseSpeed     = 100,
        .baseSpAttack  = 27,
        .baseSpDefense = 84,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GRASS),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_TOXIC_BOOST, ABILITY_NONE, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Ornithaur"),
        .cryId = CRY_ORNITHAUR,
        .natDexNum = NATIONAL_DEX_ORNITHAUR,
        .categoryName = _("Basil"),
        .height = 14,
        .weight = 648,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil. It has the\n"
            "ability to photosynthesize\n"
            "for food."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ornithaur,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Ornithaur,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Ornithaur,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Ornithaur,
        .shinyPalette = gMonShinyPalette_Ornithaur,
        .iconSprite = gMonIcon_Ornithaur,
        .iconPalIndex = 5,
        FOOTPRINT(Ornithaur)
        OVERWORLD(
            sPicTable_Ornithaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Ornithaur,
            gShinyOverworldPalette_Ornithaur
        )
        .levelUpLearnset = sOrnithaurLevelUpLearnset,
        .teachableLearnset = sOrnithaurTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_DILOPHLORA}),
},

    [SPECIES_DILOPHLORA] =
    {
        .baseHP        = 61,
        .baseAttack    = 117,
        .baseDefense   = 101,
        .baseSpeed     = 125,
        .baseSpAttack  = 30,
        .baseSpDefense = 84,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GRASS),
        .catchRate = 45,
        .expYield = 264,
        .evYield_Speed    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = {ABILITY_TOXIC_BOOST, ABILITY_NONE, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Dilophlora"),
        .cryId = CRY_DILOPHLORA,
        .natDexNum = NATIONAL_DEX_DILOPHLORA,
        .categoryName = _("Dilophsaurus"),
        .height = 18,
        .weight = 963,
        .description = COMPOUND_STRING(
            "An ancient Pokémon revived\n"
            "from a fossil. It uses the\n"
            "acid in its stomach to boost\n"
            "the power of its attacks."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dilophlora,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dilophlora,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Dilophlora,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Dilophlora,
        .shinyPalette = gMonShinyPalette_Dilophlora,
        .iconSprite = gMonIcon_Dilophlora,
        .iconPalIndex = 5,
        FOOTPRINT(Dilophlora)
        OVERWORLD(
            sPicTable_Dilophlora,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Dilophlora,
            gShinyOverworldPalette_Dilophlora
        )
        .levelUpLearnset = sDilophloraLevelUpLearnset,
        .teachableLearnset = sDilophloraTeachableLearnset,
#endif //P_FAMILY_BAZILISK

#if P_FAMILY_SQUIBBLE
    [SPECIES_SQUIBBLE] = //SQUID (BESIDES WATER/POISON MOVES ALSO HAS MOVES LIKE KNOCK OFF AND ASTONISH)
    {
        .baseHP        = 46,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 73,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_POISON, TYPE_WATER),
        .catchRate = 190,
        .expYield = 67,
        .evYield_Speed = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = {ABILITY_SUCTION_CUPS, ABILITY_LIQUID_OOZE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Squibble"),
        .cryId = CRY_SQUIBBLE,
        .natDexNum = NATIONAL_DEX_SQUIBBLE,
        .categoryName = _("Squid"),
        .height = 16,
        .weight = 600,
        .description = COMPOUND_STRING(
            "Squibble likes to use its ink\n"
            "to draw art in the ocean.\n"
            "Unfortunately, poaching\n"
            "threatens to drive it extinct."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squibble,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Squibble,
        .frontAnimId = ANIM_GLOW_BLACK,
        .backPic = gMonBackPic_Squibble,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Squibble,
        .shinyPalette = gMonShinyPalette_Squibble,
        .iconSprite = gMonIcon_Squibble,
        .iconPalIndex = 2,
        FOOTPRINT(Squibble)
        OVERWORLD(
            sPicTable_Squibble,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Squibble,
            gShinyOverworldPalette_Squibble
        )
        .levelUpLearnset = sSquibbleLevelUpLearnset,
        .teachableLearnset = sSquibbleTeachableLearnset,
	.eggMoveLearnset = sSquibbleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SQUINGO}),
    },

    [SPECIES_SQUINGO] = // EVOLVE AT LEVEL 34
    {
        .baseHP        = 86,
        .baseAttack    = 120,
        .baseDefense   = 60,
        .baseSpeed     = 113,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_POISON, TYPE_WATER),
        .catchRate = 110,
        .expYield = 134,
	.evYield_Attack = 1,
        .evYield_Speed = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = {ABILITY_SUCTION_CUPS, ABILITY_LIQUID_OOZE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Squingo"),
        .cryId = CRY_SQUINGO,
        .natDexNum = NATIONAL_DEX_SQUINGO,
        .categoryName = _("Squid"),
        .height = 37,
        .weight = 1107,
        .description = COMPOUND_STRING(
            "Squingo's ink is incredibly\n"
            "toxic to humans.\n"
            "They are hunted near cities\n"
            "to keep drinking water clean."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squingo,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Squingo,
        .frontAnimId = ANIM_GLOW_BLACK,
        .backPic = gMonBackPic_Squingo,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Squingo,
        .shinyPalette = gMonShinyPalette_Squingo,
        .iconSprite = gMonIcon_Squingo,
        .iconPalIndex = 2,
        FOOTPRINT(Squingo)
        OVERWORLD(
            sPicTable_Squingo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Squingo,
            gShinyOverworldPalette_Squingo
        )
        .levelUpLearnset = sSquingoLevelUpLearnset,
        .teachableLearnset = sSquingoTeachableLearnset,
    },
#endif //P_FAMILY_SQUIBBLE

#if P_FAMILY_DRAKNARR
    [SPECIES_DRAKNARR] =
    {
        .baseHP        = 60,
        .baseAttack    = 54,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 54,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 100,
        .expYield = 67,
        .evYield_Defense = 1,
        .itemRare = ITEM_ROCKY_HELMET,
        .genderRatio = MON_MALE,
        .eggCycles = 50,
        .friendship = 25,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = {ABILITY_WIND_RIDER, ABILITY_NONE, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Draknarr"),
        .cryId = CRY_DRAKNARR,
        .natDexNum = NATIONAL_DEX_DRAKNARR,
        .categoryName = _("Knarr"),
        .height = 100,
        .weight = 4900,
        .description = COMPOUND_STRING(
            "Draknarr resembles a boat\n"
            "that was ridden across a\n"
            "great ocean by the first\n"
            "settlers of Banjime."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Draknarr,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Draknarr,
        .frontAnimId = ANIM_H_SPRING_SLOW,
        .backPic = gMonBackPic_Draknarr,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Draknarr,
        .shinyPalette = gMonShinyPalette_Draknarr,
        .iconSprite = gMonIcon_Draknarr,
        .iconPalIndex = 3,
        FOOTPRINT(Draknarr)
        OVERWORLD(
            sPicTable_Draknarr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Draknarr,
            gShinyOverworldPalette_Draknarr
        )
        .levelUpLearnset = sDraknarrLevelUpLearnset,
        .teachableLearnset = sDraknarrTeachableLearnset,
	.eggMoveLearnset = sDraknarrEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 44, SPECIES_RAGNAROW}),
    },

    [SPECIES_RAGNAROW] =
    {
        .baseHP        = 90,
        .baseAttack    = 104,
        .baseDefense   = 110,
        .baseSpeed     = 91,
        .baseSpAttack  = 94,
        .baseSpDefense = 88,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 100,
        .expYield = 67,
        .evYield_Defense = 2,
        .itemRare = ITEM_ROCKY_HELMET,
        .genderRatio = MON_MALE,
        .eggCycles = 50,
        .friendship = 25,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = {ABILITY_WIND_RIDER, ABILITY_NONE, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ragnarow"),
        .cryId = CRY_DRAKNARR,
        .natDexNum = NATIONAL_DEX_DRAKNARR,
        .categoryName = _("Drakkar"),
        .height = 183,
        .weight = 9400,
        .description = COMPOUND_STRING(
            "Ragnarow is believed to\n"
            "have carried vikings into\n"
            "battle in ancient times. It\n"
            "symbolizes impending doom."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ragnarow,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Ragnarow,
        .frontAnimId = ANIM_H_REPEATED_SPRING_SLOW,
        .backPic = gMonBackPic_Ragnarow,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Ragnarow,
        .shinyPalette = gMonShinyPalette_Ragnarow,
        .iconSprite = gMonIcon_Ragnarow,
        .iconPalIndex = 3,
        FOOTPRINT(Ragnarow)
        OVERWORLD(
            sPicTable_Ragnarow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Ragnarow,
            gShinyOverworldPalette_Ragnarow
        )
        .levelUpLearnset = sRagnarowLevelUpLearnset,
        .teachableLearnset = sRagnarowTeachableLearnset,
    },
#endif //P_FAMILY_DRAKNARR

#if P_FAMILY_MANDALLOY
    [SPECIES_MANDALLOY] = //GODZILLA'S ENEMY MANDA THAT FUSED WITH A CARGO SHIP
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack    = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_MALE,
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_WATER_2),
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_WATER_BUBBLE},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Mandalloy"),
        .cryId = CRY_MANDALLOY,
        .natDexNum = NATIONAL_DEX_MANDALLOY,
        .categoryName = _("Kaiju"),
        .height = 400,
        .weight = 9999,
        .description = COMPOUND_STRING(
            "This massive Pokémon has merged\n"
            "its body with steel.\n"
            "It wraps its body around tanker\n"
            "ships and dranks underwater."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mandalloy,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Mandalloy,
        .frontAnimId = ANIM_LUNGE_GROW,
        .backPic = gMonBackPic_Mandalloy,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Mandalloy,
        .shinyPalette = gMonShinyPalette_Mandalloy,
        .iconSprite = gMonIcon_Mandalloy,
        .iconPalIndex = 2,
        FOOTPRINT(Mandalloy)
        OVERWORLD(
            sPicTable_Mandalloy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Mandalloy,
            gShinyOverworldPalette_Mandalloy
        )
        .levelUpLearnset = sMandalloyLevelUpLearnset,
        .teachableLearnset = sMandalloyTeachableLearnset,
	.eggMoveLearnset = sMandalloyEggMoveLearnset,
    },
#endif //P_FAMILY_MANDALLOY

#if P_FAMILY_PHLASK
    [SPECIES_PHLASK] = //POSSESSED CHEMICAL PHLASK
    {
        .baseHP        = 60,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 190,
        .expYield = 67,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_NEUTRALIZING_GAS, ABILITY_WEAK_ARMOR},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Phlask"),
        .cryId = CRY_PHLASK,
        .natDexNum = NATIONAL_DEX_PHLASK,
        .categoryName = _("Chemical"),
        .height = 4,
        .weight = 2,
        .description = COMPOUND_STRING(
            "Phlask cannot exist without\n"
            "the glass outer shell or the\n"
            "gas inside. This contradiction\n"
            "baffles Pokémon professors."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Phlask,
        .frontPicFemale = gMonFrontPic_PhlaskF,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Phlask,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Phlask,
        .backPicFemale = gMonBackPic_PhlaskF,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Phlask,
        .shinyPalette = gMonShinyPalette_Phlask,
        .iconSprite = gMonIcon_Phlask,
        .iconPalIndex = 2,
        FOOTPRINT(Phlask)
        OVERWORLD(
            sPicTable_Phlask,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Phlask,
            gShinyOverworldPalette_Phlask
        )
        .levelUpLearnset = sPhlaskLevelUpLearnset,
        .teachableLearnset = sPhlaskTeachableLearnset,
	.eggMoveLearnset = sPhlaskEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_NOXIGHAST}),
    },

    [SPECIES_NOXIGHAST] = // EVOLVE AT LEVEL 28
    {
        .baseHP        = 70,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 67,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 110,
        .expYield = 115,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_NEUTRALIZING_GAS, ABILITY_WEAK_ARMOR},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Noxighast"),
        .cryId = CRY_NOXIGHAST,
        .natDexNum = NATIONAL_DEX_NOXIGHAST,
        .categoryName = _("Chemical"),
        .height = 11,
        .weight = 11,
        .description = COMPOUND_STRING(
            "The chemicals in its body have\n"
            "been proven to be remarkably\n"
            "beneficial to humans with\n"
            "cold and flu symptoms."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_NoxighastMale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_NoxighastMale,
        .frontAnimId = ANIM_GROW_STUTTER_TWICE,
	.frontAnimDelay = 20,
        .backPic = gMonBackPic_NoxighastMale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_NoxighastMale,
        .shinyPalette = gMonShinyPalette_NoxighastMale,
        .iconSprite = gMonIcon_NoxighastMale,
        .iconPalIndex = 0,
        FOOTPRINT(Noxighast)
        OVERWORLD(
            sPicTable_NoxighastMale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_NoxighastMale,
            gShinyOverworldPalette_NoxighastMale
        )
        .levelUpLearnset = sNoxighastLevelUpLearnset,
        .teachableLearnset = sNoxighastTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_FUMIGHAST}),
    },

    [SPECIES_NOXIGHAST_FEMALE] = // EVOLVE AT LEVEL 28
    {
        .baseHP        = 70,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 67,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 110,
        .expYield = 115,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_NEUTRALIZING_GAS, ABILITY_WEAK_ARMOR},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Noxighast"),
        .cryId = CRY_NOXIGHAST,
        .natDexNum = NATIONAL_DEX_NOXIGHAST,
        .categoryName = _("Chemical"),
        .height = 11,
        .weight = 11,
        .description = COMPOUND_STRING(
            "The chemicals in its body have\n"
            "been proven to be remarkably\n"
            "beneficial to humans with\n"
            "cold and flu symptoms."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_NoxighastFemale,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Noxighast,
        .frontAnimId = ANIM_SHRINK_GROW_SLOW,
	.frontAnimDelay = 20,
        .backPic = gMonBackPic_NoxighastFemale,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_NoxighastFemale,
        .shinyPalette = gMonShinyPalette_NoxighastFemale,
        .iconSprite = gMonIcon_NoxighastFemale,
        .iconPalIndex = 0,
        FOOTPRINT(Noxighast)
        OVERWORLD(
            sPicTable_NoxighastFemale,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_NoxighastFemale,
            gShinyOverworldPalette_NoxighastFemale
        )
        .levelUpLearnset = sNoxighastLevelUpLearnset,
        .teachableLearnset = sNoxighastTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_FUMIGHAST}),
    },

    [SPECIES_FUMIGHAST] = // EVOLVE AT LEVEL 40
    {
        .baseHP        = 85,
        .baseAttack    = 45,
        .baseDefense   = 80,
        .baseSpeed     = 92,
        .baseSpAttack  = 120,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 195,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = {ABILITY_POISON_POINT, ABILITY_NEUTRALIZING_GAS, ABILITY_WEAK_ARMOR},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Fumighast"),
        .cryId = CRY_FUMIGHAST,
        .natDexNum = NATIONAL_DEX_FUMIGHAST,
        .categoryName = _("Chemical"),
        .height = 19,
        .weight = 333,
        .description = COMPOUND_STRING(
            "The fumes it releases gets\n"
            "humans and Pokémon alike\n"
            "extremely high. They eat\n"
            "toxic waste."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fumighast,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fumighast,
        .frontAnimId = ANIM_GROW_TWICE,
        .backPic = gMonBackPic_Fumighast,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Fumighast,
        .shinyPalette = gMonShinyPalette_Fumighast,
        .iconSprite = gMonIcon_Fumighast,
        .iconPalIndex = 4,
        FOOTPRINT(Fumighast)
        OVERWORLD(
            sPicTable_Fumighast,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Fumighast,
            gShinyOverworldPalette_Fumighast
        )
        .levelUpLearnset = sFumighastLevelUpLearnset,
        .teachableLearnset = sFumighastTeachableLearnset,
    },
#endif //P_FAMILY_PHLASK

#if P_FAMILY_PINECALF
    [SPECIES_PINECALF] = //PINE TREE ELEPHANT
    {
        .baseHP        = 50,
        .baseAttack    = 62,
        .baseDefense   = 53,
        .baseSpeed     = 30,
        .baseSpAttack  = 43,
        .baseSpDefense = 72,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 225,
        .expYield = 66,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = {ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_RAIN_DISH},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pinecalf"),
        .cryId = CRY_PINECALF,
        .natDexNum = NATIONAL_DEX_PINECALF,
        .categoryName = _("Pine Tree"),
        .height = 10,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Pinecalf's cones unleash its\n"
            "seeds only when they have been\n"
            "lit on fire. As such, they will\n"
            "seek out Fire-types for friends."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pinecalf,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Pinecalf,
        .frontAnimId = ANIM_H_DIP,
        .backPic = gMonBackPic_Pinecalf,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Pinecalf,
        .shinyPalette = gMonShinyPalette_Pinecalf,
        .iconSprite = gMonIcon_Pinecalf,
        .iconPalIndex = 5,
        FOOTPRINT(Pinecalf)
        OVERWORLD(
            sPicTable_Pinecalf,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pinecalf,
            gShinyOverworldPalette_Pinecalf
        )
        .levelUpLearnset = sPinecalfLevelUpLearnset,
        .teachableLearnset = sPinecalfTeachableLearnset,
	.eggMoveLearnset = sPinecalfEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_TRUNKONIFR}),
    },

    [SPECIES_TRUNKONIFR] = // EVOLVE AT LEVEL 35
    {
        .baseHP        = 94,
        .baseAttack    = 102,
        .baseDefense   = 83,
        .baseSpeed     = 40,
        .baseSpAttack  = 73,
        .baseSpDefense = 112,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 156,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = {ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_RAIN_DISH},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Trunkonifr"),
        .cryId = CRY_TRUNKONIFR,
        .natDexNum = NATIONAL_DEX_TRUNKONIFR,
        .categoryName = _("Pine Tree"),
        .height = 28,
        .weight = 6287,
        .description = COMPOUND_STRING(
            "They hide in the woods as a\n"
            "means of camouflage.\n"
            "Trunkonifr will pair with\n"
            "a mate for life."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Trunkonifr,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Trunkonifr,
        .frontAnimId = ANIM_H_DIP,
        .backPic = gMonBackPic_Trunkonifr,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Trunkonifr,
        .shinyPalette = gMonShinyPalette_Trunkonifr,
        .iconSprite = gMonIcon_Trunkonifr,
        .iconPalIndex = 5,
        FOOTPRINT(Trunkonifr)
        OVERWORLD(
            sPicTable_Trunkonifr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Trunkonifr,
            gShinyOverworldPalette_Trunkonifr
        )
        .levelUpLearnset = sTrunkonifrLevelUpLearnset,
        .teachableLearnset = sTrunkonifrTeachableLearnset,
    },
#endif //P_FAMILY_PINECALF

#if P_FAMILY_MASKREEP
    [SPECIES_MASKREEP] = //LITTLE TIKI GREMLIN WITH PRANKSTER. ABSOLUTE MENACE WITH THE SUPPORT MOVES.
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 125,
        .expYield = 50,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
        .abilities = {ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_SLANDER},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Maskreep"),
        .cryId = CRY_MASKREEP,
        .natDexNum = NATIONAL_DEX_MASKREEP,
        .categoryName = _("Tiki"),
        .height = 15,
        .weight = 462,
        .description = COMPOUND_STRING(
            "Legend has it Maskreep was a\n"
            "10 year old child who got lost\n"
            "in the woods and died. They are\n"
            "mischievous gremlins."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Maskreep,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Maskreep,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Maskreep,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Maskreep,
        .shinyPalette = gMonShinyPalette_Maskreep,
        .iconSprite = gMonIcon_Maskreep,
        .iconPalIndex = 5,
        FOOTPRINT(Maskreep)
        OVERWORLD(
            sPicTable_Maskreep,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Maskreep,
            gShinyOverworldPalette_Maskreep
        )
        .levelUpLearnset = sMaskreepLevelUpLearnset,
        .teachableLearnset = sMaskreepTeachableLearnset,
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_PARTING_SHOT, SPECIES_PHANTIKI}),
    },

    [SPECIES_PHANTIKI] = // EVOLVE AFTER LEARNING PARTING SHOT AT LEVEL 36
    {
        .baseHP        = 95,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 103,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 145,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
        .abilities = {ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_SLANDER},
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Phantiki"),
        .cryId = CRY_PHANTIKI,
        .natDexNum = NATIONAL_DEX_PHANTIKI,
        .categoryName = _("Tiki"),
        .height = 17,
        .weight = 771,
        .description = COMPOUND_STRING(
            "Phantiki plays pranks on people\n"
            "in the forest at night.\n"
            "Many people have lost their\n"
            "lives to these pranks."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Phantiki,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Phantiki,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Phantiki,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Phantiki,
        .shinyPalette = gMonShinyPalette_Phantiki,
        .iconSprite = gMonIcon_Phantiki,
        .iconPalIndex = 5,
        FOOTPRINT(Phantiki)
        OVERWORLD(
            sPicTable_Phantiki,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Phantiki,
            gShinyOverworldPalette_Phantiki
        )
        .levelUpLearnset = sPhantikiLevelUpLearnset,
        .teachableLearnset = sPhantikiTeachableLearnset,
    },
#endif //P_FAMILY_MASKREEP

#if P_FAMILY_TAOMARIN
    [SPECIES_TAOMARIN] =
    {
        .baseHP        = 70,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 74,
        .baseSpAttack  = 75,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = 100,
        .evYield_SpDefense    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_FILTER, ABILITY_NONE, ABILITY_TINTED_LENS},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Taomarin"),
        .cryId = CRY_TAOMARIN,
        .natDexNum = NATIONAL_DEX_TAOMARIN,
        .categoryName = _("Tamarin"),
        .height = 3,
        .weight = 6,
        .description = COMPOUND_STRING(
            "Taomarin is a peaceful Pokémon.\n"
            "It meditates every day as\n"
            "it walks the eight-fold path\n"
            "towards enlightenment."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Taomarin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Taomarin,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .backPic = gMonBackPic_Taomarin,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Taomarin,
        .shinyPalette = gMonShinyPalette_Taomarin,
        .iconSprite = gMonIcon_Taomarin,
        .iconPalIndex = 2,
        FOOTPRINT(Taomarin)
        OVERWORLD(
            sPicTable_Taomarin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Taomarin,
            gShinyOverworldPalette_Taomarin
        )
        .levelUpLearnset = sTaomarinLevelUpLearnset,
        .teachableLearnset = sTaomarinTeachableLearnset,
	.eggMoveLearnset = sTaomarinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 49, SPECIES_ORANGUTAO}),
    },

    [SPECIES_ORANGUTAO] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 75,
        .baseSpeed     = 75,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 200,
        .evYield_SpAttack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_FILTER, ABILITY_NONE, ABILITY_TINTED_LENS},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Orangutao"),
        .cryId = CRY_ORANGUTAO,
        .natDexNum = NATIONAL_DEX_ORANGUTAO,
        .categoryName = _("Orangutan"),
        .height = 13,
        .weight = 1300,
        .description = COMPOUND_STRING(
            "Orangutao has reached enlightenment\n"
            "and is now unbothered by the\n"
            "suffering it experiences in the\n"
            "world."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Orangutao,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Orangutao,
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        .backPic = gMonBackPic_Orangutao,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Orangutao,
        .shinyPalette = gMonShinyPalette_Orangutao,
        .iconSprite = gMonIcon_Orangutao,
        .iconPalIndex = 5,
        FOOTPRINT(Orangutao)
        OVERWORLD(
            sPicTable_Orangutao,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Orangutao,
            gShinyOverworldPalette_Oragnutao
        )
        .levelUpLearnset = sOrangutaoLevelUpLearnset,
        .teachableLearnset = sOrangutaoTeachableLearnset,
    },
#endif //P_FAMILY_TAOMARIN

#if P_FAMILY_COALT
    [SPECIES_COALT] =
    {
        .baseHP        = 58,
        .baseAttack    = 61,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 61,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 75,
        .expYield = 100,
        .evYield_Attack    = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_FLASH_FIRE, ABILITY_ROCK_HEAD, ABILITY_MOXIE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Coalt"),
        .cryId = CRY_COALT,
        .natDexNum = NATIONAL_DEX_COALT,
        .categoryName = _("Fire Goat"),
        .height = 7,
        .weight = 469,
        .description = COMPOUND_STRING(
            "Coalts are extremely aggressive\n"
            "Pokémon that love to fight.\n"
            "Their horns can heat up to 100\n"
            "degrees Fahrenheit."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Taomarin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Coalt,
        .frontAnimId = ANIM_JOLT_RIGHT_FAST,
        .backPic = gMonBackPic_Coalt,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Coalt,
        .shinyPalette = gMonShinyPalette_Coalt,
        .iconSprite = gMonIcon_Coalt,
        .iconPalIndex = 5,
        FOOTPRINT(Coalt)
        OVERWORLD(
            sPicTable_Coalt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Coalt,
            gShinyOverworldPalette_Coalt
        )
        .levelUpLearnset = sCoaltLevelUpLearnset,
        .teachableLearnset = sCoaltTeachableLearnset,
	.eggMoveLearnset = sCoaltEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 46, SPECIES_ARIESKORCH}),
    },

    [SPECIES_ARIESKORCH] =
    {
        .baseHP        = 88,
        .baseAttack    = 110,
        .baseDefense   = 86,
        .baseSpeed     = 90,
        .baseSpAttack  = 89,
        .baseSpDefense = 96,
        .types = MON_TYPES(TYPE_FIRE, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 240,
        .evYield_Attack      = 1,
        .evYield_SpAttack    = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = {ABILITY_FLASH_FIRE, ABILITY_ROCK_HEAD, ABILITY_MOXIE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Arieskorch"),
        .cryId = CRY_ARIESKORCH,
        .natDexNum = NATIONAL_DEX_ARIESKORCH,
        .categoryName = _("Ares"),
        .height = 19,
        .weight = 908,
        .description = COMPOUND_STRING(
            "Arieskorch will attack any\n"
            "living things in its sight.\n"
            "It is often trained and\n"
            "ridden into battle."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Arieskorch,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Arieskorch,
        .frontAnimId = ANIM_TIP_HOP_FORWARD,
	.frontAnimDelay = 10,
        .backPic = gMonBackPic_Ariskorch,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Arieskorch,
        .shinyPalette = gMonShinyPalette_Arieskorch,
        .iconSprite = gMonIcon_Arieskorch,
        .iconPalIndex = 0,
        FOOTPRINT(Ariskorch)
        OVERWORLD(
            sPicTable_Arieskorch,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Arieskorch,
            gShinyOverworldPalette_Arieskorch
        )
        .levelUpLearnset = sArieskorchLevelUpLearnset,
        .teachableLearnset = sArieskorchTeachableLearnset,
    },
#endif //P_FAMILY_COALT

#if P_FAMILY_BLUFFIN
    [SPECIES_BLUFFIN] =
    {
        .baseHP        = 50,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 175,
        .expYield = 67,
        .evYield_Speed    = 1,
	.itemRare = ITEN_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_1),
        .abilities = {ABILITY_WATER_VEIL, ABILITY_KLUTZ, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Bluffin"),
        .cryId = CRY_BLUFFIN,
        .natDexNum = NATIONAL_DEX_BLUFFIN,
        .categoryName = _("Puffin"),
        .height = 3,
        .weight = 4,
        .description = COMPOUND_STRING(
            "Bluffin prefer cold climates\n"
            "so that their semi-solid\n"
            "feathers do not melt.\n"
            "They love eating Magikarp."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bluffin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Bluffin,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Bluffin,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Bluffin,
        .shinyPalette = gMonShinyPalette_Bluffin,
        .iconSprite = gMonIcon_Bluffin,
        .iconPalIndex = 2,
        FOOTPRINT(Bluffin)
        OVERWORLD(
            sPicTable_Bluffin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Bluffin,
            gShinyOverworldPalette_Bluffin
        )
        .levelUpLearnset = sBluffinLevelUpLearnset,
        .teachableLearnset = sBluffinTeachableLearnset,
	.eggMoveLearnset = sBluffinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 57, SPECIES_SKARPIE}),
    },

    [SPECIES_SKARPIE] =
    {
        .baseHP        = 70,
        .baseAttack    = 102,
        .baseDefense   = 70,
        .baseSpeed     = 112,
        .baseSpAttack  = 104,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Speed    = 2,
	.itemRare = ITEN_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_1),
        .abilities = {ABILITY_WATER_VEIL, ABILITY_SERENE_GRACE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Skarpie"),
        .cryId = CRY_SKARPIE,
        .natDexNum = NATIONAL_DEX_SKARPIE,
        .categoryName = _("Harpy"),
        .height = 10,
        .weight = 59,
        .description = COMPOUND_STRING(
            "Skarpie's semi-solid feathers\n"
            "are extremely sharp when frozen.\n"
            "They can slice through a car\n"
            "door."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skarpie,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Skarpie,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .backPic = gMonBackPic_Skarpie,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Skarpie,
        .shinyPalette = gMonShinyPalette_Skarpie,
        .iconSprite = gMonIcon_Skarpie,
        .iconPalIndex = 2,
        FOOTPRINT(Skarpie)
        OVERWORLD(
            sPicTable_Skarpie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Skarpie,
            gShinyOverworldPalette_Skarpie
        )
        .levelUpLearnset = sSkarpieLevelUpLearnset,
        .teachableLearnset = sSkarpieTeachableLearnset,
    },
#endif //P_FAMILY_BLUFFIN

#if P_FAMILY_GNOWM
    [SPECIES_GNOWM] = //ICE GNOME. SHOULD HAVE SOME GOOD SUPPORT MOVES+DAMAGE OPTIONS.
    {
        .baseHP        = 78,
        .baseAttack    = 20,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_ICE),
        .catchRate = 70,
        .expYield = 77,
        .evYield_HP    = 1,
	.itemCommon = ITEM_ADRENALINE_ORB,
	.itemRare = ITEM_ADRENALINE_ORB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = 50,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_FIELD),
        .abilities = {ABILITY_FRIEND_GUARD, ABILITY_SNOW_CLOAK, ABILITY_POWER_OF_ALCHEMY},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gnowm"),
        .cryId = CRY_GNOWM,
        .natDexNum = NATIONAL_DEX_GNOWM,
        .categoryName = _("Gnome"),
        .height = 3,
        .weight = 363,
        .description = COMPOUND_STRING(
            "These mystical Pokémon live in\n"
            "tree trunks and snow banks.\n"
            "They bake delicious chocolate\n"
            "chip cookies."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gnowm,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Gnowm,
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,
        .backPic = gMonBackPic_Gnowm,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        .palette = gMonPalette_Gnowm,
        .shinyPalette = gMonShinyPalette_Gnowm,
        .iconSprite = gMonIcon_Gnowm,
        .iconPalIndex = 0,
        FOOTPRINT(Gnowm)
        OVERWORLD(
            sPicTable_Gnowm,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Gnowm,
            gShinyOverworldPalette_Gnowm
        )
        .levelUpLearnset = sGnowmLevelUpLearnset,
        .teachableLearnset = sGnowmTeachableLearnset,
	.eggMoveLearnset = sGnowmEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_SNOWGRE}),
},

    [SPECIES_SNOWGRE] = // EVOLVE AT LEVEL 40
    {
        .baseHP        = 140,
        .baseAttack    = 30,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 115,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_ICE),
        .catchRate = 45,
        .expYield = 202,
        .evYield_HP    = 2,
	.itemCommon = ITEM_ADRENALINE_ORB,
	.itemRare = ITEM_ADRENALINE_ORB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = 50,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_FIELD),
        .abilities = {ABILITY_FRIEND_GUARD, ABILITY_SNOW_CLOAK, ABILITY_POWER_OF_ALCHEMY},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Snowgre"),
        .cryId = CRY_SNOWGRE,
        .natDexNum = NATIONAL_DEX_SNOWGRE,
        .categoryName = _("Gnome"),
        .height = 15,
        .weight = 999,
        .description = COMPOUND_STRING(
            "Snowgre are extremely hospitable\n"
            "creatures. They welcome weary\n"
            "travelers into their homes with\n"
            "a hearty yodel."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snowgre,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Snowgre,
        .frontAnimId = ANIM_GROW,
        .backPic = gMonBackPic_Snowgre,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Snowgre,
        .shinyPalette = gMonShinyPalette_Snowgre,
        .iconSprite = gMonIcon_Snowgre,
        .iconPalIndex = 0,
        FOOTPRINT(Snowgre)
        OVERWORLD(
            sPicTable_Snowgre,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Snowgre,
            gShinyOverworldPalette_Snowgre
        )
        .levelUpLearnset = sSnowgreLevelUpLearnset,
        .teachableLearnset = sSnowgreTeachableLearnset,
    },
#endif //P_FAMILY_GNOWM

#if P_FAMILY_BOAREALIS
    [SPECIES_BOAREALIS] =
    {
        .baseHP        = 91,
        .baseAttack    = 70,
        .baseDefense   = 85,
        .baseSpeed     = 94,
        .baseSpAttack  = 104,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 213,
        .evYield_SpAttack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_NONE, ABILITY_SLUSH_RUSH},
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Boarealis"),
        .cryId = CRY_BOAREALIS,
        .natDexNum = NATIONAL_DEX_BOAREALIS,
        .categoryName = _("Boarealis"),
        .height = 17,
        .weight = 1703,
        .description = COMPOUND_STRING(
            "A Pokémon that rushes across\n"
            "the night sky during the winter.\n"
            "Seeing one is believed to be a\n"
            "sign of good luck."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Boarealis,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Boarealis,
        .frontAnimId = ANIM_SHAKE_GLOW_GREEN_FAST,
        .backPic = gMonBackPic_Boarealis,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_Boarealis,
        .shinyPalette = gMonShinyPalette_Boarealis,
        .iconSprite = gMonIcon_Boarealis,
        .iconPalIndex = 4,
        FOOTPRINT(Boarealis)
        OVERWORLD(
            sPicTable_Boarealis,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Boarealis,
            gShinyOverworldPalette_Boarealis
        )
        .levelUpLearnset = sBoarealisLevelUpLearnset,
        .teachableLearnset = sBoarealisTeachableLearnset,
	.eggMoveLearnset = sBoarealisEggMoveLearnset,
    },
#endif //P_FAMILY_BOAREALIS

#if P_FAMILY_WISHP
    [SPECIES_WISHP] = //WISP THAT EVOLVES INTO A DJINN. PSEUDO LEGEND (SHOULD BE GOOD).
    {
        .baseHP        = 55,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = 60,
        .evYield_Speed   = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_MAGIC_GUARD, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Wishp"),
        .cryId = CRY_WISHP,
        .natDexNum = NATIONAL_DEX_WISHP,
        .categoryName = _("Wisp"),
        .height = 2,
        .weight = 5,
        .description = COMPOUND_STRING(
            "Wishps are only ever seen when\n"
            "a person is about to have a\n"
            "fateful encounter. People with\n"
            "anxiety disorders fear them."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wishp,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Wishp,
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Wishp,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Wishp,
        .shinyPalette = gMonShinyPalette_Wishp,
        .iconSprite = gMonIcon_Wishp,
        .iconPalIndex = 0,
        FOOTPRINT(Wishp)
        OVERWORLD(
            sPicTable_Wishp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Wishp,
            gShinyOverworldPalette_Wishp
        )
        .levelUpLearnset = sWishpLevelUpLearnset,
        .teachableLearnset = sWishpTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_IGFRIT}),
    },

    [SPECIES_IGFRIT] = // EVOLVE AT LEVEL 30
    {
        .baseHP        = 84,
        .baseAttack    = 43,
        .baseDefense   = 60,
        .baseSpeed     = 88,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = 147,
        .evYield_Speed   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_MAGIC_GUARD, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Igfrit"),
        .cryId = CRY_IGFRIT,
        .natDexNum = NATIONAL_DEX_IGFRIT,
        .categoryName = _("Djinn"),
        .height = 13,
        .weight = 30,
        .description = COMPOUND_STRING(
            "Igfrit is bound to a lamp.\n"
            "Legend has it that it will grant\n"
            "three wishes to one who frees it.\n"
            "The legends are wrong."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Igfrit,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Igfrit,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_FAST,
        .backPic = gMonBackPic_Igfrit,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Igfrit,
        .shinyPalette = gMonShinyPalette_Igfrit,
        .iconSprite = gMonIcon_Igfrit,
        .iconPalIndex = 0,
        FOOTPRINT(Igfrit)
        OVERWORLD(
            sPicTable_Igfrit,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Igfrit,
            gShinyOverworldPalette_Igfrit
        )
        .levelUpLearnset = sIgfritLevelUpLearnset,
        .teachableLearnset = sIgfritTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_DJINNFERNO}),
    },

    [SPECIES_DJINNFERNO] = // EVOLVE AT LEVEL 50
    {
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 98,
        .baseSpeed     = 97,
        .baseSpAttack  = 126,
        .baseSpDefense = 116,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack   = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_FAIRY),
        .abilities = {ABILITY_MAGIC_GUARD, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE},
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Djinnferno"),
        .cryId = CRY_DJINNFERNO,
        .natDexNum = NATIONAL_DEX_DJINNFERNO,
        .categoryName = _("Djinn"),
        .height = 24,
        .weight = 696,
        .description = COMPOUND_STRING(
            "Djinnferno's magic body is made\n"
            "of smoke and fire. It can grant\n"
            "any wish, but beware, for\n"
            "it always twists your words."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Djinnferno,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Djinnferno,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_FAST,
        .backPic = gMonBackPic_Djinnferno,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Djinnferno,
        .shinyPalette = gMonShinyPalette_Djinnferno,
        .iconSprite = gMonIcon_Djinnferno,
        .iconPalIndex = 0,
        FOOTPRINT(Djinnferno)
        OVERWORLD(
            sPicTable_Djinnferno,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Djinnferno,
            gShinyOverworldPalette_Djinnferno
        )
        .levelUpLearnset = sDjinnfernoLevelUpLearnset,
        .teachableLearnset = sDjinnfernoTeachableLearnset,
    },
#endif //P_FAMILY_WISHP

#if P_FAMILY_MOONIGHT
    [SPECIES_MOONIGHT] = //CRUSADER
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 20,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DARK),
        .catchRate = 3,
        .expYield = 60,
        .evYield_Defense   = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_SHARPNESS, ABILITY_STAMINA},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Moonight"),
        .cryId = CRY_MOONIGHT,
        .natDexNum = NATIONAL_DEX_MOONIGHT,
        .categoryName = _("Crusader"),
        .height = 16,
        .weight = 600,
        .description = COMPOUND_STRING(
            "Moonight is trained in blade arts\n"
            "from the moment it hatches.\n"
            "It aligns its sense of honor\n"
            "to the Order of the Moose."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Moonight,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Moonight,
        .frontAnimId = ANIM_H_DIP_FAST,
        .backPic = gMonBackPic_Moonight,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Moonight,
        .shinyPalette = gMonShinyPalette_Moonight,
        .iconSprite = gMonIcon_Moonight,
        .iconPalIndex = 0,
        FOOTPRINT(Moonight)
        OVERWORLD(
            sPicTable_Moonight,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Moonight,
            gShinyOverworldPalette_Moonight
        )
        .levelUpLearnset = sMoonightLevelUpLearnset,
        .teachableLearnset = sMoonightTeachableLearnset,
	.eggMoveLearnset = sMoonightEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_JOUSTOCK}),
    },

    [SPECIES_JOUSTOCK] = // EVOLVE AT LEVEL 30
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DARK),
        .catchRate = 3,
        .expYield = 147,
        .evYield_Defense   = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_SHARPNESS, ABILITY_STAMINA},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Joustock"),
        .cryId = CRY_JOUSTOCK,
        .natDexNum = NATIONAL_DEX_JOUSTOCK,
        .categoryName = _("Crusader"),
        .height = 18,
        .weight = 850,
        .description = COMPOUND_STRING(
            "The executioner for the Order\n"
            "of the Moose, Joustock is\n"
            "ruthless in its combat tactics\n"
            "and friendships."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Joustock,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Joustock,
        .frontAnimId = ANIM_GROW_STUTTER,
        .backPic = gMonBackPic_Joustock,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Joustock,
        .shinyPalette = gMonShinyPalette_Joustock,
        .iconSprite = gMonIcon_Joustock,
        .iconPalIndex = 0,
        FOOTPRINT(Joustock)
        OVERWORLD(
            sPicTable_Joustock,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Joustock,
            gShinyOverworldPalette_Joustock
        )
        .levelUpLearnset = sJoustockLevelUpLearnset,
        .teachableLearnset = sJoustockTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_CRUSABER}),
    },

    [SPECIES_CRUSABER] = // EVOLVE AT LEVEL 50
    {
        .baseHP        = 80,
        .baseAttack    = 140,
        .baseDefense   = 125,
        .baseSpeed     = 102,
        .baseSpAttack  = 58,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DARK),
        .catchRate = 3,
        .expYield = 270,
        .evYield_Defense   = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = {ABILITY_JUSTIFIED, ABILITY_SHARPNESS, ABILITY_STAMINA},
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Crusaber"),
        .cryId = CRY_CRUSABER,
        .natDexNum = NATIONAL_DEX_CRUSABER,
        .categoryName = _("Crusader"),
        .height = 20,
        .weight = 1361,
        .description = COMPOUND_STRING(
            "The strongest warrior in the Order\n"
            "of the Moose. Crusaber attacks any\n"
            "who dare to deny the divinity of\n"
            "the moose god Ai Dan."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Crusaber,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Crusaber,
        .frontAnimId = ANIM_GROW_TWICE,
        .backPic = gMonBackPic_Crusaber,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Crusaber,
        .shinyPalette = gMonShinyPalette_Crusaber,
        .iconSprite = gMonIcon_Crusaber,
        .iconPalIndex = 0,
        FOOTPRINT(Crusaber)
        OVERWORLD(
            sPicTable_Crusaber,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Crusaber,
            gShinyOverworldPalette_Crusaber
        )
        .levelUpLearnset = sCrusaberLevelUpLearnset,
        .teachableLearnset = sCrusaberTeachableLearnset,
    },
#endif //P_FAMILY_MOONIGHT

#if P_FAMILY_CHELONITE
    [SPECIES_CHELONITE] = //ASTEROID BELT TURTLE
    {
        .baseHP        = 60,
        .baseAttack    = 48,
        .baseDefense   = 54,
        .baseSpeed     = 56,
        .baseSpAttack  = 62,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_ROCK),
        .catchRate = 45,
        .expYield = 72,
        .evYield_SpAttack    = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_MINERAL),
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Chelonite"),
        .cryId = CRY_CHELONITE,
        .natDexNum = NATIONAL_DEX_CHELONITE,
        .categoryName = _("Asteroid"),
        .height = 12,
        .weight = 1973,
        .description = COMPOUND_STRING(
            "Chelonite uses its psychic power\n"
            "to create a gravitational field\n"
            "around its body. The rocks it\n"
            "picks up look like asteroids."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chelonite,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chelonite,
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Chelonite,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Chelonite,
        .shinyPalette = gMonShinyPalette_Chelonite,
        .iconSprite = gMonIcon_Chelonite,
        .iconPalIndex = 4,
        FOOTPRINT(Chelonite)
        OVERWORLD(
            sPicTable_Chelonite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Chelonite,
            gShinyOverworldPalette_Chelonite
        )
        .levelUpLearnset = sCheloniteLevelUpLearnset,
        .teachableLearnset = sCheloniteTeachableLearnset,
	.eggMoveLearnset = sCheloniteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_GALAXAGOS}),
    },

    [SPECIES_GALAXAGOS] = // EVOLVE AT LEVEL 48
    {
        .baseHP        = 95,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 135,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_ROCK),
        .catchRate = 15,
        .expYield = 248,
        .evYield_SpAttack  = 3,
        .itemCommon = ITEM_HARD_STONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_MINERAL),
        .abilities = {ABILITY_ASTEROID_BELT, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Galaxagos"),
        .cryId = CRY_GALAXAGOS,
        .natDexNum = NATIONAL_DEX_GALAXAGOS,
        .categoryName = _("Asteroid"),
        .height = 18,
        .weight = 2600,
        .description = COMPOUND_STRING(
            "Galaxagos uses the rocks it pulls\n"
            "in to protect itself from predators.\n"
            "Should that fail, however, its shell\n"
            "can withstand 6 tons of force."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Galaxagos,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Galaxagos,
        .frontAnimId = ANIM_H_SLIDE_FAST,
        .backPic = gMonBackPic_Galaxagos,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Galaxagos,
        .shinyPalette = gMonShinyPalette_Galaxagos,
        .iconSprite = gMonIcon_Galaxagos,
        .iconPalIndex = 0,
        FOOTPRINT(Galaxagos)
        OVERWORLD(
            sPicTable_Galaxagos,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Galaxagos,
            gShinyOverworldPalette_Galaxagos
        )
        .levelUpLearnset = sGalaxagosLevelUpLearnset,
        .teachableLearnset = sGalaxagosTeachableLearnset,
    },
#endif //P_FAMILY_CHELONITE

#if P_FAMILY_TANUKOON
    [SPECIES_TANUKOON] =
    {
        .baseHP        = 63,
        .baseAttack    = 48,
        .baseDefense   = 56,
        .baseSpeed     = 78,
        .baseSpAttack  = 76,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 165,
        .expYield = 123,
        .evYield_SpAttack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_FIELD),
        .abilities = {ABILITY_MAGIC_BOUNCE, ABILITY_FOREWARN, ABILITY_HOSPITALITY},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tanukoon"),
        .cryId = CRY_TANUKOON,
        .natDexNum = NATIONAL_DEX_TANUKOON,
        .categoryName = _("Tanukoon"),
        .height = 6,
        .weight = 290,
        .description = COMPOUND_STRING(
            "Tanukoon will approach people\n"
            "and Pokémon alike, seeking to play\n"
            "various games. However, they\n"
            "hate to be captured."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tanukoon,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Tanukoon,
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Tanukoon,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Tanukoon,
        .shinyPalette = gMonShinyPalette_Tanukoon,
        .iconSprite = gMonIcon_Tanukoon,
        .iconPalIndex = 3,
        FOOTPRINT(Tanukoon)
        OVERWORLD(
            sPicTable_Tanukoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Tanukoon,
            gShinyOverworldPalette_Tanukoon
        )
        .levelUpLearnset = sTanukoonLevelUpLearnset,
        .teachableLearnset = sTanukoonTeachableLearnset,
	.eggMoveLearnset = sTanukoonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_NIGHT, 0, SPECIES_LEUKOON}),
    },

    [SPECIES_LEUKOON] =
    {
        .baseHP        = 93,
        .baseAttack    = 48,
        .baseDefense   = 96,
        .baseSpeed     = 98,
        .baseSpAttack  = 126,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 243,
        .evYield_SpAttack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_FIELD),
        .abilities = {ABILITY_MAGIC_BOUNCE, ABILITY_PRESSURE, ABILITY_HOSPITALITY},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Leukoon"),
        .cryId = CRY_LEUKOON,
        .natDexNum = NATIONAL_DEX_LEUKOON,
        .categoryName = _("Leukoon"),
        .height = 15,
        .weight = 2290,
        .description = COMPOUND_STRING(
            "Leukoon's mouth functions\n"
            "like a black hole. It likes to\n"
            "eat wandering spirits, which has\n"
            "made them into popular pets."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Leukoon,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Leukoon,
        .frontAnimId = ANIM_GROW_TWICE,
	.frontAnimDelay = 5,
        .backPic = gMonBackPic_Leukoon,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Leukoon,
        .shinyPalette = gMonShinyPalette_Leukoon,
        .iconSprite = gMonIcon_Leukoon,
        .iconPalIndex = 0,
        FOOTPRINT(Leukoon)
        OVERWORLD(
            sPicTable_Leukoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Leukoon,
            gShinyOverworldPalette_Leukoon
        )
        .levelUpLearnset = sLeukoonLevelUpLearnset,
        .teachableLearnset = sLeukoonTeachableLearnset,
    },
#endif //P_FAMILY_TANUKOON

#if P_FAMILY_HATHROSTUS
    [SPECIES_HATHROSTUS] = //BAT LEGENDARY BASED OFF OF HATHOR (SIGN. MOVE FIELD OF REEDS)
    {
        .baseHP        = 112,
        .baseAttack    = 73,
        .baseDefense   = 75,
        .baseSpeed     = 116,
        .baseSpAttack  = 124,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_GHOST),
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack   = 3,
        .itemCommon = ITEM_SUN_STONE,
        .itemRare = ITEM_SUN_STONE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = {ABILITY_MUMMY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .isLegendary = TRUE,
	.allPerfectIVs = TRUE,
        .speciesName = _("Hathrostus"),
        .cryId = CRY_HATHROSTUS,
        .natDexNum = NATIONAL_DEX_HATHROSTUS,
        .categoryName = _("Hathor"),
        .height = 31,
        .weight = 2223,
        .description = COMPOUND_STRING(
            "It is said thatHathrostus aligns\n"
            "the cosmos and places the stars.\n"
            "Hathrostus also guides the\n"
            "rebirth process of the afterlife."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hathrostus,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Hathrostus,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
	.frontAnimDelay = 10,
        .backPic = gMonBackPic_Hathrostus,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Hathrostus,
        .shinyPalette = gMonShinyPalette_Hathrostus,
        .iconSprite = gMonIcon_Hathrostus,
        .iconPalIndex = 1,
        FOOTPRINT(Hathrostus)
        OVERWORLD(
            sPicTable_Hathrostus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Hathrostus,
            gShinyOverworldPalette_Hathrostus
        )
        .levelUpLearnset = sHathrostusLevelUpLearnset,
        .teachableLearnset = sHathrostusTeachableLearnset,
    },
#endif //P_FAMILY_HATHROSTUS

#if P_FAMILY_BABOSIRIS
    [SPECIES_BABOSIRIS] = //BIG BABOON LEGENDARY BASED OFF OF OSIRIS (SIGN. MOVE FIELD OF REEDS+SHOULD GET A DECENT AMOUNT OF FIGHTING MOVES AS WELL)
    {
        .baseHP        = 116,
        .baseAttack    = 124,
        .baseDefense   = 80,
        .baseSpeed     = 112,
        .baseSpAttack  = 73,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 3,
        .itemCommon = ITEM_MOON_STONE,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = {ABILITY_MUMMY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
	.allPerfectIVs = TRUE,
        .speciesName = _("Babosiris"),
        .cryId = CRY_BABOSIRIS,
        .natDexNum = NATIONAL_DEX_BABOSIRIS,
        .categoryName = _("Osiris"),
        .height = 31,
        .weight = 2223,
        .description = COMPOUND_STRING(
            "Babosiris is the embodiment of\n"
            "those who have passed. As such,\n"
            "it also possesses the wisdom of\n"
            "all previous generations."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Babosiris,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Babosiris,
        .frontAnimId = ANIM_LUNGE_GROW,
        .backPic = gMonBackPic_Babosiris,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Babosiris,
        .shinyPalette = gMonShinyPalette_Babosiris,
        .iconSprite = gMonIcon_Babosiris,
        .iconPalIndex = 0,
        FOOTPRINT(Babosiris)
        OVERWORLD(
            sPicTable_Babosiris,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Babosiris,
            gShinyOverworldPalette_Babosiris
        )
        .levelUpLearnset = sBabosirisLevelUpLearnset,
        .teachableLearnset = sBabosirisTeachableLearnset,
    },
#endif //P_FAMILY_BABOSIRIS

#if P_FAMILY_HUBRISET
    [SPECIES_HUBRISET] = //GLYPH LEGENDARY BASED OFF OF SETH (SIGN. MOVE FIELD OF REEDS+SHOULD HAVE FLYING MOVES AS WELL)
    {
        .baseHP        = 100,
        .baseAttack    = 108,
        .baseDefense   = 80,
        .baseSpeed     = 124,
        .baseSpAttack  = 108,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GHOST),
        .catchRate = 3,
        .expYield = 261,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
	.allPerfectIVs = TRUE,
        .speciesName = _("Hubriset"),
        .cryId = CRY_HUBRISET,
        .natDexNum = NATIONAL_DEX_HUBRISET,
        .categoryName = _("Seth"),
        .height = 37,
        .weight = 2828,
        .description = COMPOUND_STRING(
            "The patron god-king of the dead.\n"
            "Hubriset is an ambitious legendary\n"
            "who sent its sibling, Babosiris,\n"
            "into the afterlife to depose him."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hubriset,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Hubriset,
        .frontAnimId = ANIM_GROW,
        .backPic = gMonBackPic_Hubriset,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Hubriset,
        .shinyPalette = gMonShinyPalette_Hubriset,
        .iconSprite = gMonIcon_Hubriset,
        .iconPalIndex = 3,
        FOOTPRINT(Hubriset)
        OVERWORLD(
            sPicTable_Hubriset,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Hubriset,
            gShinyOverworldPalette_Hubriset
        )
        .levelUpLearnset = sHubrisetLevelUpLearnset,
        .teachableLearnset = sHubrisetTeachableLearnset,
    },
#endif //P_FAMILY_HUBRISET

#if P_FAMILY_WENDINGO
    [SPECIES_WENDINGO] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 3,
        .expYield = 245,
        .evYield_HP    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 100,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGG_GROUPS_DISCOVERED),
        .abilities = {ABILITY_VAMPIRISM, ABILITY_NONE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Wendingo"),
        .cryId = CRY_WENDINGO,
        .natDexNum = NATIONAL_DEX_WENDINGO,
        .categoryName = _("Wendigo"),
        .height = 30,
        .weight = 628,
        .description = COMPOUND_STRING(
            "A newly discovered Pokémon.\n"
            "It appears to be a mutant form\n"
            "of Mooseferatu that appeared\n"
            "after one became cannibalistic."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wendingo,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Wendingo,
        .frontAnimId = ANIM_H_DIP_FAST,
        .backPic = gMonBackPic_Wendingo,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Wendingo,
        .shinyPalette = gMonShinyPalette_Wendingo,
        .iconSprite = gMonIcon_Wendingo,
        .iconPalIndex = 0,
        FOOTPRINT(Wendingo)
        OVERWORLD(
            sPicTable_Wendingo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Wendingo,
            gShinyOverworldPalette_Wendingo
        )
        .levelUpLearnset = sWendingoLevelUpLearnset,
        .teachableLearnset = sWendingoTeachableLearnset,
   },
#endif //P_FAMILY_WENDINGO
};
