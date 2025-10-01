// Street light posts
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        unordered_set<int> x, y;
        set<pair<int, int>> pairs;
        for(int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            x.insert(a);
            y.insert(b);
            pairs.insert({a, b});
        }
        
        bool check = false;
        if(pairs.size()  != x.size() *  y.size()) {
            check = true;
        }
        if(!check) cout << "BALANCED" << endl;
        else cout << "NOT BALANCED" << endl;
    }
}
