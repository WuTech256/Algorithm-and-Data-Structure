/*
Problem: https://codeforces.com/contest/4/problem/A
    Giải thích đề bài:
        Cho số nguyên w ứng với trọng lượng dưa hấu mà Pepe và Billy mua.
        Cả 2 người đều là fan của số chẵn và họ muốn chia DƯA HẤU thành 2 phần sao cho 2 phần dưa hấu đều có cân nặng là số chẵn.
        
    Đầu ra là YES nếu có thể chia còn NO nếu không thể chia.
    
    Vd:
    input 8 -> output YES
*/

/*
    Solution:
    - Nhận thấy nếu muốn chia thành 2 phần có cân nặng chẵn chỉ có th khối lượng ban đầu w phải là số chẵn
    - Trong các trường hợp số chẵn chỉ có 2 là khi chia luôn luôn là 1 vs 1 (2 số lẻ nên không thỏa mãn)
    6 (2 + 4); 8 (4 + 4 or 2 + 6 or v.v)
    => Ta chỉ cần check w có là số chẵn và lớn hơn 2 không thì bài toán sẽ được giải quyết
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Số cân nặng mà 2 ng mua
    int w;
    cin >> w;
    
    if(w % 2 == 0 && w > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    } 
    return 0;
}
