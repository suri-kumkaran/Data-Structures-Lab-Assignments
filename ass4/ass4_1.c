#include <stdio.h>

void INS(int *q,int *e,int v,int s)
{
	*e=((*e)+1)%s;
	q[*e]=v;
}

int DLT(int *q,int *st,int s)
{
	int v;
	v=q[*st];
	*st=((*st)+1)%s;
	return v;
}
void ROTATE(int *st,int *e,int s)
{
  *st=((*st)+1)%s;
  *e=((*e)+1)%s;
}
void DSP(int *q,int st,int c,int s)
{
	while(c--)
	{
		printf("%d ",q[st]);
		st=(st+1)%s;
	}
	printf("\n");
}

int main()
{
	int n,c,v,top=-1,count=0,start=0;
	printf("Enter the Size of Circular Queue : ");
	scanf("%d",&n);
	int q[n];
	c=-1;
	while(c!=4)
	{
 		printf("Enter 1 to INSERT in Queue\nEnter 2 to DELETE from Queue\nEnter 3 to DISPLAY the Queue\nEnter 4 to EXIT\n");
 		scanf("%d",&c);
 		switch(c)
 		{
  			case 1:if(count==n)
        {	printf("ERROR...!!\nQueue is FULL\n");
          printf("Enter 1 to Rotate else 2 to continue\n");
          scanf("%d",&c);
          if(c==1)
          {
            ROTATE(&start,&top,n);
            printf("Queue is Rotated\n");
          }
        }
         	else
          	{
           	printf("Enter Element: ");
           	scanf("%d",&v);
           	INS(q,&top,v,n);
           	count++;
          	}
         	break;
  			case 2:if(count==0)
          	printf("ERROR...!!\nQueue is EMPTY\n");
         	else
         	{
          	printf("Deleted Element is %d\n",DLT(q,&start,n));
          	count--;
          	} 
           	break;
         	case 3:printf("Queue : \n");
         	DSP(q,start,count,n);
         	break;
  			case 4:return 0;
  			default : printf("Choose a Valid Option\n");   
 		}
	}
	return 0;
}
