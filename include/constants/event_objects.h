#ifndef GUARD_CONSTANTS_EVENT_OBJECTS_H
#define GUARD_CONSTANTS_EVENT_OBJECTS_H

#include "constants/global.h"
#include "constants/map_event_ids.h"

#define PLAYER_AVATAR_GFX_MALE_NORMAL     (IS_FRLG ? OBJ_EVENT_GFX_RED_NORMAL     : OBJ_EVENT_GFX_LUCAS_NORMAL)
#define PLAYER_AVATAR_GFX_MALE_MACH_BIKE  (IS_FRLG ? OBJ_EVENT_GFX_RED_BIKE       : OBJ_EVENT_GFX_LUCAS_MACH_BIKE)
#define PLAYER_AVATAR_GFX_MALE_ACRO_BIKE  (IS_FRLG ? OBJ_EVENT_GFX_RED_BIKE       : OBJ_EVENT_GFX_LUCAS_ACRO_BIKE)
#define PLAYER_AVATAR_GFX_MALE_SURFING    (IS_FRLG ? OBJ_EVENT_GFX_RED_SURF       : OBJ_EVENT_GFX_LUCAS_SURFING)
#define PLAYER_AVATAR_GFX_MALE_UNDERWATER (IS_FRLG ? OBJ_EVENT_GFX_RED_SURF       : OBJ_EVENT_GFX_LUCAS_UNDERWATER)
#define PLAYER_AVATAR_GFX_MALE_FIELD_MOVE (IS_FRLG ? OBJ_EVENT_GFX_RED_FIELD_MOVE : OBJ_EVENT_GFX_LUCAS_FIELD_MOVE)
#define PLAYER_AVATAR_GFX_MALE_FISHING    (IS_FRLG ? OBJ_EVENT_GFX_RED_FISH       : OBJ_EVENT_GFX_LUCAS_FISHING)
#define PLAYER_AVATAR_GFX_MALE_WATERING   (IS_FRLG ? OBJ_EVENT_GFX_RED_FIELD_MOVE : OBJ_EVENT_GFX_LUCAS_WATERING)
#define PLAYER_AVATAR_GFX_MALE_VSSEEKER   (IS_FRLG ? OBJ_EVENT_GFX_RED_VS_SEEKER  : OBJ_EVENT_GFX_LUCAS_FIELD_MOVE)
#define PLAYER_AVATAR_GFX_FEMALE_NORMAL     (IS_FRLG ? OBJ_EVENT_GFX_GREEN_NORMAL     : OBJ_EVENT_GFX_DAWN_NORMAL)
#define PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE  (IS_FRLG ? OBJ_EVENT_GFX_GREEN_BIKE       : OBJ_EVENT_GFX_DAWN_MACH_BIKE)
#define PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE  (IS_FRLG ? OBJ_EVENT_GFX_GREEN_BIKE       : OBJ_EVENT_GFX_DAWN_ACRO_BIKE)
#define PLAYER_AVATAR_GFX_FEMALE_SURFING    (IS_FRLG ? OBJ_EVENT_GFX_GREEN_SURF       : OBJ_EVENT_GFX_DAWN_SURFING)
#define PLAYER_AVATAR_GFX_FEMALE_UNDERWATER (IS_FRLG ? OBJ_EVENT_GFX_GREEN_SURF       : OBJ_EVENT_GFX_DAWN_UNDERWATER)
#define PLAYER_AVATAR_GFX_FEMALE_FIELD_MOVE (IS_FRLG ? OBJ_EVENT_GFX_GREEN_FIELD_MOVE : OBJ_EVENT_GFX_DAWN_FIELD_MOVE)
#define PLAYER_AVATAR_GFX_FEMALE_FISHING    (IS_FRLG ? OBJ_EVENT_GFX_GREEN_FISH       : OBJ_EVENT_GFX_DAWN_FISHING)
#define PLAYER_AVATAR_GFX_FEMALE_WATERING   (IS_FRLG ? OBJ_EVENT_GFX_GREEN_FIELD_MOVE : OBJ_EVENT_GFX_DAWN_WATERING)
#define PLAYER_AVATAR_GFX_FEMALE_VSSEEKER   (IS_FRLG ? OBJ_EVENT_GFX_GREEN_VS_SEEKER  : OBJ_EVENT_GFX_DAWN_FIELD_MOVE)

