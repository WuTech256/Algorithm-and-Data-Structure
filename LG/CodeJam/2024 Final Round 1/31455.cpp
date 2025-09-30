// Cookie Cutting
#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &nums, int x, int y, int n)
{
    if(n == 1) {
        return nums[x][y] - '0';
    }
    
    int sum = 0;
    for(int i = x; i < x + n; ++i) {
        for(int j  = y; j < y + n; ++j) {
            sum += nums[i][j] - '0';
        }
    }
    
    int eaten = sum  % 4;
    int total = 0;
    int half = n/2;
    if(eaten != 0) total += solve(nums, x, y, half);
    if(eaten != 1) total += solve(nums, x, y + half, half);
    if(eaten != 2) total += solve(nums, x + half, y, half);
    if(eaten != 3) total += solve(nums, x + half, y + half, half);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--)  {
        int n;
        cin >> n;
        vector<string> nums;
        nums.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << solve(nums, 0, 0, n) << endl;
    }
}
