PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
	call_if_eq VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_DisableMapNameAndMusic
	call_if_eq VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_DisableMapNameAndMusic
	call_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
	setobjectxyperm LOCALID_GYM_BOY, 38, 12
	return

PetalburgCity_EventScript_DisableMapNameAndMusic::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_FOLLOW_ME
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked::
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0

PetalburgCity_EventScript_WallyTutorial::
	lockall
	special SavePlayerParty
	special LoadWallyZigzagoon
	applymovement LOCALID_PETALBURG_WALLY, PetalburgCity_Movement_WallyTutorialWally
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WALLY, Common_Movement_WalkInPlaceFasterLeft, MAP_PETALBURG_CITY
	waitmovement LOCALID_PETALBURG_WALLY, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WalkToWallyHouse::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
	waitmovement 0
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 2, 4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_WallysMom::
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_EventScript_PoliceMan::
	msgbox PetalburgCity_Text_PoliceMan, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer:
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseWallysDad:
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHouseWallysDad:
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Movement_WallyTutorialWally:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_TrainSign::
	msgbox PetalburgCity_Text_TrainSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_HouseSign::
	msgbox PetalburgCity_Text_HouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0::
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1::
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2::
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3::
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer::
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_PETALBURG_CITY_STATE, 1
	playbgm MUS_FOLLOW_ME, FALSE
	playse SE_PIN
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_BoyApproachPlayer0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_BoyApproachPlayer1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_BoyApproachPlayer2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_LeadPlayerToGym0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_LeadPlayerToGym1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_LeadPlayerToGym2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

PetalburgCity_EventScript_OldLady::
	goto_if_set FLAG_BADGE01_GET, PetalburgCity_EventScript_CheckIfHasLetter
	goto PetalburgCity_EventScript_DoesntHaveLetter
	end

PetalburgCity_EventScript_GiveLetterToOldLady::
	lock
	faceplayer
	clearflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	msgbox PetalburgCity_Text_OldLady, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_LETTER
	playbgm MUS_FOLLOW_ME, FALSE
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_EventScript_OldLadyTrainSouth
	case DIR_NORTH, PetalburgCity_EventScript_OldLadyTrainNorth
	case DIR_WEST, PetalburgCity_EventScript_OldLadyTrainWest
	end

PetalburgCity_EventScript_CheckIfHasLetter::
	goto_if_set FLAG_RECEIVED_LETTER, PetalburgCity_EventScript_GiveLetterToOldLady
	goto PetalburgCity_EventScript_DoesntHaveLetter
	end

PetalburgCity_EventScript_DoesntHaveLetter::
	msgbox PetalburgCity_Text_OldLadyWhereHubby, MSGBOX_NPC
	end

PetalburgCity_EventScript_OldLadyTrainSouth::
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyTrainSouth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Text_OldLadyChewOut, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyReturnSouth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PetalburgCity_EventScript_EndOldLady
	end

PetalburgCity_EventScript_OldLadyTrainNorth::
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyTrainNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Text_OldLadyChewOut, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyReturnNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PetalburgCity_EventScript_EndOldLady
	end

PetalburgCity_EventScript_OldLadyTrainWest::
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyTrainWest
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Text_OldLadyChewOut, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyReturnWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PetalburgCity_EventScript_EndOldLady
	end

PetalburgCity_EventScript_EndOldLady::
	fadedefaultbgm
	msgbox PetalburgCity_Text_ComeToHouse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	applymovement LOCALID_PETALBURG_ANTONWIFE, PetalburgCity_Movement_OldLadyGoHome
	waitmovement 0
	removeobject LOCALID_PETALBURG_ANTONWIFE
	release
	end

@ Unused
PetalburgCity_Movement_Delay48::
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_OldLadyTrainSouth:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

PetalburgCity_Movement_OldLadyTrainNorth:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

PetalburgCity_Movement_OldLadyTrainWest:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

PetalburgCity_Movement_OldLadyReturnSouth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_OldLadyReturnWest:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

