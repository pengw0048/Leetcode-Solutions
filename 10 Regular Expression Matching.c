bool isMatch(char* s, char* p) {
	int sl = strlen(s), pl = strlen(p);
	char m[100][100] = { 1 };
	s--; p--;
	for (int i = 0; i <= sl; i++)for (int j = 1; j <= pl; j++) {
		if (p[j] == '.') m[i][j] = i && m[i - 1][j - 1];
		else if (j > 1 && p[j] == '*' && p[j - 1] == '.') m[i][j] = m[i][j - 2] || i && m[i - 1][j];
		else if (j > 1 && p[j] == '*') m[i][j] = m[i][j - 2] || i && m[i - 1][j] && s[i] == p[j - 1];
		else m[i][j] = i && m[i - 1][j - 1] && s[i] == p[j];
	}
	return m[sl][pl];
}