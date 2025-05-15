#include "gameengine.h"
#include "eventmanager.h"
#include "scoreservice.h"

void GameEngine::start(const std::shared_ptr<Ship>& ship) {
    EventManager eventManager;

    for (int i = 0; i < 5; ++i) {
        if (ship->getFuel() <= 1 && i != 0) {
            ScoreService::display(ScoreService::calculate(ship));
            return;
        }
        eventManager.triggerRandomEvent(ship);
    }

    ScoreService::display(ScoreService::calculate(ship));
}
