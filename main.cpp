//basically c version of imports
#include <iostream>
#include <random>
#include <vector> 
#include <algorithm>

using namespace std;

int main() {
    cout << "Mastermind in C++ let's go" << endl;
    //initialising and generating the actual list
    vector<int> seq (4);
    for (int x = 0; x != 4; ++x) {
        int g = rand() % 10;
        while (find(seq.begin(),seq.end(), g) != seq.end() or g == 0) {
            int g = rand() % 10;
        }
        seq[x] = g;
    };
    int guesses = 0;
    //main loop which is broken once guess list matches actual list
    while (true) {
        int correct = 0;
        int kinda = 0;
        //for initialising and resetting player's guesses
        vector<int> play (4);
        for (int x = 0; x != 4; ++x) {
        cout << "enter number you think is in " << x+1 << "th place of sequence" << endl;
        //player's guess
        int y;
        cin >> y;
        while (find(play.begin(), play.end(), y) != play.end() or y < 1 or y > 9) {
            cout << "either you put this number already or you put an impossible value" << "\n";
            cin >> y;
        }
        play[x] = y;
        if (seq[x] == y) {
            correct++;
        }
    }
    cout << "you got " << correct << " places exactly correct" << endl;
    if (seq[0] == play[0] and seq[1] == play[1] and seq[2] and play[2] and seq[3] == play[3]) {
        break;
    }
    for (int x = 0; x != 4; ++x) {
        if (find(seq.begin(), seq.end(), play[x]) != seq.end() and play[x] != seq[x]) {
            kinda++;
            }
        }
    cout << "you got " << kinda << " numbers right but in wrong place" << endl;
    //player list printed so that player can use it for reference
    cout << play[0] << play[1] << play[2] << play[3] << endl;
    guesses++;
    }
    cout << "You got it right! The sequence was " << seq[0] << seq[1] << seq[2] << seq[3] << " which took you " << guesses << " guesses to find.";
    return 0;
}
