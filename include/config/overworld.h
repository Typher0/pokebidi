#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.
#define SLOW_MOVEMENT_ON_STAIRS     FALSE       // If enabled, the player will move slower up/down stairs like in FR

// Other settings
#define OW_POISON_DAMAGE                GEN_LATEST // In Gen4, Pokémon no longer faint from Poison in the overworld. In Gen5+, they no longer take damage at all.
#define OW_DOUBLE_APPROACH_WITH_ONE_MON FALSE      // If enabled, you can be spotted by two trainers at the same time even if you only have one eligible Pokémon in your party.
#define OW_HIDE_REPEAT_MAP_POPUP        FALSE      // If enabled, map popups will not appear if entering a map with the same Map Section Id as the last.
#define OW_WHITEOUT_CUTSCENE            GEN_LATEST // In Gen4+, whiting out shows an additional message and post whiteout event script cutscene with a healing NPC. (While this change was also in FRLG, for the sake of simplicity, setting this to GEN_3 will result in RSE behavior.)
#define OW_DEFOG_FIELD_MOVE             FALSE      // If enabled, Defog can be used as a Field Move as seen in DPPt.
#define OW_ROCK_CLIMB_FIELD_MOVE        FALSE      // If enabled, Rock Climb can be used as a Field Move as seen in DPPt.
#define OW_CHOOSE_FROM_PC_AND_PARTY     TRUE       // If enabled, NPCs like move tutors or trainers asking for trade will let you pick a Pokémon from your PC or party instead of just your party

// Item Obtain Description Box
#define OW_ITEM_DESCRIPTIONS_OFF        0   // never show descriptions
#define OW_ITEM_DESCRIPTIONS_FIRST_TIME 1   // show first time (** SAVE-BREAKING - see struct SaveBlock3 **)
#define OW_ITEM_DESCRIPTIONS_ALWAYS     2   // always show description
#define OW_SHOW_ITEM_DESCRIPTIONS       OW_ITEM_DESCRIPTIONS_OFF    // If enabled, item descriptions/images will be shown when finding items.

// These generational defines only make a distinction for Berries and the OW_PC_MOVE_ORDER
#define GEN_6_XY GEN_6
#define GEN_6_ORAS GEN_COUNT + 1

// PC settings
#define OW_PC_PRESS_B               GEN_LATEST // In Gen4, pressing B when holding a Pokémon is equivalent to placing it. In Gen3, it gives the "You're holding a Pokémon!" error.
#define OW_PC_JAPAN_WALDA_ICONS     TRUE       // In the US release of Emerald, the Cross, Bolt, and Plusle icons for Walda's wallpapers were left blank from the Japan release. Setting this to TRUE will restore them.
#define OW_PC_HEAL                  GEN_LATEST // In Gen8+, Pokémon are not healed when deposited in the PC.
#define OW_PC_MOVE_ORDER            GEN_LATEST // Starting in Gen4, the order of options in the PC menu change.
#define OW_PC_RELEASE_ITEM          GEN_LATEST // In Gen8+, Pokémon that get released with a held item return it to the bag.

#define OW_BERRY_MUTATIONS             FALSE      // If enabled, Berry plants can mutate based on berries planted next to them.
#define OW_BERRY_MUTATION_CHANCE       25         // Determines the % chance of a mutation.
#define OW_BERRY_MOISTURE              FALSE      // If enabled, Berry watering is not a matter of watering it once per stage, but rather of keeping the soil moist.
#define OW_BERRY_ALWAYS_WATERABLE      FALSE      // If OW_BERRY_MOISTURE is enabled, this setting allows the player to continuously water soil; dry soil will cause a decrease in Berry Yield (like Gen4). When off, soil can only be watered when dry and watering increases yield (like Gen6).
#define OW_BERRY_MULCH_USAGE           FALSE      // If enabled, Mulch can be used on soil to fertilize it. Otherwise, it is considered unusable. Note that moisture effects only work with OW_BERRY_MOISTURE enabled!
#define OW_BERRY_WEEDS                 FALSE      // If enabled, weeds may grow on Berry plants that the player needs to take care of. Without OW_BERRY_MOISTURE, weeding bonuses are rounded down.
#define OW_BERRY_PESTS                 FALSE      // If enabled, pests may approach Berry plants that the player needs to take care of. Without OW_BERRY_MOISTURE, pest bonuses are rounded down.
#define OW_BERRY_SIX_STAGES            FALSE      // In XY, Berries go through six stages instead of four. This toggle does not affect the time it takes for a tree to be ready for harvest. Without OW_BERRY_MOISTURE, the two extra stages count as BERRY_STAGE_TALLER for watering purposes.

