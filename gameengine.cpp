#include "gameengine.h"
#include "eventmanager.h"
#include "scoreservice.h"

void GameEngine::start(const std::shared_ptr<Ship>& ship) {
    EventManager eventManager;

    for (int i = 0; i < 5; ++i) {
        if (ship->getFuel() <= 1 && i != 0) {
            
            int finalScore = ScoreService::calculate(ship);
            ScoreService::display(finalScore);
            return;
        }
        eventManager.triggerRandomEvent(ship);
    }

    int finalScore = ScoreService::calculate(ship);
    ScoreService::display(finalScore);

}
