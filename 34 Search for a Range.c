int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret=malloc(8);
    *returnSize=2;
    int l=0,r=numsSize-1,m;
    while(l<r){
        m=(l+r+1)/2;
        if(nums[m]<target)l=m;
        else r=m-1;
    }
    if(nums[l]!=target)l++;
    if(l==numsSize||nums[l]!=target){ret[0]=ret[1]=-1;return ret;}
    ret[0]=l;
    l=0;
    r=numsSize-1;
    while(l<r){
        m=(l+r)/2;
        if(nums[m]<=target)l=m+1;
        else r=m;
    }
    if(nums[r]!=target)r--;
    ret[1]=r;
    return ret;
}