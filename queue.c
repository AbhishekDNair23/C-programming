#include<stdio.h>
int rear=-1,front=-1;
int queue[10];
void enqueue(int n)
{
    if(rear==10-1)
    {
        printf("Queue is full");
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=n;
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
}
void dequeue()
{
    int n;
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty");
    }
    else 
    {
        n=queue[front];
        printf("Deleted element %d\n",n);
        front ++;
    }
}
void peek()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The top element is %d\n",queue[rear]);
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("The elements are");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
int main(){
    int num,value;
    printf("choose \n1 for enqueue \n2 for dequeue \n3 for peek \n4 for display\n 5 for exit\n ");
    while(1){
        printf("Enter the operation number");
        scanf("%d",&num);
    switch(num){
        case 1:
        printf("Enter the number to be insterted");
        scanf("%d",&value);
        enqueue(value);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        peek();
        break;
        case 4:
        display();
        break;
        case 5:
        printf("Exit\n");
        return 0;
        default:
        printf("invalid entry\n");
    }
}          
}
