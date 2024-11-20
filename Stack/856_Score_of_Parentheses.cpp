class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cur = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                st.push(cur);
                cur = 0;
            } else {
                int last = st.top();
                st.pop();
                cur = last + max(1, 2 * cur);
            }
        }
        return cur;
    }
};
