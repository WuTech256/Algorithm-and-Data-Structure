class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = 0; i < prices.size(); ++i) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < prices.size(); ++i) {
            if(mp[i] != 0)
                res.push_back(prices[i] - prices[mp[i]]);
            else 
                res.push_back(prices[i]);
        }
        return res;
    }
};
