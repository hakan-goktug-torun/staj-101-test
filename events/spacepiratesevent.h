#ifndef SPACEGAMES_SPACEPIRATESEVENT_H
#define SPACEGAMES_SPACEPIRATESEVENT_H

#pragma once
#include <memory>
#include "events.h"
#include <string>

class spacePiratesEvent : public Events {
public:
    void manageEvents(std::shared_ptr<Ship> ship) override; 
private:
    enum class Action { Run, Fight, Negotiate, Invalid };

    void spacePirates(const std::shared_ptr<Ship>& ship);
    void consumptionFuel(const std::shared_ptr<Ship>& ship);
    bool handleRun(const std::shared_ptr<Ship>& ship);
    bool handleFight(const std::shared_ptr<Ship>& ship);
    bool handleNegotiate(const std::shared_ptr<Ship>& ship);
    Action parseActionInput(const std::string& input);
};

#endif // SPACEGAMES_SPACEPIRATESEVENT_H