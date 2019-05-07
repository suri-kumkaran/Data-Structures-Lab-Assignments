#include <stdio.h>
#include <string.h>
int POP(int *s,int *t)
{
	int o=s[*t];
	(*t)--;
	return o;
}
void PUSH(int *s,int *t,int v)
{
	(*t)++;
	s[(*t)]=v;
}
int main()
{
	printf("Enter a POSTFIX Expression to Evaluate\n");
	char postfix[50];
	int stack[50],top=-1,v1,v2,res,i;
	scanf("%s",postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		if(isdigit(postfix[i]))
		{
			PUSH(stack,&top,postfix[i]-'0');
		}
		else
		{
			v1=POP(stack,&top);
			v2=POP(stack,&top);
			switch(postfix[i])
			{
				case '+':res=v2+v1;
					 break;
				case '-':res=v2-v1;
					 break;
				case '*':res=v2*v1;
					 break;
				case '/':res=v2/v1;
					 break;
			}
			PUSH(stack,&top,res);
		}
	}
	printf("Result is %d\n",stack[top]);
	return 0;


}
