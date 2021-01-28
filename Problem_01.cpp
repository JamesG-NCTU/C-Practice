#include <stdio.h>

void printArray(int [], int);
void setArray(int [],int, int);
int checkArray(int [],int [],int);
void showComb(int, int);

int main()
{
    int n, k;

    printf("Enter two non-negative integers n >= k >= 0\n");
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    if (n<k)
    {
        printf("n cannot less than k.\n");
        return 0;
    }

    printf("\nAll k-combinations of the n objects:\n");

    showComb(n, k);

    return 0;
}

void printArray(int a[],int k)
{
    for(int i=0; i<k; i++)
        printf("%d", a[i]);
    printf("\n");
}

void setArray(int a[],int k, int m)
{
    if (m<k)
    {
        a[k-1-m] += 1;
        for (int i=k-m; i<k; i++)
            a[i] = a[k-1-m] + i - (k-m-1);
    }
}

int checkArray(int a[],int b[],int k)
{
    int num = 0;
    for (int i=0; i<k; i++)
    {
        if (a[i] == b[i])
            num += 1;
    }
    return num;
}

void showComb(int n, int k)
{
    int comb[k], fin[k];
    for (int i=0; i<k; i++)
        comb[i] = i+1;
    for (int i=0; i<k; i++)
        fin[i] = n-k+1+i;

    int m = 0;
    do
    {
        printArray(comb, k);
        m = checkArray(comb, fin, k);
        setArray(comb, k, m);
    } while (m < k);
}
