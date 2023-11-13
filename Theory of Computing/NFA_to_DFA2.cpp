#include<iostream>
#include<string>
#include<vector>

using namespace std;

void convertNFAtoDFA(string nfa_transition,int nfa_states,int nfa_symbols,string staring_state,string final_state){
    vector<string> dstates;
    string current_state;
    bool new_state = true;
    for(int i=0;i<nfa_states;i++){
        current_state = to_string(i);
        dstates.push_back(current_state);
        printf("f(%d,%d) : %s",i,0,nfa_transition[i][0]);
        printf("f(%d,%d) : %s",i,1,nfa_transition[i][1]);
        // finding new state
        new_state = 
    }
}

int main()
{
    // the transition function for a string ends with 01
    /*nfa[1][1]=12;
      nfa[1][2]=1;
      nfa[2][1]=0;
      nfa[2][2]=3;
      nfa[3][1]=0;
      nfa[3][2]=0;*/

    int nfa_states,nfa_symbols;
    string starting_state,final_state;
    printf("Enter states of nfa(3 for 1,2,3)\n");
    cin >> nfa_states;

    printf("Enter symbols of nfa(2 for 0 and 1)\n");
    cin >> nfa_symbols;

    string nfa_transition[nfa_states][nfa_symbols];
    printf("Enter transition function(for multiple states like 1 and 2 write 12)\n");
    for(int i=0;i<nfa_states;i++){
        for(int j=0;j<nfa_symbols;j++){
            printf("f(%d,%d) : ",i,j);
            cin >> nfa_transition[i][j];
        }
    }
    printf("Enter starting state\n");
    cin >> starting_state
    printf("Enter final states\n");
    cin >> final_state;
    printf("\n");
    convertNFAtoDFA(nfa_transition,nfa_states,nfa_symbols,starting_state,final_state);
    return 0;
}