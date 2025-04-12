#include <bits/stdc++.h>
using namespace std;

int N; // 행성의 수 Number of planets
// int W[100000 + 10]; // 행성 질량 Mass of planets
vector<int> W;

void InputData(void) {
	cin >> N;
	W.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
}

void solve() {
	int res = 0;
	stack<int> st;
	for(int i = 0; i < N; ++i) {
		while(!st.empty() && st.top() < W[i]) {
			res++;
			st.pop();
		}
		if(!st.empty()) {
			if(W[i] != st.top()) {
				st.push(W[i]);
			}
			res++;
		} else  st.push(W[i]);
	}
	cout << res << endl;
}

int main(void) {
	// int ans = -1;

	InputData(); // 입력 Input

	// 코드를 작성하세요 Write from here
	solve();
	// cout << ans << endl; // 출력 Output

	return 0;
}
