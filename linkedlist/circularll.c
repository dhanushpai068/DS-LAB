
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

void insert_position()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }

        printf("Node inserted successfully!\n");
        return;
    }

    temp = head;

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
    {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted successfully!\n");
}

void delete_value()
{
    struct node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    do
    {
        if (temp->data == value)
        {
            if (temp == head && temp->next == head)
            {
                head = NULL;
            }
            else if (temp == head)
            {
                prev = head;

                while (prev->next != head)
                {
                    prev = prev->next;
                }

                head = head->next;
                prev->next = head;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Node deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    printf("Value not found!\n");
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Circular Linked List is empty!\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Insert at Given Position\n");
        printf("3. Delete Node by Value\n");
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
                insert_position();
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

