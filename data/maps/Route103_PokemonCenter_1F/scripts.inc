Route103_PokemonCenter_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route103_PokemonCenter_1F_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
    .byte 0

Route103_PokemonCenter_1F_OnTransition:
    setrespawn HEAL_LOCATION_ROUTE103
    end

Route103_PokemonCenter_1F_EventScript_Nurse::
    setvar VAR_0x800B, LOCALID_ROUTE103_NURSE
    call Common_EventScript_PkmnCenterNurse
    waitmessage
    waitbuttonpress
    release
    end
