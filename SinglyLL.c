#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}n;

n *head = NULL, *new, *t;
int ch = 1, pos, i;

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

void insB(int val) {
	printf("[Insert beginning: %d]\n", val);
	new = (n *)malloc(sizeof(n));
	new -> data = val;
	if(head == NULL) 
		new -> next = NULL;
	else
		new -> next = head;
	head = new;
	dis();
}

void insE(int val) {
	printf("[Insert end: %d]\n", val);
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

void insP(int val, int pos) {
	printf("[Insert at pos %d: %d]\n", pos, val);
	new = (n *)malloc(sizeof(n));
	new -> data = val;
	if(head == NULL) {
		new -> next = NULL;
		head = new;
	}
	else {
		t = head;
		while(pos != 2) {
			t = t -> next;
			pos--;
		}
		new -> next = t -> next;
		t -> next = new;
	}
	dis();
}
	
void delB() {
	printf("[Delete beginning]\n");
	t = head;
	head = head -> next;
	free(t);
	dis();
}

void delE() {
	n *q;
        printf("[Delete end]\n");
        t = head;
	while(t -> next != NULL) {
		q = t;
		t = t -> next;
	}
	q -> next = NULL;
        free(t);
        dis();
}

void delP(int pos) {
	n *q;
	printf("[Delete at pos %d]\n", pos);
        t = head;
        while(pos != 1) {
                q = t;
                t = t -> next;
		pos--;
        }
        q -> next = t -> next;
        free(t);
        dis();
}

void main() {
	insB(15);
	insB(14);
	insE(20);
	insP(17, 3);
	insP(18, 4);
	insP(19, 5);
	insP(16, 3);
	delB();
	delE();
	delP(3);
	delP(2);
}
/*
Output
[Insert beginning: 15]
	List: 15 
[Insert beginning: 14]
	List: 14 15 
[Insert end: 20]
	List: 14 15 20 
[Insert at pos 3: 17]
	List: 14 15 17 20 
[Insert at pos 4: 18]
	List: 14 15 17 18 20 
[Insert at pos 5: 19]
	List: 14 15 17 18 19 20 
[Insert at pos 3: 16]
	List: 14 15 16 17 18 19 20 
[Delete beginning]
	List: 15 16 17 18 19 20 
[Delete end]
	List: 15 16 17 18 19 
[Delete at pos 3]
	List: 15 16 18 19 
[Delete at pos 2]
	List: 15 18 19 
*/
