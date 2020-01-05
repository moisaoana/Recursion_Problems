#include<stdio.h>


int n;
int row[]={2,1,-1,-2,-2,-1,1,2,2};
int col[]={1,2,2,1,-1,-2,-2,-1,1};
int validPosition(int i, int j);
void findPaths(int solution[n][n], int i, int j, int position);

int main()
{
    int position=1;
    printf("Enter n: ");
    scanf("%d",&n);
    getchar();
    int solution[n][n];
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++)
            solution[i][j] = 0;
    }
    findPaths(solution,0,0,position);
    return 0;
}
int validPosition(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    else
        return 1;
}
void findPaths(int solution[n][n], int i, int j, int position)
{
    int next_i, next_j;
   solution[i][j]=position;
    if(position>=n*n)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
                printf("%d ",solution[x][y]);
            printf("\n");
        }
        printf("\n");
        solution[i][j]=0;
        return;
    }
    for(int k=0;k<8;k++)
    {
        next_i=i+row[k];
        next_j=j+col[k];
        if(validPosition(next_i, next_j)==1 && solution[next_i][next_j]==0)
            findPaths(solution, next_i, next_j, position+1);

    }
    solution[i][j]=0;

}