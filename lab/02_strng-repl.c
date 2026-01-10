//function to find the first occurrence of a specific pattern (substring) within a larger string and replace it with a new replacement string.
#include <stdio.h>
#include <string.h>

void read(char *s)
{
    gets(s);
}
           //copy s2 to s1
void strcopy(char *s1,char *s2)
{
    int i;
    for(i=0;s2[i]!='\0';i++)
        s1[i]=s2[i];
    s1[i]='\0';
}





int main()
{
    char str[100],pat[20],rep[20];
    int flag=0;
    // clrscr();
    
    printf("Enter the string");
    read(str);
    printf("Enter the pattern");
    read(pat);
    printf("Enter the string to be replaced");
    read(rep);
    
    flag=matchnreplace(str,pat,rep);
    
    if(flag==1)
        printf("The string is found %s",str);
    else
        printf("The pattern is not found");
        
    return 0;
}