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
	printf("Enter a PREFIX Expression to Evaluate\n");
	char prefix[50];
	int stack[50],top=-1,v1,v2,res,i;
	scanf("%s",prefix);
	for(i=strlen(prefix)-1;i>=0;i--)
	{
		if(isdigit(prefix[i]))
		{
			PUSH(stack,&top,prefix[i]-'0');
		}
		else
		{
			v1=POP(stack,&top);
			v2=POP(stack,&top);
			switch(prefix[i])
			{
				case '+':res=v1+v2;
					 break;
				case '-':res=v1-v2;
					 break;
				case '*':res=v1*v2;
					 break;
				case '/':res=v1/v2;
					 break;
			}
			PUSH(stack,&top,res);
		}
	}
	printf("Result is %d\n",stack[top]);
	return 0;


}
