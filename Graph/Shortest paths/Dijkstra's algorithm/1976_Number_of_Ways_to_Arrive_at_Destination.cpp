#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto road : roads) 
        {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        vector<ll> dist(n , LLONG_MAX);
        vector<int> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, 0});

        const int MOD = 1e9 + 7;

        while(!pq.empty()) 
        {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;
            for(auto [nb, time] : graph[node])
            {
                if(dist[node] + time < dist[nb])
                {
                    dist[nb] = dist[node] + time;
                    cnt[nb] = cnt[node];
                    pq.push({dist[nb], nb});
                } else if(dist[node] + time == dist[nb]) {
                    cnt[nb] = (cnt[nb] + cnt[node]) % MOD; 
                }

            }
        }
        return cnt[n-1];
    }
};
