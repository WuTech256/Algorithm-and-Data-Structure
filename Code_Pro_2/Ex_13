#define SWAP(a, b) {int temp = a;a = b;b = temp;}
void Rotate(int sr, int sc, int er, int ec) {
	if(sr >= er || sc >= ec) return;
	int a = Mat[sr][sc];
	// cout << sr << sc << er << ec << endl;
	for(int r = sr + 1; r <= er; ++r) {
		SWAP(Mat[r][sc], a);
	}
	
	for(int c = sc + 1; c <= ec; ++c) {
		SWAP(Mat[er][c], a);
	} 
	
	for(int r = er - 1; r >= sr; r--) {
		SWAP(Mat[r][ec], a);
	}
	
	for(int c = ec - 1; c >= sc; c--) {
		SWAP(Mat[sr][c], a);
	}

// 	for (int c = sc + 1; c <= ec; c++) {
// 		SWAP(Mat[sr][c], a);
// 	}

// 	for (int r = sr + 1; r <= er; r++) {
// 		SWAP(Mat[r][ec], a);
// 	}

// 	for (int c = ec - 1; c >= sc; c--) {
// 		SWAP(Mat[er][c], a);
// 	}

// 	for (int r = er - 1; r >= sr; r--) {
// 		SWAP(Mat[r][sc], a);
// 	}
}
