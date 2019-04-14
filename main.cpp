#include <iostream>
#include "Game.h"

int main() {

    Game game;

    string command;
    cout << "Enter a command: ";
    cin >> command;

    while(command != "quit" && command != "q") {

        if(command == "h" || command == "help") {
            cout << "Commands: play(p), quit(q)" << endl;
        } else if (command == "p" || command == "play") {
            int startChips = 1000;

            cout << "Enter player 0's type(0=human, 1=alpha): ";
            int option1;
            cin >> option1;
            while(option1 != 0 && option1 != 1) {
                cout << "Invalid option" << endl;
                cout << "Enter player 0's type(0=human, 1=alpha): ";
                cin >> option1;
            }

            cout << "Enter player 1's type(0=human, 1=alpha): ";
            int option2;
            cin >> option2;
            while(option2 != 0 && option2 != 1) {
                cout << "Invalid option" << endl;
                cout << "Enter player 1's type(0=human, 1=alpha): ";
                cin >> option2;
            }

            Player::PlayerType p0Type, p1Type;
            switch(option1) {
                case 0:
                    p0Type = Player::HUMAN;
                    break;
                case 1:
                    p0Type = Player::ALPHA;
                    break;
            }

            switch(option2) {
                case 0:
                    p1Type = Player::HUMAN;
                    break;
                case 1:
                    p1Type = Player::ALPHA;
                    break;
            }

            game.playGame(p0Type, p1Type, startChips, startChips, false);
        }

        cout << "Enter a command: ";
        cin >> command;
    }

    return 0;
}