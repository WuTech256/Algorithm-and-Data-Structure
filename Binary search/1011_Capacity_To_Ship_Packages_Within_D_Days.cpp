class Solution {
public:
    bool check(int k, vector<int> &weights, int days) {
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); ++i) {
            sum += weights[i];
            if(sum > k) { 
                sum = weights[i];
                cnt++;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(check(mid, weights, days)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
