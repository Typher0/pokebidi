#ifndef GUARD_CONSTANTS_ITEMS_H
#define GUARD_CONSTANTS_ITEMS_H

#define ITEM_NONE 0

// Poké Balls
#define ITEM_POKE_BALL 1
#define ITEM_GREAT_BALL 2
#define ITEM_ULTRA_BALL 3
#define ITEM_MASTER_BALL 4
#define ITEM_PREMIER_BALL 5
#define ITEM_HEAL_BALL 6
#define ITEM_NET_BALL 7
#define ITEM_NEST_BALL 8
#define ITEM_DIVE_BALL 9
#define ITEM_DUSK_BALL 10
#define ITEM_TIMER_BALL 11
#define ITEM_QUICK_BALL 12
#define ITEM_REPEAT_BALL 13
#define ITEM_LUXURY_BALL 14
#define ITEM_LEVEL_BALL 15
#define ITEM_LURE_BALL 16
#define ITEM_MOON_BALL 17
#define ITEM_FRIEND_BALL 18
#define ITEM_LOVE_BALL 19
#define ITEM_FAST_BALL 20
#define ITEM_HEAVY_BALL 21
#define ITEM_DREAM_BALL 22
#define ITEM_SAFARI_BALL 23
#define ITEM_SPORT_BALL 24
#define ITEM_PARK_BALL 25
#define ITEM_BEAST_BALL 26
#define ITEM_CHERISH_BALL 27

// Note: If moving ball IDs around, updating FIRST_BALL/LAST_BALL is not sufficient
//       Several places expect the ball IDs to be first and contiguous (e.g. MON_DATA_POKEBALL)
//       If adding new balls, it's easiest to insert them after the last ball and increment the below IDs (and removing ITEM_034 for example)
#define FIRST_BALL ITEM_POKE_BALL
#define LAST_BALL  ITEM_CHERISH_BALL

// Medicine
#define ITEM_POTION 28
#define ITEM_SUPER_POTION 29
#define ITEM_HYPER_POTION 30
#define ITEM_MAX_POTION 31
#define ITEM_FULL_RESTORE 32
#define ITEM_REVIVE 33
#define ITEM_MAX_REVIVE 34
#define ITEM_FRESH_WATER 35
#define ITEM_SODA_POP 36
#define ITEM_LEMONADE 37
#define ITEM_MOOMOO_MILK 38
#define ITEM_ENERGY_POWDER 39
#define ITEM_ENERGYPOWDER ITEM_ENERGY_POWDER // Pre-Gen VI name
#define ITEM_ENERGY_ROOT 40
#define ITEM_HEAL_POWDER 41
#define ITEM_REVIVAL_HERB 42
#define ITEM_ANTIDOTE 43
#define ITEM_PARALYZE_HEAL 44
#define ITEM_PARLYZ_HEAL ITEM_PARALYZE_HEAL // Pre-Gen VI name
#define ITEM_BURN_HEAL 45
#define ITEM_ICE_HEAL 46
#define ITEM_AWAKENING 47
#define ITEM_FULL_HEAL 48
#define ITEM_ETHER 49
#define ITEM_MAX_ETHER 50
#define ITEM_ELIXIR 51
#define ITEM_ELIXER ITEM_ELIXIR // Pre-Gen III name
#define ITEM_MAX_ELIXIR 52
#define ITEM_MAX_ELIXER ITEM_MAX_ELIXIR // Pre-Gen III name
#define ITEM_BERRY_JUICE 53
#define ITEM_SACRED_ASH 54
#define ITEM_SWEET_HEART 55
#define ITEM_MAX_HONEY 56

// Regional Specialties
#define ITEM_PEWTER_CRUNCHIES 57
#define ITEM_RAGE_CANDY_BAR 58
#define ITEM_RAGECANDYBAR ITEM_RAGE_CANDY_BAR // Pre-Gen VI name
#define ITEM_LAVA_COOKIE 59
#define ITEM_OLD_GATEAU 60
#define ITEM_CASTELIACONE 61
#define ITEM_LUMIOSE_GALETTE 62
#define ITEM_SHALOUR_SABLE 63
#define ITEM_BIG_MALASADA 64
#define ITEM_CAMPFIRE_CURRY 65
#define ITEM_SANDWICH 66
#define ITEM_CABRILLO_FUDGE 67

// Vitamins
#define ITEM_HP_UP 68
#define ITEM_PROTEIN 69
#define ITEM_IRON 70
#define ITEM_CALCIUM 71
#define ITEM_ZINC 72
#define ITEM_CARBOS 73
#define ITEM_PP_UP 74
#define ITEM_PP_MAX 75

// EV Feathers
#define ITEM_HEALTH_FEATHER 76
#define ITEM_HEALTH_WING ITEM_HEALTH_FEATHER // Pre-Gen VIII name
#define ITEM_MUSCLE_FEATHER 77
#define ITEM_MUSCLE_WING ITEM_MUSCLE_FEATHER // Pre-Gen VIII name
#define ITEM_RESIST_FEATHER 78
#define ITEM_RESIST_WING ITEM_RESIST_FEATHER // Pre-Gen VIII name
#define ITEM_GENIUS_FEATHER 79
#define ITEM_GENIUS_WING ITEM_GENIUS_FEATHER // Pre-Gen VIII name
#define ITEM_CLEVER_FEATHER 80
#define ITEM_CLEVER_WING ITEM_CLEVER_FEATHER // Pre-Gen VIII name
#define ITEM_SWIFT_FEATHER 81
#define ITEM_SWIFT_WING ITEM_SWIFT_FEATHER // Pre-Gen VIII name

// Ability Modifiers
#define ITEM_ABILITY_CAPSULE 82
#define ITEM_ABILITY_PATCH 83

// Mints
#define ITEM_LONELY_MINT 84
#define ITEM_ADAMANT_MINT 85
#define ITEM_NAUGHTY_MINT 86
#define ITEM_BRAVE_MINT 87
#define ITEM_BOLD_MINT 88
#define ITEM_IMPISH_MINT 89
#define ITEM_LAX_MINT 90
#define ITEM_RELAXED_MINT 91
#define ITEM_MODEST_MINT 92
#define ITEM_MILD_MINT 93
#define ITEM_RASH_MINT 94
#define ITEM_QUIET_MINT 95
#define ITEM_CALM_MINT 96
#define ITEM_GENTLE_MINT 97
#define ITEM_CAREFUL_MINT 98
#define ITEM_SASSY_MINT 99
#define ITEM_TIMID_MINT 100
#define ITEM_HASTY_MINT 101
#define ITEM_JOLLY_MINT 102
#define ITEM_NAIVE_MINT 103
#define ITEM_SERIOUS_MINT 104

