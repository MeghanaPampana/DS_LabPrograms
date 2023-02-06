#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *prev;
}n;

n *top = NULL, *t, *new;

void dis() {
	t = top;
	if(top == NULL)
		printf("Empty stack\n");
	else {
		printf("Stack:\n");
		while(t != NULL) {
			printf("\t%d\n", t -> data);
			t = t -> prev;
		}
	}
}

void push(int val) {
	printf("[Push %d]\n", val); 
	new = (n *)malloc(sizeof(n));
	new -> data = val;
	if(top == NULL) 
		new -> prev = NULL;
	else
		new -> prev = top;
	top = new;
	dis();
}

void pop() {
	if(top == NULL)
		printf("Stack underflow\n");
	else {
		printf("[Pop]\n");
		t = top;
		top = t -> prev;
		free(t);
		dis();
	}
}

void main() {
	push(50);
	push(60);
	push(70);
	pop();
	pop();
}
