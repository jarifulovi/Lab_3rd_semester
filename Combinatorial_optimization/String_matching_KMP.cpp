#include <iostream>
#include <vector>
using namespace std;

void buildPrefixFunction(const string& pat, vector<int>& prefix_function) {
    int pat_len = pat.size();
    prefix_function.resize(pat_len, 0);

    for (int i = 1, j = 0; i < pat_len; ) {
        if (pat[i] == pat[j]) {
            prefix_function[i] = j + 1;
            ++i;
            ++j;
        } 
        else {
            if (j != 0) {
                j = prefix_function[j - 1];
            } 
            else {
                prefix_function[i] = 0;
                ++i;
            }
        }
    }
}

void kmp(const string& str, const string& pat) {
    int str_len = str.size();
    int pat_len = pat.size();
    if(str_len<pat_len) exit(1);

    vector<int> prefix_function;
    buildPrefixFunction(pat, prefix_function);

    int i = 0;  // Index for str
    int j = 0;  // Index for pat

    while(i<str_len){
        if(str[i]==pat[j]){
            i++;j++;
            if(j==pat_len){
                cout << "Matched found at index : " << i-pat_len << "\n";
                j = prefix_function[j-1];
            }
        }
        else{
            if(j!=0)  j = prefix_function[j-1];
            else  i++;
        }
    }
}

int main() {
    string str = "ABCBABCBACBACB";
    string pat = "CB";
    kmp(str, pat);

    return 0;
}
