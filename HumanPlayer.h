//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_HUMANPLAYER_H
#define PROJECT_2_HUMANPLAYER_H

#include "Player.h"
#include <iostream>

class HumanPlayer : public Player{
public:
    HumanPlayer(int id, int chips) : Player(id, chips) {};
    int getBet( Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot ) override;
};


#endif //PROJECT_2_HUMANPLAYER_H