// Candy
#define ITEM_RARE_CANDY 105
#define ITEM_EXP_CANDY_XS 106
#define ITEM_EXP_CANDY_S 107
#define ITEM_EXP_CANDY_M 108
#define ITEM_EXP_CANDY_L 109
#define ITEM_EXP_CANDY_XL 110
#define ITEM_DYNAMAX_CANDY 111

// Medicinal Flutes
#define ITEM_BLUE_FLUTE 112
#define ITEM_YELLOW_FLUTE 113
#define ITEM_RED_FLUTE 114

// Encounter-modifying Flutes
#define ITEM_BLACK_FLUTE 115
#define ITEM_WHITE_FLUTE 116

// Encounter Modifiers
#define ITEM_REPEL 117
#define ITEM_SUPER_REPEL 118
#define ITEM_MAX_REPEL 119
#define ITEM_LURE 120
#define ITEM_SUPER_LURE 121
#define ITEM_MAX_LURE 122

#define ITEM_ESCAPE_ROPE 123

// X Items
#define ITEM_X_ATTACK 124
#define ITEM_X_DEFENSE 125
#define ITEM_X_DEFEND ITEM_X_DEFENSE // Pre-Gen VI name
#define ITEM_X_SP_ATK 126
#define ITEM_X_SPECIAL ITEM_X_SP_ATK // Pre-Gen VI name
#define ITEM_X_SP_DEF 127
#define ITEM_X_SPEED 128
#define ITEM_X_ACCURACY 129

#define ITEM_DIRE_HIT 130
#define ITEM_GUARD_SPEC 131

// Escape Items
#define ITEM_POKE_DOLL 132
#define ITEM_FLUFFY_TAIL 133
#define ITEM_POKE_TOY 134

#define ITEM_MAX_MUSHROOMS 135

// Treasures
#define ITEM_BOTTLE_CAP 136
#define ITEM_GOLD_BOTTLE_CAP 137
#define ITEM_NUGGET 138
#define ITEM_BIG_NUGGET 139
#define ITEM_TINY_MUSHROOM 140
#define ITEM_TINYMUSHROOM ITEM_TINY_MUSHROOM // Pre-Gen VI name
#define ITEM_BIG_MUSHROOM 141
#define ITEM_BALM_MUSHROOM 142
#define ITEM_BALMMUSHROOM ITEM_BALM_MUSHROOM // Pre-Gen VI name
#define ITEM_PEARL 143
#define ITEM_BIG_PEARL 144
#define ITEM_PEARL_STRING 145
#define ITEM_STARDUST 146
#define ITEM_STAR_PIECE 147
#define ITEM_COMET_SHARD 148
#define ITEM_SHOAL_SALT 149
#define ITEM_SHOAL_SHELL 150
#define ITEM_RED_SHARD 151
#define ITEM_BLUE_SHARD 152
#define ITEM_YELLOW_SHARD 153
#define ITEM_GREEN_SHARD 154
#define ITEM_HEART_SCALE 155
#define ITEM_HONEY 156
#define ITEM_RARE_BONE 157
#define ITEM_ODD_KEYSTONE 158
#define ITEM_PRETTY_FEATHER 159
#define ITEM_PRETTY_WING ITEM_PRETTY_FEATHER // Pre-Gen VIII name
#define ITEM_RELIC_COPPER 160
#define ITEM_RELIC_SILVER 161
#define ITEM_RELIC_GOLD 162
#define ITEM_RELIC_VASE 163
#define ITEM_RELIC_BAND 164
#define ITEM_RELIC_STATUE 165
#define ITEM_RELIC_CROWN 166
#define ITEM_STRANGE_SOUVENIR 167

// Fossils
#define ITEM_HELIX_FOSSIL 168
#define ITEM_DOME_FOSSIL 169
#define ITEM_OLD_AMBER 170
#define ITEM_ROOT_FOSSIL 171
#define ITEM_CLAW_FOSSIL 172
#define ITEM_ARMOR_FOSSIL 173
#define ITEM_SKULL_FOSSIL 174
#define ITEM_COVER_FOSSIL 175
#define ITEM_PLUME_FOSSIL 176
#define ITEM_JAW_FOSSIL 177
#define ITEM_SAIL_FOSSIL 178
#define ITEM_FOSSILIZED_BIRD 179
#define ITEM_FOSSILIZED_FISH 180
#define ITEM_FOSSILIZED_DRAKE 181
#define ITEM_FOSSILIZED_DINO 182
#define ITEM_CLUB_FOSSIL 183
#define ITEM_LEAF_FOSSIL 184

// Mulch
#define ITEM_GROWTH_MULCH 185
#define ITEM_DAMP_MULCH 186
#define ITEM_STABLE_MULCH 187
#define ITEM_GOOEY_MULCH 188
#define ITEM_RICH_MULCH 189
#define ITEM_SURPRISE_MULCH 190
#define ITEM_BOOST_MULCH 191
#define ITEM_AMAZE_MULCH 192

// Apricorns
#define ITEM_RED_APRICORN 193
#define ITEM_BLUE_APRICORN 194
#define ITEM_BLU_APRICORN ITEM_BLUE_APRICORN // Pre-Gen VI name
#define ITEM_YELLOW_APRICORN 195
#define ITEM_YLW_APRICORN ITEM_YELLOW_APRICORN // Pre-Gen VI name
#define ITEM_GREEN_APRICORN 196
#define ITEM_GRN_APRICORN ITEM_GREEN_APRICORN // Pre-Gen VI name
#define ITEM_PINK_APRICORN 197
#define ITEM_PNK_APRICORN ITEM_PINK_APRICORN // Pre-Gen VI name
#define ITEM_WHITE_APRICORN 198
#define ITEM_WHT_APRICORN ITEM_WHITE_APRICORN // Pre-Gen VI name
#define ITEM_BLACK_APRICORN 199
#define ITEM_BLK_APRICORN ITEM_BLACK_APRICORN // Pre-Gen VI name

#define ITEM_WISHING_PIECE 200
#define ITEM_GALARICA_TWIG 201
#define ITEM_ARMORITE_ORE 202
#define ITEM_DYNITE_ORE 203

