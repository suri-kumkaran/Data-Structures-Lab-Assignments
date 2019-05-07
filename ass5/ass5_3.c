#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char emp;
	int priority;
	int time;
	int start;
	int end;
	struct Node *next;
}node;

void insert(node **root, node el);
void display(node *root);
void roundrobin(node *root, char ch);

int ctr;

int main()
{
	int n;
	printf("Enter the number of employees\n");
	scanf("%d", &n);
	node *root = NULL;
//	node *formal = NULL;	

	int i = 0;
	printf("Enter the data\n");
	
	for(i = 0; i<n; i++)
	{
		node el;
		el.emp = 'A'+i;
		printf("Employee %c \n", i+'A');
		el.start = el.end = -1;
		scanf("%d %d", &(el.priority), &(el.time));
		insert(&root, el);
	}
	
	printf("Enter the employee from which to start work\n");
	char ch;
	scanf(" %c", &ch);
//	printf("%c", ch);
	roundrobin(root, ch);
//	printf("The details of starting time and ending times are as follows\n");
	display(root);
	return 0;
}

void roundrobin(node *root, char ch)
{
	int t = 0;
	node *cur = root;
	node *prev = root;
	while(cur->emp != ch)
	{
		prev = cur;
		cur = cur->next;
	}

	printf("%c %d %d\n", ch, 0, 2);

	cur->start = 0;
	t+=2;
	cur->end = t;
	cur->time -= 2;

//	cur = cur->next;
	if(cur->time <= 0)
	{
		//You got an IPhone
		prev->next = cur->next;
		node *mem = cur;
		free(mem);
		ctr--;
		cur = prev->next;
	}
//	printf("%u \n", cur);
//	printf("%u \n", cur->next);

	while(ctr > 0)
	{
		prev = cur;	
	//	printf("Next Emp is %c", cur->next->emp);

		cur = cur->next;
		if(cur->start == -1)
		{
			cur->start = t;
			cur->end = t;
		}
		if(cur->time > 2)
		{
			cur->time -= 2;
			t += 2;
			cur->end = t;
			printf("%c %d %d\n", cur->emp, t-2, t);
		}
		else
		{
			if(cur->time > 0)
			{
				printf("%c %d %d \n", cur->emp, t, t+cur->time);
				t+= cur->time;
				cur->end = t;
			}
			prev->next = cur->next;
			node *mem = cur;
			free(mem);
			cur = prev->next;
			ctr--;
		}
	}	
}

void insert(node **root, node el)
{
	node *val = (node *)malloc(sizeof(node));
	val->emp = el.emp;
	val->priority = el.priority;
	val->time = el.time;
	val->start = el.start;
	val->end = el.end;
	val->next = *root;
	
	ctr++;
	
	if(*root == NULL)
	{
		*root = val;
		val->next = *root;
		return;
	}
	if(ctr == 2)
	{
		(*root)->next = val;
		val->next = *root;
		return ;
	}
	if(el.priority <= (*root)->priority)
	{
		val->next = *root;
		*root = val;
		node *cur = val;
		int num = ctr;
		while(num > 1)
		{
			cur = cur->next;
			num--;
		}
		cur->next = *root;
	}
	//case single node
	//case two nodes
	//case last node
	
	node *cur = *root;
	node *prev = *root;
	int count = ctr-1;
	while(count > 0 && (cur->priority <= el.priority))
	{
		prev = cur;
		cur = cur->next;
		count--;
	}
	
	prev->next = val;
	prev = prev->next;
	prev->next = cur;
}

void display(node *root)
{
	int num = ctr;
	node *cur = root;
	while(cur != NULL && ctr>0)
	{
		printf("%c %d %d %d\n", cur->emp, cur->start, cur->end, cur->time);
		cur = cur->next;
		ctr--;
	}
}
