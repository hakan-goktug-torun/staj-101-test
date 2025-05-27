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
    void manageEvents(std::shared_ptr<Ship> ship) override;

private:
    static const int kCoinReward = 10;
    // Bu sabit yalnızca bu sınıfla ilgili olduğu için class içine aldım. Const ile sabitledim ve static ile işaret ettim.
};

#endif // SPACEGAMES_ABANDONEDPLANETEVENT_H


