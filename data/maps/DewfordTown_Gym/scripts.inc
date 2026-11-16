DewfordTown_Gym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, DewfordTown_Gym_OnLoad
    map_script MAP_SCRIPT_ON_RESUME, DewfordTown_Gym_OnResume
    map_script MAP_SCRIPT_ON_FRAME_TABLE, DewfordTown_Gym_OnFrame
    .byte 0
 
 DewfordTown_Gym_OnResume:
    special StartMirrorButtonWatcher
    end

DewfordTown_Gym_OnFrame:
    map_script_2 VAR_TEMP_1, 1, DewfordTown_Gym_EventScript_MirrorButtonPressed
    .2byte 0

DewfordTown_Gym_OnLoad:
    call DewfordTown_Gym_EventScript_MirrorGatesOnLoad
    end
    
DewfordTown_Gym_EventScript_MirrorGatesOnLoad::
    goto_if_unset FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_MirrorGatesReset
    goto_if_unset FLAG_DEWFORD_GYM_MIRROR_DONE, DewfordTown_Gym_EventScript_MirrorGatesReset
    call DewfordTown_Gym_EventScript_OpenMirrorGate5
    return

DewfordTown_Gym_EventScript_MirrorGatesReset::
    clearflag FLAG_TEMP_1
    clearflag FLAG_TEMP_2
    clearflag FLAG_TEMP_3
    clearflag FLAG_TEMP_4
    clearflag FLAG_DEWFORD_GYM_MIRROR_DONE
    return          @ the ROM layout already has the gates closed
    
DewfordTown_Gym_EventScript_MirrorButtonPressed::
    lockall
    setvar VAR_TEMP_1, 0
    switch VAR_TEMP_2
    case 2342, DewfordTown_Gym_EventScript_MirrorButton1   @ button at (23, 42)
    case 1826,  DewfordTown_Gym_EventScript_MirrorButton2  @ button at (18, 26)
    case 1018, DewfordTown_Gym_EventScript_MirrorButton4   @ button at (10, 18)
    goto DewfordTown_Gym_EventScript_MirrorButtonDone

DewfordTown_Gym_EventScript_MirrorButton1::
    goto_if_set FLAG_TEMP_1, DewfordTown_Gym_EventScript_MirrorButtonDone
    setflag FLAG_TEMP_1
    call DewfordTown_Gym_EventScript_OpenMirrorGate1
    goto DewfordTown_Gym_EventScript_MirrorGateOpened
    
DewfordTown_Gym_EventScript_MirrorButton2::
    goto_if_set FLAG_TEMP_2, DewfordTown_Gym_EventScript_MirrorButtonDone
    setflag FLAG_TEMP_2
    call DewfordTown_Gym_EventScript_OpenMirrorGate2
    goto DewfordTown_Gym_EventScript_MirrorGateOpened
    
DewfordTown_Gym_EventScript_MirrorButton3::
    goto_if_set FLAG_TEMP_3, DewfordTown_Gym_EventScript_MirrorButtonDone
    setflag FLAG_TEMP_3
    call DewfordTown_Gym_EventScript_OpenMirrorGate3
    goto DewfordTown_Gym_EventScript_MirrorGateOpened

DewfordTown_Gym_EventScript_MirrorButton4::
    goto_if_set FLAG_TEMP_4, DewfordTown_Gym_EventScript_MirrorButtonDone
    setflag FLAG_TEMP_4
    call DewfordTown_Gym_EventScript_OpenMirrorGate4
    goto DewfordTown_Gym_EventScript_MirrorGateOpened
    
DewfordTown_Gym_EventScript_MirrorGateOpened::
    special DrawWholeMapView
    playse SE_UNLOCK
    goto_if_unset FLAG_TEMP_1, DewfordTown_Gym_EventScript_MirrorButtonDone
    goto_if_unset FLAG_TEMP_2, DewfordTown_Gym_EventScript_MirrorButtonDone
    goto_if_unset FLAG_TEMP_3, DewfordTown_Gym_EventScript_MirrorButtonDone
    goto_if_unset FLAG_TEMP_4, DewfordTown_Gym_EventScript_MirrorButtonDone
    setflag FLAG_DEWFORD_GYM_MIRROR_DONE
    goto DewfordTown_Gym_EventScript_MirrorButtonDone

