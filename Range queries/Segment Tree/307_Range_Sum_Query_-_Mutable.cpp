// 307. Range Sum Query - Mutable

class NumArray {
private:
    vector<int> segTree;
    vector<int> nums;
    int n;

    void build(int index, int left, int right) {
        if(left == right) {
            segTree[index] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        build(2 * index + 1, left, mid);
        build(2 * index + 2, mid + 1, right);

        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void updateTree(int index, int left, int right, int pos, int val) {
        if(left == right) {
            segTree[index] = val;
            return;
        }

        int mid = (left + right)/2;
        if(pos <= mid)
            updateTree(2 * index  + 1, left, mid, pos, val);
        else 
            updateTree(2 * index + 2, mid + 1, right, pos, val);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    int query(int index, int left, int right, int ql, int qr) {
        if(ql > right || qr < left) return 0;
        if(ql <= left && qr >= right) return segTree[index];
        int mid = (left + right) / 2;
        return query(2 * index  + 1, left, mid, ql, qr) +
                query(2 * index + 2, mid + 1, right, ql, qr);
    }
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        n = nums.size();
        if(n == 0) return;
        segTree.resize(4 * n, 0);
        build(0, 0 , n - 1);
    }
    
    void update(int index, int val) {
        if(n == 0) return;
        nums[index] = val;
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if(n == 0) return 0;
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
