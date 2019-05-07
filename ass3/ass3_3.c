#include <stdio.h>
#include <string.h>
void DPL(int *s,int st,int en)
{
	int i;
	for(i=st;i<=en;i++)
		printf("%d ",s[i]);
	printf("\n");
}
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
	int n1,n2,n3,c=1,v,o;
	printf("Enter Size of STACK 1\n");
	scanf("%d",&n1);
	printf("Enter Size of STACK 2\n");
	scanf("%d",&n2);
	printf("Enter Size of STACK 3\n");
	scanf("%d",&n3);
        int s[n1+n2+n3];
	int l1=n1-1,l2=l1+n2,l3=l2+n3;
	int t1=-1,t2=l1,t3=l2;
	while(c!=10)
	{
		printf("OPTIONS:\nEnter 1 to PUSH element in STACK 1\nEnter 2 to POP element from STACK 1\n");
				printf("Enter 3 to PUSH element in STACK 2\nEnter 4 to POP element from STACK 2\n");
	printf("Enter 5 to PUSH element in STACK 3\nEnter 6 to POP element from STACK 3\nEnter 7 to DISPLAY STACK 1\nEnter 8 to DISPLAY STACK 2\nEnter 9 to DISPLAY STACK 3\nEnter 10 to EXIT\n");
	scanf("%d",&c);
		switch(c)
		{
			case 1:if(t1==l1)
				       printf("STACK 1 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s,&t1,v);
			       }
			       break;
			case 2:if(t1==-1)
				       printf("STACK 1 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s,&t1);
				       printf("Poped Element from STACK 1 is %d\n",o);
			       }
			       break;
			case 3:if(t2==l2)
				       printf("STACK 2 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s,&t2,v);
			       }
			       break;
			case 4:if(t2==l1)
				       printf("STACK 2 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s,&t2);
				       printf("Poped Element from STACK 2 is %d\n",o);
			       }
			       break;
	                case 5:if(t3==l3)
				       printf("STACK 3 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s,&t3,v);
			       }
			       break;
			case 6:if(t3==l2)
				       printf("STACK 3 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s,&t3);
				       printf("Poped Element from STACK 3 is %d\n",o);
			       }
			       break;
			case 7:printf("STACK 1 : ");
			       DPL(s,0,t1);
			       break;
			case 8:printf("STACK 2 : ");
			       DPL(s,l1+1,t2);
			       break;
			case 9:printf("STACK 3 : ");
			       DPL(s,l2+1,t3);
			       break;
			case 10:break;
			default:printf("Choose a valid Option\n");
		}
	}


			       
	return 0;
}


