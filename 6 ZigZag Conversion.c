char* convert(char* s, int n) {
    if(n==1)return s;
    int l=strlen(s),op=0;
    char* r=malloc(l+1);
    r[l]=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<l){
            int ot=j+n*2-2-2*i;
            r[op++]=s[j];
            if(i!=0&&ot!=j&&ot<l)r[op++]=s[ot];
            j+=n*2-2;
        }
    }
    return r;
}