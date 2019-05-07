#include <stdio.h>

void swap(int *a, int *b)
{
	int tem=*a;
	*a=*b;
	*b=tem;
}

int LCI(int ind)
{
	return (2*ind)+1;
}

int RCI(int ind)
{
	return (2*ind)+2;
}

int PI(int ind)
{
	return (ind-1)/2;
}

void INS(int ind,int *heap)
{
	while(ind!=0&&heap[ind]>heap[PI(ind)])
	{
		swap(&heap[ind], &heap[PI(ind)]);
		ind=PI(ind);
	}
}

void MAXI(int i,int *heap, int n)
{
	int largest=i;
	int l=LCI(i);
	int r=RCI(i);
	if (l < n && heap[l] > heap[largest]) 
        largest = l; 
    if (r < n && heap[r] > heap[largest]) 
        largest = r; 
	if (largest != i) 
    { 
        swap(&heap[i], &heap[largest]); 
        MAXI(largest, heap, n); 
    } 
}

void HSORT(int *heap, int n)
{
	MAXI(0,heap,n);
	int i;
	for(i=n-1;i>0;i--)
	{
		swap(&heap[0],&heap[i]);
		MAXI(0,heap,i);
	}
}

int main()
{
	printf("Enter No. of Elements\n");
	int n,i;
	scanf("%d",&n);
	printf("Enter Elements\n");
	int heap[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&heap[i]);
		INS(i,heap);
	}
	HSORT(heap,n);
	printf("Sorted Elements :");
	for(i=0;i<n;i++)
		printf("%d ",heap[i]);
	printf("\n");
}