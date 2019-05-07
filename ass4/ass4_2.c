#include <stdio.h>
int POP(int *s,int *t)
{
	(*t)--;
	return s[(*t)+1];
}

void PUSH(int *s,int *t,int v)
{
	(*t)++;
	s[*t]=v;
}
void DSP(int *s,int t)
{
	int i;
	for(i=0;i<=t;i++)
	printf("%d ",s[i]);
	printf("\n");
}

int main()
{
	int n,c,v,qtop=-1,stop=-1;
	printf("Enter the Size of Queue : ");
	scanf("%d",&n);
	int q[n],s[n];
	c=-1;
	while(c!=4)
	{
 		printf("Enter 1 to INSERT in Queue\nEnter 2 to DELETE from Queue\nEnter 3 to DISPLAY the Queue\nEnter 4 to EXIT\n");
 		scanf("%d",&c);
 		switch(c)
 		{
  			case 1:if(qtop==n-1)
        	printf("ERROR...!!\nQueue is FULL\n");
         	else
          	{
           	printf("Enter Element: ");
           	scanf("%d",&v);
           	PUSH(q,&qtop,v);
          	}
         	break;
  			case 2:if(qtop==-1)
          	printf("ERROR...!!\nQueue is EMPTY\n");
         	else
         	{
         	while(qtop>0)
         	{
         	PUSH(s,&stop,POP(q,&qtop));
         	}
          	printf("Deleted Element is %d\n",POP(q,&qtop));
          	while(stop!=-1)
          	{
          	PUSH(q,&qtop,POP(s,&stop));
          	}
          	} 
           	break;
         	case 3:printf("Queue : ");
         	DSP(q,qtop);
         	break;
  			case 4:return 0;
  			default : printf("Choose a Valid Option\n");   
 		}
	}
	return 0;
}

