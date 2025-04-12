#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int d, sumTime;
    cin >> d >> sumTime;
    
    vector<int> minTime(d), maxTime(d), schedule(d);
    int minTotal = 0, maxTotal = 0;
    for(int i = 0; i < d; ++i) {
        cin >> minTime[i] >> maxTime[i];
        minTotal += minTime[i];
        maxTotal += maxTime[i];
        schedule[i] = minTime[i];
    }
    
    if(sumTime < minTotal || sumTime > maxTotal) {
        cout << "NO" << endl;
        return 0;
    }
    
    int remaining = sumTime - minTotal;
    
    for(int i = 0; i < d && remaining > 0; ++i)
    {
        int increase = min(remaining, maxTime[i] - minTime[i]);
        schedule[i] += increase;
        remaining -= increase;
    }
    
    cout << "YES" << endl;
    for(int i=0; i<d; ++i)
    {
        cout << schedule[i] << " ";
    }
    cout << endl;
    return 0;
}
