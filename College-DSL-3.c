/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    double phone;
    struct Contact *next;
};

struct Contact *head = NULL;

/* Insert contact at beginning */
void insertBeginning()
{
    struct Contact *newNode;
    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter phone number: ");
    scanf("%lf", &newNode->phone);

    newNode->next = head;
    head = newNode;

    printf("Contact inserted at beginning successfully.\n");
}

/* Insert contact at end */
void insertEnd()
{
    struct Contact *newNode, *temp;
    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter phone number: ");
    scanf("%lf", &newNode->phone);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Contact inserted at end successfully.\n");
}

/* Delete contact by name */
void deleteContact()
{
    char name[50];
    struct Contact *temp, *prev;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    temp = head;
    prev = NULL;

    /* Delete first node */
    if (strcmp(temp->name, name) == 0)
    {
        head = temp->next;
        free(temp);
        printf("Contact deleted successfully.\n");
        return;
    }

    /* Search for contact */
    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Contact deleted successfully.\n");
}

/* Search contact by name */
void searchContact()
{
    char name[50];
    struct Contact *temp;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name: %s\n", temp->name);
            printf("Phone: %.0lf\n", temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("Contact not found.\n");
}

/* Display all contacts */
void displayContacts()
{
    struct Contact *temp;
    int count = 1;

    if (head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    temp = head;
    printf("\n----- Contact List -----\n");
    while (temp != NULL)
    {
        printf("\nContact %d\n", count);
        printf("Name: %s\n", temp->name);
        printf("Phone: %.0lf\n", temp->phone);
        temp = temp->next;
        count++;
    }
    printf("------------------------\n");
}

/* Free all allocated memory */
void freeAll()
{
    struct Contact *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert Contact at Beginning\n");
        printf("2. Insert Contact at End\n");
        printf("3. Delete Contact by Name\n");
        printf("4. Search Contact by Name\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            deleteContact();
            break;

        case 4:
            searchContact();
            break;

        case 5:
            displayContacts();
            break;

        case 6:
            freeAll();
            printf("All allocated memory released.\n");
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
