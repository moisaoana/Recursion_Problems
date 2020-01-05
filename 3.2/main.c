#include <stdio.h>


int hermiteRecursive(int n,int x)
{
    if(n==0)
        return 1;
    else
    if(n==1)
        return 2*x;
    else
        return 2*n*hermiteRecursive(n-1,x)-2*(n-1)*hermiteRecursive(n-1,x);
}

int main() {
    int n,x;
    printf("n= ");
    scanf("%d",&n);
    printf("x= ");
    scanf("%d",&x);
    printf("H%d(%d)=", n,x);
    printf("%d",hermiteRecursive(n,x));
    return 0;
}
