/*5. Develop a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %,^
b. Solving Tower of Hanoi problem with n disks.*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

int stack[100],ch=0;
int top=-1;

void push(char c){
    stack[++top]= c;
}
int pop(){
    return stack[top--];
}

int main(){
    char postfix[100],ch;
    int i=0,opr1,opr2;

    printf("enter the post fix expression");
    scanf("%s",postfix);

    ch = postfix[i];
    i=i+1;

    while(ch!='\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            opr2=pop();
            opr1=pop();
            switch(ch){
                case '+' :push(opr2+opr1); break;
                case '-' :push(opr1-opr2); break;
                case '/' :push(opr1/opr2); break;
                case '*' :push(opr1*opr2); break;
                case '%' :push(opr1%opr2); break;
                case '^' :push(pow(opr1,opr2)); break;
            }
        }
        
        ch = postfix[i];
        i=i+1;
    }
    printf("Result = %d\n", stack[top]);
    return 0;

}


/*enter the post fix expression62+5*84/-
Result = 38*/