#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/battle_anim.h"
#include "constants/battle_partner.h"

// .rodata

static const struct OamData sVsLetter_V_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sVsLetter_S_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 64,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds0[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sVsLetterAffineAnimTable[] =
{
    sVsLetterAffineAnimCmds0,
    sVsLetterAffineAnimCmds1,
};

#define TAG_VS_LETTERS 10000

static const struct SpriteTemplate sVsLetter_V_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_V_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct SpriteTemplate sVsLetter_S_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_S_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct CompressedSpriteSheet sVsLettersSpriteSheet =
{
    gVsLettersGfx, 0x1000, TAG_VS_LETTERS
};

const struct BgTemplate gBattleBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sStandardBattleWindowTemplates[] =
{
    [B_WIN_MSG] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x0090,
    },
    [B_WIN_ACTION_PROMPT] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 35,
        .width = 14,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x01c0,
    },
    [B_WIN_ACTION_MENU] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 35,
        .width = 12,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0190,
    },
    [B_WIN_MOVE_NAME_1] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 55,
        .width = 16,    //for z move names
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0300,
    },
    [B_WIN_MOVE_NAME_2] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 55,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0318,
    },
    [B_WIN_MOVE_NAME_3] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 57,
        .width = 16,    //for z effect descriptions
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0328,
    },
    [B_WIN_MOVE_NAME_4] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0340,
    },
    [B_WIN_PP] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 4,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0290,
    },
    [B_WIN_DUMMY] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 57,
        .width = 0,
        .height = 0,
        .paletteNum = 5,
        .baseBlock = 0x0298,
    },
    [B_WIN_PP_REMAINING] = {
        .bg = 0,
        .tilemapLeft = 25,
        .tilemapTop = 55,
        .width = 4,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0298,
    },
    [B_WIN_MOVE_TYPE] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x02a0,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 8,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x02b0,
    },
    [B_WIN_YESNO] = {
        .bg = 0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 8,
        .width = 10,
        .height = 11,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x016e,
    },
    [B_WIN_VS_PLAYER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_OPPONENT] = {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0060,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0080,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00b0,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 47,
        .width = 18,
        .height = 6,
        .paletteNum = 5,
        .baseBlock = 0x0350,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sBattleArenaWindowTemplates[] =
{
    [B_WIN_MSG] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x0090,
    },
    [B_WIN_ACTION_PROMPT] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 35,
        .width = 14,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x01c0,
    },
    [B_WIN_ACTION_MENU] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 35,
        .width = 12,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0190,
    },
    [B_WIN_MOVE_NAME_1] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 55,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0300,
    },
    [B_WIN_MOVE_NAME_2] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 55,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0310,
    },
    [B_WIN_MOVE_NAME_3] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0320,
    },
    [B_WIN_MOVE_NAME_4] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0330,
    },
    [B_WIN_PP] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 4,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0290,
    },
    [B_WIN_DUMMY] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 57,
        .width = 0,
        .height = 0,
        .paletteNum = 5,
        .baseBlock = 0x0298,
    },
    [B_WIN_PP_REMAINING] = {
        .bg = 0,
        .tilemapLeft = 25,
        .tilemapTop = 55,
        .width = 4,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0298,
    },
    [B_WIN_MOVE_TYPE] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x02a0,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 8,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x02b0,
    },
    [B_WIN_YESNO] = {
        .bg = 0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 8,
        .width = 10,
        .height = 11,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x016e,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [ARENA_WIN_VS] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 1,
        .width = 2,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0110,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0114,
    },
    [ARENA_WIN_MIND] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 4,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0124,
    },
    [ARENA_WIN_SKILL] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0130,
    },
    [ARENA_WIN_BODY] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 8,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x013c,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 11,
        .width = 14,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0148,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 7,
        .baseBlock = 0x0090,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 47,
        .width = 18,
        .height = 6,
        .paletteNum = 5,
        .baseBlock = 0x0350,
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate *const gBattleWindowTemplates[] =
{
    [B_WIN_TYPE_NORMAL] = sStandardBattleWindowTemplates,
    [B_WIN_TYPE_ARENA]  = sBattleArenaWindowTemplates,
};

