#include <bits/stdc++.h>
using namespace std;
#define MAXN (100)
int N;
char map[MAXN + 10][MAXN + 10];
vector<string> grid;

char ans;//구매자 이름 Buyer's name
int areacnt;//구매자 영역 개수 Number of buyer's area

void InputData() {
	cin >> N;
	grid.resize(N);
	for (int h = 0; h < N; h++) {
		cin >> grid[h];
	}
}

int bfs(int x, int y, char ch, vector<vector<int>> &vis) {
	queue<pair<int, int>> q;
	int res = 0;
	q.push({x, y});
	vis[x][y] = 1;
	vector<int> dr = {-1, 1, 0, 0};
	vector<int> dc = {0, 0, -1, 1};
	
	while(!q.empty()) {
		auto [a, b] = q.front();
		res++;
		q.pop();
		
		for(int i = 0; i < 4; ++i) {
			int nx = a + dr[i];
			int ny = b + dc[i];
			
			if(nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == ch && !vis[nx][ny]) {
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	return res;
}
void solve() {
	vector<vector<int>> vis(N, vector<int> (N, 0));
	vector<vector<int>> tmp;
	int a = 0, b = 0, c = 0;
	int a1 = 0, b1 = 0, c1 = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(grid[i][j] == 'R' && !vis[i][j]) {
				a += bfs(i, j, 'R', vis);
				a1++;
			} else if(grid[i][j] == 'G' && !vis[i][j]) {
				b += bfs(i, j, 'G', vis);
				b1++;
			} else if(!vis[i][j]) {
				c += bfs(i, j, 'B', vis);
				c1++;
			}
		}
	}
	// cout << a1 << b1 << c1 << endl;
	
	tmp.push_back({a1, a, 1});
	tmp.push_back({b1, b, 2});
	tmp.push_back({c1, c, 3});
	
	sort(tmp.begin(), tmp.end(), [] (vector<int> t, vector<int> o) {
		if(t[0] == o[0]) {
			if(t[1] == o[1]) {
				return t[2] < o[2];
			}
			return t[1] > o[1];
		}
		return t[0] > o[0];
		
	}); 
	
	if(tmp[0][2] == 1) {
		cout << "R" << " " << tmp[0][0];
	} else if(tmp[0][2] == 2) {
		cout << "G" << " " << tmp[0][0];
	} else {
		cout << "B" << " " << tmp[0][0];
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();// 입력받는 부분 Input

	// 여기서부터 작성 Write from here

	solve();
	return 0;
}
