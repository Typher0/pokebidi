LittlerootTown_UnicornLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_UnicornLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_UnicornLab_OnFrame
	.byte 0

LittlerootTown_UnicornLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 0, LittlerootTown_UnicornLab_EventScript_SetPlayerPosForReceiveStarter
	.2byte 0

LittlerootTown_UnicornLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

LittlerootTown_UnicornLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 0, LittlerootTown_UnicornLab_EventScript_GiveStarterEvent
	.2byte 0

LittlerootTown_UnicornLab_EventScript_GiveStarterEvent::
	lock
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_Intro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_SEAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_SeanRPS, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_AMELIA, LittlerootTown_UnicornLab_Movement_AmeliaHuddle
	applymovement LOCALID_UNICORN_LAB_SEAN, LittlerootTown_UnicornLab_Movement_SeanHuddle
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto LittlerootTown_UnicornLab_EventScript_RPS
	end

LittlerootTown_UnicornLab_EventScript_RPS::
	dynmultichoice 22, 10, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, LittlerootTown_UnicornLab_Text_RPSChoice1, LittlerootTown_UnicornLab_Text_RPSChoice2, LittlerootTown_UnicornLab_Text_RPSChoice3
	switch VAR_RESULT
	case 0, LittlerootTown_UnicornLab_EventScript_RPS_Win
	case 1, LittlerootTown_UnicornLab_EventScript_RPS_Win
	case 2, LittlerootTown_UnicornLab_EventScript_RPS_Win
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_RPS_Win::
	applymovement LOCALID_UNICORN_LAB_SEAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_PlayerWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_AMELIA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_CantBeHelped, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_AMELIA, LittlerootTown_UnicornLab_Movement_AmeliaGoBack
	applymovement LOCALID_UNICORN_LAB_SEAN, LittlerootTown_UnicornLab_Movement_SeanGoBack
	waitmovement 0
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_HeresBalls, MSGBOX_DEFAULT
	closemessage
	goto LittlerootTown_UnicornLab_EventScript_Safari
	end

LittlerootTown_UnicornLab_EventScript_Safari::
	setvar VAR_BIRCH_LAB_STATE, 1
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_Cyndaquil::
	lockall
	faceplayer
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_Cyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_UnicornLab_EventScript_EncounterCyndaquil
	msgbox LittlerootTown_UnicornLab_Text_SomeoneElseThen, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_CYNDAQUIL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_Rowlet::
	lockall
	faceplayer
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_Rowlet, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_UnicornLab_EventScript_EncounterRowlet
	msgbox LittlerootTown_UnicornLab_Text_SomeoneElseThen, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_ROWLET, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_Squirtle::
	lockall
	faceplayer
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_Squirtle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_UnicornLab_EventScript_EncounterSquirtle
	msgbox LittlerootTown_UnicornLab_Text_SomeoneElseThen, MSGBOX_DEFAULT
	applymovement LOCALID_UNICORN_LAB_SQUIRTLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	closemessage
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_EncounterCyndaquil::
	waitse
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5
	goto LittlerootTown_UnicornLab_EventScript_CyndaquilCaught
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_EncounterRowlet::
	waitse
	playmoncry SPECIES_ROWLET, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ROWLET
	givemon SPECIES_ROWLET, 5
	goto LittlerootTown_UnicornLab_EventScript_RowletCaught
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_EncounterSquirtle::
	waitse
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SQUIRTLE
	givemon SPECIES_SQUIRTLE, 5
	goto LittlerootTown_UnicornLab_EventScript_SquirtleCaught
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_CyndaquilCaught::
	removeobject LOCALID_UNICORN_LAB_CYNDAQUIL
	removeobject LOCALID_UNICORN_LAB_SQUIRTLE
	removeobject LOCALID_UNICORN_LAB_ROWLET
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setvar VAR_STARTER_MON, 1
	setvar VAR_0x8004, 0
	applymovement LOCALID_PLAYER, LittlerootTown_UnicornLab_Movement_PlayerReturnCyndaquil
	waitmovement 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_UnicornLab_EventScript_StarterCaught
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_UnicornLab_EventScript_StarterCaught
	end