#define OBJ_EVENT_GFX_BRENDAN_NORMAL               0
#define OBJ_EVENT_GFX_BRENDAN_MACH_BIKE            1
#define OBJ_EVENT_GFX_BRENDAN_SURFING              2
#define OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE           3
#define OBJ_EVENT_GFX_QUINTY_PLUMP                 4
#define OBJ_EVENT_GFX_NINJA_BOY                    5
#define OBJ_EVENT_GFX_TWIN                         6
#define OBJ_EVENT_GFX_BOY_1                        7
#define OBJ_EVENT_GFX_GIRL_1                       8
#define OBJ_EVENT_GFX_BOY_2                        9
#define OBJ_EVENT_GFX_GIRL_2                      10
#define OBJ_EVENT_GFX_LITTLE_BOY                  11
#define OBJ_EVENT_GFX_LITTLE_GIRL                 12
#define OBJ_EVENT_GFX_BOY_3                       13
#define OBJ_EVENT_GFX_GIRL_3                      14
#define OBJ_EVENT_GFX_RICH_BOY                    15
#define OBJ_EVENT_GFX_WOMAN_1                     16
#define OBJ_EVENT_GFX_FAT_MAN                     17
#define OBJ_EVENT_GFX_POKEFAN_F                   18
#define OBJ_EVENT_GFX_MAN_1                       19
#define OBJ_EVENT_GFX_WOMAN_2                     20
#define OBJ_EVENT_GFX_EXPERT_M                    21
#define OBJ_EVENT_GFX_EXPERT_F                    22
#define OBJ_EVENT_GFX_MAN_2                       23
#define OBJ_EVENT_GFX_WOMAN_3                     24
#define OBJ_EVENT_GFX_POKEFAN_M                   25
#define OBJ_EVENT_GFX_WOMAN_4                     26
#define OBJ_EVENT_GFX_COOK                        27
#define OBJ_EVENT_GFX_LINK_RECEPTIONIST           28
#define OBJ_EVENT_GFX_OLD_MAN                     29
#define OBJ_EVENT_GFX_OLD_WOMAN                   30
#define OBJ_EVENT_GFX_CAMPER                      31
#define OBJ_EVENT_GFX_PICNICKER                   32
#define OBJ_EVENT_GFX_MAN_3                       33
#define OBJ_EVENT_GFX_WOMAN_5                     34
#define OBJ_EVENT_GFX_YOUNGSTER                   35
#define OBJ_EVENT_GFX_BUG_CATCHER                 36
#define OBJ_EVENT_GFX_PSYCHIC_M                   37
#define OBJ_EVENT_GFX_SCHOOL_KID_M                38
#define OBJ_EVENT_GFX_MANIAC                      39
#define OBJ_EVENT_GFX_HEX_MANIAC                  40
#define OBJ_EVENT_GFX_RAYQUAZA_STILL              41
#define OBJ_EVENT_GFX_SWIMMER_M                   42
#define OBJ_EVENT_GFX_SWIMMER_F                   43
#define OBJ_EVENT_GFX_BLACK_BELT                  44
#define OBJ_EVENT_GFX_BEAUTY                      45
#define OBJ_EVENT_GFX_SCIENTIST_1                 46
#define OBJ_EVENT_GFX_LASS                        47
#define OBJ_EVENT_GFX_GENTLEMAN                   48
#define OBJ_EVENT_GFX_SAILOR                      49
#define OBJ_EVENT_GFX_FISHERMAN                   50
#define OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M        51
#define OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F        52
#define OBJ_EVENT_GFX_TUBER_F                     53
#define OBJ_EVENT_GFX_TUBER_M                     54
#define OBJ_EVENT_GFX_HIKER                       55
#define OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M        56
#define OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F        57
#define OBJ_EVENT_GFX_NURSE                       58
#define OBJ_EVENT_GFX_ITEM_BALL                   59
#define OBJ_EVENT_GFX_BERRY_TREE                  60
#define OBJ_EVENT_GFX_BERRY_TREE_EARLY_STAGES     61
#define OBJ_EVENT_GFX_BERRY_TREE_LATE_STAGES      62
#define OBJ_EVENT_GFX_LUCAS_ACRO_BIKE             63
#define OBJ_EVENT_GFX_PROF_BIRCH                  64
#define OBJ_EVENT_GFX_MAN_4                       65
#define OBJ_EVENT_GFX_MAN_5                       66
#define OBJ_EVENT_GFX_REPORTER_M                  67
#define OBJ_EVENT_GFX_REPORTER_F                  68
#define OBJ_EVENT_GFX_BARD                        69
#define OBJ_EVENT_GFX_ANABEL                      70
#define OBJ_EVENT_GFX_TUCKER                      71
#define OBJ_EVENT_GFX_GRETA                       72
#define OBJ_EVENT_GFX_SPENSER                     73
#define OBJ_EVENT_GFX_NOLAND                      74
#define OBJ_EVENT_GFX_LUCY                        75
#define OBJ_EVENT_GFX_UNUSED_NATU_DOLL            76
#define OBJ_EVENT_GFX_UNUSED_MAGNEMITE_DOLL       77
#define OBJ_EVENT_GFX_UNUSED_SQUIRTLE_DOLL        78
#define OBJ_EVENT_GFX_UNUSED_WOOPER_DOLL          79
#define OBJ_EVENT_GFX_UNUSED_PIKACHU_DOLL         80
#define OBJ_EVENT_GFX_UNUSED_PORYGON2_DOLL        81
#define OBJ_EVENT_GFX_CUTTABLE_TREE               82
#define OBJ_EVENT_GFX_MART_EMPLOYEE               83
#define OBJ_EVENT_GFX_ROOFTOP_SALE_WOMAN          84
#define OBJ_EVENT_GFX_TEALA                       85
#define OBJ_EVENT_GFX_BREAKABLE_ROCK              86
#define OBJ_EVENT_GFX_PUSHABLE_BOULDER            87
#define OBJ_EVENT_GFX_MR_BRINEYS_BOAT             88
#define OBJ_EVENT_GFX_DAWN_NORMAL                 89
#define OBJ_EVENT_GFX_DAWN_MACH_BIKE              90
#define OBJ_EVENT_GFX_DAWN_ACRO_BIKE              91
#define OBJ_EVENT_GFX_DAWN_SURFING                92
#define OBJ_EVENT_GFX_DAWN_FIELD_MOVE             93
#define OBJ_EVENT_GFX_TRUCK                       94
#define OBJ_EVENT_GFX_VIGOROTH_CARRYING_BOX       95
#define OBJ_EVENT_GFX_VIGOROTH_FACING_AWAY        96
#define OBJ_EVENT_GFX_BIRCHS_BAG                  97
#define OBJ_EVENT_GFX_ZIGZAGOON_1                 98
#define OBJ_EVENT_GFX_ARTIST                      99
#define OBJ_EVENT_GFX_RIVAL_LUCAS_NORMAL         100
#define OBJ_EVENT_GFX_RIVAL_LUCAS_MACH_BIKE      101
#define OBJ_EVENT_GFX_RIVAL_LUCAS_ACRO_BIKE      102
#define OBJ_EVENT_GFX_RIVAL_LUCAS_SURFING        103
#define OBJ_EVENT_GFX_RIVAL_LUCAS_FIELD_MOVE     104
#define OBJ_EVENT_GFX_RIVAL_DAWN_NORMAL          105
#define OBJ_EVENT_GFX_RIVAL_DAWN_MACH_BIKE       106
#define OBJ_EVENT_GFX_RIVAL_DAWN_ACRO_BIKE       107
#define OBJ_EVENT_GFX_RIVAL_DAWN_SURFING         108
#define OBJ_EVENT_GFX_RIVAL_DAWN_FIELD_MOVE      109
#define OBJ_EVENT_GFX_CAMERAMAN                  110
#define OBJ_EVENT_GFX_LUCAS_UNDERWATER           111
#define OBJ_EVENT_GFX_DAWN_UNDERWATER            112
#define OBJ_EVENT_GFX_MOVING_BOX                 113
#define OBJ_EVENT_GFX_CABLE_CAR                  114
#define OBJ_EVENT_GFX_SCIENTIST_2                115
#define OBJ_EVENT_GFX_DEVON_EMPLOYEE             116
#define OBJ_EVENT_GFX_AQUA_MEMBER_M              117
#define OBJ_EVENT_GFX_AQUA_MEMBER_F              118
#define OBJ_EVENT_GFX_MAGMA_MEMBER_M             119
#define OBJ_EVENT_GFX_MAGMA_MEMBER_F             120
#define OBJ_EVENT_GFX_SIDNEY                     121
#define OBJ_EVENT_GFX_PHOEBE                     122
#define OBJ_EVENT_GFX_GLACIA                     123
#define OBJ_EVENT_GFX_DRAKE                      124
#define OBJ_EVENT_GFX_ROXANNE                    125
#define OBJ_EVENT_GFX_BRAWLY                     126
#define OBJ_EVENT_GFX_WATTSON                    127
#define OBJ_EVENT_GFX_FLANNERY                   128
#define OBJ_EVENT_GFX_NORMAN                     129
#define OBJ_EVENT_GFX_WINONA                     130
#define OBJ_EVENT_GFX_LIZA                       131
#define OBJ_EVENT_GFX_TATE                       132
#define OBJ_EVENT_GFX_WALLACE                    133
#define OBJ_EVENT_GFX_STEVEN                     134
#define OBJ_EVENT_GFX_WALLY                      135
#define OBJ_EVENT_GFX_LITTLE_BOY_3               136
#define OBJ_EVENT_GFX_LUCAS_FISHING              137
#define OBJ_EVENT_GFX_DAWN_FISHING               138
#define OBJ_EVENT_GFX_HOT_SPRINGS_OLD_WOMAN      139
#define OBJ_EVENT_GFX_SS_TIDAL                   140
#define OBJ_EVENT_GFX_SUBMARINE_SHADOW           141
#define OBJ_EVENT_GFX_PICHU_DOLL                 142
#define OBJ_EVENT_GFX_PIKACHU_DOLL               143
#define OBJ_EVENT_GFX_MARILL_DOLL                144
#define OBJ_EVENT_GFX_TOGEPI_DOLL                145
#define OBJ_EVENT_GFX_CYNDAQUIL_DOLL             146
#define OBJ_EVENT_GFX_CHIKORITA_DOLL             147
#define OBJ_EVENT_GFX_TOTODILE_DOLL              148
#define OBJ_EVENT_GFX_JIGGLYPUFF_DOLL            149
#define OBJ_EVENT_GFX_MEOWTH_DOLL                150
#define OBJ_EVENT_GFX_CLEFAIRY_DOLL              151
#define OBJ_EVENT_GFX_DITTO_DOLL                 152
#define OBJ_EVENT_GFX_SMOOCHUM_DOLL              153
#define OBJ_EVENT_GFX_TREECKO_DOLL               154
#define OBJ_EVENT_GFX_TORCHIC_DOLL               155
#define OBJ_EVENT_GFX_MUDKIP_DOLL                156
#define OBJ_EVENT_GFX_DUSKULL_DOLL               157
#define OBJ_EVENT_GFX_WYNAUT_DOLL                158
#define OBJ_EVENT_GFX_BALTOY_DOLL                159
#define OBJ_EVENT_GFX_KECLEON_DOLL               160
#define OBJ_EVENT_GFX_AZURILL_DOLL               161
#define OBJ_EVENT_GFX_SKITTY_DOLL                162
#define OBJ_EVENT_GFX_SWABLU_DOLL                163
#define OBJ_EVENT_GFX_GULPIN_DOLL                164
#define OBJ_EVENT_GFX_LOTAD_DOLL                 165
#define OBJ_EVENT_GFX_SEEDOT_DOLL                166
#define OBJ_EVENT_GFX_PIKA_CUSHION               167
#define OBJ_EVENT_GFX_ROUND_CUSHION              168
#define OBJ_EVENT_GFX_KISS_CUSHION               169
#define OBJ_EVENT_GFX_ZIGZAG_CUSHION             170
#define OBJ_EVENT_GFX_SPIN_CUSHION               171
#define OBJ_EVENT_GFX_DIAMOND_CUSHION            172
#define OBJ_EVENT_GFX_BALL_CUSHION               173
#define OBJ_EVENT_GFX_GRASS_CUSHION              174
#define OBJ_EVENT_GFX_FIRE_CUSHION               175
#define OBJ_EVENT_GFX_WATER_CUSHION              176
#define OBJ_EVENT_GFX_BIG_SNORLAX_DOLL           177
#define OBJ_EVENT_GFX_BIG_RHYDON_DOLL            178
#define OBJ_EVENT_GFX_BIG_LAPRAS_DOLL            179
#define OBJ_EVENT_GFX_BIG_VENUSAUR_DOLL          180
#define OBJ_EVENT_GFX_BIG_CHARIZARD_DOLL         181
#define OBJ_EVENT_GFX_BIG_BLASTOISE_DOLL         182
#define OBJ_EVENT_GFX_BIG_WAILMER_DOLL           183
#define OBJ_EVENT_GFX_BIG_REGIROCK_DOLL          184
#define OBJ_EVENT_GFX_BIG_REGICE_DOLL            185
#define OBJ_EVENT_GFX_BIG_REGISTEEL_DOLL         186
#define OBJ_EVENT_GFX_LATIAS                     187
#define OBJ_EVENT_GFX_LATIOS                     188
#define OBJ_EVENT_GFX_GAMEBOY_KID                189
#define OBJ_EVENT_GFX_CONTEST_JUDGE              190
#define OBJ_EVENT_GFX_LUCAS_WATERING             191
#define OBJ_EVENT_GFX_DAWN_WATERING              192
#define OBJ_EVENT_GFX_LUCAS_DECORATING           193
#define OBJ_EVENT_GFX_DAWN_DECORATING            194
#define OBJ_EVENT_GFX_ARCHIE                     195
#define OBJ_EVENT_GFX_MAXIE                      196
#define OBJ_EVENT_GFX_KYOGRE_FRONT               197
#define OBJ_EVENT_GFX_GROUDON_FRONT              198
#define OBJ_EVENT_GFX_FOSSIL                     199
#define OBJ_EVENT_GFX_REGIROCK                   200
#define OBJ_EVENT_GFX_REGICE                     201
#define OBJ_EVENT_GFX_REGISTEEL                  202
#define OBJ_EVENT_GFX_SKITTY                     203
#define OBJ_EVENT_GFX_KECLEON                    204
#define OBJ_EVENT_GFX_KYOGRE_ASLEEP              205
#define OBJ_EVENT_GFX_GROUDON_ASLEEP             206
#define OBJ_EVENT_GFX_RAYQUAZA                   207
#define OBJ_EVENT_GFX_ZIGZAGOON_2                208
#define OBJ_EVENT_GFX_PIKACHU                    209
#define OBJ_EVENT_GFX_AZUMARILL                  210
#define OBJ_EVENT_GFX_WINGULL                    211
#define OBJ_EVENT_GFX_KECLEON_BRIDGE_SHADOW      212
#define OBJ_EVENT_GFX_TUBER_M_SWIMMING           213
#define OBJ_EVENT_GFX_AZURILL                    214
#define OBJ_EVENT_GFX_MOM                        215
#define OBJ_EVENT_GFX_LINK_LUCAS                 216
#define OBJ_EVENT_GFX_LINK_DAWN                  217
#define OBJ_EVENT_GFX_JUAN                       218
#define OBJ_EVENT_GFX_SCOTT                      219
#define OBJ_EVENT_GFX_POOCHYENA                  220
#define OBJ_EVENT_GFX_KYOGRE_SIDE                221
#define OBJ_EVENT_GFX_GROUDON_SIDE               222
#define OBJ_EVENT_GFX_MYSTERY_GIFT_MAN           223
#define OBJ_EVENT_GFX_TRICK_HOUSE_STATUE         224
#define OBJ_EVENT_GFX_KIRLIA                     225
#define OBJ_EVENT_GFX_DUSCLOPS                   226
#define OBJ_EVENT_GFX_UNION_ROOM_NURSE           227
#define OBJ_EVENT_GFX_SUDOWOODO                  228
#define OBJ_EVENT_GFX_MEW                        229
#define OBJ_EVENT_GFX_RED                        230
#define OBJ_EVENT_GFX_LEAF                       231
#define OBJ_EVENT_GFX_DEOXYS                     232
#define OBJ_EVENT_GFX_DEOXYS_TRIANGLE            233
#define OBJ_EVENT_GFX_BRANDON                    234
#define OBJ_EVENT_GFX_LINK_RS_BRENDAN            235
#define OBJ_EVENT_GFX_LINK_RS_MAY                236
#define OBJ_EVENT_GFX_LUGIA                      237
#define OBJ_EVENT_GFX_HOOH                       238
#define OBJ_EVENT_GFX_LIGHT_SPRITE               547
=======
#define OBJ_EVENT_GFX_POKE_BALL                  239
#define OBJ_EVENT_GFX_OW_MON                     240
#define OBJ_EVENT_GFX_LIGHT_SPRITE               241
#define OBJ_EVENT_GFX_APRICORN_TREE              242

