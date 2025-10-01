#include <bits/stdc++.h>
using namespace std;

string s;
int k;

void input() {
    cin >> s;
    cin >> k;
}

string kill(string t, int tm) {
    int m = t.size();
    if(m < k) return t;
    for(int i = 0; i < m; ++i) {
        char c = t[i] - 'a';
        c += tm + 26;
        c %= 26;
        t[i] = 'a' + c;
    }
    return t;
}

void solve() {
    string res;
    int n = s.length();
    vector<string> tmp;
    for(int i = 0; i < n; i += k) {
        tmp.push_back(s.substr(i, k));
    }
    
    int tm = k;
    for(auto t : tmp) {
        // cout << t << endl;
        // cout << kill(t, tm) << endl;
        res += kill(t, tm);
        tm = -tm;
    }
    cout << res << endl;
    
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
