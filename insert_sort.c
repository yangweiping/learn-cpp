#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define M 115000

void generate_array(int a[], int low, int up);
void show(int a[]);
void insert(int a[], int aIndex, int bIndex);
void exchange(int a[], int aIndex, int bIndex);
bool is_sorted(int a[]);

int main()
{
    int i, lower = 1, upper = 101;
    srand(time(0));
    int arr[M];
    
    clock_t start, end;
    double cpu_time_used;
    
    generate_array(arr, lower, upper);
    
    start = clock();
    for(i = 1; i < M; i++)
    {
        int indexInsertAfter = i - 1;
        if(arr[i] < arr[indexInsertAfter])
        {
            while(indexInsertAfter >=0 && arr[i] < arr[indexInsertAfter]) 
            {
                indexInsertAfter--;
            }
            if(indexInsertAfter != i - 1)
            {
                insert(arr, indexInsertAfter + 1, i); 
            } else exchange(arr, i - 1, i);
            
        }    
    }
    // show(arr);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;     
    printf("%d numbers sort used %f seconds\n", M, cpu_time_used);
}


void insert(int a[], int aIndex, int bIndex) 
{
    int i;
    int temp = a[bIndex];

    for(i = bIndex; i > aIndex; i--) a[i] = a[i-1];
    a[aIndex] = temp;
}

bool is_sorted(int a[])
{
    int i;
    for(i = 1; i < M; i++) 
    {
        if(a[i] < a[i - 1]) return false;
    }   
}


void generate_array(int arr[], int lower, int upper) 
{
    int i;
    for(i = 0; i < M; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }   
    // show(arr);
}

void exchange(int a[], int aIndex, int bIndex) 
{
    int temp = a[aIndex];
    a[aIndex] = a[bIndex];
    a[bIndex] = temp;   
}


void show(int a[]) 
{
    int k;
    for(k = 0; k < M; k++) printf("%d ", a[k]);
    printf("\n");
}