#define OW_BERRY_GROWTH_RATE           GEN_3      // Presets for how long each Berry plant takes to grow.
#define OW_BERRY_YIELD_RATE            GEN_3      // Presets for how many Berries each plant can yield.
#define OW_BERRY_DRAIN_RATE            GEN_6_ORAS // If OW_BERRY_MOISTURE is enabled, this setting changes how fast the soil dries out. GEN_4 uses a Berry-dependent drain rate, GEN_6_XY dries out in 24 hours (4 hours with the relevant Mulch) and GEN_6_ORAS dries out in 4 hours. Other values are illegal.
#define OW_BERRY_IMMORTAL              TRUE      // If enabled, once a Berry tree has grown a Berry, the tree will not disappear until picked by the player.
#define OW_BERRY_COLORS                GEN_6_ORAS // If set to GEN_6_XY or GEN_6_ORAS, the Chesto, Wiki, Bluk, Cornn, Pamtre, Belue, Ganlon, Watmel, Qualot, Spelon, Kasib, Colbur, Lansat, Kee, Payapa, Roseli, Liechi, Enigma, and Maranga will use their colors from the stated game. Other values are illegal.

// Overworld Pokémon
#define OW_POKEMON_OBJECT_EVENTS       TRUE       // Adds Object Event fields for every species. Can be used for NPCs using the OBJ_EVENT_GFX_SPECIES macro (eg. OBJ_EVENT_GFX_SPECIES(BULBASAUR))
#define OW_SUBSTITUTE_PLACEHOLDER      TRUE       // Use a substitute OW for Pokémon that are missing overworld sprites
#define OW_LARGE_OW_SUPPORT            TRUE       // If true, adds a small amount of overhead to OW code so that large (48x48, 64x64) OWs will display correctly under bridges, etc.
#define OW_PKMN_OBJECTS_SHARE_PALETTES FALSE      // [WIP!! NOT ALL PALETTES HAVE BEEN ADJUSTED FOR THIS!!] If TRUE, follower palettes are taken from battle sprites.
#define OW_GFX_COMPRESS                TRUE       // Adds support for compressed OW graphics, (Also compresses pokemon follower graphics).
                                                  // IMPORTANT: Gfx are loaded into VRAM to avoid continous decompression. If you require more VRAM or want to use a lot of overworld Pokémon at once, you should disable this config.
                                                  // Compressed gfx are incompatible with non-power-of-two sprite sizes:
                                                  // (You should not use 48x48 sprites/tables for compressed gfx)
                                                  // 16x32, 32x32, 64x64 etc are fine
