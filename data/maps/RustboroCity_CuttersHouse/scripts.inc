RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Hm…?\n"
	.string "Yes…that's right…\l"
	.string "I am Zinzolin, one of the Seven Sages…\p"
	.string "Fear not!\n"
	.string "I am a changed man!\p"
	.string "I no longer wish to fight for my\n"
	.string "beliefs, I see the harm\l"
	.string "Team Plasma has done to Unova.\p"
	.string "As proof that I have turned over\n"
	.string "a new leaf, I will give you this HM\p"
	.string "Here, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That Hidden Machine, or HM for\n"
	.string "short, is Cut.\p"
	.string "An HM move is one that can be used\n"
	.string "by Pokémon outside of battle.\p"
	.string "Any Pokémon that's learned Cut can\n"
	.string "chop down thin trees if the Trainer\l"
	.string "has earned the Snowflake Badge.\p"
	.string "Although, I'm not sure how any trees\n"
	.string "manage to grow in this frozen hell.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When we were in Team Plasma, we were\n"
	.string "forced into this place called the\l"
	.string "Cold Storage.\p"
	.string "I don't think I've ever been\n"
	.string "somewhere more aptly named than that.$"

