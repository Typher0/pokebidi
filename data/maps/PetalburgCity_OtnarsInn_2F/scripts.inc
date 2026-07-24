PetalburgCity_OtnarsInn_2F_MapScripts::
	.byte 0

PetalburgCity_OtnarsInn_2F_EventScript_Boy::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Boy, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Boy:
	.string "My dad told me I can't run in\n"
	.string "the halls of the hotel.\p"
	.string "But there's nothing he can do to\n"
	.string "stop me!$"

PetalburgCity_OtnarsInn_2F_EventScript_Lass::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Lass, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Lass:
	.string "My sister is really sick.\p"
	.string "I'm making dinner so that my grandma\n"
	.string "can focus on taking care of her.$"

PetalburgCity_OtnarsInn_2F_EventScript_Twin::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Twin, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Twin::
	.string "I'm trying to watch my favorite show.\p"
	.string "It's not as fun to watch without\n"
	.string "my sister, though.\p"
	.string "I hope she wakes up soon…$"

PetalburgCity_OtnarsInn_2F_EventScript_Sick::
	lockall
	goto_if_set FLAG_UNUSED_0x1DE, PetalburgCity_OtnarsInn_2F_EventScript_NotSickAnymore
	msgbox PetalburgCity_OtnarsInn_2F_Text_Sick, MSGBOX_DEFAULT
	checkfieldmove FIELD_MOVE_SWEET_SCENT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, PetalburgCity_OtnarsInn_2F_EventScript_NoDreamEater
	setfieldeffectargument 0, VAR_RESULT
	msgbox PetalburgCity_OtnarsInn_2F_Text_WantToDreamEater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_OtnarsInn_2F_EventScript_NoDreamEater
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	msgbox Text_MonUsedSweetScent, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x1DE
	releaseall
	end

PetalburgCity_OtnarsInn_2F_EventScript_NoDreamEater::
	releaseall
	end

PetalburgCity_OtnarsInn_2F_EventScript_NotSickAnymore::
	msgbox PetalburgCity_OtnarsInn_2F_Text_NotSick, MSGBOX_NPC
	releaseall
	end

PetalburgCity_OtnarsInn_2F_Text_Sick:
	.string "…$"

PetalburgCity_OtnarsInn_2F_Text_NotSick:
	.string "Thanks for healing me, kind trainer!$"

PetalburgCity_OtnarsInn_2F_Text_WantToDreamEater:
	.string "She seems to be tormented by a disease…\n"
	.string "Would you like to use Sweet Scent?$"

PetalburgCity_OtnarsInn_2F_EventScript_Grandma::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Grandma, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Grandma:
	.string "My poor granddaughter is deathly sick.\n"
	.string "I believe a sweet scent would help…$"

Text_MonUsedSweetScent:
	.string "Your Pokémon used Sweet Scent!"

PetalburgCity_OtnarsInn_2F_EventScript_Dad::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Dad, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Dad:
	.string "That son of mine just won't sit still!$"

PetalburgCity_OtnarsInn_2F_EventScript_Mom::
	msgbox PetalburgCity_OtnarsInn_2F_Text_Mom, MSGBOX_NPC
	end

PetalburgCity_OtnarsInn_2F_Text_Mom:
	.string "There's a lot of people out there\n"
	.string "who get really upset hearing about kids\l"
	.string "who aren't familiar with old technology.\p"
	.string "Me?\n"
	.string "I think it's fun.\p"
	.string "I can talk about a VHS, and they've never\n"
	.string "heard of it.\p"
	.string "How would they know whether or not I'm\n"
	.string "telling the truth when I say that it\l"
	.string "stands for Vehicle Homing System?\p"
	.string "It was what we had before GPS, I say.\p"
	.string "It couldn't take you anywhere you want,\n"
	.string "but you had one receiver in your home,\l"
	.string "and one in your car.\p"
	.string "It was used to get you home!\p"
	.string "It's a harmless little thing that\n"
	.string "gives me some amusement.$"

