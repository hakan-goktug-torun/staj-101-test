#include "scoreservice.h"
#include "../ui/uimanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int ScoreService::calculate(const std::shared_ptr<Ship>& ship) {
    return (ship->getFuel() * 5) + (ship->getHealth() * 10) + (ship->getBalance() * 10);
}

void ScoreService::display(int score) {
    UIManager::get().printCongratulations(score);
}

void ScoreService::saveToFile(const std::string& playerName, int score) {
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open()) {
        file << playerName << ": " << score << "\n";
        file.close();
        UIManager::get().scoreSaved();
    } else {
        UIManager::get().gameSaveFailed();
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
            name.erase(name.find_last_not_of(" \t\r\n") + 1);
            name.erase(0, name.find_first_not_of(" \t\r\n"));
            scores[name] = std::max(scores[name], score);
        }
    }

    return scores;
}

void ScoreService::displayTop5() {
    auto scores = loadScores();
    std::vector<std::pair<std::string, int>> scoreVec(scores.begin(), scores.end());

    std::sort(scoreVec.begin(), scoreVec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    UIManager::get().displayTop5Header();
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
        UIManager::get().gameSaved();
    } else {
        UIManager::get().gameSaveFailed();
    }
}

std::tuple<std::string, int, int, int> ScoreService::loadGame() {
    std::ifstream file("save.txt");
    std::string type;
    int fuel, health, balance;

    if (file.is_open() && file >> type >> fuel >> health >> balance) {
        UIManager::get().gameLoaded();
        return {type, fuel, health, balance};
    } else {
        UIManager::get().loadFailed();
        return {"", 0, 0, 0};
    }
}

void ScoreService::saveGameJSON(const std::shared_ptr<Ship>& ship, const std::string& shipType) {
    json j;
    j["type"] = shipType;
    j["fuel"] = ship->getFuel();
    j["health"] = ship->getHealth();
    j["balance"] = ship->getBalance();

    std::ofstream file("save.json");
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
        UIManager::get().gameSaved();
    } else {
        UIManager::get().gameSaveFailed();
    }
}

std::tuple<std::string, int, int, int> ScoreService::loadGameJSON() {
    std::ifstream file("save.json");
    if (!file.is_open()) {
        UIManager::get().loadFailed();
        return {"", 0, 0, 0};
    }

    json j;
    try {
        file >> j;
        std::string type = j.at("type").get<std::string>();
        int fuel = j.at("fuel").get<int>();
        int health = j.at("health").get<int>();
        int balance = j.at("balance").get<int>();
        UIManager::get().gameLoaded();
        return {type, fuel, health, balance};
    }
    catch (const std::exception& e) {
        std::cerr << "JSON Error: " << e.what() << std::endl;
        UIManager::get().loadFailed();
        return {"", 0, 0, 0};
    }
}
