int romanToInt(char* s) {
	int ret = 0;
	while (*s == 'M') {
		ret += 1000; s++;
	}
	if (s[0] == 'C') {
		if (s[1] == 'D') { ret += 400; s += 2; }
		else if (s[1] == 'M') { ret += 900; s += 2; }
		else while (*s == 'C') {
			ret += 100; s++;
		}
	}
	else if (s[0] == 'D') {
		ret += 500; s++;
		while (*s == 'C') {
			ret += 100; s++;
		}
	}
	if (s[0] == 'X') {
		if (s[1] == 'L') { ret += 40; s += 2; }
		else if (s[1] == 'C') { ret += 90; s += 2; }
		else while (*s == 'X') {
			ret += 10; s++;
		}
	}
	else if (s[0] == 'L') {
		ret += 50; s++;
		while (*s == 'X') {
			ret += 10; s++;
		}
	}
	if (s[0] == 'I') {
		if (s[1] == 'V') { ret += 4; s += 2; }
		else if (s[1] == 'X') { ret += 9; s += 2; }
		else while (*s == 'I') {
			ret += 1; s++;
		}
	}
	else if (s[0] == 'V') {
		ret += 5; s++;
		while (*s == 'I') {
			ret += 1; s++;
		}
	}
	return ret;
}