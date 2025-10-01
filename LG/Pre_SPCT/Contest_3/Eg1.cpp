#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> nums;

void input() {
    cin >> n >> m;
    nums.resize(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> nums[i][0];  // Food price
    }
    for (int i = 0; i < n; ++i) {
        cin >> nums[i][1];  // Shipping fee
    }
}

void solve() {
    int maxDays = 0;
    int minCost = INT_MAX;

    // Try using the voucher on each day
    for (int voucherDay = 0; voucherDay < n; ++voucherDay) {
        vector<int> costs;

        // Calculate cost if voucher is used on voucherDay
        for (int i = 0; i < n; ++i) {
            if (i == voucherDay) {
                costs.push_back(nums[i][0]);  // Free shipping
            } else {
                costs.push_back(nums[i][0] + nums[i][1]);  // Normal cost
            }
        }

        sort(costs.begin(), costs.end());

        int totalCost = 0;
        int days = 0;

        // Calculate the maximum number of days we can afford with the budget
        for (int cost : costs) {
            if (totalCost + cost <= m) {
                totalCost += cost;
                days++;
            } else {
                break;
            }
        }

        // Update maximum days and minimum cost accordingly
        if (days > maxDays) {
            maxDays = days;
            minCost = totalCost;
        } else if (days == maxDays) {
            minCost = min(minCost, totalCost);
        }
    }

    cout << maxDays << " " << minCost << endl;
}

int main() {
    input();
    solve();
    return 0;
}
