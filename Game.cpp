//
// Created by tysth on 4/1/2019.
//

#include "Game.h"

Game::Game() {

    int startChips = 1000;
    p0 = Player(Player::HUMAN, startChips);
    p1 = Player(Player::HUMAN, startChips);
    vector<Card> deck;
    for(int i = 0; i < 52; i++) {
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
