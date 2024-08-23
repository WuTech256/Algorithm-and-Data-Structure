class Solution {
public:

    bool check(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool is = false;
        vector<string> all; 
        all.push_back(beginWord);
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                is = true;
            }
            all.push_back(wordList[i]);
        }
        if (!is) return 0;

        int n = all.size();
        vector<vector<int>> nums(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check(all[i], all[j]) && i != j) {
                    nums[i].push_back(j);
                }
            }
        }

        int res = 0;
        queue<int> q;
        vector<int> dis(all.size(), INT_MAX);
        bool found = false;
        dis[0] = 0;
        q.push(0);

        while (!q.empty() && !found) {
            int cur = q.front();
            q.pop();

            for (auto neighbor : nums[cur]) {
                if (dis[neighbor] > dis[cur] + 1) {
                    dis[neighbor] = dis[cur] + 1;
                    q.push(neighbor);

                    if (all[neighbor] == endWord) {
                        res = dis[neighbor] + 1; 
                        found = true;
                        break;
                    }
                }
            }
        }
        return found ? res : 0;
    }
};
