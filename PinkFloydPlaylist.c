/*Pink is sad because of some reasons, he wants to cheer up by listening to some songs from his favourite band, Pink Floyd.
There are N records and Pink will be happy if he listens to them in the ascending order, i.e, first the song No. 1, then No.2 and so on(He has to listen to all the N songs to become Happy).
Pink is delivered his records in some given order, he can either add the record to the Playlist in the delivered order or put some on an another table. After being put on the table only the topmost record can be added to the playlist at any time.
Print whether Pink will be sad or happy after the delivery of the records.
INPUT
N - Number of records followed  by
N numbers- order of records
OUTPUT
Print "Happy" if the playlist has songs from 1 to N in order else "Sad".
Sample Input
5
1 2 4 3 5
Explanation
1 2 4 3 5
1 is passed to the playlist
stack -> empty
2 is passed to the playlist
stack -> empty
4 is passed to the stack
stack -> {4}
3 is passed to the playlist
stack -> {4}
now 4 is passed from the stack
stack -> empty
now 5 is passed to the playlist
The passed becomes 1 2 3 4 5 and hence pink is happy*/
/*Sample Input
5
1 2 4 3 5
happy*/

#include <stdio.h>

	int num,a[10]={0},pl[10],stack[10],i,top=-1,j=0,k=0;
void push(int num)
{
  stack[++top]=num;
}
int pop()
{
    if(top<0)
    {
        return -1;
    }
    else
    {
     return stack[top--];   
    }
}
int peek()
{
    if(top>=0)
    {
     return stack[top];   
    }
    else
      return 0;
}
int PlaylistCheck(int n)
{

for(i=0,j=0;j<n;i++)
 {
    
     if((peek()==0&&peek()<a[i])&&a[i]>a[i+1])
     {
         push(a[i]);
     }
     else if(peek()>a[i]&&a[i]<a[i+1])
     {
         pl[j++]=a[i];
     }
     else if(peek()>a[i]&&a[i]>a[i+1])
     {
         push(a[i]);
     }
     else if((peek()!=0&&peek()<a[i]))
     {
         if(a[i]<a[i+1])
         {
         pl[j++]=pop();    
         }
         if(i==n-1)
         {
             while(top!=-1)
             {
                 pl[j++]=pop();
             }
         }
     }
     else if(a[i]<a[i+1])
     {
     pl[j++]=a[i];
     }
     if(top==n-1)
     {
         while(top!=-1)
         {
             pl[j++]=pop();
         }
     }
      if(j==n-1||i==n-1)
         {
             pl[j++]=a[i];
         }
 }
 while(top!=-1)
{
    pl[j++]=pop();
}
 int c=1;
 //Check For Happy Or Sad
 for(i=0;i<n;i++)
 {
     if(pl[i]<pl[i+1])
     {
         c++;
     }
 }
 
 return c;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
 c=PlaylistCheck(n);
 if(c==5)
 {
    printf("happy"); 
 }
 else
 {
     printf("Sad");
 }   
}

