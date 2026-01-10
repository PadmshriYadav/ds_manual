#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
 #define MAX 100

 int stack[MAX];
 int top=-1;

 //stack implementN

 void push(int item){
    if (top==MAX-1){
        printf("overflow");
    }
    else{
        top++;
        stack[top]=item;
        
    }
 }
int pop(){
    if (top==-1){
        printf("empty");
        exit(1);
    }
    int item = stack[top];
    top--;
    return item;
}



 void compute(int opr1, char ch, int opr2) {
        int result;
        switch(ch){
                case'+' : result=opr1+opr2; break;
                case '-' :result = opr1 - opr2; break;
                case '*': result = opr1 * opr2; break;
                case '/' : result = opr1 / opr2; break;
                case '$' : result = (int)pow((double)opr1, (double)opr2); break;
                default: exit(1);
            }

            push(result);

        }


//givn expn ABC-D*+E$F+# -> 6 + ((3-2)*5)^1 + 7
char exprn[] = "ABC-D*+E$F+#";

 // making post fix conditioN


int evaluatePostfix(){
    int i=0; char ch; int opr1,opr2;

    int A=6, B=3, C=2, D=5, E=1, F=7;

    /*ch = exprn[i];
    while (ch != '#') {
    i++;
    ch = exprn[i];
}
    */
    while ((ch= exprn[i++])!='#'){
        if(isalpha(ch)){// check if letter (operand)
            switch(ch){
                case'A':push(A);break;
                case'B':push(B);break;
                case'C':push(C);break;
                case'D':push(D);break;
                case'E':push(E);break;
                case'F':push(F);break;
                default: exit(1);   
            }
    }
        else{
         //operator

            opr2=pop();
            opr1=pop();
            compute(opr1,ch,opr2);
        }

    } 

    return pop();
}  
    
int main() {
int result;
result = evaluatePostfix();
printf("Final Result: %d\n", result);

return 0;
}
