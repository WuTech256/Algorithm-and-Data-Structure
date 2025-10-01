#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> nums;

struct cmp {
    bool operator() (const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) return a[2] > b[2];
        return a[1] > b[1]; 
    }
};

void input() {
    cin >> n;
    nums.resize(n, vector<int> (3, 0));
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums[i][0] = x;
        nums[i][2] = i + 1;
    }
    
    for(int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        nums[i][1] = y;
    }
}

void solve() {
    sort(nums.begin(), nums.end(), [] (vector<int> a, vector<int> b) {
        if(a[0] == b[0] && a[1] == b[1]) return a[2] < b[2];
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    vector<int> res;
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    int j = 0;
    int cur = 0;
    while(!q.empty() || j < n) {
       if(!q.empty()) {
           auto g = q.top();
           cur += g[1];
           q.pop();
           res.push_back(g[2]);
           while(j < n && nums[j][0] <= cur) {
               q.push(nums[j]);
               j++;
           }
       } else {
           if(j < n) {
               cur = nums[j][0];
               q.push(nums[j]);
               j++;
           }
       }
    }
    
    for(auto t : res) {
        cout << t << " ";
    }
    cout << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();
    return 0;
}
