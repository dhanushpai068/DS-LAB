#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
/* creates one node and returns its address */
struct Node *createNode(int value)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}
int main(void)
{
struct Node *head = NULL, *tail = NULL, *newNode, *temp;
int n, i, value;
printf("Enter the number of nodes: ");
scanf("%d", &n);
for (i = 1; i <= n; i++) {
printf("Enter value %d: ", i);
scanf("%d", &value);
newNode = createNode(value);
if (head == NULL) {
head = newNode;
tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
}
printf("Linked list: ");
temp = head;
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
return 0;
}
