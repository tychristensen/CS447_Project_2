//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_PLAYER_H
#define PROJECT_2_PLAYER_H


#include "Hand.h"
#include "BetHistory.h"

class Player {
private:
    int id, chips;
    Hand hand;
    BetHistory betHistory;
public:
    enum PlayerType { HUMAN, ALPHA, BETA };
    Player(int id, int chips);
    virtual int getBet( Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot );
    int getID();
    void clearHand();
    void dealCard(Card c);
    Hand getHand();
    void addChips(int chips);
    int getChips();
};


#endif //PROJECT_2_PLAYER_H
