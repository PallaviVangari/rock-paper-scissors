#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H

#include "IStrategy.hpp"
#include "GameEngine.hpp"

class GameInitializer
{
private:
    IStrategy* strategy;
    GameEngine* gameEngine;
public:
    GameInitializer();
    void startGame();
};

#endif // GAMEINITIALIZER_H
