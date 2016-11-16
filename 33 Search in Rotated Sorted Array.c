int search(int* nums, int numsSize, int target) {
	int l = 0, r = numsSize - 1, bp;
	if (nums[0] < nums[numsSize - 1])bp = numsSize - 1;
	else {
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (nums[m] > nums[numsSize - 1])l = m;
			else r = m - 1;
		}
		bp = l;
	}
	if (target >= nums[0]) {
		l = 0;
		r = bp;
	}
	else {
		l = bp + 1;
		r = numsSize - 1;
	}
	while (l <= r) {
		int m = (l + r) / 2;
		if (nums[m] == target) return m;
		else if (nums[m] > target) r = m - 1;
		else l = m + 1;
	}
	return -1;
}
