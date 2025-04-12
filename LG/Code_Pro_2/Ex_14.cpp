#include <bits/stdc++.h>
using namespace std;

int N; // 이동 정보의 개수
string Info; // 이동 방향 정보
int sol = -1;

void InputData(void) {
	cin >> N;
	cin >> Info;
}


vector<vector<int>> di = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int &a, int xi, int yj) {
	
	int r = grid.size();
	int c = grid[0].size();
	if(xi == 0 || yj == 0 || xi == r - 1 || yj == c - 1) a = 0;
	queue<pair<int, int>> q;
	q.push({xi, yj});
	vis[xi][yj] = 1;
	vector<int> dr = {-1, 1, 0, 0};
	vector<int> dc = {0, 0, -1, 1};
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0 && !vis[nx][ny]) {
				if(nx == 0 || ny == 0 || nx == r - 1 || ny == c - 1) a = 0;
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
}

void solve() {
	int res = 0;
	pair<int, int> start = {0, 0};
	int min_i = INT_MAX;
	int min_j = INT_MAX;
	int max_i = INT_MIN;
	int max_j = INT_MIN;
	set<pair<int, int>> s;
	s.insert({start.first, start.second});
	pair<int, int> start2 = start;
	for(int i = 0; i < N; ++i) {
		int cur = Info[i] - '0';
		
		if(cur == 0) {
			pair<int, int> tmp = start;
			start.first = start.first + di[cur][0] * 2;
			start.second = start.second + di[cur][1] * 2;
			start2.first = tmp.first + di[cur][0] * 2;
			start2.second = tmp.second + di[cur][1] * 2 - 1;
		}
		if(cur == 1) {
			pair<int, int> tmp = start;
			start.first = start.first + di[cur][0] * 2;
			start.second = start.second + di[cur][1] * 2;
			start2.first = tmp.first + di[cur][0] * 2;
			start2.second = tmp.second + di[cur][1] * 2 + 1;
		} 
		
		if(cur == 2) {
			pair<int, int> tmp = start;
			start.first = start.first + di[cur][0] * 2;
			start.second = start.second + di[cur][1] * 2;
			start2.first = tmp.first + di[cur][0] * 2 - 1;
			start2.second = tmp.second + di[cur][1] * 2;
		}
		
		if(cur == 3) {
			pair<int, int> tmp = start;
			start.first = start.first + di[cur][0] * 2;
			start.second = start.second + di[cur][1] * 2;
			start2.first = tmp.first + (di[cur][0] * 2) + 1;
			start2.second = tmp.second + di[cur][1] * 2;
			
		}
		
		
		min_i = min(min_i, start.first);
		min_i = min(min_i, start2.first);
		min_j = min(min_j, start.second);
		min_j = min(min_j, start2.second);
		
		max_i = max(max_i, start.first);
		max_i = max(max_i, start2.first);
		max_j = max(max_j, start.second);
		max_j = max(max_j, start2.second);
		s.insert({start.first, start.second});
		s.insert({start2.first, start2.second});
	}
	int a = 0;
	int b = 0;
	
	if(min_i < 0) a = abs(min_i);
	if(min_j < 0) b = abs(min_j);
	int r=a+ max_i;
	int c=b+ max_j;
	
	vector<vector<int>> grid(r+1, vector<int> (c+1, 0));
	// 	cout << r << c << endl;
	// cout << a << b << endl;
	
	
	for(auto t : s) {
		grid[t.first + a][t.second + b] = 1;
	}
	
	// for(auto t : grid) {
	// 	for(auto g: t) {
	// 		cout << g << " ";
	// 	}
	// 	cout << endl;
	// }
	vector<vector<int>> vis(r+1, vector<int> (c+1, 0));
	for(int i = 0; i < r + 1; ++i) {
		for(int j = 0; j < c + 1; ++j) {
			int t = 1;
			if(!vis[i][j] && grid[i][j] == 0) {
				bfs(grid, vis, t, i, j);
				res += t;
			}
		}
	}
	cout << res << endl;
}
int main(void) {
	//입력받는 부분
	InputData();
	solve();
	//코드를 작성하시오

	//출력하는 부분
	// cout << sol << "\n";
	return 0;
}
