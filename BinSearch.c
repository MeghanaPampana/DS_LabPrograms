#include<stdio.h>
int binary(int a[15], int low, int high, int key)
{
	int mid, i;	
	while(low <= high)
	{
		mid = (high + low)/ 2;
		if(key < a[mid])
			high = mid - 1;
		else if(key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

void main()
{
	int n, arr[15], i, idx, k;
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("Enter %d sorted elements: ", n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Enter key to find: ");
	scanf("%d", &k);
	idx = binary(arr, 0, n - 1, k);
	if(idx == -1)
		printf("Element %d is not present\n", k);
	else
		printf("Element is present at %d position\n", idx + 1);
}
/*
Enter size of array: 5
Enter 5 sorted elements: 10 20 30 40 50
Enter key to find: 10
Element is present at 1 position
*/
