#ifndef SMARTSTRATEGY_HPP
#define SMARTSTRATEGY_HPP

#include "IStrategy.hpp"
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

class SmartStrategy : public IStrategy {
public:

    SmartStrategy();
    ~SmartStrategy();
    virtual char GenerateComputerResponse(char input) override;

private:
    //static std::vector<char> choices;
    static bool frequenciesSaved;
    const int N = 5; // Sequence length for prediction
    std::vector<char> history;
    std::map<std::string, int> frequencies;
    bool frequenciesChanged = false;
    static const char choices[3]; // Array of choices

    void loadFrequencies();
    void updateHistory(char input);
    char predict();
    char makeRandomChoice();
    void updateFrequencies(char humanChoice);
    void saveFrequencies();
   // ~SmartStrategy(); // Destructor to save frequencies before destruction
};

#endif
