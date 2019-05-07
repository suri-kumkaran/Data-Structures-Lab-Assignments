#include <stdio.h>
int POP(int *s,int *t)
{
 (*t)--;
 return s[(*t)+1];
}

void PUSH(int *s,int *t,int v)
{
 (*t)++;
 s[*t]=v;
}
void DSP(int *s,int t)
{
 int i;
 for(i=0;i<=t;i++)
 printf("%d ",s[i]);
 printf("\n");
}

void duplicateStack(int size,int *s,int *top,int *sn,int *topn)
{
 int i,tt,j,flag=1,opt=-1,dt=-1,tst=-1;
 int ts[size],op[size],d[size];
 for(i=*top;i>=0;i--)
 {
   flag=1;
   tt=POP(s,top);
   for(j=0;j<i;j++)
    {
     if(s[j]==tt)
     flag=0;
    }
   if(flag)
   {
    PUSH(ts,&tst,tt);
    PUSH(op,&opt,1);
   }
   else
   {
    PUSH(d,&dt,tt);
    PUSH(op,&opt,0);
   }
 }
 // Genaration of OLD stack from new
 for(i=opt;i>=0;i--)
 {
  flag=POP(op,&opt);
  if(flag)
   {
    tt=POP(ts,&tst);
    PUSH(sn,topn,tt);
   }
  else
   {
    tt=POP(d,&dt);  
   }
   PUSH(s,top,tt);
 }
}

int main()
{
 int n,c,v,top=-1;
 printf("Enter the Size of Stack : ");
 scanf("%d",&n);
 int stack[n];
 int nstack[n];
 int ntop=-1;
c=-1;
while(c!=4)
{
 printf("Enter 1 to PUSH in Stack\nEnter 2 to POP from Stack\nEnter 3 to Copy the Stack\nEnter 4 to EXIT\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:if(top==n-1)
          printf("ERROR...!!\nStack is FULL\n");
         else
          {
           printf("Enter Element: ");
           scanf("%d",&v);
           PUSH(stack,&top,v);
          }
         break;
  case 2:if(top==-1)
          printf("ERROR...!!\nStack is EMPTY\n");
         else
          printf("Poped Element is %d\n",POP(stack,&top));
         break;
  case 3:printf("Your Stack has been copied\n");
         duplicateStack(n,stack,&top,nstack,&ntop);
         c=-1;
         goto oo;
         break;  
  case 4:return 0;
  default : printf("Choose a Valid Option\n");   
 }
}
oo:
while(c!=3)
{
 printf("Enter 1 to Display OLD stack\nEnter 2 to Display NEW stack\nEnter 3 to EXIT\n");
 scanf("%d",&c);
 switch(c)
 {
   case 1: printf("OLD STACK : ");
           DSP(stack,top);
           break;
   case 2: printf("NEW STACK : ");
           DSP(nstack,ntop);
           break;
   case 3: return 0;
           break;
   default:printf("Choose a Valid Option\n");
 }
}
return 0;
}
