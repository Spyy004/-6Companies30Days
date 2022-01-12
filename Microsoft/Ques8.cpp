class Solution
{
    public:
    Node* getRight(Node* p)
    {
        Node* x = p->nextRight;
        while(x!=NULL)
        {
            if(x->left)
            {
                return x->left;
            }
            if(x->right)
            {
                return x->right;
            }
            x=x->nextRight;
        }
        return NULL;
    }
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       Node* p = root;
       root->nextRight=NULL;
     //  p->nextRight=NULL;
       while(p!=NULL)
       {
           Node* q = p;
           while(q!=NULL)
           {
               if(q->left)
               {
                   if(q->right)
                   {
                        q->left->nextRight=q->right;
                   }
                   else
                    {
                        q->left->nextRight = getRight(q);
                    }
               }
               if(q->right)
               {
                   q->right->nextRight=getRight(q);
               }
               q=q->nextRight;
           }
           if(p->left)
           {
               p=p->left;
           }
           else if(p->right)
           {
               p=p->right;
           }
           else
           {
               p=getRight(p);
           }
    } 
    }
      
};
