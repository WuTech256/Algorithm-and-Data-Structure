#include <bits/stdc++.h>
using namespace std;

string gojo_decode(vector<int> &frag) {
    string res;
    for(int i = 0; i < frag.size(); i += 5) {
        uint8_t b = (frag[i + 4] << 4U) | (frag[i] >> 4U); 
        if(b != 0U)
            res += static_cast<char>(b);
        for(int j = 1; j  < 5; ++j) {
            uint8_t a = (frag[i+j-1] << 4U) | (frag[i+j] >> 4U);
            if(a != 0U)
                res += static_cast<char>(a);
        }
    }
    return res;
} 


int main() {
    int n;
    cin >> n;
    vector<int> nums;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    string s = gojo_decode(nums);
    cout << s << endl;
    
    return 0;
}
