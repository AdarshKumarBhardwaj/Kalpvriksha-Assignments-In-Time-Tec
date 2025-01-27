#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size)
{
    for (int index1 = 1; index1 < size; index1++)
    {
        int index2 = index1 - 1;
        int temp = arr[index1];
        while (index2 >= 0 && arr[index2] > temp)
        {
            arr[index2 + 1] = arr[index2];
            index2--;
        }
        arr[index2 + 1] = temp;
    }
}

int main()
{
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);

    printf("Enter the array elements\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Array elements are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }

    insertionSort(arr, size);
    printf("\nArray elements after sorting are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    return 0;
}