// Mail
#define ITEM_ORANGE_MAIL 204
#define ITEM_HARBOR_MAIL 205
#define ITEM_GLITTER_MAIL 206
#define ITEM_MECH_MAIL 207
#define ITEM_WOOD_MAIL 208
#define ITEM_WAVE_MAIL 209
#define ITEM_BEAD_MAIL 210
#define ITEM_SHADOW_MAIL 212
#define ITEM_TROPIC_MAIL 213
#define ITEM_DREAM_MAIL 214
#define ITEM_FAB_MAIL 215
#define ITEM_RETRO_MAIL 216

#define FIRST_MAIL_INDEX ITEM_ORANGE_MAIL

// Evolution Items
#define ITEM_FIRE_STONE 217
#define ITEM_WATER_STONE 218
#define ITEM_THUNDER_STONE 219
#define ITEM_THUNDERSTONE ITEM_THUNDER_STONE // Pre-Gen VI name
#define ITEM_LEAF_STONE 220
#define ITEM_ICE_STONE 221
#define ITEM_SUN_STONE 222
#define ITEM_MOON_STONE 223
#define ITEM_SHINY_STONE 224
#define ITEM_DUSK_STONE 225
#define ITEM_DAWN_STONE 226
#define ITEM_SWEET_APPLE 227
#define ITEM_TART_APPLE 228
#define ITEM_CRACKED_POT 229
#define ITEM_CHIPPED_POT 230
#define ITEM_GALARICA_CUFF 231
#define ITEM_GALARICA_WREATH 232
#define ITEM_DRAGON_SCALE 233
#define ITEM_UPGRADE 234
#define ITEM_UP_GRADE ITEM_UPGRADE // Pre-Gen VIII name
#define ITEM_PROTECTOR 235
#define ITEM_ELECTIRIZER 236
#define ITEM_MAGMARIZER 237
#define ITEM_DUBIOUS_DISC 238
#define ITEM_REAPER_CLOTH 239
#define ITEM_PRISM_SCALE 240
#define ITEM_WHIPPED_DREAM 241
#define ITEM_SACHET 242
#define ITEM_OVAL_STONE 243
#define ITEM_STRAWBERRY_SWEET 244
#define ITEM_LOVE_SWEET 245
#define ITEM_BERRY_SWEET 246
#define ITEM_CLOVER_SWEET 247
#define ITEM_FLOWER_SWEET 248
#define ITEM_STAR_SWEET 249
#define ITEM_RIBBON_SWEET 250

#define ITEM_EVERSTONE 251

// Nectars
#define ITEM_RED_NECTAR 252
#define ITEM_YELLOW_NECTAR 253
#define ITEM_PINK_NECTAR 254
#define ITEM_PURPLE_NECTAR 255

// Plates
#define ITEM_FLAME_PLATE 256
#define ITEM_SPLASH_PLATE 257
#define ITEM_ZAP_PLATE 258
#define ITEM_MEADOW_PLATE 259
#define ITEM_ICICLE_PLATE 260
#define ITEM_FIST_PLATE 261
#define ITEM_TOXIC_PLATE 262
#define ITEM_EARTH_PLATE 263
#define ITEM_SKY_PLATE 264
#define ITEM_MIND_PLATE 265
#define ITEM_INSECT_PLATE 266
#define ITEM_STONE_PLATE 267
#define ITEM_SPOOKY_PLATE 268
#define ITEM_DRACO_PLATE 269
#define ITEM_DREAD_PLATE 270
#define ITEM_IRON_PLATE 271
#define ITEM_PIXIE_PLATE 272
#define ITEM_SONAR_PLATE 273

// Drives
#define ITEM_DOUSE_DRIVE 274
#define ITEM_SHOCK_DRIVE 275
#define ITEM_BURN_DRIVE 276
#define ITEM_CHILL_DRIVE 277

// Memories
#define ITEM_FIRE_MEMORY 278
#define ITEM_WATER_MEMORY 279
#define ITEM_ELECTRIC_MEMORY 280
#define ITEM_GRASS_MEMORY 281
#define ITEM_ICE_MEMORY 282
#define ITEM_FIGHTING_MEMORY 283
#define ITEM_POISON_MEMORY 284
#define ITEM_GROUND_MEMORY 285
#define ITEM_FLYING_MEMORY 286
#define ITEM_PSYCHIC_MEMORY 287
#define ITEM_BUG_MEMORY 288
#define ITEM_ROCK_MEMORY 289
#define ITEM_GHOST_MEMORY 290
#define ITEM_DRAGON_MEMORY 291
#define ITEM_DARK_MEMORY 292
#define ITEM_STEEL_MEMORY 293
#define ITEM_FAIRY_MEMORY 294
#define ITEM_SOUND_MEMORY 295

#define ITEM_RUSTED_SWORD 296
#define ITEM_RUSTED_SHIELD 297

// Colored Orbs
#define ITEM_RED_ORB 298
#define ITEM_BLUE_ORB 299

// Mega Stones
#define ITEM_VENUSAURITE 300
#define ITEM_CHARIZARDITE_X 301
#define ITEM_CHARIZARDITE_Y 302
#define ITEM_BLASTOISINITE 303
#define ITEM_BEEDRILLITE 304
#define ITEM_PIDGEOTITE 305
#define ITEM_ALAKAZITE 306
#define ITEM_SLOWBRONITE 307
#define ITEM_GENGARITE 308
#define ITEM_KANGASKHANITE 309
#define ITEM_PINSIRITE 310
#define ITEM_GYARADOSITE 311
#define ITEM_AERODACTYLITE 312
#define ITEM_MEWTWONITE_X 313
#define ITEM_MEWTWONITE_Y 314
#define ITEM_AMPHAROSITE 315
#define ITEM_STEELIXITE 316
#define ITEM_SCIZORITE 317
#define ITEM_HERACRONITE 318
#define ITEM_HOUNDOOMINITE 319
#define ITEM_TYRANITARITE 320
#define ITEM_SCEPTILITE 321
#define ITEM_BLAZIKENITE 322
#define ITEM_SWAMPERTITE 323
#define ITEM_GARDEVOIRITE 324
#define ITEM_SABLENITE 325
#define ITEM_MAWILITE 326
#define ITEM_AGGRONITE 327
#define ITEM_MEDICHAMITE 328
#define ITEM_MANECTITE 329
#define ITEM_SHARPEDONITE 330
#define ITEM_CAMERUPTITE 331
#define ITEM_ALTARIANITE 332
#define ITEM_BANETTITE 333
#define ITEM_ABSOLITE 334
#define ITEM_GLALITITE 335
#define ITEM_SALAMENCITE 336
#define ITEM_METAGROSSITE 337
#define ITEM_LATIASITE 338
#define ITEM_LATIOSITE 339
#define ITEM_LOPUNNITE 340
#define ITEM_GARCHOMPITE 341
#define ITEM_LUCARIONITE 342
#define ITEM_ABOMASITE 343
#define ITEM_GALLADITE 344
#define ITEM_AUDINITE 345
#define ITEM_DIANCITE 346
#define ITEM_BUTTERFRINITE 347
#define ITEM_MACHAMPITE 348
#define ITEM_KINGLERITE 349
#define ITEM_LAPRASITE 350
#define ITEM_SNORLITE 351
#define ITEM_GARBODORITE 352
#define ITEM_RILLABITE 353
#define ITEM_CINDERACITE 354
#define ITEM_INTELEONITE 355
#define ITEM_CORVINITE 356
#define ITEM_ORBEETLITE 357
#define ITEM_DREDNITE 358
#define ITEM_COALOSSITE 359
#define ITEM_SANDACONDITE 360
#define ITEM_TOXTRICITE 361
#define ITEM_CENTISKITE 362
#define ITEM_HATTRENITE 363
#define ITEM_GRIMMSNITE 364
#define ITEM_ALCREMITE 365
#define ITEM_COPPERAJITE 366

