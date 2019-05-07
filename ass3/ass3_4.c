#include <stdio.h>

void DPL(int *s,int t)
{
	int i;
	for(i=0;i<=t;i++)
		printf("%d ",s[i]);
	printf("\n");
}

int POP(int *s,int *t)
{
	(*t)--;
	return s[(*t)+1];
}

void PUSH(int *s,int *t, int v)
{
	(*t)++;
	s[(*t)]=v;
}

void TRANS(int*ts,int *tst,int *auxs,int *auxst,int ele)
{
	int count=0;
	while((*tst)>-1&&ts[*tst]>ele)
	{
		count++;
		PUSH(auxs,auxst,POP(ts,tst));
	}
	PUSH(ts,tst,ele);
	while(count)
	{
		PUSH(ts,tst,POP(auxs,auxst));
		count--;
	}
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
    int s1[n1+n2+n3];
    int t1=-1;
    int s2[n1+n2+n3];
    int t2=-1;
    int s3[n1+n2+n3];
    int t3=-1;
	while(c!=7)
	{
		printf("OPTIONS:\nEnter 1 to PUSH element in STACK 1\nEnter 2 to POP element from STACK 1\n");
				printf("Enter 3 to PUSH element in STACK 2\nEnter 4 to POP element from STACK 2\n");
	printf("Enter 5 to PUSH element in STACK 3\nEnter 6 to POP element from STACK 3\nEnter 7 to MERGE STACKS and Display Resultant Stack\n");
	scanf("%d",&c);
		switch(c)
		{
			case 1:if(t1==n1-1)
				       printf("STACK 1 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s1,&t1,v);
			       }
			       break;
			case 2:if(t1==-1)
				       printf("STACK 1 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s1,&t1);
				       printf("Poped Element from STACK 1 is %d\n",o);
			       }
			       break;
			case 3:if(t2==n2-1)
				       printf("STACK 2 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s2,&t2,v);
			       }
			       break;
			case 4:if(t2==-1)
				       printf("STACK 2 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s2,&t2);
				       printf("Poped Element from STACK 2 is %d\n",o);
			       }
			       break;
	                case 5:if(t3==n3-1)
				       printf("STACK 3 is Full,Choose other options\n");
			       else
			       {
				       printf("Enter Element\n");
				       scanf("%d",&v);
				       PUSH(s3,&t3,v);
			       }
			       break;
			case 6:if(t3==-1)
				       printf("STACK 3 is Empty,Choose other options\n");
			       else
			       {
				       o=POP(s3,&t3);
				       printf("Poped Element from STACK 3 is %d\n",o);
			       }
			       break;
			case 7:break;
			default:printf("Choose a valid Option\n");
		}
	}

	while(t1>-1)
	{
		if(t1&1)
			PUSH(s2,&t2,POP(s1,&t1));
		else
			PUSH(s3,&t3,POP(s1,&t1));
	}
	while(t2>-1&&t3>-1)
	{
		if(s2[t2]<s3[t3])
		{
			TRANS(s1,&t1,s3,&t3,POP(s2,&t2));
		}
		else
		{
			TRANS(s1,&t1,s2,&t2,POP(s3,&t3));
		}
		printf("Stack 1: ");
		DPL(s1,t1);
		printf("Stack 2: ");
		DPL(s2,t2);
		printf("Stack 3: ");
		DPL(s3,t3);
	}
	while(t2>-1)
	{
		TRANS(s1,&t1,s3,&t3,POP(s2,&t2));
	}
	while(t3>-1)
	{
		TRANS(s1,&t1,s2,&t2,POP(s3,&t3));
	}
	printf("Merged and Sorted Stack : ");
	DPL(s1,t1);

			       
	return 0;
}