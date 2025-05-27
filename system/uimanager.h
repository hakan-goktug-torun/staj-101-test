#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include "../ships/ship.h"

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

    static void promptLanguage() {
        std::cout << "Select Language / Dil Seçin: (En/Tr): ";
    }

    static void printStatus(const std::shared_ptr<Ship>& ship) {
        std::cout << "\n=== ";
        switch (lang) {
            case Language::TR: slowPrint("Gemi Durumu"); break;
            case Language::EN:
            default: slowPrint("Ship Status"); break;
        }
        std::cout << " ===\n";

        switch (lang) {
            case Language::TR:
                std::cout << "Yakıt:    " << ship->getFuel() << "\n";
                std::cout << "Can:      " << ship->getHealth() << "\n";
                std::cout << "Bakiye:   " << ship->getBalance() << "\n";
                break;
            case Language::EN:
            default:
                std::cout << "Fuel:     " << ship->getFuel() << "\n";
                std::cout << "Health:   " << ship->getHealth() << "\n";
                std::cout << "Balance:  " << ship->getBalance() << "\n";
                break;
        }
        std::cout << "===================\n";
    }

    static void promptContinue() {
        switch (lang) {
            case Language::TR: slowPrint("Devam etmek istiyor musun? (E/H): "); break;
            case Language::EN:
            default: slowPrint("Do you want to continue? (Y/N): "); break;
        }
    }

    static void promptName() {
        switch (lang) {
            case Language::TR: slowPrint("Lütfen ismini gir: "); break;
            case Language::EN:
            default: slowPrint("Please enter your name for the scoreboard: "); break;
        }
    }

    static void printCongratulations(int score) {
        switch (lang) {
            case Language::TR:
                std::cout << "Skorun: " << score << "\n";
                slowPrint("Tebrikler!\n");
                break;
            case Language::EN:
            default:
                std::cout << "Your score: " << score << "\n";
                slowPrint("Congratulations!\n");
                break;
        }
    }

    static void printThanks() {
        switch (lang) {
            case Language::TR: slowPrint("Oynadığın için teşekkürler!\n"); break;
            case Language::EN:
            default: slowPrint("Thanks for playing!\n"); break;
        }
    }

    static void outOfFuel() {
        switch (lang) {
            case Language::TR: slowPrint("Gemin yakıtsız kaldı!\n"); break;
            case Language::EN:
            default: slowPrint("Your ship is out of fuel!\n"); break;
        }
    }

    static void chooseShipPrompt() {
        switch (lang) {
            case Language::TR:
                slowPrint("Gemi tipini seç:\n  (g) Güçlü Gemi\n  (h) Hızlı Gemi\n  (n) Normal Gemi\n> ");
                break;
            case Language::EN:
            default:
                slowPrint("Choose your ship type:\n  (s) Strong Ship\n  (f) Fast Ship\n  (n) Normal Ship\n> ");
                break;
        }
    }

    static void invalidInput() {
        switch (lang) {
            case Language::TR: std::cout << "Geçersiz giriş. Lütfen tekrar deneyin.\n"; break;
            case Language::EN:
            default: std::cout << "Invalid input. Please try again.\n"; break;
        }
    }

    static void asteroidEscape() {
        switch (lang) {
            case Language::TR: std::cout << "Asteroit kuşağından kaçmayı başardın!\n"; break;
            case Language::EN:
            default: std::cout << "You escaped the asteroid belt!\n"; break;
        }
    }

    static void asteroidDamage(int damage) {
        switch (lang) {
            case Language::TR: std::cout << "Asteroitlerden hasar aldın! Hasar: " << damage << "\n"; break;
            case Language::EN:
            default: std::cout << "You took damage from asteroids! Damage: " << damage << "\n"; break;
        }
    }

    static void pirateIncoming() {
        switch (lang) {
            case Language::TR:
                std::cout << "*************************\nUzay Korsanları geliyor!\n*************************\n";
                break;
            case Language::EN:
            default:
                std::cout << "*************************\nSpace Pirates are coming!\n*************************\n";
                break;
        }
    }

    static void abandonedPlanetFoundCoins(int coins) {
        switch (lang) {
            case Language::TR: std::cout << "Terkedilmiş gezegende " << coins << " altın buldun!\n"; break;
            case Language::EN:
            default: std::cout << "You found " << coins << " coins on the abandoned planet!\n"; break;
        }
    }

    static void abandonedPlanetPirates() {
        switch (lang) {
            case Language::TR: std::cout << "Terkedilmiş gezegende pusu! Uzay korsanları geldi!\n"; break;
            case Language::EN:
            default: std::cout << "Ambush on the abandoned planet! Space pirates incoming!\n"; break;
        }
    }

    static void selectAction() {
        switch (lang) {
            case Language::TR: std::cout << "Kaç (k), Savaş (s), Pazarlık (p)?\n> "; break;
            case Language::EN:
            default: std::cout << "Run (r), Fight (f), Negotiate (n)?\n> "; break;
        }
    }

    static void escapedPirates() {
        switch (lang) {
            case Language::TR: std::cout << "Kaçtın ama yakıt kaybettin.\n"; break;
            case Language::EN:
            default: std::cout << "You escaped but lost fuel.\n"; break;
        }
    }

    static void failedEscape() {
        switch (lang) {
            case Language::TR: std::cout << "Kaçamadın! Yakıt kaybettin.\n"; break;
            case Language::EN:
            default: std::cout << "You couldn't escape! Fuel lost.\n"; break;
        }
    }

    static void negotiationSuccess(int cost, int newBalance) {
        switch (lang) {
            case Language::TR: std::cout << cost << " altın verdin. Yeni bakiyen: " << newBalance << "\n"; break;
            case Language::EN:
            default: std::cout << "You paid " << cost << " coins. New balance: " << newBalance << "\n"; break;
        }
    }

    static void negotiationFail() {
        switch (lang) {
            case Language::TR: std::cout << "Yeterli paran yok! Korsanlar öfkelendi!\n"; break;
            case Language::EN:
            default: std::cout << "Not enough money! Pirates are angry!\n"; break;
        }
    }

    static void fightSuccess() {
        switch (lang) {
            case Language::TR: std::cout << "Tebrikler! Savaşı kazandın!\n"; break;
            case Language::EN:
            default: std::cout << "Congratulations! You won the fight!\n"; break;
        }
    }

    static void fightFail(int damage, int remainingHealth) {
        switch (lang) {
            case Language::TR: std::cout << "Savaşı kaybettin! " << damage << " hasar aldın. Kalan can: " << remainingHealth << "\n"; break;
            case Language::EN:
            default: std::cout << "You lost the fight! Took " << damage << " damage. Remaining health: " << remainingHealth << "\n"; break;
        }
    }

    static void fightBlocked() {
        switch (lang) {
            case Language::TR: std::cout << "Geminin daha fazla hasar alacak durumu yok!\n"; break;
            case Language::EN:
            default: std::cout << "Your ship can't take any more damage!\n"; break;
        }
    }

    static void pirateFuelStatus(int fuel) {
        switch (lang) {
            case Language::TR: std::cout << "Kalan yakıt: " << fuel << "\n"; break;
            case Language::EN:
            default: std::cout << "Fuel left: " << fuel << "\n"; break;
        }
    }

    static void pirateLowFuelWarning() {
        switch (lang) {
            case Language::TR: std::cout << "Yalnızca savaş ya da pazarlık yapabilirsin. Akıllıca seç!\n"; break;
            case Language::EN:
            default: std::cout << "You only have enough fuel to fight or negotiate. Choose wisely!\n"; break;
        }
    }

    static void abandonedPlanetDiscovered() {
        switch (lang) {
            case Language::TR: std::cout << "Terkedilmiş bir gezegen keşfettin!\n"; break;
            case Language::EN:
            default: std::cout << "You discovered an abandoned planet!\n"; break;
        }
    }

    static void asteroidFieldDetected() {
        switch (lang) {
            case Language::TR: std::cout << "Asteroit alanı tespit edildi!\n"; break;
            case Language::EN:
            default: std::cout << "Asteroid field detected!\n"; break;
        }
    }
    static void askToSave() {
        switch (lang) {
            case Language::TR: std::cout << "\nOyunu kaydetmek istiyor musun? (e/h): "; break;
            case Language::EN:
            default: std::cout << "\nWould you like to save your game before exiting? (y/n): "; break;
        }
    }

    static void displayTop5Header() {
        switch (lang) {
            case Language::TR: std::cout << "\n=== EN \u0130Y\u0130 5 SKOR ===\n"; break;
            case Language::EN:
            default: std::cout << "\n=== TOP 5 SCORES ===\n"; break;
        }
    }
     static void scoreSaved() {
        switch (lang) {
            case Language::TR: std::cout << "Skorunuz 'scores.txt' dosyas\u0131na kaydedildi.\n"; break;
            case Language::EN:
            default: std::cout << "Score saved to scores.txt\n"; break;
        }
    }
    static void printWelcomeMenu() {
        switch (lang) {
            case Language::TR:
                slowPrint("Uzay Oyununa Hoşgeldin!\n(1) Yeni Oyun\n(2) Kayıtlı Oyunu Yükle\n> ");
                break;
            case Language::EN:
            default:
                slowPrint("Welcome to the Space Game!\n(1) Start New Game\n(2) Load Saved Game\n> ");
                break;
        }
    }
    static void gameSaved() {
        switch (lang) {
            case Language::TR: std::cout << "Oyun 'save.txt' dosyasına kaydedildi!\n"; break;
            case Language::EN:
            default: std::cout << "Game saved to save.txt!\n"; break;
        }
    }

    static void gameSaveFailed() {
        switch (lang) {
            case Language::TR: std::cout << "Oyun kaydedilemedi.\n"; break;
            case Language::EN:
            default: std::cout << "Failed to save the game.\n"; break;
        }
    }

    static void gameLoaded() {
        switch (lang) {
            case Language::TR: std::cout << "Oyun 'save.txt' dosyasından yüklendi!\n"; break;
            case Language::EN:
            default: std::cout << "Game loaded from save.txt!\n"; break;
        }
    }

    static void loadFailed() {
        switch (lang) {
            case Language::TR: std::cout << "Kayıtlı oyun bulunamadı ya da dosya bozuk.\n"; break;
            case Language::EN:
            default: std::cout << "No saved game found or file corrupted.\n"; break;
        }
    }

};