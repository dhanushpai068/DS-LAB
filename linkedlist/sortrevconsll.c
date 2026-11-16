
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head1 = NULL, *head2 = NULL;

struct node *getnode(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory not available\n");
        exit(1);
    }

    newnode->data = x;
    newnode->link = NULL;
    return newnode;
}

struct node *create(struct node *head)
{
    int n, i, x;
    struct node *newnode, *temp;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &x);

        newnode = getnode(x);

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while (temp->link != NULL)
                temp = temp->link;

            temp->link = newnode;
        }
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }

    printf("NULL\n");
}


void sort(struct node *head)
{
    struct node *i, *j;
    int t;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    for (i = head; i->link != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->data > j->data)
            {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }

    printf("List sorted\n");
}


struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *cur = head, *next;

    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }

    printf("List reversed\n");
    return prev;
}

struct node *concatenate(struct node *h1, struct node *h2)
{
    struct node *temp;

    if (h1 == NULL)
        return h2;

    temp = h1;

    while (temp->link != NULL)
        temp = temp->link;

    temp->link = h2;

    return h1;
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n----- SINGLY LINKED LIST OPERATIONS -----\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 to List 1\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                head1 = create(head1);
                break;

            case 2:
                head2 = create(head2);
                break;

            case 3:
                printf("List 1: ");
                display(head1);
                break;

            case 4:
                printf("List 2: ");
                display(head2);
                break;

            case 5:
                sort(head1);
                printf("List 1: ");
                display(head1);
                break;

            case 6:
                head1 = reverse(head1);
                printf("List 1: ");
                display(head1);
                break;

            case 7:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Concatenated list: ");
                display(head1);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

