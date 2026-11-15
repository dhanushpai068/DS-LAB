
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void create()
{
    struct node *newnode, *temp;
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue? ");
        scanf("%d", &choice);
    }
}


void insert_left()
{
    struct node *newnode, *temp;
    int value;

    printf("Enter the value before which to insert: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->prev = temp->prev;
    newnode->next = temp;

    if (temp->prev != NULL)
    {
        temp->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }

    temp->prev = newnode;

    printf("Node inserted successfully!\n");
}

void delete_value()
{
    struct node *temp;
    int value;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully!\n");
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Doubly Linked List is empty!\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: NULL <-> ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert to the Left of a Node\n");
        printf("3. Delete a Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                insert_left();
                break;

            case 3:
                delete_value();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

