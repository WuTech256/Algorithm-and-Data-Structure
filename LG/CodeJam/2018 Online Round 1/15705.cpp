#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int r, c;
    cin >> r >> c;
    vector<string> table(r);
    for(int i = 0; i < r; ++i) {
        cin >> table[i];
    }
    
    vector<int> dr = {-1, 1, 0, 0, 1, -1, -1, 1};
    vector<int> dc = {0, 0, -1, 1, 1, -1, 1, -1};
    bool found = false;
    int len = s.length();
    
    for(int i = 0; i < r && !found; ++i) {
        for(int j = 0; j < c && !found; ++j) {
            if(table[i][j] == s[0]) {
                for(int d = 0; d < 8 && !found; ++d) {
                    int k;
                    for(k = 0; k < len; ++k) {
                        int nx = i + dr[d] * k;
                        int ny = j + dc[d] * k;

                        if(nx < 0 || nx >= r || ny < 0 || ny >= c || table[nx][ny] != s[k])
                            break;
                    }
                    if(k == len) found = true;
                } 
            }
        }
    } 
    cout << (found ? 1 : 0) << endl;
}
