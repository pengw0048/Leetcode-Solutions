int firstMissingPositive(int* nums, int numsSize) {
    nums--;
    for(int i=1;i<=numsSize;i++){
        int num=nums[i];
        while(num>=1&&num<=numsSize&&nums[num]!=num){
            int tmp=nums[num];
            nums[num]=num;
            nums[i]=tmp;
            num=tmp;
        }
    }
    for(int i=1;i<=numsSize;i++)if(nums[i]!=i)return i;
    return numsSize+1;
}