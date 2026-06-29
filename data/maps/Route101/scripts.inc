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
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
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
