#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n;
vector<string> grid;

void input() {
	cin >> n;
	grid.clear();
	grid.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
}

void solve() {
	int res = 0;
	vector<int> vis(10, 0);
	vector<int> check(10, 1);
	for(int c = 1; c < 10; ++c) {
		int min_i = 10, min_j = 10, max_i = -1, max_j = -1;
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; j++) {
				if((grid[i][j] - '0') == c) {
					vis[c] = 1;
					min_i = min(min_i, i);
					min_j = min(min_j, j);	
					max_i = max(max_i, i);
					max_j = max(max_j, j);
				}
			}
		}
		
		for(int i = min_i; i <= max_i; ++i) {
			for(int j = min_j; j <= max_j; ++j) {
				if((grid[i][j] - '0') != c) {
					check[grid[i][j] - '0'] = 0;
				}
			}
		} 
		
	}
	
	for(int c = 1; c < 10; ++c) {
		if(vis[c] == 1 && check[c] == 1) res++;
	}
	
	cout << res << endl;
}

int32_t main() {
	input();
	solve();
	return 0;
}