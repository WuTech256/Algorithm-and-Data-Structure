// Để khi & mà > 0 thì cần ít nhất 1 bit = 1 ở kết quá;
// Điều này ứng với việc giao ở bit i không được có giá trị 0 thì sẽ thỏa mãn bit i ở kết quá là 1 và > 0
// vì 10 ^ 7 nên tối đa 24 bit
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int res = 0;
        for(int i = 0; i < 24; ++i) {
            int tmp = 0;
            for(auto t : candidates) {
                if((t & (1 << i)) > 0) {
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
