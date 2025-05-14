//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_CROSSTHEBELTEVENT_H
#define SPACEGAMES_CROSSTHEBELTEVENT_H

#pragma once
#include <memory>
#include "events.h"

class crossTheBeltEvent : public Events {
public:
    void crossTheBelt(std::shared_ptr<Ship> ship) override ;
    void abandonedPlanet(std::shared_ptr<Ship> ship) override;
    void spacePirates(std::shared_ptr<Ship> ship) override ;
};
#endif //SPACEGAMES_CROSSTHEBELTEVENT_H
