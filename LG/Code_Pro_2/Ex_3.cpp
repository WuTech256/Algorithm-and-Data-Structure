#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> nums;

void input() {
	cin >> n >> m;
	nums.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
}


vector<vector<int>> bfs(int x, int y) {
	vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
	
	vector<int> dr = {-1, 1, 0, 0};
	vector<int> dc = {0, 0, -1, 1};
	
	queue<pair<int, int>> q;
	q.push({x, y});
	dist[x][y] = 0;
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && nums[nx][ny] != '*' && dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	return dist;
}

void solve() {
	int size = 0;
	vector<vector<int>> mo;
	pair<int, int> start;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(nums[i][j] == 'S') {
				start.first = i;
				start.second = j;
			}
			
			if(nums[i][j] >= '1' && nums[i][j] <= '9') {
				mo.push_back({i, j});
				size++;
			}
		}
	}
	// cout << "si> " << size << endl;
	int idx = 0;
	vector<vector<int>> mo_to_mo(size);
	vector<int> s_to_mo(size);
	for(auto t : mo) {
		vector<vector<int>> a = bfs(t[0], t[1]);
		s_to_mo[idx] = a[start.first][start.second];
		for(auto g : mo) {
			mo_to_mo[idx].push_back(a[g[0]][g[1]]);
		}
		idx++;
	}
	vector<int> to;
	for(int i = 0; i < size; ++i) {
		to.push_back(i);
	}
	
	int res = INT_MAX;
	do {
		int cur = 0;
		cur += s_to_mo[to[0]];
		cur += s_to_mo[to[size - 1]];
		for(int i = 0; i < size - 1; ++i) {
			cur += mo_to_mo[to[i]][to[i+1]];
		}
		res = min(res, cur);
	}
	while(next_permutation(to.begin(), to.end()));
	cout << res << endl;
}

int main() {
	input();
	solve();
}
