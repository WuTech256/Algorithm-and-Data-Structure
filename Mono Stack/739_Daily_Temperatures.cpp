class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                mp[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < n; ++i) {
            if(mp[i] > 0) {
                res.push_back(mp[i]);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};
