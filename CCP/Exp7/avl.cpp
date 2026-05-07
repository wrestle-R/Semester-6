class Node
{
public:
    int data;
    Node *left, *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree
{
public:
    Node* root = NULL;

    int getHeight(Node* node)
    {
        if(node == NULL)
            return 0;

        return node->height;
    }

    int getBalance(Node* node)
    {
        if(node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key)
    {
        if(node == NULL)
            return new Node(key);

        if(key < node->data)
            node->left = insert(node->left, key);

        else if(key > node->data)
            node->right = insert(node->right, key);

        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if(balance > 1 && key < node->left->data)
            return rightRotate(node);

        if(balance < -1 && key > node->right->data)
            return leftRotate(node);

        if(balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if(balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    bool isBalanced(Node* root)
    {
        if(root == NULL)
            return true;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if(abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right))
            return true;

        return false;
    }
};