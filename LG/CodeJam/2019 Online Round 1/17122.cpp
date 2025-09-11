// Chess
#include <bits/stdc++.h>
using namespace std;

inline bool colorFromCoord(const string& s) {
    int col = s[0] - 'A';      
    int row = s[1] - '1';
    return ((col % 2) == 0) ^ (row % 2);
}

inline bool colorFromNumber(int a) {
    int idx = a - 1;
    int col = idx % 8;
    int row = idx / 8;
    return ((col % 2) == 0) ^ (row % 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--) {
        string s;
        int a;
        cin >> s >> a;
        cout << (colorFromCoord(s) == colorFromNumber(a) ? "YES\n" : "NO\n");
    }
    return 0;
}
