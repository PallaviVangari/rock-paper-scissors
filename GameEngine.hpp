#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "IStrategy.hpp"

class GameEngine
{
private:
    IStrategy* strategy;
    int userPoints;
    int computerPoints;
    bool userWon(char user, char comp);
public:
    explicit GameEngine(IStrategy* strategy);
    void startGame();
};

#endif // GAMEENGINE_H
