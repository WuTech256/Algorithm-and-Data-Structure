#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> nums;
    nums.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    int curr_operation = 0;
    for(int i = 0; i < M; ++i) {
        cin >> curr_operation;
        if(curr_operation > 0) {
            if(K <= curr_operation) {
                K = (curr_operation + 1) - K;
            } 
        } else if(curr_operation < 0) {
            if(K >= (N + curr_operation + 1)) {
                K = (2 * N + curr_operation + 1) - K;
            }
        }
    }

    cout << K << endl;
    return 0;
}