// FRLG objects
#define OBJ_EVENT_GFX_RED_NORMAL                 243
#define OBJ_EVENT_GFX_RED_BIKE                   244
#define OBJ_EVENT_GFX_RED_SURF                   245
#define OBJ_EVENT_GFX_RED_FIELD_MOVE             246
#define OBJ_EVENT_GFX_RED_FISH                   247
#define OBJ_EVENT_GFX_RED_VS_SEEKER              248
#define OBJ_EVENT_GFX_RED_VS_SEEKER_BIKE         249
#define OBJ_EVENT_GFX_GREEN_NORMAL               251
#define OBJ_EVENT_GFX_GREEN_BIKE                 252
#define OBJ_EVENT_GFX_GREEN_SURF                 253
#define OBJ_EVENT_GFX_GREEN_FIELD_MOVE           254
#define OBJ_EVENT_GFX_GREEN_FISH                 255
#define OBJ_EVENT_GFX_GREEN_VS_SEEKER            256
#define OBJ_EVENT_GFX_GREEN_VS_SEEKER_BIKE       257
#define OBJ_EVENT_GFX_BOY                        258
#define OBJ_EVENT_GFX_BATTLE_GIRL                259
#define OBJ_EVENT_GFX_MAN                        260
#define OBJ_EVENT_GFX_ROCKER                     261
#define OBJ_EVENT_GFX_BALDING_MAN                262
#define OBJ_EVENT_GFX_OLD_MAN_1                  263
#define OBJ_EVENT_GFX_OLD_MAN_2                  264
#define OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN         265
#define OBJ_EVENT_GFX_TUBER_M_WATER              266
#define OBJ_EVENT_GFX_TUBER_M_LAND               267
#define OBJ_EVENT_GFX_COOLTRAINER_M              268
#define OBJ_EVENT_GFX_COOLTRAINER_F              269
#define OBJ_EVENT_GFX_SWIMMER_M_WATER            270
#define OBJ_EVENT_GFX_SWIMMER_F_WATER            271
#define OBJ_EVENT_GFX_SWIMMER_M_LAND             272
#define OBJ_EVENT_GFX_SWIMMER_F_LAND             273
#define OBJ_EVENT_GFX_WORKER_M                   274
#define OBJ_EVENT_GFX_WORKER_F                   275
#define OBJ_EVENT_GFX_ROCKET_M                   276
#define OBJ_EVENT_GFX_ROCKET_F                   277
#define OBJ_EVENT_GFX_GBA_KID                    278
#define OBJ_EVENT_GFX_SUPER_NERD                 279
#define OBJ_EVENT_GFX_BIKER                      280
#define OBJ_EVENT_GFX_BLACKBELT                  281
#define OBJ_EVENT_GFX_SCIENTIST                  282
#define OBJ_EVENT_GFX_FISHER                     283
#define OBJ_EVENT_GFX_CHANNELER                  284
#define OBJ_EVENT_GFX_CHEF                       285
#define OBJ_EVENT_GFX_POLICEMAN                  286
#define OBJ_EVENT_GFX_CAPTAIN                    287
#define OBJ_EVENT_GFX_CABLE_CLUB_RECEPTIONIST    288
#define OBJ_EVENT_GFX_UNION_ROOM_RECEPTIONIST    289
#define OBJ_EVENT_GFX_CLERK                      290
#define OBJ_EVENT_GFX_MG_DELIVERYMAN             291
#define OBJ_EVENT_GFX_TRAINER_TOWER_DUDE         292
#define OBJ_EVENT_GFX_PROF_OAK                   293
#define OBJ_EVENT_GFX_BLUE                       294
#define OBJ_EVENT_GFX_BILL                       295
#define OBJ_EVENT_GFX_LANCE                      296
#define OBJ_EVENT_GFX_AGATHA                     297
#define OBJ_EVENT_GFX_DAISY                      298
#define OBJ_EVENT_GFX_LORELEI                    299
#define OBJ_EVENT_GFX_MR_FUJI                    300
#define OBJ_EVENT_GFX_BRUNO                      301
#define OBJ_EVENT_GFX_BROCK                      302
#define OBJ_EVENT_GFX_MISTY                      303
#define OBJ_EVENT_GFX_LT_SURGE                   304
#define OBJ_EVENT_GFX_ERIKA                      305
#define OBJ_EVENT_GFX_KOGA                       306
#define OBJ_EVENT_GFX_SABRINA                    307
#define OBJ_EVENT_GFX_BLAINE                     308
#define OBJ_EVENT_GFX_GIOVANNI                   309
#define OBJ_EVENT_GFX_CELIO                      310
#define OBJ_EVENT_GFX_TEACHY_TV_HOST             311
#define OBJ_EVENT_GFX_GYM_GUY                    312
#define OBJ_EVENT_GFX_TOWN_MAP                   313
#define OBJ_EVENT_GFX_POKEDEX                    314
#define OBJ_EVENT_GFX_LITTLE_BOY_FRLG            315
#define OBJ_EVENT_GFX_LITTLE_GIRL_FRLG           316
#define OBJ_EVENT_GFX_YOUNGSTER_FRLG             317
#define OBJ_EVENT_GFX_BUG_CATCHER_FRLG           318
#define OBJ_EVENT_GFX_LASS_FRLG                  319
#define OBJ_EVENT_GFX_WOMAN_1_FRLG               320
#define OBJ_EVENT_GFX_FAT_MAN_FRLG               321
#define OBJ_EVENT_GFX_WOMAN_2_FRLG               322
#define OBJ_EVENT_GFX_BEAUTY_FRLG                323
#define OBJ_EVENT_GFX_WOMAN_3_FRLG               324
#define OBJ_EVENT_GFX_OLD_WOMAN_FRLG             325
#define OBJ_EVENT_GFX_CAMPER_FRLG                326
#define OBJ_EVENT_GFX_PICNICKER_FRLG             327
#define OBJ_EVENT_GFX_MOM_FRLG                   328
#define OBJ_EVENT_GFX_TUBER_F_FRLG               329
#define OBJ_EVENT_GFX_HIKER_FRLG                 330
#define OBJ_EVENT_GFX_GENTLEMAN_FRLG             331
#define OBJ_EVENT_GFX_SAILOR_FRLG                332
#define OBJ_EVENT_GFX_NURSE_FRLG                 333
#define OBJ_EVENT_GFX_FOSSIL_FRLG                334
#define OBJ_EVENT_GFX_RUBY                       335
#define OBJ_EVENT_GFX_SAPPHIRE                   336
#define OBJ_EVENT_GFX_OLD_AMBER                  337
#define OBJ_EVENT_GFX_GYM_SIGN                   338
#define OBJ_EVENT_GFX_SIGN                       339
#define OBJ_EVENT_GFX_TRAINER_TIPS               340
#define OBJ_EVENT_GFX_CLIPBOARD                  341
#define OBJ_EVENT_GFX_METEORITE                  342
#define OBJ_EVENT_GFX_LAPRAS_DOLL                343
#define OBJ_EVENT_GFX_SEAGALLOP                  344
#define OBJ_EVENT_GFX_SNORLAX                    345
#define OBJ_EVENT_GFX_SPEAROW                    346
#define OBJ_EVENT_GFX_CUBONE                     347
#define OBJ_EVENT_GFX_POLIWRATH                  348
#define OBJ_EVENT_GFX_CLEFAIRY                   349
#define OBJ_EVENT_GFX_PIDGEOT                    350
#define OBJ_EVENT_GFX_JIGGLYPUFF                 351
#define OBJ_EVENT_GFX_PIDGEY                     352
#define OBJ_EVENT_GFX_CHANSEY                    353
#define OBJ_EVENT_GFX_OMANYTE                    354
#define OBJ_EVENT_GFX_KANGASKHAN                 355
#define OBJ_EVENT_GFX_PIKACHU_FRLG               356
#define OBJ_EVENT_GFX_PSYDUCK                    357
#define OBJ_EVENT_GFX_NIDORAN_F                  358
#define OBJ_EVENT_GFX_NIDORAN_M                  359
#define OBJ_EVENT_GFX_NIDORINO                   360
#define OBJ_EVENT_GFX_MEOWTH                     361
#define OBJ_EVENT_GFX_SEEL                       362
#define OBJ_EVENT_GFX_VOLTORB                    363
#define OBJ_EVENT_GFX_SLOWPOKE                   364
#define OBJ_EVENT_GFX_SLOWBRO                    365
#define OBJ_EVENT_GFX_MACHOP                     366
#define OBJ_EVENT_GFX_WIGGLYTUFF                 367
#define OBJ_EVENT_GFX_DODUO                      368
#define OBJ_EVENT_GFX_FEAROW                     369
#define OBJ_EVENT_GFX_MACHOKE                    370
#define OBJ_EVENT_GFX_LAPRAS                     371
#define OBJ_EVENT_GFX_ZAPDOS                     372
#define OBJ_EVENT_GFX_MOLTRES                    373
#define OBJ_EVENT_GFX_ARTICUNO                   374
#define OBJ_EVENT_GFX_MEWTWO                     375
#define OBJ_EVENT_GFX_ENTEI                      376
#define OBJ_EVENT_GFX_SUICUNE                    377
#define OBJ_EVENT_GFX_RAIKOU                     378
#define OBJ_EVENT_GFX_CELEBI                     379
#define OBJ_EVENT_GFX_KABUTO                     380
#define OBJ_EVENT_GFX_DEOXYS_D                   381
#define OBJ_EVENT_GFX_DEOXYS_A                   382
#define OBJ_EVENT_GFX_DEOXYS_N                   383
#define OBJ_EVENT_GFX_SS_ANNE                    384
#define OBJ_EVENT_GFX_PUSHABLE_BOULDER_FRLG      385
#define OBJ_EVENT_GFX_CUTTABLE_TREE_FRLG         386
#define OBJ_EVENT_GFX_BREAKABLE_ROCK_FRLG        387
#define OBJ_EVENT_GFX_AARON                      388
#define OBJ_EVENT_GFX_ACCORDIANIST               389
#define OBJ_EVENT_GFX_ACTOR                      390
#define OBJ_EVENT_GFX_ADHIRA                     391
#define OBJ_EVENT_GFX_AGATHA_1                   392
#define OBJ_EVENT_GFX_AHAB                       393
#define OBJ_EVENT_GFX_AKARI                      394
#define OBJ_EVENT_GFX_ALDER                      395
#define OBJ_EVENT_GFX_AMELIA                     396
#define OBJ_EVENT_GFX_ANTHEA                     397
#define OBJ_EVENT_GFX_AROMA_LADY                 398
#define OBJ_EVENT_GFX_ARTIST_1                   399
#define OBJ_EVENT_GFX_ARTIST_2                   400
#define OBJ_EVENT_GFX_ARTIST_3                   401
#define OBJ_EVENT_GFX_AUDREY                     402
#define OBJ_EVENT_GFX_BACKPACKER_F               403
#define OBJ_EVENT_GFX_BACKPACKER_M               404
#define OBJ_EVENT_GFX_BAKER                      405
#define OBJ_EVENT_GFX_BATTLEGIRL_1               406
#define OBJ_EVENT_GFX_BATTLEGIRL_2               407
#define OBJ_EVENT_GFX_BEAUTY_1                   408
#define OBJ_EVENT_GFX_BEAUTY_2                   409
#define OBJ_EVENT_GFX_BEAUTY_3                   410
#define OBJ_EVENT_GFX_BEAUTY_4                   411
#define OBJ_EVENT_GFX_BELLIS                     412
#define OBJ_EVENT_GFX_BENGA                      413
#define OBJ_EVENT_GFX_BERTHA                     414
#define OBJ_EVENT_GFX_BIANCA                     415
#define OBJ_EVENT_GFX_BIKER_1                    416
#define OBJ_EVENT_GFX_BIKER_2                    417
#define OBJ_EVENT_GFX_BIRDKEEPER_F_1             418
#define OBJ_EVENT_GFX_BIRDKEEPER_F_2             419
#define OBJ_EVENT_GFX_BIRDKEEPER_M               420
#define OBJ_EVENT_GFX_BLACKBELT_1                421
#define OBJ_EVENT_GFX_BLACKBELT_2                422
#define OBJ_EVENT_GFX_BLACKBELT_3                423
#define OBJ_EVENT_GFX_BLAINE_1                   424
#define OBJ_EVENT_GFX_BOARDER                    425
#define OBJ_EVENT_GFX_BOY                        426
#define OBJ_EVENT_GFX_BRAWLY_1                   427
#define OBJ_EVENT_GFX_BREEDER_F_1                428
#define OBJ_EVENT_GFX_BREEDER_F_2                429
#define OBJ_EVENT_GFX_BREEDER_M_1                430
#define OBJ_EVENT_GFX_BREEDER_M_2                431
#define OBJ_EVENT_GFX_BROCK_1                    432
#define OBJ_EVENT_GFX_BRUNO_1                    433
#define OBJ_EVENT_GFX_BRYCEN                     434
#define OBJ_EVENT_GFX_BUG_CATCHER_1              435
#define OBJ_EVENT_GFX_BUGSY                      436
#define OBJ_EVENT_GFX_BURGH                      437
#define OBJ_EVENT_GFX_BURGLAR                    438
#define OBJ_EVENT_GFX_BW_MOM                     439
#define OBJ_EVENT_GFX_BW2_MOM                    440
#define OBJ_EVENT_GFX_BYRON                      441
#define OBJ_EVENT_GFX_CAITLIN                    442
#define OBJ_EVENT_GFX_CALEM                      443
#define OBJ_EVENT_GFX_CAMERAMAN_1                444
#define OBJ_EVENT_GFX_CAMPER_1                   445
#define OBJ_EVENT_GFX_CANDICE                    446
#define OBJ_EVENT_GFX_CAPTAIN                    447
#define OBJ_EVENT_GFX_CARLY                      448
#define OBJ_EVENT_GFX_CARMINE                    449
#define OBJ_EVENT_GFX_CARTER                     450
#define OBJ_EVENT_GFX_CEDRIC                     451
#define OBJ_EVENT_GFX_CHANNELLER                 452
#define OBJ_EVENT_GFX_CHEREN                     453
#define OBJ_EVENT_GFX_CHILI                      454
#define OBJ_EVENT_GFX_CHUCK                      455
#define OBJ_EVENT_GFX_CILAN                      456
#define OBJ_EVENT_GFX_CLAIRE                     457
#define OBJ_EVENT_GFX_CLAY                       458
#define OBJ_EVENT_GFX_CLERK_F                    459
#define OBJ_EVENT_GFX_CLERK_M_1                  460
#define OBJ_EVENT_GFX_CLERK_M_2                  461
#define OBJ_EVENT_GFX_CLOWN                      462
#define OBJ_EVENT_GFX_COLLECTOR                  463
#define OBJ_EVENT_GFX_COLRESS                    464
#define OBJ_EVENT_GFX_CONCORDIA                  465
#define OBJ_EVENT_GFX_COOLTRAINER_F_1            466
#define OBJ_EVENT_GFX_COOLTRAINER_F_2            467
#define OBJ_EVENT_GFX_COOLTRAINER_F_3            468
#define OBJ_EVENT_GFX_COOLTRAINER_F_4            469
#define OBJ_EVENT_GFX_COOLTRAINER_M_1            470
#define OBJ_EVENT_GFX_COOLTRAINER_M_2            471
#define OBJ_EVENT_GFX_COOLTRAINER_M_3            472
#define OBJ_EVENT_GFX_COOLTRAINER_M_4            473
#define OBJ_EVENT_GFX_COWGIRL                    474
#define OBJ_EVENT_GFX_CRASHER_WAKE               475
#define OBJ_EVENT_GFX_CRESS                      476
#define OBJ_EVENT_GFX_CURTIS_1                   477
#define OBJ_EVENT_GFX_CURTIS_2                   478
#define OBJ_EVENT_GFX_CYCLIST_F_1                479
#define OBJ_EVENT_GFX_CYCLIST_F_2                480
#define OBJ_EVENT_GFX_CYCLIST_M_1                481
#define OBJ_EVENT_GFX_CYCLIST_M_2                482
#define OBJ_EVENT_GFX_CYNTHIA                    483
#define OBJ_EVENT_GFX_DANCER                     484
#define OBJ_EVENT_GFX_DEPOTAGENT                 485
#define OBJ_EVENT_GFX_DIANTHA                    486
#define OBJ_EVENT_GFX_DIVER                      487
#define OBJ_EVENT_GFX_DOCTOR                     488
#define OBJ_EVENT_GFX_DRAGONTAMER                489
#define OBJ_EVENT_GFX_DRAYDEN                    490
#define OBJ_EVENT_GFX_ELDER                      491
#define OBJ_EVENT_GFX_ELISA                      492
#define OBJ_EVENT_GFX_EMMET                      493
#define OBJ_EVENT_GFX_ERICA_1                    494
#define OBJ_EVENT_GFX_ETHAN_RUN                  495
#define OBJ_EVENT_GFX_ETHAN                      496
#define OBJ_EVENT_GFX_FALKNER                    497
#define OBJ_EVENT_GFX_FANTINA                    498
#define OBJ_EVENT_GFX_FAT_MAN_1                  499
#define OBJ_EVENT_GFX_FAT_MAN_2                  500
#define OBJ_EVENT_GFX_FAT_MAN_3                  501
#define OBJ_EVENT_GFX_FENNEL                     502
#define OBJ_EVENT_GFX_FIREBREATHER               503
#define OBJ_EVENT_GFX_FISHERMAN_1                504
#define OBJ_EVENT_GFX_FISHERMAN_2                505
#define OBJ_EVENT_GFX_FLANNERY_1                 506
#define OBJ_EVENT_GFX_FLAUTIST                   507
#define OBJ_EVENT_GFX_FLINT                      508
#define OBJ_EVENT_GFX_GAMBLER                    509
#define OBJ_EVENT_GFX_GARDENIA                   510
#define OBJ_EVENT_GFX_GEETA                      511
#define OBJ_EVENT_GFX_GENTLEMAN_1                512
#define OBJ_EVENT_GFX_GENTLEMAN_2                513
#define OBJ_EVENT_GFX_GENTLEMAN_3                514
#define OBJ_EVENT_GFX_GLORIA                     515
#define OBJ_EVENT_GFX_GRIMSLEY                   516
#define OBJ_EVENT_GFX_GUIDE_F                    517
#define OBJ_EVENT_GFX_GUIDE_M                    518
#define OBJ_EVENT_GFX_GUITARIST_1                519
#define OBJ_EVENT_GFX_GUITARIST_2                520
#define OBJ_EVENT_GFX_GUITARIST_3                521
#define OBJ_EVENT_GFX_GUITARIST_F_1              522
#define OBJ_EVENT_GFX_GUITARIST_F_2              523
#define OBJ_EVENT_GFX_GUZMA                      524
#define OBJ_EVENT_GFX_GYM_GUIDE                  525
#define OBJ_EVENT_GFX_HARLEQUIN                  526
#define OBJ_EVENT_GFX_HARMONICA                  527
#define OBJ_EVENT_GFX_HEX_MANIAC                 528
#define OBJ_EVENT_GFX_HIKER_1                    529
#define OBJ_EVENT_GFX_HIKER_2                    530
#define OBJ_EVENT_GFX_HILDA                      531
#define OBJ_EVENT_GFX_HOBIE                      532
#define OBJ_EVENT_GFX_HOOPSTER                   533
#define OBJ_EVENT_GFX_HUGH                       534
#define OBJ_EVENT_GFX_IDOL                       535
#define OBJ_EVENT_GFX_INFIELDER                  536
#define OBJ_EVENT_GFX_INGO                       537
#define OBJ_EVENT_GFX_IRIS                       538
#define OBJ_EVENT_GFX_ISRAEL                     539
#define OBJ_EVENT_GFX_JANINE                     540
#define OBJ_EVENT_GFX_JANITOR                    541
#define OBJ_EVENT_GFX_JASMINE                    542
#define OBJ_EVENT_GFX_JELISSA                    543
#define OBJ_EVENT_GFX_JOGGER_1                   544
#define OBJ_EVENT_GFX_JOGGER_2                   545
#define OBJ_EVENT_GFX_JOGGER_3                   546
#define OBJ_EVENT_GFX_JOSH                       547
#define OBJ_EVENT_GFX_JUAN_1                     548
#define OBJ_EVENT_GFX_JUGGLER                    549
#define OBJ_EVENT_GFX_JUNIPER                    550
#define OBJ_EVENT_GFX_JUNKO                      551
#define OBJ_EVENT_GFX_KAHILI                     552
#define OBJ_EVENT_GFX_KAREN_1                    553
#define OBJ_EVENT_GFX_KEYTAURIST                 554
#define OBJ_EVENT_GFX_KIERAN                     555
#define OBJ_EVENT_GFX_KOGA_1                     556
#define OBJ_EVENT_GFX_LADY_1                     557
#define OBJ_EVENT_GFX_LADY_2                     558
#define OBJ_EVENT_GFX_LANCE_1                    559
#define OBJ_EVENT_GFX_LASS_1                     560
#define OBJ_EVENT_GFX_LASS_2                     561
#define OBJ_EVENT_GFX_LASS_3                     562
#define OBJ_EVENT_GFX_LEAF_1                     563
#define OBJ_EVENT_GFX_LEON                       564
#define OBJ_EVENT_GFX_LEONORA                    565
#define OBJ_EVENT_GFX_LINEBACKER                 566
#define OBJ_EVENT_GFX_LIZA_1                     567
#define OBJ_EVENT_GFX_LORELAI_1                  568
#define OBJ_EVENT_GFX_LORETTA                    569
#define OBJ_EVENT_GFX_LT_SURGE_1                 570
#define OBJ_EVENT_GFX_LUCIAN                     571
#define OBJ_EVENT_GFX_LYRA                       572
#define OBJ_EVENT_GFX_MAID_1                     573
#define OBJ_EVENT_GFX_MAID_2                     574
#define OBJ_EVENT_GFX_MAN_6                      575
#define OBJ_EVENT_GFX_MAN_7                      576
#define OBJ_EVENT_GFX_MAN_8                      577
#define OBJ_EVENT_GFX_MARLIN_SWIM                578
#define OBJ_EVENT_GFX_MARLIN                     579
#define OBJ_EVENT_GFX_MARNIE                     580
#define OBJ_EVENT_GFX_MARSHALL                   581
#define OBJ_EVENT_GFX_MAYLENE                    582
#define OBJ_EVENT_GFX_MEDAL_GUY                  583
#define OBJ_EVENT_GFX_MEDIUM                     584
#define OBJ_EVENT_GFX_MISTY_1                    585
#define OBJ_EVENT_GFX_MORTY                      586
#define OBJ_EVENT_GFX_N                          587
#define OBJ_EVENT_GFX_NEMONA                     588
#define OBJ_EVENT_GFX_NEO_GHETHIS_CANE           589
#define OBJ_EVENT_GFX_NEO_GHETHIS                590
#define OBJ_EVENT_GFX_NEO_PLASMA_F               591
#define OBJ_EVENT_GFX_NEO_PLASMA_M               592
#define OBJ_EVENT_GFX_NEO_ZINZOLIN               593
#define OBJ_EVENT_GFX_NESSA                      594
#define OBJ_EVENT_GFX_NINJA_BOY_1                595
#define OBJ_EVENT_GFX_NORMAN_1                   596
#define OBJ_EVENT_GFX_NURSE_1                    597
#define OBJ_EVENT_GFX_NURSE_JOY                  598
#define OBJ_EVENT_GFX_NURSE_JOY_WALK             599
#define OBJ_EVENT_GFX_NURSERY_AIDE               600
#define OBJ_EVENT_GFX_OAK                        601
#define OBJ_EVENT_GFX_OLD_WOMAN_1                602
#define OBJ_EVENT_GFX_OTNAR                      603
#define OBJ_EVENT_GFX_PARASOL_LADY_1             604
#define OBJ_EVENT_GFX_PARASOL_LADY_2             605
#define OBJ_EVENT_GFX_PERRIN                     606
#define OBJ_EVENT_GFX_PETER                      607
#define OBJ_EVENT_GFX_PICNICKER_1                608
#define OBJ_EVENT_GFX_PIERS                      609
#define OBJ_EVENT_GFX_PILOT                      610
#define OBJ_EVENT_GFX_POKEFAN_F_1                611
#define OBJ_EVENT_GFX_POKEFAN_F_2                612
#define OBJ_EVENT_GFX_POKEFAN_M_1                613
#define OBJ_EVENT_GFX_POKEFAN_M_2                614
#define OBJ_EVENT_GFX_POKEKID                    615
#define OBJ_EVENT_GFX_POKEMANIAC                 616
#define OBJ_EVENT_GFX_POKEMART                   617
#define OBJ_EVENT_GFX_POLICEMAN_1                618
#define OBJ_EVENT_GFX_POLICEMAN_2                619
#define OBJ_EVENT_GFX_POSTMAN                    620
#define OBJ_EVENT_GFX_PRESCHOOLER_F              621
#define OBJ_EVENT_GFX_PRESCHOOLER_M              622
#define OBJ_EVENT_GFX_PROF_UNICORN               623
#define OBJ_EVENT_GFX_PRYCE                      624
#define OBJ_EVENT_GFX_PSYCHIC_F_1                625
#define OBJ_EVENT_GFX_PSYCHIC_F_2                626
#define OBJ_EVENT_GFX_PSYCHIC_M_1                627
#define OBJ_EVENT_GFX_PSYCHIC_M_2                628
#define OBJ_EVENT_GFX_PUNK_GUY                   629
#define OBJ_EVENT_GFX_RANCHER                    630
#define OBJ_EVENT_GFX_RANGER_F_1                 631
#define OBJ_EVENT_GFX_RANGER_F_2                 632
#define OBJ_EVENT_GFX_RANGER_M_1                 633
#define OBJ_EVENT_GFX_RANGER_M_2                 634
#define OBJ_EVENT_GFX_RECEPTIONIST_1             635
#define OBJ_EVENT_GFX_RECEPTIONIST_2             636
#define OBJ_EVENT_GFX_RECEPTIONIST_3             637
#define OBJ_EVENT_GFX_RECEPTIONIST_4             638
#define OBJ_EVENT_GFX_REPORTER                   639
#define OBJ_EVENT_GFX_RICH_BOY_1                 640
#define OBJ_EVENT_GFX_RICH_BOY_2                 641
#define OBJ_EVENT_GFX_RICH_MAN                   642
#define OBJ_EVENT_GFX_ROARK                      643
#define OBJ_EVENT_GFX_ROUGHNECK_1                644
#define OBJ_EVENT_GFX_ROUGHNECK_2                645
#define OBJ_EVENT_GFX_ROUGHNECK_2_FIGHT          646
#define OBJ_EVENT_GFX_ROXANNE_1                  647
#define OBJ_EVENT_GFX_ROXIE                      648
#define OBJ_EVENT_GFX_ROXIE_GUITAR               649
#define OBJ_EVENT_GFX_RUIN_MANIAC                650
#define OBJ_EVENT_GFX_RYME                       651
#define OBJ_EVENT_GFX_SABRINA_1                  652
#define OBJ_EVENT_GFX_SAGE_BRONIUS               653
#define OBJ_EVENT_GFX_SAGE_GIALLO                654
#define OBJ_EVENT_GFX_SAGE_GORM                  655
#define OBJ_EVENT_GFX_SAGE_ROOD                  656
#define OBJ_EVENT_GFX_SAGE_RYOKU                 657
#define OBJ_EVENT_GFX_SAGE                       658
#define OBJ_EVENT_GFX_SAILOR_1                   659
#define OBJ_EVENT_GFX_SCHOOLKID_F                660
#define OBJ_EVENT_GFX_SCHOOLKID_M_1              661
#define OBJ_EVENT_GFX_SCIENTIST_F                662
#define OBJ_EVENT_GFX_SCIENTIST_M_1              663
#define OBJ_EVENT_GFX_SCIENTIST_M_2              664
#define OBJ_EVENT_GFX_SCIENTIST_M_3              665
#define OBJ_EVENT_GFX_SEAN                       666
#define OBJ_EVENT_GFX_SERENA                     667
#define OBJ_EVENT_GFX_SHADOW_TRIAD               668
#define OBJ_EVENT_GFX_SHADY_GUY                  669
#define OBJ_EVENT_GFX_SHAUNTAL                   670
#define OBJ_EVENT_GFX_SIDNEY_1                   671
#define OBJ_EVENT_GFX_SINGER                     672
#define OBJ_EVENT_GFX_SKIER_F_1                  673
#define OBJ_EVENT_GFX_SKIER_F_2                  674
#define OBJ_EVENT_GFX_SKIER_M                    675
#define OBJ_EVENT_GFX_SKYLA                      676
#define OBJ_EVENT_GFX_SMASHER                    677
#define OBJ_EVENT_GFX_SOCIALITE_1                678
#define OBJ_EVENT_GFX_SOCIALITE_2                679
#define OBJ_EVENT_GFX_STRIKER                    680
#define OBJ_EVENT_GFX_SUPERNERD                  681
#define OBJ_EVENT_GFX_SWIMMER_F_1                682
#define OBJ_EVENT_GFX_SWIMMER_F_2                683
#define OBJ_EVENT_GFX_SWIMMER_F_3                684
#define OBJ_EVENT_GFX_SWIMMER_M_1                685
#define OBJ_EVENT_GFX_SWIMMER_M_2                686
#define OBJ_EVENT_GFX_SWIMMER_M_3                687
#define OBJ_EVENT_GFX_TATE_1                     688
#define OBJ_EVENT_GFX_TEACHER                    689
#define OBJ_EVENT_GFX_TEAM_PLASMA_F              690
#define OBJ_EVENT_GFX_TEAM_PLASMA_M              691
#define OBJ_EVENT_GFX_TOXIANNA                   692
#define OBJ_EVENT_GFX_TRUMPETER                  693
#define OBJ_EVENT_GFX_TUBER_F_1                  694
#define OBJ_EVENT_GFX_TUBER_M_1                  695
#define OBJ_EVENT_GFX_TWINS_1                    696
#define OBJ_EVENT_GFX_TWINS_2                    697
#define OBJ_EVENT_GFX_TWINS_3                    698
#define OBJ_EVENT_GFX_ULTIMA                     699
#define OBJ_EVENT_GFX_VETRAN_F                   700
#define OBJ_EVENT_GFX_VETRAN_M_1                 701
#define OBJ_EVENT_GFX_VETRAN_M_2                 702
#define OBJ_EVENT_GFX_VICTOR                     703
#define OBJ_EVENT_GFX_VIOLA                      704
#define OBJ_EVENT_GFX_VOLKNER                    705
#define OBJ_EVENT_GFX_WAITER_1                   706
#define OBJ_EVENT_GFX_WAITER_2                   707
#define OBJ_EVENT_GFX_WAITRESS_1                 708
#define OBJ_EVENT_GFX_WAITRESS_2                 709
#define OBJ_EVENT_GFX_WALLACE_1                  710
#define OBJ_EVENT_GFX_WATTSON_1                  711
#define OBJ_EVENT_GFX_WHITNEY                    712
#define OBJ_EVENT_GFX_WILL                       713
#define OBJ_EVENT_GFX_WINONA                     714
#define OBJ_EVENT_GFX_WOMAN_6                    715
#define OBJ_EVENT_GFX_WOMAN_7                    716
#define OBJ_EVENT_GFX_WOMAN_8                    717
#define OBJ_EVENT_GFX_WOMAN_9                    718
#define OBJ_EVENT_GFX_WOMAN_10                   719
#define OBJ_EVENT_GFX_WOMAN_11                   720
#define OBJ_EVENT_GFX_WORKER_1                   721
#define OBJ_EVENT_GFX_WORKER_2                   722
#define OBJ_EVENT_GFX_WORKER_3                   723
#define OBJ_EVENT_GFX_YANCY_1                    724
#define OBJ_EVENT_GFX_YANCY_2                    725
#define OBJ_EVENT_GFX_YOUNGSTER_1                726
#define OBJ_EVENT_GFX_YOUNGSTER_2                727
#define OBJ_EVENT_GFX_YOUNGSTER_3                728

