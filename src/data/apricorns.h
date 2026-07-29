struct ApricornTree
{
    u8 minimum;
    u8 maximum;
    enum ApricornType apricornType;
};

const struct ApricornTree gApricornTrees[APRICORN_TREE_COUNT] =
{
    #if APRICORN_TREE_COUNT > 0
    [APRICORN_TREE_NONE] =
    {
        .minimum = 1,
        .maximum = 1,
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_ROUTE102_GREEN_TREE] =
    {
        .minimum = 1,
        .maximum = 1,
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_ROUTE103_YELLOW_TREE] =
    {
        .minimum = 1,
        .maximum = 1,
        .apricornType = APRICORN_YELLOW,
    },
    #endif
};
