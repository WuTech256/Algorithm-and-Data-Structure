class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> nums;

        for(int i = 0; i < position.size(); ++i) {
            nums.push_back({position[i], speed[i]});
        }
        sort(nums.begin(), nums.end(), [] (vector<int> a, vector<int> b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        stack<vector<int>> st;

        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && st.top()[1] > nums[i][1] && ((double)(target - st.top()[0])/st.top()[1]) <= ((double)(target - nums[i][0])/nums[i][1])) {
                st.pop();    
            }
            st.push(nums[i]);
        }
        return st.size();
    }
};
