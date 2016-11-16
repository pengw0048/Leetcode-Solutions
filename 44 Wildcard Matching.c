bool isMatch(char* s, char* p) {
	int sl = strlen(s), pl = strlen(p), on = 0;
	s--; p--;
	char m[2][10000] = { 1 };
	for (int i = 0; i <= sl; i++) {
		for (int j = 1; j <= pl; j++) {
			if (p[j] == '?') m[on][j] = i && m[!on][j - 1];
			else if (p[j] == '*') m[on][j] = m[on][j - 1] || i && m[!on][j];
			else m[on][j] = i && m[!on][j - 1] && s[i] == p[j];
		}
		on = !on;
		memset(m[on], 0, pl + 1);
	}
	return m[sl % 2][pl];
}
