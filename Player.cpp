//
// Created by tysth on 4/1/2019.
//

#include "Player.h"

Player::Player(int id, int chips) {
    this->id = id;
    this->chips = chips;
}

int Player::getID() {
    return id;
}

void Player::clearHand() {
    hand.clear();
}

void Player::dealCard(Card c) {
    hand.addCard(c);
}

Hand Player::getHand() {
    return hand;
}

void Player::addChips(int chips) {
    this->chips += chips;
}

int Player::getChips() {
    return chips;
}
