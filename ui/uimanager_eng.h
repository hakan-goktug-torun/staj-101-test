#pragma once
#include <iostream>
#include <memory>
#include "../ships/ship.h"

namespace UI_ENG {

inline void promptName() {
    std::cout << "Please enter your name for the scoreboard: ";
}

inline void printThanks() {
    std::cout << "Thanks for playing!\n";
}

inline void displayTop5Header() {
    std::cout << "\n=== TOP 5 SCORES ===\n";
}

inline void printCongratulations(int score) {
    std::cout << "Your score: " << score << "\n";
    std::cout << "Congratulations!\n";
}

inline void chooseShipPrompt() {
    std::cout << "Choose your ship type:\n  (s) Strong Ship\n  (f) Fast Ship\n  (n) Normal Ship\n> ";
}

inline void invalidInput() {
    std::cout << "Invalid input. Please try again.\n";
}

inline void printStatus(const std::shared_ptr<Ship>& ship) {
    std::cout << "\n=== Ship Status ===\n";
    std::cout << "Fuel:     " << ship->getFuel() << "\n";
    std::cout << "Health:   " << ship->getHealth() << "\n";
    std::cout << "Balance:  " << ship->getBalance() << "\n";
    std::cout << "===================\n";
}

inline void promptContinue() {
    std::cout << "Do you want to continue? (Y/N): ";
}

inline void scoreSaved() {
    std::cout << "Score saved to scores.txt\n";
}

inline void gameSaved() {
    std::cout << "Game saved to save.json!\n";
}

inline void gameSaveFailed() {
    std::cout << "Failed to save the game.\n";
}

inline void gameLoaded() {
    std::cout << "Game loaded from save.txt!\n";
}

inline void loadFailed() {
    std::cout << "No saved game found or file corrupted.\n";
}

inline void askToSave() {
    std::cout << "\nWould you like to save your game before exiting? (y/n): ";
}

inline void asteroidFieldDetected() {
    std::cout << "Asteroid field detected!\n";
}

inline void asteroidEscape() {
    std::cout << "You escaped the asteroid belt!\n";
}

inline void asteroidDamage(int damage) {
    std::cout << "You took damage from asteroids! Damage: " << damage << "\n";
}

inline void outOfFuel() {
    std::cout << "Your ship is out of fuel!\n";
}

inline void pirateIncoming() {
    std::cout << "*************************\nSpace Pirates are coming!\n*************************\n";
}

inline void selectAction() {
    std::cout << "Run (r), Fight (f), Negotiate (n)?\n> ";
}

inline void escapedPirates() {
    std::cout << "You escaped but lost fuel.\n";
}

inline void failedEscape() {
    std::cout << "You couldn't escape! Fuel lost.\n";
}

inline void negotiationSuccess(int cost, int newBalance) {
    std::cout << "You paid " << cost << " coins. New balance: " << newBalance << "\n";
}

inline void negotiationFail() {
    std::cout << "Not enough money! Pirates are angry!\n";
}

inline void fightSuccess() {
    std::cout << "Congratulations! You won the fight!\n";
}

inline void fightFail(int damage, int remainingHealth) {
    std::cout << "You lost the fight! Took " << damage << " damage. Remaining health: " << remainingHealth << "\n";
}

inline void fightBlocked() {
    std::cout << "Your ship can't take any more damage!\n";
}

inline void pirateFuelStatus(int fuel) {
    std::cout << "Fuel left: " << fuel << "\n";
}

inline void pirateLowFuelWarning() {
    std::cout << "You only have enough fuel to fight or negotiate. Choose wisely!\n";
}

inline void abandonedPlanetDiscovered() {
    std::cout << "You discovered an abandoned planet!\n";
}

inline void abandonedPlanetFoundCoins(int coins) {
    std::cout << "You found " << coins << " coins on the abandoned planet!\n";
}

inline void abandonedPlanetPirates() {
    std::cout << "Ambush on the abandoned planet! Space pirates incoming!\n";
}

inline void printWelcomeMenu() {
    std::cout << "Welcome to the Space Game!\n(1) Start New Game\n(2) Load Saved Game\n> ";
}

}
