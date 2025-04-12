#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n;
vector<int> nums;

void input() {
	cin >> n;
	nums.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
}

void solve() {
	int l = 0, r = n - 1;
	int res_i = 0;
	int res_j = n -1;
	int sum = INT_MAX;
	while(l < r) {
		int cur = nums[l] + nums[r];
		if(cur > 0) {
			if(abs(cur) < sum) {
				sum = abs(cur);
				res_i = l;
				res_j = r;
			}
			r--;
		} else if(cur < 0) {
			if(abs(cur) < sum) {
				sum = abs(cur);
				res_i = l;
				res_j = r;
			}
			l++;
		} else {
			res_i = l;
			res_j = r;
			break;
		}
	}
	cout << res_i << " " << res_j << endl;
}

int32_t main() {
	input();
	solve();
}
