#include <bits/stdc++.h>
using namespace std;

int n1, n2; // Lengths of the two sequences
vector<int> seq1, seq2; // The two sequences

// Function to read input
void readInput() {
    cin >> n1;
    seq1.resize(n1);
    for(int i = 0; i < n1; i++) {
        cin >> seq1[i];
    }

    cin >> n2;
    seq2.resize(n2);
    for(int i = 0; i < n2; i++) {
        cin >> seq2[i];
    }
}

int main() {
    readInput();

    vector<long long> prefixSum1(n1 + 1, 0); // Prefix sums for sequence 1
    vector<long long> prefixSum2(n2 + 1, 0); // Prefix sums for sequence 2

    int j = 0; // Index for sequence 2

    // Calculate prefix sums for both sequences and track maximum points
    for(int i = 0; i < n1; i++) {
        // Update prefix sum for sequence 1
        prefixSum1[i + 1] = prefixSum1[i] + seq1[i];

        // Move forward in sequence 2 if necessary
        while (j < n2 && seq1[i] >= seq2[j]) {
            prefixSum2[j + 1] = prefixSum2[j] + seq2[j];
            // If values match, update the prefix sum for sequence 1
            if (seq1[i] == seq2[j]) {
                prefixSum1[i + 1] = max(prefixSum2[j + 1], prefixSum1[i + 1]);
                prefixSum2[j + 1] = prefixSum1[i + 1];
            }
            j++;
        }
    }

    // Finish updating prefix sums for sequence 2
    while (j < n2) {
        prefixSum2[j + 1] = prefixSum2[j] + seq2[j];
        j++;
    }

    // The maximum score is the best we can achieve either ending in sequence 1 or sequence 2
    cout << max(prefixSum2[n2], prefixSum1[n1]) << endl;

    return 0;
}
