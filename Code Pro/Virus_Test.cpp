#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;

void input() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
}

bool check(int idx) {
	vector<int> tmp;
	for(int i = idx; i < idx + m; ++i) {
		tmp.push_back(a[i]);
	}
	sort(tmp.begin(), tmp.end());
	for(int i = 0; i < m - 1; ++i) {
		if(tmp[i] - b[i] !=  tmp[i + 1] - b[i+1]) return false;
	}
	return true;
}

void solve() {
	sort(b.begin(), b.end());
	int res = 0;
	for(int i = 0; i < n - m + 1; ++i) {
		if(check(i))
			res++;
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}