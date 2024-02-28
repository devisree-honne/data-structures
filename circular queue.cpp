#include<stdio.h>
#define N 100
int queue[N];
int i;
int front=-1,rear=-1;
void enqueue()
{ 
  if(front==-1 && rear==-1)
	{
		int X;
		scanf("%d",&X);
		front=rear=0;
		queue[rear]=X;
	}
	else if(((rear+1) % N) == front)
		{
		printf("queue is overflow !");
	}
	else
	{
	 int X;
	 printf("Enter the value to be inserted : ");
	 scanf("%d",&X);
	  rear=(rear+1) % N;
	  queue[rear]=X;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is underflow !");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
	  printf("DEQUEUED ELEMENT IS : %d\n",queue[front]);	
	  front=(front+1)%N;
	}
}
void access()
{
		if(front==-1 && rear==-1)
	{
		printf("queue is underflow !");
	}
	else
	{
	printf("front = %d \n rear = %d\n",queue[front],queue[rear]);
	}
}
void display()
{
		if(front==-1 && rear==-1)
	{
		printf("queue is underflow !");
	}
	else
	{
		printf("the elements in queue are : \n ");
		while(i!=rear)
		{
        	printf("%d\n",queue[i]);
    		i=(i+1)%N;
       }
       printf("%d\n",queue[i]);
    }
}
int main()
{
	int size;
	printf("enetr size of circular queue[N=100]: ");
	scanf("%d",&size);
	  if (size > N || size <= 0) 
	  {
        printf("Invalid size entered. Exiting...\n");
        return 1;
      }
      		printf("CIRCULAR QUEUE OPERATIONS USING ARRAY\n__\n1.enqueue()\n2.dequeue()\n3.front and rear elements\n4.display()\n5.exit\n");
	int choice;
	while(1){
	printf("\n enter choice: ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
			        enqueue();
			        break;
			  case 2 :dequeue();
			          break;
			  case 3 :access();
			          break;
			  case 4 :display();
			          break;
			  case 5 :printf("EXIT");
			           return 0;
			            default:
                printf("Enter the choice between 1 and 5.\n");
                break;

	    }
	}
}
