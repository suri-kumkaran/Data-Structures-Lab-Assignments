#include <stdio.h>
int main()
{
  int n,i,lr,sm;
  printf("Enter No. of Elements in Array\n");
  scanf("%d",&n);
  int arr[n];
  printf("Enter Elements of Array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
    if(i==0)
    {
      lr=arr[i];
      sm=arr[i];
    }
    else
    { 
       if(lr<arr[i])
         lr=arr[i];
       if(sm>arr[i])
         sm=arr[i];
    }
  }
  printf("Smallest element in Array is %d and Largest element in Array is %d\n",sm,lr);
}
