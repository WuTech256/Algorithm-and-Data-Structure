class Solution {
public:
    struct compare {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            if(a[1] == b[1])
                return a[2] > b[2];
            return a[1] > b[1];
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // ưu tiên lấy time nhỏ hơn (ngược lại với sort), và nếu thời gian == thì lấy idx
        priority_queue<vector<int>, vector<vector<int>>, compare> q;
        vector<int> res;

        vector<vector<int>> nums;
        for(int i = 0; i < n; ++i) {
            nums.push_back({tasks[i][0], tasks[i][1], i});
        }
        // available thằng đến sớm trước và nếu == thì ưu tiên thời gian xử lý thấp -> 
        sort(nums.begin(), nums.end(), [] (vector<int> a, vector<int> b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        long long cur = 0;
        int j = 0;
        // thực hiện đến khi q rỗng và hết task
        while(!q.empty() || j < n) {
            if(!q.empty()) {
                auto g = q.top(); 
                q.pop();
                res.push_back(g[2]);
                cur += g[1];
                while(j < n && nums[j][0] <= cur) {
                    q.push(nums[j]);
                    j++;
                }
            } else {
                if(j < n) {
                    cur = nums[j][0];
                    q.push(nums[j]);
                    j++;
                }
            }
        }
        return res;
    }
};
