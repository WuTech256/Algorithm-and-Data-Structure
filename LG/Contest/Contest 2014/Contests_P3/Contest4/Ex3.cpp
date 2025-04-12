// Ship Packages
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;

void input() {
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

bool check(int maxSum) {
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sum > maxSum) {
            sum = nums[i];
            cnt++;
            if (cnt > k) return false; 
        }
    }
    return true;
}

int main() {
    input();

    int l = *max_element(nums.begin(), nums.end()); 
    int r = accumulate(nums.begin(), nums.end(), 0); 
    int res = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }

    cout << res << endl;
    return 0;
}