DewfordTown_Gym_EventScript_MirrorButtonDone::
    releaseall
    end

DewfordTown_Gym_EventScript_OpenMirrorGate1::
    setmetatile 21, 36, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 21, 37, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 20, 36, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 20, 37, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 22, 36, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 22, 37, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 14,  33, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 14,  34, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 13,  33, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 13,  34, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 15,  33, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 15,  34, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 23,  42, METATILE_PapillysGym_button_pressed_dark, FALSE
    return
    
DewfordTown_Gym_EventScript_OpenMirrorGate2::
    setmetatile 10, 27, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 10, 28, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 9,  27, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 9,  28, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 11, 27, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 11, 28, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 18, 26, METATILE_PapillysGym_button_pressed_dark, FALSE
    return
    
DewfordTown_Gym_EventScript_OpenMirrorGate3::
    setmetatile 20, 15, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 20, 16, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 19, 15, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 19, 16, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 21, 15, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 21, 16, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 16, 17, METATILE_PapillysGym_button_pressed_dark, FALSE
    return

DewfordTown_Gym_EventScript_OpenMirrorGate4::
    setmetatile 14, 13, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 14, 14, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 13, 13, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 13, 14, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 15, 13, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 15, 14, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 10, 18, METATILE_PapillysGym_button_pressed_dark, FALSE
    return

DewfordTown_Gym_EventScript_OpenMirrorGate5::
    setmetatile 3, 15, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 3, 16, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 2, 15, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 2, 16, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 4, 15, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 4, 16, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 3, 25, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 3, 26, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 2, 25, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 2, 26, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 4, 25, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 4, 26, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    setmetatile 3, 35, METATILE_PapillysGym_gym_door_open_top_middle, FALSE
    setmetatile 3, 36, METATILE_PapillysGym_gym_door_open_bottom_middle, FALSE
    setmetatile 2, 35, METATILE_PapillysGym_gym_door_open_top_left, TRUE
    setmetatile 2, 36, METATILE_PapillysGym_gym_door_open_bottom_left, TRUE
    setmetatile 4, 35, METATILE_PapillysGym_gym_door_open_top_right, TRUE
    setmetatile 4, 36, METATILE_PapillysGym_gym_door_open_bottom_right, TRUE
    return
    
DewfordTown_Gym_EventScript_MirrorRespawn1Trigger::
    call DewfordTown_Gym_EventScript_RespawnMirrorNpc
    release
    end
    
DewfordTown_Gym_EventScript_RespawnMirrorNpc::
    copyobjectxytoperm 9      @ local id, new x, new y (Porymap coords)
    removeobject 9
    addobject 9
    return

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_ROXANNE_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
    	call DewfordTown_Gym_EventScript_OpenMirrorGate5
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_HG_POKEGEAR_REGISTERED
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	goto_if_set FLAG_TEMP_1, DewfordTown_Gym_EventScript_GymGuideGotWater
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER
	setflag FLAG_TEMP_1
	release
	end

DewfordTown_Gym_EventScript_GymGuideGotWater::
	msgbox DewfordTown_Gym_Text_GymGuideAdviceNoWater, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going,\n"
	.string "Champ-to-be?\p"
	.string "Before I tell you about the Gym\n"
	.string "Leader, you need to know about the\l"
	.string "Gym's puzzle.\p"
	.string "You see that Slowking to your right?\p"
	.string "It's reading your mind to follow your\n"
	.string "movements.\p"
	.string "The goal of this puzzle is to partner\n"
	.string "up with the Slowking to press buttons\l"
	.string "to open up the doors blocking your path.\p"
	.string "Now, what kind of foes are you\n"
	.string "going to find here?\p"
	.string "Joridan City's Gym Leader, Josh, teaches\n"
	.string "Double Battles at the University.\p"
	.string "Thus, all of the trainers in this Gym\n"
	.string "partner up in double battles.\p"
	.string "Furthermore, Josh is also a specialist\n"
	.string "in the Normal-type.\p"
	.string "You might not think much of the Normal-\n"
	.string "type, but they're more difficult to\l"
	.string "handle than you might expect!\p"
	.string "They're bulky and well-balanced, and\n"
	.string "they have many moves to support their\l"
	.string "partners in a double battle.\p"
	.string "Fighting-type moves are going to help\n"
	.string "a lot, but even more than that…\p"
	.string "I recommend stocking up on healing\n"
	.string "items and prepare for your Pokémon to\l"
	.string "partner up!\p"
	.string "Speaking of healing items, take this!$"

