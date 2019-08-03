/*Write a C program to merge two arrays. (Use dynamic array and functions )

case=1
Sample input:
Enter array1 & array2 sizes:4 3
Enter elements:5 2 7 1
Enter elements:6 3 9

Sample output:
Elements:1	2	3	5	6	7	9
*/	

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int* create(int);
void sort(int*,int);
void display(int*,int);
int* merge(int*,int*,int*,int,int);

void main()
{
    int *a,n1,n2,*b,*c;
    printf("Enter Size Of Two Arrays:");
    scanf("%d",&n1);
    scanf("%d",&n2);
    a=create(n1);
    b=create(n2);
    display(a,n1);
    display(b,n2);
    sort(a,n1);
    sort(b,n2);
     display(a,n1);
    display(b,n2);
    c=(int *)malloc(n1+n2*sizeof(int));
    c=merge(a,b,c,n1,n2);
    display(c,n1+n2);
    getch();
}

int* create(int size)
{
    int i,*a;
    a=(int *)malloc(size*sizeof(int));
    printf("Enter Elements of array:");
    for(i=0;i<size;i++)
    {
     scanf("%d",&a[i]);  
    }
    a[i]=INFINITY;
    return a;
}

void sort(int *arr,int size)
{ 
      int i,temp=0,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        
        }
}
}
void display(int *arr, int size)
{
      printf("\nElements:");
      int i;
    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }
}
int* merge(int *a,int *b,int *c,int n1,int n2)
{ 
    int i,j,k;
    for(i=0,k=0,j=0;i<n1+n2;i++)
    {
        if(a[k]<b[j])
        {
            c[i]=a[k];
            k++;
        }
        else
        {
            c[i]=b[j];
            j++;
        }

    }
    return c;
}

