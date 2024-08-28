class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int i = 0;
        stack<int> st;
        while(i < n) {
            while(!st.empty() && st.top() > nums[i]  && n - i - 1 + st.size() >= k) {
                st.pop();
            }
            st.push(nums[i]);
            i++;
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};
