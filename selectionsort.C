#include<stdio.h>
#include<conio.h>

void printarray(int arr[],int n)
{
	int i;
	printf("Enter sorted element:");
	for(i=0;i<n;i++)
	  printf("%d\n",arr[i]);
}

void selection(int arr[], int  n)
{
    int temp,i,j,loc;
	for(i=0;i<n-1;i++)
	{
	   loc =i;
	   for(j=1;j<n;j++)
	     if(arr[j]< arr[i])	
		 {
			loc = j;  
		 }
	    
		if(loc != i)
		{
		  temp = arr[i];
          arr[i] = arr[loc];
          arr[loc] = temp;
        }
  }
		printarray(arr,n);    
    
}

int main()
{
	int arr[10],n,i, loc;
	
	printf("Enter no of element in array:");
	scanf("%d",&n);
	
	printf("Enter element of array:");
	for(i=0;i<n;i++)
	  scanf("%d",&arr[i]);
    
	printarray(arr, n);	  
	selection(arr, n);
	printarray(arr, n);
	return 0;
}
