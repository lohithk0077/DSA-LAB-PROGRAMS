#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DAYS 7
#define MAX_STRING_LENGTH 50

// Structure to represent a day
struct Day {
    char *name;
    int date;
    char *activity;
};

// Function to dynamically allocate memory for a string
char *allocateString() {
    char *str = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    if (!str) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return str;
}

// Function to create the calendar
void create(struct Day calendar[]) {
    for (int i = 0; i < MAX_DAYS; i++) {
        calendar[i].name = allocateString();
        calendar[i].activity = allocateString();
        printf("Enter the name of the day %d: ", i + 1);
        scanf("%s", calendar[i].name);
        printf("Enter the date of the day %d: ", i + 1);
        scanf("%d", &calendar[i].date);
        printf("Enter the activity for the day %d: ", i + 1);
        scanf(" %[^\n]", calendar[i].activity);
    }
}

// Function to read data from keyboard
void read(struct Day calendar[]) {
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

// Function to display the calendar
void display(struct Day calendar[]) {
    printf("\nCalendar:\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

int main() {
    struct Day calendar[MAX_DAYS];
    create(calendar);
    display(calendar);
    return 0;
}

