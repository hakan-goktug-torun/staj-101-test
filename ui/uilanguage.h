#pragma once
#include <memory>
#include "../ships/ship.h"
#include <chrono>
#include <thread>

class IUILanguage {
public:
    virtual ~IUILanguage() = default;

    virtual void promptName() = 0;
    virtual void printThanks() = 0;
    virtual void displayTop5Header() = 0;
    virtual void printCongratulations(int score) = 0;
    virtual void chooseShipPrompt() = 0;
    virtual void invalidInput() = 0;
    virtual void printStatus(const std::shared_ptr<Ship>& ship) = 0;
    virtual void promptContinue() = 0;
    virtual void scoreSaved() = 0;
    virtual void gameSaved() = 0;
    virtual void gameSaveFailed() = 0;
    virtual void gameLoaded() = 0;
    virtual void loadFailed() = 0;
    virtual void askToSave() = 0;
    virtual void asteroidFieldDetected() = 0;
    virtual void asteroidEscape() = 0;
    virtual void asteroidDamage(int damage) = 0;
    virtual void outOfFuel() = 0;
    virtual void pirateIncoming() = 0;
    virtual void selectAction() = 0;
    virtual void escapedPirates() = 0;
    virtual void failedEscape() = 0;
    virtual void negotiationSuccess(int cost, int newBalance) = 0;
    virtual void negotiationFail() = 0;
    virtual void fightSuccess() = 0;
    virtual void fightFail(int damage, int remainingHealth) = 0;
    virtual void fightBlocked() = 0;
    virtual void pirateFuelStatus(int fuel) = 0;
    virtual void pirateLowFuelWarning() = 0;
    virtual void abandonedPlanetDiscovered() = 0;
    virtual void abandonedPlanetFoundCoins(int coins) = 0;
    virtual void abandonedPlanetPirates() = 0;
    virtual void printWelcomeMenu() = 0;
    virtual void printEventDivider() = 0;
    virtual void printIntroArt() = 0;
    virtual void printGameRules() = 0;


    inline void printSlow(const std::string& text, int delayMs = 30) {
    for (char ch : text) {
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
    }
};
