char* longestPalindrome(char* c) {
    int i,j,l,max=0,s,e;
    l=strlen(c);
    for(i=0;i<l;i++){
        for(j=1;j<=1000;j++){
            if(i-j+1<0||i+j-1>=l||c[i-j+1]!=c[i+j-1])break;
            if(j*2-1>max){
                max=j*2-1;
                s=i-j+1;
                e=i+j-1;
            }
        }
        for(j=1;j<=1000;j++){
            if(i-j+1<0||i+j>=l||c[i-j+1]!=c[i+j])break;
            if(j*2>max){
                max=j*2;
                s=i-j+1;
                e=i+j;
            }
        }
    }
    c[e+1]=0;
    return c+s;
}