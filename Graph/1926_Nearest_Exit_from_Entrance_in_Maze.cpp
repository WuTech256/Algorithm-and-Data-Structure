class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {

        int n = grid.size();

        int m = grid[0].size();

        // direction co-ordinates

        vector<int> dx = {-1, 0, 1, 0};

        vector<int> dy = {0, 1, 0, -1};

        // declare a queue

        queue<pair<int, int>> q;

        // push the entracnce point into queue

        q.push({entrance[0], entrance[1]});

        int level = 0;

        // mark the entrance cell as visited

        grid[entrance[0]][entrance[1]] = '+';

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto curr = q.front();

                q.pop();

                int i = curr.first;

                int j = curr.second;

                // if exit cell is found return level

                if(!(i == entrance[0] && j == entrance[1]) && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                {
                    return level;
                }

                // push the next level cell into queue which is not visited and don't have wall and mark that cell as visited

                for(int k = 0; k < 4; k++)
                {
                    int new_i = i + dx[k];

                    int new_j = j + dy[k];

                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != '+')
                    {
                        grid[new_i][new_j] = '+';

                        q.push({new_i, new_j});
                    }
                }
            }

            // increment level

            level++;
        }

        return -1;
    }
};