LittlerootTown_UnicornLab_EventScript_RowletCaught::
	removeobject LOCALID_UNICORN_LAB_CYNDAQUIL
	removeobject LOCALID_UNICORN_LAB_SQUIRTLE
	removeobject LOCALID_UNICORN_LAB_ROWLET
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setvar VAR_STARTER_MON, 0
	setvar VAR_0x8004, 0
	applymovement LOCALID_PLAYER, LittlerootTown_UnicornLab_Movement_PlayerReturnRowlet
	waitmovement 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_UnicornLab_EventScript_StarterCaught
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_UnicornLab_EventScript_StarterCaught
	end

LittlerootTown_UnicornLab_EventScript_SquirtleCaught::
	removeobject LOCALID_UNICORN_LAB_CYNDAQUIL
	removeobject LOCALID_UNICORN_LAB_SQUIRTLE
	removeobject LOCALID_UNICORN_LAB_ROWLET
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setvar VAR_STARTER_MON, 2
	setvar VAR_0x8004, 0
	applymovement LOCALID_PLAYER, LittlerootTown_UnicornLab_Movement_PlayerReturnSquirtle
	waitmovement 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_UnicornLab_EventScript_StarterCaught
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_UnicornLab_EventScript_StarterCaught
	end

LittlerootTown_UnicornLab_EventScript_StarterCaught::
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	bufferleadmonspeciesname STR_VAR_1
	msgbox LittlerootTown_UnicornLab_Text_YouHavePokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, LittlerootTown_UnicornLab_Movement_UnicornGetDex
	waitmovement 0
	removeobject LOCALID_UNICORN_LAB_DEX_1
	removeobject LOCALID_UNICORN_LAB_DEX_2
	removeobject LOCALID_UNICORN_LAB_DEX_3
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, LittlerootTown_UnicornLab_Movement_UnicornReturn
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_HereDex, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_UnicornLab_Text_DexGet
	waitmessage
	waitfanfare
	setvar VAR_ROUTE101_STATE, 1
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	msgbox LittlerootTown_UnicornLab_Text_FinishIt, MSGBOX_DEFAULT
	closemessage
	goto LittlerootTown_UnicornLab_EventScript_SeanWantBattle
	end

LittlerootTown_UnicornLab_EventScript_SeanWantBattle::
	applymovement LOCALID_UNICORN_LAB_SEAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	bufferleadmonspeciesname STR_VAR_1
	msgbox LittlerootTown_UnicornLab_Text_WeGotMonNowFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_AMELIA, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_GoodIdea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_SEAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_SeanLetsFight, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

LittlerootTown_UnicornLab_EventScript_AmeliaWantBattle::
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_HealParty, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_UNICORN_LAB_AMELIA, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_AmeliaLetsFight, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

LittlerootTown_UnicornLab_EventScript_TimeToLeave::
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_HealParty, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox LittlerootTown_UnicornLab_Text_UnicornDips, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, LittlerootTown_UnicornLab_Movement_UnicornLeaves
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_UNICORN_LAB_PROF_UNICORN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_SeanLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 
	msgbox LittlerootTown_UnicornLab_Text_AmeliaPokeBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_UnicornLab_Text_AmeliaLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNICORN_LAB_SEAN, LittlerootTown_UnicornLab_Movement_UnicornLeaves
	applymovement LOCALID_UNICORN_LAB_AMELIA, LittlerootTown_UnicornLab_Movement_UnicornLeaves
	waitmovement 0
	removeobject LOCALID_UNICORN_LAB_SEAN
	removeobject LOCALID_UNICORN_LAB_AMELIA
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setvar VAR_ROUTE101_STATE, 1
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setflag FLAG_UNUSED_0x264
	playse SE_EXIT
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_DontLeave::
	lockall
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 10
	waitmovement 0
	msgbox LittlerootTown_UnicornLab_Text_DontLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_UnicornLab_Movement_PlayerDown
	waitmovement 0
	applymovement LOCALID_UNICORN_LAB_PROF_UNICORN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

