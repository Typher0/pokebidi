PlayersHouseParentsRoom_MapScripts::
	.byte 0

PlayersHouseParentsRoom_EventScript_Sink::
	lockall
	switch VAR_TEMP_4
	case 0, PlayersHouseParentsRoom_EventScript_Sink_Off
	case 1, PlayersHouseParentsRoom_EventScript_Sink_On
	end

PlayersHouseParentsRoom_EventScript_Sink_Off::
	setmetatile 11, 1, METATILE_PlayersHouse_Sink_Off_Left, TRUE
	setmetatile 12, 1, METATILE_PlayersHouse_Sink_Off_Right, TRUE
	releaseall
	end

PlayersHouseParentsRoom_EventScript_Sink_On::
	setmetatile 11, 1, METATILE_PlayersHouse_Sink_On_Left, TRUE
	setmetatile 12, 1, METATILE_PlayersHouse_Sink_On_Right, TRUE
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