#define OW_MON_WANDER_WALK             TRUE       // If true, OW pokemon with MOVEMENT_TYPE_WANDER will walk-in-place in between steps.
// Follower Pokémon
#define OW_FOLLOWERS_ENABLED           TRUE      // Enables follower Pokémon, HGSS style. Requires OW_POKEMON_OBJECT_EVENTS. Note that additional scripting may be required for them to be fully supported!
#define OW_FOLLOWERS_BOBBING           TRUE       // If TRUE, follower Pokémon will bob up and down during their idle & walking animations
#define OW_FOLLOWERS_POKEBALLS         TRUE       // If TRUE, follower Pokémon will emerge from the Poké Ball they are stored in, instead of a normal Poké Ball
#define OW_FOLLOWERS_WEATHER_FORMS     TRUE       // If TRUE, Castform and Cherrim gain FORM_CHANGE_OVERWORLD_WEATHER, which will make them transform in the overworld based on the weather.
#define OW_FOLLOWERS_COPY_WILD_PKMN    TRUE       // If TRUE, follower Pokémon that know Transform or have Illusion/Imposter will copy wild Pokémon at random.
#define OW_BATTLE_ONLY_FORMS           FALSE      // If TRUE, loads overworld sprites for battle-only forms like Mega Evos. Requires OW_POKEMON_OBJECT_EVENTS.
#define B_FLAG_FOLLOWERS_DISABLED      0          // Enables / Disables followers by using a flag. Helpful to disable followers for a period of time.
#define OW_FOLLOWERS_SCRIPT_MOVEMENT   TRUE       // If TRUE, follower Pokémon only go back to their Poké Ball if a non-player collides with them by setting the FLAG_SAFE_FOLLOWER_MOVEMENT flag by default.
// Follower Pokémon Restrictions
// If set, the only pokemon allowed to follow you will be those matching species, met location, and/or met level; These accept vars, too: VAR_TEMP_1, etc
// For examples, see "docs/tutorials/how_to_new_pokemon.md"
#define OW_FOLLOWERS_ALLOWED_SPECIES (SPECIES_BULBASAUR, SPECIES_IVYSAUR, SPECIES_VENUSAUR, SPECIES_CHARMANDER, SPECIES_CHARMELEON, SPECIES_CHARIZARD, SPECIES_SQUIRTLE, SPECIES_WARTORTLE, SPECIES_BLASTOISE, SPECIES_PIDGEY, SPECIES_PIDGEOTTO, SPECIES_PIDGEOT, SPECIES_RATTATA, SPECIES_RATICATE, SPECIES_SPEAROW, SPECIES_FEAROW, SPECIES_PIKACHU, SPECIES_RAICHU, SPECIES_SANDSHREW, SPECIES_SANDSLASH, SPECIES_NIDORAN_F, SPECIES_NIDORINA, SPECIES_NIDOQUEEN, SPECIES_NIDORAN_M, SPECIES_NIDORINO, SPECIES_NIDOKING, SPECIES_CLEFAIRY, SPECIES_CLEFABLE, SPECIES_VULPIX, SPECIES_NINETALES, SPECIES_JIGGLYPUFF, SPECIES_WIGGLYTUFF, SPECIES_MEOWTH, SPECIES_PERSIAN, SPECIES_PSYDUCK, SPECIES_GOLDUCK, SPECIES_GROWLITHE, SPECIES_ARCANINE, SPECIES_POLIWAG, SPECIES_POLIWHIRL, SPECIES_POLIWRATH, SPECIES_POLITOED, SPECIES_ABRA, SPECIES_KADABRA, SPECIES_ALAKAZAM, SPECIES_BELLSPROUT, SPECIES_WEEPINBELL, SPECIES_VICTREEBEL, SPECIES_GEODUDE, SPECIES_GRAVELER, SPECIES_GOLEM, SPECIES_PONYTA, SPECIES_RAPIDASH, SPECIES_DODUO, SPECIES_DODRIO, SPECIES_SEEL, SPECIES_DEWGONG, SPECIES_GRIMER, SPECIES_MUK, SPECIES_GASTLY, SPECIES_HAUNTER, SPECIES_GENGAR, SPECIES_KRABBY, SPECIES_KINGLER, SPECIES_CHANSEY, SPECIES_SCYTHER, SPECIES_MAGIKARP, SPECIES_GYARADOS, SPECIES_LAPRAS, SPECIES_DITTO, SPECIES_EEVEE, SPECIES_VAPOREON, SPECIES_JOLTEON, SPECIES_FLAREON, SPECIES_OMANYTE, SPECIES_OMASTAR, SPECIES_KABUTO, SPECIES_KABUTOPS, SPECIES_AERODACTYL, SPECIES_ARTICUNO, SPECIES_ZAPDOS, SPECIES_MOLTRES, SPECIES_DRATINI, SPECIES_DRAGONAIR, SPECIES_DRAGONITE, SPECIES_MEWTWO, SPECIES_MEW, SPECIES_CHIKORITA, SPECIES_BAYLEEF, SPECIES_MEGANIUM, SPECIES_CYNDAQUIL, SPECIES_QUILAVA, SPECIES_TYPHLOSION, SPECIES_TOTODILE, SPECIES_CROCONAW, SPECIES_FERALIGATR, SPECIES_SENTRET, SPECIES_FURRET, SPECIES_HOOTHOOT, SPECIES_NOCTOWL, SPECIES_LEDYBA, SPECIES_LEDIAN, SPECIES_SPINARAK, SPECIES_ARIADOS, SPECIES_PICHU, SPECIES_CLEFFA, SPECIES_IGGLYBUFF, SPECIES_TOGEPI, SPECIES_TOGETIC, SPECIES_NATU, SPECIES_XATU, SPECIES_MAREEP, SPECIES_FLAAFFY, SPECIES_AMPHAROS, SPECIES_MARILL, SPECIES_AZUMARILL, SPECIES_HOPPIP, SPECIES_SKIPLOOM, SPECIES_JUMPLUFF, SPECIES_WOOPER, SPECIES_QUAGSIRE, SPECIES_ESPEON, SPECIES_UMBREON, SPECIES_MURKROW, SPECIES_SLOWKING, SPECIES_MISDREAVUS, SPECIES_WOBBUFFET, SPECIES_GIRAFARIG, SPECIES_PINECO, SPECIES_FORRETRESS, SPECIES_DUNSPARCE, SPECIES_GLIGAR, SNUBBULL, SPECIES_GRANBULL, SPECIES_SCIZOR, SPECIES_SHUCKLE, SPECIES_HERACROSS, SPECIES_SNEASEL, SPECIES_SWINUB, SPECIES_PILOSWINE, SPECIES_PHANPY, SPECIES_DONPHAN, SPECIES_BLISSEY, SPECIES_RAIKOU, SPECIES_ENTEI, SPECIES_SUICUNE, SPECIES_LARVITAR, SPECIES_PUPITAR, SPECIES_TYRANITAR, SPECIES_CELEBI, SPECIES_TREECKO, SPECIES_GROVYLE, SPECIES_SCEPTILE, SPECIES_TORCHIC, SPECIES_COMBUSKEN, SPECIES_BLAZIKEN, SPECIES_MUDKIP, SPECIES_MARSHTOMP, SPECIES_SWAMPERT, SPECIES_ZIGZAGOON, SPECIES_LINOONE, SPECIES_WURMPLE, SPECIES_BEAUTIFLY, SPECIES_CASCOON, SPECIES_DUSTOX, SPECIES_LOTAD, SPECIES_LOMBRE, SPECIES_LUDICOLO, SPECIES_SEEDOT, SPECIES_NUZLEAF, SPECIES_SHIFTRY, SPECIES_TAILLOW, SPECIES_SWELLOW, SPECIES_WINGULL, SPECIES_PELIPPER, SPECIES_RALTS, SPECIES_KIRLIA, SPECIES_GARDEVOIR, SPECIES_SURSKIT, SPECIES_MASQUERAIN, SPECIES_SHROOMISH, SPECIES_BRELOOM, SPECIES_VIGOROTH, SPECIES_NINCADA, SPECIES_NINJASK, SPECIES_SHEDINJA, SPECIES_WHISMUR, SPECIES_LOUDRED, SPECIES_EXPLOUD, SPECIES_AZURILL, SPECIES_SKITTY, SPECIES_DELCATTY, SPECIES_SABLEYE, SPECIES_MEDITITE, SPECIES_MEDICHAM, SPECIES_ELECTRIKE, SPECIES_MANECTRIC, SPECIES_PLUSLE, SPECIES_MINUN, SPECIES_VOLBEAT, SPECIES_ILLUMISE, SPECIES_ROSELIA, SPECIES_SPOINK, SPECIES_GRUMPIG, SPECIES_TRAPINCH, SPECIES_VIBRAVA, SPECIES_FLYGON, SPECIES_CACNEA, SPECIES_CACTURNE, SPECIES_SWABLU, SPECIES_ALTARIA, SPECIES_LILEEP, SPECIES_CRADILY, SPECIES_ANORITH, SPECIES_ARMALDO, SPECIES_FEEBAS, SPECIES_MILOTIC, SPECIES_CASTFORM, SPECIES_SHUPPET, SPECIES_BANETTE, SPECIES_DUSKULL, SPECIES_DUSCLOPS, SPECIES_SNORUNT, SPECIES_GLALIE, SPECIES_SPHEAL, SPECIES_SEALEO, SPECIES_WALREIN, SPECIES_LUVDISC, SPECIES_BAGON, SPECIES_SHELGON, SPECIES_SALAMENCE, SPECIES_BELDUM, SPECIES_METANG, SPECIES_METAGROSS, SPECIES_REGIROCK, SPECIES_REGICE, SPECIES_REGISTEEL, SPECIES_LATIAS, SPECIES_LATIOS, SPECIES_JIRACHI, SPECIES_TURTWIG, SPECIES_GROTLE, SPECIES_TORTERRA, SPECIES_CHIMCHAR, SPECIES_MONFERNO, SPECIES_INFERNAPE, SPECIES_PIPLUP, SPECIES_PRINPLUP, SPECIES_EMPOLEON, SPECIES_STARLY, SPECIES_STARAVIA, SPECIES_STARAPTOR, SPECIES_BIDOOF, SPECIES_BIBAREL, SPECIES_KRICKETOT, SPECIES_KRICKETUNE, SPECIES_SHINX, SPECIES_LUXIO, SPECIES_LUXRAY, SPECIES_BUDEW, SPECIES_ROSERADE, SPECIES_CRANIDOS, SPECIES_RAMPARDOS, SPECIES_SHIELDON, SPECIES_BASTIODON, SPECIES_PACHURISU, SPECIES_BUIZEL, SPECIES_FLOATZEL, SPECIES_CHERUBI, SPECIES_CHERRIM, SPECIES_SHELLOS, SPECIES_GASTRODON, SPECIES_GLAMEOW, SPECIES_PURUGLY, SPECIES_BRONZOR, SPECIES_BRONZONG, SPECIES_HAPPINY, SPECIES_GIBLE, SPECIES_GABITE, SPECIES_GARCHOMP, SPECIES_RIOLU, SPECIES_LUCARIO, SPECIES_CROAGUNK, SPECIES_TOXICROAK, SPECIES_WEAVILE, SPECIES_TOGEKISS, SPECIES_LEAFEON, SPECIES_GLACEON, SPECIES_GLISCOR, SPECIES_MAMOSWINE, SPECIES_GALLADE, SPECIES_DUSKNOIR, SPECIES_FROSLASS, SPECIES_ROTOM, SPECIES_UXIE, SPECIES_MESPRIT, SPECIES_AZELF, SPECIES_CRESSELIA, SPECIES_PHIONE, SPECIES_MANAPHY, SPECIES_SHAYMIN, SPECIES_VICTINI, SPECIES_SNIVY, SPECIES_SERVINE, SPECIES_SERPERIOR, SPECIES_TEPIG, SPECIES_PIGNITE, SPECIES_EMBOAR, SPECIES_OSHAWOTT, SPECIES_DEWOTT, SPECIES_SAMUROTT, SPECIES_PATRAT, SPECIES_WATCHOG, SPECIES_LILLIPUP, SPECIES_HERDIER, SPECIES_STOUTLAND, SPECIES_PURRLOIN, SPECIES_LIEPARD, SPECIES_PANSAGE, SPECIES_SIMISAGE, SPECIES_PANSEAR, SPECIES_SIMISEAR, SPECIES_PANPOUR, SPECIES_SIMIPOUR, SPECIES_MUNNA, SPECIES_MUSHARNA, SPECIES_PIDOVE, SPECIES_TRANQUILL, SPECIES_UNFEZANT, SPECIES_BLITZLE, SPECIES_ZEBSTRIKA, SPECIES_ROGGENROLA, SPECIES_BOLDORE, SPECIES_GIGALITH, SPECIES_WOOBAT, SPECIES_SWOOBAT, SPECIES_DRILBUR, SPECIES_EXCADRILL, SPECIES_AUDINO, SPECIES_TIMBURR, SPECIES_GURDURR, SPECIES_CONKELDURR, SPECIES_TYMPOLE, SPECIES_PALPITOAD, SPECIES_SEISMITOAD, SPECIES_THROH, SPECIES_SAWK, SPECIES_SEWADDLE, SPECIES_SWADLOON, SPECIES_LEAVANNY, SPECIES_VENIPEDE, SPECIES_WHIRLIPEDE, SPECIES_SCOLIPEDE, SPECIES_COTTONEE, SPECIES_WHIMSICOTT, SPECIES_PETILIL, SPECIES_LILLIGANT, SPECIES_BASCULIN, SPECIES_SANDILE, SPECIES_KROKOROK, SPECIES_KROOKODILE, SPECIES_DARUMAKA, SPECIES_DARMANITAN, SPECIES_MARACTUS, SPECIES_DWEBBLE, SPECIES_CRUSTLE, SPECIES_SCRAGGY, SPECIES_SCRAFTY, SPECIES_SIGILYPH, SPECIES_YAMASK, SPECIES_COFAGRIGUS, SPECIES_TIRTOUGA, SPECIES_CARRACOSTA, SPECIES_ARCHEN, SPECIES_ARCHEOPS, SPECIES_TRUBBISH, SPECIES_GARBODOR, SPECIES_ZORUA, SPECIES_ZOROARK, SPECIES_MINCCINO, SPECIES_CINCCINO, SPECIES_GOTHITA, SPECIES_GOTHORITA, SPECIES_GOTHITELLE, SPECIES_SOLOSIS, SPECIES_DUOSION, SPECIES_REUNICLUS, SPECIES_DUCKLETT, SPECIES_SWANNA, SPECIES_VANILITE, SPECIES_VANILLISH, SPECIES_VANILLUXE, SPECIES_DEERLING, SPECIES_SAWSBUCK, SPECIES_EMOLGA, SPECIES_KARRABLAST, SPECIES_ESCAVALIER, SPECIES_FOONGUS, SPECIES_AMOONGUSS, SPECIES_FRILLISH, SPECIES_JELLICENT, SPECIES_ALOMOMOLA, SPECIES_FERROSEED, SPECIES_FERROTHORN, SPECIES_KLINK, SPECIES_KLANG, SPECIES_KLINKLANG, SPECIES_TYNAMO, SPECIES_EELEKTRIK, SPECIES_EELEKTROSS, SPECIES_ELGYEM, SPECIES_BEHEEYEM, SPECIES_LITWICK, SPECIES_LAMPENT, SPECIES_CHANDELURE, SPECIES_AXEW, SPECIES_FRAXURE, SPECIES_HAXORUS, SPECIES_CROGONAL, SPECIES_SHELMET, SPECIES_ACCELGORE, SPECIES_STUNFISK, SPECIES_MIENFOO, SPECIES_MIENSHAO, SPECIES_DRUDDIGON, SPECIES_PAWNIARD, SPECIES_BISHARP, SPECIES_RUFFLET, SPECIES_BRAVIARY, SPECIES_VULLABY, SPECIES_MANDIBUZZ, SPECIES_HEATMOR, SPECIES_DURANT, SPECIES_DEINO, SPECIES_ZWEILOUS, SPECIES_HYDREIGON, SPECIES_LARVESTA, SPECIES_VOLCARONA, SPECIES_TORNADUS, SPECIES_THUNDURUS, SPECIES_LANDORUS, SPECIES_MELOETTA, SPECIES_CHESPIN, SPECIES_QUILLADIN, SPECIES_CHESNAUGHT, SPECIES_FENNEKIN, SPECIES_BRAIXEN, SPECIES_DELPHOX, SPECIES_FROAKIE, SPECIES_FROGADIER, SPECIES_GRENINJA, SPECIES_BUNNELBY, SPECIES_DIGGERSBY, SPECIES_FLETHLING, SPECIES_FLETCHINDER, SPECIES_TALONFLAME, SPECIES_FLABEBE, SPECIES_FLOETTE, SPECIES_FLORGES, SPECIES_FURFROU, SPECIES_ESPURR, SPECIES_MEOWSTIC, SPECIES_SPRITZEE, SPECIES_AROMATISSE, SPECIES_SWIRLIX, SPECIES_SLURPUFF, SPECIES_HELIOPTILE, SPECIES_HELIOLISK, SPECIES_TYRUNT, SPECIES_TYRANTRUM, SPECIES_AMAURA, SPECIES_AURORUS, SPECIES_SYLVEON, SPECIES_HAWLUCHA, SPECIES_DEDENNE, SPECIES_CARBINK, SPECIES_GOOMY, SPECIES_SLIGGOO, SPECIES_GOODRA, SPECIES_KLEFKI, NOIBAT, SPECIES_NOIVERN, SPECIES_XERNEAS, SPECIES_YVELTAL, SPECIES_ZYGARDE, SPECIES_DIANCIE, SPECIES_HOOPA, SPECIES_ROWLET, SPECIES_DARTRIX, SPECIES_DECIDUEYE, SPECIES_LITTEN, SPECIES_TORRACAT, SPECIES_INCINEROAR, SPECIES_POPPLIO, SPECIES_BRIONNE, SPECIES_PRIMARINA, SPECIES_PIKIPEK, SPECIES_TRUMBEAK, SPECIES_TOUCANNON, SPECIES_CRABRAWLER, SPECIES_CRABOMINABLE, SPECIES_ORICORIO, SPECIES_CUTIEFLY, SPECIES_RIBOMBEE, SPECIES_COMFEY, SPECIES_WIMPOD, SPECIES_GOLISOPOD, SPECIES_SANDYGAST, SPECIES_PALOSSAND, SPECIES_PYUKUMUKU, SPECIES_MINIOR, SPECIES_TOGEDEMARU, SPECIES_MIMIKYU, SPECIES_JANGMO_O, SPECIES_HAKAMO_O, SPECIES_KOMMO_O, SPECIES_COSMOG, SPECIES_GROOKEY, SPECIES_THWACKEY, SPECIES_RILLABOOM, SPECIES_SCORBUNNY, SPECIES_RABOOT, SPECIES_CINDERACE, SPECIES_SOBBLE, SPECIES_DRIZZILE, SPECIES_INTELEON, SPECIES_SKWOVET, SPECIES_GREEDENT, SPECIES_ROOKIDEE, SPECIES_CORVISQUIRE, SPECIES_CORVIKNIGHT, SPECIES_NICKIT, SPECIES_THIEVUL, SPECIES_GOSSIFLEUR, SPECIES_ELDEGOSS, SPECIES_WOOLOO, SPECIES_DUBWOOL, SPECIES_YAMPER, SPECIES_BOLTUND, SPECIES_ROLYCOLY, SPECIES_CARKOL, SPECIES_COALOSSAL, SPECIES_ARROKUDA, SPECIES_BARRASKEWDA, SPECIES_TOXEL, SPECIES_TOXTRICITY, SPECIES_SINISTEA, SPECIES_POLTEAGEIST, SPECIES_OBSTAGOON, SPECIES_PERRSERKER, SPECIES_MILCERY, SPECIES_ALCREMIE, SPECIES_FALINKS, SPECIES_PINCURCHIN, SPECIES_SNOM, SPECIES_FROSMOTH, SPECIES_EISCUE, SPECIES_INDEEDEE, SPECIES_MORPEKO, SPECIES_DREEPY, SPECIES_DRAKLOAK, SPECIES_DRAGAPULT, SPECIES_KUBFU, SPECIES_URSHIFU, SPECIES_REGIELEKI, SPECIES_REGIDRAGO, SPECIES_KLEAVOR, SPECIES_BASCULEGION, SPECIES_SNEASLER, SPECIES_ENAMORUS, SPECIES_SPRIGATITO, SPECIES_FLORAGATO, SPECIES_MEOWSCARADA, SPECIES_FUECOCO, SPECIES_CROCALOR, SPECIES_SKELEDIRGE, SPECIES_QUAXLY, SPECIES_QUAXWELL, SPECIES_QUQUAVAL, SPECIES_PAWMI, SPECIES_PAWMO, SPECIES_PAWMOT, SPECIES_TANDEMAUS, SPECIES_MAUSHOLD, SPECIES_FIDOUGH, SPECIES_DACHSBUN, SPECIES_SMOLIV, SPECIES_DOLLIV, SPECIES_ARBOLIVA, SPECIES_CHARCADET, SPECIES_ARMAROUGE, SPECIES_CERULEDGE, SPECIES_TADBULB, SPECIES_BELLIBOLT, SPECIES_WATTREL, SPECIES_KILOWATTREL, SPECIES_MASCHIFF, SPECIES_MABOSSTIFF, SPECIES_KLAWF, SPECIES_FINIZEN, SPECIES_PALAFIN, SPECIES_GLIMMET, SPECIES_GLIMMORA, SPECIES_FLAMIGO, SPECIES_TATSUGIRI, SPECIES_CLODSIRE, SPECIES_FARIGIRAF, SPECIES_DUDUNSPARCE, SPECIES_KINGAMBIT, SPECIES_FRIGIBAX, SPECIES_ARCTIBAX, SPECIES_BAXCALIBUR, SPECIES_GIMMIGHOUL, SPECIES_GHOLDENGO, SPECIES_KORAIDON, SPECIES_MIRAIDON, SPECIES_HAMSNUG, SPECIES_SNUGGYBARA, SPECIES_PINGLOO, SPECIES_PENGLACIER, SPECIES_CABOB, SPECIES_LYNXSKEW, SPECIES_DOCTOWL, SPECIES_CUPPY, SPECIES_FETTLEKISH, SPECIES_SHELFUR, SPECIES_IGNOISE, SPECIES_MOLTORTOISE, SPECIES_PUMACH, SPECIES_JAGWIRE, SPECIES_CHIHAHA, SPECIES_HOWLEQUIN, SPECIES_TOTTER, SPECIES_CASCOTTA, SPECIES_LUTRAJET, SPECIES_CHIMPOCA, SPECIES_SIMAYAN, SPECIES_PSYYNEN, SPECIES_AANCHGORA, SPECIES_NECTRI, SPECIES_HUMMISCUS, SPECIES_NECTRIARY, SPECIES_FANWPIRE, SPECIES_LLAMCULA, SPECIES_MOSSEFERATU, SPECIES_PLATYPOW, SPECIES_PLATYPUNCH, SPECIES_SILKINDER, SPECIES_SENSILK, SPECIES_SQUIBBLE, SPECIES_SQUINGO, SPECIES_RELLADUNE, SPECIES_CAMORELLA, SPECIES_MASKREEP, SPECIES_PHANTIKI, SPECIES_TANUKOON, SPECIES_LEUKOON, SPECIES_GNOWM, SPECIES_SNOWGRE, SPECIES_CHELONITE, SPECIES_GALAXAGOS, SPECIES_HATHROSTUS, SPECIES_BABOSIRIS, SPECIES_HUBRISET, SPECIES_ROYGIBIV)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (0)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (0)

