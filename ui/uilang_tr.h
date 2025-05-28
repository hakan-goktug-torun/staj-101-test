#pragma once
#include "uilanguage.h"
#include <iostream>

class UILangTR : public IUILanguage {
public:
    void promptName() override {
        std::cout << "Lütfen ismini gir: ";
    }

    void printThanks() override {
        std::cout << "Oynadığın için teşekkürler!\n";
    }

    void displayTop5Header() override {
        std::cout << "\n=== EN İYİ 5 SKOR ===\n";
    }

    void printCongratulations(int score) override {
        std::cout << "Skorun: " << score << "\n";
        std::cout << "Tebrikler!\n";
    }

    void chooseShipPrompt() override {
        std::cout << "Gemi tipini seç:\n  (g) Güçlü Gemi\n  (h) Hızlı Gemi\n  (n) Normal Gemi\n> ";
    }

    void invalidInput() override {
        std::cout << "Geçersiz giriş. Lütfen tekrar deneyin.\n";
    }

    void printStatus(const std::shared_ptr<Ship>& ship) override {
        std::cout << "\n=== Gemi Durumu ===\n";
        std::cout << "Yakıt:    " << ship->getFuel() << "\n";
        std::cout << "Can:      " << ship->getHealth() << "\n";
        std::cout << "Bakiye:   " << ship->getBalance() << "\n";
        std::cout << "===================\n";
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
        std::cout << "Oyun 'save.txt' dosyasından yüklendi!\n";
    }

    void loadFailed() override {
        std::cout << "Kayıtlı oyun bulunamadı ya da dosya bozuk.\n";
    }

    void askToSave() override {
        std::cout << "\nOyunu kaydetmek istiyor musun? (e/h): ";
    }

    void asteroidFieldDetected() override {
        std::cout << "Asteroit alanı tespit edildi!\n";
    }

    void asteroidEscape() override {
        std::cout << "Asteroit kuşağından kaçmayı başardın!\n";
    }

    void asteroidDamage(int damage) override {
        std::cout << "Asteroitlerden hasar aldın! Hasar: " << damage << "\n";
    }

    void outOfFuel() override {
        std::cout << "Gemin yakıtsız kaldı!\n";
    }

    void pirateIncoming() override {
        std::cout << "*************************\nUzay Korsanları geliyor!\n*************************\n";
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
        std::cout << cost << " altın verdin. Yeni bakiyen: " << newBalance << "\n";
    }

    void negotiationFail() override {
        std::cout << "Yeterli paran yok! Korsanlar öfkelendi!\n";
    }

    void fightSuccess() override {
        std::cout << "Tebrikler! Savaşı kazandın!\n";
    }

    void fightFail(int damage, int remainingHealth) override {
        std::cout << "Savaşı kaybettin! " << damage << " hasar aldın. Kalan can: " << remainingHealth << "\n";
    }

    void fightBlocked() override {
        std::cout << "Geminin daha fazla hasar alacak durumu yok!\n";
    }

    void pirateFuelStatus(int fuel) override {
        std::cout << "Kalan yakıt: " << fuel << "\n";
    }

    void pirateLowFuelWarning() override {
        std::cout << "Yalnızca savaş ya da pazarlık yapabilirsin. Akıllıca seç!\n";
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
        std::cout << "Uzay Oyununa Hoşgeldin!\n(1) Yeni Oyun\n(2) Kayıtlı Oyunu Yükle\n> ";
    }
};
