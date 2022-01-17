struct tree 
{
    int data;
    struct tree* left;
    struct tree* right;

};

bool isSameTree(struct tree* p, struct tree* q)
{
    bool temp1, temp2;
    if(p == NULL && q != NULL)
    {
        return false;
    }
    else if(p != NULL && q == NULL)
    {
        return false;
    }
    else if(p != NULL && q != NULL)
    {
        if(p->data == q->data)
        {
            temp1 = isSameTree(p->left, q->left);
            if(temp1 == true)
            {
                temp2 = isSameTree(p->right, q->right);    
            }
            
            if(temp1 == true && temp2 == true)
            {
                return true;
            }
        }   
    }
    else 
    {
        return true;
    }
    
    return false;
}