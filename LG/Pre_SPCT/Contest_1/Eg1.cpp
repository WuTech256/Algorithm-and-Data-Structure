#include <bits/stdc++.h>
using namespace std;

string s;
int k;

void input() {
    cin >> s;
    cin >> k;
}


string encode(string s1, int t) {
    for(int i = 0; i < s1.size(); ++i) {
        char c = s1[i] - 'a';
        // cout << (int)c << endl;
        c += (26 + t);
        c %= 26;
        s1[i] = 'a' + c;
    }
    
    return s1;
}

void solve() {
    int n = s.length();
    int di = n/k;
    int a = n % k;
    string res;
    int i = 0;
    int cnt = 0;
    while(i < n && cnt < di) {
        // cout << i << endl;
        // cout << cnt << endl;
        if(cnt % 2 == 0) {
            string cur = s.substr(i, k);
            string cur1 = encode(cur, k);
            res += cur1;
        } else {
            string cur = s.substr(i, k);
            string cur1 = encode(cur, -k);
            res += cur1;
        }
        cnt++;
        i += k;
    }
    
    for(int i = n - a; i < n; ++i) {
        res += s[i];
    }
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
