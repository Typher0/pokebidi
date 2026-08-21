#ifndef GUARD_PASSIVE_POOLS_H
#define GUARD_PASSIVE_POOLS_H
 
#include "constants/passive.h"
 
enum PassivePoolEntryKind
{
    POOL_ENTRY_LITERAL, // .passive is used as-is (the ~20 general Passives)
    POOL_ENTRY_TYPE1,   // resolves to .archetypeBase + the species' own Type 1
    POOL_ENTRY_TYPE2,   // resolves to .archetypeBase + the species' own Type 2
    POOL_ENTRY_END,     // terminator - TYPE1/TYPE2 rows leave .passive unset (0/PASSIVE_NONE),
                         // so PASSIVE_NONE can't double as the end-of-array sentinel anymore
};
 
struct PassivePoolEntry
{
    enum PassivePoolEntryKind kind;
    enum Passive passive;       // valid when kind == POOL_ENTRY_LITERAL
    enum Passive archetypeBase; // valid when kind == POOL_ENTRY_TYPE1/TYPE2, e.g. PASSIVE_BOOST_NORMAL
    u32 weight;
};
 
// Declarations for every cross-file Passive-roll function - all of these
// need to be non-static and declared here, since a function only defined in
// one .c file with no declaration in a shared header can't be called from a
// different .c file.
enum Passive RollPassiveForMon(enum Species species, u32 obtainMethod);
bool32 IsPassiveBannedForSpecies(enum Species species, enum Passive passive);
bool32 CanSpeciesHavePassive(enum Species species, enum Passive passive);
enum Passive RerollPassiveForEvolution(struct Pokemon *mon, enum Species oldSpecies, enum Species newSpecies);
 
#endif // GUARD_PASSIVE_POOLS_H
