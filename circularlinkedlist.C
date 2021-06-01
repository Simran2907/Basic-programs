#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = 0;
void createlist()
{
	struct node *newnode1,*newnode2;
	int c;
    newnode1 = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &newnode1->data);
    newnode1->next = newnode1;
    head = newnode1;
    printf("If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
        newnode2 = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", &newnode2->data);
        newnode1->next = newnode2;
        newnode2->next = head;
        newnode1 = newnode2;
        printf("If you wish to continue press 1 otherwise 0:");
        scanf("%d", &c); 
    };
	
}
void insert_beg()
{
	struct node *temp,*newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	temp = head;
	printf("\nEnter element you want to insert:");
	scanf("%d",&newnode->data);
	while(temp->next!=head)
	{
		temp= temp->next;
	}
	temp->next=newnode;
	newnode->next= head;
	head = newnode;
}
void insert_after_element()
{
	struct node *ptr,*newnode;
	int var, element;
	if(head == 0)
	{
		printf("You cannot insert element");
	}
	else
	{
	   printf("\nEnter element you want to insert and after which element");
	   scanf("%d%d",&var,&element);
	   newnode = (struct node *)malloc(sizeof(struct node));
	   newnode->data=var;
	   ptr = head;
	   while(ptr->data!= element)
	   {
	    	ptr = ptr->next;
	   }
	   newnode->next= ptr->next;
	   ptr->next = newnode;
    }
}
void insert_specified()
{
	struct node *ptr,*newnode,*x,*temp;
	int pos,count=1,c=1;	
	newnode = (struct node *)malloc(sizeof(struct node));
	if(head==0)
	{
		printf("U cannot enter an element");
	}
	else
	{
		printf("Enter element u want to insert:");
		scanf("%d",&newnode->data);
		printf("Enter position where u want to insert:");
		scanf("%d",&pos);
		ptr = head;
		temp = head;
		while(ptr->next!=head)
		{
			count++;
			ptr= ptr->next;
		}
		count++;
		if(pos>count)
		{
			printf("U cannot enter element");
			return;
		}
		while(c<pos)
		{
			x = temp;
			temp=temp->next;
			c++;
		}
		newnode->next=temp;
		x->next=newnode;
		
	}
}

void insert_end()
{
	struct node *ptr,*newnode;
	int var;
	ptr = head;
	printf("\nEnter element you want to insert:");
	scanf("%d",&var);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=var;
	while(ptr->next!=head)
    {
    	ptr = ptr->next;
	}
	newnode->next= head;
	ptr->next = newnode;
		
}
void delete_beg()
{
	if(head == 0)
	{
		printf("list is empty");
	}
	else
	{
		struct node *temp,*ptr;
	    temp = head;
	    ptr = head;
	    while(temp->next!= head)
	    {
		   temp = temp->next;
	    }
	    head = ptr->next;
	    temp->next = head;
	    free(ptr);
	}
	
}

void delete_after_element()
{
	if(head==0)
	{
		printf("list is empty");
	}
	else
	{
		struct node *ptr,*temp;
	    int var;
	    printf("\nEnter element after which you want to delete element:");
	    scanf("%d",&var);
	    ptr = head;
	    while(ptr->data!=var)
	   {
 	  	  ptr= ptr->next;
	   }
	   temp= ptr->next;
	   ptr->next = temp->next;
    }
}
void delete_specified()
{
	struct node *ptr, *temp, *x;
	int pos,count=1,c=1;
	if(head==0)
	{
		printf("Underflow");
	}
	else
	{
		printf("Enter position where u want to delete element:");
		scanf("%d",&pos);
		ptr=head;
		temp = head;
		while(ptr->next!=head)
		{
			count++;
			ptr=ptr->next;
		}
		count++;
		if(pos>count)
		{
			printf("U cannot delete element");
			return;
		}
		while(c<pos)
		{
			x = temp;
			temp= temp->next;
			c++; 
		}
		x->next=temp->next;
		free(temp);
	}
}
void delete_end()
{
   if(head == 0)
   {
   	printf("list is empty");
   }
   else
   {
      struct node *ptr;
      ptr = head;
      while((ptr->next)->next!=head)
      {
   	     ptr = ptr->next;
      }
      ptr->next = head;
   }
}

void display()
{
	struct node *ptr;
	ptr = head;
	if(ptr==0)
	{
		printf("list is empty");
	}
	else
	{
	   while(ptr->next!=head)
	   {
	    	printf("%5d",ptr->data);
		    ptr=ptr->next;
	   }
	   printf("%5d",ptr->data);
    }
}


int main()
{
	int choice;
	do
	{
	   printf("\nWhat you want to do?");
	   printf("\n1.Create list");
	   printf("\n2.Insertion at the beginning");
	   printf("\n3.Insertion after an element");
	   printf("\n4.Insertion at specified position");
       printf("\n5.Insertion at end");
	   printf("\n6.Deletion from beginning");
	   printf("\n7.Deletion after a element");
	   printf("\n8.Deletion at specified position");
	   printf("\n9.Deletion from end");
	   printf("\n10.Display");
	   printf("\n11.Exit");
	   printf("\nEnter your choice:");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	   	case 1: createlist();
	   	        break;
	   	case 2: insert_beg();
	   	        break;
	   	case 3: insert_after_element();
	   	        break;
	   	case 4 :insert_specified();
		        break;
		case 5: insert_end();
	   	        break;
	   	case 6: delete_beg();
	   	        break;
	   	case 7: delete_after_element();
	   	        break;
	   	case 8: delete_specified();
		        break;
		case 9: delete_end();
	   	        break;
	   	case 10: display();
	   	        break;
	   	case 11: break;
	   	deafult: printf("wrong choice");
	   }
    }while(choice!=11);
	getch();
}
