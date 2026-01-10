//code defines a structure for a calendar day and then uses an array of that structure to create a simple weekly calendar. It includes functions to read data into the calendar and display the calendar's contents.

#include <stdio.h>   //provides functions like printf (for output) and scanf (for input)
#define MAX_DESCRIPTION_LENGTH 100   //preprocessor directive defines a constant for the maximum number of characters an activity description can hold
#define MAX_DAY_NAME_LENGTH 20 //constant for the maximum number of characters a day name (like "Monday") can hold


//A structure is a user-defined data type that groups of different data types under a single name.
struct Day {
    char dayName[MAX_DAY_NAME_LENGTH];
    int date;
    char activityDescription[MAX_DESCRIPTION_LENGTH];
};

struct Day weekCalendar[7];  //element of this array is a struct Day

void read()
{
    for (int i = 0; i < 7; ++i)
    {
        printf("Enter day name for day %d: ", i + 1);
        scanf("%s", weekCalendar[i].dayName);
        
        printf("Enter date for day %d: ", i + 1);
        scanf("%d", &weekCalendar[i].date);
        
        printf("Enter activity description for day %d: ", i + 1);
        scanf(" %[^\n]", weekCalendar[i].activityDescription);
       //[^\n] is a scanset that reads all characters until a newline character is encountered.
    }
}

void display()
{
    printf("\n--- Calendar ---\n");
    for (int i = 0; i < 7; ++i)
    {
        printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, weekCalendar[i].dayName,
               weekCalendar[i].date, weekCalendar[i].activityDescription);
    }
}

int main()
{
    printf("Enter details for each day of the week:\n");
    read();
    display();
    return 0;
}