#ifndef GUARD_CONSTANTS_CONTEST_H
#define GUARD_CONSTANTS_CONTEST_H

#define APPLAUSE_METER_SIZE 5
#define CONTEST_NUM_APPEALS 5
#define CONTEST_LAST_APPEAL (CONTEST_NUM_APPEALS - 1)
#define MAX_CONTEST_MOVE_HEARTS 8

#define CONTESTANT_NONE 0xFF

#define LINK_CONTEST_FLAG_IS_LINK       (1 << 0)
#define LINK_CONTEST_FLAG_IS_WIRELESS   (1 << 1)
#define LINK_CONTEST_FLAG_HAS_RS_PLAYER (1 << 2)

#define CONTEST_RANK_NORMAL  0
#define CONTEST_RANK_SUPER   1
#define CONTEST_RANK_HYPER   2
#define CONTEST_RANK_MASTER  3
#define CONTEST_RANK_LINK    4

// States for VAR_CONTEST_TYPE
#define CONTEST_TYPE_NPC_NORMAL  (CONTEST_RANK_NORMAL + 1)
#define CONTEST_TYPE_NPC_SUPER   (CONTEST_RANK_SUPER + 1)
#define CONTEST_TYPE_NPC_HYPER   (CONTEST_RANK_HYPER + 1)
#define CONTEST_TYPE_NPC_MASTER  (CONTEST_RANK_MASTER + 1)
#define CONTEST_TYPE_LINK        (CONTEST_RANK_LINK + 1)

// IDs below - 1 are indexes into gSaveBlock1Ptr->contestWinners[]
// CONTEST_WINNER_ARTIST is for the winner of the most recent contest, and is not saved.
#define CONTEST_WINNER_ARTIST 0
#define CONTEST_WINNER_HALL_1 1
#define CONTEST_WINNER_HALL_2 2
#define CONTEST_WINNER_HALL_3 3
#define CONTEST_WINNER_HALL_4 4
#define CONTEST_WINNER_HALL_5 5
#define CONTEST_WINNER_HALL_6 6
#define NUM_CONTEST_HALL_WINNERS 6
#define CONTEST_WINNER_HALL_UNUSED_1 7 // These two have data for gDefaultContestWinners
#define CONTEST_WINNER_HALL_UNUSED_2 8 // but there are only 6 paintings in the Contest Hall
#define CONTEST_WINNER_MUSEUM_COOL   9
#define CONTEST_WINNER_MUSEUM_BEAUTY 10
#define CONTEST_WINNER_MUSEUM_CUTE   11
#define CONTEST_WINNER_MUSEUM_SMART  12
#define CONTEST_WINNER_MUSEUM_TOUGH  13
// NUM_CONTEST_WINNERS in constants/global.h

#define MUSEUM_CONTEST_WINNERS_START (CONTEST_WINNER_MUSEUM_COOL - 1)

#define CONTEST_SAVE_FOR_MUSEUM ((u8)-1)
#define CONTEST_SAVE_FOR_ARTIST ((u8)-2)

// The number of possible captions for a Contest painting, per category
#define NUM_PAINTING_CAPTIONS 3

#define CANT_ENTER_CONTEST             0
#define CAN_ENTER_CONTEST_EQUAL_RANK   1
#define CAN_ENTER_CONTEST_HIGH_RANK    2
#define CANT_ENTER_CONTEST_EGG         3
#define CANT_ENTER_CONTEST_FAINTED     4

#define CONTEST_AI_CHECK_BAD_MOVE   (1 << 0)
#define CONTEST_AI_CHECK_COMBO      (1 << 1)
#define CONTEST_AI_CHECK_BORING     (1 << 2)
#define CONTEST_AI_CHECK_EXCITEMENT (1 << 3)
#define CONTEST_AI_CHECK_ORDER      (1 << 4)
#define CONTEST_AI_CHECK_GOOD_MOVE  (1 << 5)
#define CONTEST_AI_ERRATIC          (1 << 6)
#define CONTEST_AI_DUMMY_1          (1 << 7)
#define CONTEST_AI_DUMMY_2          (1 << 8)
#define CONTEST_AI_DUMMY_3          (1 << 9)
#define CONTEST_AI_DUMMY_4          (1 << 10)
#define CONTEST_AI_DUMMY_5          (1 << 11)
#define CONTEST_AI_DUMMY_6          (1 << 12)
#define CONTEST_AI_DUMMY_7          (1 << 13)
#define CONTEST_AI_DUMMY_8          (1 << 14)
#define CONTEST_AI_DUMMY_9          (1 << 15)
#define CONTEST_AI_DUMMY_10         (1 << 16)
#define CONTEST_AI_DUMMY_11         (1 << 17)
#define CONTEST_AI_DUMMY_12         (1 << 18)
#define CONTEST_AI_DUMMY_13         (1 << 19)
#define CONTEST_AI_DUMMY_14         (1 << 20)
#define CONTEST_AI_DUMMY_15         (1 << 21)
#define CONTEST_AI_DUMMY_16         (1 << 22)
#define CONTEST_AI_DUMMY_17         (1 << 23)
#define CONTEST_AI_DUMMY_18         (1 << 24)
#define CONTEST_AI_DUMMY_19         (1 << 25)
#define CONTEST_AI_DUMMY_20         (1 << 26)
#define CONTEST_AI_DUMMY_21         (1 << 27)
#define CONTEST_AI_DUMMY_22         (1 << 28)
#define CONTEST_AI_DUMMY_23         (1 << 29)
#define CONTEST_AI_DUMMY_24         (1 << 30)
#define CONTEST_AI_DUMMY_25         (1 << 31)

