// Solar Charging

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;
vector<int> P, D;
vector<ll> F;
vector<vector<ll>> dp;
int N, B, C;

ll solve(int day, int charge) {
    if(day == N) {
        return charge >= B ? 0 : INF;
    }
    if(dp[day][charge] != -1) return dp[day][charge];
    ll res = INF;

    if(charge >= D[day]) {
        res = min(res, solve(day+1, charge - D[day]));
    }

    ll pay = (ll)F[day] * D[day];
    ll charge2 = min(C, charge + P[day]);
    res = min(res, solve(day+1, charge2) + pay);
    dp[day][charge] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> B >> C;
        P.resize(N), D.resize(N), F.resize(N);
        for(int i = 0; i < N; ++i) cin >> P[i];
        for(int i = 0; i < N; ++i) cin >> F[i];
        for(int i = 0; i < N; ++i) cin >> D[i];
        dp.assign(N+1, vector<ll> (C+1, -1));
        ll res = solve(0, B);
        cout << res << endl;
    }
    return 0;
}
