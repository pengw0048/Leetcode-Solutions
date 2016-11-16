char st[10000000];
int sl=0;
bool isValid(char* s) {
    sl=0;
    while(*s){
        if(*s=='('||*s=='['||*s=='{')st[sl++]=*s;
        else if(sl>0&&(st[sl-1]+1==*s||st[sl-1]+2==*s))sl--;
        else return false;
        s++;
    }
    return sl==0;
}