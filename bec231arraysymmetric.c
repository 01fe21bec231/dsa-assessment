#include<stdio.h>
#define m 100
int check(int arr[m][m],int n)
{
    int i,j;

//symetric
     for(i=0;i<n;i++)
    {
        for(j=i+1;i<n;i++)
        {

        if(arr[i][j]!=arr[j][i])
        return 0;    //not means
        }

    }
    return 1;

}

void read (int arr[m][m],int n)
{
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main ()
{
    int arr[m][m];
    int n,i,j;
    printf("enter n \n");
    scanf("%d",&n);

    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
  read(arr,n);
    if(check(arr,n))
    {
        printf("symmetric");
    }
    else
    {
        printf("nonsymmetric");
    }

    return 0;
}
//123245351
