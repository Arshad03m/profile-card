#include<stdio.h>
#include<stdlib.h>
#define max 3
int st[max],top=-1;
void display();
int pop();
void push(int);
int main()
{
	int n,ch;
	while(1)
	{
		printf("*********Stack Operations**********");
		printf("1-push,2-pop,3-display,4-exit\n");
		printf("Enter your choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the element to be inserted:");
			scanf("%d",&n);
			push(n);
			break;
			
			case 2:
			printf("Popped element:%d",pop());
			printf("\n");
			break;
			
			case 3:
			display();
			break;
			
			case 4:
			exit(0);
		}
	}
	return 0;
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
	printf("\t_____Stack Overflow!_____\n");
	else{
		return st[top--];
	}
	
	
}
