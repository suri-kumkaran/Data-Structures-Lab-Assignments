#include <stdio.h>
#include <string.h>
struct tree
{
	char data[10];
	int freq;
	struct tree *lc,*rc;
};
typedef struct tree BST;

void INS(BST **r,char * c)
{
	if(*r==NULL)
	{
		*r=(BST *)malloc(sizeof(BST));
		(*r)->lc=(*r)->rc=NULL;
		strcpy((*r)->data,c);
		(*r)->freq=1;
		return;
	}
	else if(strcmp(c,(*r)->data)>0)
		INS(&((*r)->rc),c);
	else if(strcmp(c,(*r)->data)<0)
		INS(&((*r)->lc),c);
	else ((*r)->freq)++;
}

void TRAVIN(BST *r)
{
	if(r->lc!=NULL)
		TRAVIN(r->lc);
	int i;
	for(i=0;i<r->freq;i++)
		printf("%s ",r->data);
	if(r->rc!=NULL)
		TRAVIN(r->rc);
}


int main()
{
	BST *root=NULL;
	printf("Enter No. of Words\n");
	int n,i;
	char tem[10];
	scanf("%d",&n);
	printf("Enter Words\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",tem);
		INS(&root,tem);
	}
	printf("Sorted Set of Words : ");
	TRAVIN(root);
	printf("\n");
}
