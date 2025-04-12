#include <bits/stdc++.h>
using namespace std;

int S, E1, E2;
int ans1, ans2;

void InputData()
{
    cin >> S >> E1 >> E2;
}

bool check(int a, int b) {
    auto cnt = [](int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                cnt++;  
                if (i != n / i) cnt++;  
            }
        }
        return cnt;
    };


    int cnt1 = cnt(a);
    int cnt2 = cnt(b);

    return abs(cnt1 - cnt2) <= 1;
}



int bfs(int start, int end) {
    set<int> vis;
    queue<int> q;
    q.push(start);
    vis.insert(start);
    int res = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int cur = q.front();
            q.pop();
            if (cur == end) return res;


            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= 9; ++j) {
                    if (i == 0 && j == 0) continue; 
                    string t = to_string(cur);
                    int a = t[i] - '0';
                    if (a == j) continue; 
                    t[i] = j + '0';
                    int new_num = stoi(t);

                    if (vis.find(new_num) == vis.end() && check(cur, new_num)) {
                        vis.insert(new_num);
                        q.push(new_num);
                    }
                }
            }
        }
        res++;
    }

    return -1; 
}

int main()
{
    InputData(); 


    ans1 = bfs(S, E1);
    ans2 = bfs(S, E2);

    
    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}
