GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_CLIMB, GraniteCave_1F_EventScript_ReceivedRockClimb
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_CLIMB
	setflag FLAG_RECEIVED_HM_ROCK_CLIMB
	msgbox GraniteCave_1F_Text_ExplainRockClimb, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedRockClimb::
	msgbox GraniteCave_1F_Text_ExplainRockClimb, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainRockClimb:
	.string "Teach that hidden move ROCK CLIMB\n"
	.string "to a POKéMON and use it.\p"
	.string "It will allow you to climb up\n"
	.string "the steepest of slopes.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

