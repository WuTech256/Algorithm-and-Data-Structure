#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;
vector<int> g(4);
int n;
void input() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < 4; ++i) {
        cin >> g[i];
    }
    for(int i = 0; i < n; ++i) {
        nums[i].resize(5);
        for(int j = 0; j < 5; ++j) {
            cin >> nums[i][j];
        }
    }  
}


void solve() {
    vector<int> store;
    int res = INT_MAX;

    for(int mask = 1; mask < (1 << n); ++mask) {
        int price_t = 0;
        int a = 0, b = 0, c = 0, d =0;
        vector<int> tmp;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                a += nums[i][0];
                b += nums[i][1];
                c += nums[i][2];
                d += nums[i][3];
                price_t += nums[i][4];
                tmp.push_back(i + 1);
            }
        }
        // cout << "p: " << price_t << endl;
        if(a >= g[0] && b >= g[1] && c >= g[2] && d >= g[3]) {
            if(price_t < res) {
                res = price_t;
                store = tmp;
            }
        }
        
    }
    if(res != INT_MAX) {
          cout << res << endl;
        for(auto t : store) {
            cout << t << " ";
        }
    
    } else {
        cout << "-1" << endl;
    }
  
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();
    return 0;
}