const struct BattleBackground sBattleEnvironmentTable[] =
{
    [BATTLE_ENVIRONMENT_ARENA] =
    {
        .tileset = gBattleEnvironmentTiles_Arena,
        .tilemap = gBattleEnvironmentTilemap_Arena,
        .palette = gBattleEnvironmentPalette_Arena,
    },
    
    [BATTLE_ENVIRONMENT_AUTUMN_FOREST] =
    {
        .tileset = gBattleEnvironmentTiles_AutumnForest,
        .tilemap = gBattleEnvironmentTilemap_AutumnForest,
        .palette = gBattleEnvironmentPalette_AutumnForest,
    },
    
    [BATTLE_ENVIRONMENT_BEACH] =
    {
        .tileset = gBattleEnvironmentTiles_Beach,
        .tilemap = gBattleEnvironmentTilemap_Beach,
        .palette = gBattleEnvironmentPalette_Beach,
    },

    [BATTLE_ENVIRONMENT_BRIDGE] =
    {
        .tileset = gBattleEnvironmentTiles_Bridge,
        .tilemap = gBattleEnvironmentTilemap_Bridge,
        .palette = gBattleEnvironmentPalette_Bridge,
    },

    [BATTLE_ENVIRONMENT_CAVE] =
    {
        .tileset = gBattleEnvironmentTiles_Cave,
        .tilemap = gBattleEnvironmentTilemap_Cave,
        .palette = gBattleEnvironmentPalette_Cave,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_DARK] =
    {
        .tileset = gBattleEnvironmentTiles_CaveDark,
        .tilemap = gBattleEnvironmentTilemap_CaveDark,
        .palette = gBattleEnvironmentPalette_CaveDark,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_MAGMA] =
    {
        .tileset = gBattleEnvironmentTiles_CaveMagma,
        .tilemap = gBattleEnvironmentTilemap_CaveMagma,
        .palette = gBattleEnvironmentPalette_CaveMagma,
    },
    
    [BATTLE_ENVIRONMENT_CAVE_SNOW] =
    {
        .tileset = gBattleEnvironmentTiles_CaveSnow,
        .tilemap = gBattleEnvironmentTilemap_CaveSnow,
        .palette = gBattleEnvironmentPalette_CaveSnow,
    },
    
    [BATTLE_ENVIRONMENT_CITY] =
    {
        .tileset = gBattleEnvironmentTiles_City,
        .tilemap = gBattleEnvironmentTilemap_City,
        .palette = gBattleEnvironmentPalette_City,
    },

    [BATTLE_ENVIRONMENT_CRAG] =
    {
        .tileset = gBattleEnvironmentTiles_Crag,
        .tilemap = gBattleEnvironmentTilemap_Crag,
        .palette = gBattleEnvironmentPalette_Crag,
    },

    [BATTLE_ENVIRONMENT_DESERT] =
    {
        .tileset = gBattleEnvironmentTiles_Desert,
        .tilemap = gBattleEnvironmentTilemap_Desert,
        .palette = gBattleEnvironmentPalette_Desert,
    },

    [BATTLE_ENVIRONMENT_GYM] =
    {
        .tileset = gBattleEnvironmentTiles_Gym,
        .tilemap = gBattleEnvironmentTilemap_Gym,
        .palette = gBattleEnvironmentPalette_Gym,
    },
    
    [BATTLE_ENVIRONMENT_INDOOR] =
    {
        .tileset = gBattleEnvironmentTiles_Indoor,
        .tilemap = gBattleEnvironmentTilemap_Indoor,
        .palette = gBattleEnvironmentPalette_Indoor,
    },
    
    [BATTLE_ENVIRONMENT_LAB] =
    {
        .tileset = gBattleEnvironmentTiles_Lab,
        .tilemap = gBattleEnvironmentTilemap_Lab,
        .palette = gBattleEnvironmentPalette_Lab,
    },
    
    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .tileset = gBattleEnvironmentTiles_Mountain,
        .tilemap = gBattleEnvironmentTilemap_Mountain,
        .palette = gBattleEnvironmentPalette_Mountain,
    },

    [BATTLE_ENVIRONMENT_MOUNTAIN_SNOW] =
    {
        .tileset = gBattleEnvironmentTiles_MountainSnow,
        .tilemap = gBattleEnvironmentTilemap_MountainSnow,
        .palette = gBattleEnvironmentPalette_MountainSnow,
    },

    [BATTLE_ENVIRONMENT_ROCKY] =
    {
        .tileset = gBattleEnvironmentTiles_Rocky,
        .tilemap = gBattleEnvironmentTilemap_Rocky,
        .palette = gBattleEnvironmentPalette_Rocky,
    },

    [BATTLE_ENVIRONMENT_ROUTE] =
    {
        .tileset = gBattleEnvironmentTiles_Route,
        .tilemap = gBattleEnvironmentTilemap_Route,
        .palette = gBattleEnvironmentPalette_Route,
    },

    [BATTLE_ENVIRONMENT_SAFARI] =
    {
        .tileset = gBattleEnvironmentTiles_Safari,
        .tilemap = gBattleEnvironmentTilemap_Safari,
        .palette = gBattleEnvironmentPalette_Safari,
    },

    [BATTLE_ENVIRONMENT_SEA] =
    {
        .tileset = gBattleEnvironmentTiles_Sea,
        .tilemap = gBattleEnvironmentTilemap_Sea,
        .palette = gBattleEnvironmentPalette_Sea,
    },

    [BATTLE_ENVIRONMENT_SNOW] =
    {
        .tileset = gBattleEnvironmentTiles_Snow,
        .tilemap = gBattleEnvironmentTilemap_Snow,
        .palette = gBattleEnvironmentPalette_Snow,
    },

    [BATTLE_ENVIRONMENT_SWAMP] =
    {
        .tileset = gBattleEnvironmentTiles_Swamp,
        .tilemap = gBattleEnvironmentTilemap_Swamp,
        .palette = gBattleEnvironmentPalette_Swamp,
    },

    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .tileset = gBattleEnvironmentTiles_Underwater,
        .tilemap = gBattleEnvironmentTilemap_Underwater,
        .palette = gBattleEnvironmentPalette_Underwater,
    },

    [BATTLE_ENVIRONMENT_VOLCANO] =
    {
        .tileset = gBattleEnvironmentTiles_Volcano,
        .tilemap = gBattleEnvironmentTilemap_Volcano,
        .palette = gBattleEnvironmentPalette_Volcano,
    },

    [BATTLE_ENVIRONMENT_MOOSE] =
    {
        .tileset = gBattleEnvironmentTiles_Moose,
        .tilemap = gBattleEnvironmentTilemap_Moose,
        .palette = gBattleEnvironmentPalette_Moose,
    },
    
    [BATTLE_ENVIRONMENT_THOMAS] =
    {
        .tileset = gBattleEnvironmentTiles_Thomas,
        .tilemap = gBattleEnvironmentTilemap_Thomas,
        .palette = gBattleEnvironmentPalette_Thomas,
    },
    
    [BATTLE_ENVIRONMENT_TINKER] =
    {
        .tileset = gBattleEnvironmentTiles_Tinker,
        .tilemap = gBattleEnvironmentTilemap_Tinker,
        .palette = gBattleEnvironmentPalette_Tinker,
    },
    
    [BATTLE_ENVIRONMENT_TOBIAS] =
    {
        .tileset = gBattleEnvironmentTiles_Tobias,
        .tilemap = gBattleEnvironmentTilemap_Tobias,
        .palette = gBattleEnvironmentPalette_Tobias,
    },
    
    [BATTLE_ENVIRONMENT_GWEN] =
    {
        .tileset = gBattleEnvironmentTiles_Gwen,
        .tilemap = gBattleEnvironmentTilemap_Gwen,
        .palette = gBattleEnvironmentPalette_Gwen,
    },
};

void BattleInitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gBattleBgTemplates, ARRAY_COUNT(gBattleBgTemplates));

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        gBattleScripting.windowsType = B_WIN_TYPE_ARENA;
        SetBgTilemapBuffer(1, gBattleAnimBgTilemapBuffer);
        SetBgTilemapBuffer(2, gBattleAnimBgTilemapBuffer);
    }
    else
    {
        gBattleScripting.windowsType = B_WIN_TYPE_NORMAL;
    }

    InitWindows(gBattleWindowTemplates[gBattleScripting.windowsType]);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    BattleInitBgsAndWindows();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

void LoadBattleMenuWindowGfx(void)
{
    LoadUserWindowBorderGfx(2, 0x12, BG_PLTT_ID(1));
    LoadUserWindowBorderGfx(2, 0x22, BG_PLTT_ID(1));
    LoadCompressedPalette(gBattleWindowTextPalette, BG_PLTT_ID(5), PLTT_SIZE_4BPP);

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        // Load graphics for the Battle Arena referee's mid-battle messages.
        Menu_LoadStdPalAt(BG_PLTT_ID(7));
        LoadMessageBoxGfx(0, 0x30, BG_PLTT_ID(7));
        gPlttBufferUnfaded[BG_PLTT_ID(7) + 6] = 0;
        CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(7) + 6], &gPlttBufferFaded[BG_PLTT_ID(7) + 6], PLTT_SIZEOF(1));
    }
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_RECORDED_LINK))
    {
        LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleEnvironmentTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_CaveMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleEnvironmentTiles_Sea, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Sea, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Sea, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleEnvironmentTiles_Crag, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Crag, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Crag, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        default:
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleEnvironmentTable[gBattleEnvironment].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u32 trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleEnvironmentTiles_Gym, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleEnvironmentTilemap_Gym, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleEnvironmentPalette_Gym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleEnvironmentTiles_Gwen, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleEnvironmentTilemap_Gwen, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleEnvironmentPalette_Gwen, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        default:
        case MAP_BATTLE_SCENE_NORMAL:
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleEnvironmentTable[gBattleEnvironment].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_GYM:
            LZDecompressVram(gBattleEnvironmentTiles_Gym, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Gym, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Gym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_MAGMA:
            LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_AQUA:
            LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_SIDNEY:
            LZDecompressVram(gBattleEnvironmentTiles_Moose, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Moose, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Moose, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_PHOEBE:
            LZDecompressVram(gBattleEnvironmentTiles_Thomas, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Thomas, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Thomas, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_GLACIA:
            LZDecompressVram(gBattleEnvironmentTiles_Tinker, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Tinker, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Tinker, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_DRAKE:
            LZDecompressVram(gBattleEnvironmentTiles_Tobias, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Tobias, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Tobias, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_FRONTIER:
            LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadBattleMenuWindowGfx();
    if (B_TERRAIN_BG_CHANGE == TRUE)
        DrawTerrainTypeBattleBackground();
    else
        DrawMainBattleBackground();
}

static void DrawLinkBattleParticipantPokeballs(u8 taskId, u8 multiplayerId, u8 bgId, u8 destX, u8 destY)
{
    s32 i;
    u16 pokeballStatuses = 0;
    u16 tiles[6];

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gTasks[taskId].data[5] != 0)
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            }
        }
        else
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            }
        }

        for (i = 0; i < 3; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 3, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
    else
    {
        if (multiplayerId == gBattleScripting.multiplayerId)
            pokeballStatuses = gTasks[taskId].data[3];
        else
            pokeballStatuses = gTasks[taskId].data[4];

        for (i = 0; i < 6; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 6, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
}

static void DrawLinkBattleVsScreenOutcomeText(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
    {
        BattlePutTextOnWindow(gText_Draw, B_WIN_VS_OUTCOME_DRAW);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleOutcome == B_OUTCOME_WON)
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            }
        }
        else
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            }
        }
    }
    else if (gBattleOutcome == B_OUTCOME_WON)
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
    }
    else
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
    }
}

