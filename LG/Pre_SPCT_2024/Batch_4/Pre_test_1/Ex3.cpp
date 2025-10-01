#include <bits/stdc++.h>
using namespace std;

int r, c, f;
vector<string> grid;

void input() {
    cin >> r >> c >> f;
    grid.resize(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }
}

int dis(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

int func(vector<int> v, vector<vector<int>>& f_to_f, vector<vector<int>> s_to_f, int idx) {
    int res =INT_MAX;
       do {
            int dist = 0;
            for(int i = 0; i < v.size() -1; ++i) {
                dist += f_to_f[v[i]][v[i+1]];
            }
            dist += s_to_f[idx][v[0]];
            dist += s_to_f[idx][v[v.size()-1]];
            res = min(res, dist);
        }
        while(next_permutation(v.begin(), v.end()));
    return res;
}

void solve() {
    vector<vector<int>> start;
    vector<vector<int>> flag;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'f') {
                flag.push_back({i, j});
            } else if (grid[i][j] == 's') {
                start.push_back({i, j});
            }
        }
    }

    vector<vector<int>> f_to_f(f, vector<int>(f));
    vector<vector<int>> s_to_f(2, vector<int>(f));

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < f; ++j) {
            f_to_f[i][j] = dis(flag[i][0], flag[i][1], flag[j][0], flag[j][1]);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < f; ++j) {
            s_to_f[i][j] = dis(start[i][0], start[i][1], flag[j][0], flag[j][1]);
        }
    }

    vector<int> nums(f);
    iota(nums.begin(), nums.end(), 0);
    int res = INT_MAX;
    
    int ans1, ans2;
    for(int mask = 0; mask < (1 << f); ++mask) {
        vector<int> tmp1;
        for(int i = 0; i < f; ++i) {
            if(mask & (1 << i)) {
                tmp1.push_back(1);
            }
            else {
                tmp1.push_back(0);
            }
        }
        
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < tmp1.size(); ++i) {
            if(tmp1[i] == 0) {
                v1.push_back(i);
            }
            else v2.push_back(i);
        }
        
        if(v1.size() > 0 && v2.size() > 0) {
            int a = func(v1, f_to_f, s_to_f, 0);
            int b = func(v2, f_to_f, s_to_f, 1);
            // cout << a << " " << b << endl;
            
            if((a + b) < res) {
                res = a+ b;
                ans1 = a;
                ans2 = b;
            } else if((a + b) == res) {
                if(abs(ans1 - ans2) > abs(a - b)) {
                    ans1 = a;
                    ans2 = b;
                }
            }
        }
        
        if(v1.size() == 0) {
            int b = func(v2, f_to_f, s_to_f, 1);
            int a = 0;
            // cout << a << " " << b << endl;
            if((a + b) < res) {
                res = a + b;
                ans1 = a;
                ans2 = b;
            } else if((a + b) == res) {
                if(abs(ans1 - ans2) > abs(a - b)) {
                    ans1 = a;
                    ans2 = b;
                }
            }
        }
        
        if(v2.size() == 0) {
            int a = func(v1, f_to_f, s_to_f, 0);
            int b = 0;
            // cout << a << " " << b << endl;
                    if((a + b) < res) {
                        res = a +  b;
                ans1 = a;
                ans2 = b;
            } else if((a + b) == res) {
                if(abs(ans1 - ans2) > abs(a - b)) {
                    ans1 = a;
                    ans2 = b;
                }
            }
        }
        
        
        
    }
    cout << ans1 + ans2 << " " << abs(ans1 -ans2) << endl;

}

int main() {
    input();
    solve();
    return 0;
}
