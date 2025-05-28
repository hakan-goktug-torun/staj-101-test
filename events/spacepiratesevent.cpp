#include "spacepiratesevent.h"
#include "../ui/uimanager.h"
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <iostream>

constexpr int kFuelConsumption = 33;
constexpr int kFightSuccessRate = 50;

void spacePiratesEvent::manageEvents(std::shared_ptr<Ship> ship) {
    spacePirates(ship);
}

spacePiratesEvent::Action spacePiratesEvent::parseActionInput(const std::string& input) {
    std::string lower = input;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "run" || lower == "r" || lower == "k") return Action::Run;
    if (lower == "fight" || lower == "f" || lower == "s") return Action::Fight;
    if (lower == "negotiate" || lower == "n" || lower == "p") return Action::Negotiate;
    return Action::Invalid;
}

void spacePiratesEvent::spacePirates(const std::shared_ptr<Ship>& ship) {
    std::string decision;
    int overRun = 0;
    int attempts = 0;
    constexpr int maxAttempts = 3;

    UIManager::get().pirateIncoming();

    while (attempts < maxAttempts) {
        if (ship->getFuel() <= 1 && overRun == 0) {
            UIManager::get().pirateLowFuelWarning();
            overRun++;
        }

        UIManager::get().selectAction();
        std::getline(std::cin, decision);

        Action action = parseActionInput(decision);
        switch (action) {
            case Action::Run:
                if (ship->getFuel() > 1 && handleRun(ship)) return;
                break;
            case Action::Fight:
                if (handleFight(ship)) return;
                break;
            case Action::Negotiate:
                if (handleNegotiate(ship)) return;
                break;
            default:
                UIManager::get().invalidInput();
                attempts++;
                break;
        }
    }

    std::cout << "Too many invalid attempts. Skipping event.\n";
}

bool spacePiratesEvent::handleRun(const std::shared_ptr<Ship>& ship) {
    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        UIManager::get().escapedPirates();
    } else {
        UIManager::get().failedEscape();
    }

    consumptionFuel(ship);
    UIManager::get().pirateFuelStatus(ship->getFuel());
    return true;
}

bool spacePiratesEvent::handleFight(const std::shared_ptr<Ship>& ship) {
    if (ship->getHealth() < ship->getDamage()) {
        UIManager::get().fightBlocked();
        return false;
    }

    int chance = rand() % 101;
    if (chance >= kFightSuccessRate) {
        UIManager::get().fightSuccess();
    } else {
        ship->takeDamage(ship->getDamage());
        UIManager::get().fightFail(ship->getDamage(), ship->getHealth());
    }

    return true;
}

bool spacePiratesEvent::handleNegotiate(const std::shared_ptr<Ship>& ship) {
    const int costs[] = {10, 20, 30};
    int cost = costs[rand() % 3];

    if (ship->getBalance() >= cost) {
        ship->setBalance(ship->getBalance() - cost);
        UIManager::get().negotiationSuccess(cost, ship->getBalance());
        return true;
    } else {
        UIManager::get().negotiationFail();
        return false;
    }
}

void spacePiratesEvent::consumptionFuel(const std::shared_ptr<Ship>& ship) {
    ship->setFuel(ship->getFuel() - kFuelConsumption);
}


