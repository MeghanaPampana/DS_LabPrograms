#include<stdio.h>
int n, i, stack[15], top = -1, s, ch = 1;

void push()
{
	if(top == s - 1)
		printf("Stack overflow\n");
	else
	{
		printf("Enter number to push: ");
		scanf("%d", &n);
		top++;
		stack[top] = n;
	}
}

void pop()
{
	if(top == -1)
		printf("Stack underflow\n");
	else
		top--;
}

void display()
{
	if(top == -1)
		printf("No elements to display\n");
	else
	{
		printf("Stack:\n");
		for(i = top; i > -1; i--)
			printf("\t%d\n", stack[i]);
	}
}

void main()
{
	printf("Enter size of stack: ");
	scanf("%d", &s);
	while(ch != 0)
	{
		printf("--------------\n1.Push  \n2.Pop  \n3.Display\n--------------\nEnter choice: ");
       		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				ch = 0;
		}
	}
}
/*
Enter size of stack: 3
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 1
Enter number to push: 56
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 1
Enter number to push: 9
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 3
Stack:
        9
        56
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
        56
--------------
1.Push  
2.Pop  
3.Display
--------------
Enter choice: 0
*/
