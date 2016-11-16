int removeDuplicates(int* nums, int numsSize) {
    int r=0,w=0,v;
    while(r<numsSize){
        v=nums[r++];
        while(r<numsSize&&nums[r]==v)r++;
        nums[w++]=v;
    }
    return w;
}