LittlerootTown_UnicornLab_EventScript_TableScientistM::
	msgbox LittlerootTown_UnicornLab_Text_TableScientistM, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_TableScientistF::
	msgbox LittlerootTown_UnicornLab_Text_TableScientistF, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_SideShelfScientist::
	msgbox LittlerootTown_UnicornLab_Text_SideShelfScientist, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_NorthShelfScientistM::
	msgbox LittlerootTown_UnicornLab_Text_NorthShelfScientistM, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_NorthShelfScientistF::
	msgbox LittlerootTown_UnicornLab_Text_NorthShelfScientistF, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_Sign::
	msgbox LittlerootTown_UnicornLab_Text_Sign, MSGBOX_SIGN
	release
	end

LittlerootTown_UnicornLab_EventScript_Sean::
	msgbox LittlerootTown_UnicornLab_Text_SeanChat, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_Amelia::
	msgbox LittlerootTown_UnicornLab_Text_AmeliaChat, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_EventScript_Unicorn::
	msgbox LittlerootTown_UnicornLab_Text_UnicornChat, MSGBOX_NPC
	release
	end

LittlerootTown_UnicornLab_Movement_AmeliaHuddle:
	walk_up
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_UnicornLab_Movement_SeanHuddle:
	walk_up
	walk_right
	step_end

 LittlerootTown_UnicornLab_Movement_SeanGoBack:
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

 LittlerootTown_UnicornLab_Movement_AmeliaGoBack:
	delay_16
	walk_down
	walk_in_place_faster_up
	step_end

LittlerootTown_UnicornLab_Movement_PlayerReturnCyndaquil:
	walk_up
	step_end

LittlerootTown_UnicornLab_Movement_PlayerReturnRowlet:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

LittlerootTown_UnicornLab_Movement_PlayerReturnSquirtle:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LittlerootTown_UnicornLab_Movement_UnicornGetDex:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	delay_16
	step_end

LittlerootTown_UnicornLab_Movement_UnicornReturn:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_UnicornLab_Movement_UnicornLeaves:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

LittlerootTown_UnicornLab_Movement_PlayerDown:
	walk_down
	step_end

LittlerootTown_UnicornLab_Text_Intro:
	.string "Prof. Unicorn: Ah, there you all are!\p"
	.string "{PLAYER}, Amelia, and Sean,\n"
	.string "so good to see you!\p"
	.string "You've worked hard to get your\n"
	.string "Pokémon Training License at Banjime U,\l"
	.string "and now, you get your starter!\p"
	.string "Behind you are three Pokémon\n"
	.string "handpicked by me as the best starters.\p"
	.string "As for who picks first, I think\n"
	.string "you settled on rock-paper-scissors,\l"
	.string "right?$"

LittlerootTown_UnicornLab_Text_SeanRPS:
	.string "Sean: That's right!\n"
	.string "I'm totally going to win!$"

LittlerootTown_UnicornLab_Text_RPSChoice1:
	.string "Rock$"

LittlerootTown_UnicornLab_Text_RPSChoice2:
	.string "Paper$"

LittlerootTown_UnicornLab_Text_RPSChoice3:
	.string "Scissors$"

LittlerootTown_UnicornLab_Text_PlayerWon:
	.string "Sean: Aw man!\n"
	.string "{PLAYER} won!$"

LittlerootTown_UnicornLab_Text_CantBeHelped:
	.string "Amelia: It can't be helped,\n"
	.string "{PLAYER} is the victor.$"

