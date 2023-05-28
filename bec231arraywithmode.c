#include <stdio.h>

void check_if(int arr[], int n);
int main()
{
    int i, a[25];
    printf("Enter 25 numbers:\n");
    for (i=0;i<25;i++)
    {
        scanf("%d", &a[i]);
    }
    check_if(a, 25);
    return 0;
}

void check_if(int arr[], int n)
{
    int i,j,c;

    for (i=0;i<n;i++)
    {
        if (arr[i] == -1)
        {
            continue;
        }

        c=1;
        for (j=i+1; j<n;j++)
        {
            if (arr[i]==arr[j])
            {
                c++;
                arr[j]=-1;
            }
        }

        printf("%d is repeated %d times\n", arr[i], c);
    }
}
