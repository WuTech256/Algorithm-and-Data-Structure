#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> start;
vector<vector<int>> val;
int n;
void input() {
	cin >> n;
	start.resize(2);
	val.resize(n);
	
	for(int i = 0; i < 2; ++i) {
		int x, y;
		cin >> x >> y;
		start[i] = {x, y};
	}
	
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		val[i] = {x, y};
	}
}
int dist(int x, int y, int a, int b) {
	return abs(x - a) + abs(y - b);
}

int func(vector<int> nums, int idx) {
	int res = INT_MAX;
	do {
		int ans=0;
		int cnt = 1;
		for(int i = 0; i < nums.size() - 1; ++i) {
			int x = nums[i];
			int x1 = nums[i+1];
			ans+= dist(val[x][0], val[x][1], val[x1][0], val[x1][1]) * (cnt + 1);
			cnt++;
		}
		ans+= dist(val[nums[0]][0], val[nums[0]][1], start[idx][0], start[idx][1]);
		int size = nums.size() - 1;
		ans+= dist(val[nums[size]][0], val[nums[size]][1], start[idx][0], start[idx][1]) * (cnt + 1);
		res = min(ans, res);
	} while(next_permutation(nums.begin(), nums.end()));
	return res;
}

void solve() {
	int res = INT_MAX;
	for(int mask = 0; mask < (1 << n); mask++) {
		vector<int> a;
		vector<int> b;
		for(int i = 0; i < n; ++i) {
			if(mask & (1 << i)) {
				a.push_back(i);
			} else {
				b.push_back(i);
			}
		}
		int res1 = 0;
		int res2 = 0;
		if(a.size() > 0) res1 = func(a, 0);
		if(b.size() > 0) res2 = func(b, 1);
		res = min(res1 + res2, res);
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
}
