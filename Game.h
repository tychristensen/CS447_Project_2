//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_GAME_H
#define PROJECT_2_GAME_H

#include "Player.h"

class Game {
private:
    Player::PlayerType p0, p1;
    int chips0, chips1;
    bool reportFlag;
public:
    bool playGame(Player::PlayerType p0, Player::PlayerType p1, int& chips0, int& chips1, bool reportFlag);
};


#endif //PROJECT_2_GAME_H
