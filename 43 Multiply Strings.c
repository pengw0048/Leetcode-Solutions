char* multiply(char* num1, char* num2) {
	int l1 = strlen(num1), l2 = strlen(num2);
	char *res = malloc(l1 + l2 + 2);
	memset(res, 0, l1 + l2 + 2);
	for (int i = 0; i < l1; i++)num1[i] -= '0';
	for (int i = 0; i < l2; i++)num2[i] -= '0';
	for (int i = 0; i < l1; i++)for (int j = 0; j < l2; j++) {
		int pos = i + j;
		res[pos] += num1[l1-1-i] * num2[l2-1-j];
		while (res[pos] >= 10) {
			res[pos + 1] += res[pos] / 10;
			res[pos++] %= 10;
		}
	}
	int lo = l1+l2+2;
	while (res[lo-1] == 0 && lo > 1)lo--;
	char *out = malloc(lo + 1);
	for (int i = 0; i < lo; i++)out[i] = res[lo - i - 1] + '0';
	out[lo] = 0;
	return out;
}
