/*suri_kumkaran*/
#include <stdio.h>

void swap(int *a, int *b)
{
	int tem=*a;
	*a=*b;
	*b=tem;
}


int fpivot(int *v,int s,int m,int e)
{
	if((v[s]>=v[m]&&v[s]<=v[e])||(v[s]<=v[m]&&v[s]>=v[e]))
		return s;
	else	if((v[m]>=v[s]&&v[m]<=v[e])||(v[m]<=v[s]&&v[m]>=v[e]))
		return m;
	else	if((v[e]>=v[m]&&v[e]<=v[s])||(v[e]<=v[m]&&v[e]>=v[s]))
		return e;

}
int part(int *v,int s,int e)
{
	int p=fpivot(v,s,(s+e)/2,e);
	swap(&v[s],&v[p]);
	p=v[s];
	int i=s+1;
	int j=s+1;
	for(;i<=e;i++)
	{
		if(v[i]<p)
		{
			swap(&v[i],&v[j]);
			j++;
		}
	}
	swap(&v[s],&v[j-1]);
	return j-1;
}

void qsort(int *v,int s,int e)
{
	if(e>s)
	{
		int p=part(v,s,e);
		qsort(v,s,p-1);
		qsort(v,p+1,e);
	}
}

void binary_search(int *v, int s, int e,int ele)
{
	if(s>e)
	{
		printf("%d is not present in Array\n",ele);
		return;
	}
	int m=(s+e)/2;
	if(v[m]==ele)
	{
		printf("%d is present at Index %d in sorted Array\n",ele,m);
	}
	else if(v[m]>ele)
	{
		binary_search(v,s,m-1,ele);
	}
	else
	{
		binary_search(v,m+1,e,ele);
	}
}

int main()
{

	int n,i,t;
	printf("Enter No. of Elements\n");
	scanf("%d",&n);
	int v[n];
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	qsort(v,0,n-1);
	printf("Enter Element to find in Sorted Array\n");
	int ele;
	scanf("%d",&ele);
	binary_search(v,0,n-1,ele);
}

