// Word Flipping
#include <bits/stdc++.h>
using namespace std;

string s;
string res = "";

void input() {
    getline(cin, s);
}

void solve() {
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '<') {
            res += '<';
            while (s[i] != '>' && i < s.length()) {
                i++;
                res += s[i];
            }
            continue;
        }

        if (s[i] != '<' && s[i] != '>' && s[i] != ' ') {
            while (i < s.length() && (s[i] != ' ' && s[i] != '<' && s[i] != '>')) {
                st.push(s[i]);
                i++;
            }
            i--;
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        if (s[i] == ' ') 
            res += ' ';
    }

    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
