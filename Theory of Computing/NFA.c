#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 3
#define MAX_ALPHABET 2
#define STRING 6
int numpaths = 0;
char allpaths[MAX_STATES*STRING][100];
char path[STRING+1] = "";

void print_path(char path[100]){
    printf("%s\n",path);
}

int stateIndex(char state, char *states) {
    for(int i=0;states[i]!='\0';i++){
        if(state==states[i]) return i;
    }
}

bool NFA(char currentState, char *string, char *alphabet, char acceptState,
                 char transition[MAX_STATES][MAX_ALPHABET][MAX_STATES+1],char *states,int pathlength) {
    path[pathlength] = currentState;
    if (*string == '\0') {
        path[pathlength+1] = '\0';
        print_path(path);
        return currentState == acceptState;
    }

    bool result = false;
    for (int i = 0; i < MAX_STATES; i++) {
        char nextState = transition[stateIndex(currentState, states)][*string-'0'][i];
        if (nextState != '\0') {
            
            result = result || NFA(nextState, string + 1,
                                          alphabet, acceptState, transition,states,pathlength+1);
           
        }
        
    }
    
    return result;
}

int main() {
    char alphabet[MAX_ALPHABET+1];
    char states[MAX_STATES+1];
    char startState;
    char acceptState;
    printf("Enter the alphabet symbols ('01'): ");
    scanf("%s", alphabet);

    printf("Enter the list of states ('abc'): ");
    scanf("%s", states);

    printf("Enter the start state: ");
    scanf(" %c", &startState);

    printf("Enter the accept state: ");
    scanf(" %c", &acceptState);

    // Transition function as a 3-dimensional array
    char transition[MAX_STATES][MAX_ALPHABET][MAX_STATES+1];
    printf("Enter the transition function:\n");
    for (int i = 0; i < strlen(states); i++) {
        for (int j = 0; j < strlen(alphabet); j++) {
            printf("From state %c on symbol %c: ", states[i], alphabet[j]);
            scanf("%s", transition[i][j]);
        }
    }
    char string[100];
    printf("Enter the input string: ");
    scanf("%s", string);

    

    if (NFA(startState, string, alphabet, acceptState, transition,states,0)) {
        printf("\nInput string is accepted by the NFA.\n");
    } else {
        printf("\nInput string is rejected by the NFA.\n");
    }
    
    return 0;
}
