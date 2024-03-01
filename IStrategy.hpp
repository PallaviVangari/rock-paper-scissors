#ifndef ISTRATEGY_H
#define ISTRATEGY_H

class IStrategy
{
public:
    virtual char GenerateComputerResponse(char input) = 0;
    virtual ~IStrategy() {} 
};

#endif // ISTRATEGY_H
