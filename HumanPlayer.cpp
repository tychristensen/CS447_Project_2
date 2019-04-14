//
// Created by tysth on 4/1/2019.
//

#include "HumanPlayer.h"

int HumanPlayer::getBet(Hand opponent, BetHistory bh, int bet2Player, bool canRaise, int& pot) {

    cout << endl << "It's player " << getID() << "'s turn" << endl;

    cout << endl << "Your hand contains: ";
    for(int i = 0; i < getHand().getCount(); i++) {
        if(i != 0 && i != getHand().getCount()) {
            cout << ", ";
        }
        cout << hand.getCard(i).getName();
    }

    cout << endl << "Your hidden card is a " << hand.getCard(0).getName() << endl;

    cout << "Your opponent's visible hand contains: ";
    for(int i = 0; i < opponent.getCount(); i++) {
        if(i != 0 && i != opponent.getCount()) {
            cout << ", ";
        }
        cout << opponent.getVisible().getCard(i).getName();
    }
    cout << endl;

    cout << "The pot is " << pot << endl;
    cout << "You have " << getChips() << " chips" << endl;

    cout << "Your opponent bet " << bet2Player << endl;
    int bet;
    if(bet2Player == 0) {
        if(canRaise) {
            cout << "Enter 0 to check or 1 through 10 to raise: ";
            cin >> bet;
        } else {
            cout << "You cannot raise this round" << endl;
        }
    } else {
        int option;
        if(canRaise) {
            cout << "Enter 0 to fold, 1 to call, or 2 to raise: ";
            cin >> option;
            switch (option) {
                case 0:
                    bet = 0;
                    break;
                case 1:
                    bet = bet2Player;
                    break;
                case 2:
                    cout << "Enter an amount from 1 to 10 to raise: ";
                    cin >> bet;
                    bet += bet2Player;
                    break;
            }
        } else {
            cout << "You cannot raise this round" << endl;
            cout << "Enter 0 to fold or 1 to call: ";
            cin >> option;
            switch (option) {
                case 0:
                    bet = 0;
                    break;
                case 1:
                    bet = bet2Player;
                    break;
            }
        }
    }

    pot += bet;
    addChips(-1 * bet);
    betHistory.addBet(Bet(bet, getID()));


    return bet;
}
