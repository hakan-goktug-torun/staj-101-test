#pragma once
#include <iostream>
#include <memory>
#include "../ships/ship.h"

namespace UI_TR {

inline void promptName() {
    std::cout << "Lütfen ismini gir: ";
}

inline void printThanks() {
    std::cout << "Oynadığın için teşekkürler!\n";
}

inline void displayTop5Header() {
    std::cout << "\n=== EN İYİ 5 SKOR ===\n";
}

inline void printCongratulations(int score) {
    std::cout << "Skorun: " << score << "\n";
    std::cout << "Tebrikler!\n";
}

inline void chooseShipPrompt() {
    std::cout << "Gemi tipini seç:\n  (g) Güçlü Gemi\n  (h) Hızlı Gemi\n  (n) Normal Gemi\n> ";
}

inline void invalidInput() {
    std::cout << "Geçersiz giriş. Lütfen tekrar deneyin.\n";
}

inline void printStatus(const std::shared_ptr<Ship>& ship) {
    std::cout << "\n=== Gemi Durumu ===\n";
    std::cout << "Yakıt:    " << ship->getFuel() << "\n";
    std::cout << "Can:      " << ship->getHealth() << "\n";
    std::cout << "Bakiye:   " << ship->getBalance() << "\n";
    std::cout << "===================\n";
}

inline void promptContinue() {
    std::cout << "Devam etmek istiyor musun? (E/H): ";
}

inline void scoreSaved() {
    std::cout << "Skorunuz 'scores.txt' dosyasına kaydedildi.\n";
}

inline void gameSaved() {
    std::cout << "Oyun 'save.json' dosyasına kaydedildi!\n";
}

inline void gameSaveFailed() {
    std::cout << "Oyun kaydedilemedi.\n";
}

inline void gameLoaded() {
    std::cout << "Oyun 'save.txt' dosyasından yüklendi!\n";
}

inline void loadFailed() {
    std::cout << "Kayıtlı oyun bulunamadı ya da dosya bozuk.\n";
}

inline void askToSave() {
    std::cout << "\nOyunu kaydetmek istiyor musun? (e/h): ";
}

inline void asteroidFieldDetected() {
    std::cout << "Asteroit alanı tespit edildi!\n";
}

inline void asteroidEscape() {
    std::cout << "Asteroit kuşağından kaçmayı başardın!\n";
}

inline void asteroidDamage(int damage) {
    std::cout << "Asteroitlerden hasar aldın! Hasar: " << damage << "\n";
}

inline void outOfFuel() {
    std::cout << "Gemin yakıtsız kaldı!\n";
}

inline void pirateIncoming() {
    std::cout << "*************************\nUzay Korsanları geliyor!\n*************************\n";
}

inline void selectAction() {
    std::cout << "Kaç (k), Savaş (s), Pazarlık (p)?\n> ";
}

inline void escapedPirates() {
    std::cout << "Kaçtın ama yakıt kaybettin.\n";
}

inline void failedEscape() {
    std::cout << "Kaçamadın! Yakıt kaybettin.\n";
}

inline void negotiationSuccess(int cost, int newBalance) {
    std::cout << cost << " altın verdin. Yeni bakiyen: " << newBalance << "\n";
}

inline void negotiationFail() {
    std::cout << "Yeterli paran yok! Korsanlar öfkelendi!\n";
}

inline void fightSuccess() {
    std::cout << "Tebrikler! Savaşı kazandın!\n";
}

inline void fightFail(int damage, int remainingHealth) {
    std::cout << "Savaşı kaybettin! " << damage << " hasar aldın. Kalan can: " << remainingHealth << "\n";
}

inline void fightBlocked() {
    std::cout << "Geminin daha fazla hasar alacak durumu yok!\n";
}

inline void pirateFuelStatus(int fuel) {
    std::cout << "Kalan yakıt: " << fuel << "\n";
}

inline void pirateLowFuelWarning() {
    std::cout << "Yalnızca savaş ya da pazarlık yapabilirsin. Akıllıca seç!\n";
}

inline void abandonedPlanetDiscovered() {
    std::cout << "Terkedilmiş bir gezegen keşfettin!\n";
}

inline void abandonedPlanetFoundCoins(int coins) {
    std::cout << "Terkedilmiş gezegende " << coins << " altın buldun!\n";
}

inline void abandonedPlanetPirates() {
    std::cout << "Terkedilmiş gezegende pusu! Uzay korsanları geldi!\n";
}

inline void printWelcomeMenu() {
    std::cout << "Uzay Oyununa Hoşgeldin!\n(1) Yeni Oyun\n(2) Kayıtlı Oyunu Yükle\n> ";
}
}