void InitLinkBattleVsScreen(u8 taskId)
{
    struct LinkPlayer *linkPlayer;
    u8 *name;
    s32 i, palId;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                name = gLinkPlayers[i].name;
                linkPlayer = &gLinkPlayers[i];

                switch (linkPlayer->id)
                {
                case 0:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_1);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 4);
                    break;
                case 1:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_2);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 4);
                    break;
                case 2:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_3);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 8);
                    break;
                case 3:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_4);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 8);
                    break;
                }
            }
        }
        else
        {
            u8 playerId = gBattleScripting.multiplayerId;
            u8 opponentId = playerId ^ BIT_SIDE;
            u8 opponentId_copy = opponentId;

            if (gLinkPlayers[playerId].id != 0)
                opponentId = playerId, playerId = opponentId_copy;

            name = gLinkPlayers[playerId].name;
            BattlePutTextOnWindow(name, B_WIN_VS_PLAYER);

            name = gLinkPlayers[opponentId].name;
            BattlePutTextOnWindow(name, B_WIN_VS_OPPONENT);

            DrawLinkBattleParticipantPokeballs(taskId, playerId, 1, 2, 7);
            DrawLinkBattleParticipantPokeballs(taskId, opponentId, 2, 2, 7);
        }
        gTasks[taskId].data[0]++;
        break;
    case 1:
        palId = AllocSpritePalette(TAG_VS_LETTERS);
        gPlttBufferUnfaded[OBJ_PLTT_ID(palId) + 15] = gPlttBufferFaded[OBJ_PLTT_ID(palId) + 15] = RGB_WHITE;
        gBattleStruct->linkBattleVsSpriteId_V = CreateSprite(&sVsLetter_V_SpriteTemplate, 111, 80, 0);
        gBattleStruct->linkBattleVsSpriteId_S = CreateSprite(&sVsLetter_S_SpriteTemplate, 129, 80, 0);
        gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = TRUE;
        gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (gTasks[taskId].data[5] != 0)
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG1_Y = -36;
            gBattle_BG2_Y = -36;
        }
        else
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG1_Y = (Cos2(gTasks[taskId].data[1]) / 32) - 164;
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG2_Y = (Cos2(gTasks[taskId].data[2]) / 32) - 164;
        }

        if (gTasks[taskId].data[2] != 0)
        {
            gTasks[taskId].data[2] -= 2;
            gTasks[taskId].data[1] += 2;
        }
        else
        {
            if (gTasks[taskId].data[5] != 0)
                DrawLinkBattleVsScreenOutcomeText();

            PlaySE(SE_M_HARDEN);
            DestroyTask(taskId);
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].oam.tileNum += 0x40;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[0] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[0] = 1;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_V].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_S].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[2] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[2] = 0;
        }
        break;
    }
}

