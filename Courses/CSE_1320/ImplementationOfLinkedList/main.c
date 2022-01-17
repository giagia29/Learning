//Insert a node at the beginning
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;

void Insert(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Delete(int position)
{
    int i;
    struct node *temp = head;
    if(position == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    for (i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void Print()
{
    struct node *temp = head;
    printf("Here goes the linked list: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int num, i, x;
    printf("Enter the total input number: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        Insert(x);
    }
    Print();
    Delete(2);
    Print();
}
