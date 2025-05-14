//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_STRONGSHIP_H
#define SPACEGAMES_STRONGSHIP_H

#pragma once
#include "ship.h"

class strongShip : public Ship {
public:
    strongShip(int _fuel, int _health, int _balance) : Ship(_fuel, _health, _balance) {}

    int getPercEscape() const override { return 25; }
    int getAsDamage() const override { return 5; }
    int getDamage() const override { return 15; }
};

#endif //SPACEGAMES_STRONGSHIP_H
