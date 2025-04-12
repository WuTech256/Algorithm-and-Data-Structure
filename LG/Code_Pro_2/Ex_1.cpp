#include <bits/stdc++.h>
int CalLargestBlock(int id_ignore){
	// int max_block_size = 0;
	// int cur_size = 1;
	// for (int i = 1; i < N; i++){
	// 	if (ID[i] == ID[i - 1]) cur_size++;
	// 	else cur_size = 1;
		
	// 	if (max_block_size < cur_size) {
	// 		max_block_size = cur_size;
	// 	}
	// }
	// return max_block_size;
	int res = 0;
	vector<int> tmp;
	int cur_size = 1;
	for(int i = 0; i < N; ++i) {
		if(ID[i] == id_ignore) continue;
		tmp.push_back(ID[i]);
	}
	for(int i = 1; i < tmp.size(); ++i) {
		if(tmp[i] == tmp[i-1]) cur_size++;
		else 
			cur_size = 1;
		
		res = max(res, cur_size);
	}
	return res;
}
