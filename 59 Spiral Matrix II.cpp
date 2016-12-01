class Solution {
public:
    const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        if(n==0)return ret;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++)v.push_back(0);
            ret.push_back(v);
        }
        int ol=2,x=0,y=0,dir=0;
        char *mark=(char*)malloc(n*n);
        memset(mark,0,n*n);
        ret[0][0]=1;
        mark[0]=1;
        while(ol<=n*n){
            while(x+dx[dir]<0||x+dx[dir]>=n||y+dy[dir]<0||y+dy[dir]>=n||mark[(x+dx[dir])*n+y+dy[dir]])dir=(dir+1)%4;
            x+=dx[dir];
            y+=dy[dir];
            mark[x*n+y]=1;
            ret[x][y]=ol++;
        }
        free(mark);
        return ret;
    }
};
