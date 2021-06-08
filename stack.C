#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define MAX 5

int top = -1, stack[MAX];
void push();
void pop();
void display();

int main()
{
   char ch;
   while(1)
   {
     printf("whats your choice?");
     printf("\n1.Push \n2.pop\n");
     scanf("%d",&ch);
	 
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
		    case 3: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
	  
}
void display()
{
	int i;
	if(top == -1)
	{
		 printf("Stack is empty");
	}
	else
	{
	  printf("E;ement in stacks:");
	  for(i=top;i>=0;i--)
      {
		printf("%d\n",stack[i]);
	  } 
    }
}
void push()
{
	int val;
	if(top == MAX  - 1)
	{
		printf("Stack is full");
		
	}
	else
	{
		printf("Enter the value you want to push\n");
		scanf("%d",&val);
		top = top + 1;
		stack[top] = val;
		display();
	}
}

void pop()
{
	if(top == -1)
	{
		printf("stack is empty");
	}
	else
	{
		printf("\nDeleted item is %d\n",stack[top]);
		top= top - 1;
		display();
	}
}
