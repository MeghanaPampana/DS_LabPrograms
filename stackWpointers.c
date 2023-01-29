#include<stdio.h>
int i, n, s, ch = 1;

struct st{
	int top, stack[15];
};

void init_st(struct st *p){
	p -> top = -1;
}

void push(struct st *p)
{
	if(p -> top == s - 1)
		printf("Stack overflow\n");
	else
	{
		printf("Enter number to push: ");
	        scanf("%d", &n);
		p -> top++;
		p -> stack[p -> top] = n;
	}
}

void pop(struct st *p)
{
	if(p -> top == -1)
		printf("Stack underflow\n");
	else
		p -> top--;
}

void display(struct st *p)
{
	if(p -> top == -1)
		printf("No elements to display\n");
	else
	{
		printf("Stack: \n");
		for(i = p -> top; i > -1; i--)
			printf("\t%d\n", p -> stack[i]);
	}
}

void main()
{
	struct st ptr;
	init_st(&ptr);
	printf("Enter size of stack: ");
	scanf("%d", &s);
	while(ch != 0)
	{
		printf("--------------\n1.Push  \n2.Pop  \n3.Display\n--------------\nEnter choice: ");
       	scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push(&ptr);
				break;
			case 2:
				pop(&ptr);
				break;
			case 3:
				display(&ptr);
				break;
			default:
				ch = 0;
				printf("Exited program\n");
		}
	}
}
/*
Enter size of stack: 5
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 1
Enter number to push: 84
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 1
Enter number to push: 54
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 3
Stack: 
        54
        84
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 2
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 3
Stack: 
        84
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 0
Exited program
*/
