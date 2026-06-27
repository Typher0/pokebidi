LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckGender
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckGender::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CallOutMale
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CallOutFemale
	return

LittlerootTown_BrendansHouse_2F_EventScript_CallOutMale::
	lockall
	msgbox BrendansHouse_2F_Text_CallOutMale, MSGBOX_DEFAULT
	delay 10
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_EveryoneEnters
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_EveryoneEnters
	return

LittlerootTown_BrendansHouse_2F_EventScript_CallOutFemale::
	lockall
	msgbox BrendansHouse_2F_Text_CallOutFemale, MSGBOX_DEFAULT
	delay 10
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_EveryoneEnters
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_EveryoneEnters
	return

LittlerootTown_BrendansHouse_2F_EventScript_EveryoneEnters::
	addobject LOCALID_PLAYERS_BEDROOM_SEAN
	addobject LOCALID_PLAYERS_BEDROOM_AMELIA
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, LittlerootTown_BrendansHouse_2F_Movement_RivalsEnter
	waitmovement 0
	applymovement LOCALID_PLAYERS_BEDROOM_AMELIA, LittlerootTown_BrendansHouse_2F_Movement_RivalsEnter
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerApproachFriends
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYERS_BEDROOM_AMELIA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BrendansHouse_2F_Text_SeanExcited, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_BEDROOM_AMELIA, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BrendansHouse_2F_Text_AmeliaIdiot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BrendansHouse_2F_Text_SeanClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_BEDROOM_AMELIA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BrendansHouse_2F_Text_AmeliaOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_BEDROOM_AMELIA, LittlerootTown_BrendansHouse_2F_Movement_AmeliaLeaves
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PLAYERS_BEDROOM_AMELIA
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchSean
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, LittlerootTown_BrendansHouse_2F_Movement_SeanWalksToClock
	waitmovement 0
	msgbox BrendansHouse_2F_Text_SeanClockNotSet, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_ComeSetClock::
	lockall
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_Release
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 10
	msgbox PlayersHouse_2F_Text_SeanComeSetClock, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_NoLeave
	applymovement LOCALID_PLAYERS_BEDROOM_SEAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

PlayersHouse_2F_EventScript_Release::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	releaseall
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAWii, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_2F_Movement_RivalsEnter:
	walk_up
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerApproachFriends:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_AmeliaLeaves:
	walk_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_SeanWalksToClock:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchSean:
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_BrendansHouse_2F_Movement_NoLeave:
	walk_up
	step_end

PlayersHouse_2F_SeanLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_ItsAWii:
	.string "It's your Nintendo Wii!\p"
	.string "A copy of The Legend of Zelda: Twilight\n"
	.string "Princess is loaded in the disc slot.$"

BrendansHouse_2F_Text_CallOutMale:
	.string "Sean: {PLAYER}!!!!!!!\n"
	.string "Are you ready to go on our adventure?!\p"
	.string "Amelia: SEAN!!!\n"
	.string "STOP!!!\p"
	.string "You can't just barge into people's room\n"
	.string "whenever you feel like it!$"

BrendansHouse_2F_Text_CallOutFemale:
	.string "Sean: {PLAYER}!!!!!!!\n"
	.string "Are you ready to go on our adventure?!\p"
	.string "Amelia: SEAN!!!\n"
	.string "STOP!!!\p"
	.string "You can't just barge into a girl's\n"
	.string "room whenever you feel like it!$"

BrendansHouse_2F_Text_SeanExcited:
	.string "Sean: {PLAYER}!\p"
	.string "Sorry for barging into your room\n"
	.string "whenever I feel like it!\p"
	.string "But today's the day we finally get\n"
	.string "our Pokémon partners!\p"
	.string "And you two were just taking forever\n"
	.string "to wake up, so I got Amelia and came here!$"

BrendansHouse_2F_Text_AmeliaIdiot:
	.string "Amelia: Sean, it is entirely reasonable\n"
	.string "to still be in bed at 6 A.M.$"

BrendansHouse_2F_Text_SeanClock:
	.string "Sean: Okay, but now it's like…\n"
	.string "Wait, what time is it?\p"
	.string "Amelia: Sean, you're hopeless.\n"
	.string "Go check {PLAYER}'s clock.$"

BrendansHouse_2F_Text_AmeliaOut:
	.string "Amelia: {PLAYER}, I'm heading out.\n"
	.string "I'll see you both in the Lab on Route 631.$"

BrendansHouse_2F_Text_SeanClockNotSet:
	.string "Sean: Yo, {PLAYER}, you forgot to\n"
	.string "set your clock!$"

PlayersHouse_2F_Text_SeanComeSetClock:
	.string "Sean: Yo, {PLAYER}, you forgot to\n"
	.string "set your clock!\p"
	.string "Come over here.\n"
	.string "I don't know how to do it.$"

PlayersHouse_2F_Text_ReadyToGo:
	.string "Sean: Okay, so that's the time.\n"
	.string "Let's head out to Route 631!$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "{REGION} region map.$"
