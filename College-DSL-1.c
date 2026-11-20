/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A
*/
#include <stdio.h>
#include <stdbool.h>
int main()
{
  int n, i,l, pos, ch;
  bool flag = false;
  int student_marks[]={90, 85, 78, 92, 88}; // Example student marks 
  do
{
  printf("--------------------Menu---------------------\n");
  printf("1. Insertion\n");
  printf("2. Deletion\n");
  printf("3. Display\n");
  printf("4. Linear Search\n");
  printf("5. Binary Search\n");
  printf("Enter your choice: ");
  scanf("%d", &ch);

  switch (ch)
  {
  case 1:
    /* code */
    printf("Insertion\n");
    printf("Enter the student marks: ");
    scanf("%d",&l);
    student_marks[sizeof(student_marks) / sizeof(student_marks[0]) - 1] = l;
    break;
  case 2:
    /* code */
    printf("Deletion\n");
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    for (i = pos - 1; i < sizeof(student_marks) / sizeof(student_marks[0]) - 1; i++)
    {
      student_marks[i] = student_marks[i + 1];
    }
    printf("Element deleted successfully.\n");
    break;
    case 3:
    /* code */  
    printf("Display\n");
    for (i = 0; i < sizeof(student_marks) / sizeof(student_marks[0]); i++)
    {
      printf("%d ", student_marks[i]);
    }
    printf("\n");
    break;
    case 4:
    /* code */  
    printf("Linear Search\n");
    printf("Enter the student marks to search: ");  
    scanf("%d",&n);
    for (i = 0; i < sizeof(student_marks); i++)
   {
       if (student_marks[i] == n)
      {
        printf("Element found at position: %d\n", i + 1);
        flag = true;
        break;
      }
  }
    if (!flag)
    {
      printf("Element not found\n");
    }
 case 5:
    /* code */  
    printf("Binary Search\n");
    printf("Enter the student marks to search: ");
    scanf("%d", &n);
    // Binary search implementation would go here
    flag = false;
    //sorting the array before binary search
    for (i = 0; i < sizeof(student_marks) / sizeof(student_marks[0]) - 1; i++)
    {
      for (int j = 0; j < sizeof(student_marks) / sizeof(student_marks[0]) - i - 1; j++)
      {
        if (student_marks[j] > student_marks[j + 1])
        {
          int temp = student_marks[j];
          student_marks[j] = student_marks[j + 1];
          student_marks[j + 1] = temp;
        }
      }
    }
    int low = 0;
    int high = sizeof(student_marks) / sizeof(student_marks[0]) - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (student_marks[mid] == n)
      {
        printf("Element found at position: %d\n", mid + 1);
        flag = true;
        break;
      }
      else if (student_marks[mid] < n)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    {
      /* code */
    }
    
    {
      /* code */

    }
    
    break;
    

  default:
    printf("Invalid choice\n");
    break;
  }
} while (ch != 0);

  return 0;
}
