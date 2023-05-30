#include <stdio.h>
#include <stdlib.h>
#define m 10
#define n 100

int length(const char str[]);
void findandReplace(char str[][n]);

int main()
{
     FILE *fp1;
    char str[m][n];

    fp1 = fopen("123.txt", "r");
    if (fp1 == NULL)
    {
        printf("not found.\n");
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        fgets(str[i], n, fp1);
    }

    fclose(fp1);

    for (int i = 0; i < m; i++)
    {
        puts(str[i]);
    }

    findandReplace(str);

    return 0;
}

int length(const char str[])
{
    int ll = 0;
    while (str[ll] != '\0')
    {
        ll++;
    }
    return ll;
}

void findandReplace(char str[][n])
{
    char new_key[26];
    char str2[n];
    int i, j, k, n;

    printf("Enter the key");
    fgets(new_key, sizeof(new_key), stdin);
    new_key[length(new_key) - 1] = '\0'; // Remove newline character

    printf("Enter the string to be replaced: ");
    fgets(str2, sizeof(str2), stdin);
    str2[length(str2) - 1] = '\0'; // Remove newline character

    int new_keyLength = length(new_key);
    int str2Length = length(str2);

    for (i = 0; i < m; i++)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] == new_key[0])
            {
                n = 0;
                //for (k = j; k < j + new_keyLength; k++)
                {
                    if (str
                        [i][k] == new_key[n])
                    {
                        n++;
                        /*if (n == new_keyLength) //replacing
                        {
                            for (int l = 0; l < new_keyLength; l++)
                            {
                                str[i][j + l] = str2[l];
                            }
                            break;
                        }
                    }*/
                }
            }
            j++;
        }
    }

    printf("new strings or paragrahp\n");
    for (i = 0; i < m; i++)
    {
        puts(str[i]);
    }
}
