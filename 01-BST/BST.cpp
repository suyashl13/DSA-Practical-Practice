#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

class Tree
{
public:
    void createTree(int rootNodeData)
    {
        if (root != NULL)
        {
            root = NULL;
        }
        root = new node();
        root->data = rootNodeData;
    }

    void addDataToTree(int nodeData, struct node *parent)
    {
        if (parent->data < nodeData)
        {
            if (parent->right == NULL)
            {
                parent->right = new node();
                parent->right->data = nodeData;
            }
            else if (parent->data != NULL)
            {
                addDataToTree(nodeData, parent->right);
            }
        }
        else if (parent->data > nodeData)
        {
            if (parent->left == NULL)
            {
                parent->left = new node();
                parent->left->data = nodeData;
            }
            else if (parent->data != NULL)
            {
                addDataToTree(nodeData, parent->left);
            }
        }
    }

    void printPostorder(struct node *node)
    {
        if (node == NULL)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    void printInorder(struct node *node)
    {
        if (node == NULL)
            return;

        printInorder(node->left);

        cout << node->data << " ";

        printInorder(node->right);
    }

    void printPreorder(struct node *node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";

        printPreorder(node->left);

        printPreorder(node->right);
    }
};

void driver(Tree t)
{
    while (true)
    {
        cout << "**** MENU ****" << endl;
        int option;
        int data;
        if (root == NULL)
        {
            cout << "1. Create Tree" << endl;
            cout << "2. Exit" << endl;

            cout << endl
                 << "Select option :";
            cin >> option;

            if (option == 1)
            {
                cout << "Enter the value of root node : ";
                cin >> data;
                t.createTree(data);
            }
        }
        else
        {
            cout << "1. Add data to tree." << endl
                 << "2. Traverse Post-Order." << endl
                 << "3. Traverse In-Order" << endl
                 << "4. Traverse Pre-Order" << endl
                 << "5. Exit" << endl;

            cout << endl
                 << "Select option : ";
            cin >> option;

            switch (option)
            {
            case 1:
                cout << "Enter the data to insert in BST : ";
                cin >> data;
                t.addDataToTree(data, root);
                break;

            case 2:
                t.printPostorder(root);
                cout << endl;
                break;

            case 3:
                t.printInorder(root);
                cout << endl;
                break;

            case 4:
                t.printPreorder(root);
                cout << endl;
                break;

            case 5:
                exit(0);
                break;

            default:
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Tree t = Tree();
    driver(t);
    return 0;
}