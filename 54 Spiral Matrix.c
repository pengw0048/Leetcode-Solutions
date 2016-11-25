const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *o=malloc(4*matrixRowSize*matrixColSize),ol=1,x=0,y=0,dir=0;
    char *mark=malloc(matrixRowSize*matrixColSize);
    memset(mark,0,matrixRowSize*matrixColSize);
    if(matrixRowSize*matrixColSize>0){
    o[0]=matrix[0][0];
    mark[0]=1;
    while(ol<matrixRowSize*matrixColSize){
        while(x+dx[dir]<0||x+dx[dir]>=matrixRowSize||y+dy[dir]<0||y+dy[dir]>=matrixColSize||mark[(x+dx[dir])*matrixColSize+y+dy[dir]])dir=(dir+1)%4;
        x+=dx[dir];
        y+=dy[dir];
        mark[x*matrixColSize+y]=1;
        o[ol++]=matrix[x][y];
    }
    }
    return o;
}
