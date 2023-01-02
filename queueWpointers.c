#include<stdio.h>
int ch = 1, i, n, size;

struct qu {
	int f, r, q[15];
};

void initq(struct qu *p){
	p -> f = -1;
	p -> r = -1;
}

void enq(struct qu *p){
	if(p -> r == size - 1){
		printf("Queue Overflow\n");
		return;
	}
	printf("Enter element to enqueue: ");
	scanf("%d", &n);
	p -> r++;
	p -> q[p -> r] = n; 
}

void deq(struct qu *p){
	if(p -> f == p -> r){
		printf("Queue Underflow\n");
		return;
	}
	p -> f++;
}

void dis(struct qu *p){
	if(p -> r == p -> f){
		printf("No elements in queue\n");
		return;
	}
	printf("Queue:\n");
	for(i = p -> f + 1 ; i <= p -> r; i++)
		printf("\t%d", p -> q[i]);
	printf("\n");
}

void main(){
	struct qu ptr;
	initq(&ptr);
	printf("Enter size of queue: ");
	scanf("%d", &size);
	while(ch != 0){
		printf("-----\n1.Enqueue\n2.Dequeue\n3.Display\n-----\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				enq(&ptr);
				break;
			case 2:
				deq(&ptr);
				break;
			case 3:
				dis(&ptr);
				break;
			default:
				ch = 0;
				printf("Exited program\n");
		}
	}
}
