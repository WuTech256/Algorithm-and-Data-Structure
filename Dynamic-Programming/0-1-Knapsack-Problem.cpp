// Bài toán Knapsack
// Tìm giá trị tối đã có thể mang trong chiếc balo với điều kiện không vượt quá sức chứa tối đa,
// đồng thời mỗi vật phẩm chỉ có thể chọn hoặc không (bài toán chiếc balo 0-1)
// Cho trọng lượng, cho values, và giới hạn của balo
//     Eg:
//     weight = {2, 3, 4, 5}
//     values = {3, 4, 5, 6}
//     maxCapacity = 7
        
//     -> value = 10 (out)

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> weight;
vector<int> values;
int maxCapacity;


void input() {
    cin >> n;
    weight.resize(n);
    values.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> weight[i] >> values[i];
    }
    
    cin >> maxCapacity;
}

void solve() {
    vector<vector<int>> dp(n+1, vector<int> (maxCapacity + 1, 0));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= maxCapacity; ++j) {
            if(weight[i - 1] <= j) {
                dp[i][j] = max(dp[i-1][j - weight[i-1]] + values[i-1], dp[i-1][j]);
            } else {
                dp[i][j] =  dp[i-1][j];
            }
        }
    }
    cout << dp[n][maxCapacity] << endl;
}

int main() {
    input();
    solve();
}
