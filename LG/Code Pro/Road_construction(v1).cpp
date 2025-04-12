#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> grid;
void input() {
	cin >> n;
	grid.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
}

void solve() {
	queue<pair<int, int>> q;
	vector<vector<int>> dis(n, vector<int> (n, INT_MAX));
	q.push({0, 0});
	dis[0][0] = grid[0][0] - '0';
	vector<int> dr = {-1, 1, 0, 0};
	vector<int> dc = {0, 0, -1, 1};
	
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && dis[nx][ny] > dis[x][y] + (int)(grid[nx][ny] - '0')) {
				dis[nx][ny] = dis[x][y] + (int)(grid[nx][ny] - '0');
				q.push({nx, ny});
			}
		}
	}
	
	cout << dis[n-1][n-1] << endl;
}

int main() {
	input();
	solve();
}
