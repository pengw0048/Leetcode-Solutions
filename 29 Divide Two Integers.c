int divide(int adividend, int adivisor) {
	if (adivisor == 0 || adivisor == -1 && adividend == 0x80000000)return 0x7fffffff;
	long long dividend = adividend, divisor = adivisor;
	if (dividend < 0)dividend = -dividend;
	if (divisor < 0)divisor = -divisor;
	long long ans = 0;
	while (dividend >= divisor) {
		long long top = divisor, add = 1;
		while (dividend >= (top << 1)) {
			top <<= 1;
			add <<= 1;
		}
		dividend -= top;
		ans += add;
	}
	return (int)(((adividend<0)^(adivisor<0))?-ans:ans);
}
