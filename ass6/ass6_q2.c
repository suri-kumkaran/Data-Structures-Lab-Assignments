#include <stdio.h>
struct tree
{
	int key1,key2;
	struct tree *c1,*c2,*c3;
	int count;

};
typedef struct tree TST;

void INS(TST **r,int val)
{
	if(*r==NULL)
	{
		*r=(TST *)malloc(sizeof(TST));
		(*r)->key1=val;
		(*r)->count=1;
		(*r)->c1=(*r)->c2=(*r)->c3=NULL;
	}
	else if((*r)->count<2)
	{
		if(val<(*r)->key1)
		{
			(*r)->key2=(*r)->key1;
			(*r)->key1=val;
		}
		else
		{
			(*r)->key2=val;
		}
		(*r)->count++;
	}
	else
	{
		if(val<(*r)->key1)
			INS(&((*r)->c1),val);
		else if(val>(*r)->key2)
			INS(&((*r)->c3),val);
		else
			INS(&((*r)->c2),val);
	}
}

void TRAVIN(TST *r)
{
	if(r->c1!=NULL)
		TRAVIN(r->c1);
	printf("%d ",r->key1);
	if(r->c2!=NULL)
		TRAVIN(r->c2);
	if(r->count==2)
		printf("%d ",r->key2);
	if(r->c3!=NULL)
		TRAVIN(r->c3);

}


int main()
{
	TST *root=NULL;
	printf("Enter No. of Elements\n");
	int n,i,tem;
	scanf("%d",&n);
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&tem);
		INS(&root,tem);
	}
	printf("Sorted Elements using Ternary Search Tree with two KEY values :\n");
	TRAVIN(root);
	printf("\n");
}