// Bài toán 
// Bài toán cắt que và bán các đoạn: Bạn có một cây que có chiều dài là n và một mảng prices chứa giá trị bán của các đoạn que có chiều dài từ 1 đến n. Nhiệm vụ của bạn là tìm ra giá tối đa có thể thu được bằng cách cắt que thành nhiều đoạn và bán các đoạn này.
    
//     Ví dụ cho n = 8, prices = {1, 5, 8, 9, 10, 17, 17, 20}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> prices;
void input() {
    cin >> n;
    prices.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
}

void solve() {
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }
    cout << dp[n] << endl;
}

int main() {
    input();
    solve();
}
