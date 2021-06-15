#include<stdio.h>
#include<conio.h>
#define MAX 5
int front = -1;
int rear = -1;
int queue_arr[MAX];

void insert(int item)
{
	if(rear == MAX-1)
	   {
	     printf("Overflow\n");
	     return;
       }
	if(front == -1&& rear == -1)
	{
		front = 0;
		rear= 0;
	}
	else
	{
	  rear = rear + 1;
	}
	
	queue_arr[rear] = item;
	
}

void deletion()
{
	if(front == -1)
	{
		printf("underflow\n");
		return;
	}
	printf("Element deleted : %d\n",queue_arr[front]);
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
	  front = front + 1;
		
	}
}

void display()
{
	int front_pos = front, rear_pos = rear;
	printf("front :%d\nrear:%d\n",front_pos,rear_pos);
	if(front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Elements of Queue: ");
	if(front_pos <= rear_pos)
	  while(front_pos <= rear_pos)
	  {
		printf("%d\n",queue_arr[front_pos]);
		front_pos++;
	  }
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d\n",queue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
		   printf("%d\n",queue_arr[front_pos]);
		   front_pos++;	
		}
	}
	printf("\n");
}

int main()
{
	int item,choice;
	do
	{
		printf("1.Insertion\n");
		printf("2.Deletion\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
	    switch(choice)
	    {
		  case 1: printf("Element to be inserted: ");
		        scanf("%d",&item);
		        insert(item);
		    break;
		  case 2: deletion();
		    break;
		  case 3: display();
		    break;
		  case 4: break;
		  default: printf("Wrong choice");		
	    }
	}while(choice!=4);
	return 0;
}
