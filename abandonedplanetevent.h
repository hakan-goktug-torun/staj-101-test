//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_ABANDONEDPLANETEVENT_H
#define SPACEGAMES_ABANDONEDPLANETEVENT_H

#pragma once
#include <memory>
#include "events.h"

class abandonedPlanetEvent : public Events {
public:
    void crossTheBelt(std::shared_ptr<Ship> ship) override;
    void abandonedPlanet(std::shared_ptr<Ship> ship) override ;
    void spacePirates(std::shared_ptr<Ship> ship) override;
};


#endif //SPACEGAMES_ABANDONEDPLANETEVENT_H
