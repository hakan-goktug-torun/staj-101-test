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
    void manageEvents(std::shared_ptr<Ship> ship) override; 
private:
    void spacePirates(const std::shared_ptr<Ship>& ship);
    void consumptionFuel(const std::shared_ptr<Ship>& ship);
    bool handleRun(const std::shared_ptr<Ship>& ship);
    bool handleFight(const std::shared_ptr<Ship>& ship);
    bool handleNegotiate(const std::shared_ptr<Ship>& ship);
};

#endif // SPACEGAMES_SPACEPIRATESEVENT_H




