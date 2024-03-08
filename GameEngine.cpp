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
    cout << "\n\n\n\t\t\tWelcome to Rock Paper Scissor "
            "Game\n";
    for(int i = 0 ; i < count; i++)
    {
        char choice;
        cout << "\n\t\tEnter R for ROCK, P for PAPER, and S "
                "for SCISSOR\n\t\t\t\t\t";
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
            cout<<"\tRound result: Congratulations!! User won this round"<<endl;
        }
        else
        {
            computerPoints++;
            cout<<"\tRound result: oh! Computer won this round"<<endl;
        }
    }
    if(userPoints > computerPoints)
        cout<<endl<<"\t\tMatch result: Congratulations!! User won the match"<<endl;
    if(computerPoints > userPoints)
        cout<<endl<<"\t\t Oh!Computer won the match"<<endl;
    else
        cout<<endl<<"\t\tMatch ended as Tie"<<endl;
}

bool GameEngine::userWon(char user, char comp)
{
    if((user == 'R' && comp == 'S') || (user == 'S' && comp == 'P') || (user == 'P' && comp == 'R'))
        return true;
    return false;
}
