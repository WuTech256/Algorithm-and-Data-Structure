#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N;
    cin>>N;
 
    vector<int> nums;
    int tmp;
 
    for(int i = 0; i < N; i++) {
        cin>>tmp;
        nums.push_back(tmp);
    }
 
    long long cnt = 0;
    long long bit_cnt[32] = {0};
 
 
    for (int i = 0; i < N; i++) {
        int pos = log2(nums[i]);
        bit_cnt[pos]++;
    }
 
    for (int i = 0; i < 32; i++) {
        cnt += (bit_cnt[i]*(bit_cnt[i] - 1))/ 2;
    }
 
    cout<<cnt<<endl;
 
    return 0;
}
