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
    vector<int> dis(n + 1, -1);
    vector<vector<int>> graph;
    graph.resize(n);
    bool found = false;
    for(int i = 0; i < n; ++i) {
        if(nums[i] + i - 1 > 0)
            graph[i].push_back(nums[i] + i - 1);
        else 
            graph[i].push_back(0);
        
        if(nums[i] + i < n)
            graph[i].push_back(nums[i] + i);
        else {
            graph[i].push_back(n);
            continue;
        }
        
        if(nums[i] + i + 1 < n)
            graph[i].push_back(nums[i] + i + 1);
        else 
            graph[i].push_back(n);
    }
    
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    
    while(!q.empty() && !found) {
        int cur = q.front();
        q.pop();
        
        for(auto nb : graph[cur]) {
            if(dis[nb] == -1) {
                dis[nb] = dis[cur] + 1;
                q.push(nb);
                
                if(nb == n) {
                    cout << dis[nb] << endl;
                    found = true;
                    break;
                }
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
