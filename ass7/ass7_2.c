#include <stdio.h>
#include <string.h> 

void swap(int *a, int *b)
{
	int tem=*a;
	*a=*b;
	*b=tem;
}

void merge(int *arr,int s, int m, int e)
{
	int s1=m-s+1;
	int s2= e-m;
	int left[s1];
	int right[s2];
	int i,j;
	j=0;
	for(i=s;i<=m;i++)
	{
		left[j]=arr[i];
		j++;
	}
	j=0;
	for(i=m+1;i<=e;i++)
	{
		right[j]=arr[i];
		j++;
	}
	int k=s;
	for(i=0,j=0;i<s1&&j<s2;k++)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
	}
	while(i<s1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<s2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void merge_sort(int *arr,int s,int e)
{
	if(s<e)
	{
		int m=(s+e)/2;
		merge_sort(arr,s,m);
		merge_sort(arr,m+1,e);
		merge(arr,s,m,e);
	}
}

int main(int argc,char* argv[])
{
	int i;
	int arr[argc-1];
	for(i=0;i<argc-1;i++)
	{
		arr[i]=atoi(argv[i+1]);
	}
	merge_sort(arr,0,argc-2);
	printf("Sorted Array using Merge Sort : ");
	for(i=0;i<argc-1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;


}