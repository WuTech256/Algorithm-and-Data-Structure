#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pos;
vector<int> speech;
void input() {
    cin >> n;
    pos.resize(n);
    speech.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> pos[i] >> speech[i];
    }
}

void solve() {
    stack<pair<int, int>> st;
    for(int i = 0; i < speech.size(); ++i) {
        while(!st.empty() && st.top().first > speech[i]){
            st.pop();
        }
        st.push({speech[i], i + 1});
    }
    
    int number_of_teams = st.size();
    
    vector<int> tmp;
    while(!st.empty()) {
        tmp.push_back(st.top().second);
        st.pop();
    }
    reverse(tmp.begin(), tmp.end());
    vector<int> tmp2;
    tmp2.push_back(0);
    for(auto t : tmp){
        tmp2.push_back(t);
    }
    
    // for(auto t : tmp2) {
    //     cout << t << endl;
    // }
    // cout << " ok " << endl;
    vector<int> nums;
    for(int i = 0; i < tmp2.size() -1; ++i) {
        nums.push_back(tmp2[i + 1] - tmp2[i]);
    }
    // for(auto t : nums) {
    //     cout << t << endl;
    // }
    
    int max_i = *max_element(nums.begin(), nums.end());
    int min_i = *min_element(nums.begin(), nums.end());
    cout << number_of_teams << " " << max_i << " " << min_i << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}