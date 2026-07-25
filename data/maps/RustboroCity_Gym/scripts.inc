RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_HAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	goto_if_set FLAG_TEMP_1, RustboroCity_Gym_EventScript_GymGuideGotWater
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER
	setflag FLAG_TEMP_1
	release
	end

RustboroCity_Gym_EventScript_GymGuideGotWater::
	msgbox RustboroCity_Gym_Text_GymGuideAdviceNoWater, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the Champion?\p"
	.string "I'm no Trainer, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "Pokémon Championship together!\p"
	.string "It's your job as a Trainer to collect\n"
	.string "Gym Badges, am I right?\p"
	.string "But Gym Leaders aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "Otnar, the Gym Leader, is a user\n"
	.string "of Ice-type Pokémon.\p"
	.string "The Ice type is very powerful, but\n"
	.string "it can't stand Fire-type and\l"
	.string "Rock-type moves.\p"
	.string "Also, I'd like to give you this\n"
	.string "Fresh Water to keep you and your\l"
	.string "Pokémon hydrated!$"

RustboroCity_Gym_Text_GymGuideAdviceNoWater:
	.string "I'm here to provide expert advice!\p"
	.string "Otnar, the Gym Leader, is a user\n"
	.string "of Ice-type Pokémon.\p"
	.string "The Ice type is very powerful, but\n"
	.string "it can't stand Fire-type and\l"
	.string "Rock-type moves.$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your Trainer Card.\p"
	.string "The Snowflake Badge you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Chamionship!\p"
	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Don't take us Gym Trainers lightly!\n"
	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "You haven't seen anything of the Ice\n"
	.string "type's terrifying power!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Otnar!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Otnar is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Otnar always says I need to\n"
	.string "keep my head cool, but so what?\p"
	.string "My Ice Pokémon need room to\n"
	.string "rampage!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "I have to hand it to our Leader.\p"
	.string "He is an absolute master of the\n"
	.string "Ice type, even at his old age.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Wo-hohohohoho!\p"
	.string "Hello! I am Otnar, the Papilys City\n"
	.string "Pokémon Gym Leader.\p"
	.string "After decades of exploration of\n"
	.string "Banjime's frigid landscape, I have\l"
	.string "mastered the Ice-type.\p"
	.string "Now, as a Gym Leader, I test\n"
	.string "trainers to see if they are up\l"
	.string "to the challenges that await them.\p"
	.string "Now, show me what you've got!$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Wo-hohohohoho!\n"
	.string "I have lost!\p"
	.string "It seems that you indeed have\n"
	.string "what it takes to travel Banjime!\p"
	.string "Well then,\p"
	.string "By the power vested in me by the\n"
	.string "State of Banjime and it's Pokémon\l"
	.string "Leage, I pronounce you a Trainer.\p"
	.string "Now, accept the official Pokémon\n"
	.string "League Snowflake Badge!$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} received the Snowflake\n"
	.string "Badge from Otnar.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "The Snowflake Badge enables your\n"
	.string "Pokémon to use the HM move Cut\l"
 	.string "outside of battle.\p"
	.string "You can have this as well.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "That Technical Machine, TM07,\n"
	.string "contains Hail.\p"
	.string "It not only inflicts damage every turn\n"
	.string "on non-Ice types, but gives Ice types\l"
	.string "a Defense boost as well!\p"
	.string "It makes the frail guys into much\n"
	.string "tougher opponents, so I recommend it!\p"
	.string "Just use it on one of your Pokémon,\n"
	.string "and they'll learn the move instantly!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Now that you have defeated me, you\n"
	.string "ought to challenge other Gym Leaders.\p"
	.string "The next Gym I recommend is in Joridan\n"
	.string "City, to the West of Zephyr Town.$"

RustboroCity_Gym_Text_GymStatue:
	.string "Papilys City Pokémon Gym\p"
	.string "Certified Trainers in order of completion:\n"
	.string "Peter, Ahab, Jelissa, Toxiana, Tinker\p"
	.string "Moose, Gwen, Tobias, Ishmael, Josh, Adhira\n"
	.string "Amanda, Sean$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Papilys City Pokémon Gym\p"
	.string "Certified Trainers in order of completion:\n"
	.string "Peter, Ahab, Jelissa, Toxiana, Tinker\p"
	.string "Moose, Gwen, Tobias, Ishmael, Josh, Adhira\n"
	.string "Amanda, Sean, {PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registered Gym Leader Otnar\n"
	.string "in the Pokénav.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
