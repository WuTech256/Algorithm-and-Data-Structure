/*
// 숨은 그림을 의미하는 숫자가 2개인 숨은 그림을 찾는 코드

#include <iostream>
using namespace std;

int N; // 풍경화의 크기
int a[10 + 10][10 + 10]; // 풍경화
int X1, X2; // 숨은 그림을 의미하는 2개의 숫자

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };
int Solve(void) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != X1) continue;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
				if (a[ni][nj] != X2) continue;
				count++;
			}
		}
	}
	return count;
}

void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	cin >> X1 >> X2;
}

int main(void) {
	int ans;
	InputData();
	ans = Solve();
	cout << ans;
	return 0;
}
*/

#include <iostream>
using namespace std;

int N; // 풍경화의 크기
int a[10 + 10][10 + 10]; // 풍경화
int X1, X2, X3; // 숨은 그림을 의미하는 3개의 숫자

void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	cin >> X1 >> X2 >> X3;
}

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };

int di1[8] = { 1,1,0,-1,-1,-1,0,1 };
int dj1[8] = { 0,-1,-1,-1,0,1,1,1 };



int Solve(void) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != X2) continue;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				int ni1 = i + di1[k];
				int nj1 = j + dj1[k];
				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
				if (ni1 < 0 || ni1 >= N) continue;
				if (nj1 < 0 || nj1 >= N) continue;
				if (a[ni][nj] != X1) continue;
					if (a[ni1][nj1] != 	X3) continue;
				count++;
			}
		}
	}
	return count;
}

int main(void) {
	int ans = -1;
	InputData(); // 입력

	// 코드 작성

	ans = Solve();
	cout << ans; // 출력
	return 0;
}
