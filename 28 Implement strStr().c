int strStr(char* haystack, char* needle) {
    if(needle[0]==0)return 0;
    int l1=strlen(haystack),l2=strlen(needle);
    for(int i=0;i<=l1-l2;i++){
        for(int j=0;j<l2;j++)if(haystack[i+j]!=needle[j])goto nxt;
        return i;
        nxt:;
    }
    return -1;
}