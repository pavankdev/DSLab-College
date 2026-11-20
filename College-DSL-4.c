/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1

Title: Browser Navigation System Using Stack
LAB ASSIGNMENT NO: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define PAGE_SIZE 100

char backStack[MAX][PAGE_SIZE];
char forwardStack[MAX][PAGE_SIZE];

int backTop = -1;
int forwardTop = -1;

char currentPage[PAGE_SIZE] = "Home";

/* Push a page into a stack */
void push(char stack[MAX][PAGE_SIZE], int *top, const char page[])
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    (*top)++;
    strcpy(stack[*top], page);
}

/* Pop a page from a stack */
int pop(char stack[MAX][PAGE_SIZE], int *top, char page[])
{
    if (*top == -1)
    {
        return 0;
    }

    strcpy(page, stack[*top]);
    (*top)--;
    return 1;
}

/* Clear the Forward Stack */
void clearForwardStack()
{
    forwardTop = -1;
}

/* Visit a new webpage */
void visitNewPage()
{
    char newPage[PAGE_SIZE];

    printf("Enter new webpage: ");
    scanf(" %99[^\n]", newPage);

    push(backStack, &backTop, currentPage);
    strcpy(currentPage, newPage);

    /* New page clears forward history */
    clearForwardStack();

    printf("Visited: %s\n", currentPage);
}

/* Go Back */
void goBack()
{
    char page[PAGE_SIZE];

    if (!pop(backStack, &backTop, page))
    {
        printf("No previous page available.\n");
        return;
    }

    push(forwardStack, &forwardTop, currentPage);
    strcpy(currentPage, page);

    printf("Back navigation successful.\n");
    printf("Current Page: %s\n", currentPage);
}

/* Go Forward */
void goForward()
{
    char page[PAGE_SIZE];

    if (!pop(forwardStack, &forwardTop, page))
    {
        printf("No forward page available.\n");
        return;
    }

    push(backStack, &backTop, currentPage);
    strcpy(currentPage, page);

    printf("Forward navigation successful.\n");
    printf("Current Page: %s\n", currentPage);
}

/* Display current page */
void displayCurrentPage()
{
    printf("Current Page: %s\n", currentPage);
}

int main()
{
    int choice;

    printf("========================================\n");
    printf("  BROWSER NAVIGATION SYSTEM USING STACK\n");
    printf("========================================\n");
    printf("Initial Page: %s\n", currentPage);

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("----------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            visitNewPage();
            break;

        case 2:
            goBack();
            break;

        case 3:
            goForward();
            break;

        case 4:
            displayCurrentPage();
            break;

        case 5:
            printf("Exiting Browser Navigation System...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}