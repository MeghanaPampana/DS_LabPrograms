#include<stdio.h>

void insertion(int a[15], int size)
{
	int i, j, temp;
	for(i = 1; i < size; i++)
	{
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void main()
{
        int n, i, arr[15];
        printf("Enter size of array: ");
        scanf("%d", &n);
        printf("Enter %d elements: ", n);
        for(i = 0; i < n; i++)
                scanf("%d", &arr[i]);
        printf("Elements are: \n");
        for(i = 0; i < n; i++)
                printf("%d ", arr[i]);
        insertion(arr, n);
        printf("\nElements after sorting: \n");
        for(i = 0; i < n; i++)
                printf("%d ", arr[i]);
}

