#include<stdio.h>
typedef struct priority{
	int data,priority;
} E;
void INS(E *q,int *e,E v,int s,int c)
{
	*e=((*e)+1)%s;
	q[*e].data=v.data;
	q[*e].priority=v.priority;
	int en=*e;
	if(c>1)
	{
		while(c>1&&q[en].priority>q[(en+s-1)%s].priority)
		{
			 q[(en+s-1)%s].data=q[(en+s-1)%s].data+q[en].data;
			 q[en].data=q[(en+s-1)%s].data-q[en].data;
			 q[(en+s-1)%s].data=q[(en+s-1)%s].data-q[en].data;
			 q[(en+s-1)%s].priority=q[(en+s-1)%s].priority+q[en].priority;
			 q[en].priority=q[(en+s-1)%s].priority-q[en].priority;
			 q[(en+s-1)%s].priority=q[(en+s-1)%s].priority-q[en].priority;
			 c--;
			 en=(en-1)%s;
		}
	}
}

E DLT(E *q,int *st,int s)
{
	E v;
	v.data=q[*st].data;
	v.priority=q[*st].priority;
	*st=((*st)+1)%s;
	return v;
}

void DSP(E *q,int st,int c,int s)
{
	while(c--)
	{
		printf("%d ",q[st].data);
		st=(st+1)%s;
	}
	printf("\n");
}

int main()
{
	int n,c,top=-1,count=0,start=0;
	printf("Enter the Size of Circular Queue : ");
	scanf("%d",&n);
	E q[n],v;
	c=-1;
	while(c!=4)
	{
 		printf("Enter 1 to INSERT in Queue\nEnter 2 to DELETE from Queue\nEnter 3 to DISPLAY the Queue\nEnter 4 to EXIT\n");
 		scanf("%d",&c);
 		switch(c)
 		{
  			case 1:if(count==n)
        	printf("ERROR...!!\nQueue is FULL\n");
         	else
          	{
           	printf("Enter Element: ");
           	scanf("%d",&v.data);
           	printf("Enter Priority: ");
           	scanf("%d",&v.priority);
           	count++;
           	INS(q,&top,v,n,count);
          	}
         	break;
  			case 2:if(count==0)
          	printf("ERROR...!!\nQueue is EMPTY\n");
         	else
         	{
         	count--;
          	printf("Deleted Element is %d\n",DLT(q,&start,n).data);
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
