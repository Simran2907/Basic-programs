#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *prevnode;
	struct node *nextnode;
};
struct node *head=0;
void create_list();
void insert_beg();
void insert_specified();
void insert_end();
void display();

int main()
{
	int num;
	do{
	   printf("\nWhat you want to do?");
	   printf("\n1.Create a list");
	   printf("\n2.Insertion at beginning");
	   printf("\n3.Insertion at given position");
	   printf("\n4.Insertion at end");
	   printf("\n5.Display");
	   printf("\n6.exit");
	   printf("\nEnter your choice:");
	   scanf("%d",&num);
	   switch(num)
	   {
	   	case 1: create_list();
	   	        break;
	   	case 2: insert_beg();
	   	        break;
	   	case 3: insert_specified();
	   	        break;
	   	case 4: insert_end();
	   	        break;
	   	case 5: display();
		        break;
		case 6: break;
	    default: printf("Wrong choice");
	   }
     }while(num!=6);	
}
void create_list()
{
    struct node *newnode1,*newnode2,*temp;
    int num;
    head = 0;
	newnode1 = (struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode1->data);
	newnode1->prevnode=0;
	newnode1->nextnode=0;
	if(head==0)
	{
		head = newnode1;		
	}
	temp=head;
	printf("Press 1 if you want to continue otherwise 0:");
	scanf("%d",&num);
	while(num!=0)
	{
		    newnode2 = (struct node *)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d",&newnode2->data);
			newnode2->prevnode = temp;
			newnode2->nextnode=0;	
			temp->nextnode=newnode2;
			temp=newnode2;	
			printf("Press 1 if you want to continue otherwise 0:");
			scanf("%d",&num);
	}
}
void insert_beg()
{
	if(head==0)
	{
		printf("underflow");
		return;
	}
	else
	{
		struct node *newnode,*ptr;
		newnode =(struct node *)malloc(sizeof(struct node));
		if(newnode==0)
		{
			printf("Cannot insert");
		}
		else
		{
			printf("Enter element you want to insert:");
			scanf("%d",&newnode->data);
			newnode->prevnode = 0;
			newnode->nextnode = head;
			head->prevnode = newnode;
			head=newnode;
		}
	}
}
void insert_specified()
{
	struct node *newnode, *ptr,*temp;
	int pos,count=1,c=1;
	if(head==0)
	{
		printf("underflow");
		return;
	}
	else
	{
	   newnode =(struct node *)malloc(sizeof(struct node));
	   if(newnode==0)
	   {
	   	  printf("Cannot insert");
	   	  return;
	   }	
	   else
	   {
	   	  int i;
		  printf("Enter element you want to insert:");
	   	  scanf("%d",&newnode->data);
	   	  printf("Enter position where you want to insert:");
	   	  scanf("%d",&pos);
	   	  ptr=head;
	   	  if(pos==1)
	   	  {
	   	  	 insert_beg();
		  }
		  else
		  {
		  	for(i=1;i<pos-1;i++)
		  	{
		  		ptr = ptr->nextnode;
			}
			newnode->nextnode=ptr->nextnode;
			newnode->prevnode=ptr->nextnode->prevnode;
			ptr->nextnode=newnode;
			
		  }
	   }
	}
}
void insert_end()
{
	if(head==0)
	{
		printf("underflow");
		return;
	}
	else
	{
		struct node *newnode,*ptr;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==0)
		{
			printf("Cannot enter elements");
			return;
		}
		else
		{
			printf("Enter element u want to insert");
			scanf("%d",&newnode->data);
		    ptr=head;
		    while(ptr->nextnode!=0)
		    {
		    	ptr=ptr->nextnode;
			}
			newnode->nextnode=0;
			newnode->prevnode=ptr;
			ptr->nextnode=newnode;
		}
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(head==0)
	{
		printf("List is empty");
	}
	else
	{
	   while(ptr->nextnode!=0)
	   {
	    	printf("%5d",ptr->data);
	    	ptr=ptr->nextnode;
	   }
	   printf("%5d",ptr->data);
	}
}
