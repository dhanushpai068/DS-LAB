#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key, value;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;
int capacity, count = 0;

void insert(int key, int value)
{
    struct node *temp = head;


    while(temp != NULL)
    {
        if(temp->key == key)
        {
            temp->value = value;


            if(temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if(temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;


            temp->prev = NULL;
            temp->next = head;

            if(head != NULL)
                head->prev = temp;

            head = temp;

            if(tail == NULL)
                tail = temp;

            return;
        }

        temp = temp->next;
    }


    struct node *newnode =
        (struct node*)malloc(sizeof(struct node));

    newnode->key = key;
    newnode->value = value;

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;
    else
        tail = newnode;

    head = newnode;

    count++;


    if(count > capacity)
    {
        temp = tail;

        tail = tail->prev;

        if(tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        free(temp);
        count--;
    }
}

int get(int key)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            int value = temp->value;

            if(temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if(temp->next != NULL)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;


            temp->prev = NULL;
            temp->next = head;

            if(head != NULL)
                head->prev = temp;
            else
                tail = temp;

            head = temp;

            return value;
        }

        temp = temp->next;
    }

    return -1;
}

void display()
{
    struct node *temp = head;

    printf("\nCache: ");

    while(temp != NULL)
    {
        printf("(%d,%d) ", temp->key, temp->value);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, key, value;

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    while(1)
    {
        printf("\n1. PUT");
        printf("\n2. GET");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key and value: ");
                scanf("%d%d", &key, &value);

                insert(key, value);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);

                printf("Value = %d", get(key));
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
