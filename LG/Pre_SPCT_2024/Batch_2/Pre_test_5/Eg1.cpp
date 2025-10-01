#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    set<char> s1(s.begin(), s.end());
    string a(s1.begin(), s1.end());
    
    unordered_map<char, char> mp;
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        mp[a[i]] = a[n-i-1];
        mp[a[n-i-1]] = a[i];
    }
    
    for(int i = 0; i < s.length(); ++i) {
        s[i] = mp[s[i]];
    }
    cout << s << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
