#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include "../ships/ship.h"
#include "uimanager_tr.h"
#include "uimanager_eng.h"

enum class Language { EN, TR };

class UIManager {
public:
    static Language lang;

    static void slowPrint(const std::string& text, int delayMs = 10) {
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
    }

    static void promptName() {
        switch (lang) {
            case Language::TR: UI_TR::promptName(); break;
            case Language::EN: default: UI_ENG::promptName(); break;
        }
    }

    static void printWelcomeMenu() {
        switch (lang) {
            case Language::TR: UI_TR::printWelcomeMenu(); break;
            case Language::EN: default: UI_ENG::printWelcomeMenu(); break;
        }
    }

    static void printThanks() {
        switch (lang) {
            case Language::TR: UI_TR::printThanks(); break;
            case Language::EN: default: UI_ENG::printThanks(); break;
        }
    }

    static void displayTop5Header() {
        switch (lang) {
            case Language::TR: UI_TR::displayTop5Header(); break;
            case Language::EN: default: UI_ENG::displayTop5Header(); break;
        }
    }

    static void printCongratulations(int score) {
        switch (lang) {
            case Language::TR: UI_TR::printCongratulations(score); break;
            case Language::EN: default: UI_ENG::printCongratulations(score); break;
        }
    }

    static void promptLanguage() {
        std::cout << "Select Language / Dil Seçin: (En/Tr): ";
    }

    static void chooseShipPrompt() {
        switch (lang) {
            case Language::TR: UI_TR::chooseShipPrompt(); break;
            case Language::EN: default: UI_ENG::chooseShipPrompt(); break;
        }
    }

    static void invalidInput() {
        switch (lang) {
            case Language::TR: UI_TR::invalidInput(); break;
            case Language::EN: default: UI_ENG::invalidInput(); break;
        }
    }

    static void printStatus(const std::shared_ptr<Ship>& ship) {
        switch (lang) {
            case Language::TR: UI_TR::printStatus(ship); break;
            case Language::EN: default: UI_ENG::printStatus(ship); break;
        }
    }

    static void promptContinue() {
        switch (lang) {
            case Language::TR: UI_TR::promptContinue(); break;
            case Language::EN: default: UI_ENG::promptContinue(); break;
        }
    }

    static void scoreSaved() {
        switch (lang) {
            case Language::TR: UI_TR::scoreSaved(); break;
            case Language::EN: default: UI_ENG::scoreSaved(); break;
        }
    }

    static void gameSaved() {
        switch (lang) {
            case Language::TR: UI_TR::gameSaved(); break;
            case Language::EN: default: UI_ENG::gameSaved(); break;
        }
    }

    static void gameSaveFailed() {
        switch (lang) {
            case Language::TR: UI_TR::gameSaveFailed(); break;
            case Language::EN: default: UI_ENG::gameSaveFailed(); break;
        }
    }

    static void gameLoaded() {
        switch (lang) {
            case Language::TR: UI_TR::gameLoaded(); break;
            case Language::EN: default: UI_ENG::gameLoaded(); break;
        }
    }

    static void loadFailed() {
        switch (lang) {
            case Language::TR: UI_TR::loadFailed(); break;
            case Language::EN: default: UI_ENG::loadFailed(); break;
        }
    }

    static void askToSave() {
        switch (lang) {
            case Language::TR: UI_TR::askToSave(); break;
            case Language::EN: default: UI_ENG::askToSave(); break;
        }
    }

    static void asteroidFieldDetected() {
        switch (lang) {
            case Language::TR: UI_TR::asteroidFieldDetected(); break;
            case Language::EN: default: UI_ENG::asteroidFieldDetected(); break;
        }
    }

    static void asteroidEscape() {
        switch (lang) {
            case Language::TR: UI_TR::asteroidEscape(); break;
            case Language::EN: default: UI_ENG::asteroidEscape(); break;
        }
    }

    static void asteroidDamage(int damage) {
        switch (lang) {
            case Language::TR: UI_TR::asteroidDamage(damage); break;
            case Language::EN: default: UI_ENG::asteroidDamage(damage); break;
        }
    }

    static void outOfFuel() {
        switch (lang) {
            case Language::TR: UI_TR::outOfFuel(); break;
            case Language::EN: default: UI_ENG::outOfFuel(); break;
        }
    }

        static void pirateIncoming() {
        switch (lang) {
            case Language::TR: UI_TR::pirateIncoming(); break;
            case Language::EN: default: UI_ENG::pirateIncoming(); break;
        }
    }

    static void selectAction() {
        switch (lang) {
            case Language::TR: UI_TR::selectAction(); break;
            case Language::EN: default: UI_ENG::selectAction(); break;
        }
    }

    static void escapedPirates() {
        switch (lang) {
            case Language::TR: UI_TR::escapedPirates(); break;
            case Language::EN: default: UI_ENG::escapedPirates(); break;
        }
    }

    static void failedEscape() {
        switch (lang) {
            case Language::TR: UI_TR::failedEscape(); break;
            case Language::EN: default: UI_ENG::failedEscape(); break;
        }
    }

    static void negotiationSuccess(int cost, int newBalance) {
        switch (lang) {
            case Language::TR: UI_TR::negotiationSuccess(cost, newBalance); break;
            case Language::EN: default: UI_ENG::negotiationSuccess(cost, newBalance); break;
        }
    }

    static void negotiationFail() {
        switch (lang) {
            case Language::TR: UI_TR::negotiationFail(); break;
            case Language::EN: default: UI_ENG::negotiationFail(); break;
        }
    }

    static void fightSuccess() {
        switch (lang) {
            case Language::TR: UI_TR::fightSuccess(); break;
            case Language::EN: default: UI_ENG::fightSuccess(); break;
        }
    }

    static void fightFail(int damage, int remainingHealth) {
        switch (lang) {
            case Language::TR: UI_TR::fightFail(damage, remainingHealth); break;
            case Language::EN: default: UI_ENG::fightFail(damage, remainingHealth); break;
        }
    }

    static void fightBlocked() {
        switch (lang) {
            case Language::TR: UI_TR::fightBlocked(); break;
            case Language::EN: default: UI_ENG::fightBlocked(); break;
        }
    }

    static void pirateFuelStatus(int fuel) {
        switch (lang) {
            case Language::TR: UI_TR::pirateFuelStatus(fuel); break;
            case Language::EN: default: UI_ENG::pirateFuelStatus(fuel); break;
        }
    }

    static void pirateLowFuelWarning() {
        switch (lang) {
            case Language::TR: UI_TR::pirateLowFuelWarning(); break;
            case Language::EN: default: UI_ENG::pirateLowFuelWarning(); break;
        }
    }

    static void abandonedPlanetDiscovered() {
        switch (lang) {
            case Language::TR: UI_TR::abandonedPlanetDiscovered(); break;
            case Language::EN: default: UI_ENG::abandonedPlanetDiscovered(); break;
        }
    }

    static void abandonedPlanetFoundCoins(int coins) {
        switch (lang) {
            case Language::TR: UI_TR::abandonedPlanetFoundCoins(coins); break;
            case Language::EN: default: UI_ENG::abandonedPlanetFoundCoins(coins); break;
        }
    }

    static void abandonedPlanetPirates() {
        switch (lang) {
            case Language::TR: UI_TR::abandonedPlanetPirates(); break;
            case Language::EN: default: UI_ENG::abandonedPlanetPirates(); break;
        }
    }
};
