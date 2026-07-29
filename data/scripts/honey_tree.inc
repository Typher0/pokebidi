@ Interact with honey tree
EventScript_Honey::
    lockall
    checkitem ITEM_HONEY
    goto_if_eq VAR_RESULT, FALSE, EventScript_CantHoneyTree
    setfieldeffectargument 0, VAR_RESULT
    msgbox Text_WantToHoney, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CancelHoney
    removeitem ITEM_HONEY
    playse SE_M_SWEET_SCENT
    delay 180
    special HoneyWildEncounter
    goto EventScript_EndHoney
    waitstate
    releaseall
    end

EventScript_CantHoneyTree::
    msgbox Text_CantHoneyTree, MSGBOX_DEFAULT
    releaseall
    end
    
EventScript_EndHoney::
    releaseall
    end

EventScript_CancelHoney::
    closemessage
    releaseall
    end
    
Text_WantToHoney:
    .string "There's a sweet scent in the air.\n"
    .string "Slather the bark with honey?$"

Text_CantHoneyTree:
    .string "There's a sweet scent in the air.$"
