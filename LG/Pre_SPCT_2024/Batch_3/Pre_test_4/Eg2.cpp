#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m, e;
    cin >> n >> m >> e;
    
    vector<long long> nums_1(n);
    vector<long long> nums_2(m);
    
    for (long long i = 0; i < n; ++i) {
        cin >> nums_1[i];
    }
    
    for (long long i = 0; i < m; ++i) {
        cin >> nums_2[i];
    }
    
    vector<long long> res;
    res.reserve(n + m); 

    for (long long i = 0; i < n; ++i) {
        res.push_back(nums_1[i] + e);
    }
    
    for (long long i = 0; i < m; ++i) {
        res.push_back(nums_2[i] - e);
    }
    
    sort(res.begin(), res.end());
    

    long long total_distance = 0;
    long long prefix_sum = 0;
    long long count = 0;
    
    for (long long i = 0; i < res.size(); ++i) {
 
        total_distance += (res[i] * i - prefix_sum) % MOD;
        prefix_sum += res[i];
        prefix_sum %= MOD;
    }
    
    total_distance = (total_distance % MOD + MOD) % MOD; 
    cout << total_distance << endl;

    return 0;
}
