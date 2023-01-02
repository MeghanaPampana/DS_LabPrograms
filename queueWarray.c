#include<stdio.h>
int ch = 1, f = -1, r = -1, i, n, q[15], size;

void enq(){
	if(r == size - 1){
		printf("Queue Overflow\n");
		return;
	}
	printf("Enter element to enqueue: ");
	scanf("%d", &n);
	r++;
	q[r] = n; 
}

void deq(){
	if(f == r){
		printf("Queue Underflow\n");
		return;
	}
	f++;
}

void dis(){
	if(r == f){
		printf("No elements in queue\n");
		return;
	}
	printf("Queue:\n");
	for(i = f + 1 ; i <= r; i++)
		printf("\t%d", q[i]);
	printf("\n");
}

void main(){
	printf("Enter size of queue: ");
	scanf("%d", &size);
	while(ch != 0){
		printf("-----\n1.Enqueue\n2.Dequeue\n3.Display\n-----\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				enq();
				break;
			case 2:
				deq();
				break;
			case 3:
				dis();
				break;
			default:
				ch = 0;
				printf("Exited program\n");
		}
	}
}
