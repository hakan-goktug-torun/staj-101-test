//
// Created by ChatCPP on 02.03.2024
//

#ifndef SPACEGAMES_CROSSTHEBELTEVENT_H
#define SPACEGAMES_CROSSTHEBELTEVENT_H

#include <memory>
#include "events.h"

class crossTheBeltEvent : public Events {
public:
    void manageEvents(std::shared_ptr<Ship> ship) override;
};

#endif // SPACEGAMES_CROSSTHEBELTEVENT_H

