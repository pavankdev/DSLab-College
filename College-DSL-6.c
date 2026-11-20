/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll_number;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int roll)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll_number = roll;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int roll)
{
    if (root == NULL)
    {
        return createNode(roll);
    }
    if (roll < root->roll_number)
    {
        root->left = insert(root->left, roll);
    }
    else if (roll > root->roll_number)
    {
        root->right = insert(root->right, roll);
    }
    else
    {
        printf("Duplicate roll number %d entered. Insertion ignored.\n", roll);
    }
    return root;
}

struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int roll)
{
    if (root == NULL)
    {
        printf("Roll number %d not found for deletion.\n", roll);
        return root;
    }
    if (roll < root->roll_number)
    {
        root->left = deleteNode(root->left, roll);
    }
    else if (roll > root->roll_number)
    {
        root->right = deleteNode(root->right, roll);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            printf("Roll number deleted successfully.\n");
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            printf("Roll number deleted successfully.\n");
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->roll_number = temp->roll_number;
        root->right = deleteNode(root->right, temp->roll_number);
    }
    return root;
}

struct Node *search(struct Node *root, int roll)
{
    if (root == NULL || root->roll_number == roll)
    {
        return root;
    }
    if (roll < root->roll_number)
    {
        return search(root->left, roll);
    }
    return search(root->right, roll);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->roll_number);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->roll_number);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->roll_number);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, roll;
    struct Node *searchResult = NULL;

    while (1)
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert a student roll number\n");
        printf("2. Delete a student roll number\n");
        printf("3. Search for a student roll number\n");
        printf("4. Display inorder traversal\n");
        printf("5. Display preorder traversal\n");
        printf("6. Display postorder traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter roll number to insert: ");
            scanf("%d", &roll);
            root = insert(root, roll);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            root = deleteNode(root, roll);
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            searchResult = search(root, roll);
            if (searchResult != NULL)
            {
                printf("Roll number %d found in the BST.\n", roll);
            }
            else
            {
                printf("Roll number %d not found.\n", roll);
            }
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}