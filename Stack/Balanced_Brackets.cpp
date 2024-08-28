#include <bits/stdc++.h>

using namespace std;

int T;

bool solve(string s) {
    stack<char> st;
    if(s[0] == ')' || s[0] == ']' || s[0] == '}') {
        return false;
    }
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if(!st.empty() && s[i] == ')' && st.top() != '(')
                return false;
            else if (!st.empty() && s[i] == ']' && st.top() != '[') 
                return false;
            else if (!st.empty() && s[i] == '}' && st.top() != '{') 
                return false;
            else if(!st.empty())
                st.pop();
        } else {
            st.push(s[i]);
        }
    }
    if(st.size() == 0)
        return true;
    return false;
}


int main() {
    cin >> T;
    while(T--) {
        string s; 
        cin >> s;
        if(solve(s)) cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}
