#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<limits.h>

int mandstable(int [], int);
int paranthesis(int s[][10], int i, int j)
{
	 if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        paranthesis(s,i,s[i][j]);
        paranthesis(s,s[i][j]+1,j);
        printf(")");
    }
}
int mandstable(int ar[], int s)
{
	int m[10][10]={0}; 
	int S[10][10]={0};
	int i, j,l,k,q;
	//int INT_MAX = 32767;
	
	for(i=1;i<s;i++)
	{
		m[i][i] = 0;
		S[i][i]=0;
	}
	for(i=2;i<s;i++)
	{
		for(j=1;j<i;j++)
		{
		   m[i][j]=0;
		   S[i][j]=0;
		}
	}
	for(l=2;l<s;l++)
	{
		for(i=1;i<s-l+1;i++)
		{
			j= i+l-1;
			m[i][j] = INT_MAX;
			
			for(k=i;k<=j-1;k++)
			{
				q = m[i][k] + m[k+1][j] + ar[i-1]*ar[k]*ar[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					S[i][j]=k;
				}
				
			}
			
		}
	}
	printf("Table m:\n");
	for(i=1;i<s;i++)
	{
		for(j=1;j<s;j++)
		{
			printf("%7d",m[i][j]);
		}
		printf("\n");
	}
	printf("Table s: \n");
	for(i=1;i<s;i++)
	{
		for(j=1;j<s;j++)
		{
			printf("%7d",S[i][j]);
		}
		printf("\n");
	}
    paranthesis(S,1,s-1);
}


int main()
{
	int i,n;
	printf("Enter number of matrices:");
	scanf("%d",&n);
	
	n++;
	int a[n];
	printf("Enter dimensions:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter a%d:",i);
		scanf("%d",&a[i]);
	}
	
	int size= sizeof(a)/sizeof(a[0]);
	
	printf("Table m and s:\n");
	mandstable(a,size);
    	
}
