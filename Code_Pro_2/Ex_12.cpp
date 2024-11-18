#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> X;

bool check(int t) {
    int cnt = 1;
    int last_pos = X[0];

    for (int i = 1; i < N; i++) {
        if (X[i] > last_pos + 2 * t) {
            cnt++;
            last_pos = X[i];
        }
    }
    return cnt <= K;
}

int main() {
    cin >> N >> K;
    X.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    int l = 0, r = X[N-1] - X[0];
    int result = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
