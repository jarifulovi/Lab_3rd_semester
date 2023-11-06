#include<iostream>
#include<string>
#define V 5
using namespace std;

string check_G(string grammar[V],int f_ind,int l_ind,string input){
    if(f_ind>l_ind) return grammar[0];
    if(f_ind==l_ind){
        if(input[f_ind]=='1') return grammar[1];
        else                  return grammar[2];
    }
    else {
        if(input[f_ind]=='1') return grammar[3];
        else                  return grammar[4];
    }
}
bool CFG_Palindrome(string input,string& main_ans){
    string grammar[V] = {
        "","1","0","1P1","0P0"
    };
    int length = input.size();
    int first_ind = 0;
    int last_ind = length-1;
    string ans = "P";
    main_ans += ans + " => ";
    if(length==0){
        cout << "P => ";
        ans = ans.replace(0,1,"epsilon");  // for zero length string
        cout << ans << "\n";
        return true;
    }
    for(int i=0;i<=length/2;i++){
        if(input[first_ind]!=input[last_ind]){
            return false;
        }
        int position_P = ans.find('P');
        ans = ans.replace(position_P,1,check_G(grammar,first_ind,last_ind,input));
        if(i<length/2) main_ans += ans + " => ";
        else               main_ans += ans;
        first_ind++;
        last_ind--;
    }
    return true;
}
int main() {
    string input,ans = "";
    cout << "Enter you string : ";
    cin >> input;
    if(CFG_Palindrome(input,ans)){
        cout << "The string is Palindrome\n";
        cout << "The derivative is :\n";
        cout << ans;
    }
    else {
        cout << "Not in this grammar\n";
    }

    return 0;
}