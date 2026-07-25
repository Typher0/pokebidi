OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Most Pokémon can't drink coffee\n"
	.string "because caffeine is toxic to them.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Prof. Unicorn is really smart, but\n"
	.string "the way he acts means it's not always\l"
	.string "obvious how brilliant he is.$"

