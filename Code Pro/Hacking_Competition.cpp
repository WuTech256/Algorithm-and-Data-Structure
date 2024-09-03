#include <bits/stdc++.h>
using namespace std;

string str;
string cmd_str;

void input() {
	cin >> str;
	cin >> cmd_str;
}

void solve() {
	int n = str.size();
	int cursor = n;
	for(auto c : cmd_str) {
		switch(c) {
			case 'L': {
				if(cursor > 0) {
					--cursor;
				}
				break;
			}
			case 'R': {
				if(cursor < n) {
					cursor++;
				}
				break;
			}
			case 'B': {
				if(cursor > 0) {
					--cursor;
					str.erase(cursor, 1);
				}
				break;
			}
			default:
				if(c >= 'a' && c <= 'z') {
					str.insert(cursor, 1, c);
					++cursor;
				}
				break;
		}
		cout << str << endl;
	}
	cout << str << endl;
}

int main() {
	input();
	solve();
}
