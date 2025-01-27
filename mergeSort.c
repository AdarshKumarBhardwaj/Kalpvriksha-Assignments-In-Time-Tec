#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int lowerBound, int mid, int upperBound)
{
    int index1 = lowerBound;
    int index2 = mid + 1;
    int index3 = lowerBound;
    int *result = (int *)malloc(sizeof(int) * (upperBound + 1));

    while (index1 <= mid && index2 <= upperBound)
    {
        if (arr[index1] <= arr[index2])
        {
            result[index3] = arr[index1];
            index1++;
            index3++;
        }
        else
        {
            result[index3] = arr[index2];
            index2++;
            index3++;
        }
    }
    if (index1 > mid)
    {
        while (index2 <= upperBound)
        {
            result[index3] = arr[index2];
            index2++;
            index3++;
        }
    }
    else
    {
        while (index1 <= mid)
        {
            result[index3] = arr[index1];
            index1++;
            index3++;
        }
    }
    for (int index = lowerBound; index <= upperBound; index++)
    {
        arr[index] = result[index];
    }
}

void mergeSort(int *arr, int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int mid = (lowerBound + upperBound) / 2;
        mergeSort(arr, lowerBound, mid);
        mergeSort(arr, mid + 1, upperBound);
        merge(arr, lowerBound, mid, upperBound);
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

    mergeSort(arr, 0, size - 1);
    printf("\nArray elements after sorting are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    return 0;
}