class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        int n = pattern.size();

        int cnt = 1;
        stack<int> st;

        for(int i = 0; i < n; ++i) {
            st.push(cnt++);
            if(pattern[i] == 'I') {
                while(!st.empty()) {
                    res += st.top() + '0';
                    st.pop();
                }
            }
        }
        st.push(cnt++);
        while(!st.empty()) {
            res += st.top() + '0';
            st.pop();
        }

        return res;
    }
};