// FRLG equivalents

// #define OBJ_EVENT_GFX_MEW OBJ_EVENT_GFX_NINJA_BOY
// #define OBJ_EVENT_GFX_LUGIA OBJ_EVENT_GFX_NINJA_BOY



// NOTE: The maximum amount of object events has been expanded from 255 to 65535.
// Since dynamic graphics ids still require at least 16 free values, the actual limit
// is 65519, but even considering follower Pokémon, this should be more than enough :)
#define NUM_OBJ_EVENT_GFX                        388


// These are dynamic object gfx ids.
// They correspond with the values of the VAR_OBJ_GFX_ID_X vars.
// More info about them in include/constants/vars.h
#define OBJ_EVENT_GFX_VARS   (NUM_OBJ_EVENT_GFX + 1)
#define OBJ_EVENT_GFX_VAR_0  (OBJ_EVENT_GFX_VARS + 0x0)
#define OBJ_EVENT_GFX_VAR_1  (OBJ_EVENT_GFX_VARS + 0x1)
#define OBJ_EVENT_GFX_VAR_2  (OBJ_EVENT_GFX_VARS + 0x2)
#define OBJ_EVENT_GFX_VAR_3  (OBJ_EVENT_GFX_VARS + 0x3)
#define OBJ_EVENT_GFX_VAR_4  (OBJ_EVENT_GFX_VARS + 0x4)
#define OBJ_EVENT_GFX_VAR_5  (OBJ_EVENT_GFX_VARS + 0x5)
#define OBJ_EVENT_GFX_VAR_6  (OBJ_EVENT_GFX_VARS + 0x6)
#define OBJ_EVENT_GFX_VAR_7  (OBJ_EVENT_GFX_VARS + 0x7)
#define OBJ_EVENT_GFX_VAR_8  (OBJ_EVENT_GFX_VARS + 0x8)
#define OBJ_EVENT_GFX_VAR_9  (OBJ_EVENT_GFX_VARS + 0x9)
#define OBJ_EVENT_GFX_VAR_A  (OBJ_EVENT_GFX_VARS + 0xA)
#define OBJ_EVENT_GFX_VAR_B  (OBJ_EVENT_GFX_VARS + 0xB)
#define OBJ_EVENT_GFX_VAR_C  (OBJ_EVENT_GFX_VARS + 0xC)
#define OBJ_EVENT_GFX_VAR_D  (OBJ_EVENT_GFX_VARS + 0xD)
#define OBJ_EVENT_GFX_VAR_E  (OBJ_EVENT_GFX_VARS + 0xE)
#define OBJ_EVENT_GFX_VAR_F  (OBJ_EVENT_GFX_VARS + 0xF)

