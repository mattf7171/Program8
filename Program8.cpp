#include <iostream>
using namespace std;

/*
 I think that staying with the door that you picked gives a
 higher probability of winning the game.
 */

void simulateMontyHall(int num_trials) {
    int wins_if_switch = 0;
    int wins_if_stay = 0;

    srand(1489);

    for (int i = 0; i < num_trials; ++i) {
        int winning_door = rand() % 3 + 1;

        int contestant_choice = rand() % 3 + 1;

        int monty_shows;
        do {
            monty_shows = rand() % 3 + 1;
        } while (monty_shows == contestant_choice || monty_shows == winning_door);

        int remaining_door = 6 - contestant_choice - monty_shows;

        if (remaining_door == winning_door) {
            wins_if_switch++;
        }
        if (contestant_choice == winning_door) {
            wins_if_stay++;
        }
    }

    double switch_win_prob = double(wins_if_switch) / num_trials;
    double stay_win_prob = double(wins_if_stay) / num_trials;

    cout << "Probability of winning if switching: " << switch_win_prob << endl;
    cout << "Probability of winning if staying: " << stay_win_prob << endl;
}

int main() {
    const int NUM_TRIALS = 100000;
    simulateMontyHall(NUM_TRIALS);
    return 0;
}