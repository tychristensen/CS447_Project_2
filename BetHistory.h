//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_BETHISTORY_H
#define PROJECT_2_BETHISTORY_H


#include "Bet.h"
#include <vector>

class BetHistory {
private:
    std::vector<Bet> betHistory;
public:
    void clearHistory();
    void addBet(Bet bet);
    int getCount();
    Bet getBet(int n);
};


#endif //PROJECT_2_BETHISTORY_H
