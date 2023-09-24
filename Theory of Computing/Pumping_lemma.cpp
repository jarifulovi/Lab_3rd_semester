#include<iostream>
#include<string>
using namespace std;
string generateW(int n,bool st){  // st for second term expression
    string str;
    for(int i=0;i<n;i++) str += "0";
    for(int i=0;i<n;i++) str += "1";
    if(st){
        for(int i=0;i<n;i++) str += "1";
    }
    return str;
}
bool checkW(string str,bool st){  // st for second term expression
    int size = str.size();
    bool check = true;
    if(st){
        for(int i=0;i<size/3;i++) if(str[i]=='1') check = false;
        for(int i = size/3;i<size;i++) if(str[i]=='0') check = false;
    }
    else{
        for(int i=0;i<size/2;i++){
            if(str[i]=='1') check = false;
            if(str[i+size/2]=='0') check = false;
        }
    }
    return check;
}
string Pumping(string str){
    string x,y,z;
    x += str[0];
    z += str[str.size()-1];
    for(int i=1;i<str.size()-1;i++) y += str[i];
    // Pumping part
    str = x + y + y + z;
    return str;
}
void Pumping_lemma(string input){
    bool second_term = false;   // second term is for those expression where 0^n 1^2n
    bool isReguler = true;
    if(input.size()==8) second_term = true;    
    for(int i=2;i<10;i++){
        int n = i;
        string str;
        str = generateW(n,second_term);   // generate string according to expression
       
        int ite = 0;
        while(isReguler&&ite++<10){      // it will check atmost 10 times
            str = Pumping(str);
            isReguler = checkW(str,second_term);
        }
        if(!isReguler){
            cout << "The expression is not reguler when n is " << n << "and k is " <<ite << "\n";
            cout << "The pumped string is "<< str << "\n";
            break;
        }
    }
    if(isReguler)   cout << "The expression is reguler\n";
}
int main(){
    cout << "Enter the expression :\n";
    string input;
    getline(cin, input);
    Pumping_lemma(input);  // it will only work on two cases 0^n 1^n and 0^n 1^2n
    return 0;
}