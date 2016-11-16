int reverse(int x) {
    if(x==0x80000000)return 0;
    if(x<0)return -reverse(-x);
    char buf[15],t;
    sprintf(buf,"%d",x);
    for(int i=(strlen(buf)-1)/2;i>=0;i--){t=buf[i];buf[i]=buf[strlen(buf)-1-i];buf[strlen(buf)-1-i]=t;}
    long long r;
    sscanf(buf,"%lld",&r);
    if((int)r==r)return (int)r;
    return 0;
}