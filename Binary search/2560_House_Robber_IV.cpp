// Ý tưởng của bài này là dùng binary search để tìm 1 giá trị x thỏa mãn các đk như tối thiểu phải cướp k nhà
// Số tiền cướp ở trong dãy nums không vượt quá x
// Từ đó nếu x thỏa mãn thì ta tăng x lên 
class Solution {
public:

    bool check(vector<int> &nums, int mid, int k)
    {
        int cnt = 0; 
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            if(nums[i] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(check(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
