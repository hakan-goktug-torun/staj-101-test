#ifndef SPACEGAMES_SCORESERVICE_H
#define SPACEGAMES_SCORESERVICE_H

#include <map>
#include <memory>
#include <string>
#include <tuple>
#include "ship.h"


class ScoreService {
public:
    static int calculate(const std::shared_ptr<Ship>& ship); //nesne çağırmadan kullanabilmek için static
    static void display(int score);
    static void saveToFile(const std::string& playerName, int score);
    static std::map<std::string, int> loadScores();                // Dosyadan skorları oku
    static void displayTop5();        
    static void saveGame(const std::shared_ptr<Ship>& ship, const std::string& shipType);
    static std::tuple<std::string, int, int, int> loadGame();                             // En iyi 5 skoru göster
};

#endif // SPACEGAMES_SCORESERVICE_H



