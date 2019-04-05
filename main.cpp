#include <iostream>
#include "Game.h"

int main() {

    Game game;

    string command;
    cout << "Enter a command: ";
    cin >> command;

    while(command != "quit") {

        if(command == "h" || command == "help") {
            cout << "Commands: play, quit" << endl;
        } else if (command == "p" || command == "play") {
            int startChips = 1000;
            game.playGame(Player::HUMAN, Player::HUMAN, startChips, startChips, false);
        }

        cout << "Enter a command: ";
        cin >> command;
    }

    return 0;
}