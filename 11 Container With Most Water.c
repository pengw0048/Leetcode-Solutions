int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int maxArea(int* height, int heightSize) {
    int l=0,r=heightSize-1,ret=0;
    while(l<r){
        ret=max(ret,min(height[l],height[r])*(r-l));
        if(height[l]<height[r])l++;
        else r--;
    }
    return ret;
}