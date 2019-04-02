//
// Created by tysth on 4/1/2019.
//

#include "Card.h"

Card::Card(string cardName, int cardValue) {
    this->name = cardName;
    this->value = cardValue;
    this->faceup = false;
}

string Card::getName() {
    return name;
}

int Card::getValue() {
    return value;
}

bool Card::isFaceup() {
    return faceup;
}

void Card::setFaceup(bool faceup) {
    this->faceup = faceup;
}
