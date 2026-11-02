#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
int main(void)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory not allocated\n");
return 1;
}
newNode->data = 50;
newNode->next = NULL;
printf("Data of the node : %d\n", newNode->data);
if (newNode->next == NULL)
printf("Next of the node : NULL\n");
free(newNode);
return 0;
}
