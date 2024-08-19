class Solution {
public:

    void bt(vector<int> tmp, vector<vector<int>> &res, vector<int> nums, vector<bool> &vis) {
        if(tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])) {
                continue;
            }
            vis[i] = true;
            tmp.push_back(nums[i]);
            bt(tmp, res, nums, vis);
            tmp.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> vis(n, false);
        vector<int> tmp;
        bt(tmp, res, nums, vis);
        return res;
    }
};