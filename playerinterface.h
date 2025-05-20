#ifndef SPACEGAMES_PLAYERINTERFACE_H
#define SPACEGAMES_PLAYERINTERFACE_H

#include <memory>
#include "ship.h"

class PlayerInterface {
public:
    static std::shared_ptr<Ship> selectShip();                   // Gemi seçimi ekranı
    static void askAndSaveScore(const std::shared_ptr<Ship>&);   // Kullanıcı adı alır ve skoru kaydeder
};

#endif // SPACEGAMES_PLAYERINTERFACE_H

