// Để giải quyết bài này ta nhận thấy phép & có tính chất là giữ nguyên giá trị hoặc làm giảm
// -> Trong 1 thành phần liên thông từ a -> b chăng hạn. Khi nó đi qua tất cả các đỉnh dù lặp đi lặp lại 
// thì chi phí của bài này vẫn là 1 giá trị min khi đi qua hết các đỉnh.
// -> Ta dùng Union Find để cho nó chạy hết 1 thành phần lieenn thông và tìm ra cost min.


class DSU {
public: 
    vector<int> link;
    vector<int> size;
    vector<int> cost;

    DSU(int n) {
        link.resize(n);
        size.resize(n, 1);
        cost.resize(n, INT_MAX);
        for(int i = 0; i < n; ++i) 
        {
            link[i] = i;
        }
    }

    int find(int x) {
        if(link[x] != x) {
            link[x] = find(link[x]);
        } 
        return link[x];
    }

    void unite(int x, int y, int w) {
        int rootX = find(x);
        int rootY = find(y);

        if(size[rootX] < size[rootY]) swap(rootX, rootY);
        link[rootY] = rootX;
        cost[rootX] &= cost[rootY] & w; 
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dsu.unite(u, v, w);
        }

        vector<int> res;
        for(auto q : query) {
            int s = q[0];
            int t = q[1];

            if(dsu.same(s, t)) {
                res.push_back(dsu.cost[dsu.find(s)]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