// Out-of-battle Ability effects
#define OW_SYNCHRONIZE_NATURE       GEN_LATEST // In Gen8+, if a Pokémon with Synchronize leads the party, wild Pokémon will always have their same Nature as opposed to the 50% chance in previous games. Gift Pokémon excluded.
                                               // In USUM (here GEN_7), if a Pokémon with Synchronize leads the party, gift Pokémon will always have their same Nature regardless of their Egg Group.
                                               // In ORAS (here GEN_6), if a Pokémon with Synchronize leads the party, gift Pokémon from the No Eggs Discovered Egg Group will always have their same Nature.
#define OW_SUPER_LUCK               GEN_LATEST // In Gen8+, if a Pokémon with Super Luck is leading the party, the wild held item rate is increased to 60%/20%.
#define OW_INFILTRATOR              GEN_LATEST // In Gen8+, if a Pokémon with Infiltrator is leading the party, the wild encounter rate is halved.
#define OW_HARVEST                  GEN_LATEST // In Gen8+, if a Pokémon with Harvest is leading the party, there is a 50% chance to encounter a Grass-type Pokémon.
#define OW_LIGHTNING_ROD            GEN_LATEST // In Gen8+, if a Pokémon with Lightning Rod is leading the party, there is a 50% chance to encounter an Electric-type Pokémon.
#define OW_STORM_DRAIN              GEN_LATEST // In Gen8+, if a Pokémon with Storm Drain is leading the party, there is a 50% chance to encounter a Water-type Pokémon.
#define OW_FLASH_FIRE               GEN_LATEST // In Gen8+, if a Pokémon with Flash Fire is leading the party, there is a 50% chance to encounter a Fire-type Pokémon.

