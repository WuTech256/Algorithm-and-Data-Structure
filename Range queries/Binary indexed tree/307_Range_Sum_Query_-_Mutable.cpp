class NumArray {
private:
    vector<int> BIT;
    vector<int> nums;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->n = n;
        this->nums = nums;
        BIT.resize(n+1, 0);

        for(int i = 0; i < n; ++i) {
            add(i+1, nums[i]);
        }
    }
    
    void add(int k, int x) {
        while(k <= n) {
            BIT[k] += x;
            k += k & -k;
        }
    }

    int sum(int k) {
        int s = 0;
        while(k > 0) {
            s += BIT[k];
            k -= k & -k;
        }
    }
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index + 1, diff);
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
