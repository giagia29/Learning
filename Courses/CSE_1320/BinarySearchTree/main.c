#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* GetNewNode(int data)
{
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

struct node* Insert(struct node *root, int data)
{
//empty tree(check whether the tree is empty or not)
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    //left subtree
    else if (data <= root->data)
    {
        root->left = Insert(root->left,data);
        return root;
    }
    //right subtree
    else
    {
        root->right = Insert(root->right,data);
        return root;
    }
}
//Search function
int Search(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}

int main()
{
    struct node *root = NULL;
    root = Insert(root,16);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,7);
    root = Insert(root,11);
    int num;
    printf("Enter a number to search: ");
    scanf("%d", &num);
    Search(root,num);
    if(Search(root,num) == 1)
    {
        printf("Found.\n");
    }
    else{
        printf("Not found.\n");
    }
    return 0;
}
