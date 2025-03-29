class Solution {
private:
    // đếm số lượng số nguyên tố phân biệt của n
    int countDistinctPrimeFactors(int n) {
        int count = 0;
        // kiểm tra ước số 2
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) {
                n /= 2;
            }
        }
        // kiểm tra các ước số lẻ từ 3 đến căn n
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        // nếu n còn lớn hơn 1 => n là số nguyên tố lớn hơn căn n
        if (n > 1)
            count++;
        return count;
    }

    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return (int)result;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0)
            return 1;

        // lưu csac phần tử theo thứ tự giảm dần của giá trị
        priority_queue<pair<int, int>> maxValues;
        vector<int> rightLarge(n, n); // vị trí phần tử đầu tiên lớn hơn hoặc bằng phần tử hiện tại nằm bên phải
        vector<int> LeftLarge(n, -1); // vị trí phần tử đầu tiên bên trái lớn hơn hoặc bằng phần tử hiện tại
        vector<int> primeScores(n, 0); // lưu số lượng số nguyên tố phân biệt của từng phần tử
        stack<int> st, reverse;

        // tính primeScore và đẩy vào queue, sao cho ưu tiên value số lượng trước
        for (int i = 0; i < n; i++) {
            primeScores[i] = countDistinctPrimeFactors(nums[i]);
            maxValues.emplace(nums[i], i);
        }

        // mono stack để lấy right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[i] > primeScores[st.top()]) {
                rightLarge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // mono stack để lấy left
        for (int i = n - 1; i >= 0; i--) {
            while (!reverse.empty() &&
                   primeScores[i] >= primeScores[reverse.top()]) {
                LeftLarge[reverse.top()] = i;
                reverse.pop();
            }
            reverse.push(i);
        }

        int score = 1;
        const int MODULE = 1000000007;

        while (!maxValues.empty() && k > 0) {
            auto [val, idx] = maxValues.top();
            maxValues.pop();
            // Số lần val có thể được chọn là số khoảng chứa phần tử đó
            long long t =
                1LL * (rightLarge[idx] - idx) * (idx - LeftLarge[idx]);
            long long steps = min(t, (long long)k);

            int multiply = modPow(val, (int)steps, MODULE);
            score = (int)((1LL * score * multiply) % MODULE);

            k -= steps;
        }
        return score % MODULE;
    }
};
