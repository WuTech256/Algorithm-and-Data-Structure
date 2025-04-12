#include <bits/stdc++.h>
using namespace std;

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
	int res  = INT_MIN;
	vector<int> dp_end_sub(n, 0);
	vector<int> dp_end_add(n, 0);
	dp_end_sub[0] = 0;
	dp_end_add[0] = max(nums[0], nums[1]);
	
	for(int i = 1; i < n; ++i) {
		dp_end_add[i] = max(dp_end_add[i - 1], dp_end_sub[i - 1] + nums[i]);
		// cout << "add: " << dp_end_add[i] << endl;
		dp_end_sub[i] = max(dp_end_sub[i - 1], dp_end_add[i-1] - nums[i]);
		// cout << "sub: " << dp_end_sub[i] << endl;
		int cur = max(dp_end_add[i], dp_end_sub[i]);
		res = max(res, cur);
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}