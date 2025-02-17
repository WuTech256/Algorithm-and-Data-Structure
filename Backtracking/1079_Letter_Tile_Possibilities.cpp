class Solution {
public:
    unordered_set<string> st;

    void bt(string tmp, string &tiles, vector<bool> &vis, const int &n) {
        if(!tmp.empty()) {
            st.insert(tmp);
            // return;
        }

        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                vis[i] = true;
                bt(tmp+tiles[i], tiles, vis, n);
                vis[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> vis(n, false);
        string tmp = "";
        bt(tmp, tiles, vis, n);
        return st.size();
    }
};
