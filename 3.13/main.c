#include <stdio.h>

#define MAX_ROW_COL 50
int v[MAX_ROW_COL][MAX_ROW_COL];
int sol[MAX_ROW_COL][MAX_ROW_COL];
void readMaze(int m, int n);
void displayMaze(int m, int n);
void displaySolution(int m, int n);
void solMaze(int x, int y, int m, int n);
int main() {
    int m,n,i,j,ok;
    printf("Please enter the number of rows: \n");
    scanf("%d",&m);
    printf("Please enter the number of columns: \n");
    scanf("%d",&n);
    readMaze(m,n);
    printf("Please enter the coordinates of the starting cell: \n");
    scanf("%d",&i);
    scanf("%d",&j);
    for(int k=0;k<m;k++)
    {
        for(int l=0;l<n;l++)
            sol[k][l]=0;
    }
    printf("The solutions are: \n");
    solMaze(i,j,m,n);
    return 0;
}
void readMaze(int m, int n)
{
    printf("Please enter the maze matrix: (1 means blocked cell, 0 means free cell) \n");
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &v[i][j]);
    }

}
void displayMaze(int m, int n)
{
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }

}
void displaySolution(int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",sol[i][j]);
        printf("\n");
    }
    printf("\n");
}
void solMaze(int x, int y, int m, int n)
{

    if(x==m-1 && y==n-1) {
        sol[x][y]=1;
        displaySolution( m, n);
        sol[x][y]=0;

    }
    if(x>=0 && x<m && y>=0 && y<n && sol[x][y]==0 && v[x][y]==0) {
        sol[x][y] = 1;
        if (x+1>=0 && x+1<m && sol[x+1][y]==0 && v[x+1][y]==0)
            solMaze(x+1,y,m,n);
        if (y+1>=0 && y+1<n && sol[x][y+1]==0 && v[x][y+1]==0)
            solMaze(x,y+1,m,n);
        if (x-1>=0 && x-1<m  && sol[x-1][y]==0 && v[x-1][y]==0)
            solMaze(x-1,y,m,n);
        if (y-1>=0 && y-1<n && sol[x][y-1]==0 && v[x][y-1]==0)
            solMaze(x,y-1,m,n);
        sol[x][y] = 0;

    }
}