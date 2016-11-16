int lengthOfLongestSubstring(char* s) {
    if (!s[0]) return 0;
	char you[256] = { 0 };
	int i = 1, p = 0, ans = 1;
	you[s[0]] = 1;
	for (; s[i]; i++) {
		while (you[s[i]]) {
			you[s[p++]] = 0;
		}
		you[s[i]] = 1;
		if (i - p + 1 > ans) ans = i - p + 1;
	}
	if (i - p > ans) ans = i - p;
	return ans;
}