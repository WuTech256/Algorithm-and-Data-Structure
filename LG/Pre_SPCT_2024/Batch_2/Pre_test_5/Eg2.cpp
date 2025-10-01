#include <bits/stdc++.h>
using namespace std;

int n, m;
long long k;
vector<long long> a;

void input() {
    cin >> n >> m >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = (int)ceil((double)x / k);
    }
}

int main() {
    input();
    int l = 0, r = n-1;
    long long res = 0;
    bool start = true;
    while( m > 0){
        if(start){
            if(a[l] > a[r]){
                res += a[r] * 2;
                a[l] -= a[r];
                r--; m--;
            } else {
                res += a[l] * 2 - 1;
                a[r] = a[r] -  a[l] + 1;
                l++; m--;
                start = false;
            }
        } else {
            if(a[r] > a[l] ){
                res += a[l] * 2;
                a[r] -= a[l];
                l++; m--;
            } else {
                res += a[r] * 2-1;
                a[l] = a[l] -a[r] + 1;
                r--; m--;
                start = true;
            }
        }
    }
    cout << res;
    return 0;
}