#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> times;
    int count = 0;

    for(int h = 0; h < 24; ++h) {
        for(int m = 0; m < 60; ++m) {
            for(int s = 0; s < 60; ++s) {
                if ((h << 2 | m << 1 | s) == n) {
                    count++;
                    times.push_back({h, m, s});
                }
            }
        }
    }

    if(count == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(times.begin(), times.end(), [] (const vector<int>& a, const vector<int>& b) {
        if(a[0] != b[0]) return a[0] < b[0];
        if(a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
    });

    vector<int> best_time = times[0];
    int min_sum_digits = INT_MAX;

    for(const auto& t : times) {
        int sum_digits = t[0] / 10 + t[0] % 10 + t[1] / 10 + t[1] % 10 + t[2] / 10 + t[2] % 10;
        if(sum_digits < min_sum_digits) {
            min_sum_digits = sum_digits;
            best_time = t;
        }
    }

    cout << count << endl;
    printf("%02d:%02d:%02d\n", best_time[0], best_time[1], best_time[2]);

    return 0;
}
