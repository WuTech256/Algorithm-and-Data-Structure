#include <bits/stdc++.h>
using namespace std;

string s;
void input() {
    cin >> s;
}

void solve() {
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(auto t : s) {
        mp1[t] = 1;
    }
    int cnt  =0;
    // cout << mp1.size() << endl;
    for(int i = 0; i < s.length(); ++i) {
        mp2[s[i]]++;
        int cur = mp2[s[i]];
        bool check = true;
        for(auto t : mp1) {
            if(mp2[t.first] != cur) {
                check = false;
                break;
            }
        }
        
        if(check) {
            mp2.clear();
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    input();
    solve();
}