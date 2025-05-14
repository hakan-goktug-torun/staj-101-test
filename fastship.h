//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_FASTSHIP_H
#define SPACEGAMES_FASTSHIP_H

#pragma once
#include "ship.h"

class fastShip : public Ship {
public:
    fastShip(int _fuel, int _health, int _balance) : Ship(_fuel, _health, _balance) {}

    int getPercEscape() const override { return 75; }
    int getAsDamage() const override { return 15; }
    int getDamage() const override { return 45; }
};
#endif //SPACEGAMES_FASTSHIP_H
