#include <stdio.h>
int DFA(char* str,char* states,char transition[6][4],char starting_state,char final_state,char* alphabets){
    char state = starting_state;
    for(int i=0;str[i]!='\0';i++){
        for(int j=0;j<6;j++){
            if(str[i]==transition[j][0]&&state==transition[j][1]){
                state = transition[j][2];
                break;
            }
        }
        printf("%c",state);
    }
    if(state==final_state) return 1;
    else return 0;

}
int main() {
    char str[100], states[4], transition[6][4], starting_state, final_state, alphabets[10];
    printf("Enter the alphabets: ");
    scanf("%s", alphabets);
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the states: ");
    scanf("%s", states);
    getchar();
    printf("Enter the transition function: ");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &transition[i][j]);
        }
        transition[i][3] = '\0'; 
    }
    printf("Enter the starting state: ");
    scanf(" %c", &starting_state);
    getchar();
    printf("Enter the final state: ");
    scanf(" %c", &final_state);
    //printf("\nA: %s, str: %s, s: %s, ss: %c, fs: %c\n", alphabets, str, states, starting_state, final_state);
    //for (int i = 0; i < 6; i++) printf("%s\n", transition[i]);
    printf("%s\n",str);
    int bolean = DFA(str,states,transition,starting_state,final_state,alphabets);
    if(bolean) printf("\nAccepted\n");
    else printf("\nRejected\n");
    return 0;
}
