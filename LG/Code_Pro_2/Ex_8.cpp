#include <bits/stdc++.h>
using namespace std;

int N;//선수의 인원수 number of playersnumber of players
long long T;//시간 time
// long long P[100000 + 10];//선수 초기 위치 player initial position
// long long S[100000 + 10];//선수 속도 player speed

vector<long long> P;
vector<long long> S;
int group_first[100000 + 10];//각 그룹의 선두선수 leader of each group


void InputData() {
	cin >> N >> T;
	P.resize(N);
	S.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i] >> S[i];
	}
}

void solve() {
	stack<int> st;
	
	for(int i = 0; i < N; ++i) {
		while(!st.empty() && S[st.top()] > S[i] && P[st.top()] + T * S[st.top()] >= S[i] * T + P[i]) {
			st.pop();
		}
		st.push(i);
	}
	
	cout << st.size() << endl;
	vector<int> tmp;
	while(!st.empty()) {
		tmp.push_back(st.top());
		st.pop();
	}
	
	for(auto t : tmp) {
		cout << t + 1 << " ";
	}
}

int main() {
	// int ans = -1;
	InputData();//입력 Input
	solve();
	//코드를 작성하세요 Write the code

	//출력 Output
	// cout << ans << endl;
	// for (int i = 0; i < ans; i++) cout << group_first[i] << " ";
	return 0;
}
