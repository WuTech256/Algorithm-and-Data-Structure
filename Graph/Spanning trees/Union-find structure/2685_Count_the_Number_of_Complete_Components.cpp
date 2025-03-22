class DSU {
public:
    vector<int> link;
    vector<int> size;

    DSU(int n) {
        link.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; ++i) {
            link[i] = i;
        }
    }

    int find(int x) {
        if( x != link[x] ) 
        {
            link[x] = find(link[x]);
        }
        return link[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            if(size[rootX] < size[rootY]) swap(rootX, rootY);
            link[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> edgeCnt(n, 0);
        for(auto edge : edges)
        {
            dsu.unite(edge[0], edge[1]);
        }

        for(auto edge : edges)
        {
            int root = dsu.find(edge[0]);
            edgeCnt[root]++;
        }

        for(auto a: edgeCnt) {cout << a << endl;}
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            if(root == i) {
                int cnt = dsu.size[i];
                int expectEdge = (cnt * (cnt - 1)) / 2;
                if(expectEdge == edgeCnt[root]) {
                    res++;
                }
            }
        } 
        return res;
    }
};