// Gems
#define ITEM_NORMAL_GEM 367
#define ITEM_FIRE_GEM 368
#define ITEM_WATER_GEM 369
#define ITEM_ELECTRIC_GEM 370
#define ITEM_GRASS_GEM 371
#define ITEM_ICE_GEM 372
#define ITEM_FIGHTING_GEM 373
#define ITEM_POISON_GEM 374
#define ITEM_GROUND_GEM 375
#define ITEM_FLYING_GEM 376
#define ITEM_PSYCHIC_GEM 377
#define ITEM_BUG_GEM 378
#define ITEM_ROCK_GEM 379
#define ITEM_GHOST_GEM 380
#define ITEM_DRAGON_GEM 381
#define ITEM_DARK_GEM 382
#define ITEM_STEEL_GEM 383
#define ITEM_FAIRY_GEM 384
#define ITEM_SOUND_GEM 385

// Z-Crystals
#define ITEM_NORMALIUM_Z 386
#define ITEM_FIRIUM_Z 387
#define ITEM_WATERIUM_Z 388
#define ITEM_ELECTRIUM_Z 389
#define ITEM_GRASSIUM_Z 390
#define ITEM_ICIUM_Z 391
#define ITEM_FIGHTINIUM_Z 392
#define ITEM_POISONIUM_Z 393
#define ITEM_GROUNDIUM_Z 394
#define ITEM_FLYINIUM_Z 395
#define ITEM_PSYCHIUM_Z 396
#define ITEM_BUGINIUM_Z 397
#define ITEM_ROCKIUM_Z 398
#define ITEM_GHOSTIUM_Z 399
#define ITEM_DRAGONIUM_Z 400
#define ITEM_DARKINIUM_Z 401
#define ITEM_STEELIUM_Z 402
#define ITEM_FAIRIUM_Z 403
#define ITEM_SOUNDIUM_Z 404
#define ITEM_PIKANIUM_Z 405
#define ITEM_EEVIUM_Z 406
#define ITEM_SNORLIUM_Z 407
#define ITEM_MEWNIUM_Z 408
#define ITEM_DECIDIUM_Z 409
#define ITEM_INCINIUM_Z 410
#define ITEM_PRIMARIUM_Z 411
#define ITEM_LYCANIUM_Z 412
#define ITEM_MIMIKIUM_Z 413
#define ITEM_KOMMONIUM_Z 414
#define ITEM_TAPUNIUM_Z 415
#define ITEM_SOLGANIUM_Z 416
#define ITEM_LUNALIUM_Z 417
#define ITEM_MARSHADIUM_Z 418
#define ITEM_ALORAICHIUM_Z 419
#define ITEM_PIKASHUNIUM_Z 420
#define ITEM_ULTRANECROZIUM_Z 421

// Species-specific Held Items
#define ITEM_LIGHT_BALL 422
#define ITEM_LEEK 423
#define ITEM_STICK ITEM_LEEK // Pre-Gen VIII name
#define ITEM_THICK_CLUB 424
#define ITEM_LUCKY_PUNCH 425
#define ITEM_METAL_POWDER 426
#define ITEM_QUICK_POWDER 427
#define ITEM_DEEP_SEA_SCALE 428
#define ITEM_DEEPSEASCALE ITEM_DEEP_SEA_SCALE // Pre-Gen VI name
#define ITEM_DEEP_SEA_TOOTH 429
#define ITEM_DEEPSEATOOTH ITEM_DEEP_SEA_TOOTH // Pre-Gen VI name
#define ITEM_SOUL_DEW 430
#define ITEM_ADAMANT_ORB 431
#define ITEM_LUSTROUS_ORB 432
#define ITEM_GRISEOUS_ORB 433

// Incenses
#define ITEM_SEA_INCENSE 434
#define ITEM_LAX_INCENSE 435
#define ITEM_ODD_INCENSE 436
#define ITEM_ROCK_INCENSE 437
#define ITEM_FULL_INCENSE 438
#define ITEM_WAVE_INCENSE 439
#define ITEM_ROSE_INCENSE 430
#define ITEM_LUCK_INCENSE 431
#define ITEM_PURE_INCENSE 432

// Contest Scarves
#define ITEM_RED_SCARF 433
#define ITEM_BLUE_SCARF 434
#define ITEM_PINK_SCARF 435
#define ITEM_GREEN_SCARF 436
#define ITEM_YELLOW_SCARF 437

// EV Gain Modifiers
#define ITEM_MACHO_BRACE 438
#define ITEM_POWER_WEIGHT 439
#define ITEM_POWER_BRACER 440
#define ITEM_POWER_BELT 441
#define ITEM_POWER_LENS 442
#define ITEM_POWER_BAND 443
#define ITEM_POWER_ANKLET 444

