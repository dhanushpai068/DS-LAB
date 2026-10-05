#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert()
{
    int value;
    if (rear==MAX-1)
    {
        printf("overflow");
        return;
    }
    printf("enter the no:");
    scanf("%d",&value);
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=value;
    printf("inserted");
}
void delete()
{
    if (front==-1)
    {
        printf("underflow");
        return;}
    printf("deleted element %d",queue[front]);
    front++;
    if(front>rear)
        front=rear=-1;

}
void display()
{
    int i;
    if(front==-1)
    {
        printf("empty queue");
        return;
    }
    printf("queue elements:");
    for (i=front;i<=rear;i++)
       {
            printf("%d",queue[i]);
       }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("linear queue\n");
        printf("\n1.insert \n2.delete \n3.display \n4.exit\n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:printf("exiting");
                   break;
            default:printf("invalid");
        }

    }while(choice!=4);
return 0;
}
