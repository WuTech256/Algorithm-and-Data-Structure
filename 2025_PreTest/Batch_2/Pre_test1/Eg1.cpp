#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
vector<int> nums;

void input() {
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
}

void solve() {
    int min_i = LLONG_MAX;
    int max_i = LLONG_MIN;
    

    sort(nums.begin(), nums.end());

    for (int i = 0; i < 7; ++i) { 
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            int mod_val = (nums[j] % 7 + i) % 7; 
            if (mod_val == 0 || mod_val == 1)
                continue;
            cnt++;
        }
        min_i = min(cnt, min_i);
        max_i = max(cnt, max_i);
    }

    cout << min_i << " " << max_i << endl;
}

int32_t main() {
    input();
    solve();
    return 0;
}
