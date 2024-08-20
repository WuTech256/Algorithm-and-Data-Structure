class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, r = 0;
        stack<char> st;

        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                l++;
            } else if(s[i] == ')') {
                r++;
            }

            if(r > l) {
                r--;
                continue;
            } else {
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()) {
            char cur = st.top();
            st.pop();
            if(l > r && cur == '(') {
                l--;
            } else {
                res += cur;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};