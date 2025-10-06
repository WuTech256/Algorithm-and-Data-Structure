// Operations on Array of Integers

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef struct {
    char cmd;
    int st;
    int en;
} Operation;

ll reverseCheck(vector<Operation>& ops, int pos) {
    ll value = 0;
    for(auto op = ops.rbegin(); op != ops.rend(); ++op) {
        if(op -> cmd == 'a') value += pos;
        if(op -> cmd == 'r') {
            if(op -> st <= pos && pos <= op->en) {
                pos = op->st + op->en - pos;
            }
        }
    }
    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Operation> ops;
    int n, q, m;
    cin >> n >> q >> m;
    
    for(int i = 0; i < q; ++i) {
        char cmd;
        cin >> cmd;
        int st, en;
        if(cmd == 'a') {
            ops.push_back({cmd, 0, 0});
        } else if(cmd == 'r') {
            cin >> st >> en;
            ops.push_back({cmd, st, en});
        }
    }
    
    for(int i = 0; i < m; ++i) {
        cin >> n;
        cout << reverseCheck(ops, n) << endl;
    }
    return 0;
}
