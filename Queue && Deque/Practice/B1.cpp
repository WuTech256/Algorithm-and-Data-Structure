#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> query;

void input() {
    cin >> n;
    cin.ignore();
    query.resize(n);
    for(int i = 0; i < n; ++i) {
        getline(cin, query[i]);
    }
}

void solve() {

    queue<char> q;
    // for(auto t : query) {
    //     cout << t << endl;
    // }
    for(int i = 0; i < n; ++i) {
        if(query[i][0] == 'E') {
            q.push(query[i][2]);
            cout << q.size() << endl;
        } else if(query[i][0] == 'D') {
            if(!q.empty()) {
                cout << q.front() << " ";
                q.pop();
                cout << q.size() << endl;
            } else {
                cout << "-1 0" << endl;
            }
        }
    }
}

int main() {
    input();
    solve();
}