// Don't use (1u << 15) to avoid conflict with BLEND_IMMUNE_FLAG.
#define OBJ_EVENT_MON               (1u << 14)
#define OBJ_EVENT_MON_SHINY         (1u << 13)
#define OBJ_EVENT_MON_FEMALE        (1u << 12)
#define OBJ_EVENT_MON_SPECIES_MASK  (~(7u << 12))

// Used to call a specific species' follower graphics. Useful for static encounters.
#define OBJ_EVENT_GFX_SPECIES(name)                 (SPECIES_##name + OBJ_EVENT_MON)
#define OBJ_EVENT_GFX_SPECIES_SHINY(name)           (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY)
#define OBJ_EVENT_GFX_SPECIES_FEMALE(name)          (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_FEMALE)
#define OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(name)    (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY + OBJ_EVENT_MON_FEMALE)

#define OW_SPECIES(x) ((x)->graphicsId & OBJ_EVENT_MON_SPECIES_MASK)
#define OW_SHINY(x) ((x)->graphicsId & OBJ_EVENT_MON_SHINY)
#define OW_FEMALE(x) ((x)->graphicsId & OBJ_EVENT_MON_FEMALE)

// Whether Object Event is an OW pokemon
#define IS_OW_MON_OBJ(obj) ((obj)->graphicsId & OBJ_EVENT_MON)

