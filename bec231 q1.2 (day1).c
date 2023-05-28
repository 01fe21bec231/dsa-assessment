#include <stdio.h>
#include <stdlib.h>

void find_longest(char lines[][1000], int n);
int length(char lines[]);

int main() {
    FILE *fp1,*fp2;
    int n;
    fp1 =fopen("sha.txt", "r");
    fp2=fopen("anu.txt", "r");
    if (fp1==NULL && fp2==NULL) {
        printf("does not exists");
        exit(1);
    }
    else
    fscanf(fp2,"%d", &n);
    fclose(fp2);
    char lines[n][1000];  // [n][size]  (2D array)
    for (int i=0; i<n; i++) {
        fscanf(fp1, "%s", lines[i]);  // read each string
    }

     fclose(fp1);
    find_longest(lines, n);
    return 0;
}

int length(char lines[]) {
    int i=0,c=0;
    while (lines[i] != '\0') {
        c++;
        i++;
    }
    return c;
}

void find_longest(char lines[][1000], int n) {
    int i,j=0;
    int min=length(lines[0]);  // compare with first string itself
    for (i =0;i<n;i++) {
        int hold=length(lines[i]);
        if (hold > min) {
            min=hold;
            j=i;
        }
    }
    printf("%s \n", lines[j]);
}
