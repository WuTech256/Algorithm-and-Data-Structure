#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
const int mod = 1e9 + 7;
void input() {
    int x;
    while(cin >> x) {
        if(cin.peek() == '\n' && cin.peek() == EOF) break;
        nums.push_back(x);
    }
}

void solve() {
    int n = nums.size();
    vector<int> pre_less(n, -1);
    vector<int> next_less(n, n);
    
    stack<int> st;
    
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            pre_less[i] = st.top();
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        st.pop();
    }
    
    for(int i = n-1; i >= 0; --i) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            next_less[i] = st.top();
        }
        st.push(i);
    }
    
    long long res = 0;
    
    for(int i = 0; i < n; ++i) {
        long long  l = i - pre_less[i];
        long long  r = next_less[i] - i;
        
        res = (res + (nums[i] * l * r)) % mod;
    }
    cout << res << endl;
}

int main() {
    input();
    solve();
} 