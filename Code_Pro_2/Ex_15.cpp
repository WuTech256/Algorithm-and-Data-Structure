#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN ((int)2e5)

int N, M;
vector<int> ID;

void InputData() {
    cin >> N >> M;
    ID.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ID[i];
    }
}

void solve() {
    int res = 0;
    vector<int> freq(16, 0);

    auto calculate_max = [&]() {
        int max_val = 0;
        for (int i = 1; i <= 14; i++) {
            max_val = max(max_val, freq[i] + freq[i - 1] + freq[i + 1]);
        }
        return max_val;
    };

    for (int i = 0; i < M; ++i) {
        freq[ID[i]]++;
    }

    res = max(res, calculate_max());

    for (int i = M; i < N; ++i) {
        freq[ID[i]]++;
        freq[ID[i - M]]--;
        res = max(res, calculate_max());
    }

    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    InputData();  
    solve();      

    return 0;
}
