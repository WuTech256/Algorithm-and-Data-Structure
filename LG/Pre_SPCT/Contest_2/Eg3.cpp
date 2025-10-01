#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < q; ++i) {
        int type, index, val;
        cin >> type >> index >> val;

        if (type == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[index][j] = val;
            }
        } else if (type == 1) {
            for (int j = 0; j < n; ++j) {
                matrix[j][index] = val;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}
