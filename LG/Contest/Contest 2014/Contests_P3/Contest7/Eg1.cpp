#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<string, int>> nums;


bool cmp(pair<string, int> a, pair<string, int> b) {
    if(a.first.substr(0, 4) != b.first.substr(0, 4))
        return a.first.substr(0, 4) < b.first.substr(0, 4);
    if(a.first.substr(5, 2) != b.first.substr(5,2)) 
        return a.first.substr(5,2) < b.first.substr(5,2);
    if(a.first.substr(8, 2) != b.first.substr(8, 2))
        return a.first.substr(8, 2) < b.first.substr(8, 2);
    return a.second > b.second;
}
void input() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string x, y;
        cin >> x >> y;
        nums.push_back({x, 1});
        nums.push_back({y, 2});
    }
}

void solve() {
    sort(nums.begin(), nums.end(), cmp);
    string res;
    int cnt = 0;
    int max_i = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i].second == 1) {
            cnt++;
            if(cnt > max_i) {
                max_i = cnt;
                res = nums[i].first;
            }
        } else {
            cnt--;
        }
    }
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}