PetalburgCity_Movement_OldLadyReturnNorth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_OldLadyGoHome:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_BoyWalkToGym1:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_BoyWalkToGym2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_BoyWalkToGym3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Movement_PlayerWalkToGym1:
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Movement_PlayerWalkToGym2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Movement_PlayerWalkToGym3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 10
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 11
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott2::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 12
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott3::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 3
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 13
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott::
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_ScottExit0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_ScottExit1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_ScottExit2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_ScottExit3
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject LOCALID_PETALBURG_SCOTT
	releaseall
	end

PetalburgCity_EventScript_ScottExit0::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit3:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit3:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_EventScript_GymBoy::
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_WhereIsWally:
	.string "I am the mayor and Otnar's wife.\p"
	.string "In my younger days, I traveled with\n"
	.string "my husband, painting the scenes we\l"
	.string "saw along our many travels.\p"
	.string "Now, I help fund other artists who\n"
	.string "wish to pursue a career in art.$"

PetalburgCity_Text_AreYouRookieTrainer:
	.string "Hiya! Are you maybe…\n"
	.string "A rookie Trainer?\p"
	.string "Do you know what Pokémon Trainers\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of Gym\n"
	.string "is in the town.$"

PetalburgCity_Text_ThisIsPetalburgGym:
	.string "See? This is Papilys City's Gym.$"

PetalburgCity_Text_ThisIsGymSign:
	.string "This is the Gym's sign. Look for it\n"
	.string "whenever you're looking for a Gym.$"

PetalburgCity_Text_WaterReflection:
	.string "Most people come here as aspiring\n"
	.string "painters or sculptors.\p"
	.string "Me?\p"
	.string "I came here because I'm a fan of Otnar.\p"
	.string "He's an adventurer who has traversed\n"
	.string "across a multitude of terrains.\p"
	.string "From the frigid tundras around here\n"
	.string "to the scorching deserts of Redburro,\l"
	.string "Otnar's conquered it all!\p"
	.string "I hope to be a trainer like him\n"
	.string "who inspires young men to take on the\l"
	.string "treacherous world of the unknown!$"

PetalburgCity_Text_FullPartyExplanation:
	.string "Back in my day, this town was a\n"
	.string "mining town.\p"
	.string "We carved these buildings out of the\n"
	.string "mountain with our own two hands.\p"
	.string "Later, artists like Anton DeRoux\n"
	.string "came in and made our crude buildings\l"
	.string "into beautiful works of art.$"

PetalburgCity_Text_GymSign:
	.string "Papilys City Pokémon Gym\n"
	.string "Leader: Otnar\l"
	.string "“The cool-headed warrior!”$"

PetalburgCity_Text_CitySign:
	.string "Papilys City\n"
	.string "“Home of cliffside artists.”$"

PetalburgCity_Text_WallyHouseSign:
	.string "Otnar's Inn$"

PetalburgCity_Text_AreYouATrainer:
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a POKéMON TRAINER?$"

PetalburgCity_Text_WellMaybeNot:
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie TRAINER,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers:
	.string "I'm roaming the land in search of\n"
	.string "talented TRAINERS.\p"
	.string "I'm sorry to have taken your time.$"

PetalburgCity_Text_PoliceMan:
	.string "Sorry, but you can't enter here\n"
	.string "without a gym badge.$"

PetalburgCity_Text_HouseSign:
	.string "Papilys Art Studio$"

PetalburgCity_Text_OldLadyWhereHubby:
	.string "Oh, Anton…\n"
	.string "Where have you gone?\p"
	.string "If only there were a strong trainer\n"
	.string "around to help me…$"

PetalburgCity_Text_OldLady:
	.string "Is that letter for me?\n"
	.string "Thank you.\p"
	.string "Let's see…\n"
	.string "So the train has been delayed, eh?\p"
	.string "Well, that just won't do.\p"
	.string "I ought to give the conductor a piece\n"
	.string "of my mind!\p"
	.string "Pardon me…$"

