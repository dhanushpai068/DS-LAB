
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

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



void push(int x)
{
    struct node *newnode = getnode(x);
    newnode->link = top;
    top = newnode;
    printf("%d pushed into stack\n", x);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("STACK UNDERFLOW\n");
        return;
    }

    temp = top;
    printf("The value being deleted is: %d\n", temp->data);
    top = top->link;
    free(temp);
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element is: %d\n", top->data);
}

void displayStack()
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom): ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}


void enqueue(int x)
{
    struct node *newnode = getnode(x);

    if (rear == NULL)
        front = rear = newnode;
    else
    {
        rear->link = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue\n", x);
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    temp = front;
    printf("The value being deleted is: %d\n", temp->data);
    front = front->link;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements (front to rear): ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n----- STACK & QUEUE USING LINKED LIST -----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display Stack\n");
        printf("5. Enqueue\n6. Dequeue\n7. Display Queue\n8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
                break;

            case 5:
                printf("Enter the value: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 6:
                dequeue();
                break;

            case 7:
                displayQueue();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
