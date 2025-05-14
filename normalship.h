//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_NORMALSHIP_H
#define SPACEGAMES_NORMALSHIP_H

#pragma once
#include "ship.h"

class normalShip : public Ship {
public:
    normalShip(int _fuel, int _health, int _balance) : Ship(_fuel, _health, _balance) {}

    int getPercEscape() const override { return 50; }
    int getAsDamage() const override { return 10; }
    int getDamage() const override { return 30; }
};
#endif //SPACEGAMES_NORMALSHIP_H
