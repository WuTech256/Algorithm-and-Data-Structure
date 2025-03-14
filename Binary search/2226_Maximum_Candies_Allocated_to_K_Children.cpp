#define ll long long
class Solution {
public:
    bool check(ll num, vector<int> &candies, long long k)
    {
        ll cnt = 0;
        for(ll i = 0; i < candies.size(); ++i) {
            ll tmp = (ll) (floor((float)(candies[i]/num)));
            cnt += tmp;
            if(cnt >= k) return true;
        }
        return false;
    }
    ll maximumCandies(vector<int>& candies, long long k) {
        ll l = 1;
        ll r = *max_element(candies.begin(), candies.end());

        ll res = 0;
        while(l <= r) {
            ll mid = l + (r-l)/2;
            if(check(mid, candies, k)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