// Type-boosting Held Items
#define ITEM_SILK_SCARF 445
#define ITEM_CHARCOAL 446
#define ITEM_MYSTIC_WATER 447
#define ITEM_MAGNET 448
#define ITEM_MIRACLE_SEED 449
#define ITEM_NEVER_MELT_ICE 450
#define ITEM_NEVERMELTICE ITEM_NEVER_MELT_ICE // Pre-Gen VI name
#define ITEM_BLACK_BELT 451
#define ITEM_BLACKBELT ITEM_BLACK_BELT // Gen II name
#define ITEM_POISON_BARB 452
#define ITEM_SOFT_SAND 453
#define ITEM_SHARP_BEAK 454
#define ITEM_TWISTED_SPOON 455
#define ITEM_TWISTEDSPOON ITEM_TWISTED_SPOON // Pre-Gen VI name
#define ITEM_SILVER_POWDER 456
#define ITEM_SILVERPOWDER ITEM_SILVER_POWDER // Pre-Gen VI name
#define ITEM_HARD_STONE 457
#define ITEM_SPELL_TAG 458
#define ITEM_DRAGON_FANG 459
#define ITEM_BLACK_GLASSES 460
#define ITEM_BLACKGLASSES ITEM_BLACK_GLASSES // Pre-Gen VI name
#define ITEM_METAL_COAT 461

// Choice Items
#define ITEM_CHOICE_BAND 462
#define ITEM_CHOICE_SPECS 463
#define ITEM_CHOICE_SCARF 464

// Status Orbs
#define ITEM_FLAME_ORB 465
#define ITEM_TOXIC_ORB 466

// Weather Rocks
#define ITEM_DAMP_ROCK 467
#define ITEM_HEAT_ROCK 468
#define ITEM_SMOOTH_ROCK 469
#define ITEM_ICY_ROCK 470

// Terrain Seeds
#define ITEM_ELECTRIC_SEED 471
#define ITEM_PSYCHIC_SEED 472
#define ITEM_MISTY_SEED 473
#define ITEM_GRASSY_SEED 474

// Type-activated Stat Modifiers
#define ITEM_ABSORB_BULB 475
#define ITEM_CELL_BATTERY 476
#define ITEM_LUMINOUS_MOSS 477
#define ITEM_SNOWBALL 478

// Misc. Held Items
#define ITEM_BRIGHT_POWDER 479
#define ITEM_BRIGHTPOWDER ITEM_BRIGHT_POWDER // Pre-Gen VI name
#define ITEM_WHITE_HERB 480
#define ITEM_EXP_SHARE 481
#define ITEM_EXP_ALL ITEM_EXP_SHARE // Gen I name
#define ITEM_QUICK_CLAW 482
#define ITEM_SOOTHE_BELL 483
#define ITEM_MENTAL_HERB 484
#define ITEM_KINGS_ROCK 485
#define ITEM_AMULET_COIN 486
#define ITEM_CLEANSE_TAG 487
#define ITEM_SMOKE_BALL 488
#define ITEM_FOCUS_BAND 489
#define ITEM_LUCKY_EGG 490
#define ITEM_SCOPE_LENS 491
#define ITEM_LEFTOVERS 492
#define ITEM_SHELL_BELL 493
#define ITEM_WIDE_LENS 494
#define ITEM_MUSCLE_BAND 495
#define ITEM_WISE_GLASSES 496
#define ITEM_EXPERT_BELT 497
#define ITEM_LIGHT_CLAY 498
#define ITEM_LIFE_ORB 499
#define ITEM_POWER_HERB 500
#define ITEM_FOCUS_SASH 501
#define ITEM_ZOOM_LENS 502
#define ITEM_METRONOME 503
#define ITEM_IRON_BALL 504
#define ITEM_LAGGING_TAIL 505
#define ITEM_DESTINY_KNOT 506
#define ITEM_BLACK_SLUDGE 507
#define ITEM_GRIP_CLAW 508
#define ITEM_STICKY_BARB 509
#define ITEM_SHED_SHELL 510
#define ITEM_BIG_ROOT 511
#define ITEM_RAZOR_CLAW 512
#define ITEM_RAZOR_FANG 513
#define ITEM_EVIOLITE 514
#define ITEM_FLOAT_STONE 515
#define ITEM_ROCKY_HELMET 516
#define ITEM_AIR_BALLOON 517
#define ITEM_RED_CARD 518
#define ITEM_RING_TARGET 519
#define ITEM_BINDING_BAND 520
#define ITEM_EJECT_BUTTON 521
#define ITEM_WEAKNESS_POLICY 522
#define ITEM_ASSAULT_VEST 523
#define ITEM_SAFETY_GOGGLES 524
#define ITEM_ADRENALINE_ORB 525
#define ITEM_TERRAIN_EXTENDER 526
#define ITEM_PROTECTIVE_PADS 527
#define ITEM_THROAT_SPRAY 528
#define ITEM_EJECT_PACK 529
#define ITEM_HEAVY_DUTY_BOOTS 530
#define ITEM_BLUNDER_POLICY 531
#define ITEM_ROOM_SERVICE 532
#define ITEM_UTILITY_UMBRELLA 533

// Berries
#if B_CONFUSE_BERRIES_HEAL >= GEN_8
    #define CONFUSE_BERRY_HEAL_FRACTION 3
#elif B_CONFUSE_BERRIES_HEAL == GEN_7
    #define CONFUSE_BERRY_HEAL_FRACTION 2
#else
    #define CONFUSE_BERRY_HEAL_FRACTION 8
#endif

#define CONFUSE_BERRY_HP_FRACTION ((B_CONFUSE_BERRIES_HEAL >= GEN_7) ? 4 : 2)

