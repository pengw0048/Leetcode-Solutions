bool isPalindrome(int x) {
    if(x<0)return false;
    char buf[15],t;
    sprintf(buf,"%lld",(long long)x);
    for(int i=(strlen(buf)-1)/2;i>=0;i--){t=buf[i];buf[i]=buf[strlen(buf)-1-i];buf[strlen(buf)-1-i]=t;}
    long long r;
    sscanf(buf,"%lld",&r);
    printf("%lld\n",r);
    return x==r;
}