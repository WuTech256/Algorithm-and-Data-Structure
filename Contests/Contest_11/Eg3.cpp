#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m; // n ~ human, m nofp

vector<int> nums;
set<int> s;

bool check(vector<int> &pos1, int n, int dis) {
    int cnt = 1;
    int prev_pos = pos1[0];
    for(int i = 1; i < pos1.size(); ++i) {
        if(pos1[i] - prev_pos >= dis) {
            cnt++;
            prev_pos = pos1[i];
            
            if(cnt == n)
                return true;
        }
    }
    return false;
}

void input() {
    cin >> n >> m;
    nums.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> nums[i];
        s.insert(nums[i] - 1);
        s.insert(nums[i]);
        s.insert(nums[i] + 1);        
    }
}

int main() {
    input();
    vector<int> pos;
    for(auto t : s) {
        pos.push_back(t);
    }
    
    int l = 1, h = pos[m-1] - pos[0]; 
    
    int res = 0;
    
    while(l <= h) {
        int mid = l + (h - l) / 2;
        
        if(check(pos, n, mid)) {
            res = mid;
            l = mid + 1; 
        } else {
            h = mid - 1; 
        }
    }
    
    cout << res << endl;
    
    return 0;
}