#define SHADOW_SIZE_S       0
#define SHADOW_SIZE_M       1
#define SHADOW_SIZE_L       2
#define SHADOW_SIZE_NONE    3   // Originally SHADOW_SIZE_XL, which went unused due to shadowSize in ObjectEventGraphicsInfo being only 2 bits.

#define SHADOW_SIZE_XL_BATTLE_ONLY  SHADOW_SIZE_NONE    // Battle-only definition for XL shadow size.

#define F_INANIMATE                        (1 << 6)
#define F_DISABLE_REFLECTION_PALETTE_LOAD  (1 << 7)

#define TRACKS_NONE       0
#define TRACKS_FOOT       1
#define TRACKS_BIKE_TIRE  2
#define TRACKS_SLITHER    3
#define TRACKS_SPOT       4
#define TRACKS_BUG        5

#define LIGHT_TYPE_BALL             0
#define LIGHT_TYPE_PKMN_CENTER_SIGN 1
#define LIGHT_TYPE_POKE_MART_SIGN   2

#define FIRST_DECORATION_SPRITE_GFX OBJ_EVENT_GFX_PICHU_DOLL

#define OBJ_KIND_NORMAL 0
#define OBJ_KIND_CLONE  255 // Exclusive to FRLG

// Special object event local ids
// Used for link player OWs in CreateLinkPlayerSprite
#define OBJ_EVENT_ID_DYNAMIC_BASE 0xF0

