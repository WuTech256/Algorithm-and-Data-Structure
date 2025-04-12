#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> nums;
void input() {
	cin >> n >> k;
	nums.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
}

void solve() {
	unordered_map<int, int> mp;
	for(auto t : nums) {
		mp[t]++;
	}
	vector<int> tmp(k);
	int res = INT_MAX;
	iota(tmp.begin(), tmp.end(), 1);
	do {
		int move = 0;
		int cnt = 0;
		int j = 0;
		for(int i = 0; i < nums.size(); ++i) {
			cnt++;

			if(nums[i] != tmp[j])  {
				move++;
				// cout << "move: " << move << endl;
			} 
			if(cnt >= mp[tmp[j]]) {
				j++;
				cnt = 0;
			}
		}
		// cout << move << endl;
		res = min(res, move);
	} while(next_permutation(tmp.begin(), tmp.end()));
	cout << res << endl;
}

int32_t main() {
	input();
	solve();
}
