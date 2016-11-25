int maxSubArray(int* nums, int numsSize) {
    int bv=nums[0],cv=nums[0],s=0;
    for(int i=1;i<numsSize;i++){
        while(s<i&&cv<0)cv-=nums[s++];
        cv+=nums[i];
        bv=cv>bv?cv:bv;
    }
    return bv;
}
