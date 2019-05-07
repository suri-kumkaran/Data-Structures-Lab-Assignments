#include <stdio.h>
#include <string.h>

int mpow(int a,int b)
{
 int res=1,i;
 for(i=0;i<b;i++)
 {
  res*=a;
 }
 return res;
 
}


int btd(char*a)
{
 int l=strlen(a),i;
 int res=0;
 for(i=0;i<l;i++)
 { 
   res+=((a[i]-'0')*mpow(2,l-1-i));
 } 
 return res;
}


void dtb(int a)
{
  int k,i; 
  printf("Binary: ");
  for(i=9;i>=0;i--)
  {
   k=a>>i;
   if(k&1)
   printf("1");
   else
   printf("0");
  }
  printf("\n");
 
}

int main()
{
 int n,res;
 while(n!=3)
{
 printf("Enter 1 to Convert Binary to Decimal and Enter 2 to Convert Decimal to Binary and 3 to Exit\n");
 scanf("%d",&n);
 char a[10];
 switch(n)
 {
  case 1: printf("Enter a maximum of 10 bit Binary No.\n");
          scanf("%s",a);
          res=btd(a);
          printf("Decimal: %d\n",res);
          break;
  case 2:
         printf("Enter a Decimal No. equivalent to maximum of 10 bit Binary\n");
         scanf("%d",&res);
         dtb(res);
         break;
 case 3: return 0;
 default:printf("Choose From Given Options\n");
 }
}
 return 0;
}
