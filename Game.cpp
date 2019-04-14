//
// Created by tysth on 4/1/2019.
//

#include "Game.h"

Game::Game() {}

bool Game::playGame(Player::PlayerType p0Type, Player::PlayerType p1Type, int &chips0, int &chips1, bool reportFlag) {

    pot = 0;

    Player* p0;
    Player* p1;

    switch (p0Type) {
        case Player::HUMAN:
            p0 = new HumanPlayer(0, chips0);
            break;
        case Player::ALPHA:
            p0 = new AlphaPlayer(0, chips0);
            break;
    }

    switch(p1Type) {
        case Player::HUMAN:
            p1 = new HumanPlayer(1, chips1);
            break;
        case Player::ALPHA:
            p1 = new AlphaPlayer(1, chips1);
            break;
    }

    for(int i = 0; i < 10; i++) {
        doHand(*p0, *p1);
        doHand(*p1, *p0);
    }

    if(p0->getChips() > p1->getChips()) {
        cout << "Player 0 wins with " << p0->getChips() << " and Player 1 with " << p1->getChips() << endl;
    } else if(p0->getChips() < p1->getChips()) {
        cout << "Player 1 wins with " << p1->getChips() << " and Player 0 with " << p0->getChips() << endl;
    } else {
        cout << "Players 0 & 1 tied" << endl;
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

void Game::doHand(Player& firstPlayer, Player& secondPlayer) {

    shuffleDeck();
    pot = 0;

    //deal three cards
    for (int j = 0; j < 3; j++) {
        if(j != 0) {
            deck[0].setFaceup(true);
            deck[1].setFaceup(true);
        }
        firstPlayer.dealCard(deck[0]);
        secondPlayer.dealCard(deck[1]);
        deck.erase(deck.begin());
        deck.erase(deck.begin());
    }

    //setup pot with buy in
    firstPlayer.addChips(-10);
    secondPlayer.addChips(-10);
    pot += 20;

    int bet1 = 0;
    int bet2 = 0;
    firstPlayer.clearBetHistory();
    secondPlayer.clearBetHistory();
    bool handOver = doBetRound(&firstPlayer, &secondPlayer, bet1, bet2, 0);

    if(handOver) {
        cout << "Hand over" << endl;
        firstPlayer.clearHand();
        secondPlayer.clearHand();
        return;
    }

    //deal another card
    deck[0].setFaceup(true);
    deck[1].setFaceup(true);
    firstPlayer.dealCard(deck[0]);
    secondPlayer.dealCard(deck[1]);
    deck.erase(deck.begin());
    deck.erase(deck.begin());

    firstPlayer.clearBetHistory();
    secondPlayer.clearBetHistory();
    handOver = doBetRound(&firstPlayer, &secondPlayer, bet1, bet2, 0);

    if(handOver) {
        cout << "Hand over" << endl;
        firstPlayer.clearHand();
        secondPlayer.clearHand();
        return;
    }

    //deal final card
    deck[0].setFaceup(true);
    deck[1].setFaceup(true);
    firstPlayer.dealCard(deck[0]);
    secondPlayer.dealCard(deck[1]);
    deck.erase(deck.begin());
    deck.erase(deck.begin());

    firstPlayer.clearBetHistory();
    secondPlayer.clearBetHistory();
    handOver = doBetRound(&firstPlayer, &secondPlayer, bet1, bet2, 0);

    if(handOver) {
        cout << "Hand over" << endl;
        firstPlayer.clearHand();
        secondPlayer.clearHand();
        return;
    }

    cout << "Player " << firstPlayer.getID() << " had a " << firstPlayer.getHand().getCard(0).getName();
    cout << " with a total hand value of " << firstPlayer.getHand().evaluate() << endl;

    cout << "Player " << secondPlayer.getID() << " had a " << secondPlayer.getHand().getCard(0).getName();
    cout << " with a total hand value of " << secondPlayer.getHand().evaluate() << endl;

    if(firstPlayer.getHand().evaluate() > secondPlayer.getHand().evaluate()) {
        cout << "Player " << firstPlayer.getID() << " wins a pot of " << pot << endl;
        firstPlayer.addChips(pot);
        pot = 0;
    } else if (firstPlayer.getHand().evaluate() < secondPlayer.getHand().evaluate()) {
        cout << "Player " << secondPlayer.getID() << " wins a pot of " << pot << endl;
        secondPlayer.addChips(pot);
        pot = 0;
    } else {
        cout << "It's a tie" << endl;
    }

    firstPlayer.clearHand();
    secondPlayer.clearHand();

}

bool Game::doBetRound(Player* firstPlayer, Player* secondPlayer, int &bet1, int &bet2, int numRaises) {

    bet1 = firstPlayer->getBet(secondPlayer->getHand().getVisible(), secondPlayer->getBetHistory(), bet2, numRaises < 3, pot);

    if(firstPlayer->getBetHistory().getCount() == 1) {
        if(bet1 == 0) {
            cout << endl << "Player " << firstPlayer->getID() << " checks" << endl;
        } else {
            cout << endl << "Player " << firstPlayer->getID() << " raises " << bet1 << endl;
            numRaises++;
        }
    } else {
        if (bet1 == 0) {
            cout << endl << "Player " << firstPlayer->getID() << " folds" << endl;
            secondPlayer->addChips(pot);
            pot = 0;
            return true;
        } else if (bet1 == bet2) {
            cout << endl << "Player " << firstPlayer->getID() << " called Player " << secondPlayer->getID() << endl;
            bet2 = 0;
            bet1 = 0;
            return false;
        } else {
            cout << endl << "Player " << firstPlayer->getID() << " raised " << bet1 - bet2 << " after Player " << secondPlayer->getID() << " raised " << bet2 << endl;
            numRaises++;
            bet1 -= bet2;
        }
    }


    bet2 = secondPlayer->getBet(firstPlayer->getHand().getVisible(), firstPlayer->getBetHistory(), bet1, numRaises < 3, pot);

    if (bet1 == 0) {
        if (bet2 == 0) {
            cout << endl << "Both players check" << endl << endl;
            return false;
        } else {
            cout << endl << "Player " << secondPlayer->getID() << " raised " << bet2 << endl;
            numRaises++;
        }
    } else {
        if (bet2 == 0) {
            cout << endl << "Player " << secondPlayer->getID() << " folds" << endl;
            firstPlayer->addChips(pot);
            pot = 0;
            return true;
        } else if (bet1 == bet2) {
            cout << endl << "Player " << secondPlayer->getID() << " called Player " << firstPlayer->getID() << endl;
            bet1 = 0;
            bet2 = 0;
            return false;
        } else {
            cout << endl << "Player " << secondPlayer->getID() << " raised " << bet2 - bet1 << " after Player " << firstPlayer->getID() << " raised " << bet1 << endl;
            numRaises++;
            bet2 -= bet1;
        }
    }

    return doBetRound(firstPlayer, secondPlayer, bet1, bet2, numRaises);

}
