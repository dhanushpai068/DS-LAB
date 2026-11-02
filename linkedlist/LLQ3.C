#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
int main(void)
{
struct Node *head = NULL, *tail = NULL, *newNode, *temp;
int n, i, value;
printf("Enter the number of nodes: ");
scanf("%d", &n);
for (i = 1; i <= n; i++) {
printf("Enter value %d: ", i);
scanf("%d", &value);
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) { /* first node */
head = newNode;
tail = newNode;
} else { /* add at the end */
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
