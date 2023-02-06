#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}n;

n *head = NULL, *new, *t;
int  i;

void dis() {
	if(head == NULL) {
		printf("Empty list\n");
	}
	else {
		printf("\tList: ");
		t = head;
		while(t != NULL) {
			printf("%d ", t -> data);
			t = t -> next;
		}
		printf("\n");
	}
}

void enq(int val) {
	printf("[Enqueue: %d]\n", val);
	new = (n *)malloc(sizeof(n));
	new -> data = val;
	new -> next = NULL;
	if(head == NULL) {
		head = new;
	}
	else {
		t = head;
		while(t -> next != NULL) {
			t = t -> next;
		}
		t -> next = new;
	}
	dis();
}
	
void deq() {
	printf("[Dequeue]\n");
	t = head;
	head = head -> next;
	free(t);
	dis();
}


void main() {
	enq(10);
	enq(20);
	enq(30);
	deq();
	deq();
	deq();
}
/*
Output
[Enqueue: 10]
	List: 10 
[Enqueue: 20]
	List: 10 20 
[Enqueue: 30]
	List: 10 20 30 
[Dequeue]
	List: 20 30 
[Dequeue]
	List: 30 
[Dequeue]
Empty list
*/
