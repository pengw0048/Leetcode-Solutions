int x[81], y[81], el = 0;
char **b, h[9][10] = { 0 }, l[9][10] = { 0 }, g[9][10] = { 0 };
char go(int v) {
	if (v == el)return 1;
	int tx = x[v], ty = y[v];
	for (int i = 1; i <= 9; i++) {
		if (h[tx][i] || l[ty][i] || g[tx / 3 * 3 + ty / 3][i]) continue;
		b[tx][ty] = i;
		h[tx][i] = l[ty][i] = g[tx / 3 * 3 + ty / 3][i] = 1;
		if (go(v + 1)) return 1;
		h[tx][i] = l[ty][i] = g[tx / 3 * 3 + ty / 3][i] = 0;
	}
	return 0;
}
void solveSudoku(char **board, int boardRowSize, int boardColSize) {
    el=0;
    memset(h,0,90);
    memset(l,0,90);
    memset(g,0,90);
	b = board;
	for (int i = 0; i < 9; i++)for (int j = 0; j < 9; j++) {
		if (b[i][j] == '.') {
			x[el] = i;
			y[el++] = j;
		}
		else {
			b[i][j] -= '0';
			h[i][b[i][j]] = l[j][b[i][j]] = g[i / 3 * 3 + j / 3][b[i][j]] = 1;
		}
	}
	go(0);
	for (int i = 0; i < 9; i++)for (int j = 0; j < 9; j++) b[i][j] += '0';
}
