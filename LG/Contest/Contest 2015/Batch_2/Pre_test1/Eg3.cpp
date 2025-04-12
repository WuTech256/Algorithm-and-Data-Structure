#include <bits/stdc++.h>
using namespace std;
#define int long long 

int N;
vector<int> expire, value;

void input() {
    cin >> N;
    expire.resize(N);
    value.resize(N);
    for (int i = 0; i < N; i++) cin >> expire[i];
    for (int i = 0; i < N; i++) cin >> value[i];
}

void solve() {
    vector<pair<int, int>> buttons(N);
    for (int i = 0; i < N; i++) {
        buttons[i] = {expire[i], value[i]};
    }

    sort(buttons.begin(), buttons.end());

    priority_queue<int> pq; 
    int maxScore = 0, idx = N - 1;

    int max_i = *max_element(expire.begin(), expire.end());

    for (int time = max_i; time >= 1; time--) {
        while (idx >= 0 && buttons[idx].first >= time) {
            pq.push(buttons[idx].second);
            idx--;
        }

        if (!pq.empty()) {
            maxScore += pq.top();
            pq.pop();
        }
    }

    cout << maxScore << endl;
}

int32_t main() {
    input();
    solve();
    return 0;
}
