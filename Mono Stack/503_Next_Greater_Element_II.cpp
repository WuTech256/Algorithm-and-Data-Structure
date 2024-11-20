class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> tmp = nums;
        tmp.insert(tmp.begin(), nums.begin(), nums.end());
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < tmp.size(); ++i) {
            while(!st.empty() && tmp[st.top()] < tmp[i]) {
                if(mp.find(st.top()) == mp.end()) {
                    mp[st.top()] = tmp[i];
                }
                st.pop();
            }
            st.push(i);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find(i) != mp.end())
                res.push_back(mp[i]);
            else 
                res.push_back(-1);
        }
        return res;
    }
};
