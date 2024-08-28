class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = 0; i < nums2.size(); ++i) {
            while(!st.empty() && st.top() < nums2[i]) {
                mp[st.top()] = nums2[i];
                st.pop();
            }  
            st.push(nums2[i]);
        }

        vector<int> res;
        for(int i = 0; i < nums1.size(); ++i) {
            if(mp[nums1[i]] != 0)
                res.push_back(mp[nums1[i]]);
            else 
                res.push_back(-1);
        }
        return res;
    }
};
