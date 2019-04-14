//
// Created by tysth on 4/1/2019.
//

#include "AlphaPlayer.h"

int AlphaPlayer::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int &pot) {

    int handValue = hand.evaluate();
    int oppValue = opponent.evaluate();
    int delta = handValue - oppValue;
    int bet;

    if(hand.getCount() < 5) {
        if(bh.getCount() == 0) {
            if(delta > 10) {
                bet = 10 + bet2Player;
            } else if(delta > 5) {
                bet = 5 + bet2Player;
            } else if(delta > 0) {
                bet = 1 + bet2Player;
            } else {
                bet = bet2Player;
            }
        } else {
            int potFactor = pot / 10;
            if(bet2Player == 0) {
                if(handValue - oppValue > 5 - potFactor) {
                    bet = 10 + bet2Player;
                } else if(handValue - oppValue > 0 - potFactor) {
                    bet = 1 + bet2Player;
                } else {
                    bet = bet2Player;
                }
            } else if(bet2Player > 0 && bet2Player < 1 + potFactor * 2) {
                if(delta > 8 - potFactor) {
                    bet = 10 + bet2Player;
                } else if(delta > -2 * potFactor) {
                    bet = 1 + bet2Player;
                } else if(delta > -4 * potFactor) {
                    bet = bet2Player;
                } else {
                    bet = 0;
                }
            } else {
                if(delta > 10 - potFactor) {
                    bet = 10 + bet2Player;
                } else if(delta > 0 - potFactor) {
                    bet = 1 + bet2Player;
                } else if(delta > -2 - potFactor) {
                    bet = bet2Player;
                } else {
                    bet = 0;
                }
            }
        }
    } else {
        if(bh.getCount() == 0) {
            if(delta > 10) {
                bet = 10 + bet2Player;
            } else if(delta > 5) {
                bet = 5 + bet2Player;
            } else {
                bet = bet2Player;
            }
        } else {
            int potFactor = pot / 10;
            if(bet2Player == 0) {
                if(delta > 10 - potFactor) {
                    bet =  10 + bet2Player;
                } else {
                    bet = bet2Player;
                }
            } else if(bet2Player > 0 && bet2Player < 1 + potFactor * 2) {
                if(delta > 6 - potFactor) {
                    bet = 10 + bet2Player;
                } else if(delta > 2) {
                    bet = bet2Player;
                } else {
                    bet = 0;
                }
            } else {
                if(delta > 8 - potFactor) {
                    bet = 10 + bet2Player;
                } else if(delta > 4) {
                    bet = bet2Player;
                } else {
                    bet = 0;
                }
            }
        }
    }

    if(!canRaise && bet > bet2Player) {
        bet = bet2Player;
    }
    betHistory.addBet(Bet(bet, getID()));
    addChips(-1 * bet);
    pot += bet;
    return bet;
}
