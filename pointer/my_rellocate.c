// rellocate the dynamicla allocated memory with out lose any kind of data.
#include <stdio.h>
#include <stdlib.h>
int *my_rellocate(int *, int, int);
int main()
{
    int n;
    printf("enter the size of array :");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("enter the array element's :");
    for (int c1 = 0; c1 < n; c1++)
    {
        scanf("%d", ptr + c1);
    }
    int new_size;
    printf("before the my_rellocate() : %d\n", ptr);
    printf("enter the new size of array :");
    scanf("%d", &new_size);
    ptr = my_rellocate(ptr, n, new_size);
    printf("after the my_rellocate() %d\n", ptr);
    printf("after the my_rellocate() elemennt's :");
    for (int c1 = 0; c1 < new_size; c1++)
    {
        printf("%-20d", *(ptr + c1));
    }
    return 0;
}

int *my_rellocate(int *ptr, int old_size, int new_size)
{
    int *ptr_rel = (int *)malloc(new_size * sizeof(int));
    for (int c1 = 0; c1 < old_size; c1++)
    {
        ptr_rel[c1] = *(ptr + c1);
    }
    free(ptr);                                                  // if frre() then compliler reassign the address to ptr.
    ptr = (int *)malloc(new_size * sizeof(int));
    for (int c1 = 0; c1 < old_size; c1++)
    {
        ptr[c1] = *(ptr_rel + c1);
    }
    return ptr;
}
