#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	char ch, op;
	double num1, num2, result;
    
	do
	{
		cout <<"********MAIN*********";
		cout <<"\n1.Add.";
		cout <<"\n2.Subtract.\n3.Divison.\n4.Multiplication"<< endl;
		cout << "Enter first number, operator, second number"<< endl;
		cin >>num1>>op>>num2;
		switch(op)
		{
			case '+' : result = num1 + num2;
			   cout <<"Result = "<<result<< endl;
			   break;
			   
			case '-' : result = num1 - num2;
			   cout <<"Result = "<<result<< endl;
			   break;
			   
			case '/' : result = num1 / num2;
			   cout <<"Result = "<<result<< endl;
			   break;
			
			case '*' : result = num1 * num2;
			   cout <<"Result = "<<result<< endl;
			   break;
			   
			default : cout<<"\nWrong Choice.";			
			
		}
		
		cout<<"/nDo you want to continue(y/n):: ";
		cin>>ch;
	}while(ch=='y' || ch == 'Y');
	getch();
	return 0;
	
}
