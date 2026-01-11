/*4. Develop a Program in C for converting an Infix Expression to Postfix Expression. Program
should support for both parenthesized and free parenthesized expressions with the
operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/

#include<stdio.h>
#include<ctype.h>

char stack[100],infix[100],postfix[100];
int top=-1;

void push(char c){
    stack[++top]=c;
}

int pop(){
    return stack[top--];
}
int prec(char c){
    if (c=='^'|| c== '$'){
        return 3;
    }
    else if (c=='*' || c== '/'|| c=='%'){
        return 2;
    }

    else if (c=='+'|| c== '-'){
        return 1;
    }
    return 0;

}

int main(){
    int j=0;
    printf("enetr the infix expression:");
    scanf("%s",infix);

    for(int i=0;infix[i];i++){
        int s =infix[i];
        if(isalnum(s)){
            postfix[j++]=s;
        }
        else if(s=='('){
            push(s);
        }
        else if(s==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }

        else {
            while (top!=-1 && prec(stack[top]) >= prec(s)){
            postfix[j++]=pop();
            }
        
        push(s);
            }


      }

    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}

//enetr the infix expression:K+L-M*N+(O^P)*W/U/V*T+Q
// Postfix: KL+MN*-OP^W*U/V/T*+Q+