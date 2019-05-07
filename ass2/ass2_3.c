#include <stdio.h>
int main()
{
 printf("Enter Length of String\n");
 int n,i;
 scanf("%d",&n);
 char a[n];
 scanf("%s",a);
 for(i=0;i<n/2;i++)
 {
  if(*(a+i)!=*(a+n-1-i))
  { 
    printf("This String is not Palindromic\n");
    return 0;
  }
 }
  printf("This String is Palindromic\n");
  return 0;
}
