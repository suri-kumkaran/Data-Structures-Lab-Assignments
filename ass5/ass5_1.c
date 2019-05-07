#include <stdio.h>

typedef struct spmat{
	int r;
	int c;
	int v;
	struct spmat *add;
} node;

void INST(node **h,node val)
{
	if(*h==NULL)
	{
		*h=(node *)malloc(sizeof(node));
		(*h)->r=val.r;
		(*h)->c=val.c;
		(*h)->v=val.v;
		(*h)->add=NULL;

	}
	else
	{
		node *current=*h;
		while(current->add!=NULL)
		{
			current=current->add;
		}
		current->add=(node *)malloc(sizeof(node));
		current=current->add;
		current->r=val.r;
		current->c=val.c;
		current->v=val.v;
		current->add=NULL;
	}
}

void TRAV(node *h)
{
	if(h==NULL)
		return;
	else
	{
		printf("%3d %6d %5d\n",h->r,h->c,h->v);
		TRAV(h->add);
	}
}

int main()
{
	int n,m,tem,i,j;
	node *h1=NULL;
	node *h2=NULL;
	node *h3=NULL;
	node tt,t1,t2;
	printf("Enter No. of Rows\n");
	scanf("%d",&n);
	printf("Enter No. of Column\n");
	scanf("%d",&m);
	printf("Enetr Matrix 1\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&tem);
			if(tem!=0)
			{
				tt.r=i;
				tt.c=j;
				tt.v=tem;
				INST(&h1,tt);
			}
		//	scanf("\n");
		}
	}
	printf("Enetr Matrix 2\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&tem);
			if(tem!=0)
			{
				tt.r=i;
				tt.c=j;
				tt.v=tem;
				INST(&h2,tt);
			}
		//	scanf("\n");
		}
	}

	node *c1=h1;
	node *c2=h2;
	while(c1!=NULL||c2!=NULL)
	{
		if(c1!=NULL&&c2!=NULL)
		{
			t1=*c1;
			t2=*c2;
			if(t1.r<t2.r)
			{
				INST(&h3,t1);
				c1=c1->add;
			}
			else if(t2.r<t1.r)
			{
				INST(&h3,t2);
				c2=c2->add;
			}
			else
			{
				if(t1.c<t2.c)
				{
					INST(&h3,t1);
					c1=c1->add;
				}
				else if(t2.c<t1.c)
				{
					INST(&h3,t2);
					c2=c2->add;
				}
				else
				{
					tt.r=t1.r;
					tt.c=t1.c;
					tt.v=t1.v+t2.v;
					INST(&h3,tt);
					c1=c1->add;
					c2=c2->add;
				}
			}
		}
		else if(c1!=NULL)
		{
			t1=*c1;
			INST(&h3,t1);
			c1=c1->add;
		}
		else if(c2!=NULL)
		{
			t2=*c2;
			INST(&h3,t2);
			c2=c2->add;
		}

	}
	printf("Sum of 2 Sparse Matrix :\n");
	printf("Row Column Value\n");
	TRAV(h3);



	return 0;

}