#define ITEM_CHERI_BERRY 534
#define ITEM_CHESTO_BERRY 535
#define ITEM_PECHA_BERRY 536
#define ITEM_RAWST_BERRY 537
#define ITEM_ASPEAR_BERRY 538
#define ITEM_LEPPA_BERRY 539
#define ITEM_ORAN_BERRY 540
#define ITEM_PERSIM_BERRY 541
#define ITEM_LUM_BERRY 542
#define ITEM_SITRUS_BERRY 543
#define ITEM_FIGY_BERRY 544
#define ITEM_WIKI_BERRY 545
#define ITEM_MAGO_BERRY 546
#define ITEM_AGUAV_BERRY 547
#define ITEM_IAPAPA_BERRY 548
#define ITEM_RAZZ_BERRY 549
#define ITEM_BLUK_BERRY 550
#define ITEM_NANAB_BERRY 551
#define ITEM_WEPEAR_BERRY 552
#define ITEM_PINAP_BERRY 553
#define ITEM_POMEG_BERRY 554
#define ITEM_KELPSY_BERRY 555
#define ITEM_QUALOT_BERRY 556
#define ITEM_HONDEW_BERRY 557
#define ITEM_GREPA_BERRY 558
#define ITEM_TAMATO_BERRY 559
#define ITEM_CORNN_BERRY 560
#define ITEM_MAGOST_BERRY 561
#define ITEM_RABUTA_BERRY 562
#define ITEM_NOMEL_BERRY 563
#define ITEM_SPELON_BERRY 564
#define ITEM_PAMTRE_BERRY 565
#define ITEM_WATMEL_BERRY 566
#define ITEM_DURIN_BERRY 567
#define ITEM_BELUE_BERRY 568
#define ITEM_CHILAN_BERRY 569
#define ITEM_OCCA_BERRY 570
#define ITEM_PASSHO_BERRY 571
#define ITEM_WACAN_BERRY 572
#define ITEM_RINDO_BERRY 573
#define ITEM_YACHE_BERRY 574
#define ITEM_CHOPLE_BERRY 575
#define ITEM_KEBIA_BERRY 576
#define ITEM_SHUCA_BERRY 577
#define ITEM_COBA_BERRY 578
#define ITEM_PAYAPA_BERRY 579
#define ITEM_TANGA_BERRY 580
#define ITEM_CHARTI_BERRY 581
#define ITEM_KASIB_BERRY 582
#define ITEM_HABAN_BERRY 583
#define ITEM_COLBUR_BERRY 584
#define ITEM_BABIRI_BERRY 585
#define ITEM_ROSELI_BERRY 586
#define ITEM_LIECHI_BERRY 587
#define ITEM_GANLON_BERRY 588
#define ITEM_SALAC_BERRY 589
#define ITEM_PETAYA_BERRY 590
#define ITEM_APICOT_BERRY 591
#define ITEM_LANSAT_BERRY 592
#define ITEM_STARF_BERRY 593
#define ITEM_ENIGMA_BERRY 594
#define ITEM_MICLE_BERRY 595
#define ITEM_CUSTAP_BERRY 596
#define ITEM_JABOCA_BERRY 597
#define ITEM_ROWAP_BERRY 598
#define ITEM_KEE_BERRY 599
#define ITEM_MARANGA_BERRY 600
#define ITEM_ENIGMA_BERRY_E_READER 601

#define FIRST_BERRY_INDEX ITEM_CHERI_BERRY
#define LAST_BERRY_INDEX  ITEM_ENIGMA_BERRY_E_READER

// TMs/HMs
#define ITEM_TM01 602
#define ITEM_TM02 603
#define ITEM_TM03 604
#define ITEM_TM04 605
#define ITEM_TM05 606
#define ITEM_TM06 607
#define ITEM_TM07 608
#define ITEM_TM08 609
#define ITEM_TM09 610
#define ITEM_TM10 611
#define ITEM_TM11 612
#define ITEM_TM12 613
#define ITEM_TM13 614
#define ITEM_TM14 615
#define ITEM_TM15 616
#define ITEM_TM16 617
#define ITEM_TM17 618
#define ITEM_TM18 619
#define ITEM_TM19 620
#define ITEM_TM20 621
#define ITEM_TM21 622
#define ITEM_TM22 623
#define ITEM_TM23 624
#define ITEM_TM24 625
#define ITEM_TM25 626
#define ITEM_TM26 627
#define ITEM_TM27 628
#define ITEM_TM28 629
#define ITEM_TM29 630
#define ITEM_TM30 631
#define ITEM_TM31 632
#define ITEM_TM32 633
#define ITEM_TM33 634
#define ITEM_TM34 635
#define ITEM_TM35 636
#define ITEM_TM36 637
#define ITEM_TM37 638
#define ITEM_TM38 639
#define ITEM_TM39 640
#define ITEM_TM40 641
#define ITEM_TM41 642
#define ITEM_TM42 643
#define ITEM_TM43 644
#define ITEM_TM44 645
#define ITEM_TM45 646
#define ITEM_TM46 647
#define ITEM_TM47 648
#define ITEM_TM48 649
#define ITEM_TM49 650
#define ITEM_TM50 651
#define ITEM_TM51 652
#define ITEM_TM52 653
#define ITEM_TM53 654
#define ITEM_TM54 655
#define ITEM_TM55 656
#define ITEM_TM56 657
#define ITEM_TM57 658
#define ITEM_TM58 659
#define ITEM_TM59 660
#define ITEM_TM60 661
#define ITEM_TM61 662
#define ITEM_TM62 663
#define ITEM_TM63 664
#define ITEM_TM64 665
#define ITEM_TM65 666
#define ITEM_TM66 667
#define ITEM_TM67 668
#define ITEM_TM68 669
#define ITEM_TM69 670
#define ITEM_TM70 671
#define ITEM_TM71 672
#define ITEM_TM72 673
#define ITEM_TM73 674
#define ITEM_TM74 675
#define ITEM_TM75 676
#define ITEM_TM76 677
#define ITEM_TM77 678
#define ITEM_TM78 679
#define ITEM_TM79 680
#define ITEM_TM80 681
#define ITEM_TM81 682
#define ITEM_TM82 683
#define ITEM_TM83 684
#define ITEM_TM84 685
#define ITEM_TM85 686
#define ITEM_TM86 687
#define ITEM_TM87 688
#define ITEM_TM88 689
#define ITEM_TM89 690
#define ITEM_TM90 691
#define ITEM_TM91 692
#define ITEM_TM92 693
#define ITEM_TM93 694
#define ITEM_TM94 695
#define ITEM_TM95 696
#define ITEM_TM96 697
#define ITEM_TM97 698
#define ITEM_TM98 699
#define ITEM_TM99 700
#define ITEM_TM100 701
#define ITEM_TM101 702
#define ITEM_TM102 703
#define ITEM_TM102 704
#define ITEM_TM103 705
#define ITEM_TM104 706
#define ITEM_TM105 707
#define ITEM_TM106 708
#define ITEM_TM107 709
#define ITEM_TM108 710
#define ITEM_TM109 711
#define ITEM_TM110 712
#define ITEM_TM111 713
#define ITEM_TM112 714
#define ITEM_TM113 715
#define ITEM_TM114 716
#define ITEM_TM115 717
#define ITEM_TM116 718
#define ITEM_TM117 719
#define ITEM_TM118 720
#define ITEM_TM119 721
#define ITEM_TM120 722

#define ITEM_HM01 723
#define ITEM_HM02 724
#define ITEM_HM03 725
#define ITEM_HM04 726
#define ITEM_HM05 727
#define ITEM_HM06 728
#define ITEM_HM07 729
#define ITEM_HM08 730

// Charms
#define ITEM_OVAL_CHARM 731
#define ITEM_SHINY_CHARM 732
#define ITEM_CATCHING_CHARM 733
#define ITEM_EXP_CHARM 734

