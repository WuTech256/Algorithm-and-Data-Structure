class NumArray {
public:
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            prefix_sum[i+1] = nums[i] + prefix_sum[i]; 
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
