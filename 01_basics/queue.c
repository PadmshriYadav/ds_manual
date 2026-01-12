#include<stdio.h>
#define N 5
//insert from rear....delete from front
int queue[N];
int front=-1,rear=-1;

void enqueue(int x){
    //empty
    if(front==-1 && rear ==-1){
        front=rear=0;
        queue[rear]=x;
    }
    //full
    else if(rear==N-1){
        printf("overflow");
    }
    //something is there
    else{
        rear++;
        queue[rear]=x;
    }

}

void dequeue(){
    //empty
    if(front==-1 && rear==-1){
        printf("underflow");
    }
    //one element is there
    else if(front== rear){
        front = rear =-1;
    }
    //more than one element
    else{
     front++;

    }
}


int display(){
    //empty
    if(front==-1&&rear==-1){
        printf("empty");

    }

    else{
        int i;
        for (i=front;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("\ndisplayng\n");
    display();
    dequeue();
    printf("\ndisplayng\n");
    display();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}