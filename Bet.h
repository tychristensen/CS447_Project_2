//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_BET_H
#define PROJECT_2_BET_H


class Bet {
private:
    int amount;
    int player;
public:
    Bet(int amount, int player);
    int getPlayer();
    int getAmount();
};


#endif //PROJECT_2_BET_H
