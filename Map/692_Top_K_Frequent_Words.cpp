class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> res;
        for(auto t : words) {
            mp[t]++;
        }
        
        for(auto a : mp) {
            res.push_back(a.first);
        }

        sort(res.begin(), res.end(), [&] (string a, string b) {
            if(mp[a] == mp[b])  
                return a < b;
            return mp[a] > mp[b];
        });
        vector<string> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};
