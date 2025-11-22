// Moving Freely
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    vector<ll> nums(K);
    for (int i = 0; i < K; ++i) cin >> nums[i];

    int Q;
    cin >> Q;

    while (Q--) {
        ll T, P;
        cin >> T >> P;

        // Tìm vị trí đầu tiên mà nums[idx] >= P
        int idx = int(lower_bound(nums.begin(), nums.end(), P) - nums.begin());

        // Xác định biên trái/phải tránh phần tử trong nums
        bool hasRight = (idx < K);
        bool hasLeft  = (idx - 1 >= 0);

        ll L = hasLeft  ? nums[idx - 1] + 1 : -INF;
        ll R = hasRight ? nums[idx] - 1     :  INF;

        // Giao với [P - T, P + T]
        ll lo = max(L, P - T);
        ll hi = min(R, P + T);

        if (lo > hi) {
            cout << 0 << "\n";
            continue;
        }

        // Parity phải giống (P + T)
        int parity = (P + T) & 1;

        // Tìm số đầu tiên có đúng parity
        ll first = lo;
        if ((first & 1) != parity) first++;

        // Nếu vượt khỏi hi → không có số nào
        if (first > hi) {
            cout << 0 << "\n";
            continue;
        }

        // Đếm số lượng: first, first+2, ...
        ll cnt = 1 + (hi - first) / 2;
        cout << cnt << "\n";
    }

    return 0;
}
