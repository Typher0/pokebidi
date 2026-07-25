OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x1DF, OldaleTown_House1_EventScript_Woman2
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNUSED_0x1DF
	giveitem ITEM_HONEY
	release
	end

OldaleTown_House1_Text_LeftPokemonGoesOutFirst:
	.string "Have you noticed the golden tree\n"
	.string "on Route 631?\p"
	.string "If you slather some honey on it,\n"
	.string "wild Pokémon will be drawn to it!\p"
	.string "There are many Pokémon you'll only\n"
	.string "find by using this method.\p"
	.string "I know, take some honey to try\n"
	.string "for yourself!$"

OldaleTown_House1_EventScript_Woman2::
	msgbox OldaleTown_House1_Text_UseThatHoney, MSGBOX_NPC
	end

OldaleTown_House1_Text_UseThatHoney:
	.string "Some Pokémon are easier to find than\n"
	.string "others, so keep trying if you're\l"
	.string "looking for one Pokémon in particular!\p"
	.string "I personally love Munchlax!$"

OldaleTown_House1_EventScript_Munchlax::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
	msgbox OldaleTown_House1_Text_Munchlax, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OldaleTown_House1_Text_Munchlax:
	.string "Munch! Munchlax!$"

