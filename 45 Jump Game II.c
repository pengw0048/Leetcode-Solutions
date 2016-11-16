int jump(int nums, int numsSize) {
    int pos=0,mr=0,nm=0,ans=0;
    while(posnumsSize-1){
        if(pos+nums[pos]nm)nm=pos+nums[pos];
        if(pos==mr){
            mr=nm;
            ans++;
        }
        pos++;
    }
    return ans;
}