//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_SHIPGENERATOR_H
#define SPACEGAMES_SHIPGENERATOR_H

#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "ship.h"
#include "fastship.h"
#include "strongship.h"
#include "normalship.h"
#include "events.h"
#include "spacepiratesevent.h"
#include "abandonedplanetevent.h"
#include "crossthebeltevent.h"

class shipGenerator {
public:
    static void playGame(const std::shared_ptr<Ship>& ship);
    static void addNewShip();
protected:
    static bool createShip(const std::string& shipType);
    static void executeEvent(int eventChoice, const std::shared_ptr<Ship>& ship, spacePiratesEvent& eventSpace, crossTheBeltEvent& beltEvent, abandonedPlanetEvent& planetEvent);
    static int calculateScore(const std::shared_ptr<Ship>& ship);
    static inline void displayScore(int score);
};

#endif //SPACEGAME_SHIPGENERATOR_H