// These defines only make a distinction for OW_ALTERED_TIME_RATIO
#define GEN_8_PLA                       GEN_COUNT + 2
#define TIME_DEBUG                      GEN_COUNT + 3

// Time
#define OW_TIMES_OF_DAY                 GEN_LATEST   // Different generations have the times of day change at different times.
#define OW_USE_FAKE_RTC                 FALSE        // When TRUE, seconds on the in-game clock will only advance once every 60 playTimeVBlanks (every 60 frames).
#define OW_ALTERED_TIME_RATIO           GEN_LATEST   // In GEN_8_PLA, the time in game moves forward 60 seconds for every second in the RTC. In GEN_9, it is 20 seconds. TIME_DEBUG is 1:1, and meant for debugging purposes. This has no effect if OW_USE_FAKE_RTC is FALSE.
#define OW_TIME_OF_DAY_ENCOUNTERS       TRUE        // If TRUE, will allow the user to define and use different encounter tables based on the time of day.
#define OW_TIME_OF_DAY_DISABLE_FALLBACK FALSE        // If TRUE, if the encounter table for a specific map and time is empty, the area will have no encounters instead of falling back to the vanilla map and time.
#define OW_TIME_OF_DAY_FALLBACK         TIME_MORNING // The time of day that encounter tables fall back to. If you set OW_TIMES_OF_DAY to GEN_3, change this to TIME_DAY or you won't have any encounters!

