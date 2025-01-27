#include <stdio.h>
#include <stdlib.h>

void findTriplet(int arr[], int size, int target)
{
    for (int index = 0; index < size - 2; index++)
    {
        int left = index + 1, right = size - 1;

        while (left < right)
        {
            int sum = arr[index] + arr[left] + arr[right];

            if (sum == target)
            {
                printf("Triplet found: (%d, %d, %d)\n", arr[index], arr[left], arr[right]);
                return;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    printf("No triplet found.\n");
}

int main()
{
    int size, target;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);
    printf("Enter %d sorted elements:\n", size);
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    findTriplet(arr, size, target);

    return 0;
}
