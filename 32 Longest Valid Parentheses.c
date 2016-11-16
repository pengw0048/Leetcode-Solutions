int sp[1000000];
int max(int a, int b) { return a > b ? a : b; }
int longestValidParentheses(char* s) {
	int sl = 0, i = 0, ans = 0;
	sp[0] = -1;
	while (*s) {
		if (*s == '('){
			if(sp[sl] == -1) sp[sl] = i;
			sp[++sl] = -1;
		}
		else if (sl > 0) {
			ans = max(ans, i + 1 - sp[--sl]);
			sp[sl+1] = -1;
		}
		else sp[0] = -1;
		s++;
		i++;
	}
	return ans;
}
