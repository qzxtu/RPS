#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char get_user_input();
char get_computer_choice();
void choice(char l);
void winner(char plr, char comp);

int main() {
    srand(time(nullptr));
    char plr;
    char comp;

    do {
        plr = get_user_input();
        cout << "Your Choice Is: ";
        choice(plr);

        comp = get_computer_choice();
        cout << "Computer Choice Is: ";
        choice(comp);

        winner(plr, comp);
    } while (true);
}

char get_user_input() {
    char player;
    cout << "Rock - Paper - Scissors\n";
    do {
        cout << "'r' for rock, 's' for scissors, 'p' for paper: ";
        cin >> player;
    } while (player != 'r' && player != 's' && player != 'p');
    return player;
}

char get_computer_choice() {
    int computer = rand() % 3;

    switch (computer) {
        case 0:
            return 'r';
        case 1:
            return 's';
        case 2:
            return 'p';
    }
}

void choice(char l) {
    switch (l) {
        case 'r':
            cout << "Rock\n";
            break;
        case 's':
            cout << "Scissors\n";
            break;
        case 'p':
            cout << "Paper\n";
            break;
    }
}

void winner(char plr, char comp) {
    if (plr == comp) {
        cout << "Tie\n";
    } else if ((plr == 'r' && comp == 's') || (plr == 's' && comp == 'p') || (plr == 'p' && comp == 'r')) {
        cout << "You Won\n";
    } else {
        cout << "Computer Won\n";
    }
}