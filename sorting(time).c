#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(FILE *fptr,int num[],int n);
void bubble_sorting(int num[],int n);
void selecting_sorting(int num[],int n);
void merge_sort_1(int num[], int start, int end, int mid,int n);
void merge_sort(int num[], int start, int end);
void check_time(int num[],int n);
int main()
{
    FILE *fptr;
    int num[1000],n;
    fptr = fopen("input.txt", "w");
    if (fptr==NULL)
    {
        printf("file does not exist\n");
        exit(0);
    }

     // initialize n before passing it to random function
     printf("Enter the value of n: ");
     scanf("%d", &n);
     random(fptr,num,n);
     fclose(fptr);
     printf("go to 'INPUT.TXT' FILE\n");

     //reading the data
    fptr=fopen("input.txt","r");
    fscanf(fptr,"%d",&n);
    for (int i=0;i<n;i++)
    {
        fscanf(fptr, "%d", &num[i]);
    }
    fclose(fptr);

    //to sort
    bubble_sorting(num,n);
    fptr= fopen("output.TXT", "w");
    fprintf(fptr ,"\n bubble sort:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "%d\t", num[i]);
    }
    fprintf(fptr ,"\n");
    //check_time(num,n);
    fclose(fptr);

    selecting_sorting(num,n);
    fptr= fopen("output.TXT", "a");
     fprintf(fptr ,"\nSelection sort:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "%d\t", num[i]);
    }
    fprintf(fptr ,"\n");
    //check_time(num,n);
    fclose(fptr);

    int start=0,end=n-1;
    merge_sort(num,start,end);
    fptr= fopen("output.TXT", "a");
     fprintf(fptr ,"\nMerge sort:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "%d\t", num[i]);
    }
    fprintf(fptr ,"\n");
   // check_time(num,n);
    fclose(fptr);

    return 0;
}

void random(FILE *fptr,int num[],int n)
{
    // range making
    int low, high,i;
    printf("Enter the lower and higher limits: ");
    scanf("%d%d",&low,&high);

    srand(time(0));
    fprintf(fptr, "%d\n", n);

    for (i=0;i<n;i++)
    {
        num[i]= (rand() %(high-low+1))+low;
        fprintf(fptr,"%d\t",num[i]);
    }
}

void bubble_sorting(int num[],int n)
{

 int clock_time,start_time,end_time;
    int Start_time=clock();
    //begin
    int i,j,temp;
    for (i=0;i< n-1; i++) {
        for (j=0;j< n-i-1;j++) {
            if (num[j]>num[j+1]) {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    end_time=clock();
   double total_t=((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("time taken by the sort=%lf\n",total_t);
    //ends

}

void selecting_sorting(int num[],int n)
{
    int min_i;
    int clock_time,start_time,end_time;
    int Start_time=clock();
//begins
    for(int i = 0; i<n-1;i++)
        {
        min_i = i;
        for(int j =i+1;j<n;j++)
         {
            if(num[min_i]>num[j])
            {
                min_i = j;
            }
        }
        if(min_i!= i)
        {
            //swap
            int temp=num[i];
            num[i]=num[min_i];
            num[min_i]=temp;
        }
    }

    end_time=clock();
   double total_t=((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("time taken by the sort=%lf\n",total_t);
    //ends

}


void merge_sort(int num[], int start, int end)
{
    int n;
 int clock_time,start_time,end_time;
 int Start_time=clock();
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(num, start, mid);
        merge_sort(num, mid + 1, end);
        merge_sort_1(num, start, end, mid,n);
    }
}

void merge_sort_1(int num[], int start, int end, int mid,int n)
{
    int temp[1000];
    int i = start;
    int j = mid + 1;
    int k = start;

   int clock_time,start_time,end_time;
    int Start_time=clock();

    //begins
     while (i<=mid  &&  j<=end)
    {
        if (num[i]<=num[j])
        {
            temp[k] = num[i];
            i++;
        }
        else
        {
            temp[k]=num[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k]=num[i];
        i++;
        k++;
    }

    while(j<=end)
    {
        temp[k]=num[j];
        j++;
        k++;
    }


    end_time=clock();
   double total_t=((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("time taken by the sort=%lf\n",total_t);
    for (i=start;i<=end;i++)
    {
        num[i]=temp[i];
    }



}
//no need
/*void check_time(int num[],int n)
{

 int clock_time,start_time,end_time;
    int Start_time=clock();

   end_time=clock();
   double total_t=((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("time taken by the sort=%lf\n",total_t);

}
*/
