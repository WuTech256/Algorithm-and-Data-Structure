#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        struct Job { int s, e; int p; };
        vector<Job> jobs;
        jobs.reserve(N);
        for (int i = 0; i < N; ++i) {
            int s, e, p;
            cin >> s >> e >> p;
            jobs.push_back({s, e, p});
        }
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
            if (a.e != b.e) return a.e < b.e;
            return a.s < b.s;
        });
        vector<int> ends(N);
        for (int i = 0; i < N; ++i) ends[i] = jobs[i].e;
        vector<ll> dp(N, 0);
        for (int i = 0; i < N; ++i) {
            ll take = jobs[i].p;
            int lo = 0, hi = i - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (ends[mid] <= jobs[i].s) {
                    pos = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            if (pos != -1) take += dp[pos];
            ll notake = (i > 0 ? dp[i-1] : 0);
            dp[i] = max(take, notake);
        }
        cout << (N ? dp[N-1] : 0) << '\n';
    }
    return 0;
}