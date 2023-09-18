#include <stdio.h>
#define STATE 8
#define ALP 2

#include <stdbool.h>

void print_minimal_dfa(int equivalence[STATE], int transition[STATE][ALP]) {
    bool printed[STATE] = {false};

    printf("\nMinimal DFA Transition Table:\n");

    // Print column headers
    printf("State\t");
    for (int i = 0; i < ALP; i++) {
        printf("Input %d\t", i);
    }
    printf("\n");

    // Print transitions based on equivalence and merged states
    for (int i = 0; i < STATE; i++) {
        if (!printed[i]) {
            // Check for merged states
            bool is_merged = false;
            printf("%c", i + 'A');

            // Print merged states
            for (int j = i + 1; j < STATE; j++) {
                if (equivalence[i] == equivalence[j]) {
                    printed[j] = true;
                    printf(", %c", j + 'A');
                    is_merged = true;
                }
            }

            if (!is_merged)
                printf("\t");
            else
                printf(" (Merged)\t");

            // Print transitions for the group of merged states
            for (int j = 0; j < ALP; j++) {
                int target_state = equivalence[transition[i][j]];
                printf("%c\t", target_state + 'A');
            }

            printf("\n");
        }
    }
}


void print_distinguishability_table(int distinguish_table[STATE][STATE]) {
    printf("Table of Distinguishabilities:\n");
    printf("  A B C D E F G H\n");
    for (int i = 0; i < STATE; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < STATE; j++) {
            printf("%s ", distinguish_table[i][j] == 0 ? "x" : "=");
        }
        printf("\n");
    }
}
void calculate_distinguishabilities(int transition[STATE][ALP],int starting_state, int final_state) {
    int distinguish_table[STATE][STATE] = {0};
    for (int i = 1; i < STATE; i++) {
        for (int j = 0; j < i; j++) {
            if ((i == final_state && j != final_state)) {
                distinguish_table[i][j] = 1;
            }
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
    int equivalent_state[STATE];
    print_minimal_dfa(equivalent_state,transition);
}



int main() {
    int transition[STATE][ALP] = {
        {1, 0}, {0, 2}, {3, 1}, {3, 0}, {3, 5}, {6, 4}, {5, 6}, {6, 3}
    };
    int starting_state = 0;
    int final_state = 3;
   
    

    calculate_distinguishabilities(transition,starting_state,final_state);

    return 0;
}
