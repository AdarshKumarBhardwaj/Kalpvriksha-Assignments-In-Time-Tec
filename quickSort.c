#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partititon(int *arr, int lowerBound, int upperBound)
{
    int pivot = arr[lowerBound];
    int start = lowerBound;
    int end = upperBound;

    while (start < end)
    {

        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }

    swap(&arr[lowerBound], &arr[end]);
    return end;
}

void quickSort(int arr[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int lock = partititon(arr, lowerBound, upperBound);
        quickSort(arr, lowerBound, lock - 1);
        quickSort(arr, lock + 1, upperBound);
    }
}

void printArray(int arr[],int size){
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
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
    printArray(arr,size);
    quickSort(arr, 0, size - 1);
    printf("\nArray elements after sorting are\n");
    printArray(arr,size);
    return 0;
}

