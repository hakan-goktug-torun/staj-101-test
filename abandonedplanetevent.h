//
// Created by ChatCPP on 02.03.2024
//
#ifndef SPACEGAMES_ABANDONEDPLANETEVENT_H
#define SPACEGAMES_ABANDONEDPLANETEVENT_H

#include <memory>
#include "events.h"

class abandonedPlanetEvent : public Events {
public:
    void manageEvents(std::shared_ptr<Ship> ship) override;
};

#endif // SPACEGAMES_ABANDONEDPLANETEVENT_H



