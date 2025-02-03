#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int *arr, int size)
{
    for (int index1 = 0; index1 < size - 1; index1++)
    {
        int minIndex = index1;
        for (int index2 = index1 + 1; index2 < size; index2++)
        {
            if (arr[index2] < arr[minIndex])
            {
                minIndex = index2;
            }
        }
        if (minIndex != index1)
        {
            swap(&arr[index1], &arr[minIndex]);
        }
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
    selectionSort(arr, size);
    printf("\nArray elements after sorting are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    return 0;
}