// Lighting
#define OW_SHADOW_INTENSITY             4       // Ranges from 0 to 16, where 0 is fully transparent and 16 is black.
#define OW_OBJECT_SUBPRIORITY           148     // The higher the value, the farther back compared to other sprites. Shadows should be behind object events.
#define OW_ENABLE_DNS                   TRUE    // If set to TRUE, the overworld will be tinted depending on time of day.

// Object Event Shadows
#define OW_OBJECT_VANILLA_SHADOWS      FALSE    // When FALSE, every object in the overworld has a shadow. WARNING: This means every object will take up two sprites instead of one. When TRUE, an object's shadow is only shown when jumping.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_PAUSE_TIME          0  // If this flag is set and OW_USE_FAKE_RTC is enabled, seconds on the in-game clock will not advance.
#define OW_FLAG_NO_ENCOUNTER        0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      0  // If this flag is set, trainers will not battle the player unless they're talked to.
#define OW_FLAG_NO_COLLISION        0  // If this flag is set, the player will be able to walk over tiles with collision. Mainly intended for debugging purposes.
#define OW_FLAG_POKE_RIDER          0  // If this flag is set, the player will be able to use fly from the Pokenav Region Map and the Town Map key item by pressing 'R' on a city/location they are able to fly to.

#define BATTLE_PYRAMID_RANDOM_ENCOUNTERS    FALSE    // If set to TRUE, battle pyramid Pokemon will be generated randomly based on the round's challenge instead of hardcoded in src/data/battle_frontier/battle_pyramid_level_50_wild_mons.h (or open_level_wild_mons.h)

