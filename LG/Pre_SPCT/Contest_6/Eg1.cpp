#include <bits/stdc++.h>
using namespace std;

string s;

void input() {
    cin >> s;
}

void solve() {
    string res;
    for(int i = 0; i < s.length(); i += 2) {
        if(isdigit(s[i])) {
            int cur = s[i] - '0';
            for(int j = 0; j < cur; ++j) {
                res += s[i+1];
            }
        }
    }
    cout << res << endl;
}

int main() {
    input();
    solve();
}