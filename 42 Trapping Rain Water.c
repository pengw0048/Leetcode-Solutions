int trap(int* height, int heightSize) {
    int ans=0,l=0,r=heightSize-1,lh=height[l],rh=height[r];
    while(l<r){
        if(lh<rh){
            l++;
            if(height[l]<=lh)ans+=lh-height[l];
            else lh=height[l];
        }else{
            r--;
            if(height[r]<=rh)ans+=rh-height[r];
            else rh=height[r];
        }
    }
    return ans;
}