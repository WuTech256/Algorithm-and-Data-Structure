// Drawing Binary Trees
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 444449;

// Hàm tính lũy thừa modulo
ll mod_pow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

// Hàm tính nghịch đảo modulo
ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

// Hàm tính C(R, K) % MOD
ll comb(ll R, ll K) {
    if (K > R) return 0;
    K = min(K, R - K); // tối ưu
    ll num = 1, den = 1;
    for (ll i = 0; i < K; i++) {
        num = num * (R - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * mod_inv(den) % MOD;
}

// DFS in-order để lấy thứ tự nút
void inorder(int u, const vector<int>& L, const vector<int>& R, vector<int>& ord) {
    if (L[u] != -1) inorder(L[u], L, R, ord);
    ord.push_back(u);
    if (R[u] != -1) inorder(R[u], L, R, ord);
}

void solve() {
    int N;
    ll V;
    cin >> N >> V;
    vector<ll> A(N);
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        if (L[i] != 0) L[i]--; else L[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i];
        if (R[i] != 0) R[i]--; else R[i] = -1;
    }

    // Tìm gốc (nút không có cha)
    vector<int> hasParent(N, 0);
    for (int i = 0; i < N; i++) {
        if (L[i] != -1) hasParent[L[i]] = 1;
        if (R[i] != -1) hasParent[R[i]] = 1;
    }
    int root = 0;
    for (int i = 0; i < N; i++) {
        if (!hasParent[i]) { root = i; break; }
    }

    // Lấy thứ tự in-order
    vector<int> ord;
    inorder(root, L, R, ord);
    

    // Lấy các nút cố định x-coordinate và thêm nút ảo
    vector<pair<ll,int>> fixedNodes; // (x_value, index_inorder)
    fixedNodes.push_back({0, -1}); // nút ảo đầu
    for (int i = 0; i < N; i++) {
        int idx = ord[i];
        if (A[idx] != 0) {
            fixedNodes.push_back({A[idx], i});
        }
    }
    fixedNodes.push_back({V + 1, N}); // nút ảo cuối
      for(auto v : fixedNodes) {
        cout << v.first << " " << v.second << endl;
    }

    // Tính số cách cho mỗi khoảng giữa 2 nút cố định
    ll ans = 1;
    for (int i = 1; i < (int)fixedNodes.size(); i++) {
        ll x1 = fixedNodes[i-1].first;
        int idx1 = fixedNodes[i-1].second;
        ll x2 = fixedNodes[i].first;
        int idx2 = fixedNodes[i].second;

        ll R = x2 - x1 - 1;       // số x khả dụng
        ll K = idx2 - idx1 - 1;   // số nút chưa cố định trong khoảng
        ans = ans * comb(R, K) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
