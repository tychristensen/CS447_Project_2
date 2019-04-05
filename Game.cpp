//
// Created by tysth on 4/1/2019.
//

#include "Game.h"

Game::Game() {}

bool Game::playGame(Player::PlayerType p0Type, Player::PlayerType p1Type, int &chips0, int &chips1, bool reportFlag) {

    int pot = 0;

    //if(p0Type == Player::HUMAN) {
        HumanPlayer p0(0, chips0);
    //}

    //if(p1Type == Player::HUMAN) {
        HumanPlayer p1(1, chips1);
    //}

    for(int i = 0; i < 20; i++) {
        shuffleDeck();

        //deal three cards
        for (int j = 0; j < 3; j++) {
            if(j != 2) {
                deck[0].setFaceup(true);
                deck[1].setFaceup(true);
            }
            p0.dealCard(deck[0]);
            p1.dealCard(deck[1]);
            deck.erase(deck.begin());
            deck.erase(deck.begin());
        }

        p0.addChips(-10);
        p1.addChips(-10);
        pot += 20;

        //First round of betting
        int p0Bet = 0;
        int p1Bet = 0;
        cout << endl << "Betting Round " << i + 1 << endl;
        int numRaises = 0;
        if(i % 2 == 0) {
            do {
                p0Bet = p0.getBet(p1.getHand().getVisible(), p1.getBetHistory(), p1Bet, numRaises < 3, pot);
                if(p0Bet > 0 && p1Bet != p0Bet)
                    numRaises++;
                p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), p0Bet, numRaises < 3, pot);
                if(p0Bet == 0) {
                    if(p1Bet == 0) {
                        cout << endl << "Both players call" << endl << endl;
                        break;
                    } else {
                        cout << endl << "p1 raises after p0 calls" << endl << endl;
                        p1.addChips(-1 * p1Bet);
                        pot += p1Bet;
                    }
                } else {
                    if(p1Bet == 0) {
                        cout << endl << "p1 folds" << endl << endl;
                        p0.addChips(pot + p0Bet);
                        break;
                    } else if(p1Bet == p0Bet) {
                        cout << endl << "p1 calls p0" << endl << endl;
                        pot += p0Bet + p1Bet;
                        p0.addChips(-1 * p0Bet);
                        p1.addChips(-1 * p1Bet);
                        break;
                    } else {
                        cout << endl << "p1 raised after p0 raised" << endl;
                        numRaises++;
                        p0.addChips(-1 * p0Bet);
                        p1.addChips(-1 * p1Bet);
                        pot += p0Bet + p1Bet;
                        p1Bet -= p0Bet;
                    }
                }
            } while(true);
        } /*else {
            p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), p0Bet, p0.getChips() != 0, pot);
            p0Bet = p0.getBet(p1.getHand().getVisible(), p0.getBetHistory(), p1Bet, p1.getChips() != 0, pot);
        }

        //Deal each player a card and go through another round of betting
        deck[0].setFaceup(true);
        deck[1].setFaceup(true);
        p0.dealCard(deck[0]);
        p1.dealCard(deck[1]);
        deck.erase(deck.begin());
        deck.erase(deck.begin());

        if(i % 2 == 1) {
            p0Bet = p0.getBet(p1.getHand().getVisible(), p1.getBetHistory(), 0, p1.getChips() != 0, pot);
            p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), p0Bet, p0.getChips() != 0, pot);
        } else {
            p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), 0, p0.getChips() != 0, pot);
            p0Bet = p0.getBet(p1.getHand().getVisible(), p0.getBetHistory(), p1Bet, p1.getChips() != 0, pot);
        }

        //Deal another card and go through final round of bidding
        deck[0].setFaceup(true);
        deck[1].setFaceup(true);
        p0.dealCard(deck[0]);
        p1.dealCard(deck[1]);
        deck.erase(deck.begin());
        deck.erase(deck.begin());

        if(i % 2 == 0) {
            p0Bet = p0.getBet(p1.getHand().getVisible(), p1.getBetHistory(), 0, p1.getChips() != 0, pot);
            p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), p0Bet, p0.getChips() != 0, pot);
        } else {
            p1Bet = p1.getBet(p0.getHand().getVisible(), p0.getBetHistory(), 0, p0.getChips() != 0, pot);
            p0Bet = p0.getBet(p1.getHand().getVisible(), p0.getBetHistory(), p1Bet, p1.getChips() != 0, pot);
        }*/

        if(p0Bet != 0 || p1Bet != 0)
            pot = 0;
        p0.clearHand();
        p1.clearHand();
    }

    return false;
}

void Game::fillDeck() {
    deck.clear();

    for(int i = 0; i < 4; i++) {
        deck.emplace_back(Card("Ace", 1));
        deck.emplace_back(Card("2", 2));
        deck.emplace_back(Card("3", 3));
        deck.emplace_back(Card("4", 4));
        deck.emplace_back(Card("5", 5));
        deck.emplace_back(Card("6", 6));
        deck.emplace_back(Card("7", 7));
        deck.emplace_back(Card("8", 8));
        deck.emplace_back(Card("9", 9));
        deck.emplace_back(Card("10", 10));
        deck.emplace_back(Card("Jack", 10));
        deck.emplace_back(Card("Queen", 10));
        deck.emplace_back(Card("King", 10));
    }
}

void Game::shuffleDeck() {
    fillDeck();
    auto rng = default_random_engine {};
    rng.seed(time(0));
    shuffle(deck.begin(), deck.end(), rng);
}