// Each object event template gets an ID that can be used to refer to it in scripts and elsewhere.
// This is referred to as the "local id" (and it's really just 1 + its index in the templates array).
// There are a few special IDs reserved for objects that don't have templates in the map data -- one for the player
// in regular offline play, five for linked players while playing Berry Blender, and one for an invisible object that
// can be spawned for the camera to track instead of the player. Additionally, the value 0 is reserved as an "empty" indicator.
#define LOCALID_NONE                         0
#define LOCALID_CAMERA                     127
#define LOCALID_BERRY_BLENDER_PLAYER_END   240 // This will use 5 (MAX_RFU_PLAYERS) IDs ending at 240, i.e. 236-240
#define LOCALID_FOLLOWING_POKEMON          254
#define LOCALID_PLAYER                     255
#define OBJ_EVENT_ID_FOLLOWER              0xFE
#define OBJ_EVENT_ID_NPC_FOLLOWER          0xFD

// Aliases for old names. "object event id" normally refers to an index into gObjectEvents, which these are not.
// Used for link player OWs in CreateLinkPlayerSprite
#define OBJ_EVENT_ID_DYNAMIC_BASE 0xF0
#define OBJ_EVENT_ID_CAMERA LOCALID_CAMERA
#define OBJ_EVENT_ID_PLAYER LOCALID_PLAYER

