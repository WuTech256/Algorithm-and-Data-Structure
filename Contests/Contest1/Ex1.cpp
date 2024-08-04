#include <bits/stdc++.h>
using namespace std;

string s;
void input()
{
    cin >> s;
}
void solve() 
{
    string res = "";
    int n = s.length();
    string albe =  "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < n; ++i) { 
        if(i + 2 < n && s[i+2] == '0' && s[i + 3] != '0') {
            string tmp = s.substr(i, 2);
            int k = stoi(tmp);
            res += albe[k - 1];
            i += 2;
        } else {
            res += albe[s[i] - '0' -1];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    input();
    solve();
    return 0;
}
