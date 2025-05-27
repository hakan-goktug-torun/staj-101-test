//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_EVENTS_H
#define SPACEGAMES_EVENTS_H

#pragma once
#include <memory>
#include <iostream>
#include "../ships/ship.h"

class Events {
public:
    virtual void manageEvents(std::shared_ptr<Ship> ship) = 0; // bir tane method olsun birden fazla eventin override olmasına gerek yok
    virtual ~Events() = default;
};

#endif // SPACEGAMES_EVENTS_H