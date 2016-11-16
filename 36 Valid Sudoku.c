bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    char h[9][9]={0},s[9][9]={0},g[9][9]={0};
    for(int i=0;i<9;i++)for(int j=0;j<9;j++){
        if(board[i][j]=='.')continue;
        int v=board[i][j]-'1';
        if(h[i][v])return false;
        h[i][v]=1;
        if(s[j][v])return false;
        s[j][v]=1;
        if(g[i/3*3+j/3][v])return false;
        g[i/3*3+j/3][v]=true;
    }
    return true;
}