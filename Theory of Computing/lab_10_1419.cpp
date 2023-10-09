#include<iostream>
#include<string>
using namespace std;

void generateLeftmostDerivation(string input){
    if(input.find("1")==string::npos){
        cout << "The string is not valid according to the grammar\n";
        return;
    }
    string ans = "A1B";
    cout << "S => " << ans;
    for(int i=0;i<input.size();i++){
        if(ans.find("A")!=string::npos){
            if(input[i]=='0') ans = ans.replace(i,1,"0A");
            else   ans = ans.replace(i,1,"");
        }
        else{
            if(input[i]=='0') ans = ans.replace(i,1,"0B");
            else if(input[i]=='1') ans = ans.replace(i,1,"1B");
        }
        cout << " => " << ans;
    }
    if(ans.find("B")!=string::npos) ans = ans.replace(input.size(),1,"");
    cout << " => " << ans;

}
void generateRightmostDerivation(string input){
    if(input.find("1")==string::npos){
        cout << "The string is not valid according to the grammar\n";
        return;
    }
    string ans = "A1B";
    cout << "\nS => " << ans;
    size_t position1 = input.find("1");

    for(int i = position1+1;i<input.size();i++){
        size_t positionB = ans.find("B");
       
        if(positionB!=string::npos){
            if(input[i]=='0') ans = ans.replace(positionB,1,"0B");
            else if(input[i]=='1') ans = ans.replace(positionB,1,"1B");
        }
        cout << " => " << ans;
    }
    ans.replace(ans.find("B"),1,"");
    cout << " => " << ans;
    for(int i=0;i<position1;i++){
        size_t positionA = ans.find("A");
        if(positionA!=string::npos){
            if(input[i]=='0') ans = ans.replace(positionA,1,"0A");
        }
        cout << " => " << ans;
    }
    ans.replace(ans.find("A"),1,"");
    cout << " => " << ans;
}

int main(){
    string input;
    cout << "Enter the string : ";
    cin >> input;
    cout << "The string is : " << input << "\n";
    generateLeftmostDerivation(input);
    generateRightmostDerivation(input);
    return 0;
}