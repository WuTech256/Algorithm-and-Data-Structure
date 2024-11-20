#include<bits/stdc++.h>
#define int long long
using namespace std;


// 1. Gen het tat ca truong hop phep toan OK
// 2. Tinh ket qua phep toan
// 3. Check ket qua co phai so dac biet khong


vector<string> all;
void backtrack(string& cur, const string& s, int i) {
    if(i == (int)s.size()) {
        all.push_back(cur);
        return;
    }
    // them dau cong
    cur += '+';
    cur += s[i];
    backtrack(cur, s, i + 1);
    cur.pop_back();
    cur.pop_back();
    
    // them dau tru
    cur += '-';
    cur += s[i];
    backtrack(cur, s, i + 1);
    cur.pop_back();
    cur.pop_back();
    
    // khong lam gi
    cur += s[i];
    backtrack(cur, s, i + 1);
    cur.pop_back();
}
int cal(const string& s) {
    int res = 0;
    int cur = 0;
    int sign = 1;
    for(int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '+') {
            res += cur * sign;
            cur = 0;
            sign = 1;
        } else if(s[i] == '-') {
            res += cur * sign;
            cur = 0;
            sign = -1;
        } else {
            cur = cur * 10 + (s[i] - '0');
        }
    }
    return res + sign * cur;
}
bool is_special(int x, vector<int>& f) {
    vector<int> fre(10);
    string s = to_string(abs(x));
    for(auto& i : s) {
        fre[i-'0']++;
    }
    for(int i = 0; i < 10; ++i) {
        if(f[i] == -1)
            continue;
        if(f[i] != fre[i])
            return false;
    }
    return true;
}
void test_case() {
    string s;
    cin >> s;
    vector<int> f(10);
    for(auto& x : f) cin >> x;
    string cur = string(1, s[0]);
    all.clear();
    backtrack(cur, s, 1);
    int res = 0;
    for(auto& x : all)
    {
        int val = cal(x);
        if(is_special(val, f))
            ++res;
    }
    cout << res << endl;
    
}
int32_t main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        test_case();
    return 0;
}
