///
// Created by ChatCPP on 02.03.2024
//

#include "spacepiratesevent.h"
#include <iostream>
#include <cstdlib>
#include <limits>

constexpr int kFuelConsumption = 33;
constexpr int kFightSuccessRate = 50;

void spacePiratesEvent::manageEvents(std::shared_ptr<Ship> ship) {
    spacePirates(ship);  // kendi özel olayını çağırır
}

void spacePiratesEvent::spacePirates(std::shared_ptr<Ship> ship) {
    std::string decision;
    int overRun = 0;

    std::cout << "***********************\n";
    std::cout << "Space Pirates are coming!\n";

    while (true) {
        if (ship->getFuel() <= 1 && overRun == 0) {
            std::cout << "You only have enough fuel to fight or negotiate. Choose wisely!\n";
            overRun++;
        }

        std::cout << "Run, fight, negotiate?\n> ";
        std::cin >> decision;

        if (decision == "run" && ship->getFuel() > 1) {
            if (handleRun(ship)) break;
        } else if (decision == "fight") {
            if (handleFight(ship)) break;
        } else if (decision == "negotiate") {
            if (handleNegotiate(ship)) break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool spacePiratesEvent::handleRun(const std::shared_ptr<Ship>& ship) {
    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        std::cout << "You've escaped but lost fuel.\n";
    } else {
        std::cout << "You couldn't escape! Lost fuel.\n";
    }
    ship->setFuel(ship->getFuel() - kFuelConsumption);
    std::cout << "Ship's fuel: " << ship->getFuel() << "\n";
    return true; // Run ends event
}

bool spacePiratesEvent::handleFight(const std::shared_ptr<Ship>& ship) {
    if (ship->getHealth() < ship->getDamage()) {
        std::cout << "Your ship can't take any more damage!\n";
        return false;
    }

    int chance = rand() % 101;
    if (chance < kFightSuccessRate) {
        std::cout << "You lost the fight! Your ship took damage!\n";
        ship->takeDamage(ship->getDamage());
        std::cout << "Ship's health: " << ship->getHealth() << "\n";
    } else {
        std::cout << "Congratulations! You won the fight!\n";
    }
    return true;
}

bool spacePiratesEvent::handleNegotiate(const std::shared_ptr<Ship>& ship) {
    const int costs[] = {10, 20, 30};
    int randomIndex = rand() % 3;
    int cost = costs[randomIndex];

    if (ship->getBalance() >= cost) {
        ship->setBalance(ship->getBalance() - cost);
        std::cout << "They took " << cost << " coins from you. New balance: " << ship->getBalance() << "\n";
        return true;
    } else {
        std::cout << "Not enough money! Pirates are angry!\n";
        return false;
    }
}

void spacePiratesEvent::consumptionFuel(const std::shared_ptr<Ship>& ship) {
    ship->setFuel(ship->getFuel() - kFuelConsumption);
}

//fonksiyonlar silindi
