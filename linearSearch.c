#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void linearSearch(int *arr, int size, int element)
{
    bool isFound = 0;
    int elementIndex;
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == element)
        {
            isFound = 1;
            elementIndex = index;
            break;
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

    linearSearch(arr, size, element);
    return 0;
}
