int removeElement(int* nums, int numsSize, int val) {
    int w=0;
    for(int r=0;r<numsSize;r++)if(nums[r]!=val)nums[w++]=nums[r];
    return w;
}