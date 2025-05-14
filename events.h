//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_EVENTS_H
#define SPACEGAMES_EVENTS_H

#pragma once
#include "ship.h"
#include <memory>

class Events {
public:
    virtual void crossTheBelt(std::shared_ptr<Ship> ship)=0;
    virtual void abandonedPlanet(std::shared_ptr<Ship> ship)=0;
    virtual void spacePirates(std::shared_ptr<Ship> ship)=0;
};

#endif //SPACEGAMES_EVENTS_H
