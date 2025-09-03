// Random Best-of Series
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        string W;
        cin >> W;

        string W2 = W + W;
        int L = W2.size();

        vector<int> prefA(L+1, 0), prefB(L+1, 0);

        for (int i = 0; i < L; i++) {
            prefA[i+1] = prefA[i] + (W2[i] == 'A');
            prefB[i+1] = prefB[i] + (W2[i] == 'B');
        }

        long long total = 0;

        for (int j = 0; j < M; j++) {
            int s, g;
            cin >> s >> g;
            int need = (g + 1) / 2;

            int left = 1, right = g, ans = g;

            while (left <= right) {
                int mid = (left + right) / 2;
                int l = s-1;
                int r = l + mid;

                int aWin = prefA[r] - prefA[l];
                int bWin = prefB[r] - prefB[l];

                if (aWin >= need || bWin >= need) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            total += ans;
        }

        cout << total << "\n";
    }
    return 0;
}
