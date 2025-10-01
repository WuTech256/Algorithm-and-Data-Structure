#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> x;

void input() {
    cin >> n;
    x.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
}

void solve() {
    vector<int> temp;
    sort(x.begin(), x.end());
    int res = 1;
    int t = x.size();
    temp.push_back(x[0]);
    x.erase(x.begin());
    t = t - 1;
    while(t != 0) {
        auto it = lower_bound(x.begin(), x.end(), temp.size());
        if(it == x.end()) {
            res++;
            temp = {};
            temp.push_back(x.front());
            x.erase(x.begin());
            t = x.size();
        } else {
            temp.push_back(*it);
            x.erase(it);
            t--;
        }
    }
    
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
