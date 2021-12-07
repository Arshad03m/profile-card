#include<stdio.h>
#include<ctype.h>
#define max 20
void display();
int pop();
void push(int);
char post[20];
int st[max],top=-1;
int main()
{
	char ch;
	int i;
	int op1,op2,res,d;
	printf("\nEnter the AE in postfix form (add '$'):");
	scanf("%s",post);
	i=0;
	while(post[i]!='$')
	{
		ch=post[i++];
		if(isdigit(ch))
		{
			d=ch-'0';
			push(d);
			display();
		}
		else
		{
			op2=pop();
			op1=pop();
		    switch(ch)
		    {
				case '+':
				res=op1+op2;
				break;
				
				case '-':
				res=op1-op2;
				break;
				
				case '*':
				res=op1*op2;
				break;
				
				case '/':
				res=op1/op2;
				break;
			}
			push(res);
		}
	}
	if(top==0)
	printf("Postfix expression result:%d",pop());
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",st[i]);
	}
	printf("\n");
}
void push(int n)
{
	if(top==max-1)
	printf("\t______Stack Overflow!______\n");
	else{
		top=top+1;
		st[top]=n;
		printf("Inserted____!");	
	}
	printf("\n");
}
int pop()
{
	if(top==-1)
	printf("\t_____Stack Empty_____\n");
	else{
		return st[top--];
	}
	
	
}
