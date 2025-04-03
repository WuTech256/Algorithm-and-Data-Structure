/*
    Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
    Can you do this in place.
*/

/*
[SOLUTION]
    - The rotation can be performed in layers, where u perform a cyclic swap on the edges on each layer.alignas
    - In the first for loop, we rotate the first layer (outermost edges). We rotate the edges by doing a four-way swap first on the corners, then 
    on the element clockwise from the edges, then on the element three steps away. 
    - Once the exterior elements are rotated, we then rotate the interior region's edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix, int n) {
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;
            int last = n - 1 - layer;

            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i]; // Save top

                // Left -> Top
                matrix[first][i] = matrix[last - offset][first];

                // Bottom -> Left
                matrix[last - offset][first] = matrix[last][last - offset];

                // Right -> Bottom
                matrix[last][last - offset] = matrix[i][last];

                // Top -> Right
                matrix[i][last] = top;
            }
        }
    }
};


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Ma trận gốc:\n";
    printMatrix(matrix);

    Solution sol;
    sol.rotate(matrix, matrix.size());

    cout << "Ma trận sau khi xoay 90 độ:\n";
    printMatrix(matrix);

    return 0;
}
