LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
	end

LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_HideMapNamePopup::
	return

LittlerootTown_EventScript_SetRivalLeftForRoute103::
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_MoveRivalFromOldale::
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return


LittlerootTown_EventScript_SetTwinPos::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos::
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_OnFrame:
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_EventScript_BeginDexUpgradeScene::
	lockall
	playse SE_PIN
	applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_OnWarp:
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
	addobject LOCALID_LITTLEROOT_BIRCH
	addobject LOCALID_LITTLEROOT_RIVAL
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
	end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_Lady::
	msgbox LittlerootTown_Text_Lady, MSGBOX_NPC
	end

LittlerootTown_EventScript_Gentleman::
	goto_if_set FLAG_BADGE01_GET, LittlerootTown_EventScript_GentlemanMissedWife
	goto_if_set FLAG_RECEIVED_LETTER, LittlerootTown_EventScript_GentlemanGoDeliver
	lock
	faceplayer
	msgbox LittlerootTown_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_LETTER
	waitfanfare
	setflag FLAG_RECEIVED_LETTER
	release
	end

LittlerootTown_EventScript_GentlemanGoDeliver::
	msgbox LittlerootTown_Text_DeliverPlease, MSGBOX_NPC
	end

LittlerootTown_EventScript_GentlemanMissedWife::
	msgbox LittlerootTown_Text_MissedWife, MSGBOX_NPC
	end

LittlerootTown_EventScript_RoadblockMan::
	goto_if_set FLAG_SYS_POKEMON_GET, LittlerootTown_EventScript_RoadblockManHasPKMN
	msgbox LittlerootTown_Text_ProfWaiting, MSGBOX_NPC
	end

LittlerootTown_EventScript_RoadblockManHasPKMN::
	msgbox LittlerootTown_Text_YouHavePKMN, MSGBOX_NPC
	end

LittlerootTown_EventScript_ManSouth::
	lockall
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_RoadblockSouth
	waitmovement 0
	msgbox LittlerootTown_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_MoveRight
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_MoveRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_BackToBenchSouth
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_ManMid::
	lockall
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_RoadblockMid
	waitmovement 0
	msgbox LittlerootTown_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_MoveRight
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_MoveRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_BackToBenchMid
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_ManNorth::
	lockall
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_RoadblockNorth
	waitmovement 0
	msgbox LittlerootTown_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_MoveRight
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_MoveRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_LITTLEROOTTOWN_ROADBLOCKMAN, LittlerootTown_Movement_BackToBenchNorth
	waitmovement 0
	releaseall
	end

LittlerootTown_Movement_MoveRight:
	walk_right
	step_end

LittlerootTown_Movement_RoadblockSouth:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_BackToBenchSouth:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

LittlerootTown_Movement_RoadblockMid:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_BackToBenchMid:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

LittlerootTown_Movement_RoadblockNorth:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_BackToBenchNorth:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignMale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignMale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_SetHomeDoorCoordsMale::
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_Text_CanUsePCToStoreItems:
	.string "Did you know that the first sandwich\n"
	.string "was made to feed a gambling addiction?\p"
	.string "A lord in Hisui wanted food he could\n"
	.string "eat without leaving the gambling table.$"

LittlerootTown_Text_BirchSpendsDaysInLab:
	.string "The train station allows you to\n"
	.string "travel to cities you've visited\l"
	.string "more quickly.\p"
	.string "The train goes to Papilys City\n"
	.string "and to Joridan City.$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch:
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign:
	.string "Zephyr Town\n"
	.string "“Where winds blow in new beginnings.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "Sean's House$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "Amelia's House$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

LittlerootTown_Text_Gentleman:
	.string "Hello there, young traveler!\n"
	.string "My name is Anton, what is yours?\p"
	.string "{PLAYER}?\n"
	.string "Is that right?\l"
	.string "Well met!\p"
	.string "{PLAYER}…\p"
	.string "I have something I wish to share\n"
	.string "with you, a fledgling trainer.\p"
	.string "Sometimes, I think to myself,\p"
	.string "“Anton, you simply must board\n"
	.string "the train at Zephyr Town.”\p"
	.string "Far too often, I've talked myself\n"
	.string "out of it.\p"
	.string "Now, I've been waiting here for\n"
	.string "hours thinking,\p"
	.string "“Anton, you've really gone and\n"
	.string "screwed it up this time.\p"
	.string "Now, your wife in Papilys is going\n"
	.string "to be absolutely furious that you\l"
	.string "are not home for dinner.”\p"
	.string "Please, would you take this letter\n"
	.string "to my wife, explaining my absence?$"

LittlerootTown_Text_DeliverPlease:
	.string "I implore you,\n"
	.string "Please deliver this letter to my wife.\p"
	.string "We live East of here, in Papilys City.\p"
	.string "If you're thinking about taking the\n"
	.string "Gym Challenge, you'll need to go there\l"
	.string "anyways, so it is worth your while.$"

LittlerootTown_Text_MissedWife:
	.string "{PLAYER}!\n"
	.string "Greetings!\p"
	.string "I see you have the Gym Badge from\n"
	.string "Papilys City, and yet you still\l"
	.string "carry my letter.\p"
	.string "Surely you have not forgotten your\n"
	.string "promise to me, and perhaps just\l"
	.string "missed her?\p"
	.string "Please, return to Papilys City\n"
	.string "and deliver my letter.\p"
	.string "I can assure you that you will\n"
	.string "be adequately rewarded.$"

LittlerootTown_Text_Lady:
	.string "It's great that I can take this\n"
	.string "train to Joridan City,\p"
	.string "but who can I get back home to\n"
	.string "Arkane City?$"

LittlerootTown_Text_NeedPokemon:
	.string "Hey, {PLAYER}!\n"
	.string "Slow down there!\p"
	.string "You need a Pokémon before you\n"
	.string "Can go into the forest.\p"
	.string "Route 631 is Southeast from here.\p"
	.string "I think Prof. Unicorn is there\n"
	.string "waiting for you and your friends.$"

LittlerootTown_Text_ProfWaiting:
	.string "Hey, {PLAYER}!\n"
	.string "Route 631 is Southeast from here.\p"
	.string "I think Prof. Unicorn is there\n"
	.string "waiting for you and your friends.$"

LittlerootTown_Text_YouHavePKMN:
	.string "Hey, {PLAYER}!\n"
	.string "Is this Pokémon from the Professor?\p"
	.string "They're real cute, that's for sure!\n"
	.string "You've made an excellent choice.$"


