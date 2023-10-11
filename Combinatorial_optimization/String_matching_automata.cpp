#include <iostream>
#include <vector>
#include <string>
using namespace std;
void computeTransitionFunction(string pattern,string alphabet,vector<vector<int>>& transitionFunction) {
    int m = pattern.length();
    int AlphabetSize = alphabet.length();

    transitionFunction.resize(m + 1, vector<int>(AlphabetSize));

    for (int q = 0; q <= m; q++) {
        for (char a : alphabet) {
            int k = min(m, q + 1);

            while (k > 0) {
                string Pk = pattern.substr(0, k);
                string Pqa = pattern.substr(0, q) + a;

                if (Pk == Pqa.substr(Pqa.length() - k))
                    break;

                k--;
            }

            transitionFunction[q][a - 'a'] = k;
        }
    }
}

void finiteAutomatonMatcher(string text,string pattern,string alphabet) {
    int n = text.length();
    int m = pattern.length();
    vector<vector<int>> transitionFunction;

    computeTransitionFunction(pattern, alphabet, transitionFunction);
    cout << "Transition table :\n";
    for(int i=0;i<m;i++){
        cout << "For state " << i << " : "; 
        for(int j=0;j<alphabet.size();j++) cout << transitionFunction[i][j] << " ";
        cout << "\n";
    }
    int q = 0;
    for (int i = 0; i < n; i++) {
        char a = text[i];
        q = transitionFunction[q][a - 'a'];

        if (q == m) {
            int s = i - m + 1;
            cout << "\nPattern occurs with shift " << s << "\n";
        }
    }
}

int main() {
    string text = "ababcabab";
    string pattern = "ab";
    string alphabet = "abc";

    cout << "Pattern occurrences in the text:\n";
    finiteAutomatonMatcher(text, pattern, alphabet);

    return 0;
}
