class Solution {
public:
    void go(int l,int n,int &res,vector<bool> &mark1,vector<bool> &mark2,vector<bool> &mark3){
        if(l==n){
            res++;
            return;
        }
        for(int i=0;i<n;i++)if(mark1[i]==false&&mark2[l+i]==false&&mark3[n-i-1+l]==false){
            mark1[i]=true;
            mark2[l+i]=true;
            mark3[n-i-1+l]=true;
            go(l+1,n,res,mark1,mark2,mark3);
            mark1[i]=false;
            mark2[l+i]=false;
            mark3[n-i-1+l]=false;
        }
    }
    int totalNQueens(int n) {
        int res=0;
        vector<bool> mark1,mark2,mark3;
        for(int i=0;i<n;i++){
            mark1.push_back(false);
            mark2.push_back(false);
            mark3.push_back(false);
            mark2.push_back(false);
            mark3.push_back(false);
            string s="";
            for(int j=0;j<n;j++)s+=".";
        }
        go(0,n,res,mark1,mark2,mark3);
        return res;
    }
};