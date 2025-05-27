#include "spacepiratesevent.h"
#include "../ui/uimanager.h"
#include <cstdlib>
#include <limits>
#include <algorithm>

constexpr int kFuelConsumption = 33;
constexpr int kFightSuccessRate = 50;

void spacePiratesEvent::manageEvents(std::shared_ptr<Ship> ship) {
    spacePirates(ship);
}

void spacePiratesEvent::spacePirates(const std::shared_ptr<Ship>& ship) {
    std::string decision;
    int overRun = 0;

    UIManager::pirateIncoming();

    while (true) {
        if (ship->getFuel() <= 1 && overRun == 0) {
            UIManager::pirateLowFuelWarning();
            overRun++;
        }

        UIManager::selectAction();
        std::cin >> decision;
        std::transform(decision.begin(), decision.end(), decision.begin(), ::tolower);

        if ((decision == "run" || decision == "r" || decision == "k") && ship->getFuel() > 1) {
            if (handleRun(ship)) break;
        } else if (decision == "fight" || decision == "f" || decision == "s") {
            if (handleFight(ship)) break;
        } else if (decision == "negotiate" || decision == "n" || decision == "p") {
            if (handleNegotiate(ship)) break;
        } else {
            UIManager::invalidInput();
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool spacePiratesEvent::handleRun(const std::shared_ptr<Ship>& ship) {
    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        UIManager::escapedPirates();
    } else {
        UIManager::failedEscape();
    }

    consumptionFuel(ship);
    UIManager::pirateFuelStatus(ship->getFuel());
    return true;
}

bool spacePiratesEvent::handleFight(const std::shared_ptr<Ship>& ship) {
    if (ship->getHealth() < ship->getDamage()) {
        UIManager::fightBlocked();
        return false;
    }

    int chance = rand() % 101;
    if (chance < kFightSuccessRate) {
        ship->takeDamage(ship->getDamage());
        UIManager::fightFail(ship->getDamage(), ship->getHealth());
    } else {
        UIManager::fightSuccess();
    }
    return true;
}

bool spacePiratesEvent::handleNegotiate(const std::shared_ptr<Ship>& ship) {
    const int costs[] = {10, 20, 30};
    int cost = costs[rand() % 3];

    if (ship->getBalance() >= cost) {
        ship->setBalance(ship->getBalance() - cost);
        UIManager::negotiationSuccess(cost, ship->getBalance());
        return true;
    } else {
        UIManager::negotiationFail();
        return false;
    }
}

void spacePiratesEvent::consumptionFuel(const std::shared_ptr<Ship>& ship) {
    ship->setFuel(ship->getFuel() - kFuelConsumption);
}


