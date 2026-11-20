/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1
Title: Roll Number System Sorting Using Bubble Sort
*/

#include <stdio.h>

int main()
{
    int rollno[100], n, i, j, temp, choice;

    do
    {
        // Display menu
        printf("\n....MENU\t\n");
        printf("1. Insert Roll Numbers\n");
        printf("2. Bubble Sort\n");
        printf("3. Roll NO Are\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            printf("Enter roll numbers:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &rollno[i]);
            }
            break;

        case 2:
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (rollno[j] > rollno[j + 1])
                    {
                        temp = rollno[j];
                        rollno[j] = rollno[j + 1];
                        rollno[j + 1] = temp;
                    }
                }
                printf("Pass %d: ", i + 1);
                for (j = 0; j < n; j++)
                {
                    printf("%d ", rollno[j]);
                }
                printf("\n");
            }
            printf("\nSorted Roll Numbers: ");
            for (i = 0; i < n; i++)
            {
                printf("\t%d ", rollno[i]);
            }
            printf("\n");
            break;

        case 3:
            printf("Roll Numbers Are: ");
            for (i = 0; i < n; i++)
            {
                printf("\t%d", rollno[i]);
            }
            printf("\n");
            break;

        case 4:
            printf("Program ended.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
    } while (ch != 0);

    return 0;
}