// Moved from src/event_object_movement.c so that they're accesible from other files.
#define OBJ_EVENT_PAL_TAG_BRENDAN                 0x1100
#define OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION      0x1101
#define OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION       0x1102
#define OBJ_EVENT_PAL_TAG_NPC_1                   0x1103
#define OBJ_EVENT_PAL_TAG_NPC_2                   0x1104
#define OBJ_EVENT_PAL_TAG_NPC_3                   0x1105
#define OBJ_EVENT_PAL_TAG_NPC_4                   0x1106
#define OBJ_EVENT_PAL_TAG_NPC_5                   0x1107
#define OBJ_EVENT_PAL_TAG_NPC_6                   0x1108
#define OBJ_EVENT_PAL_TAG_NPC_7                   0x1109
#define OBJ_EVENT_PAL_TAG_NPC_8                   0x110A
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP            0x110B
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION 0x110C
#define OBJ_EVENT_PAL_TAG_TRUCK                   0x110D
#define OBJ_EVENT_PAL_TAG_VIGOROTH                0x110E
#define OBJ_EVENT_PAL_TAG_ZIGZAGOON               0x110F
#define OBJ_EVENT_PAL_TAG_MAY                     0x1110
#define OBJ_EVENT_PAL_TAG_MAY_REFLECTION          0x1111
#define OBJ_EVENT_PAL_TAG_MOVING_BOX              0x1112
#define OBJ_EVENT_PAL_TAG_CABLE_CAR               0x1113
#define OBJ_EVENT_PAL_TAG_SSTIDAL                 0x1114
#define OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER       0x1115
#define OBJ_EVENT_PAL_TAG_KYOGRE                  0x1116
#define OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION       0x1117
#define OBJ_EVENT_PAL_TAG_GROUDON                 0x1118
#define OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION      0x1119
#define OBJ_EVENT_PAL_TAG_UNUSED                  0x111A
#define OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW        0x111B
#define OBJ_EVENT_PAL_TAG_POOCHYENA               0x111C
#define OBJ_EVENT_PAL_TAG_RED_LEAF                0x111D
#define OBJ_EVENT_PAL_TAG_DEOXYS                  0x111E
#define OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE      0x111F
#define OBJ_EVENT_PAL_TAG_HO_OH                   0x1120
#define OBJ_EVENT_PAL_TAG_LUGIA                   0x1121
#define OBJ_EVENT_PAL_TAG_RS_BRENDAN              0x1122
#define OBJ_EVENT_PAL_TAG_RS_MAY                  0x1123
#define OBJ_EVENT_PAL_TAG_DYNAMIC                 0x1124
#define OBJ_EVENT_PAL_TAG_PLAYER_RED              0x1125
#define OBJ_EVENT_PAL_TAG_PLAYER_RED_REFLECTION   0x1126
#define OBJ_EVENT_PAL_TAG_PLAYER_GREEN            0x1127
#define OBJ_EVENT_PAL_TAG_PLAYER_GREEN_REFLECTION 0x1128
#define OBJ_EVENT_PAL_TAG_NPC_BLUE                0x1129
#define OBJ_EVENT_PAL_TAG_NPC_PINK                0x112A
#define OBJ_EVENT_PAL_TAG_NPC_GREEN               0x112B
#define OBJ_EVENT_PAL_TAG_NPC_WHITE               0x112C
#define OBJ_EVENT_PAL_TAG_NPC_BLUE_REFLECTION     0x112D
#define OBJ_EVENT_PAL_TAG_NPC_PINK_REFLECTION     0x112E
#define OBJ_EVENT_PAL_TAG_NPC_GREEN_REFLECTION    0x112F
#define OBJ_EVENT_PAL_TAG_NPC_WHITE_REFLECTION    0x1130
#define OBJ_EVENT_PAL_TAG_METEORITE               0x1131
#define OBJ_EVENT_PAL_TAG_SEAGALLOP               0x1132
#define OBJ_EVENT_PAL_TAG_SS_ANNE                 0x1133
#define OBJ_EVENT_PAL_TAG_DAWN                    0x1134
#define OBJ_EVENT_PAL_TAG_LUCAS                   0x1135
#define OBJ_EVENT_PAL_TAG_DAWN_LUCAS_UNDERWATER   0x1136
#define OBJ_EVENT_PAL_TAG_ADHIRA                  0x1137
#define OBJ_EVENT_PAL_TAG_AHAB                    0x1138
#define OBJ_EVENT_PAL_TAG_CARLY                   0x1139
#define OBJ_EVENT_PAL_TAG_ISRAEL                  0x1140
#define OBJ_EVENT_PAL_TAG_JELISSA                 0x1141
#define OBJ_EVENT_PAL_TAG_JOSH                    0x1142
#define OBJ_EVENT_PAL_TAG_OTNAR                   0x1143
#define OBJ_EVENT_PAL_TAG_PETER                   0x1144
#define OBJ_EVENT_PAL_TAG_TOXIANNA                0x1145
#define OBJ_EVENT_PAL_TAG_AMELIA                  0x1146
#define OBJ_EVENT_PAL_TAG_AUDREY                  0x1147
#define OBJ_EVENT_PAL_TAG_BELLIS                  0x1148
#define OBJ_EVENT_PAL_TAG_CARTER                  0x1149
#define OBJ_EVENT_PAL_TAG_HOBIE                   0x1150
#define OBJ_EVENT_PAL_TAG_JUNKO                   0x1151
#define OBJ_EVENT_PAL_TAG_LORETTA                 0x1152
#define OBJ_EVENT_PAL_TAG_PROF_UNICORN            0x1153
#define OBJ_EVENT_PAL_TAG_SEAN                    0x1154

#if OW_FOLLOWERS_POKEBALLS
// Vanilla
#define OBJ_EVENT_PAL_TAG_BALL_MASTER             0x1150
#define OBJ_EVENT_PAL_TAG_BALL_ULTRA              0x1151
#define OBJ_EVENT_PAL_TAG_BALL_GREAT              0x1152
#define OBJ_EVENT_PAL_TAG_BALL_SAFARI             0x1153
#define OBJ_EVENT_PAL_TAG_BALL_NET                0x1154
#define OBJ_EVENT_PAL_TAG_BALL_DIVE               0x1155
#define OBJ_EVENT_PAL_TAG_BALL_NEST               0x1156
#define OBJ_EVENT_PAL_TAG_BALL_REPEAT             0x1157
#define OBJ_EVENT_PAL_TAG_BALL_TIMER              0x1158
#define OBJ_EVENT_PAL_TAG_BALL_LUXURY             0x1159
#define OBJ_EVENT_PAL_TAG_BALL_PREMIER            0x115A
// Gen IV/Sinnoh
#define OBJ_EVENT_PAL_TAG_BALL_DUSK               0x115B
#define OBJ_EVENT_PAL_TAG_BALL_HEAL               0x115C
#define OBJ_EVENT_PAL_TAG_BALL_QUICK              0x115D
#define OBJ_EVENT_PAL_TAG_BALL_CHERISH            0x115E
#define OBJ_EVENT_PAL_TAG_BALL_PARK               0x115F
// Gen II/Johto Apricorns
#define OBJ_EVENT_PAL_TAG_BALL_FAST               0x1160
#define OBJ_EVENT_PAL_TAG_BALL_LEVEL              0x1161
#define OBJ_EVENT_PAL_TAG_BALL_LURE               0x1162
#define OBJ_EVENT_PAL_TAG_BALL_HEAVY              0x1163
#define OBJ_EVENT_PAL_TAG_BALL_LOVE               0x1164
#define OBJ_EVENT_PAL_TAG_BALL_FRIEND             0x1165
#define OBJ_EVENT_PAL_TAG_BALL_MOON               0x1166
#define OBJ_EVENT_PAL_TAG_BALL_SPORT              0x1167
// Gen V
#define OBJ_EVENT_PAL_TAG_BALL_DREAM              0x1168
// Gen VII
#define OBJ_EVENT_PAL_TAG_BALL_BEAST              0x1169
// Gen VIII
#define OBJ_EVENT_PAL_TAG_BALL_STRANGE            0x116A
#endif //OW_FOLLOWERS_POKEBALLS
// Used as a placeholder follower graphic
#define OBJ_EVENT_PAL_TAG_SUBSTITUTE              0x7611
#define OBJ_EVENT_PAL_TAG_LIGHT                   0x8001
#define OBJ_EVENT_PAL_TAG_LIGHT_2                 0x8002
#define OBJ_EVENT_PAL_TAG_EMOTES                  0x8003
#define OBJ_EVENT_PAL_TAG_NEON_LIGHT              0x8004
// Not a real OW palette tag; used for the white flash applied to followers
#define OBJ_EVENT_PAL_TAG_WHITE                   (OBJ_EVENT_PAL_TAG_NONE - 1)
#define OBJ_EVENT_PAL_TAG_NONE                    0x11FF

// This + localId is used as the tileTag
// for compressed graphicsInfos
// '(C)ompressed (E)vent'
#define COMP_OW_TILE_TAG_BASE 0xCE00

#endif  // GUARD_CONSTANTS_EVENT_OBJECTS_H
