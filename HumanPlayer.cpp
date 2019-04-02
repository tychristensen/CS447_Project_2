//
// Created by tysth on 4/1/2019.
//

#include "HumanPlayer.h"

int HumanPlayer::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int pot) {
    return Player::getBet(opponent, bh, bet2Player, canRaise, pot);
}
