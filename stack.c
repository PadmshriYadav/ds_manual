#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1; 
void push() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);
     if (top == N - 1) {
        printf("overflow ");
     }
     else{
        top++;
        stack[top] = x;
        printf("Pushed \n");
     }
     }
      void display(){
        if (top == -1) {
        printf("empty\n");
        }
        
        else{
            printf("displaying\n");
            for (int i = top; i >= 0; i--) {
                printf(" %d\n", stack[i]);
        }
      }
    }


    void pop(){
        int item;
        if (top == - 1) {
        printf("underflow ");
        }
        else{
        item = stack[top];
        top--;
         printf(" %d is value at %d position \n", item,stack[top]);
        }
     
    }
     int main() {
        int y;
    printf("Enter number of element: ");
    scanf("%d", &y);
    for (int i=0;i<y;i++){
          push();
    }
    display();
    pop();
    display();

     return 0;
     }