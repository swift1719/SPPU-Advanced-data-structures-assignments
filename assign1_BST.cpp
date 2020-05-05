#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *left,*right;
};
class BST
{
    node *root;
    public:
    BST()
    {
        root=NULL;
    }
    node * create(int);
    node *insert(node *,int);
    void binarytree();
    void display();
    void preorderrec(node *);
    void inorderrec(node *);
    void postorderrec(node *);
    void revpostorderrec(node *);
    void revpreorderrec(node *);
    void revinorderrec(node *);
    void display_leaf(node *);
    void leaf();
    node* getroot()
    {
          return root;
    }
    void mirror(node*);
    void mirror_call()
    {
          mirror(root);
    }
    int heightBST(node *);
    int height()
    {
          return(heightBST(root));
     }
};
void BST::binarytree()
{
      int n;
    if(root==NULL)
    {
        cout<<"\nENTER THE DATA OF ROOT NODE:";
        cin>>n;
        root=insert(root,n);
    }
    else
    {
        cout<<"\nENTER THE DATA YOU WANT TO INSERT IN BINARY TREE:";
        cin>>n;
        insert(root,n);
    }

}
node* BST::create(int d)
{
    node *temp=new node;
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* BST::insert(node *temp,int d)
{
    if(temp==NULL)
       return create(d);
    if(d>temp->data)
     temp->right=insert(temp->right,d);
    else
     temp->left=insert(temp->left,d);

    return temp;
}
void BST::preorderrec(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preorderrec(temp->left);
        preorderrec(temp->right);
    }
}
void BST::inorderrec(node *temp)
{
    if(temp!=NULL)
    {
        inorderrec(temp->left);
        cout<<temp->data<<" ";
        inorderrec(temp->right);
    }
}
void BST::postorderrec(node *temp)
{
    if(temp!=NULL)
    {
        postorderrec(temp->left);
        postorderrec(temp->right);
        cout<<temp->data<<" ";
    }
}
void BST::revpostorderrec(node *temp)
{
    if(temp!=NULL)
    {
        revpostorderrec(temp->right);
        revpostorderrec(temp->left);
        cout<<temp->data<<" ";
    }
}
void BST::revinorderrec(node *temp)
{
    if(temp!=NULL)
    {
        revinorderrec(temp->right);
        cout<<temp->data<<" ";
        revinorderrec(temp->left);
    }
}
void BST::revpreorderrec(node *temp)
{
    if(temp!=NULL)
    {    cout<<temp->data<<" ";
        revpreorderrec(temp->right);
        revpreorderrec(temp->left);
    }
}
void BST::display()
{
    cout<<"\nPREORDERED TRAVERSAL OF BINARY TREE:";
    preorderrec(root);
    cout<<"\n";
    cout<<"\nINORDERED TRAVERSAL OF BINARY TREE:";
    inorderrec(root);
    cout<<"\n";
    cout<<"\nPOSTORDERED TRAVERSAL OF BINARY TREE:";
    postorderrec(root);
    cout<<"\n";
    cout<<"\nREVERSE PREORDERED TRAVERSAL OF BINARY TREE:";
    revpreorderrec(root);
    cout<<"\n";
    cout<<"\nREVERSE INORDERED TRAVERSAL OF BINARY TREE:";
    revinorderrec(root);
    cout<<"\n";
    cout<<"\nREVERSE POSTORDERED TRAVERSAL OF BINARY TREE:";
    revpostorderrec(root);
    cout<<"\n";

}

int BST::heightBST(node *temp)
{
     if(temp==NULL)
          return -1;
     int left,right;
     left=heightBST(temp->left);
     right=heightBST(temp->right);
     if(left>right)
       return left+1;
     else
       return right+1;
}

void BST::mirror(node *n)
{
      if(n==NULL)
      {
            return;
      }
      else
      {
            node *temp;
            mirror(n->left);
            mirror(n->right);
            temp=n->left;
            n->left=n->right;
            n->right=temp;
      }
}
void BST::leaf()
{
            if(root==NULL)
            {
                  cout<<"NULL\n";
                  return;
            }
            else
                  display_leaf(root);
}
void BST::display_leaf(node *q)
{
      if(q->left==NULL && q->right==NULL)
      {
            cout<<q->data<<" ";
            return;
      }
      display_leaf(q->left);
      display_leaf(q->right);
}
int identical(node *t1,node*t2)
{
      if(t1==NULL && t2==NULL)
            return 1;
      if(t1!=NULL && t2!=NULL)
      {
            return (t1->data==t2->data && identical(t1->left,t2->left) && identical(t1->right,t2->right));
      }
      return 0;
}
int main()
{  node *root;
   BST b,d;
   int ch,y,i,n;
  for(;;)
   {
       cout<<"\nPRESS:\n1.to add element\n2.to display\n3.to obtain height\n4.to display leaf nodes\n5.to obtain mirror tree\n6.to check for identical binary trees\n7.to exit";
       cout<<"\nENTER YOUR CHOICE: ";
       cin>>ch;
       switch(ch)
       {
         case 1:
            b.binarytree();
            break;
         case 2:
            b.display();
            break;
         case 3:
             int x;
             x=b.height();
             cout<<"\nHEIGHT (NUMBER OF NODES OF LONGEST PATH) OF BINARY SEARCH TREE:"<<x+1<<endl;
             cout<<"\nMAXIMUM NUMBER OF NODES IN A BINARY TREE OF"<<x+1<<"HEIGHT IS:"<<pow(2,x+1)-1;
             break;
         case 4:
               cout<<"\nLEAF NODES: ";
                  b.leaf();
                  break;
         case 5:
               b.mirror_call();
               break;
         case 6:
               cout<<endl<<"Create another binary tree: "<<endl;
               cout<<"Enter no. of nodes: ";
               cin>>n;
               for( i=0;i<n;i++)
               {
                 d.binarytree();
               }
               y=identical(b.getroot(),d.getroot());
               if(y==1)
                     cout<<"IDENTICAL TREES"<<endl;
              else
                  cout<<"NOT IDENTICAL"<<endl;
            break;
         case 7:
            return 77;
        default:cout<<"\nWRONG CHOICE.";
       }

   }

   return 0;
}
