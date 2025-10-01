 #include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

vector<int> a;

void input() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

    
void solve() {
    int res = 0;
    vector<int> prefix(n);
    vector<int> ans;
    vector<pair<int, int>> nums;
    for(int i = 0; i < a.size(); ++i) {
        nums.push_back({a[i], i});
    }
    sort(nums.begin(), nums.end());
    int cur = 0;
    for(auto t: a) cur += t;
    prefix[0] = nums[0].first;
    
    int te = prefix[0];
    for(int i = 1; i < n; ++i) {
        if(prefix[0] >= nums[i].first) {
            te +=  nums[i].first;
        } else break;
    }
    
    if(te == cur) {res++; ans.push_back(1);}
    
    for(int i = 1; i < n; ++i) {
        prefix[i]  = prefix[i-1] + nums[i].first;
        // cout << "a: " << prefix[i] << endl;
        int sum = prefix[i];
        if(sum >= nums[n-1].first) {
            res++;
            ans.push_back(nums[i].second + 1);
            continue;
        }
        for(int j = i + 1; j < n; ++j) {
            if(sum >= nums[j].first) {
                sum += nums[j].first;
            } else {
                break;
            }
        }
        // cout << "b: " << sum << endl;
        if(sum == cur) { res++; ans.push_back(nums[i].second + 1);}
    }
    cout << res << endl;
    sort(ans.begin(), ans.end());
    for(auto t : ans) {
        cout << t << " ";
    }
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    input();
    solve();
    return 0;
}
