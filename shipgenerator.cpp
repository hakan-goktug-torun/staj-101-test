//
// Created by ChatCPP on 02.03.2024
//

#include "shipgenerator.h"

void shipGenerator::playGame(const std::shared_ptr<Ship>& ship) {
    int gameScore {0};
    spacePiratesEvent eventSpace;
    crossTheBeltEvent beltEvent;
    abandonedPlanetEvent planetEvent;
    for (int eventNum {0}; eventNum < 5; ++eventNum) {
        if (ship->getFuel() <= 1) {
            gameScore = calculateScore(ship);
            displayScore(gameScore);
            break;
        }
        int randomEvent = rand() % 3 + 1;
        executeEvent(randomEvent, ship, eventSpace, beltEvent, planetEvent);
        if (eventNum == 4) {
            gameScore = calculateScore(ship);
            displayScore(gameScore);
        }
    }
}

void shipGenerator::addNewShip() {
    std::string shipType;
    std::cout << "Hello Captain! Welcome to the Space World Game!\n";
    while (true) {
        std::cout << "Enter which type of ship you want to be the captain of. For strong ship (s), for fast ship(f), for normal ship(n).\n";
        std::cin >> shipType;
        if (createShip(shipType)) break;
        std::cout << "Wrong typing! Please try again!\n";
    }
}

bool shipGenerator::createShip(const std::string& shipType) {
    int health = 100, fuel = 100, balance = 0;
    if (shipType == "s") {
        playGame(std::make_shared<strongShip>(health, fuel, balance));
    }
    else if (shipType == "f") {
        playGame(std::make_shared<fastShip>(health, fuel, balance));
    }
    else if (shipType == "n") {
        playGame(std::make_shared<normalShip>(health, fuel, balance));
    }
    else {
        return false;
    }
    return true;
}

void shipGenerator::executeEvent(int eventChoice, const std::shared_ptr<Ship>& ship, spacePiratesEvent& eventSpace, crossTheBeltEvent& beltEvent, abandonedPlanetEvent& planetEvent) {
    switch (eventChoice) {
        case 1: eventSpace.spacePirates(ship); break;
        case 2: std::cout << "***********************\n"; beltEvent.crossTheBelt(ship); break;
        case 3: std::cout << "***********************\n"; planetEvent.abandonedPlanet(ship); break;
        default: std::cout << "**********************\n";
    }
}

int shipGenerator::calculateScore(const std::shared_ptr<Ship>& ship) {
    return (ship->getFuel() * 5) + (ship->getHealth() * 10) + (ship->getBalance() * 10);
}

void shipGenerator::displayScore(int score) {
    std::cout << "Your game score: " << score << "\n Congratulations! You finished the game!\n";
}