
#include <stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
int n;
int Enqueue(int a[], int e)
{
    if (rear == n - 1)
    {
        printf("Queue is Full \n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        a[rear] = e;
        printf("The Element %d is Inserted \n", e);
    }
}
int Dequeue(int a[])
{
    if (rear == -1 || front > rear)
    {
        printf("The Queue is Empty \n");
    }
    else
    {
        printf("The Element %d is Deleted \n", a[front]);
        front++;
    }
}
int Display(int a[])
{
    if (rear == -1 || front > rear)
    {
        printf("The Queue is Empty \n");
    }
    else
    {
        printf("The Elements of Queue are : ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d \t ", a[i]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the size of the Queue : ");
    scanf("%d", &n);
    int queue[n], ch, ele;
    while (1)
    {
        printf("\n-------------------------------------------------");
        printf("\n 1 --> Enqueue \t 2 --> Dequeue");
        printf("\n 3 --> Display \t 4 --> Exit");
        printf("\n-------------------------------------------------");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &ele);
            Enqueue(queue, ele);
            break;
        case 2:
            Dequeue(queue);
            break;

        case 3:
            Display(queue);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}