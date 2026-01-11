/*2. Develop a Program in C for the following operations on Strings.
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR
with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in
STR*/


#include <stdio.h>
// #include<conio.h>

void read(char *s){
    gets(s);
}

void my_strcpy(char *str1,char *str2){
    int i;
    for(i=0; str2[i]!='\0';++i){
        str1[i]=str2[i];
    }
    str1[i]='\0';
}

int matchnrplc(char *str,char *pat,char *rep){
    char ans[100];
    int flag =0;
    int c=0,m=0,i=0,j=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            m++;
            i++;
            if(pat[i]=='\0'){
                flag=1;
                for(int k=0;rep[k]!='\0';++j,k++){
                    ans[j]=rep[k];
                    
                }
                i=0;
                c=m;
            }
        }
        else{
            ans[j]=str[c];
            j++;
            c++;
        
        i=0;
        m=c;
        }
    }
    ans[j]='\0';
    my_strcpy(str,ans);
    return flag;
    
    
}

int main()
{
    char str[100],pat[20],rep[20];
    int flag =0;
    
    // clrscr();
    
    printf("enter string :");
    read(str);
    
    printf("enter pattern :");
    read(pat);
    
    printf("enter replace :");
    read(rep);
    
    flag = matchnrplc(str,pat,rep);
    if(flag==0){
        printf("not a match :");
    }
    else{
        printf("a match :,%s",str);
        
    }
    
    

    return 0;
}