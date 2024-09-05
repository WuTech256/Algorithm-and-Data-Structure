class Solution {
public:
    bool canAchieveMaxSize(const std::vector<int>& nums, int maxSize, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > maxSize) {
                // Calculate number of splits needed to make all parts <= maxSize
                operations += (balls - 1) / maxSize; // Equivalent to ceiling division (balls / maxSize)
                if (operations > maxOperations) return false; // Too many operations required
            }
        }
        return true;
    }

    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *std::max_element(nums.begin(), nums.end());
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canAchieveMaxSize(nums, mid, maxOperations)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return res;
    }
};
