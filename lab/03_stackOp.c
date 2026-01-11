/*3. Develop a menu driven Program in C for the following operations on STACK of Integers
(Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5

int stack[max];
int top =-1;

void push( ){
    int x;
    if(top==max -1){
        printf("overflow \n");
    }
    else{
        printf("enter elemnt:");
    scanf("%d",&x);
        top ++;
        stack[top]=x;
        printf("pushed %d \n",x);
    }

}

int pop(){
    if(top == -1){
        printf("underflow \n");
    }
    else{
        int value = stack[top];
        top--;
        printf("poped %d \n",value);
        return value;
    }
}

void display(){
    for (int i=0;i<= top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void checkpalindrom(){
    char  str[100];
    int len ,i;
    printf("enter string :");
    scanf("%s",str);
    int top=-1;

    for(i=0;i< strlen(str);i++){
        stack[++top]=str[i];
    }

   for(i=0;i<strlen(str);i++){
        if(stack[top--]!=str[i]){
            printf("%s not palindrom",str);
            return ;
        }
        
    }
    printf("%s is a Palindrome\n", str);
}

int main(){
    int ch;
    while(1){
        printf("push,pop,display,palindrom,exit \n");
        printf("enter your choice:");
        
        scanf("%d",&ch);

        switch(ch){
            case 1:push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: checkpalindrom(); break;
            case 5: exit(0);
            default :
            printf("invld");
    


        }
    }

    return 0;
}