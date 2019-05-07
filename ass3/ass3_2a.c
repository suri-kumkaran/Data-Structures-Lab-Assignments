#include <stdio.h>
#include <string.h>
char POP(char *s,int *t)
{
	char o=s[*t];
	(*t)--;
	return o;
}
void PUSH(char *s,int *t,char v)
{
	(*t)++;
	s[(*t)]=v;
}
int priority(char c)
{
	switch(c)
	{
		case '(':return 1;
		case '/':return 5;
		case '*':return 4;
		case '+':return 3;
		case '-':return 2;
	}
}
int main()
{
	char infix[50],postfix[50],stack[50];
	printf("Enter a INFIX expression to convert it into POSTFIX\n");
	scanf("%s",infix);
	int i,j=0,top=-1;
	for(i=0;infix[i]!=0;i++)
	{
		if(infix[i]>='0'&&infix[i]<='9')
		{
			postfix[j++]=infix[i];
		}
		else
		{
			switch(infix[i])
			{
				case'(':PUSH(stack,&top,infix[i]);
					break;
				case')':while(stack[top]!='(')
					{
						postfix[j++]=POP(stack,&top);
					}
					top--;
					break;
				default:while(priority(stack[top])>priority(infix[i])&&top>-1)
					{
						postfix[j++]=POP(stack,&top);
					}
					PUSH(stack,&top,infix[i]);
					break;

			}

		}
	}
	while(top!=-1)
	{
		postfix[j]=POP(stack,&top);
		j++;
	}
	postfix[j]=0;
	printf("POSTFIX : %s\n",postfix);

}
