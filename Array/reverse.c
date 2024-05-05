#include <stdio.h>
//reverseing an array.
int main()
{
    int arr[10] = {1, 2, 4, 5, 6, 6, 7, 4, 6, 7};
    for (int i = 0, j = 9; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int c1 = 0; c1 < 10; c1++)
        printf("%d\t", arr[c1]);
    return 0;
}