
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node *add_node(struct node *start, int c, int p)
{
    struct node *ptr, *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->coeff = c;
    new_node->pow = p;
    new_node->next = NULL;

    if (start == NULL)
        return new_node;

    ptr = start;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;

    return start;
}

struct node *create_poly(struct node *start)
{
    int c, p;

    printf("\nEnter coefficient and power (enter -1 -1 to end)");
    printf("\nEnter terms in descending order of power: ");

    scanf("%d %d", &c, &p);

    while (!(c == -1 && p == -1))
    {
        start = add_node(start, c, p);
        scanf("%d %d", &c, &p);
    }

    return start;
}

void display_poly(struct node *start)
{
    struct node *ptr = start;

    if (ptr == NULL)
    {
        printf("0");
        return;
    }

    while (ptr != NULL)
    {
        printf(" %dx^%d", ptr->coeff, ptr->pow);
        ptr = ptr->next;

        if (ptr != NULL)
            printf(" +");
    }
}

struct node *add_poly(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1 = start1, *ptr2 = start2;
    int sum;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->pow == ptr2->pow)
        {
            sum = ptr1->coeff + ptr2->coeff;

            if (sum != 0)
                start3 = add_node(start3, sum, ptr1->pow);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->pow > ptr2->pow)
        {
            start3 = add_node(start3, ptr1->coeff, ptr1->pow);
            ptr1 = ptr1->next;
        }
        else
        {
            start3 = add_node(start3, ptr2->coeff, ptr2->pow);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        start3 = add_node(start3, ptr1->coeff, ptr1->pow);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        start3 = add_node(start3, ptr2->coeff, ptr2->pow);
        ptr2 = ptr2->next;
    }

    return start3;
}

int main()
{
    struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;

    printf("\nFirst polynomial");
    start1 = create_poly(start1);

    printf("\nSecond polynomial");
    start2 = create_poly(start2);

    start3 = add_poly(start1, start2, start3);

    printf("\nP1 =");
    display_poly(start1);

    printf("\nP2 =");
    display_poly(start2);

    printf("\nP1 + P2 =");
    display_poly(start3);

    printf("\n");

    return 0;
}
