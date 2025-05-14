//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_SHIP_H
#define SPACEGAMES_SHIP_H

#pragma once
#include <iostream>

class Ship {
protected:
    int percEscape{};
    int fuel{};
    int health{};
    int balance{};

public:
    Ship(int _fuel, int _health, int _balance) : fuel{ _fuel }, health{ _health }, balance{ _balance } {}

    virtual int getAsDamage() const = 0;
    virtual int getPercEscape() const = 0;
    virtual int getDamage() const = 0;

    int getFuel() const { return fuel; }
    int getHealth() const { return health; }
    int getBalance() const { return balance; }

    void setFuel(int _fuel) { fuel = _fuel; }
    void setHealth(int _health) { health = _health; }
    void setBalance(int _balance) { balance = _balance; }

    void takenDamage(int eventNum);
    void possEscape(int eventNum);

    virtual ~Ship() = default;
};

#endif //SPACEGAMES_SHIP_H
