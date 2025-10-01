#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> b;
void input() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
}

int solve(vector<vector<int>> &nums) {
    sort(nums.begin(), nums.end(), [] (vector<int> n1, vector<int> n2) {
       return n1[1] - n1[0] > n2[1] - n2[0]; 
    });
    int res = 0;
    int saved = 0;
    for(int i = 0; i < n; ++i) {
        if(saved < nums[i][1]) {
            res += nums[i][1] - saved;
            saved = nums[i][1] - nums[i][0];
        } else {
            saved = saved - nums[i][0];
        }
    }
    return res;
}


int main() {
    input();
    vector<vector<int>> nums(n, vector<int> (2));
    for(int i = 0; i < n; ++i) {
        nums[i][0] = a[i];
        nums[i][1] = b[i];
    }
    cout << solve(nums) << endl;
}