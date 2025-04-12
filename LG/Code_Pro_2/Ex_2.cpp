#include <bits/stdc++.h>
using namespace std;

int N; // 상자의 크기
// int Box[150][150];
vector<vector<int>> nums;
int sum = 0;
void InputData() {
	cin >> N;
	nums.resize(N);
	for (int i = 0; i < N; i++) {
		nums[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> nums[i][j];
			sum += nums[i][j];
		}
	}
}


void solve() {
	int max_1 = INT_MIN;
	int max_2 = INT_MIN;
	for(int row = 0; row < N; row++) {
		int cur = 0;
		int cur1 = 0;
		for(int col = 0; col < N; col++) {
			cur += nums[row][col];
			cur1 += nums[col][row];
		}
		max_1 = max(max_1, cur);
		max_2 = max(max_2, cur1);
	}
	int gg = max(max_1, max_2) * N;
	cout << gg - sum << endl;
}
int main() {
	// int ans = -1;
	InputData(); // 입력 받는 부분
	solve();
	// // 여기서부터 작성
	
	// cout << ans << endl;// 출력하는 부분
	return 0;
}
