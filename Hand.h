//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_HAND_H
#define PROJECT_2_HAND_H

#include "Card.h"

class Hand {
private:

public:
    void clear();
    void addCard(Card card);
    int getCount();
    Card getCard(int n);

};


#endif //PROJECT_2_HAND_H
