// Bài toán:
// Bạn được đưa 1 mảng coins và target. Mảng coins chứa các mệnh giá tiền.
// Giả sử số tiền của mỗi mệnh giá là vô tận
// Nhiệm vụ của bạn là tạo ra target từ các mệnh giá tiền đó với sống lượng đồng coin ít nhất có thể

// Ví dụ:
// coins = {1, 5, 6, 8} 
// target = 11
    
// Chỉ mất 2 đồng coin 5 và 6 để tạo ra 11
// mất 11 đồng 1 để tạo ra 11

// -> Thì ít nhất là 2


#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;
int target;

void input() {
    cin >> n;
    coins.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cin >> target;
}

void solve() {
    // Tạo mảng dp với giá trị mặc định là vô hạn
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;  // Không cần đồng xu nào để tạo ra 0

    // Duyệt qua tất cả các mệnh giá coin
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= target; ++j) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    // Nếu dp[target] vẫn là INT_MAX, nghĩa là không thể tạo ra target
    if (dp[target] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[target] << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}
