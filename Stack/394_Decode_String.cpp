class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string res;
        stack<char> st;
        for(int i = 0; i < n; ++i) {
            if(s[i] != ']') {
                st.push(s[i]);
            } else {
                string tmp;
                while(!st.empty() && st.top() != '[') {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(tmp.begin(), tmp.end());
                string a;
                while(!st.empty() && isdigit(st.top())) {
                    a += st.top();
                    st.pop();
                }
                reverse(a.begin(), a.end());
                int k = stoi(a);
                for(int j = 0; j < k; ++j) {
                    for(int i = 0; i < tmp.size(); ++i) {
                        st.push(tmp[i]);
                    }
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
