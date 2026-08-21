#ifndef GUARD_PASSIVES_INFO_H
#define GUARD_PASSIVES_INFO_H

#include "constants/passive.h"

struct PassiveInfo
{
    u8 name[ABILITY_NAME_LENGTH + 1];
};

extern const struct PassiveInfo gPassivesInfo[PASSIVES_COUNT];

#endif // GUARD_PASSIVES_INFO_H
