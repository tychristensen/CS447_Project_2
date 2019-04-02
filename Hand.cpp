//
// Created by tysth on 4/1/2019.
//

#include "Hand.h"

Hand::Hand() {}

Hand::Hand(vector<Card> cards) {
    this->cards = cards;
}

void Hand::clear() {
    cards.clear();
}

void Hand::addCard(Card card) {
    cards.emplace_back(card);
}

int Hand::getCount() {
    return cards.size();
}

Card Hand::getCard(int n) {
    return cards[n];
}

Hand Hand::getVisible() {
    vector<Card> visibleCards;
    for(auto card : cards) {
        if(card.isFaceup()) {
            visibleCards.emplace_back(card);
        }
    }
    return Hand(visibleCards);
}

int Hand::evaluate() {
    int handTotal = 0;
    for(auto card : cards) {
        handTotal += card.getValue();
    }
    return handTotal;
}

