// Mini BINGO
#include <bits/stdc++.h>
using namespace std;

string compute_T(const string& order, vector<int>& pos) {
    bool colored[9]= {false};
    string tmp;
    tmp.reserve(9);
    
    for(char ch : order) {
        int p = pos[ch - 'A'];
        colored[p] = true;
        
        int score = 0;
        
        int r = p/3;
        if(colored[r*3] && colored[r*3 + 1] && colored[r*3+2]) score++;
        
        int c = p % 3;
        if(colored[c] && colored[c + 3] && colored[c + 6]) score++;
        
        if(p == 0 || p == 4 || p == 8) {
            if(colored[0] && colored[4] && colored[8]) score++;
        }
        
        if(p == 2 || p == 4 || p == 6) {
            if(colored[2] && colored[4] && colored[6]) score++;
        }
        tmp.push_back(score + '0');
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        vector<string> grid(3);
        for(int i = 0; i < 3; ++i) cin >> grid[i];
        
        vector<int> pos(26, -1);
        string letters;
        
        for(int r = 0; r < 3; ++r) {
            for(int c = 0; c < 3; ++c) {
                char ch = grid[r][c];
                pos[ch - 'A'] = r*3+c;
                letters.push_back(ch);
            }
        }
        
        string targetT = compute_T(s, pos);
        sort(letters.begin(), letters.end());
        
        string best = "";
        do {
            string cand = compute_T(letters, pos);
            if(cand == targetT) {
                best = letters;
                break;
            }
        } while(next_permutation(letters.begin(), letters.end()));
        cout << targetT << " " << best << endl;
    }
    return 0;
}
