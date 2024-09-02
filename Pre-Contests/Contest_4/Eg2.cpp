#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

void input() {
    cin >> n; 
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
} 

void solve() {
    multiset<int> s;
    for(auto t : nums) {
        auto it = s.upper_bound(t);
        
        if(it != s.end()) {
            s.erase(it);
        }
        s.insert(t);
    }
    cout << s.size() << endl;
}

int main() {
    input();
    solve();
}