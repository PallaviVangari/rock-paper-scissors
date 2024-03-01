#include "GameEngine.hpp"
#include <iostream>

using namespace std;

GameEngine::GameEngine(IStrategy* strategy)
{
    this->strategy = strategy;
    userPoints = 0;
    computerPoints = 0;
}

void GameEngine::startGame()
{
    int count = 20;
    for(int i = 0 ; i < count; i++)
    {
        char choice;
        cout<<"Enter your choice (R or P or S)";
        cin>>choice;
        char computerChoice = strategy->GenerateComputerResponse(choice);
        cout<<"Computer choice ="<<computerChoice<<endl;
        if(choice == computerChoice)
        {
            cout<<"Tie"<<endl;
            continue;
        }
        if(userWon(choice,computerChoice))
        {
            userPoints++;
            cout<<"User won this game"<<endl;
        }
        else
        {
            computerPoints++;
            cout<<"Compuer won this game"<<endl;
        }
    }
    if(userPoints > computerPoints)
        cout<<"User won the match"<<endl;
    if(computerPoints > userPoints)
        cout<<"Computer won the match"<<endl;
    else
        cout<<"Match ended as Tie"<<endl;
}

bool GameEngine::userWon(char user, char comp)
{
    if((user == 'R' && comp == 'S') || (user == 'S' && comp == 'P') || (user == 'P' && comp == 'R'))
        return true;
    return false;
}
