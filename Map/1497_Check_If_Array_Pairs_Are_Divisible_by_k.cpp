class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        cout << "n: " << n << endl;
        if(n % 2 == 1) return false;
        for(int i = 0; i < n; ++i) {
            int cur = arr[i];
            cur = ((cur % k) + k)%k;
            mp[cur]++;
        }

        for(auto t : mp) {
            if(t.first == 0) continue;
            if(mp[k - t.first] != t.second) {
                return false;
            }
        }
        if(mp[0] % 2  == 1) return false;
        return true;
    }
};
