#include<stdio.h>
int linear(int a[15], int size, int key)
{
	for(int i = 0; i < size; i++)
	{
		if(a[i] == key)
			return i;
	}
	return -1;
}

void main()
{
	int n, arr[15], i, k, idx;
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("Enter %d elements: ", n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Enter key to find: ");
	scanf("%d", &k);
	idx = linear(arr, n, k);
	if(idx == -1)
		printf("Element %d not present\n", k);
	else
		printf("Element present at %d position\n", idx + 1);
}
/* 
Enter size of array: 5
Enter 5 elements: 1 4 2 5 6
Enter key to find: 2
Element present at 3 position
*/
