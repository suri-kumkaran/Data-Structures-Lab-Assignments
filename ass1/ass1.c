#include <stdio.h>

int main()
{
  int data[68][5]={0};
  int n,i,j,s,d,da;
while(1)
{
  printf("Enter 1 to insert sales figure\nEnter 2 to update sales figure\nEnter 3 to delete sales figure\nEnter 4 to display the data base\nEnter 5 to Close Programme\n");
  scanf("%d",&n);
  if(n==1||n==2)
  {
    if(n==1)
    printf("Enter STORE NO.(1-68), DEPARTMENT NO.(1-5) and DATA in Format \" STORE_NO. DEPARTMENT_NO. DATA \" to insert sales figure DATA\n");
    else
    printf("Enter STORE NO.(1-68), DEPARTMENT NO.(1-5) and DATA in Format \" STORE_NO. DEPARTMENT_NO. DATA \" to update sales figure DATA\n");
    scanf("%d %d %d",&s,&d,&da);
    data[s-1][d-1]=da;
  }
  else if(n==3)
  {
    printf("Enter STORE NO.(1-68) and DEPARTMENT NO.(1-5) in Format \" STORE_NO. DEPARTMENT_NO.\" to delete sales figure\n");
    scanf("%d %d",&s,&d);
    data[s-1][d-1]=0; 
  }
  else if(n==4)
  {
    printf("DEPARTMENTS ");
    for(i=0;i<5;i++)
    {
      printf("%10d ",i+1);
    }
    printf("\n");
    for(i=0;i<68;i++)
    {
      printf("  STORE %3d ",i+1);
      for(j=0;j<5;j++)
      {
        printf("%10d ",data[i][j]);
      }
      printf("\n");
    }
  }
  else if(n==5)
   return 0;
  else
  { 
    printf("Choose a valid operation");
  }
}
}
