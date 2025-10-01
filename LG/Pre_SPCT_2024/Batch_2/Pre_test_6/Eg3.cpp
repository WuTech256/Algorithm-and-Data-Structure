#include<bits/stdc++.h>

using namespace std;

void test_case() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> data;
    int cnt = 0; // cnt = 1 ->4 cnt = cnt * 10 + 4
    for(auto& x : s) {
        if('0' <= x && x <= '9') {
            cnt = 10 * cnt + (x - '0');
        } 
        else {
            data.push_back({cnt, x - 'a' + 1});
            cnt = 0;
        }
    }
    if(data.size() % 2)
        data.push_back({0, 0});
    int res = 0;
    // bit 10 -> 1 (res |= (1 << 10))
    vector<int> good(32, 1);
    for(int i = 0; i < 10; ++i) {
        int bit = ((n % 32) + i) % 32;
        res |= (1 << bit);
        good[bit] = 0;
    }
    // res -> 0000111111111100000000...
    
    for(int i = 0; i < data.size(); i += 2) {
        int tmp = (data[i].first << 16) | (data[i].second << 11) | (data[i+1].first << 5) | (data[i+1].second);
        int d = res;
        int j = 0;
        for(int k = 0; k < 32; ++k) {
            if(good[k]) {
                // tmp 0011000 1000 - > 1000
                int bit = (tmp & (1 << j)) > 0;
                d |= (bit << k);
                ++j;
            }
        }
        assert(j == 22);
        cout << d << " ";
    }
}
int main() {
    test_case();
    return 0;
}
