#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "IStrategy.hpp"

class GameEngine
{
private:
    IStrategy* strategy;
    int userPoints;
    int computerPoints;
public:
    GameEngine(IStrategy* strategy);
    void startGame();
    bool userWon(char user, char comp);
};

#endif // GAMEENGINE_H
