//
// Created by tysth on 4/1/2019.
//

#ifndef PROJECT_2_CARD_H
#define PROJECT_2_CARD_H

#include <string>

using namespace std;

class Card {
private:
    bool faceup;
    string name;
    int value;
public:
    Card(string cardName, int cardValue);
    string getName();
    int getValue();
    bool isFaceup();
    void setFaceup(bool faceup);
};


#endif //PROJECT_2_CARD_H
