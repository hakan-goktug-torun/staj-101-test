#pragma once
#include "uilanguage.h"
#include <iostream>
#include "color.h"

class UILangTR : public IUILanguage {
public:
    void promptName() override {
        std::cout << "Lütfen ismini gir: ";
    }

    void printThanks() override {   
            std::cout << BOLD << GREEN
            << "\n╔════════════════════════════╗\n"
            << "║Oynadığın için teşekkürler!  ║\n"
            << "╚════════════════════════════╝\n"
            << RESET;
    }

    void displayTop5Header() override {
        std::cout << BOLD << CYAN << "\n=== EN İYİ 5 SKOR ===\n" << RESET;
    }

    void printCongratulations(int score) override {
        std::cout << "Skorun: " << score << "\n";
        std::cout << "Tebrikler!\n";
    }

    void chooseShipPrompt() override {
        std::cout << "Gemi tipini seç:\n  (g) Güçlü Gemi\n  (h) Hızlı Gemi\n  (n) Normal Gemi\n> ";
    }

    void invalidInput() override {
        std::cout << BOLD << RED << "Geçersiz giriş. Lütfen tekrar deneyin.\n" << RESET;
    }

    void printStatus(const std::shared_ptr<Ship>& ship) override {
    std::cout << BOLD << BLUE << "\n╔══════════════════════╗\n";
    std::cout << "║     GEMİ DURUMU      ║\n";
    std::cout << "╠══════════════════════╣\n" << RESET;

    std::cout << "  Yakıt:   " << GREEN << ship->getFuel() << RESET << "\n";

    std::cout << "  Can:     ";
    if (ship->getHealth() > 70)
        std::cout << GREEN;
    else if (ship->getHealth() > 30)
        std::cout << YELLOW;
    else
        std::cout << RED;
    std::cout << ship->getHealth() << RESET << "\n";

    std::cout << "  Bakiye:  " << CYAN << ship->getBalance() << RESET << "\n";
    std::cout << BOLD << BLUE << "╚══════════════════════╝" << RESET << "\n";
    }


    void promptContinue() override {
        std::cout << "Devam etmek istiyor musun? (E/H): ";
    }

    void scoreSaved() override {
        std::cout << "Skorunuz 'scores.txt' dosyasına kaydedildi.\n";
    }

    void gameSaved() override {
        std::cout << "Oyun 'save.json' dosyasına kaydedildi!\n";
    }

    void gameSaveFailed() override {
        std::cout << "Oyun kaydedilemedi.\n";
    }

    void gameLoaded() override {
        std::cout << "Oyun 'save.json' dosyasından yüklendi!\n";
    }

    void loadFailed() override {
        std::cout << "Kayıtlı oyun bulunamadı ya da dosya bozuk.\n";
    }

    void askToSave() override {
        std::cout << "\nOyunu kaydetmek istiyor musun? (e/h): ";
    }

    void asteroidFieldDetected() override {
        std::cout << BOLD << YELLOW << "Asteroit alanı tespit edildi!\n" << RESET;
    }

    void asteroidEscape() override {
        std::cout << "Asteroit kuşağından kaçmayı başardın!\n";
    }

    void asteroidDamage(int damage) override {
        std::cout << "Asteroitlerden hasar aldın! Hasar: " << damage << "\n";
    }

    void outOfFuel() override {
        std::cout << BOLD << RED << "Gemin yakıtsız kaldı! Hareket edemezsin.\n" << RESET;
    }

    void pirateIncoming() override {
        std::cout << BOLD << RED;
        std::cout << "\n*************************\n";
        std::cout << "  UZAY KORSANLARI GELİYOR!\n";
        std::cout << "*************************\n" << RESET;
    }

    void selectAction() override {
        std::cout << "Kaç (k), Savaş (s), Pazarlık (p)?\n> ";
    }

    void escapedPirates() override {
        std::cout << "Kaçtın ama yakıt kaybettin.\n";
    }

    void failedEscape() override {
        std::cout << "Kaçamadın! Yakıt kaybettin.\n";
    }

    void negotiationSuccess(int cost, int newBalance) override {
        std::cout << GREEN << cost << " altın verdin. Yeni bakiyen: " << newBalance << "\n" << RESET;
    }

    void negotiationFail() override {
        std::cout << RED << "Yeterli paran yok! Korsanlar öfkelendi!\n" << RESET;
    }

    void fightSuccess() override {
        std::cout << GREEN << BOLD << "Tebrikler! Savaşı kazandın!\n" << RESET;
    }

    void fightFail(int damage, int remainingHealth) override {
        std::cout << RED << "Savaşı kaybettin! " << damage << " hasar aldın. Kalan can: " << remainingHealth << "\n" << RESET;
    }

    void fightBlocked() override {
        std::cout << "Geminin daha fazla hasar alacak durumu yok!\n";
    }

    void pirateFuelStatus(int fuel) override {
        std::cout << "Kalan yakıt: " << fuel << "\n";
    }

    void pirateLowFuelWarning() override {
        std::cout << BOLD << YELLOW << "Yakıtın yetersiz! Sadece savaş ya da pazarlık yapabilirsin. Akıllıca seç!\n" << RESET;
    }

    void abandonedPlanetDiscovered() override {
        std::cout << "Terkedilmiş bir gezegen keşfettin!\n";
    }

    void abandonedPlanetFoundCoins(int coins) override {
        std::cout << "Terkedilmiş gezegende " << coins << " altın buldun!\n";
    }

    void abandonedPlanetPirates() override {
        std::cout << "Terkedilmiş gezegende pusu! Uzay korsanları geldi!\n";
    }

    void printWelcomeMenu() override {
        std::cout << BOLD << CYAN;
        std::cout << "╔════════════════════════════════════╗\n";
        std::cout << "║         UZAY MACERASINA HOŞGELDİN! ║\n";
        std::cout << "╠════════════════════════════════════╣\n";
        std::cout << "║ (1) Yeni Oyun                      ║\n";
        std::cout << "║ (2) Kayıtlı Oyunu Yükle            ║\n";
        std::cout << "╚════════════════════════════════════╝\n";
        std::cout << RESET << "> ";
    }

    void printEventDivider() override {
    std::cout << BOLD << BLUE << "\n――――  Yeni Uzay Anomalisi!  ――――\n" << RESET;
    }
};
