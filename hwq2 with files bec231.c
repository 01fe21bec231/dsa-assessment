#include<stdio.h>
#include<stdlib.h>
void find(char str[10][100]);
int length(char str[]);

int main()
{
    FILE *s;
 char str[11][100];
 s=fopen("123.txt","r");
 for(int i=0;i<10;i++)
 {
     fgets(str[i],200,s);
 }
 for(int i=0;i<10;i++)
 {
     puts(str[i]);
 }
 find(str);
 return 0;
}
int length(char str[])
{

    int i,ll=0;
    while(str[i]!='\0')
    {
        ll++;
        i++;
    }

    return ll;
}
void find(char str[][100])
{
    char hold[26],str1[10],str2[26];
    printf("enter the key \n");
    gets(hold);

    int i=0,j=0,k=0,l,n=0;
   for(int i=0;i<10;i++)
   { j=0;
    while(str[i][j]!='\0')
    {
        if(str[i][j]==hold[0])
        {
              n=0;
            for(int k=j;k<j+4;k++)
            {
                if(str[i][k]==hold[n])
                {
                    n++;
                    while(hold[n]=='\0')
                    {
                        printf("LINE IS %s\n",str[i]);

                       int a=i;
                        break;
                    }

                }
            }
        }
        j++;
    }

   }


printf("enter the string to be replaced\n");
gets(str2);
for(int i=0;i<10;i++)
   { j=0;
    while(str[i][j]!='\0')
    {
        if(str[i][j]==hold[0])
        {
              n=0;
            for(int k=j;k<j+4;k++)
            {
                if(str[i][k]==hold[n])
                {
                    str[i][k]=str2[n];
                    n++;
                    while(hold[n]=='\0')
                    {
                        printf("LINE IS %s\n",str[i]);
                       int a=i;

                        break;
                    }

                }
            }
        }
        j++;
    }
   }
}
