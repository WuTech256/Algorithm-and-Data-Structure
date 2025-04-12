#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> types = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
vector<int> nums(10);

void input() {
	cin >> n;
	for(int i = 0; i < 10; ++i) {
		cin >> nums[i];
	}
}

void solve() {
	int sum = 0;
	int tmp = 0;
	for(int i = 0; i < 10; ++i) {
		sum += types[i] * nums[i];
		tmp += nums[i];
	}
	sum = sum - n;
	
	int min_i = 0;
	for(int i = nums.size() - 1; i >= 0; --i) {
		while(sum >= types[i] && nums[i] > 0) {
			sum -= types[i];
			nums[i]--;
			min_i++;
		}
	}
	cout << tmp - min_i << endl;
	for(auto t: nums) {
		cout << t <<" ";
	}
	cout << endl;
}

int main() {
	input();
	solve();
	return 0;
}