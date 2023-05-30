#include <stdio.h>
#include <stdlib.h>

void find_longest(char lines[][1000], int n);
int length(char lines[]);

int main() {
    FILE *fp;
    int n;
    fp = fopen("input.txt","r");
    if (fp == NULL) {
        printf("go to inputfile.");
        exit(1);
    }
    fscanf(fp, "%d", &n);  // read number of strings
    char lines[n][1000];  // [n][size]  (2D array)
    for (int i = 0; i < n; i++) {
        fscanf(fp,"%s",lines[i]);  // read each string
    }
    fclose(fp);

    find_longest(lines,n);
    return 0;
}

int length(char lines[]) {
    int i=0, c=0;
    while (lines[i]!= '\0') {
        c++;
        i++;
    }
    return c;
}

void find_longest(char lines[][1000], int n) {
    int i, j = 0;
    int min=length(lines[0]);  // compare with first string itself
    for (i = 0; i < n; i++) {
        int hold=length(lines[i]);
        if (hold > min) {
            min=hold;
            j=i;
        }
    }
    printf("%s \n", lines[j]);
}
