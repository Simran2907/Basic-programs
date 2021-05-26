#include<stdio.h>
#include<conio.h>
void swap(int*,int*);
int partition(int arr[],int,int);
int quick_sort(int arr[],int,int);
void print_array(int arr[],int);
void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int j;
	int i=low-1;
	for( j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
int quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
	int pi=partition(arr,low,high);
	quick_sort(arr,low,pi-1);
	quick_sort(arr,pi+1,high);
	return 0;
}
}
void print_array(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
}
int main()
{
	int k;
	int arr[100],n;
	printf("Enter how many elements u want to enter into array:");
	scanf("%d",&n);
	printf("enter %d elements",n);
	for(k=0;k<n;k++)
	{
		scanf("%d",&arr[k]);
	}
	quick_sort(arr,0,n-1);
	printf("Array after sortning is\n");
	print_array(arr,n);
	getch();
	return 0;
}
