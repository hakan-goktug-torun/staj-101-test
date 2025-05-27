#ifndef SPACEGAMES_SCORESERVICE_H
#define SPACEGAMES_SCORESERVICE_H

#include <map>
#include <memory>
#include <string>
#include "ship.h"

class ScoreService {
public:
    static int calculate(const std::shared_ptr<Ship>& ship); //nesne çağırmadan kullanabilmek için static
    static void display(int score);
    static void saveToFile(const std::string& playerName, int score);
    static std::map<std::string, int> loadScores();                // Dosyadan skorları oku
    static void displayTop5();                                     // En iyi 5 skoru göster
};

#endif // SPACEGAMES_SCORESERVICE_H



