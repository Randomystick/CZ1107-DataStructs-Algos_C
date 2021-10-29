#include <stdio.h>

int main()
{
    Q3b(2);
}
void Q3b(int N)
{
    int i;
    if (N>0)
    {
        for (int i = 0; i<N; i++)
        {
            printf("CZ1107\n");
        }
        Q3b(N-1);
        Q3b(N-1);
    }
}
