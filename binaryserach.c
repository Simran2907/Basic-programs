#include<stdio.h>
#include<math.h>
int binarysearch(int arr[], int s, int n, int first, int last)
{
	int mid;
	if(first<=last)
	  {
     	int mid;
        mid= (first +last)/2;
		if(s==arr[mid]) 
		{
		    printf("Element found at %d position", mid + 1);
		    return;
	    }
	    else
	    {
	    	if(s<arr[mid])
			    binarysearch(arr,n,s,0,mid-1);
		    else
		       binarysearch(arr,n,s,mid+1,last);
	    }
	}
	 else
      {
	     printf("Not found! %d isn't present in the list.\n", s);
         return;
      }
	
}
int main()
{
	int n,i,search, arr[50],first,last; 
	
	printf("enter number of elments: ");
	scanf("%d/n",&n);
	
	printf("elements are : ");
	for(i=0;i<n;i++)
	  scanf("%d", &arr[i]);
	  
	printf("Enter the element you want to search: ");
	scanf("%d",&search);
	
	first = 0;
	last = n-1;	
	binarysearch(arr, search , n, first, last);
    
    return 0;
}
