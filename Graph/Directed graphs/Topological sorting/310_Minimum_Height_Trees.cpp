class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            ans.clear();
            int s = q.size();
            for(int i = 0; i < s; ++i) {
                int curr = q.front();
                ans.push_back(curr);
                q.pop();

                for(auto nb : graph[curr]) {
                    indegree[nb]--;
                    if(indegree[nb] == 1) {
                        q.push(nb);
                    }
                }
            }
        }
        if(ans.size() == 0) ans.push_back(0);
        return ans;
    }
};
