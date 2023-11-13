#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<char> _stack;

bool PDA(string str,int ratio){
    int i,count_pop = ratio;
    for(i=0; i<str.size(); i++){
        
        if (str[i] == '1' && i + 1 < str.size()) {
            if (str[i + 1] == '0') {
                return false;
            }
        }
        if(str[i] == '0'){
            _stack.push_back(str[i]);
        }
        else if(str[i] == '1'){
            count_pop--;
            if(count_pop) continue;  // don't go further if count_pop is not zero
            count_pop = ratio;
            if(!_stack.empty()){
                _stack.pop_back();
            }
            else {
                return false;
            }
        }
    }

    return _stack.empty();
}

int main(){
    int ratio;
    cout << "Enter the ratio of 0 and 1 (i.e 0^n 1^xn so the ratio is x)\n";
    cin >> ratio;
    cout << "Enter the string : \n";
    string str;
    cin>>str;
    if(PDA(str,ratio)){
        cout<<"Accepted"<<endl;
    }
    else{
        cout<<"Not accepted"<<endl;
    }
}