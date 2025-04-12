#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        if(mp[x] == 0) {cout << "OK" << endl; mp[x]++;}
        else if(mp[x] > 0){
            cout << x << mp[x] << endl;
            mp[x]++;
        }
    }
    return 0;
}
