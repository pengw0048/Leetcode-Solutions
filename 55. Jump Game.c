bool canJump(int* nums, int numsSize) {
    int far=nums[0];
    for(int i=1;i<numsSize;i++){
        if(far<i)return false;
        if(i+nums[i]>far)far=i+nums[i];
    }
    return true;
}
