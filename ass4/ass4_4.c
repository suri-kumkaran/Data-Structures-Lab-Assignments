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

int main()
{
	int n,i,tem;
	printf("Enter Size of Queue\n");
	scanf("%d",&n);
	int q[n],qs=0,qt=-1;
	int p[n],ps=0,pt=-1;
	int s[n],st=-1;
	printf("Enter Permutation\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&tem);
			INS(q,&qt,tem,n);
		}
	printf("Now Enter Queue P\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&tem);
			INS(p,&pt,tem,n);
		}
	while(ps<n-1)
	{
		if(q[qs]==p[ps])
		{
			DLT(q,&qs,n);
			DLT(p,&ps,n);
		}
		else if(st>-1)
		{
			if(s[st]==q[qs])
			{
				DLT(q,&qs,n);
				POP(s,&st);
			}
			else
			{
				PUSH(s,&st,DLT(p,&pt,n));
			}

		}
		else
		{
			PUSH(s,&st,DLT(p,&pt,n));
		}
	}
	if(st!=-1)
	{
		printf("Yes This Permutation is Possible\n");
	}
	else
		printf("No This Permutation is not Possible\n");
	return 0;
}