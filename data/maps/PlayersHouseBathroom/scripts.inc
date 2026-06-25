PlayersHouseBathroom_MapScripts::
	.byte 0

PlayersHouseBathroom_EventScript_Sink::
	lockall
	switch VAR_TEMP_4
	case 0, PlayersHouseBathroom_EventScript_Sink_On
	case 1, PlayersHouseBathroom_EventScript_Sink_Off
	end

PlayersHouseBathroom_EventScript_Sink_Off::
	setmetatile 4, 1, METATILE_PlayersHouse_Sink_Off_Left, TRUE
	setmetatile 5, 1, METATILE_PlayersHouse_Sink_Off_Right, TRUE
	special DrawWholeMapView
	releaseall
	end

PlayersHouseBathroom_EventScript_Sink_On::
	setmetatile 4, 1, METATILE_PlayersHouse_Sink_On_Left, FALSE
	setmetatile 5, 1, METATILE_PlayersHouse_Sink_On_Right, FALSE
	special DrawWholeMapView
	releaseall
	end

PlayersHouseBathroom_EventScript_Toilet::
	lock
	msgbox PlayersHouseBathroom_Text_Toilet, MSGBOX_DEFAULT
	release
	end

PlayersHouseBathroom_Text_Toilet:
	.string "It's a toilet.\p"
	.string "You don't have to go right now.$"


	