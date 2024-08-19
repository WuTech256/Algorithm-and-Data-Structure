#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int k, vector<int> &piles, int h) {
        long long cnt = 0;
        for(int i = 0; i < piles.size(); ++i) {
            if(piles[i] <= k) cnt++;
            else {
                double cur = (double)piles[i]/k;
                int t = ceil(cur);
                cnt += t;
            }
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int res = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(check(mid, piles, h)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};

int main() {

}