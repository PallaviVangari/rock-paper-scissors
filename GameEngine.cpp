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
        cout<<endl<<"\tEnter your choice (R or P or S)\t";
        cin>>choice;
        char computerChoice = strategy->GenerateComputerResponse(choice);
        cout<<"\tComputer choice =\t"<<computerChoice<<endl;
        if(choice == computerChoice)
        {
            cout<<"\tRound Result: Tie"<<endl;
            continue;
        }
        if(userWon(choice,computerChoice))
        {
            userPoints++;
            cout<<"\tRound result: User won this round"<<endl;
        }
        else
        {
            computerPoints++;
            cout<<"\tRound result: Computer won this round"<<endl;
        }
    }
    if(userPoints > computerPoints)
        cout<<endl<<"\t\tMatch result: User won the match"<<endl;
    if(computerPoints > userPoints)
        cout<<endl<<"\t\tComputer won the match"<<endl;
    else
        cout<<endl<<"\t\tMatch ended as Tie"<<endl;
}

bool GameEngine::userWon(char user, char comp)
{
    if((user == 'R' && comp == 'S') || (user == 'S' && comp == 'P') || (user == 'P' && comp == 'R'))
        return true;
    return false;
}