LittlerootTown_UnicornLab_Text_HeresBalls:
	.string "Prof. Unicorn: Okay, so {PLAYER}\n"
	.string "will pick a Pokémon first.\p"
	.string "{PLAYER}, go ahead and choose which\n"
	.string "Pokémon you want to be your partner.$"

LittlerootTown_UnicornLab_Text_Cyndaquil:
	.string "Prof. Unicorn: That is the Fire-\n"
	.string "type Pokémon, Cyndaquil.\p"
	.string "{PLAYER}, is that the Pokémon\n"
	.string "you want?$"

LittlerootTown_UnicornLab_Text_SomeoneElseThen:
	.string "Prof. Unicorn: Take your time, find\n"
	.string "the Pokémon that suits you best.$"

LittlerootTown_UnicornLab_Text_Rowlet:
	.string "Prof. Unicorn: That is the Grass-\n"
	.string "type Pokémon, Rowlet.\p"
	.string "{PLAYER}, is that the Pokémon\n"
	.string "you want?$"

LittlerootTown_UnicornLab_Text_Squirtle:
	.string "Prof. Unicorn: That is the Water-\n"
	.string "type Pokémon, Squirtle.\p"
	.string "{PLAYER}, is that the Pokémon\n"
	.string "you want?$"

LittlerootTown_UnicornLab_Text_YouHavePokemon:
	.string "Prof. Unicorn: Ah, {PLAYER}, what\n"
	.string "a fine {STR_VAR_1} you've chosen!\p"
	.string "Now then…$"

LittlerootTown_UnicornLab_Text_HereDex:
	.string "Prof. Unicorn: Alright, so here's\n"
	.string "this thing-it's called a PokéDex.\p"
	.string "It's used to keep track of Pokémon\n"
	.string "you've met along your journey.$"

LittlerootTown_UnicornLab_Text_DexGet:
	.string "{PLAYER} received the PokéDex!\n"
	.string "It is currently set to Banjime Mode.$"

LittlerootTown_UnicornLab_Text_FinishIt:
	.string "Prof. Unicorn: Your final assignment\n"
	.string "is to finish this PokéDex.\p"
	.string "Granted, you've already graduated, so\n"
	.string "I don't really care if you do it or not.\p"
	.string "Heck, I already have a finished one,\n"
	.string "so if you don't do it, it's whatever.$"

LittlerootTown_UnicornLab_Text_WeGotMonNowFight:
	.string "Sean: {PLAYER}!\p"
	.string "Now that we're both trainers,\n"
	.string "let me battle your {STR_VAR_1}!\p"
	.string "This is the moment we've been working\n"
	.string "towards for the last four years!$"

LittlerootTown_UnicornLab_Text_GoodIdea:
	.string "Amelia: Good idea, Sean.\p"
	.string "You and {PLAYER} battle first,\n"
	.string "and then I'll face the winner.$"

LittlerootTown_UnicornLab_Text_SeanLetsFight:
	.string "Sean: See, even Amelia agrees!\p"
	.string "{PLAYER}, prepare yourself!\n"
	.string "Because my new friend and I are\l"
	.string "coming for you!$"

LittlerootTown_UnicornLab_Text_AmeliaLetsFight:
	.string "Amelia: Not bad, either of you!\n"
	.string "Okay, {PLAYER}, I'm up next.\p"
	.string "Show me what you've got!$"

LittlerootTown_UnicornLab_Text_HealParty:
	.string "Prof Unicorn: Great battle, you two!\n"
	.string "Here, let me heal your Pokémon.$"

LittlerootTown_UnicornLab_Text_UnicornDips:
	.string "Prof Unicorn: And with that, I'm\n"
	.string "going to head out.\p"
	.string "If you're ever in Arkane City, feel\n"
	.string "free to stop by my main office.\p"
	.string "I've got way more cool stuff there.\p"
	.string "See you later!$"

