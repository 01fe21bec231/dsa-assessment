#include<stdio.h>
void find_longest(char lines[][1000],int n);
int length(char lines[]);
int main()
{
    int n;
    scanf("%d",&n); //no of the string
    char lines[n][1000];  //[n][size]  (2d array)

    for(int i=0;i<n;i++)
    {
        scanf("%s",lines[i]);
    }


    find_longest(lines,n);
    return 0;

}

int length(char lines[])
{
    int i,c=0;
    while(lines[i]!='\0')
    {
        c++;
        i++;
    }
    return c;
}



void find_longest(char lines[][1000],int n)
{
    int i,j=0;

    int min=length(lines[i]);  //compare with first string itself
    for (i=0; i<n;i++)
    {
        int hold=length(lines[i]);
        if (hold > min)
        {
            min=hold;
            j=i;
        }
    }
    printf("%s \n", lines[j]);
}


