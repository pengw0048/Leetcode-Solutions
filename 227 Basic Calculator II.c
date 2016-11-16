int calculate(char* s) {
    int len=strlen(s);
    s[len++]='*';
    int num_stack[len],stack_len=0;
    char op_stack[len];
    int number=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')number=number*10+s[i]-'0';
        else if(s[i]!=' '){
            if(stack_len!=0){
                if(op_stack[stack_len-1]=='*'){
                    num_stack[stack_len-1]*=number;
                    op_stack[stack_len-1]=s[i];
                    goto nxt;
                }else if(op_stack[stack_len-1]=='/'){
                    num_stack[stack_len-1]/=number;
                    op_stack[stack_len-1]=s[i];
                    goto nxt;
                }
            }
            op_stack[stack_len]=s[i];
            num_stack[stack_len++]=number;
            nxt:
            number=0;
        }
    }
    int res=num_stack[0];
    for(int i=1;i<stack_len;i++){
        if(op_stack[i-1]=='+')res+=num_stack[i];
        else res-=num_stack[i];
    }
    return res;
}