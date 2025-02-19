class Solution {
public:
    void bt(string tmp, int n, vector<string>& res, int idx, string& patterns) {
        if (tmp.size() == n) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < 3; ++i) {
            if (i != idx) {
                bt(tmp + patterns[i], n, res, i, patterns);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        string patterns = "abc";
        bt("", n, res, -1, patterns);

        if (k > res.size()) return "";
        return res[k - 1];
    }
};
