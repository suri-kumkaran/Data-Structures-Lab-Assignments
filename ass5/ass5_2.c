#include <stdio.h>
#include <string.h>
typedef struct str
{
	char c[10];
	int f;
	int s;
	struct str *add;
} node;

void INST(node **h,char *val)
{
//	printf("INST CALLED");
	if(*h==NULL)
	{
		*h=(node *)malloc(sizeof(node));
		strcpy(((*h)->c),val);
		(*h)->f=1;
		(*h)->s=strlen(val);
		(*h)->add=NULL;

	}
	else
	{
		int chch=1;
		node *current=*h;
		while(current->add!=NULL)
		{
			if(strcmp(current->c,val)==0)
			{
				chch=0;
				(current->f)++;
				break;
			}
			current=current->add;

		}
		if(chch)
		{
			if(strcmp(current->c,val)==0)
			{
				chch=0;
				(current->f)++;
			}
			else
			{
				current->add=(node *)malloc(sizeof(node));
				current=current->add;
				strcpy((current->c),val);
				current->f=1;
				current->s=strlen(val);
				current->add=NULL;
			}
		}
	}
}

void FIND(node **h, int n)
{
	if((*h)==NULL)
		return;
	if((*h)->s==n)
	{
		printf("%10s %10d\n",(*h)->c,(*h)->f);
	}
	FIND(&((*h)->add),n);
	return;
}

int main()
{
	node *h=NULL;
	char str[1000];
	char tem[100];
	int n,i,j;
	printf("Enter the TEXT\n");
	scanf("%[^\n]%*c",str);
	//printf("%d",strlen(str));
	for(i=0,j=0;i<strlen(str);i++)
	{
		//printf("%d",i);
		if(str[i]==' ')
		{
			tem[j]=0;
			INST(&h,tem);
			j=0;
		}
		else
		{
			tem[j]=str[i];
			j++;
		}
	}
	tem[j]=0;
	INST(&h,tem);
	printf("Enter the Specific length of words to display\n");
	scanf(" %d",&n);
	printf("       WORD      FREQUENCY\n");
	FIND(&h,n);
}