// Map pop-up config
#define OW_POPUP_GENERATION        GEN_5    // Different generations display location names in overworld pop-ups differently.
                                            // Only choices are GEN_3 and GEN_5, all others will default to Gen3 pop-ups.
                                            // Due to changes in project scope, as detailed in docs/team_procedures/scope.md,
                                            // no other overworld popups will be implemented in expansion.

// Gen5 map pop-up config
// Constants
#define OW_POPUP_BW_TIME_NONE      0   // Don't show the time
#define OW_POPUP_BW_TIME_12_HR     1   // Use 12 hour (AM/PM) time
#define OW_POPUP_BW_TIME_24_HR     2   // Use 24 hour time

#define OW_POPUP_BW_COLOR_BLACK    0   // Black pop-up from B2
#define OW_POPUP_BW_COLOR_WHITE    1   // White pop-up from W2

// Configuration
#define OW_POPUP_BW_COLOR          OW_POPUP_BW_COLOR_BLACK  // B2W2 use different colors for their map pop-ups.
#define OW_POPUP_BW_TIME_MODE      OW_POPUP_BW_TIME_12_HR    // Determines what type of time is shown.
#define OW_POPUP_BW_ALPHA_BLEND    FALSE                    // Enables alpha blending/transparency for the pop-ups. Mainly intended to be used with the black color option.
                                                            // Setting this to TRUE will cause graphical errors with the Day Night System enabled.
                                                            // It will also cause minor visual glitches of shadow and reflection sprites adjusting their transparency when the pop-up disappear

// Pokémon Center
#define OW_IGNORE_EGGS_ON_HEAL           GEN_LATEST         // In Gen 4+, the nurse in the Pokémon Center does not heal Eggs on healing machine.
#define OW_UNION_DISABLE_CHECK           TRUE               // When TRUE, the nurse does not inform the player if there is a trainer waiting in the Union Room. This speeds up the loading of the Pokémon Center.
#define OW_FLAG_MOVE_UNION_ROOM_CHECK    0                  // If this flag is set, the game will only check if players are in the Union Room while healing Pokémon, and not when players enter the Pokémon Center. This speeds up the loading of the Pokémon Center. This is ignored if OW_UNION_DISABLE_CHECK is TRUE.

// Berry Blender
#define BERRY_BLENDER_THROW_ALL_BERRIES_AT_ONCE TRUE        // This is a small little addition, that basically speeds up the animation where all players' berries are thrown into the blender. Self-explanatory I hope!

// Trainer Rematches
#define OW_REMATCH_BADGE_COUNT      5 // Number of badges necessary before the match call or vs seeker features allow rematches

#endif // GUARD_CONFIG_OVERWORLD_H
