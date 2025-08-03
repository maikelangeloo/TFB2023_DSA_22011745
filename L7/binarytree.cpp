
#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(string n)
    {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    void add_root(string name)
    {
        root = new Node(name);
    }

    void add_left(Node *parent, string name)
    {
        parent->left = new Node(name);
    }

    void add_right(Node *parent, string name)
    {
        parent->right = new Node(name);
    }

    void display(Node *node, int depth = 0)
    {
        if (!node)
            return;
        display(node->right, depth + 1);
        for (int i = 0; i < depth; i++)
            cout << "  ";
        cout << node->name << endl;
        display(node->left, depth + 1);
    }
};

int main()
{
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    tree.display(tree.root);

    return 0;
}