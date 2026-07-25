Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_Sign::
	msgbox Route101_Text_Sign, MSGBOX_SIGN
	end

Route101_EventScript_LabSign::
	msgbox Route101_Text_LabSign, MSGBOX_SIGN
	end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_Scientist::
	msgbox Route101_Text_LookAtTheLake, MSGBOX_NPC
	end

Route101_EventScript_SeanLeft::
	lockall
	setvar VAR_ROUTE101_STATE, 1
	playse SE_PIN
	applymovement LOCALID_ROUTE101_SEAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE101_SEAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE101_SEAN, Route101_Movement_SeanLeft
	waitmovement 0
	msgbox Route101_Text_GoToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE101_SEAN, Route101_Movement_SeanLab
	applymovement LOCALID_PLAYER, Route101_Movement_PlayerLab
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 20
	playse SE_EXIT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_UNICORN_LAB, 11, 11
	waitstate
	releaseall
	end

Route101_EventScript_SeanRight::
	lockall
	setvar VAR_ROUTE101_STATE, 1
	playse SE_PIN
	applymovement LOCALID_ROUTE101_SEAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE101_SEAN, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE101_SEAN, Route101_Movement_SeanRight
	waitmovement 0
	msgbox Route101_Text_GoToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE101_SEAN, Route101_Movement_SeanLabRight
	applymovement LOCALID_PLAYER, Route101_Movement_PlayerLabRight
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 20
	playse SE_EXIT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_UNICORN_LAB, 11, 11
	waitstate
	releaseall
	end

Route101_Movement_SeanLeft:
	walk_up
	step_end

Route101_Movement_SeanRight:
	walk_right
	walk_up
	step_end

Route101_Movement_SeanLab:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	delay_16
	step_end

Route101_Movement_SeanLabRight:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	delay_16
	step_end

Route101_Movement_PlayerLab:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	step_end

Route101_Movement_PlayerLabRight:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	step_end

Route101_Text_GoToLab:
	.string "Sean: {PLAYER}!\n"
	.string "There you are!\p"
	.string "The Lab's right here, come with\n"
	.string "me, and let's get our first Pokémon!$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "You see that golden tree over there?\n"
	.string "That's a honey tree.\p"
	.string "If you slather honey on it,\n"
	.string "a Pokémon will jump right out!$"

Route101_Text_WildPokemonInTallGrass:
	.string "There are so many places you can find\n"
	.string "wild Pokémon.\p"
	.string "Climates like this tend to have\n"
	.string "Ice-types, like Hamsnug.\p"
	.string "If you want a variety of types,\n"
	.string "You should go to different places.$"

Route101_Text_LookAtTheLake:
	.string "Take a look at that…\n"
	.string "That lake is Lake Transcendence.\p"
	.string "I must say, she's very aptly named…\p"
	.string "Lake Transcendence is the largest\n"
	.string "Lake in Banjime.\p"
	.string "As such, Prof. Unicorn chose to\n"
	.string "set up observation labs on either\l"
	.string "side of the lake.\p"
	.string "We've discovered many new species\n"
	.string "of Pokémon here in the last few years.$"

Route101_Text_RouteSign:
	.string "Route 631\p"
	.string "{UP_ARROW} Zephyr Town\n"
	.string "{DOWN_ARROW} Albatross Town$"

Route101_Text_Sign:
	.string "Trainer Tips!\p"
	.string "There are two kinds of icy\n"
	.string "status conditions.\p"
	.string "A Pokémon can be Frozen by Ice-type\n"
	.string "Special moves, like Ice Beam.\p"
	.string "If hit by a Physical move, like\n"
	.string "Ice Punch, it could get Frostbite.$"

Route101_Text_LabSign:
	.string "Unicorn Research Laboratory\n"
	.string "Zephyr Town Branch$"
