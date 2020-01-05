#include <stdio.h>


int hermiteRecursive(int n,int x)
{
    if(n==0)
        return 1;
    else
    if(n==1)
        return 2*x;
    else
        return 2*n*hermiteRecursive(n-1,x)-2*(n-1)*hermiteRecursive(n-2,x);
}
int hermiteNonRecursive(int n, int x)
{
    if(n==0)
        return 1;
    int a1=1,a2=2*x,a=0;
    if(n==1)
        return a2;
    for(int i=2;i<=n;i++)
    {
        a=2*i*a2-2*(i-1)*a1;
        a1=a2;
        a2=a;
    }
    return a;

}
int main() {
    int n,x;
    printf("n= ");
    scanf("%d",&n);
    printf("x= ");
    scanf("%d",&x);
    printf("Recursive solution: \n");
    printf("H%d(%d)=", n,x);
    printf("%d",hermiteRecursive(n,x));
    printf("\nNon-Recursive solution: \n");
    printf("H%d(%d)=", n,x);
    printf("%d",hermiteNonRecursive(n,x));
    return 0;
}
