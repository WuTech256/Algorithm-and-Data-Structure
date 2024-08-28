class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        int res = 0;
        for(auto t : reservedSeats) {
            mp[t[0]].push_back(t[1]);
        }

        for(auto m : mp) {
            bool l = true, r = true, mid = true;
            for(int i = 0; i < m.second.size(); ++i) {
                if(m.second[i] == 2 || m.second[i]  == 3) l = false;
                if(m.second[i]  == 8 ||m.second[i]  == 9) r = false;
                if(m.second[i]  == 4 || m.second[i]  == 5) {
                    l = false;
                    mid = false;
                }
                if(m.second[i]  == 6 || m.second[i]  == 7) {
                    r = false;
                    mid = false;
                }
            }
            if(l & r) {
                res += 2;
            } else if(l || mid || r) {
                res += 1;
            }
        }
        res += (n - mp.size()) * 2;
        return res;
    }
};
