int cmp(int *a, int *b) {
	return *a - *b;
}
void nextPermutation(int* nums, int numsSize) {
	int i = numsSize - 1;
	while (i>0 && nums[i] <= nums[i - 1])i--;
	if (i != 0) {
		int j = i;
		while (nums[j]>nums[i-1] && j<numsSize)j++;
		j--;
		int t = nums[i-1]; nums[i-1] = nums[j]; nums[j] = t;
	}
	qsort(nums + i, numsSize - i, 4, cmp);
}
