// Đề bài là tìm 1 cái basket phù hợp với từng phần tử trong Fruits (lấy basket từ trái sang phải của baskets)
// Ý tưởng là dùng SegmentTree Max
// Ta build một cây segment tree max
// Ta duyệt lần lượt fruits
// Dùng Binary Search đề tìm xem giá trị > hơn fruit_i mà có pos nhỏ nhất (tức nằm bên trái nhất)
// Sau khi tìm được ta reset basket tìm ở trên đấy về 0 và update pos = cái vị trí vừa tìm được bởi Binary Search vào SegTree

class SegmentTree 
{
public:
    vector<int> segTree;
    vector<int> nums;

    SegmentTree(int n, vector<int>& nums)
    {
        segTree.resize(4 * n);
        this->nums = nums;
        build(0, 0, n - 1);
    }

    void build(int idx, int left, int right)
    {
        if (left == right) {
            segTree[idx] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);
    }

    void update(int idx, int left, int right, int pos, int val)
    {
        if (left == right) {
            segTree[idx] = val;
            return;
        }

        int mid = left + (right - left) / 2;
        if (pos <= mid)
            update(2 * idx + 1, left, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, right, pos, val);

        segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);
    }

    int query(int idx, int left, int right, int ql, int qr)
    {
        if (qr < left || ql > right) return INT_MIN; // Không có giá trị hợp lệ
        if (left >= ql && right <= qr) return segTree[idx];

        int mid = left + (right - left) / 2;
        int leftMax = query(2 * idx + 1, left, mid, ql, qr);
        int rightMax = query(2 * idx + 2, mid + 1, right, ql, qr);

        return max(leftMax, rightMax);
    }
};

int res;

void find(int val, SegmentTree& st, vector<int>& baskets, int n)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        int max_i = st.query(0, 0, n - 1, 0, mid);
        if (max_i >= val) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (ans != -1) {
        st.update(0, 0, n - 1, ans, 0);
        baskets[ans] = 0; // Cập nhật giá trị trong baskets
    } else {
        ++res;
    }
}

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        res = 0;
        int n = baskets.size();

        SegmentTree st(n, baskets);

        for (int i = 0; i < fruits.size(); ++i) {
            find(fruits[i], st, baskets, n);
        }

        return res;
    }
};
