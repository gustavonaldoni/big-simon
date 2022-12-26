#include <stdlib.h>
#include "random.h"

int GenerateRandomInt(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