void DrawBattleEntryBackground(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        LZDecompressVram(gBattleVSFrame_Gfx, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gVsLettersGfx, (void *)OBJ_VRAM0);
        LoadCompressedPalette(gBattleVSFrame_Pal, BG_PLTT_ID(6), PLTT_SIZE_4BPP);
        SetBgAttribute(1, BG_ATTR_SCREENSIZE, 1);
        SetGpuReg(REG_OFFSET_BG1CNT, 0x5C04);
        CopyToBgTilemapBuffer(1, gBattleVSFrame_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gBattleVSFrame_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        gBattle_BG1_Y = 0xFF5C;
        gBattle_BG2_Y = 0xFF5C;
        LoadCompressedSpriteSheetUsingHeap(&sVsLettersSpriteSheet);
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) || gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
        {
            LZDecompressVram(gBattleEnvironmentTiles_Indoor, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleEnvironmentTilemap_Indoor, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            // Set up bg for the multi battle intro where both teams slide in facing the screen.
            // Note Steven's multi battle (which has a dedicated back pic) is excluded above.
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 2);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 2);
            CopyToBgTilemapBuffer(1, gMultiBattleIntroBg_Opponent_Tilemap, 0, 0);
            CopyToBgTilemapBuffer(2, gMultiBattleIntroBg_Player_Tilemap, 0, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleEnvironmentTiles_Cave, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleEnvironmentTilemap_Cave, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleEnvironmentTiles_Underwater, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleEnvironmentTilemap_Underwater, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleEnvironmentTiles_Crag, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleEnvironmentTilemap_Crag, (void*)(BG_SCREEN_ADDR(28)));
            break;
        default:
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
            break;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u32 trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleEnvironmentTiles_Gym, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleEnvironmentTilemap_Gym, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleEnvironmentTiles_Gwen, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleEnvironmentTilemap_Gwen, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
        }

        if (GetCurrentMapBattleScene() == MAP_BATTLE_SCENE_NORMAL)
        {
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            LZDecompressVram(gBattleEnvironmentTiles_Indoor, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleEnvironmentTilemap_Indoor, (void *)(BG_SCREEN_ADDR(28)));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        break;
    case 3:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleEnvironmentTiles_Indoor, (void *)(BG_CHAR_ADDR(2)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
        {
            switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
            {
            case SPECIES_GROUDON:
                LZDecompressVram(gBattleEnvironmentTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
                break;
            case SPECIES_KYOGRE:
                LZDecompressVram(gBattleEnvironmentTilemap_Sea, (void*)(BG_SCREEN_ADDR(2)));
                break;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u32 trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleEnvironmentTiles_Gym, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleEnvironmentTiles_Gwen, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tileset, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleEnvironmentTiles_Gym, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleEnvironmentTiles_Arena, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleEnvironmentTiles_Moose, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleEnvironmentTiles_Thomas, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleEnvironmentTiles_Tinker, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleEnvironmentTiles_Tobias, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleEnvironmentTiles_Indoor, (void *)(BG_CHAR_ADDR(2)));
                break;
            }
        }
        break;
    case 4:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleEnvironmentTilemap_Indoor, (void *)(BG_SCREEN_ADDR(26)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LZDecompressVram(gBattleEnvironmentTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            else
                LZDecompressVram(gBattleEnvironmentTilemap_Sea, (void *)(BG_SCREEN_ADDR(26)));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u32 trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleEnvironmentTilemap_Indoor, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleEnvironmentTilemap_Gwen, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(sBattleEnvironmentTable[gBattleEnvironment].tilemap, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleEnvironmentTilemap_Gym, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleEnvironmentTilemap_Arena, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleEnvironmentTilemap_Moose, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleEnvironmentTilemap_Thomas, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleEnvironmentTilemap_Tinker, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleEnvironmentTilemap_Tobias, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleEnvironmentTilemap_Indoor, (void *)(BG_SCREEN_ADDR(26)));
                break;
            }
        }
        break;
    case 5:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LoadCompressedPalette(gBattleEnvironmentPalette_CaveMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            else
                LoadCompressedPalette(gBattleEnvironmentPalette_Sea, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u32 trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadCompressedPalette(gBattleEnvironmentPalette_Gym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadCompressedPalette(gBattleEnvironmentPalette_Gwen, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LoadCompressedPalette(sBattleEnvironmentTable[gBattleEnvironment].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_GYM:
                LoadCompressedPalette(gBattleEnvironmentPalette_Gym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LoadCompressedPalette(gBattleEnvironmentPalette_Moose, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LoadCompressedPalette(gBattleEnvironmentPalette_Thomas, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LoadCompressedPalette(gBattleEnvironmentPalette_Tinker, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LoadCompressedPalette(gBattleEnvironmentPalette_Tobias, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LoadCompressedPalette(gBattleEnvironmentPalette_Arena, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            }
        }
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}

void DrawTerrainTypeBattleBackground(void)
{
    switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
    {
    case STATUS_FIELD_GRASSY_TERRAIN:
        LoadMoveBg(BG_GRASSY_TERRAIN);
        break;
    case STATUS_FIELD_MISTY_TERRAIN:
        LoadMoveBg(BG_MISTY_TERRAIN);
        break;
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        LoadMoveBg(BG_ELECTRIC_TERRAIN);
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        LoadMoveBg(BG_PSYCHIC_TERRAIN);
        break;
    default:
        DrawMainBattleBackground();
        break;
    }
}

