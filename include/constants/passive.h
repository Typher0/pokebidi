#ifndef GUARD_CONSTANTS_PASSIVE_H
#define GUARD_CONSTANTS_PASSIVE_H

enum Passive
{
    PASSIVE_NONE,

    // 5 typed archetypes x 19 types = 95 values, generate with a macro so you don't hand-write 95 names
    #define PASSIVE_TYPED(archetype) \
        PASSIVE_##archetype##_NORMAL, PASSIVE_##archetype##_FIGHTING, PASSIVE_##archetype##_FLYING, \
        PASSIVE_##archetype##_POISON, PASSIVE_##archetype##_GROUND, PASSIVE_##archetype##_ROCK, \
        PASSIVE_##archetype##_BUG, PASSIVE_##archetype##_GHOST, PASSIVE_##archetype##_STEEL, \
        PASSIVE_##archetype##_FIRE, PASSIVE_##archetype##_WATER, PASSIVE_##archetype##_GRASS, \
        PASSIVE_##archetype##_ELECTRIC, PASSIVE_##archetype##_PSYCHIC, PASSIVE_##archetype##_ICE, \
        PASSIVE_##archetype##_DRAGON, PASSIVE_##archetype##_DARK, PASSIVE_##archetype##_FAIRY, \
        PASSIVE_##archetype##_SOUND,

    PASSIVE_TYPED(BOOST)
    PASSIVE_TYPED(RESIST)
    PASSIVE_TYPED(NULL)
    PASSIVE_TYPED(DRAIN)
    PASSIVE_TYPED(REPEL)
    #undef PASSIVE_TYPED

    PASSIVE_BOOST_CRIT,
    PASSIVE_BOOST_HEAL,
    PASSIVE_BOOST_SPEED,
    PASSIVE_BOOST_PHYS,
    PASSIVE_BOOST_SPEC,
    PASSIVE_RESIST_PHYS,
    PASSIVE_RESIST_SPEC,
    PASSIVE_PHYS_MASTERY,
    PASSIVE_SPEC_MASTERY,
    PASSIVE_ATK_MASTERY,
    PASSIVE_DEF_MASTERY,
    PASSIVE_COPY,
    PASSIVE_STEADY_HEAL,
    PASSIVE_PIERCE,
    PASSIVE_CHANGE_CLEAR,
    PASSIVE_STATUS_CLEAR,
    PASSIVE_NULL_SE,
    PASSIVE_NULL_AE,
    PASSIVE_NULL_NVE,
    PASSIVE_NULL_PD,

    PASSIVES_COUNT,
};

#endif // GUARD_CONSTANTS_PASSIVE_H
