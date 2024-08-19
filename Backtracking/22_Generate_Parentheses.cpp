class Solution {
public:
    void bt(vector<string>& res, int& n, int a, int b, string& tmp) {
        if(a == n && b == a) {
            res.push_back(tmp);
            return;
        }

        if(a < n) {
            tmp.push_back('(');
            bt(res, n, a + 1, b, tmp);
            tmp.pop_back();
        }
        if(b < a) {
            tmp.push_back(')');
            bt(res, n, a, b + 1, tmp);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        bt(res, n, 0, 0, tmp);
        return res;
    }
};