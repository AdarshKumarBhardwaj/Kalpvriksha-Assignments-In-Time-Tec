#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void binarySearch(int *arr, int size, int element)
{
    int start = 0;
    int end = size - 1;
    bool isFound = 0;
    int elementIndex;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element)
        {
            isFound = 1;
            elementIndex = mid;
            break;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (isFound)
    {
        printf("\nElement %d present at %d index ", element, elementIndex);
    }
    else
    {
        printf("\nElement not found");
    }
}

int main()
{
    int size, element;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);

    printf("Enter the element for search\n");
    scanf("%d", &element);

    printf("Enter array elements\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Array elements are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }

    binarySearch(arr, size, element);
    return 0;
}
