#include<stdio.h>

#define max 8
int queue[max];
int front=-1,rear=-1;

void backInsert(int item) {
    if(rear == max - 1) {
        printf("Overflow...");
    } else {
        if (rear == -1 && front == -1) {
            front=rear=0;
        } else {
            rear++;
        }
        queue[rear] = item;
        printf("Item is added at back.\n\n");
    }
}

void frontInsert(int value){
    if(rear==max-1&& front==0){
        printf("Overflow");
    }
    else{
        front=front-1;
        queue[front]=value;
         printf("Item is added at front.\n\n");
    }
}

void deleteFront(){
    if (front==-1|| front>rear){
        printf("Underflow...");
    }
    else{
        int element = queue[front];
        printf("Deleted element :%d",element);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    printf("\n");
}

void deleteBack(){
    if(rear==-1){
        printf("Underflow\n");
    }
    else{
        int item=queue[rear];
        if(front==rear){
            front=rear=-1;
        }
        else{
            rear--;
        }
    }
}

void display(){
    if (front==-1&&rear==-1){
        printf("The Queue is Empty.\n");
        
    }
    else{
        
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int i=1,value,item;
    while(i>0){
        printf("Enter the choice....\n");
        printf("1.Insert_front.\n2.Insert_back.\n3.delete_front.\n4.delete_back.\n5.display.\n");
        scanf("%d",&value);
        switch(value){
            case 1:{
                printf("Enter the value..");
                scanf("%d",&item);
                frontInsert(item);
                break;
            }
            case 2:{
                printf("Enter the value..");
                scanf("%d",&item);
                backInsert(item);
                break;
            }
            case 3:{
                deleteFront();
                break;
            }
            case 4:{
                deleteBack();
                break;
            }
            case 5:{
                display();
                break;
            }
        }
        
    }
    return 0;
}
