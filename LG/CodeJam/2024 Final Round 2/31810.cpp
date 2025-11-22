// Magic Donut Game
#include <iostream>
#include <vector>
#include <cmath>

const long long MOD = 1e9 + 7;

// Cây đoạn (Segment Tree) hỗ trợ cộng đoạn và truy vấn tổng đoạn với lazy propagation
class SegmentTree {
public:
    int n;
    std::vector<long long> st, lazy;

    // Khởi tạo cây với kích thước n
    SegmentTree(const std::vector<long long>& a) {
        n = a.size();
        int size = 1 << (static_cast<int>(std::ceil(std::log2(n))) + 1);
        st.assign(size, 0);
        lazy.assign(size, 0);
        build(1, 0, n - 1, a);
    }

    // Xây dựng cây từ mảng a
    void build(int node, int l, int r, const std::vector<long long>& a) {
        if (l == r) {
            st[node] = a[l] % MOD;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        st[node] = (st[node * 2] + st[node * 2 + 1]) % MOD;
    }

    // Đẩy lazy xuống các node con
    void propagate(int node, int l, int r) {
        if (lazy[node] != 0) {
            st[node] = (st[node] + (r - l + 1) * lazy[node]) % MOD;
            if (l != r) {
                lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
            }
            lazy[node] = 0;
        }
    }

    // Cộng giá trị val vào đoạn [ql, qr]
    void update(int node, int l, int r, int ql, int qr, long long val) {
        propagate(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] = (lazy[node] + val) % MOD;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        st[node] = (st[node * 2] + st[node * 2 + 1]) % MOD;
    }

    // Truy vấn tổng đoạn [ql, qr]
    long long query(int node, int l, int r, int ql, int qr) {
        propagate(node, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[node] % MOD;
        int mid = (l + r) / 2;
        long long left = query(node * 2, l, mid, ql, qr);
        long long right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return (left + right) % MOD;
    }
};

// Hàm xử lý từng test case
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    SegmentTree seg(a);

    std::vector<int> S(m);
    std::vector<long long> X(m), Y(m);
    for (int i = 0; i < m; ++i) std::cin >> S[i];
    for (int i = 0; i < m; ++i) std::cin >> X[i];
    for (int i = 0; i < m; ++i) std::cin >> Y[i];

    int pos = 0, dir = 1;
    std::vector<long long> ans;

    for (int i = 0; i < m; ++i) {
        if (S[i] == 1 || S[i] == 2) {
            long long step = X[i] * dir;
            if (S[i] == 2) step *= -1;
            pos = ((pos + step) % n + n) % n;
        } else if (S[i] == 3) {
            dir *= -1;
        } else if (S[i] == 4) {
            long long end = pos + X[i] * dir;
            if (end < 0) {
                end = (end % n + n) % n;
                seg.update(1, 0, n - 1, 0, pos, Y[i]);
                if (end + 1 <= n - 1)
                    seg.update(1, 0, n - 1, end + 1, n - 1, Y[i]);
            } else if (end >= n) {
                end %= n;
                if (end > 0)
                    seg.update(1, 0, n - 1, 0, end - 1, Y[i]);
                seg.update(1, 0, n - 1, pos, n - 1, Y[i]);
            } else {
                if (dir < 0) {
                    if (end + 1 <= pos)
                        seg.update(1, 0, n - 1, end + 1, pos, Y[i]);
                } else {
                    if (pos <= end - 1)
                        seg.update(1, 0, n - 1, pos, end - 1, Y[i]);
                }
            }
        } else if (S[i] == 5) {
            long long end = pos + X[i] * dir;
            long long res = 0;
            if (end < 0) {
                end = (end % n + n) % n;
                res = (res + seg.query(1, 0, n - 1, 0, pos)) % MOD;
                if (end + 1 <= n - 1)
                    res = (res + seg.query(1, 0, n - 1, end + 1, n - 1)) % MOD;
            } else if (end >= n) {
                end %= n;
                if (end > 0)
                    res = (res + seg.query(1, 0, n - 1, 0, end - 1)) % MOD;
                res = (res + seg.query(1, 0, n - 1, pos, n - 1)) % MOD;
            } else {
                if (dir < 0) {
                    if (end + 1 <= pos)
                        res = (res + seg.query(1, 0, n - 1, end + 1, pos)) % MOD;
                } else {
                    if (pos <= end - 1)
                        res = (res + seg.query(1, 0, n - 1, pos, end - 1)) % MOD;
                }
            }
            ans.push_back(res % MOD);
        }
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
        if (i + 1 < ans.size()) std::cout << " ";
    }
    if (!ans.empty()) std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) solve();

    return 0;
}
