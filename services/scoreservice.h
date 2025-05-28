#ifndef SPACEGAMES_SCORESERVICE_H
#define SPACEGAMES_SCORESERVICE_H

#pragma once
#include <memory>
#include <string>
#include "../ships/ship.h"
#include <map>
#include <tuple>
#include <nlohmann/json.hpp>

class ScoreService {
public:
    static int calculate(const std::shared_ptr<Ship>& ship);
    static void display(int score);
    static void saveToFile(const std::string& playerName, int score);
    static std::map<std::string, int> loadScores();
    static void displayTop5();
    static void saveGame(const std::shared_ptr<Ship>& ship, const std::string& shipType);
    static std::tuple<std::string, int, int, int> loadGame();
    static void saveGameJSON(const std::shared_ptr<Ship>& ship, const std::string& shipType);
    static std::tuple<std::string, int, int, int> loadGameJSON();
};

#endif // SPACEGAMES_SCORESERVICE_H
