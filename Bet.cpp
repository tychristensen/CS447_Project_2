//
// Created by tysth on 4/1/2019.
//

#include "Bet.h"

Bet::Bet(int amount, int player) {
    this->amount = amount;
    this->player = player;
}

int Bet::getPlayer() {
    return player;
}

int Bet::getAmount() {
    return amount;
}
