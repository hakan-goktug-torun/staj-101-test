//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_SPACEPIRATESEVENT_H
#define SPACEGAMES_SPACEPIRATESEVENT_H

#pragma once
#include <memory>
#include "events.h"

class spacePiratesEvent : public Events {
public:
    void spacePirates(std::shared_ptr<Ship> ship) override;
    void crossTheBelt(std::shared_ptr<Ship> ship) override;
    void abandonedPlanet(std::shared_ptr<Ship> ship) override;
    static void consumptionFuel(const std::shared_ptr<Ship>& ship);
};




#endif //SPACEGAMES_SPACEPIRATESEVENT_H
