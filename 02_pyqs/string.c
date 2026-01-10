//Write functions in C for the following operations without using built-in functions i) compare two strings. ii) Concatenate two strings.

#include <stdio.h>
#include <stdlib.h>

int my_strcmp(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0' || str1[i] < str2[i]) {
        return -1;
    } else {
        return 1;
    }
}

void my_strcat(char dest[], char src[]) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

void rev_str(const char str1[]) {
    int i = 0;
    // Calculate length manually
    while (str1[i] != '\0') {
        i++;
    }

    char str2[100]; // Allocate buffer with sufficient size
    int j = 0;
    i--; // Start from the last character (before \0)
    while (i >= 0) {
        str2[j] = str1[i];
        i--;
        j++;
    }
    str2[j]='\0';
    printf("Reversed: %s\n", str2);
}

int main() {
    printf("--- String Comparison (my_strcmp) ---\n");

   
    char s1_a[] = "hello";
    char s2_a[] = "hello";
    int result_a = my_strcmp(s1_a, s2_a);
    printf("Comparing '%s' and '%s': Result = %d (Expected 0)\n", s1_a, s2_a, result_a);

    char s1_b[] = "apple";
    char s2_b[] = "banana";
    int result_b = my_strcmp(s1_b, s2_b);
    printf("Comparing '%s' and '%s': Result = %d (Expected < 0)\n", s1_b, s2_b, result_b);


    printf("\n--- String Concatenation (my_strcat) ---\n");

    char src_e[] = " World!";
    char dest_e[50] = "Hello";

    printf("Before concat: dest='%s', src='%s'\n", dest_e, src_e);
    my_strcat(dest_e, src_e);
    printf("After concat: dest='%s' (Expected 'Hello World!')\n", dest_e);

    return 0;
}
/*

output:----
--- String Comparison (my_strcmp) ---
Comparing 'hello' and 'hello': Result = 0 (Expected 0)
Comparing 'apple' and 'banana': Result = -1 (Expected < 0)

--- String Concatenation (my_strcat) ---
Before concat: dest='Hello', src=' World!'
After concat: dest='Hello World!' (Expected 'Hello World!')
*/