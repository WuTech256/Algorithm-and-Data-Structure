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
	int res = INT_MIN;
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += nums[i];
		res = max(sum, res);
		if(sum < 0) 
			sum = 0;
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}