#include <stdio.h>
void swap(int*a ,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
int main()
{
 int n,i;
 printf("Enter Size of Array\n");
 scanf("%d",&n);
 int arr[n];
 printf("Enter Elements of array\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 for(i=0;i<n/2;i++)
 {
  swap(&arr[i],&arr[n-1-i]);
 }
 for(i=0;i<n;i++)
 {
  printf("%d ",arr[i]);
 }
 printf("\n");
}
