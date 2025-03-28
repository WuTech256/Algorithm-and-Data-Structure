class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int r = grid.size();
        int c = grid[0].size();

        int k = queries.size();
        vector<int> res(k, 0);

        vector<pair<int, int>> idxqueries;
        for (int i = 0; i < k; ++i) {
            idxqueries.push_back({queries[i], i});
        }

        sort(idxqueries.begin(), idxqueries.end());

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        int points = 0;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true; 

        int idx = 0;
        while (idx < k) {
            int currQ = idxqueries[idx].first;


            while (!pq.empty() && pq.top().first < currQ) {
                auto [val, pos] = pq.top();
                pq.pop();

                int x = pos.first, y = pos.second;
                points++;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dr[i];
                    int ny = y + dc[i];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            while (idx < k && idxqueries[idx].first == currQ) {
                res[idxqueries[idx].second] = points;
                idx++;
            }
        }

        return res;
    }
};
