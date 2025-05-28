#pragma once
#include "uilanguage.h"
#include <iostream>
#include "color.h"


class UILangEN : public IUILanguage {
public:
    void promptName() override {
        std::cout << "Please enter your name for the scoreboard: ";
    }

    void printThanks() override {
        std::cout << BOLD << GREEN;
        printSlow("\n╔════════════════════════════╗\n");
        printSlow("║     Thanks for playing!    ║\n");
        printSlow("╚════════════════════════════╝\n");
        std::cout << RESET;
    }


    void displayTop5Header() override {
        std::cout << BOLD << CYAN << "\n=== TOP 5 SCORES ===\n" << RESET;
    }

    void printCongratulations(int score) override {
        std::cout << "Your score: " << score << "\n";
        std::cout << "Congratulations!\n";
    }

    void chooseShipPrompt() override {
        std::cout << "Choose your ship type:\n  (s) Strong Ship\n  (f) Fast Ship\n  (n) Normal Ship\n> ";
    }

    void invalidInput() override {
        std::cout << BOLD << RED << "Invalid input. Please try again.\n" << RESET;
    }

    void printStatus(const std::shared_ptr<Ship>& ship) override {
    std::cout << BOLD << MAGENTA << "\n╔══════════════════════╗\n";
    std::cout << "║     SHIP STATUS      ║\n";
    std::cout << "╠══════════════════════╣\n" << RESET;

    std::cout << "  Fuel:    " << GREEN << ship->getFuel() << RESET << "\n";

    std::cout << "  Health:  ";
    if (ship->getHealth() > 70)
        std::cout << GREEN;
    else if (ship->getHealth() > 30)
        std::cout << YELLOW;
    else
        std::cout << RED;
    std::cout << ship->getHealth() << RESET << "\n";

    std::cout << "  Balance: " << CYAN << ship->getBalance() << RESET << "\n";
    std::cout << BOLD << MAGENTA << "╚══════════════════════╝" << RESET << "\n";
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
        std::cout << "Game loaded from save.json!\n";
    }

    void loadFailed() override {
        std::cout << "No saved game found or file corrupted.\n";
    }

    void askToSave() override {
        std::cout << "\nWould you like to save your game before exiting? (y/n): ";
    }

    void asteroidFieldDetected() override {
        std::cout << BOLD << YELLOW << "Asteroid field detected!\n" << RESET;
    }

    void asteroidEscape() override {
        std::cout << "You escaped the asteroid belt!\n";
    }

    void asteroidDamage(int damage) override {
        std::cout << "You took damage from asteroids! Damage: " << damage << "\n";
    }

    void outOfFuel() override {
        std::cout << BOLD << RED << "Your ship is out of fuel! You can't move.\n" << RESET;
    }

    void pirateIncoming() override {
        std::cout << BOLD << RED;
        printSlow("\n*************************\n");
        printSlow("  SPACE PIRATES INCOMING!\n");
        printSlow("*************************\n");
        std::cout << RESET;
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
        std::cout << GREEN << "You paid " << cost << " coins. New balance: " << newBalance << "\n" << RESET;
    }

    void negotiationFail() override {
        std::cout << RED << "Not enough money! Pirates are angry!\n" << RESET;
    }

    void fightSuccess() override {
        std::cout << "Congratulations! You won the fight!\n";
    }

    void fightFail(int damage, int remainingHealth) override {
        std::cout << RED;
        printSlow("You lost the fight!\n");
        printSlow("Damage: " + std::to_string(damage) + 
                ", Health left: " + std::to_string(remainingHealth) + "\n");
        std::cout << RESET;
    }


    void fightBlocked() override {
        std::cout << "Your ship can't take any more damage!\n";
    }

    void pirateFuelStatus(int fuel) override {
        std::cout << "Fuel left: " << fuel << "\n";
    }

    void pirateLowFuelWarning() override {
        std::cout << BOLD << YELLOW << "Fuel is low! You can only fight or negotiate. Choose wisely!\n" << RESET;
    }

    void abandonedPlanetDiscovered() override {
        std::cout << YELLOW;
        printSlow("You discovered an abandoned planet...\n", 40);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        printSlow("Silence surrounds the place...\n", 40);
        std::cout << RESET;
    }


    void abandonedPlanetFoundCoins(int coins) override {
        std::cout << "You found " << coins << " coins on the abandoned planet!\n";
    }

    void abandonedPlanetPirates() override {
        std::cout << "Ambush on the abandoned planet! Space pirates incoming!\n";
    }

    void printWelcomeMenu() override {
        std::cout << BOLD << CYAN;
        std::cout << "╔════════════════════════════════════╗\n";
        std::cout << "║        WELCOME TO SPACE GAME       ║\n";
        std::cout << "╠════════════════════════════════════╣\n";
        std::cout << "║ (1) Start New Game                 ║\n";
        std::cout << "║ (2) Load Saved Game                ║\n";
        std::cout << "╚════════════════════════════════════╝\n";
        std::cout << RESET << "> ";
    }

    void printEventDivider() override {
        std::cout << BOLD << BLUE << "\n――――  New Space Anomaly Detected  ――――\n" << RESET;
    }
    
    void printIntroArt() override {
    std::cout << BOLD << CYAN;
    printSlow(R"(
        ___
     __/___\__
   _|         |_
  |  ___   ___  |
  | |___| |___| |
   \    |_|    /
    \_________/
      /  |  \
     |   |   |
     |___|___|
     [=======]
 Welcome Captain!
    )", 1);
    std::cout << RESET;
}


    void printGameRules() override {
        std::cout << BOLD << MAGENTA;
        printSlow("\n╔════════════════════════════════════════╗\n");
        printSlow("║              GAME RULES                ║\n");
        printSlow("╠════════════════════════════════════════╣\n");
        printSlow("║ • Each round, a random event occurs.   ║\n");
        printSlow("║ • If fuel hits zero, you can't move.   ║\n");
        printSlow("║ • If health reaches zero, you lose.    ║\n");
        printSlow("║ • Your choices shape your journey.     ║\n");
        printSlow("╚════════════════════════════════════════╝\n");
        std::cout << RESET;

        std::cout << "\nPress ENTER to continue...";
        std::cin.ignore();
    }
};
