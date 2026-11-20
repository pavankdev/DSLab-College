/*
LAB ASSIGNMENT NO: 5
Title: Implement a hospital patient registration system using queue simulate a patient queue data structure

1. Add patient (patient id, arrivaltime)
2. Attend patient
3. View patient
4. Check queue empty
5. Exit

Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    int pat;
    char arr[20];
};

int front = -1;
int rear = -1;
struct patient queue[20];

/* Add a patient */
void addpat()
{
    int patid;
    char arrt[20];

    if (rear == 19)
    {
        printf("The Queue Is Full");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        printf("Enter The Patient ID : ");
        scanf("%d", &patid);
        printf("Enter The Arrival Time: ");
        scanf("%s", arrt);
        queue[rear].pat = patid;
        strcpy(queue[rear].arr, arrt);
        printf("\npatient added succesfully!\n");
    }
}

/* Attend a Patient */
void attendpat()
{
    if (front == -1)
    {
        printf("No patient waiting");
    }
    else
    {
        printf("%d", queue[front].pat);
        printf("->");
        printf("%s", queue[front].arr);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
    }
}

void IsEmpty()
{
    if (front == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("Patients are waiting");
    }
}

void viewpat()
{
    if (front == -1)
    {
        printf("queue is empty");
        return;
    }
    else
    {
        printf("PatientId -> Arrival Time\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d -> %s", queue[i].pat, queue[i].arr);
            printf("\n");
        }
    }
}

int main()
{
    int choice;

    printf("==================================================\n");
    printf("  HOSPITAL PATIENT REGISTRATION SYSTEM USING QUEUE\n");
    printf("==================================================\n");

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Patient\n");
        printf("5. Exit\n");
        printf("----------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addpat();
            break;

        case 2:
            attendpat();
            break;

        case 3:
            viewpat();
            break;

        case 4:
            IsEmpty();
            break;

        case 5:
            printf("Exiting Hospital Patient Registration System...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}