// Form-changing Key Items
#define ITEM_ROTOM_CATALOG 735
#define ITEM_GRACIDEA 736
#define ITEM_REVEAL_GLASS 737
#define ITEM_DNA_SPLICERS 738
#define ITEM_ZYGARDE_CUBE 739
#define ITEM_PRISON_BOTTLE 740
#define ITEM_N_SOLARIZER 741
#define ITEM_N_LUNARIZER 742
#define ITEM_REINS_OF_UNITY 743

// Battle Mechanic Key Items
#define ITEM_MEGA_RING 744
#define ITEM_Z_POWER_RING 745
#define ITEM_DYNAMAX_BAND 746

// Misc. Key Items
#define ITEM_BICYCLE 747
#define ITEM_MACH_BIKE 748
#define ITEM_ACRO_BIKE 749
#define ITEM_OLD_ROD 750
#define ITEM_GOOD_ROD 751
#define ITEM_SUPER_ROD 752
#define ITEM_DOWSING_MACHINE 753
#define ITEM_ITEMFINDER ITEM_DOWSING_MACHINE // Pre-Gen IV name
#define ITEM_DOWSING_MCHN ITEM_DOWSING_MACHINE // Gen IV-V name
#define ITEM_TOWN_MAP 754
#define ITEM_VS_SEEKER 755
#define ITEM_TM_CASE 756
#define ITEM_BERRY_POUCH 757
#define ITEM_POKEMON_BOX_LINK 758
#define ITEM_POKEMON_BOX ITEM_POKEMON_BOX_LINK // Pre-Gen VIII name
#define ITEM_COIN_CASE 759
#define ITEM_POWDER_JAR 760
#define ITEM_WAILMER_PAIL 761
#define ITEM_POKE_RADAR 762
#define ITEM_POKEBLOCK_CASE 763
#define ITEM_SOOT_SACK 764
#define ITEM_POKE_FLUTE 765
#define ITEM_FAME_CHECKER 766
#define ITEM_TEACHY_TV 767

// Story Key Items
#define ITEM_SS_TICKET 768
#define ITEM_EON_TICKET 769
#define ITEM_MYSTIC_TICKET 770
#define ITEM_AURORA_TICKET 771
#define ITEM_OLD_SEA_MAP 772
#define ITEM_LETTER 773
#define ITEM_DEVON_PARTS 774
#define ITEM_DEVON_GOODS ITEM_DEVON_PARTS // Pre-Gen VI name
#define ITEM_GO_GOGGLES 775
#define ITEM_DEVON_SCOPE 776
#define ITEM_BASEMENT_KEY 777
#define ITEM_SCANNER 778
#define ITEM_STORAGE_KEY 779
#define ITEM_KEY_TO_ROOM_1 780
#define ITEM_RM_1_KEY ITEM_KEY_TO_ROOM_1 // Pre-Gen VI name
#define ITEM_KEY_TO_ROOM_2 781
#define ITEM_RM_2_KEY ITEM_KEY_TO_ROOM_2 // Pre-Gen VI name
#define ITEM_KEY_TO_ROOM_4 782
#define ITEM_RM_4_KEY ITEM_KEY_TO_ROOM_4 // Pre-Gen VI name
#define ITEM_KEY_TO_ROOM_6 783
#define ITEM_RM_6_KEY ITEM_KEY_TO_ROOM_6 // Pre-Gen VI name
#define ITEM_METEORITE 784
#define ITEM_MAGMA_EMBLEM 785
#define ITEM_CONTEST_PASS 786
#define ITEM_PARCEL 787
#define ITEM_OAKS_PARCEL ITEM_PARCEL // Pre-Gen IV name
#define ITEM_SECRET_KEY 788
#define ITEM_BIKE_VOUCHER 789
#define ITEM_GOLD_TEETH 790
#define ITEM_CARD_KEY 791
#define ITEM_LIFT_KEY 792
#define ITEM_SILPH_SCOPE 793
#define ITEM_TRI_PASS 794
#define ITEM_RAINBOW_PASS 795
#define ITEM_TEA 796
#define ITEM_RUBY 797
#define ITEM_SAPPHIRE 798

// GEN IX ITEMS
#define ITEM_ABILITY_SHIELD 799
#define ITEM_CLEAR_AMULET 800
#define ITEM_PUNCHING_GLOVE 801
#define ITEM_COVERT_CLOAK 802
#define ITEM_LOADED_DICE 803
#define ITEM_AUSPICIOUS_ARMOR 804
#define ITEM_BOOSTER_ENERGY 805
#define ITEM_BIG_BAMBOO_SHOOT 806
#define ITEM_GIMMIGHOUL_COIN 807
#define ITEM_LEADERS_CREST 808
#define ITEM_MALICIOUS_ARMOR 809
#define ITEM_MIRROR_HERB 810
#define ITEM_SCROLL_OF_DARKNESS 811
#define ITEM_SCROLL_OF_WATERS 812
#define ITEM_TERA_ORB 813
#define ITEM_TINY_BAMBOO_SHOOT 814

#define ITEM_BUG_TERA_SHARD 815
#define ITEM_DARK_TERA_SHARD 816
#define ITEM_DRAGON_TERA_SHARD 817
#define ITEM_ELECTRIC_TERA_SHARD 818
#define ITEM_FAIRY_TERA_SHARD 819
#define ITEM_FIGHTING_TERA_SHARD 820
#define ITEM_FIRE_TERA_SHARD 821
#define ITEM_FLYING_TERA_SHARD 822
#define ITEM_GHOST_TERA_SHARD 823
#define ITEM_GRASS_TERA_SHARD 824
#define ITEM_GROUND_TERA_SHARD 825
#define ITEM_ICE_TERA_SHARD 826
#define ITEM_NORMAL_TERA_SHARD 827
#define ITEM_POISON_TERA_SHARD 828
#define ITEM_PSYCHIC_TERA_SHARD 829
#define ITEM_ROCK_TERA_SHARD 830
#define ITEM_STEEL_TERA_SHARD 831
#define ITEM_WATER_TERA_SHARD 832
#define ITEM_SOUND_TERA_SHARD 833

#define ITEM_ADAMANT_CRYSTAL 834
#define ITEM_GRISEOUS_CORE 835
#define ITEM_LUSTROUS_GLOBE 836

#define ITEM_BLACK_AUGURITE 837
#define ITEM_LINKING_CORD 838
#define ITEM_PEAT_BLOCK 839
#define ITEM_BERSERK_GENE 840

