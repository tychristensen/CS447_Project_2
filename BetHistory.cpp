//
// Created by tysth on 4/1/2019.
//

#include "BetHistory.h"

void BetHistory::clearHistory() {
    betHistory.clear();
}

void BetHistory::addBet(Bet bet) {
    this->betHistory.push_back(bet);
}

int BetHistory::getCount() {
    return betHistory.size();
}

Bet BetHistory::getBet(int n) {
    return betHistory[n];
}
