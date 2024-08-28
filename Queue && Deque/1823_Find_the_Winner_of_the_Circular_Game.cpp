class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> q;
        for(int i = 1; i <= n; ++i) {
            q.push_back(i);
        }

        while(q.size() != 1) {
            for(int i = 0; i < k - 1; ++i) {
                q.push_back(q.front());
                q.pop_front();
            }
            q.pop_front();
        }
        return q.front();
    }
};