#define ITEM_FAIRY_FEATHER 841
#define ITEM_SYRUPY_APPLE 842
#define ITEM_UNREMARKABLE_TEACUP 843
#define ITEM_MASTERPIECE_TEACUP 844
#define ITEM_CORNERSTONE_MASK 845
#define ITEM_WELLSPRING_MASK 846
#define ITEM_HEARTHFLAME_MASK 847
#define ITEM_HEALTH_MOCHI 848
#define ITEM_MUSCLE_MOCHI 849
#define ITEM_RESIST_MOCHI 850
#define ITEM_GENIUS_MOCHI 851
#define ITEM_CLEVER_MOCHI 852
#define ITEM_SWIFT_MOCHI 853
#define ITEM_FRESH_START_MOCHI 854
#define ITEM_GLIMMERING_CHARM 855
#define ITEM_METAL_ALLOY 856
#define ITEM_STELLAR_TERA_SHARD 857

#define ITEM_JUBILIFE_MUFFIN 858
#define ITEM_REMEDY 859
#define ITEM_FINE_REMEDY 860
#define ITEM_SUPERB_REMEDY 861
#define ITEM_AUX_EVASION 862
#define ITEM_AUX_GUARD 863
#define ITEM_AUX_POWER 864
#define ITEM_AUX_POWERGUARD 865
#define ITEM_CHOICE_DUMPLING 866
#define ITEM_SWAP_SNACK 867
#define ITEM_TWICE_SPICED_RADISH 868
#define ITEM_POKESHI_DOLL 869

// HOPO BERRY
// LEGEND PLATE

#define ITEMS_COUNT 870
#define ITEM_FIELD_ARROW ITEMS_COUNT

// A special item id associated with "Cancel"/"Exit" etc. in a list of items or decorations
// Its icon is defined at ITEMS_COUNT as the "return to field" arrow
#define ITEM_LIST_END 0xFFFF

// Range of berries given out by various NPCS
#define FIRST_BERRY_MASTER_BERRY      ITEM_POMEG_BERRY
#define LAST_BERRY_MASTER_BERRY       ITEM_NOMEL_BERRY
#define FIRST_BERRY_MASTER_WIFE_BERRY ITEM_CHERI_BERRY
#define LAST_BERRY_MASTER_WIFE_BERRY  ITEM_SITRUS_BERRY
#define FIRST_KIRI_BERRY              ITEM_POMEG_BERRY
#define LAST_KIRI_BERRY               ITEM_NOMEL_BERRY
#define FIRST_ROUTE_114_MAN_BERRY     ITEM_RAZZ_BERRY
#define LAST_ROUTE_114_MAN_BERRY      ITEM_PINAP_BERRY

#define NUM_BERRY_MASTER_BERRIES          (LAST_BERRY_MASTER_BERRY - FIRST_BERRY_MASTER_BERRY + 1)
#define NUM_BERRY_MASTER_BERRIES_SKIPPED  (FIRST_BERRY_MASTER_BERRY - FIRST_BERRY_INDEX)
#define NUM_BERRY_MASTER_WIFE_BERRIES     (LAST_BERRY_MASTER_WIFE_BERRY - FIRST_BERRY_MASTER_WIFE_BERRY + 1)
#define NUM_KIRI_BERRIES                  (LAST_KIRI_BERRY - FIRST_KIRI_BERRY + 1)
#define NUM_KIRI_BERRIES_SKIPPED          (FIRST_KIRI_BERRY - FIRST_BERRY_INDEX)
#define NUM_ROUTE_114_MAN_BERRIES         (LAST_ROUTE_114_MAN_BERRY - FIRST_ROUTE_114_MAN_BERRY + 1)
#define NUM_ROUTE_114_MAN_BERRIES_SKIPPED (FIRST_ROUTE_114_MAN_BERRY - FIRST_BERRY_INDEX)

#define ITEM_TO_BERRY(itemId)(((itemId) - FIRST_BERRY_INDEX) + 1)
#define ITEM_TO_MAIL(itemId)((itemId) - FIRST_MAIL_INDEX)
#define MAIL_NONE 0xFF
#define ITEM_TO_MULCH(itemId)(((itemId) - ITEM_GROWTH_MULCH) + 1)

#define NUM_TECHNICAL_MACHINES 120
#define NUM_HIDDEN_MACHINES 8

#define MAX_BAG_ITEM_CAPACITY         999
#define MAX_PC_ITEM_CAPACITY          999
#define MAX_PYRAMID_BAG_ITEM_CAPACITY  10 // Values higher than 255 require free SaveBlock2 space.

#define MAX_ITEM_DIGITS         ((MAX_BAG_ITEM_CAPACITY > 99) ? 3 : 2)
#define MAX_PYRAMID_ITEM_DIGITS ((MAX_PYRAMID_BAG_ITEM_CAPACITY > 99) ? 3 : 2)

// Secondary IDs for rods
#define OLD_ROD   0
#define GOOD_ROD  1
#define SUPER_ROD 2

// Secondary IDs for bikes
#define MACH_BIKE 0
#define ACRO_BIKE 1

// Item parameters for EXP Candies
#define EXP_100   1
#define EXP_800   2
#define EXP_3000  3
#define EXP_10000 4
#define EXP_30000 5

// Item type IDs (used to determine the exit callback)
#define ITEM_USE_MAIL             0
#define ITEM_USE_PARTY_MENU       1
#define ITEM_USE_FIELD            2
#define ITEM_USE_PBLOCK_CASE      3
#define ITEM_USE_BAG_MENU         4 // No exit callback, stays in bag menu
#define ITEM_USE_PARTY_MENU_MOVES 5

// Item battle script IDs (need to be non-zero)
#define EFFECT_ITEM_RESTORE_HP              1
#define EFFECT_ITEM_CURE_STATUS             2
#define EFFECT_ITEM_HEAL_AND_CURE_STATUS    3
#define EFFECT_ITEM_INCREASE_STAT           4
#define EFFECT_ITEM_SET_MIST                5
#define EFFECT_ITEM_SET_FOCUS_ENERGY        6
#define EFFECT_ITEM_ESCAPE                  7
#define EFFECT_ITEM_THROW_BALL              8
#define EFFECT_ITEM_REVIVE                  9
#define EFFECT_ITEM_RESTORE_PP              10
#define EFFECT_ITEM_INCREASE_ALL_STATS      11

// Enigma Berry dummy constant
#define EFFECT_ITEM_ENIGMA_BERRY_EREADER    1

#endif  // GUARD_CONSTANTS_ITEMS_H
