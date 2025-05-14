///
// Created by ChatCPP on 02.03.2024
//

#include "spacepiratesevent.h"

void spacePiratesEvent::consumptionFuel(const std::shared_ptr<Ship>& ship) {
    int newFuel{ 0 };
    const int usedFuel{ 33 };
    newFuel = ship->getFuel() - usedFuel;
    ship->setFuel(newFuel);
}

void spacePiratesEvent::spacePirates(std::shared_ptr<Ship> ship) {
    std::string decision;
    std::string decRun{ "run" };
    std::string decFight{ "fight" };
    std::string decNego{ "negotiate" };
    spacePiratesEvent event;
    int overRun{0};
    std::cout << "***********************\n";
    std::cout << "Space Pirates are coming!\n";
    do {
        if ((ship->getFuel() > 1) || (overRun != 0)) {
            std::cout << "Run, fight, negotiate ? \n";
            std::cin >> decision;
            int random{ 0 };
            const int maks{ 100 };
            const int min{ 0 };
            try {
                if ((decision == decRun) && (overRun == 0)) {



                    random = rand() % (maks - min + 1) + min;
                    if (ship->getPercEscape() >= random) {
                        std::cout << "You've escaped but ship's fuel is decreased!\n";
                        consumptionFuel(ship);
                        std::cout << "Ship's fuel: " << ship->getFuel() << "\n";
                        break;
                    }
                    else {
                        std::cout << "You couldn't escape!\n";
                        consumptionFuel(ship);
                        std::cout << "Ship's fuel: " << ship->getFuel() << "\n";
                    }
                }
                else if (decision == decFight) {
                    int probFight{ 50 };
                    random = rand() % (maks - min + 1) + min;
                    try {
                        if (ship->getHealth() >= ship->getDamage()) {
                            if (random < probFight) {
                                std::cout << "You lost the fight! Your ship took damage!\n";
                                ship->takenDamage(2);
                                std::cout << "Ship's health: " << ship->getHealth() << "\n";
                                break;
                            }
                            else {
                                std::cout << "Congratulations! You win the fight!\n";
                                break;
                            }
                        }
                        else
                            throw 108;
                    }
                    catch (...) {
                        std::cout << "Your ship can't take any more damage! Please choose another status!\n";
                        event.spacePirates(ship);
                    }

                }
                else if (decision == decNego) {
                    std::cout << "You chose to bargain and after much negotiation the pirates agreed to release you in exchange for money!\n";
                    random = rand() % (3) + 1;
                    if (random == 1) {
                        const int coins{ 10 };
                        int balance{ 0 };
                        try {

                            balance = ship->getBalance() - coins;
                            if (ship->getBalance() >= coins) {
                                ship->setBalance(balance);
                                std::cout << "They got 10 coins from you! Your new balance: " << ship->getBalance() << "\n";
                                break;
                            }
                            else if (ship->getBalance() < coins) {
                                throw 101;
                            }
                        }
                        catch (int errorNo) {
                            if (errorNo == 101) {
                                std::cout << "You don't have enough money! You can try negotiate again but pirates seems angry!\n";
                            }
                        }
                    }
                    else if (random == 2) {
                        const int coins{ 20 };
                        int balance{ 0 };
                        try {
                            balance = ship->getBalance() - coins;
                            if (ship->getBalance() >= coins) {
                                ship->setBalance(balance);
                                std::cout << "They got 20 coins from you! Your new balance: " << ship->getBalance() << "\n";
                                break;
                            }
                            else if (ship->getBalance() < coins) {
                                throw 101;
                            }
                        }
                        catch (int errorNo) {
                            if (errorNo == 101) {
                                std::cout << "You don't have enough money! You can try negotiate again but pirates seems angry!\n";
                                event.spacePirates(ship);
                            }
                        }
                    }
                    else if (random == 3) {
                        const int coins{ 30 };
                        int balance{ 0 };
                        try {
                            balance = ship->getBalance() - coins;
                            if (ship->getBalance() >= coins) {
                                ship->setBalance(balance);
                                std::cout << "They got 30 coins from you! Your new balance: " << ship->getBalance() << "\n";
                                break;
                            }
                            else if (ship->getBalance() < coins) {
                                throw 101;
                            }
                        }
                        catch (int errorNo) {
                            if (errorNo == 101) {
                                std::cout << "You don't have enough money! You can try negotiate again but pirates seems angry!\n";
                                event.spacePirates(ship);
                            }
                        }
                    }
                }
                else
                    throw 100;
            }
            catch (int errorNo) {
                if (errorNo == 100) {
                    std::cout << "Wrong decision!\n";
                }
            }
        }
        else{
            std::cout << "You only have enough fuel to fight or negotiate. Choose wisely!\n";
            overRun++;
            continue;
        }
    } while ((decision == decRun) || ((decision != decRun) || (decision != decNego) || (decision != decFight)));
}

void spacePiratesEvent::abandonedPlanet(std::shared_ptr<Ship> ship) {}
void spacePiratesEvent::crossTheBelt(std::shared_ptr<Ship> ship) {}
