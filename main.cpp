#include <ctime>
#include "playerinterface.h"
#include "gameengine.h"
#include "scoreservice.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    auto ship = PlayerInterface::selectShip();

    GameEngine engine;

    engine.start(ship);

    PlayerInterface::askAndSaveScore(ship);
    ScoreService::displayTop5();

    return 0;
}


// (./spacegame.exe) oyunu başlatma komutu 