// The below scripts are used by every AI contest opponent
// It includes every non-dummy script
#define CONTEST_AI_COMMON   (CONTEST_AI_CHECK_BAD_MOVE | CONTEST_AI_CHECK_COMBO | CONTEST_AI_CHECK_BORING | \
                             CONTEST_AI_CHECK_EXCITEMENT | CONTEST_AI_CHECK_ORDER | CONTEST_AI_CHECK_GOOD_MOVE | CONTEST_AI_ERRATIC | \
                             CONTEST_AI_DUMMY_1 | CONTEST_AI_DUMMY_2 | CONTEST_AI_DUMMY_3 | CONTEST_AI_DUMMY_4 | CONTEST_AI_DUMMY_5)

#define CONTEST_EFFECT_HIGHLY_APPEALING                         0
#define CONTEST_EFFECT_USER_MORE_EASILY_STARTLED                1
#define CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES           2
#define CONTEST_EFFECT_REPETITION_NOT_BORING                    3
#define CONTEST_EFFECT_AVOID_STARTLE_ONCE                       4
#define CONTEST_EFFECT_AVOID_STARTLE                            5
#define CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY                   6
#define CONTEST_EFFECT_USER_LESS_EASILY_STARTLED                7
#define CONTEST_EFFECT_STARTLE_FRONT_MON                        8
#define CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS               9
#define CONTEST_EFFECT_STARTLE_PREV_MON                         10
#define CONTEST_EFFECT_STARTLE_PREV_MONS                        11
#define CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON                  12
#define CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS                  13
#define CONTEST_EFFECT_STARTLE_PREV_MON_2                       14
#define CONTEST_EFFECT_STARTLE_PREV_MONS_2                      15
#define CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION                    16
#define CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION        17
#define CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN            18
#define CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL            19
#define CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL                 20
#define CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL               21
#define CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL                 22
#define CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL                23
#define CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL                24
#define CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS               25
#define CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS              26
#define CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS            27
#define CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION    28
#define CONTEST_EFFECT_BETTER_IF_FIRST                          29
#define CONTEST_EFFECT_BETTER_IF_LAST                           30
#define CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES              31
#define CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE               32
#define CONTEST_EFFECT_BETTER_WHEN_LATER                        33
#define CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING                34
#define CONTEST_EFFECT_BETTER_IF_SAME_TYPE                      35
#define CONTEST_EFFECT_BETTER_IF_DIFF_TYPE                      36
#define CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL                  37
#define CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS    38
#define CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION               39
#define CONTEST_EFFECT_NEXT_APPEAL_EARLIER                      40
#define CONTEST_EFFECT_NEXT_APPEAL_LATER                        41
#define CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER        42
#define CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER                 43
#define CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST           44
#define CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS     45
#define CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED             46
#define CONTEST_EFFECT_DONT_EXCITE_AUDIENCE                     47

// Each of the above effects is grouped into one of these effect type categories
// Only a few of these get checked by the AI, the rest go unused
#define CONTEST_EFFECT_TYPE_APPEAL         0
#define CONTEST_EFFECT_TYPE_AVOID_STARTLE  1
#define CONTEST_EFFECT_TYPE_STARTLE_MON    2
#define CONTEST_EFFECT_TYPE_STARTLE_MONS   3
#define CONTEST_EFFECT_TYPE_WORSEN         4
#define CONTEST_EFFECT_TYPE_SPECIAL_APPEAL 5
#define CONTEST_EFFECT_TYPE_TURN_ORDER     6
#define CONTEST_EFFECT_TYPE_UNKNOWN        8