PetalburgCity_Text_OldLadyChewOut:
	.string "Listen here, Mr. Conductor…\p"
	.string "You best bring my husband here,\n"
	.string "or I'm going to REDACTED BY GAME DEV\l"
	.string "to such a degree that you're going\l"
	.string "to REDACTED!\p"
	.string "REDACTED\n"
	.string "REDACTED…EXTENDED…\p"
	.string "…OH, YOU…YOU REALLY SHOULDN'T SAY\n"
	.string "THAT TO ANOTHER HUMAN BEING…\p"
	.string "THIS IS…\p"
	.string "…YEAH, I'M JUST GOING TO SKIP\n"
	.string "TO THE END OF HER DIALOGUE…\p"
	.string "Old Woman: Good day to you, sir!$"

PetalburgCity_Text_ComeToHouse:
	.string "Okay, my husband should be in soon.\n"
	.string "In the mean time, why don't you come\l"
	.string "visit our beloved art studio?$"

PetalburgCity_Text_TrainSign:
	.string "Papillys City Train Station$"

PetalburgCity_EventScript_N::
	lockall
	faceplayer
	msgbox PetalburgCity_Text_NMayIJoin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_EventScript_NNo
	setfollowernpc LOCALID_PETALBURG_CITY_N, FNPC_ALL, PetalburgCity_EventScript_NFollower, PARTNER_N_PETALBURG
	msgbox PetalburgCity_Text_GreatThanks, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_Text_NJoined, MSGBOX_SIGN
	closemessage
	releaseall
	end

PetalburgCity_EventScript_NNo::
	msgbox PetalburgCity_Text_ISee, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PetalburgCity_EventScript_NFollower::
	msgbox PetalburgCity_Text_NFollowMessage, MSGBOX_NPC
	end

PetalburgCity_EventScript_DancingCrew::
	lock
	msgbox PetalburgCity_Text_NotNow, MSGBOX_DEFAULT
	closemessage
	release
	end

PetalburgCity_EventScript_Line::
	msgbox PetalburgCity_Text_Line, MSGBOX_NPC
	end

PetalburgCity_Text_NMayIJoin:
	.string "???: Ah, Hello there.\n"
	.string "Who are you?\p"
	.string "{PLAYER}?\n"
	.string "Your Pokémon speak highly of you.\p"
	.string "I am an agent for the International\n"
	.string "Police.\p"
	.string "My na-codename is N.\p"
	.string "N: I'm currently working on a case,\n"
	.string "but I'm not a particularly strong\l"
	.string "trainer, you see.\p"
	.string "Thus, I'm looking for someone who\n"
	.string "could accompany me on this mission.\p"
	.string "Just to fend off some wild Pokémon\n"
	.string "in the cave, nothing more.\p"
	.string "What do you say, {PLAYER}?\n"
	.string "Would you be willing to lend a hand?$"

PetalburgCity_Text_GreatThanks:
	.string "N: Thank you, {PLAYER}.\p"
	.string "I'll try to make this quick so I\n"
	.string "don't take advantage of your time.$"

PetalburgCity_Text_NJoined:
	.string "{PLAYER} decided to go with N.\p"
	.string "N will automatically heal {PLAYER}'s\n"
	.string "party after each battle.$"

PetalburgCity_Text_ISee:
	.string "I see…\p"
	.string "Well, I'll wait here for you in case\n"
	.string "you change your mind.$"

PetalburgCity_Text_NFollowMessage:
	.string "N: The case?\n"
	.string "I'm limited in how much I can say…\p"
	.string "Let's just keep going, and let me\n"
	.string "know if you need any healing.$"

PetalburgCity_Text_NotNow:
	.string "Not now, we're in the middle of\n"
	.string "a shoot!$"

PetalburgCity_Text_Line:
	.string "The train's finally back in\n"
	.string "working condition!\p"
	.string "I have to board ASAP!$"


