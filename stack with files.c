#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void push(int num);
int isFull();
int isEmpty();
void display();
int pop();
void generaterandomNos(FILE *fp1, int num[], int n);
int top = -1;
int arr1[MAX_SIZE];

int main()
{
    int choice, num, n,c=0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    FILE *fp1 = fopen("input.txt", "w");
    if (fp1 == NULL)
    {
        printf("Unable to open the file.\n");
        exit(1);
    }

    generaterandomNos(fp1, arr1, n);
    fclose(fp1);
    printf("Random numbers generated and saved in 'input.txt' file.\n");

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        num = arr1[i];
        //push(num);
    }

    FILE *logpush = fopen("logpush.txt", "a");
    FILE *logpop = fopen("logpop.txt", "a");

    if (logpush == NULL || logpop == NULL)
    {
        printf("Unable to open log files.\n");
        exit(1);
    }

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fp1 = fopen("input.txt", "r+");
            logpush=fopen("logpush.txt","w");
             push(arr1[c]);
             c++;

             fprintf(logpush, "%d\n", num);
             fclose(logpush);
            fclose(fp1);
            break;
        case 2:
             logpop=fopen("logpop.txt","w");
            num = pop();
            printf("\nPopped number is: %d\n", num);
            fprintf(logpop, "%d\n", num);
          fclose(logpop);
             fclose(logpop);
            break;
        case 3:
            display();
            break;
        case 4:
            fclose(logpush);
            fclose(logpop);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int num)
{
    if (isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top = top + 1;
    arr1[top] = num;
}

int pop()
{
    int num;
    if (isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    num = arr1[top];
    top = top - 1;
    return num;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack elements:\n\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", arr1[i]);
    }
    printf("\n");
}

void generaterandomNos(FILE *fp1, int num[], int n)
{
    int low, high;

    printf("Enter the lower and higher limits: ");
    scanf("%d%d", &low, &high);

    srand(time(NULL));
     fprintf(fp1, "%d\n", n);

    for (int i=0;i<n;i++)
    {
        num[i]= (rand() %(high-low+1))+low;
        fprintf(fp1,"%d\t",num[i]);
    }
}

