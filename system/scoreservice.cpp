#include "scoreservice.h"
#include <iostream>
#include <fstream> //dosya okuma ve yazma için 

#include <sstream>
#include <vector>
#include <algorithm>

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

std::map<std::string, int> ScoreService::loadScores() {
    std::ifstream file("scores.txt");
    std::map<std::string, int> scores;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int score;
        if (std::getline(iss, name, ':') && iss >> score) {
            // Whitespace temizliği
            name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
            scores[name] = std::max(scores[name], score);
        }
    }

    return scores;
}

void ScoreService::displayTop5() {
    auto scores = loadScores();
    std::vector<std::pair<std::string, int>> scoreVec(scores.begin(), scores.end());

    std::sort(scoreVec.begin(), scoreVec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;  // büyükten küçüğe sırala
    });

    std::cout << "\n=== TOP 5 SCORES ===\n";
    int count = 0;
    for (const auto& [name, score] : scoreVec) {
        std::cout << name << ": " << score << "\n";
        if (++count >= 5) break;
    }
    std::cout << "====================\n";
}
void ScoreService::saveGame(const std::shared_ptr<Ship>& ship, const std::string& shipType) {
    std::ofstream file("save.txt");
    if (file.is_open()) {
        file << shipType << " " << ship->getFuel() << " " << ship->getHealth() << " " << ship->getBalance() << "\n";
        file.close();
        std::cout << "Game saved to save.txt!\n";
    } else {
        std::cout << "Failed to save the game.\n";
    }
}

std::tuple<std::string, int, int, int> ScoreService::loadGame() {
    std::ifstream file("save.txt");
    std::string type;
    int fuel, health, balance;

    if (file.is_open() && file >> type >> fuel >> health >> balance) {
        std::cout << "Game loaded from save.txt!\n";
        return {type, fuel, health, balance};
    } else {
        std::cout << "No saved game found or file corrupted.\n";
        return {"", 0, 0, 0};
    }
}
