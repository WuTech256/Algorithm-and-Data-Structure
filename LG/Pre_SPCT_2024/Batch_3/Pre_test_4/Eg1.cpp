#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> grid;

void input() {
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        grid[i].resize(m);
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
}

void solve() {
    vector<vector<pair<int, int>>> nums(n + m - 1);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (i == 0)
                nums[i + j].push_back({grid[i][j], 0});
            else
                nums[i + j].push_back({grid[i][j], 1});
        }
    }
    
    vector<pair<int, int>> result;
    bool reverse_flag = true;

    for(int i = nums.size() - 1; i >= 0; --i) {
        if (reverse_flag) {
            reverse(nums[i].begin(), nums[i].end());
        }
        result.insert(result.end(), nums[i].begin(), nums[i].end());
        reverse_flag = !reverse_flag; 
    }
   
    int sum = 0;
    int i = 0;
    vector<int> ans;
    int size = result.size();
    while(i < size) {
        int cur = result[i].first;
        // cout << "cur: " << cur << endl;
        if(cur % 2 == 1) {
            while(cur > 0 && i < size) {
                sum += result[i].first;
                // cout << " ok 1 : " << endl;
                // cout << result[i].first << endl;
                cur--;
                i++;
            }
            ans.push_back(sum % 23);
            // cout << sum << endl;
            sum = 0;
        } else {
            if(i < size && result[i].second == 0) {
                ans.push_back(result[i].first % 23);
                i++;
                continue;
            }
            while(i < size && cur > 0 && result[i].second == 1) {
                sum += result[i].first;
                // cout << " ok 2 : " << endl;
                // cout << result[i].first << endl;
                cur--;
                i++; 
            }
            if(i < size && result[i].second == 0 && cur > 0) {sum += result[i].first; i++;}
            ans.push_back(sum % 23);
            // cout << sum << endl;
            sum = 0;
            
        }
        
    }
    string ans_1;
    for(auto t : ans) {
        ans_1.push_back('a' + t);
    }
    cout << ans_1 << endl;
}

int32_t main() {
    input();
    solve();
    return 0;
}
