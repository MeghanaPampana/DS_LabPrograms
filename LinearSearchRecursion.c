#include<stdio.h>
int linear(int a[15], int size, int key, int idx)
{
	if(a[idx] == key){
		return idx;
	}
	else if(idx == size){
		return -1;
	}
	else{
		return linear(a, size, key, idx + 1);
	}
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
	idx = linear(arr, n, k, 0);
	if(idx == -1)
		printf("Element %d not present\n", k);
	else
		printf("Element present at %d position\n", idx + 1);
}
/*
Enter size of array: 5
Enter 5 elements: 8 7 9 4 0
Enter key to find: 4
Element present at 4 position
*/
