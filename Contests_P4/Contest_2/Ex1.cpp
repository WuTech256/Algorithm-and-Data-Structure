#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;

set<int> st = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};

void solve(string s, int k) {
    int res = 0;
    string a = s.substr(0, 2);
    string b = s.substr(3, 2);
    int g1 = stoi(a); 
    int g2 = stoi(b);
    
    
    int m = g1 * 60 + g2;
    int loop = (24 * 60) /k;
    int tmp = m;
    while(1) {
        m = (m + k) % 1440;
 
        auto it = st.find(m);
        if(it != st.end()) res++;
        if(m == tmp) break;
    }
    
    cout << res << endl;
    
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> T;
    while(T--) {
        string s;
        int k;
        cin >> s;

        // cin.ignore();
        cin >> k;
        solve(s, k);
    }
    return 0;
}
