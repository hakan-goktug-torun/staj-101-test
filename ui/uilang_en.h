#pragma once
#include "uilanguage.h"
#include <iostream>

class UILangEN : public IUILanguage {
public:
    void promptName() override {
        std::cout << "Please enter your name for the scoreboard: ";
    }

    void printThanks() override {
        std::cout << "Thanks for playing!\n";
    }

    void displayTop5Header() override {
        std::cout << "\n=== TOP 5 SCORES ===\n";
    }

    void printCongratulations(int score) override {
        std::cout << "Your score: " << score << "\n";
        std::cout << "Congratulations!\n";
    }

    void chooseShipPrompt() override {
        std::cout << "Choose your ship type:\n  (s) Strong Ship\n  (f) Fast Ship\n  (n) Normal Ship\n> ";
    }

    void invalidInput() override {
        std::cout << "Invalid input. Please try again.\n";
    }

    void printStatus(const std::shared_ptr<Ship>& ship) override {
        std::cout << "\n=== Ship Status ===\n";
        std::cout << "Fuel:     " << ship->getFuel() << "\n";
        std::cout << "Health:   " << ship->getHealth() << "\n";
        std::cout << "Balance:  " << ship->getBalance() << "\n";
        std::cout << "===================\n";
    }

    void promptContinue() override {
        std::cout << "Do you want to continue? (Y/N): ";
    }

    void scoreSaved() override {
        std::cout << "Score saved to scores.txt\n";
    }

    void gameSaved() override {
        std::cout << "Game saved to save.json!\n";
    }

    void gameSaveFailed() override {
        std::cout << "Failed to save the game.\n";
    }

    void gameLoaded() override {
        std::cout << "Game loaded from save.txt!\n";
    }

    void loadFailed() override {
        std::cout << "No saved game found or file corrupted.\n";
    }

    void askToSave() override {
        std::cout << "\nWould you like to save your game before exiting? (y/n): ";
    }

    void asteroidFieldDetected() override {
        std::cout << "Asteroid field detected!\n";
    }

    void asteroidEscape() override {
        std::cout << "You escaped the asteroid belt!\n";
    }

    void asteroidDamage(int damage) override {
        std::cout << "You took damage from asteroids! Damage: " << damage << "\n";
    }

    void outOfFuel() override {
        std::cout << "Your ship is out of fuel!\n";
    }

    void pirateIncoming() override {
        std::cout << "*************************\nSpace Pirates are coming!\n*************************\n";
    }

    void selectAction() override {
        std::cout << "Run (r), Fight (f), Negotiate (n)?\n> ";
    }

    void escapedPirates() override {
        std::cout << "You escaped but lost fuel.\n";
    }

    void failedEscape() override {
        std::cout << "You couldn't escape! Fuel lost.\n";
    }

    void negotiationSuccess(int cost, int newBalance) override {
        std::cout << "You paid " << cost << " coins. New balance: " << newBalance << "\n";
    }

    void negotiationFail() override {
        std::cout << "Not enough money! Pirates are angry!\n";
    }

    void fightSuccess() override {
        std::cout << "Congratulations! You won the fight!\n";
    }

    void fightFail(int damage, int remainingHealth) override {
        std::cout << "You lost the fight! Took " << damage << " damage. Remaining health: " << remainingHealth << "\n";
    }

    void fightBlocked() override {
        std::cout << "Your ship can't take any more damage!\n";
    }

    void pirateFuelStatus(int fuel) override {
        std::cout << "Fuel left: " << fuel << "\n";
    }

    void pirateLowFuelWarning() override {
        std::cout << "You only have enough fuel to fight or negotiate. Choose wisely!\n";
    }

    void abandonedPlanetDiscovered() override {
        std::cout << "You discovered an abandoned planet!\n";
    }

    void abandonedPlanetFoundCoins(int coins) override {
        std::cout << "You found " << coins << " coins on the abandoned planet!\n";
    }

    void abandonedPlanetPirates() override {
        std::cout << "Ambush on the abandoned planet! Space pirates incoming!\n";
    }

    void printWelcomeMenu() override {
        std::cout << "Welcome to the Space Game!\n(1) Start New Game\n(2) Load Saved Game\n> ";
    }
};
