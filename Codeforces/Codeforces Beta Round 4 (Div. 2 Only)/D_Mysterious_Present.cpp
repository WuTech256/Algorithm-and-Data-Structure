#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Envelope {
    int w, h, index;
};
 
int main() {
    int n, w, h;
    cin >> n >> w >> h;
 
    vector<Envelope> envelopes;
 
    for (int i = 0; i < n; ++i) {
        int wi, hi;
        cin >> wi >> hi;
        if (wi > w && hi > h) {
            envelopes.push_back({wi, hi, i + 1}); // Save original index (1-based)
        }
    }
 
    if (envelopes.empty()) {
        cout << 0 << endl;
        return 0;
    }
 
    // Sort by width ascending, and by height descending if widths are equal
    sort(envelopes.begin(), envelopes.end(), [](const Envelope &a, const Envelope &b) {
        if (a.w == b.w) return a.h > b.h;
        return a.w < b.w;
    });
 
    int m = envelopes.size();
    vector<int> dp(m, 1);       // dp[i] = length of chain ending at i
    vector<int> prev(m, -1);    // prev[i] = previous envelope index in the chain
 
    int max_len = 1, last_index = 0;
 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[j].w < envelopes[i].w && envelopes[j].h < envelopes[i].h) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_index = i;
        }
    }
 
    // Reconstruct the chain
    vector<int> result;
    for (int i = last_index; i != -1; i = prev[i]) {
        result.push_back(envelopes[i].index);
    }
 
    reverse(result.begin(), result.end());
 
    cout << max_len << endl;
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
 
    return 0;
}
