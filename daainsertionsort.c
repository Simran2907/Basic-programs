#include<stdio.h>
#include<math.h>

void insertionsort(int A[],int n)
{
	int i, j,key;
	for(j=1;j<n;j++)
	{
	  key = A[j];
	  i= j-1;
	  while(i>-1&&A[i]>key)
	  {
	  	A[i+1]=A[i];
	  	i= i-1;
	  }
	  A[i+1]=key;	
	}
}

void printarray(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%5d",A[i]);
	}
}
int main()
{
	int arr[] = {10, 5, 23, 6, 7, 12};
	int size_arr = sizeof(arr)/ sizeof(arr[0]);
	
	printf("Element before insertion sort:");
	printarray(arr, size_arr);
	insertionsort(arr,size_arr);
	printf("\nElement after insertion sort:");
	printarray(arr,size_arr);
	
	return 0;
}