DewfordTown_Gym_Text_GymGuideAdviceNoWater:
	.string "So about the Gym's puzzle…\p"
	.string "That Slowking to your right is reading\n"
	.string "your mind to follow your movements.\p"
	.string "The goal of this puzzle is to partner\n"
	.string "up with the Slowking to press buttons\l"
	.string "to open up the doors blocking your path.\p"
	.string "Now, what kind of foes are you\n"
	.string "going to find here?\p"
	.string "All of the trainers in this Gym\n"
	.string "partner up in double battles.\p"
	.string "Josh is also a specialist in the\n"
	.string "Normal-type.\p"
	.string "So, Fighting-type moves are going to\n"
	.string "help a lot, but even more than that…\p"
	.string "I recommend stocking up on healing\n"
	.string "items and prepare for your Pokémon to\l"
	.string "partner up!\p"
	.string "Good luck, Champ-to-be!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Whoah! What a dynamic duo!\p"
	.string "You've got enough brain power to\n"
	.string "think for two!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "I must read my ally's moves!\n"
	.string "Come on!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Not on the same page…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Perhaps it would be easier to\n"
	.string "fight without a partner,\l"
	.string "but I only have one Pokémon…$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "I'm the finest fighter in this\n"
	.string "Gym!\p"
	.string "I'll crush you!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a Gym Leader!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Double battles have an extra element\n"
	.string "to their strategy that makes them\l"
	.string "much harder.\p"
	.string "I've been taking Josh's class for\n"
	.string "so long, but I don't see any progress…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\p"
	.string "Is it hard to think on the same page\n"
	.string "as the Slowking?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "going home crying!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "I'll show you the gumption of\n"
	.string "a seasoned scholar!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our Gym Leader.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that Badge!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Hello, young traveler!\n"
	.string "I'm Josh, the Joridan City Gym Leader!\p"
	.string "I've got to say, I don't really stand\n"
	.string "out all that much, but I've honed my\l"
	.string "skills enough to become Champion!\p"
	.string "If you want my Gym Badge, you'll\n"
	.string "need to demonstrate proficiency in\l"
	.string "the art of a double battle!\p"
	.string "Still want to take me on?\n"
	.string "Very well, let's see…\l"
	.string "how many badges do you have?\p"
	.string "One?\n"
	.string "Okay, I'll use this team then…\p"
	.string "Now, show me what you've got!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Impressive!\p"
	.string "You broke through my impenetrable\n"
	.string "defenses!\p"
	.string "I concede.\p"
	.string "By the power vested in me by the\n"
	.string "State of Banjime and it's Pokémon\l"
	.string "League, I bestow upon you this…\p"
	.string "Please accept the official Pokémon\n"
	.string "League Gemini Badge!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the Gemini Badge\n"
	.string "from Josh.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The Gemini Badge makes all Pokémon\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "Rock Smash outside of battle.\p"
	.string "Please accept this Technical\n"
	.string "Machine, too.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "TM94 contains Secret Power.\p"
	.string "It's a move that changes depending\n"
	.string "on the environment.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Registered Gym Leader Josh\n"
	.string "in the PokéNav.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Your journey is still long.\p"
	.string "My father is a Gym Leader in\n"
	.string "Redburro City.\p"
	.string "If you see him, please say hello\n"
	.string "for me!$"

DewfordTown_Gym_Text_GymStatue:
	.string "Joridan City Pokémon Gym\p"
	.string "Leader:\n"
	.string "Josh\p"
	.string "Certified Trainers in order of completion:\n"
	.string "Peter, Otnar, Ahab, Jelissa,\p"
	.string "Toxiana, Tinker, Moose, Gwen,\n"
	.string "Tobias, Ishmael, Adhira,\l"
	.string "Tiffany, Amelia, Sean$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "Joridan City Pokémon Gym\p"
	.string "Leader:\n"
	.string "Josh\p"
	.string "Certified Trainers in order of completion:\n"
	.string "Peter, Otnar, Ahab, Jelissa,\p"
	.string "Toxiana, Tinker, Moose, Gwen,\n"
	.string "Tobias, Ishmael, Adhira,\l"
	.string "Tiffany, Amelia, Sean\l"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
