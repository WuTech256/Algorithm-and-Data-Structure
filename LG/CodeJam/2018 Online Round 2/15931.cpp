// Alex and Playing Cards

#include <bits/stdc++.h>
using namespace std;

int optFunc(int x2, int x3, int x4) {
    int total = x2 + x3 + 2 * x4;
    int best = 0;
    for (int t4 = 0; t4 <= x4; t4++) {
        int remain = total - 2 * t4;
        int t3 = (remain - t4) / 2;
        for (int cand : {max(0, min(x3, t3)), max(0, min(x3, t3 + 1))}) {
            int T = t4 + cand;
            int P = remain - cand;
            best = max(best, min(T, P));
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int R = 52 - n;
    int res_1 = INT_MAX;
    int res_2 = 0;
    for (int x4 = 0; x4 <= 13; x4++) {
        for (int x3 = 0; x3 <= 13 - x4; x3++) {
            for (int x2 = 0; x2 <= 13 - x3 - x4; x2++) {
                int re = 13 - (x2 + x3 + x4);
                int reVal = R - (x2 * 2 + x3 * 3 + x4 * 4);
                if (reVal < 0 || reVal > re) continue;

                int opt = optFunc(x2, x3, x4);
                res_1 = min(res_1, opt);
                res_2 = max(res_2, opt);
            }
        }
    }
    if (res_1 == INT_MAX) res_1 = 0;
    cout << res_1 << " " << res_2 << endl;
    return 0;
}
