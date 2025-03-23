class DSU {
public:
    vector<int> link;

    DSU(int n) {
        link.resize(n);
        for(int i = 0; i < n; ++i) {
            link[i] = i;
        }
    }

    int find(int x) {
        if (x != link[x]) {
            link[x] = find(link[x]);
        }
        return link[x];
    }

    int unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            link[rootY] = rootX;
            return 1;
        }
        return 0;
    }
};

class Solution {
public:
    bool check(unordered_map<int, unordered_set<int>> &mp, int k, int i, int j) {
        for (auto t : mp[i]) {
            if (mp[j].find(t) != mp[j].end()) {
                --k;
                if (k <= 0) return true; // Dừng sớm khi đủ số phần tử chung
            }
        }
        return false;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int res = n;
        DSU dsu(n);
        unordered_map<int, unordered_set<int>> mp;

        // Tạo lookup table cho từng node
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < properties[i].size(); ++j) {
                mp[i].insert(properties[i][j]);
            }
        }

        // Kiểm tra và kết nối các node
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(mp, k, i, j)) {
                    res -= dsu.unite(i, j);
                }
            }
        }
        return res;
    }
};
