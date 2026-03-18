#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;

    while (1){
        while (i<=high && arr[i]<=pivot)
            i++;
        while (arr[j]>pivot)
            j--;
        if (i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }else{
            break;
        }
    }

    arr[low]=arr[j];
    arr[j]=pivot;
    return j;
}

void quicksort(int arr[],int low,int high){
    if (low<high){
        int idx=partition(arr,low,high);
        quicksort(arr,low,idx-1);
        quicksort(arr,idx+1,high);
    }
}

void generate_random(int arr[],int n) {
    for (int i=0;i<n;i++){
        arr[i]=rand();
    }
}

int main() {
    int sizes[]={10000,20000,50000,75000,100000,200000,500000,750000,1000000,2000000,5000000};
    int n=11;
    srand(time(NULL));
FILE *fp = fopen("quicksort_data.csv", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Size,Time\n");
    for (int k=0;k<n;k++) {
        int n=sizes[k];

        int *arr=(int*)malloc(n*sizeof(int));
        if (arr==NULL){
            printf("Memory allocation failed\n");
            fclose(fp);
            return 1;
        }

        generate_random(arr, n);
        clock_t start, end;
        double cpu_time;

        start=clock();
        quicksort(arr,0,n-1);
        end=clock();

        cpu_time=((double)(end-start))/CLOCKS_PER_SEC;

        printf("Size: %d -> Time: %f seconds\n", n, cpu_time);
        fprintf(fp, "%d,%f\n", n, cpu_time);
        free(arr);
    }
fclose(fp);
    return 0;
}
