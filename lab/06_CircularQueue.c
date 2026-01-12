/*6. Develop a menu driven Program in C for the following operations on Circular QUEUE of
Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

char queue[N];
int front =-1; int rear =-1;

void enqueue( ){
    char x;
    //empty

    if(front ==-1 &&rear ==-1){
        printf("enetr element:");
        scanf(" %c",&x);
       rear=front=0;
       queue[rear]=x;
       printf("added %c \n",queue[rear]);
    }

    // full
    else if((rear+1)%N==front){
        printf("full");
        return ;
    }

    else{ 
        printf("enetr element:");
        scanf(" %c",&x);   
         rear=(rear+1)%N;
        queue[rear]=x;
        printf("added %c \n",queue[rear]);
    }
}

void dequeue(){
    //empty
    if(front==-1 && rear==-1){
        printf("empty!!");
        return ;
    }
    //one wlement
    else if(front==rear){
        printf("deleted %c ",queue[front]);
        front=rear=-1;
    }
    else
    {
    printf("deleted %c ",queue[front]);
    front = (front+1)%N;
    }
    
}
void display(){
    //empty
    if(rear==-1 && front ==-1){
        printf("empty");
        return ;
    }

    else{
        for(int i=front;i!=rear;i=(i+1)%N){
            printf("%c",queue[i]);
        }
        printf("%c",queue[rear]);

    }
}

int main() {
    int ch;
    while (1) {
        printf("\n\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid");
        }
    }
}