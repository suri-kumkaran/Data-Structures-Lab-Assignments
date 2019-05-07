#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *arr[5] = {NULL};

void insert(int el);
void print();

int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int el;
	printf("Input the elements\n");
	int i = 0;
	for(i = 0; i<n; i++)
	{
		scanf("%d", &el);
		insert(el);
	}

	printf("Printing the hash table\n");

	print();
	return 0;
}

void insert(int el)
{
	int hash = el%5;
	if(arr[hash] == NULL)
	{
		arr[hash] = (node *)malloc(sizeof(node));
		arr[hash] -> data = el;
		arr[hash] ->next = NULL;
		return;
	}
	node *cur = arr[hash];
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next =  (node *)malloc(sizeof(node));
	cur = cur->next;
	cur->data = el;
	cur->next = NULL;
}

void print()
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d -> ",i);
		node *cur = arr[i];
		while(cur!=NULL)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
}