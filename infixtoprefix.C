#include<stdio.h>
#include<ctype.h>
#include<conio.h>

char stack[100];
int top= -1;

void push(char x)
{
	stack[++top] = x; //increment stack i.e ++ increment stack first then top = x
}

char pop()
{
	if(top == -1)
	  return -1;
	else
	  return stack[top--]; //frist it return top value then it decreses
}

int priority(char x)
{
	if(x == '(')
	   return 0;
	if(x == '+' || x == '-')
	   return 1;
	if(x == '*'||x == '/')
	   return 2;
	return 0;
}

int main()
{
	char exp[100], result[100];  // e/d-)c-b(+a
	char *e, x;
	int i,j=0;
	printf("Enter the expression:");
	scanf("%s",exp);
	printf("\n");
	e = exp; //address given
	
	for(i=0;i<strlen(*e);i++)
	
	{
		if(isalnum(*e)) //islanum=it check operands
		  result[j] = *e;
		  j++;
		else if(*e == ')')
		  push(*e);
		else if(*e == '(')
		{
			while((x = pop()) != ')')  // x taking top value
			   printf("%c",x);
		}
		else
		{
			while(priority(stack[top]) > priority(*e)) // stack[top] = *, *e = +
                    result[j]=pop();
                    j++;
		            push(*e);
		}
		e++;
	}
	while(top != -1)
	 {
	 	result[j]=pop();
	 	j++;
	 }
	 result[j]= '\0';
	 puts((result));
	 getch();
	 return 0;
}
