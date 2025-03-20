class DSU {
public:
    vector<int> list, size;

    DSU(int n) {
        list.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; ++i) 
        {
            list[i] = i;
        }
    }

    int find(int x) {
        if(list[x] != x) {
            list[x] = find(list[x]);
        }
        return list[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(size[rootX] < size[rootY]) swap(rootX, rootY);
            list[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        DSU dsu(r * c);
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] > 0) {
                    int idx = i * c + j;
                    if(i > 0 && grid[i-1][j] > 0) {
                        dsu.unite(idx, (i-1) * c + j);
                    }

                    if(i < r-1 && grid[i+1][j] > 0) {
                        dsu.unite(idx, (i+1) * c + j);
                    }

                    if(j > 0 && grid[i][j-1] > 0) {
                        dsu.unite(idx, i * c + (j - 1));
                    }

                    if(j < c -1 && grid[i][j+1] > 0) {
                        dsu.unite(idx, i * c + (j+1));
                    }
                }

            }
        }

        unordered_map<int, int> totalFish;
        int res = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] > 0) {
                    int root = dsu.find(i * c + j);
                    totalFish[root] += grid[i][j];
                    res = max(res, totalFish[root]);
                }
            }
        }
        return res;
    }
};
