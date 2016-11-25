class Solution {
public:
    void go(int l,int n,vector<vector<string>> &res,vector<string> &board,vector<bool> &mark1,vector<bool> &mark2,vector<bool> &mark3){
        if(l==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)if(mark1[i]==false&&mark2[l+i]==false&&mark3[n-i-1+l]==false){
            mark1[i]=true;
            mark2[l+i]=true;
            mark3[n-i-1+l]=true;
            board[l][i]='Q';
            go(l+1,n,res,board,mark1,mark2,mark3);
            board[l][i]='.';
            mark1[i]=false;
            mark2[l+i]=false;
            mark3[n-i-1+l]=false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        vector<bool> mark1,mark2,mark3;
        for(int i=0;i<n;i++){
            mark1.push_back(false);
            mark2.push_back(false);
            mark3.push_back(false);
            mark2.push_back(false);
            mark3.push_back(false);
            string s="";
            for(int j=0;j<n;j++)s+=".";
            board.push_back(s);
        }
        go(0,n,res,board,mark1,mark2,mark3);
        return res;
    }
};