#define COMBO_STARTER_POUND 1
#define COMBO_STARTER_FIRE_PUNCH 2
#define COMBO_STARTER_ICE_PUNCH 3
#define COMBO_STARTER_THUNDER_PUNCH 4
#define COMBO_STARTER_SCRATCH 5
#define COMBO_STARTER_VICE_GRIP 6
#define COMBO_STARTER_SWORDS_DANCE 7
#define COMBO_STARTER_SAND_ATTACK 8
#define COMBO_STARTER_HORN_ATTACK 9
#define COMBO_STARTER_LEER 10
#define COMBO_STARTER_SING 11
#define COMBO_STARTER_SURF 12
#define COMBO_STARTER_PECK 13
#define COMBO_STARTER_LEECH_SEED 14
#define COMBO_STARTER_GROWTH 15
#define COMBO_STARTER_STRING_SHOT 16
#define COMBO_STARTER_DRAGON_RAGE 17
#define COMBO_STARTER_ROCK_THROW 18
#define COMBO_STARTER_EARTHQUAKE 19
#define COMBO_STARTER_TOXIC 20
#define COMBO_STARTER_CONFUSION 21
#define COMBO_STARTER_PSYCHIC 22
#define COMBO_STARTER_HYPNOSIS 23
#define COMBO_STARTER_RAGE 24
#define COMBO_STARTER_DOUBLE_TEAM 25
#define COMBO_STARTER_HARDEN 26
#define COMBO_STARTER_DEFENSE_CURL 27
#define COMBO_STARTER_FOCUS_ENERGY 28
#define COMBO_STARTER_SMOG 29
#define COMBO_STARTER_SLUDGE 30
#define COMBO_STARTER_BONE_CLUB 31
#define COMBO_STARTER_KINESIS 32
#define COMBO_STARTER_SOFT_BOILED 33
#define COMBO_STARTER_BONEMERANG 34
#define COMBO_STARTER_REST 35
#define COMBO_STARTER_MIND_READER 36
#define COMBO_STARTER_CURSE 37
#define COMBO_STARTER_POWDER_SNOW 38
#define COMBO_STARTER_SCARY_FACE 39
#define COMBO_STARTER_BELLY_DRUM 40
#define COMBO_STARTER_SLUDGE_BOMB 41
#define COMBO_STARTER_MUD_SLAP 42
#define COMBO_STARTER_BONE_RUSH 43
#define COMBO_STARTER_LOCK_ON 44
#define COMBO_STARTER_SANDSTORM 45
#define COMBO_STARTER_ENDURE 46
#define COMBO_STARTER_CHARM 47
#define COMBO_STARTER_MEAN_LOOK 48
#define COMBO_STARTER_HEAL_BELL 49
#define COMBO_STARTER_DRAGON_BREATH 50
#define COMBO_STARTER_SWEET_SCENT 51
#define COMBO_STARTER_RAIN_DANCE 52
#define COMBO_STARTER_SUNNY_DAY 53
#define COMBO_STARTER_FAKE_OUT 54
#define COMBO_STARTER_STOCKPILE 55
#define COMBO_STARTER_HAIL 56
#define COMBO_STARTER_CHARGE 57
#define COMBO_STARTER_TAUNT 58
#define COMBO_STARTER_REVENGE 59
#define COMBO_STARTER_YAWN 60
#define COMBO_STARTER_DIVE 61
#define COMBO_STARTER_MUD_SPORT 62
#define COMBO_STARTER_METAL_SOUND 63
#define COMBO_STARTER_WATER_SPORT 64
#define COMBO_STARTER_CALM_MIND 65
#define COMBO_STARTER_DRAGON_DANCE 66
#define COMBO_STARTER_PAYBACK 67
#define COMBO_STARTER_LUCKY_CHANT 68
#define COMBO_STARTER_WORRY_SEED 69
#define COMBO_STARTER_DRAGON_RUSH 70
#define COMBO_STARTER_BRAVE_BIRD 71
#define COMBO_STARTER_THUNDER_FANG 72
#define COMBO_STARTER_ICE_FANG 73
#define COMBO_STARTER_FIRE_FANG 74
#define COMBO_STARTER_ATTACK_ORDER 75
#define COMBO_STARTER_DEFEND_ORDER 76
#define COMBO_STARTER_HEAL_ORDER 77
#define COMBO_STARTER_SCALD 78
#define COMBO_STARTER_DRAGON_TAIL 79
#define COMBO_STARTER_HYPERSPACE_HOLE 80
#define COMBO_STARTER_THOUSAND_ARROWS 81
#define COMBO_STARTER_THOUSAND_WAVES 82
#define COMBO_STARTER_HYPERSPACE_FURY 83
#define COMBO_STARTER_SHADOW_BONE 84
#define COMBO_STARTER_ELECTRIC_TERRAIN 85
#define COMBO_STARTER_MISTY_TERRAIN 86
#define COMBO_STARTER_GRASSY_TERRAIN 87
#define COMBO_STARTER_PSYCHIC_TERRAIN 88
#define COMBO_STARTER_EN_GARDE 89

#endif  // GUARD_CONSTANTS_CONTEST_H
