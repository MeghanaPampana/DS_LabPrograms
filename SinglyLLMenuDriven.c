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
	while(ch != 0) {
		printf("\n1.Display\n2.Ins B\n3.Ins E\n4.Ins P\n5.Del B\n6.Del E\n7.Del P\n\nSelect: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: 
				dis();
				break;
			case 2: 
				printf("Enter elem to insert: ");
				scanf("%d", &i);
				insB(i);
				break;
			case 3:
				printf("Enter elem to insert: ");
                	        scanf("%d", &i);
                        	insE(i);
	                        break;
			case 4:
				printf("Enter elem to insert and pos: ");
                        	scanf("%d %d", &i, &pos);
	                        insP(i, pos);
        	                break;
			case 5:
				delB();
				break;
			case 6: 
				delE();
				break;
			case 7:
				printf("Enter pos of elem to delete: ");
                                scanf("%d", &pos);
				delP(pos);
				break;
			default: 
				ch = 0;
		}
	}
}
/*
Output

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 1
Empty list

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 2
Enter elem to insert: 50
[Insert beginning: 50]
	List: 50 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 1
	List: 50 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 2
Enter elem to insert: 40
[Insert beginning: 40]
	List: 40 50 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 3
Enter elem to insert: 60
[Insert end: 60]
	List: 40 50 60 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 3
Enter elem to insert: 80
[Insert end: 80]
	List: 40 50 60 80 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 4
Enter elem to insert and pos: 70 4
[Insert at pos 4: 70]
	List: 40 50 60 70 80 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 5
[Delete beginning]
	List: 50 60 70 80 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 6
[Delete end]
	List: 50 60 70 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 7
Enter pos of elem to delete: 2
[Delete at pos 2]
	List: 50 70 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 5
[Delete beginning]
	List: 70 

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 5
[Delete beginning]
Empty list

1.Display
2.Ins B
3.Ins E
4.Ins P
5.Del B
6.Del E
7.Del P

Select: 0
*/
