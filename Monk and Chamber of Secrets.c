/*Queue Application-Monk and Chamber of Secrets
    
    Problem: 
    Hagrid says "follow the spiders" and so Harry and Ron head to the Forbidden Forest. There they meet Aragog, a giant spider who tells them about the innocence of Hagrid. But Aragog only allows Hagrid to go back. These boys have got into a serious trouble now.
    The only way to escape as Aragog says is to answer a question. 
    Aragog shows them a queue of N spiders of which only X spiders are to be selected. Each spider has some power associated with it. There are X iterations on the queue.
    In each iteration, X spiders are dequeued (if queue has less than X entries, all of them will be dequeued) and the one with maximum power is selected and remaining spiders are enqueued back to the queue (in the order they were dequeued) but their power is decreased by one unit. If there are multiple spiders with maximum power in those dequeued spiders, the one which comes first in the queue is selected. If at any moment , power of any spider becomes 0, it can't be decremented any further, it remains the same.
    Now, Aragog asks the boys to tell him the positions of all the selected spiders (positions in the initial given queue) in the order they are selected. As the boys are frightened and can't think of anything , they call Monk for the rescue. Help Monk to get the answer fast and save the boys.
    Input Format:
    The first line consists of two space separated integers N and X, denoting the number of spiders in the queue and the number of spiders that have to be selected respectively.
    The next line consists of an array A, A[i] denoting the power of spider at position i (1≤i≤N).
    Output Format:
    For each of the X iterations, output the position of the selected spider in that iteration. Position refers to the index at which the spider was present in the initial given queue (1 based indexing).
    Constraints:
    1≤X≤316
    X≤N≤X∗X
    1≤A[i]≤X; 1≤i≤N
    SAMPLE INPUT
     
    6 5
    1 2 2 3 4 5
    SAMPLE OUTPUT
     
    5 6 4 1 2 
    Explanation
    The initial queue: 1,2,2,3,4,5
    In first iteration, starting 5 entries are removed from the queue.
    The removed entries are:[1,2,2,3,4].
    The queue now becomes: [5] The maximum power spider is present at index 5 in the given initial queue. So, we print 5 and power of remaining spiders in the removed ones is decremented by 1 unit and enqueued back to the queue.
    The queue now becomes: [5,0,1,1,2]
    In the second iteration, we print index 6 as element 5 is present at index 6 in the initial queue.
    After the second iteration, the queue becomes: [0,0,0,1]
    Note that the power of spider with power 0 after the first iteration still remains 0.
    Example:
    6 5 
    1 2 2 3 4 5
    5 6 4 1 2 
    */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Spider's Index and Power*/
struct queue {
	int id;
    int power;
	struct queue *next;
};

struct queue *front=NULL,*rear=NULL,*ptr=NULL,*front1=NULL,*rear1=NULL,*ptr1=NULL;

void enqueue(int no,int power)
{
	struct queue *temp;
	temp=(struct queue *)malloc(sizeof(struct queue));
	temp->id=no;
	temp->power=power;
    temp->next=NULL;
	if(front==NULL)
    {
	  rear=front=temp;
    }
    else
    {
        rear->next=temp;
	    rear=temp;
    }
}
void enqueue1(struct queue *temp)
{
	if(front1==NULL)
    {
	  rear1=front1=temp;
    }
    else
    {
        rear1->next=temp;
	    rear1=temp;
    }
}
struct queue* dequeue()
{
    struct queue *temp;
    temp=front;
    front=front->next;
    temp->next=NULL;
    return temp;
}
struct queue * iteration(struct queue *front)
{
    int tid=0;
    struct queue *temp;
    int max;
        ptr=front;
        max=ptr->power;
        tid=ptr->id;
    while(ptr!=NULL)
    {
        if(max<ptr->power)
        {
            tid=ptr->id;
            max=ptr->power;
        }
        if(ptr->power>0)
        {
            ptr->power--;
        }
        ptr=ptr->next;
    }
    printf("%d ",tid);
    ptr=front;
    struct queue *prev;
    while(ptr!=NULL)
    {
        if(ptr->id==tid)
        {
            temp=ptr;
            if(ptr==front)
            {
                front=front->next;
            }
            else
            {
                prev->next=ptr->next;
            }
            temp->next=NULL;
            free(temp);
            break;
        }

        prev=ptr;
        ptr=ptr->next;
    }
    return front;
}
void display()
{
	struct queue *ptr=front;
	while(ptr!=NULL)
	{
	    printf("%d ",ptr->power);
	    ptr=ptr->next;
	}
}
void display1()
{
	struct queue *ptr=front1;
	while(ptr!=NULL)
	{
	    printf("%d ",ptr->power);
	    ptr=ptr->next;
	}
}	

int main()
{
	int i,noofspiders,id,pow,itrn;
	printf("Enter no.of spiders and no of iterations\n");
	scanf("%d %d",&noofspiders,&itrn);
    printf("Enter power of spiders\n");
	for(i=0;i<noofspiders;i++)
    {	
		scanf("%d",&pow);
		enqueue(i+1,pow);
	}
    
	printf("spiders in queue\n");
    for(i=0;i<itrn;i++)
    {
        ptr1=front;
        enqueue1(dequeue());
        ptr1=ptr1->next;
    }
    iteration(front1);
    ptr1=front1;
   for(i=0;i<itrn-1;i++)
   {
       enqueue(ptr1->id,ptr1->power);
       ptr1=ptr1->next;
   } 

// After Enqueue Displaying Of Intermediate Powers Of Spiders
// Decomment the Below Two statements to check intermediate Powers
   //    display();
     //  printf("\n");
   for(i=0;i<itrn-1;i++)
   {
       front=iteration(front);
    // Refer to Line : 184 and 185 
       //display();
       //printf("\n");
   }
   getch();
}

      
