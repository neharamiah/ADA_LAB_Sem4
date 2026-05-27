#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int getMobile(int a[], int dir[], int n)
{
    int mobile_prev = 0;
    int mobile_index = -1;

    for(int i = 0; i < n; i++)
    {
  
        if(dir[a[i]-1] == LEFT && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }

        if(dir[a[i]-1] == RIGHT && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printf("\nPermutations are:\n");

    printPermutation(a, n);

    while(1)
    {
        int mobile = getMobile(a, dir, n);

        if(mobile == -1)
            break;

        int swapPos;

        if(dir[a[mobile]-1] == LEFT)
            swapPos = mobile - 1;
        else
            swapPos = mobile + 1;

        int temp = a[mobile];
        a[mobile] = a[swapPos];
        a[swapPos] = temp;

        mobile = swapPos;

        for(int i = 0; i < n; i++)
        {
            if(a[i] > a[mobile])
                dir[a[i]-1] *= -1;
        }

        printPermutation(a, n);
    }

    return 0;
}
