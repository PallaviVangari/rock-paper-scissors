#include "RandomGenerator.hpp"
#include <cstdlib>

char RandomGenerator::GenerateComputerResponse(char input)
{
    int random = rand() % 3;
    switch(random)
    {
        case 0 : return 'R';
            break;
        case 1 : return 'P';
            break;
        case 2 : return 'S';
            break;
        default: return '0';
    }
}
