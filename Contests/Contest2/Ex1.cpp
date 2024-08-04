#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> nums;
vector<int> a;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.insert(x);
    }
    cin >> m;
    a.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> a[i];
    }
}

int solve(int k, vector<int> &tmp) {
    auto it = upper_bound(tmp.begin(), tmp.end(), k);
    if(it == tmp.end()) return 1;
    return tmp.end() - it + 1; 
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    vector<int> tmp(nums.begin(), nums.end());
    for(int i = 0; i < m; ++i) {
        cout <<solve(a[i], tmp) << endl;
    }
    return 0;
}
