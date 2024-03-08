#include "GameInitializer.hpp"
#include "RandomGenerator.hpp"
#include "SmartStrategy.hpp"
#include <iostream>

using namespace std;

GameInitializer::GameInitializer()
{
    char choice;
    cout<<"In this game, you have the option to face off against the computer using one of two distinct strategies: Random Strategy or Smart Strategy. Please select your preferred approach before we commence the game."<<endl;
    cout<<"Enter R If you want to face off computer with RANDOM STRATEGY or any other character if you want to face off computer with SMART STRATEGY\t\t";
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
