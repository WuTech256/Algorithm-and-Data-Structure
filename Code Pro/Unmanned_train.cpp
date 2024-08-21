#include <bits/stdc++.h>
using namespace std;
 
int rowSize, colSize;
int matrix[50][50];
 
void readInput() {
    cin >> rowSize >> colSize;
    for (int r = 0; r < rowSize; ++r) {
        for (int c = 0; c < colSize; ++c) {
            cin >> matrix[r][c];
        }
    }
}
 
typedef pair<int,int> rc;
vector<rc> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
 
queue<rc> colorProductionLine(rc startPoint) {
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize,false));
    queue<rc> bfsQueue;
    queue<rc> productionLine;
    productionLine.push(startPoint);
    bfsQueue.push(startPoint);
    matrix[startPoint.first][startPoint.second] = 2;
     
    while (!bfsQueue.empty()) {
        auto cur = bfsQueue.front();
        bfsQueue.pop();
        for (const auto& dir:dirs) {
            int newR = cur.first + dir.first;
            int newC = cur.second + dir.second;
            if (newR >=0 && newR <= rowSize-1 && newC >= 0 && newC <= colSize-1
                    && matrix[newR][newC] == 1) {
                matrix[newR][newC] = 2;
                bfsQueue.push(rc{newR, newC});
                productionLine.push(rc{newR, newC});
            }
        }
    }
    return productionLine;
}
 
rc getStartPoint() {
    for (int r = 0; r < rowSize; ++r) {
        for (int c = 0; c < colSize; ++c) {
            if (matrix[r][c]) {
                return rc{r,c};
            }
        }
    }
    return rc{};
}
 
int getMinRailModules(queue<rc>& productionLine) {
    while (!productionLine.empty()) {
        auto cur = productionLine.front();
        productionLine.pop();
        for (const auto& dir:dirs) {
            int newR = cur.first + dir.first;
            int newC = cur.second + dir.second;
             
            if (newR >= 0 && newR <= rowSize-1 && newC >= 0 && newC <= colSize-1) {
                if (matrix[newR][newC] == 0) {
                    matrix[newR][newC] = matrix[cur.first][cur.second] + 1;
                    productionLine.push(rc{newR,newC});
                } else if (matrix[newR][newC] == 1) {
                    return matrix[cur.first][cur.second] - 2;
                }
            }
        }
    }
    return 0;
}
 
int main() {
    readInput();
    auto startPoint = getStartPoint();
    auto productionLine = colorProductionLine(startPoint);
     
    auto minRail = getMinRailModules(productionLine);
    cout << minRail;
     
    return 0;
}
