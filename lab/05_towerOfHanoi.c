// Solving Tower of Hanoi problem with n disks.

#include<stdio.h>
#include<math.h>

void tower(int n,char src,char temp,char dest){
    if(n==0) return;
    tower(n-1,src,dest,temp);
    printf("\nmove disk %d from %c to %c",n,src,dest);
    tower(n-1,temp,src,dest);
}
int main(){
    int n;
    printf("enter no of disk");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("total no of moves%d",(int)pow(2,n)-1);
    return 0;
}