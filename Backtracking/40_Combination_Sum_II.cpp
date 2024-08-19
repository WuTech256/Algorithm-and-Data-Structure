class Solution {
public:
    void bt(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            res.push_back(tmp);
            return;
        }

        for(int i = idx; i < candidates.size(); ++i) {
            if(candidates[i] > target) continue;
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            bt(res, tmp, candidates, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int vis = 0;
        vector<int> tmp;
        int idx = 0;
        sort(candidates.begin(), candidates.end());
        bt(res, tmp, candidates, target, idx);
        return res;
    }
};