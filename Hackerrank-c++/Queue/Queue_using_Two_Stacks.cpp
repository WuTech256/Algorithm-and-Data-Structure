#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> nums;
void input() {
    cin >> n;
    cin.ignore();
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        getline(cin, nums[i]);
    }
}

void solve() {
    queue<int> q;
    for(auto num : nums) {
        if(num[0] == '1') {
            string cur = num.substr(2);
            int a = stoi(cur);
            q.push(a);
        } else if(num[0] == '2') {
            if(!q.empty()) {
                q.pop();
            }
        } else {
            if(!q.empty()) {
                cout << q.front() << endl;
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();  
    return 0;
}
