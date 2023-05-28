#include<stdio.h>
#include<stdlib.h>

void read_array(int mat[20][20],int m,int n);
void display_array(int mat[20][20],int m,int n);
void multiplication(int mat1[20][20],int mat2[20][20], int m1, int n1, int m2, int n2);

int main()
{
    int mat1[20][20],mat2[20][20];
    int m1,n1,m2,n2;
    printf("Enter the row and column for the 1st matrix: ");
    scanf("%d%d",&m1,&n1);
    printf("Enter the elements for 1st matrix:\n");
    read_array(mat1,m1,n1);
    display_array(mat1,m1,n1);

    printf("Enter the row and column for the 2nd matrix: ");
    scanf("%d%d",&m2,&n2);
    printf("Enter the elements for 2nd matrix:\n");
    read_array(mat2,m2,n2);
    printf("2nd matrix:\n");
    display_array(mat2,m2,n2);

    printf("answer:\n");
    multiplication(mat1,mat2,m1,n1,m2,n2);

    return 0;
}

void read_array(int mat[20][20],int m,int n)
{
   int i,j;
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%d",(*(mat+i)+j));
       }
   }
}
void display_array(int mat[20][20],int m ,int n)
{
     int i,j;
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%d\t",*(*(mat+i)+j));
       }
       printf("\n");
   }
}

void multiplication(int mat1[20][20],int mat2[20][20], int m1, int n1, int m2, int n2)
{
   int i,j,k,add=0,new_mat[20][20];
   for(i=0;i<m1;i++)
   {
       for(j=0;j<n2;j++)
       {
           for(k=0;k<n1;k++)
           {
             add=add+((*(*(mat1+i)+k)) * (*(*(mat2+k)+j)));
           }
           *(*(new_mat+i)+j)=add;    //*p=value
           add=0;
       }
   }
   for(i=0;i<m1;i++)
   {
       for(j=0;j<n2;j++)
       {
           printf("%d\t",*(*(new_mat+i)+j));
       }
       printf("\n");
   }
}
