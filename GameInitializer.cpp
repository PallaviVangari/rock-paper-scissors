#include "GameInitializer.hpp"
#include "RandomGenerator.hpp"
#include "SmartStrategy.hpp"
#include <iostream>

using namespace std;

GameInitializer::GameInitializer()
{
    char choice;
    cout<<"Enter R for random and anything else for special\t\t";
    cin>> choice;

    if(choice == 'R')
        strategy = new RandomGenerator();
    else    
        strategy = new SmartStrategy();
    
    gameEngine = new GameEngine(strategy);
}

void GameInitializer::startGame()
{
    gameEngine->startGame();
}
