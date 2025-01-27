#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size)
{
    for (int index1 = 0; index1 < size - 1; index1++)
    {
        int flag = 0;
        for (int index2 = 0; index2 < size - 1 - index1; index2++)
        {
            if (arr[index2] > arr[index2 + 1])
            {
                int temp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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

    bubbleSort(arr, size);
    printf("\nArray elements after sorting are\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    return 0;
}

