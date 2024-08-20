class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string res;
        for(int i = 0; i < n; ++i) {
            if(s[i] != ')') {
                st.push(s[i]);
            } else  {
                string tmp;
                while(st.top() != '(' && !st.empty()) {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto t : tmp) {
                    st.push(t);
                }
            }
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};