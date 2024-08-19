class Solution {
public:
    void bt(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int vis) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis & (1 << i)) continue;
            vis =  vis ^ (1 << i);
            tmp.push_back(nums[i]);
            bt(nums, tmp, res, vis);
            vis =  vis ^ (1 << i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int vis = 0;
        bt(nums, tmp, res, vis);
        return res;
    }
};
View less
