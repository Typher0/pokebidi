PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Traveling is wonderful!\p"
	.string "When I was young, I roamed the seas\n"
	.string "and the mountains!$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some Pokémon…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "It must be fabulous to travel!$"

@ Burgh: Winston 5

PetalburgCity_House1_EventScript_Burgh::
	lock
	faceplayer
	playbgm MUS_GYM, FALSE
	trainerbattle_single TRAINER_WINSTON_5, PetalburgCity_House1_Text_BurghIntro, PetalburgCity_House1_Text_BurghDefeat, PetalburgCity_House1_EventScript_BurghDefeated, NO_MUSIC
	goto_if_unset FLAG_UNUSED_0x2BB, PetalburgCity_House1_EventScript_GiveStruggleBug
	msgbox PetalburgCity_House1_Text_BurghPostBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

PetalburgCity_House1_EventScript_BurghDefeated::
	playbgm MUS_GYM, FALSE
	setobjectxyperm LOCALID_PETALBURG_ANTON, 4, 8
	msgbox PetalburgCity_House1_Text_GiveYouThis, MSGBOX_DEFAULT
	closemessage
	goto PetalburgCity_House1_EventScript_GiveStruggleBug
	end

PetalburgCity_House1_EventScript_GiveStruggleBug::
	giveitem ITEM_TM_INFESTATION
	setflag FLAG_UNUSED_0x2BB
	msgbox PetalburgCity_House1_Text_ExplainTM, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	playse SE_EXIT
	clearflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_PETALBURG_CITY_SCOTT
	addobject LOCALID_PETALBURG_ANTON
	delay 10
	delay 10
	msgbox PetalburgCity_House1_Text_AntonEnters, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_ANTON, PetalburgCity_House1_Movement_GoToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PetalburgCity_House1_EventScript_AntonGiveTicket
	end

PetalburgCity_House1_EventScript_AntonGiveTicket::
	msgbox PetalburgCity_House1_Text_AntonThanks, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SS_TICKET
	release
	end

PetalburgCity_House1_Movement_GoToPlayer:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end
	

PetalburgCity_House1_Text_BurghIntro:
	.string "Hello there.\p"
	.string "Are you the one who delivered the\n"
	.string "letter to Madame De Roux?\p"
	.string "Thank you for that.\p"
	.string "I would have liked to help them\n"
	.string "myself, but I only just arrived\l"
	.string "in town, you see.\p"
	.string "The De Rouxs are good friends of\n"
	.string "mine, so I will not soon forget\l"
	.string "your kindness!\p"
	.string "Who am I?\p"
	.string "Oh, pardon me, I forgot to\n"
	.string "introduce myself.\p"
	.string "My name is Burgh.\p"
	.string "I am the Gym Leader of Castelia\n"
	.string "City, Unova.\p"
	.string "I see you've defeated Otnar.\p"
	.string "Then why don't you test yourself\n"
	.string "against a guy like me?$"

PetalburgCity_House1_Text_BurghDefeat:
	.string "Bravo!\p"
	.string "I see you are quite the trainer!\p"
	.string "While you lack the badge case for\n"
	.string "a Unovan Gym Badge, I commend you\l"
	.string "nonetheless!$"

PetalburgCity_House1_Text_GiveYouThis:
	.string "As a token of my acknowledgment\n"
	.string "of your victory, please take this.$"

PetalburgCity_House1_Text_ExplainTM:
	.string "This TM contains the move\n"
	.string "Infestation.\p"
	.string "It is a Bug-type move that does\n"
	.string "damage and traps the opponent,\l"
	.string "doing damage to them every turn!$"

PetalburgCity_House1_Text_BurghPostBattle:
	.string "Anton De Roux was my hero growing up.\p"
	.string "Incredibly, he was also the first\n"
	.string "artist to support me.\p"
	.string "Truly, few artists have been as\n"
	.string "fortunate as I!$"

PetalburgCity_House1_Text_AntonEnters:
	.string "Anton: Ah, I see we have guests!\p"
	.string "Burgh, {PLAYER}!\n"
	.string "Good to see you both.$"

PetalburgCity_House1_Text_AntonThanks:
	.string "Thank you for delivering my letter,\n"
	.string "my dear {PLAYER}.\p"
	.string "That's right, I am Anton De Roux,\n"
	.string "world-famous artist.\p"
	.string "I simply must repay you for your\n"
	.string "kindness.\p"
	.string "Ah, how about this?\n"
	.string "Why don't you take my train pass?\p"
	.string "It's probably best I avoid using it\n"
	.string "again, lest my wife really get angry.\p"
	.string "Oh, but don't worry.\n"
	.string "The trains are operational again.\p"
	.string "It will help you get home, and can\n"
	.string "get you to Joridan City, where you\l"
	.string "can face the next Gym.$"

