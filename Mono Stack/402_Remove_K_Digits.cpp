class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        // If k is equal to the length of num, the result is "0"
        if (n == k) return "0";
        
        stack<char> st;
        
        // Process each digit in the string
        for (int i = 0; i < n; ++i) {
            // Pop from stack if the current digit is smaller than the top of the stack
            // and we still have digits to remove
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        // If k > 0, remove the remaining digits from the stack
        while (k > 0) {
            st.pop();
            k--;
        }
        
        // Build the resulting string from the stack
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        // Reverse the string because stack gives us the result in reverse order
        reverse(res.begin(), res.end());
        
        // Remove leading zeros, if any
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        
        // If the result is empty (i.e., all digits were zeros), return "0"
        if (start == res.size()) {
            return "0";
        }
        
        return res.substr(start);  // Return the result string without leading zeros
    }
};
