#include <stdio.h>
#include <math.h>

int a(int);
int s(int);
int find(int);
void showAns(int);

int main()
{
    int n;
    printf("Enter an positive integer n: ");
    scanf("%d", &n);
    showAns(n);
    return 0;
}

int a(int k)
{
    // number of digits in the k-th group
    if (k==0) return 0;
    int alpha = floor(log10(k));
    int sum =0;
    for (int i=0; i<=alpha; i++)
        sum += (k - pow(10,i) + 1);
    return sum;
}

int s(int k)
{
    // number of digits in the k-th sequence
    int sum = 0;
    for (int i=0; i<=k; i++)
        sum += a(i);
    return sum;
}

int find(int l)
{
    // the l-th digit is the u-th digit (from the left) of the number t
    // compute t and u
    int t=0;
    while (a(t)-l<0) t++;
    int u = l - a(t-1);
    printf("\nAnd this digit is the u-th dight(from the left) of the number t, where\n");
    printf("t = %d\n", t);
    printf("u = %d\n", u);
    // find the digit
    int position = (int)log10(t) - u + 2;
    int ans = (t/(int)pow(10, position-1))%10;
    return ans;
}

void showAns(int n)
{
    // n is the l-th digit of the k-th group
    int k = 0;
    printf("\nn is the l-th digit of the k-th group, where\n");
    while (s(k)-n<0) k++;
    int l = n - s(k-1);
    printf("k = %d\n", k);
    printf("l = %d\n", l);
    printf("\nSo, X(%d) = %d\n", n, find(l));
}
