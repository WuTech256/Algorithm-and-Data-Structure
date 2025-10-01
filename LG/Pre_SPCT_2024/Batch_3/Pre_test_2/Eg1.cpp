#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

void input() {
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
}

void solve() {
    int top = 0, bottom = n -1;
    int l = 0, r = m - 1;
    string res;
    while(top <= bottom && l <= r) {
        for(int i = l; i <= r; ++i) {
            res += grid[top][i];
        }
        top++;
        for(int i = top; i <= bottom; ++i) {
            res += grid[i][r];
        }
        r--;
        if(top <= bottom) {
            for(int i = r; i >= l; --i) {
                res += grid[bottom][i];
            }
            bottom--;
        }
        if(l <= r) {
            for(int i = bottom; i >= top; --i) {
                res += grid[i][l];
            }
            l++;
        }
    }
    cout << res << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
