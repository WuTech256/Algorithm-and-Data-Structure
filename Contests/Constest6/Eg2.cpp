#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to calculate the points for a given permutation
int calculatePoints(const vector<int>& permutation, const vector<int>& A, const vector<int>& B, const vector<int>& C, const unordered_map<int, int>& pos) {
    int points = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (pos.at(A[i]) < pos.at(B[i])) {
            points += C[i];
        }
    }
    return points;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; ++i) {
        cin >> C[i] >> A[i] >> B[i];
    }

    // Generate all permutations of stores
    vector<int> stores(N);
    for (int i = 0; i < N; ++i) {
        stores[i] = i + 1;
    }

    int maxPoints = 0;
    int maxCount = 0;
    unordered_map<int, int> pos;

    do {
        for (int i = 0; i < stores.size(); ++i) {
            pos[stores[i]] = i;
        }
        int points = calculatePoints(stores, A, B, C, pos);
        if (points > maxPoints) {
            maxPoints = points;
            maxCount = 1;
        } else if (points == maxPoints) {
            ++maxCount;
        }
    } while (next_permutation(stores.begin(), stores.end()));

    cout << maxPoints << " " << maxCount << endl;

    return 0;
}
