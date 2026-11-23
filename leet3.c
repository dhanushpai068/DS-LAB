#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int find132pattern(int nums[], int n)
{
    int second = -999999;

    for(int i = n-1; i >= 0; i--)
    {
        if(nums[i] < second)
        {
            return 1;
        }

        while(top != -1 && nums[i] > stack[top])
        {
            second = stack[top];
            top--;
        }

        top++;
        stack[top] = nums[i];
    }

    return 0;
}

int main()
{
    int nums[SIZE], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    if(find132pattern(nums, n))
    {
        printf("132 Pattern Found");
    }
    else
    {
        printf("132 Pattern Not Found");
    }

    return 0;
}
