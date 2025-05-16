#include "scoreservice.h"
#include <iostream>
#include <fstream> //dosya okuma ve yazma için 

int ScoreService::calculate(const std::shared_ptr<Ship>& ship) {
    return (ship->getFuel() * 5) + (ship->getHealth() * 10) + (ship->getBalance() * 10);
}

void ScoreService::display(int score) {
    std::cout << "Your game score: " << score << "\nCongratulations!\n";
}

void ScoreService::saveToFile(const std::string& playerName, int score) {
    std::ofstream file("scores.txt", std::ios::app); 
    if (file.is_open()) {
        file << playerName << ": " << score << "\n";
        file.close();
        std::cout << "Score saved to scores.txt\n";
    } else {
        std::cout << "Could not open file to save score.\n";
    }
}
