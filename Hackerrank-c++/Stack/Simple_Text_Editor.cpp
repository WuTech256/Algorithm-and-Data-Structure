#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> nums;

void input() {
    cin >> n;
    cin.ignore();  

    nums.resize(n);

    for (int i = 0; i < n; ++i) {
        getline(cin, nums[i]);
    }
}

void solve() {
    string tmp;
    stack<string> st;

    for (auto& s : nums) {
        int size = tmp.size(); 
        if (s[0] == '1') {
            string a = s.substr(2);
            tmp += a;
            st.push(tmp);
        } else if (s[0] == '2') {
            string a = s.substr(2);
            int cur = stoi(a);
            if (cur >= 0 && cur <= size) {
                tmp = tmp.substr(0, size - cur);
            } else {
                tmp = "";
            }
            st.push(tmp);
        } else if (s[0] == '3') {
            string a = s.substr(2);
            int cur = stoi(a);
            if (cur >= 1 && cur <= size) {
                cout << tmp[cur - 1] << endl;
            }
        } else if (s[0] == '4') {
            if (!st.empty()) {
                st.pop();
                if (!st.empty()) {
                    tmp = st.top(); 
                } else {
                    tmp.clear(); 
                }
            }
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}
