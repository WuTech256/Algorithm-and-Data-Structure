#include <iostream>
#include <queue> 
#include <vector>
using namespace std;

int n;
vector<int> b;
vector<int> s;

void input() {
    cin >> n;
    b.resize(n);
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
}

int solve() {
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(s[0]);
    for(int i = 1; i < n; ++i) {
        while(!pq.empty() && pq.top() < b[i]) {
            pq.pop();
        }
        pq.push(s[i]);
    }
    res = pq.size();
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << solve() << endl;
    return 0;
}
