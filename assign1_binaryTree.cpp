#include <iostream>
using namespace std;
static int k = 0;
struct node
{
    int data;
    node *left, *right;
};

class stack
{
    node *data[30];
    int top;

public:
    stack()
    {
        top = -1;
    }
    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(node *p)
    {
        data[++top] = p;
    }

    node *pop()
    {
        return data[top--];
    }
};

class binary_tree
{
    node *root;

public:
    binary_tree()
    {
        root = NULL;
    }
    node *create()
    {
        node *p;
        int x;
        cout << " Enter value(-1 for no data): ";
        cin >> x;
        k++;
        if (x == -1)
        {
            return NULL;
        }

        p = new node;
        p->data = x;
        if (k == 1)
        {
            root = p;
        }
        cout << "Left child of '" << x << "'";
        p->left = create();
        cout << "Right child of '" << x << "'";
        p->right = create();
    }
    void inorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void preorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
    void postorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
    void inorder()
    {
        cout << "Inorder : ";
        inorder(root);
        cout << endl;
    }
    void preorder()
    {
        cout << "Preoder : ";
        preorder(root);
        cout << endl;
    }
    void postorder()
    {
        cout << "Postorder : ";
        postorder(root);
        cout << endl;
    }
    int heightOfBinaryTree(node *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        int left = heightOfBinaryTree(r->left);
        int right = heightOfBinaryTree(r->right);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
    int heightOfBinaryTree()
    {
        int height = heightOfBinaryTree(root);
        cout << "Height of binary tree : " << height << endl;
    }
    void copy(binary_tree &obj)
    {
        obj.root = root;
    }
    void mirror(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            node *temp;
            mirror(r->left);
            mirror(r->right);
            temp = r->left;
            r->left = r->right;
            r->right = temp;
        }
    }
    void mirror()
    {
        mirror(root);
    }
    void display_leafNodes(node *r)
    {
        if (r->left == NULL && r->right == NULL)
        {
            cout << r->data << " ";
            return;
        }
        display_leafNodes(r->left);
        display_leafNodes(r->right);
    }
    void leafNodes()
    {
        cout << "Leaf Nodes : ";
        if (root == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        else
        {
            display_leafNodes(root);
        }
    }
    bool identical(node *t1, node *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return true;
        if (t1 != NULL && t2 != NULL)
        {
            return (t1->data == t2->data && identical(t1->left, t2->left) && identical(t1->right, t2->right));
        }
        return false;
    }
    bool identi(binary_tree &obj2)
    {
        return identical(root, obj2.root);
    }
    void preorder_nonRecursive(node *r)
    {
        stack s;
        while (r != NULL)
        {
            cout << r->data << " ";
            s.push(r);
            r = r->left;
        }
        while (!s.empty())
        {
            r = s.pop();
            r = r->right;
            while (r != NULL)
            {
                cout << r->data << " ";
                s.push(r);
                r = r->left;
            }
        }
    }
    void preorder_nonRecursive()
    {
        cout << "Non-Recursive Preorder : ";
        preorder_nonRecursive(root);
        cout << endl;
    }
    void inorder_nonRecursive(node *r)
    {
        stack st;
        while (r != NULL)
        {
            st.push(r);
            r = r->left;
        }
        while (!st.empty())
        {
            r = st.pop();
            cout << r->data << " ";
            r = r->right;
            while (r != NULL)
            {
                st.push(r);
                r = r->left;
            }
        }
    }
    void inorder_nonRecursive()
    {
        cout << "Non-Recursive Inoder : ";
        inorder_nonRecursive(root);
        cout << endl;
    }
};

int main()
{
    binary_tree bt, bt_same, bt2;

    int ch;
    for (;;)
    {
        cout << "\nPress:\n1. Insert a node\n2. All traversals \n3. Find the height of a tree.\n4. Assign this tree to another and then erase all nodes in a binary tree.\n5. Create a Mirror image of a tree.\n6. Check if two trees are identical or not\n7.display all the leaf nodes\n8. construct tree from given inorder and preorder traversals.\n9. to EXIT." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            bt.create();
            cout << endl;
            break;
        case 2:
            cout << "\t---Binary Tree Traversals via DFS (Recursive)---" << endl;
            bt.inorder();
            bt.preorder();
            bt.postorder();
            cout << "\t---Binary Tree Traversals via DFS (Non-Recursive)---" << endl;
            bt.preorder_nonRecursive();
            bt.inorder_nonRecursive();
            break;
        case 3:
            bt.heightOfBinaryTree();
            break;
        case 4:
            bt.copy(bt_same);
            cout << "****Copied binary Tree****" << endl;
            cout << "\t";
            bt_same.inorder();
            cout << endl;
            break;
        case 5:
            bt.copy(bt_same);
            bt_same.mirror();
            cout << "****Mirror image of tree****" << endl;
            cout << "\t";
            bt_same.inorder();
            cout << endl;
            bt_same.mirror();
            cout << "****Original tree****" << endl;
            cout << "\t";
            bt.inorder();
            cout << endl;
            break;
        case 6:
            cout << "Enter data for another binary tree: ";
            k = 0;
            bt2.create();
            // cout << "****Tree 1****" << endl;
            // cout << "\t";
            // bt.inorder();
            cout << "****Tree 2****" << endl;
            cout << "\t";
            bt2.inorder();
            cout << endl;
            if (bt.identi(bt2))
            {
                cout << "Trees are identical." << endl;
            }
            else
            {
                cout << "Trees are not identical." << endl;
            }

            break;
        case 7:
            bt.leafNodes();
            break;
        case 8:
            break;
        case 9:
            return 17;
        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    }
    return 0;
}


//for postorder non recursive refer the code below
/*#include <iostream>
using namespace std;
static int k = 0;
struct node
{
    int data;
    node *left, *right;
};
struct stacknode
{
    node *data;
    int flag;
};
class stack
{
    stacknode data[30];
    int top;

public:
    stack()
    {
        top = -1;
    }
    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(stacknode p)
    {
        data[++top] = p;
    }

    stacknode pop()
    {
        return data[top--];
    }
};
class binary_tree
{
    node *root;

public:
    binary_tree()
    {
        root = NULL;
    }
    node *create()
    {
        node *p;
        int x;
        cout << " Enter value(-1 for no data): ";
        cin >> x;
        k++;
        if (x == -1)
        {
            return NULL;
        }

        p = new node;
        p->data = x;
        if (k == 1)
        {
            root = p;
        }
        cout << "Left child of '" << x << "'";
        p->left = create();
        cout << "Right child of '" << x << "'";
        p->right = create();
    }
    void postorder_nonRecursive(node *r)
    {
        stack stc;
        stacknode stnode;
        node *p;
        while (r != NULL)
        {
            stnode.data = r;
            stnode.flag = 0;
            stc.push(stnode);
            r = r->left;
        }
        while (!stc.empty())
        {
            stnode = stc.pop();
            if (stnode.flag == 0)
            {
                stnode.flag = 1;
                stc.push(stnode);
                r = stnode.data;
                r = r->right;
                while (r != NULL)
                {
                    stnode.data = r;
                    stnode.flag = 0;
                    stc.push(stnode);
                    r = r->left;
                }
            }
            else
            {
                p = stnode.data;
                cout << p->data << " ";
            }
        }
    }
    void postorder_nonRecursive()
    {
        cout << "Non-Recursive Postorder : ";
        postorder_nonRecursive(root);
        cout << endl;
    }
};

int main()
{
    binary_tree bt;
    bt.create();
    bt.postorder_nonRecursive();
    return 0;
}*/

//for tree traversal via BFS
/*
#include <iostream>
using namespace std;

static int k = 0;
struct node
{
    int data;
    node *left, *right;
};

class que
{
    node *data[30];
    int rear, front;

public:
    que()
    {
        rear = front = -1;
    }
    void init()
    {
        rear = front = -1;
    }
    int empty()
    {
        if (rear == -1)
        {
            return 1;
        }
        return 0;
    }
    void enque(node *t)
    {
        if (empty())
        {
            rear = front = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = t;
    }
    node *deque()
    {
        node *t = data[front];
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front++;
        }
        return t;
    }
};

class btree
{
    node *root;

public:
    btree()
    {
        root = NULL;
    }
    node *create()
    {
        int x;
        cout << "Enter value(-1 for no data) : ";
        cin >> x;
        k++;
        if (x == -1)
        {
            return NULL;
        }
        node *p = new node;
        p->data = x;
        if (k == 1)
        {
            root = p;
        }
        cout << "Left child of '" << x << "'";
        p->left = create();
        cout << "Right child of '" << x << "'";
        p->right = create();
    }
    void dfs(node *r)
    {
        que q1, q2;
        node *t1, *t2;
        if (r == NULL)
        {
            return;
        }
        q1.enque(r);
        cout << r->data << endl;
        cout << "\t";
        while (!q1.empty())
        {
            q2.init();
            while (!q1.empty())
            {
                t1 = q1.deque();
                if (t1->left != NULL)
                {
                    q2.enque(t1->left);
                    cout << t1->left->data << "\t";
                }
                if (t1->right != NULL)
                {
                    q2.enque(t1->right);
                    cout << t1->right->data << "\t";
                }
            }
            cout << endl;
            cout << " ";
            q1 = q2;
        }
    }
    void binaryTreeDFS()
    {
        cout << "***Binary Tree Traversal (Breadth FIRST)***" << endl;
        cout << "\t";
        dfs(root);
        cout << endl;
    }
};

int main()
{
    btree t;
    t.create();
    t.binaryTreeDFS();
    return 0;
}
*/
