/*
#include <stdio.h>
#include <stdlib.h>


int ProcessArray(int *listA, int x, int n)
{
    int i,j,k;
    i = 0;
    j = n-1;
//    for (int xx = 0; xx < n; xx++)
//    {
//        printf("%d ", listA[xx]);
//    }
//    printf("%d %d", x, n);
    do
    {
        k = (i+j)/2;
        if (x <= listA[k])
        {
            j = k-1;
        }
        if (listA[k] <= x)
        {
            i = k+1;
        }
    } while (i <= j);

    if (listA[k] == x) return k;
    else return -1;
}

int main()
{
    int listA[] = {1,3,6,9,13,25,76,98};
    int n = sizeof(listA)/sizeof(listA[0]);
    int x = 98;
    int ans = ProcessArray(listA, x, n);
    printf("%d", ans);
    return 0;
}
*/
