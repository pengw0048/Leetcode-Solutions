int myAtoi(char* str) {
    long long ret=0;
    int sign=1;
    while((*str==' '||*str<14)&&*str!=0)str++;
    if(*str==0)return 0;
    if(*str=='+')str++;
    else if(*str=='-'){sign=-1;str++;}
    while(*str>='0'&&*str<='9'){
        ret=ret*10+(*str-'0');
        if(ret>2147483648||ret==2147483648&&sign==1)return sign==1?2147483647:-2147483648;
        str++;
    }
    return sign*(int)ret;
}