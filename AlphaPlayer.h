//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_ALPHAPLAYER_H
#define PROJECT_2_ALPHAPLAYER_H


#include "Player.h"

class AlphaPlayer : public Player {
public:
    AlphaPlayer(int id, int chips) : Player(id, chips) {};
    int getBet( Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot ) override;
};


#endif //PROJECT_2_ALPHAPLAYER_H
