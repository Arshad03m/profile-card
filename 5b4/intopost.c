#include<stdio.h>
#include<ctype.h>
#define max 5
int isp(char);
int icp(char);

void push(char);
char pop();

char infix[20];
char post[20];
char st[20];
int top=-1;
int main()
{
	char ch,ch1;
	int i1=0,i2=0;
	printf("Enter the AE in infix form (add ')') :");
	scanf("%s",infix);
	push('(');
	while(infix[i1]!='$')
	{
		ch=infix[i1++];
		if(isalpha(ch))
		post[i2++]=ch;
		else
		{
			switch(ch)
			{
				case ')':
				while(st[top]!='(')
				{
					post[i2++]=pop();
				}
				pop();
				break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
				case '(':
				ch1=pop();
				if(icp(ch)>isp(ch1))
				{
					push(ch1);
					push(ch);
				}
				else
				{
					while(icp(ch)>=isp(ch1))
					{
						post[i2++]=pop();
					}
				}
				break;
			}
		}
	}
	if(top>=0)
	{
		while(top!=0)
		{
			post[i2++]=pop();
		}
	}
	printf("\npostfix expression:");
	for(int k=0;k<i2;k++)
	{
		printf("%c",post[k]);
	}
	return 0;
}

			
int icp(char c)
{
	switch(c)
	{
		case '+':
		case '_':
		return 1;
		case '*':
		case '/':
		return 3;
		case '^':
		return 5;
		case '(':
		return 7;
		case ')':
		return 0;
	}
}

int isp(char c)
{
	switch(c)
	{
		case '+':
		case '_':
		return 2;
		case '*':
		case '/':
		return 4;
		case '^':
		return 6;
		case '(':
		return 0;
		case ')':
		return -1;	
	}
}

void push(char n)
{
	if(top==max-1)
	printf("\t______Stack Overflow!______\n");
	else{
		top=top+1;
		st[top]=n;
			
	}
	printf("\n");
}
char pop()
{
	if(top==-1)
	printf("\nStack empty\n");
    
	else
	return st[top--];
}
