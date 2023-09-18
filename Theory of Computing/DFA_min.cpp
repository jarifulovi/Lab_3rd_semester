#include<bits/stdc++.h>
using namespace std;
int main(){
    int numStates,alphabets,i,j,k,f_ind;
    bool flg;
    cout<< "Enter number of states and alphabets :"<<endl;
    cin>>numStates>>alphabets;
    char states[numStates],alpha[alphabets],final,transition[numStates][alphabets],start,table[numStates][numStates];
    cout<<"Enter alphabet: "<<endl;
    for( i=0;i<alphabets;i++){
        cin>>alpha[i];
    }
    cout<<"Enter states: "<<endl;
    for( i=0;i<numStates;i++){
        cin>>states[i];
    }
    cout<<"Enter starting node : ";
    cin>>start;
    cout<<"Enter Final node : ";
    cin>>final;
    cout<<"Transition function :"<<endl;
    for(i=0;i<numStates;i++){
        cout<<"State "<<states[i]<<endl;
        for(j=0;j<alphabets;j++){
            cout<<"For alphabet "<<alpha[j]<<" ";
            cin>>transition[i][j];
        }
    }
    bool situation[numStates];
        for( i=0;i<numStates;i++){
            if(final== states[i]){
                situation[i]=true;
                f_ind=i;
            }
            else{
                situation[i]=false;
            }
        }
        for(i=0;i<numStates;i++){
            for(j=0;j<numStates;j++){
                table[i][j]='*';
            }
        }
        for(i=0;i<numStates;i++){
                table[i][f_ind]='X';
                table[f_ind][i]='X';
            
        }
        for(i=0;i<numStates;i++){
            table[i][i]='=';
        }
        for(i=0;i<numStates;i++){
            for(j=i+1;j<numStates;j++){
                if(table[i][j]=='*'){
                    for(int m=0;m<alphabets;m++){
                        if(transition[i][m]==final || transition[j][m]==final){
                            if(transition[i][m]== final && transition[j][m]==final){
                                table[i][j]='=';
                                table[j][i]='=';
                            }
                            else{
                                table[i][j]='X';
                                table[j][i]='X';
                                break;
                            }
                        }
                    }
                if(table[i][j]=='*'){
                     flg=true;
                    for(int m=0;m<alphabets;m++){
                        for(int w=0;w<alphabets;w++){
                            if(situation[transition[transition[i][m]-'a'][w]-'a']!=situation[transition[transition[j][m]-'a'][w]-'a']){
                                table[i][j]='X';
                                table[j][i]='X';
                                flg=false;
                                break;
                            }
                        }
                        if(flg==false){
                            break;
                        }
                    }
                    if(flg==true){
                       table[i][j]='=';
                       table[j][i]='='; 
                    }
                }
             }
                
            }
        }
        cout<<"  ";
        for(i=0;i<numStates;i++){
            cout<<states[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<numStates;i++){
            cout<<states[i]<<" ";
            for(j=0;j<=i;j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
        bool equivalent[numStates];
        for(i=0;i<numStates;i++){
            equivalent[i]=true;
        }
        for(i=0;i<numStates;i++){
            for(j=0;j<i;j++){
                if(table[i][j]=='='){
                    equivalent[i]=false;
                    states[i]=states[j];
                    break;
                }
            }
        }
        cout<<"  ";
        for(i=0;i<alphabets;i++)cout<<alpha[i]<<" ";
        cout<<endl;
        for(i=0;i<numStates;i++){
            if(equivalent[i]==true){
                cout<<states[i]<<" ";
            for(j=0;j<alphabets;j++){
                if(equivalent[transition[i][j]-'a']==false)cout<<states[transition[i][j]-'a']<<" ";
                else 
                cout<<transition[i][j]<<" ";
            }
            cout<<endl;
            }
        }
}