int searchInsert(int* nums, int numsSize, int target) {
    if(target<nums[0])return 0;
    if(target>nums[numsSize-1])return numsSize;
    int l=0,r=numsSize-1;
    while(l<r){
        int m=(l+r)/2;
        if(nums[m]>target)r=m;
        else if(nums[m]<target)l=m+1;
        else return m;
    }
    return l;
}