LittlerootTown_UnicornLab_Text_SeanLeave:
	.string "Sean: We better get going, too. I\p"
	.string "think I'm going to go to Papillys\n"
	.string "City to toughen up at the gym.$"

LittlerootTown_UnicornLab_Text_AmeliaPokeBalls:
	.string "Amelia: Personally, I think I'll go\n"
	.string "to Bloomngrove Forest first.\p"
	.string "I've heard there's a rare Pokémon\n"
	.string "there that will be useful against\l"
	.string "Papillys City's Gym Leader.\p"
	.string "{PLAYER}, you don't have Poké Balls,\n"
	.string "do you?\p"
	.string "Here, take these.$"

LittlerootTown_UnicornLab_Text_AmeliaLeave:
	.string "Amelia: See you around, {PLAYER}!$"

LittlerootTown_UnicornLab_Text_DontLeave:
	.string "Prof Unicorn: {PLAYER}, where the\n"
	.string "heck are you going?\p"
	.string "The Pokémon are over here,\n"
	.string "not up there.\p"
	.string "Come back!$"

LittlerootTown_UnicornLab_Text_TableScientistM:
	.string "We're developing a device to\n"
	.string "recreate weather and terrain in\l"
	.string "controlled environments.\p"
	.string "It's still a work in progress, though.$"

LittlerootTown_UnicornLab_Text_TableScientistF:
	.string "If we can reproduce weather and\n"
	.string "terrain in a laboratory, we could\l"
	.string "study Pokémon in their native\l"
	.string "environments without making\l"
	.string "outpost laboratories everywhere.\p"
	.string "Not that these labs aren't valuable,\n"
	.string "but we must invade nature to build\l"
	.string "them.\p"
	.string "Not to mention, we still must\n"
	.string "travel around the area to study\l"
	.string "the Routes surrounding this Lab.$"

LittlerootTown_UnicornLab_Text_SideShelfScientist:
	.string "The books on this shelf are\n"
	.string "the catalogues we created about\l"
	.string "the Pokémon on Route 631.\p"
	.string "They're quite comprehensive!$"

LittlerootTown_UnicornLab_Text_NorthShelfScientistM:
	.string "This laboratory is built to maximize\n"
	.string "the quality of our research space.\p"
	.string "It's great…\p"
	.string "But I really wish I could look out\n"
	.string "the window…$"

LittlerootTown_UnicornLab_Text_NorthShelfScientistF:
	.string "Fire, Water, and Grass…\p"
	.string "Our professor prepared his favorite\n"
	.string "Pokémon of each of those types\l"
	.string "for you and your friends.\p"
	.string "He felt that those types would\n"
	.string "be the best choice for the three\l"
	.string "of you on account of the type\l"
	.string "triangle they make.$"

LittlerootTown_UnicornLab_Text_Sign:
	.string "The sign details the anatomy of an\n"
	.string "orange Pokémon with fire on its tail.\p"
	.string "Beside it, there's another poster\n"
	.string "showing multiple types of Poké Balls.$"

LittlerootTown_UnicornLab_Text_SeanChat:
	.string "{PLAYER}, which Pokémon are you\n"
	.string "thinking of taking?\p"
	.string "I don't want to influence your decision,\n"
	.string "but I've got my eye on someone…$"

LittlerootTown_UnicornLab_Text_AmeliaChat:
	.string "…\p"
	.string "Oh, sorry, {PLAYER}, I was just\n"
	.string "thinking about which Pokémon to take.\p"
	.string "It's important to consider how this\n"
	.string "selection will influence the rest of\l"
	.string "my team…$"

LittlerootTown_UnicornLab_Text_UnicornChat:
	.string "{PLAYER}, what do you want?\p"
	.string "The Pokémon are over there.\n"
	.string "I don't know what you're confused about.\p"
	.string "Just, like, go pick a Pokémon already.$"


