#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include "IStrategy.hpp"

class RandomGenerator : public IStrategy
{
public:
    char GenerateComputerResponse(char input) override;
};

#endif // RANDOMGENERATOR_H
