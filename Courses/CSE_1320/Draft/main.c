#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head;

void Reverse()
{
    struct node *prev = head;
    struct node *text = NULL;
    struct node *curr = NULL;
    while(prev != NULL)
    {
        text = prev->next;
        prev->next = curr;
        curr = prev;
        prev = text;
    }
    head = curr;
}

void Insert(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, i, x;
    printf("Enter an amount of number: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number you want: ");
        scanf("%d", &x);
        Insert(x);
    }
    printf("\nThe linked list after install: \n");
    Print();
    printf("\n\nReverse linked list: \n");
    Reverse();
    Print();
}
