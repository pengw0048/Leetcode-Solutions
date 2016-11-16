void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    for(int i=0;i<matrixRowSize/2;i++)for(int j=i;j<matrixRowSize-i-1;j++){
        int t=matrix[i][j];
        matrix[i][j]=matrix[matrixRowSize-j-1][i];
        matrix[matrixRowSize-j-1][i]=matrix[matrixRowSize-i-1][matrixRowSize-j-1];
        matrix[matrixRowSize-i-1][matrixRowSize-j-1]=matrix[j][matrixRowSize-i-1];
        matrix[j][matrixRowSize-i-1]=t;
    }
}