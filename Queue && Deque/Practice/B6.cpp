#include <bits/stdc++.h>
using namespace std;

int T;

// downToZero
void solve(int n) {
    vector<int> dist(n+1, 0);
    
    queue<int> q;
    q.push(n);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == 0) {
            break;
        }
        
        if(dist[cur-1] == 0) {
            q.push(cur-1);
            dist[cur-1] = dist[cur] + 1;
        }
        
        for(int i = sqrt(cur); i >= 2; --i) {
            if(cur % i == 0 & dist[cur/i] == 0) {
                dist[cur/i] = dist[cur] + 1;
                q.push(cur/i);
            }
        }
    }
    
    cout << dist[0] << endl;
}

int main() {
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        solve(n);   
    }
}
