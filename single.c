#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *nxt;
}node;
node *t, *head, *del;
int val, pos, i;

void insBeg(){
	node *new;
	printf("Enter val to insert: ");
	scanf("%d", &val);
	new = (node *)malloc(sizeof(node));
	new -> data = val;
	if(head == NULL)
		new -> nxt = NULL;
	else
		new -> nxt = head;
	head = new;
	printf("Inserted");
}

void insEnd(){
        node *new;
        printf("Enter val to insert: ");
        scanf("%d", &val);
        new = (node *)malloc(sizeof(node));
        new -> data = val;
	new -> nxt = NULL;
	if(head == NULL)
		head = new;
	else{
		t = head;
		while(t -> nxt != NULL)
			t = t -> nxt;
		t -> nxt = new;
	}
	printf("Inserted");
}

void insPos(){
	printf("Enter position to insert: ");
	scanf("%d", &pos);
	printf("Enter val to insert: ");
        scanf("%d", &val);
	node *new;
	new = (node *)malloc(sizeof(node));
        new -> data = val;
	t = head;
	for(i = 1; i < pos - 1; i++){
		if(t -> nxt == NULL){
			printf("Out of range");
			return;
		}
		else
			t = t -> nxt;
	}
	new -> nxt = t -> nxt;
	t -> nxt = new;
	printf("Inserted");
}

void delBeg(){
	if(head == NULL)
		printf("Empty list");
	else{
		t = head;
		head = head -> nxt;
		free(t);
		printf("Deleted");
	}
}

void delEnd(){
	if(head == NULL)
                printf("Empty list");
        else{
                t = head;
                while(t -> nxt -> nxt != NULL)
			t = t -> nxt;
	       	del = t -> nxt;
		t -> nxt = NULL;
                free(del);
                printf("Deleted");
        }
}

void delPos(){
	if(head == NULL)
                printf("Empty list");
	else{
		printf("Enter position to delete: ");
	        scanf("%d", &pos);
		t = head;
		for(i = 1; i < pos - 1; i++){
        	        if(t -> nxt == NULL){
                	        printf("Out of range");
                        	return;
	                }
        	        else
                	        t = t -> nxt;
	        }
		del = t -> nxt;
		t -> nxt = del -> nxt;
		free(del);
		printf("Deleted");
	}
}

void dis(){
	if(head == NULL)
		printf("Empty list");
	else{
		t = head;
		printf("List: ");
		while(t != NULL){
			printf("%d ", t -> data);
			t = t -> nxt;
		}
	}
}

void search(){
	if(head == NULL)
                printf("Empty list");
	else{
		printf("Enter val to search: ");
       		scanf("%d", &val);
		int idx = 0, flag = 0;
		t = head;
		while(t != NULL){
			if(t -> data == val){
				printf("'%d' found at postion %d", val, idx + 1);
				flag = 1;
				break;
			}
			idx++;
			t = t -> nxt;
		}
		if(flag == 0)
			printf("Not found");
	}
}

void main(){
	int ch = 1;
	while(ch != 9){
		printf("----\n1.Insert Beginning\n2.Insert End\n3.Insert at position\n4.Delete Beginning\n5.Delete End\n6.Delete at position\n7.Display\n8.Search\n----\nSelect choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: insBeg();
				break;
			case 2: insEnd();
				break;
			case 3: insPos();
				break;
			case 4: delBeg();
				break;
			case 5: delEnd();
				break;
			case 6: delPos();
				break;
			case 7: dis();
				break;
			case 8: search();
				break;
			default: ch = 9;
		}
		printf("\n");
	}
}
