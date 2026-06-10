PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PetalburgCity_PokemonCenter_1F_StatMart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_PokemonCenter_1F_StatMart:
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	pokemartlistend

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Man, do I love Old Gateaus…\n"
	.string "They taste so good…\p"
	.string "If you put a Castelia Cone on them…\n"
	.string "It doesn't get better than that!!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Hey there!\n"
	.string "You don't look like a normal person.\p"
	.string "You look like the kinda person to\n"
	.string "eat Old Gateaus covered in Castelia\l"
	.string "Cones.\p"
	.string "You also look like the kind of person\n"
	.string "who doesn't know that in this region,\l"
	.string "the Ice-type resists Water and Flying.$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "There are many types of Pokémon.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of Pokémon,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "For example, your Starter\n"
	.string "is a Grass type.\p"
	.string "It's strong against the Sound-\n"
	.string "type Pokémon in this region.\p"
	.string "But, it's weak against Ice-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "For example, your Starter\n"
	.string "is a Fire type.\p"
	.string "It's strong against the Grass and\n"
	.string "Ice types.\p"
	.string "But, it's weak against Water and\n"
	.string "Rock type Pokémon.\p"
	.string "Incidentally, the Sound-type is a\n"
	.string "good pairing with your starter.\p"
	.string "It is weak against Grass-types,\n"
	.string "and strong against Water-types.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "For example, your Starter\n"
	.string "is a Water type.\p"
	.string "It's strong against the Sound type.\p"
	.string "But, it's weak against Grass-type\n"
	.string "and Sound-type Pokémon.$"

