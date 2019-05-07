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

void INS(int ind,int *r,int *data,int *lc,int *rc)
{
	if(*r==-1)
	{
		*r=ind;
		lc[ind]=-1;
		rc[ind]=-1;
	}
	else if(data[ind]>(data[*r]))
	{
		INS(ind,&rc[*r],data,lc,rc);
	}
	else
		INS(ind,&lc[*r],data,lc,rc);
}

void TRAVIN(int ind,int *data, int *lc, int *rc,int *stack,int *top)
{
	if(lc[ind]!=-1)
		TRAVIN(lc[ind],data,lc,rc,stack,top);
	PUSH(stack,top,data[ind]);
	if(rc[ind]!=-1)
		TRAVIN(rc[ind],data,lc,rc,stack,top);

}

void DSP(int *s,int t)
{
 int i;
 for(i=0;i<=t;i++)
 printf("%d ",s[i]);
}

int main()
{
	printf("Enter No. of Elements\n");
	int n,i,tem,ind=0;
	scanf("%d",&n);
	printf("Enter Elements\n");
	int data[n],lc[n],rc[n];
	int stack[n];
	int top=-1;
	for(i=0;i<n;i++)
	{
		data[i]=lc[i]=rc[i]=-1;
	}
	int root=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
		INS(i,&root,data,lc,rc);
	}
	printf("Sorted Elements :");
	TRAVIN(0,data,lc,rc,stack,&top);
	DSP(stack,top);
	printf("\n");
}