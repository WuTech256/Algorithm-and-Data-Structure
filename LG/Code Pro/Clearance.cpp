#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;

void input() {
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

void solve() {
    map<int, int> freq;
    for(int num : nums) {
        freq[num]++;
    }

    vector<vector<int>> prefix(m + 1, vector<int>(n, 0));
    for(int num = 1; num <= m; ++num) {
        for(int i = 0; i < n; ++i) {
            prefix[num][i] = (i > 0 ? prefix[num][i-1] : 0);
            if(nums[i] == num) {
                prefix[num][i]++;
            }
        }
    }

    vector<int> types(m);
    iota(types.begin(), types.end(), 1);
    int res = INT_MAX;

    do {
        int start = 0;
        int curMove = 0;
        for(int type : types) {
            int end = start + freq[type] - 1;
            if (end >= n) break;  

            int availableMove = (start > 0 ? prefix[type][end] - prefix[type][start - 1] : prefix[type][end]);
            curMove += (freq[type] - availableMove);
            start = end + 1;
        }
        res = min(res, curMove);
    } while(next_permutation(types.begin(), types.end()));

    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
