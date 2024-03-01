#include "SmartStrategy.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <ctime>

bool SmartStrategy::frequenciesSaved = false;

const char SmartStrategy::choices[3] = {'R', 'P', 'S'};

SmartStrategy::SmartStrategy() {
    loadFrequencies();
    // Initialize your class here
}

char SmartStrategy::GenerateComputerResponse(char input) {
    updateHistory(input);

    // Get prediction based on history
    char prediction = predict();

    // Make a random choice if prediction is not available
    if (prediction == 'N') {
        prediction = makeRandomChoice();
    }

    // Update frequencies based on actual human choice
    updateFrequencies(input);

    return prediction;
}

void SmartStrategy::loadFrequencies() {
    std::ifstream file("frequencies.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string sequence;
            int frequency;
            if (iss >> sequence >> frequency) {
                frequencies[sequence] = frequency;
            }
        }
        file.close();
    }
}

void SmartStrategy::updateHistory(char input) {
    history.push_back(input);
    if (history.size() > N) {
        history.erase(history.begin());
    }
}

char SmartStrategy::predict() {
    std::map<std::string, int> predictionMap;
    for (int i = 0; i < history.size() - 1; i++) {
        std::string sequence = "";
        for (int j = i; j < i + N; j++) {
            sequence += history[j];
        }
        predictionMap[sequence]++;
    }

    std::string maxSequence = "";
    int maxFrequency = 0;
    for (auto& entry : predictionMap) {
        if (entry.second > maxFrequency) {
            maxSequence = entry.first;
            maxFrequency = entry.second;
        }
    }

    if (frequencies.find(maxSequence) != frequencies.end()) {
        return maxSequence[N - 1];
    } else {
        return 'N'; // Prediction not available
    }
}

char SmartStrategy::makeRandomChoice() {
    srand(time(nullptr));
    int random = rand() % 3;
    return choices[random];
}

void SmartStrategy::updateFrequencies(char humanChoice) {
    if (history.size() < N + 1) {
        return; // Not enough history for prediction
    }

    std::string sequence = "";
    for (int i = history.size() - N - 1; i < history.size() - 1; i++) {
        sequence += history[i];
    }
    sequence += humanChoice;

    frequencies[sequence]++;
}

void SmartStrategy::saveFrequencies() {
    if (!frequenciesSaved) {
        std::ofstream file("frequencies.txt");
        if (file.is_open()) {
            for (const auto& entry : frequencies) {
                file << entry.first << " " << entry.second << std::endl;
            }
            file.close();
            std::cout << "Frequencies saved to file." << std::endl; // Debugging output
            frequenciesSaved = true;
        } else {
            std::cout << "Unable to open frequencies.txt for writing." << std::endl; // Debugging output
        }
    }
}

SmartStrategy::~SmartStrategy() {
    // Define your destructor here
    // Clean up any resources if needed
    saveFrequencies();
}
