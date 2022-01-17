#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;
    struct queue *link;
};

struct queue *start1 = NULL;
struct queue *stop1 = NULL;

struct queue *start2 = NULL;
struct queue *stop2 = NULL;

void Enqueue1(int x)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->data = x;
    temp->link = NULL;
    if (start1 == NULL && stop1 == NULL)
    {
        start1 = temp;
        stop1 = temp;
    }
    else{
        stop1->link = temp;
        stop1 = temp;
    }
}

void Enqueue2(int y)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->data = y;
    temp->link = NULL;
    if (start2 == NULL && stop2 == NULL)
    {
        start2 = temp;
        stop2 = temp;
    }
    else{
        stop2->link = temp;
        stop2 = temp;
    }
}

void Print(struct queue *head)
{
    struct queue *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n\n");
}

int main()
{
   int num1, num2, i, x, y;
   printf("Enter the total elements for first queue: ");
   scanf("%d", &num1);
   printf("Enter the elements: ");
   for (i = 0; i < num1; i++)
   {
       scanf("%d", &x);
       Enqueue1(x);
   }
   printf("\n\n");
   printf("Enter the total elements for second queue: ");
   scanf("%d", &num2);
   printf("Enter the elements: ");
   for (i = 0; i < num2; i++)
   {
       scanf("%d", &y);
       Enqueue2(y);
   }
   printf("\nThe result after merge: \n");
   Print(start2);
}
