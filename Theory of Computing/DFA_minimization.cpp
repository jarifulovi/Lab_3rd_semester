#include <iostream>
#include <vector>

#define STATE 8
#define ALP 2

using namespace std;

void minimal_dfa(char table[STATE][STATE], int transition[STATE][ALP]) {
    bool equivalent[STATE] = { true };
    int states[STATE];
    for (int i = 0; i < STATE; i++) states[i] = i;

    for (int i = 0; i < STATE; i++) {
        for (int j = 0; j < i; j++) {
            if (table[i][j] == '=') {
                equivalent[i] = false;
                states[i] = states[j];
                break;
            }
        }
    }

    cout << "  ";
    for (int i = 0; i < ALP; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < STATE; i++) {
        if (equivalent[i] == true) {
            cout << (char)(states[i] + 'A') << " ";
            for (int j = 0; j < ALP; j++) {
                if (equivalent[transition[i][j]] == false)
                    cout << (char)(states[transition[i][j]] + 'A') << " ";
                else
                    cout << (char)(transition[i][j] + 'A') << " ";
            }
            cout << endl;
        }
    }
}

void print_distinguishability_table(char distinguish_table[STATE][STATE]) {
    cout << "Table of Distinguishabilities:\n";
    cout << "  A B C D E F G H\n";
    for (int i = 0; i < STATE; i++) {
        cout << char(i + 'A') << " ";
        for (int j = 0; j < STATE; j++) {
            cout << distinguish_table[i][j] << " ";
        }
        cout << "\n";
    }
}

void calculate_distinguishabilities(int transition[STATE][ALP], int starting_state, int final_state) {
    char distinguish_table[STATE][STATE];

    for (int i = 0; i < STATE; i++) {
        for (int j = 0; j < STATE; j++) {
            distinguish_table[i][j] = (i == final_state && j != final_state) ? 1 : 0;
        }
    }

    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 1; i < STATE; i++) {
            for (int j = 0; j < i; j++) {
                if (distinguish_table[i][j] == 0) {
                    for (int k = 0; k < ALP; k++) {
                        int a = transition[i][k];
                        int b = transition[j][k];
                        if (distinguish_table[a][b] == 1) {
                            distinguish_table[i][j] = 1;
                            changed = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    print_distinguishability_table(distinguish_table);
    minimal_dfa(distinguish_table, transition);
}

int main() {
    int transition[STATE][ALP];
    int starting_state, final_state;

    cout << "Enter transition function :\n";
    for (int i = 0; i < STATE; i++) {
        cout << "For state " << i << "\n";
        for (int j = 0; j < ALP; j++) {
            cout << "Alphabet " << j << " : ";
            cin >> transition[i][j];
        }
    }

    cout << "\nEnter starting state : ";
    cin >> starting_state;
    cout << "\nEnter final state : ";
    cin >> final_state;

    calculate_distinguishabilities(transition, starting_state, final_state);

    return 0;
}
