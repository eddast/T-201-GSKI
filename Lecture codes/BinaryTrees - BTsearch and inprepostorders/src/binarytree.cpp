#include "binarytree.h"

BinaryTree::BinaryTree()
{
    root = new TreeNode('a',
                        new TreeNode('b',
                                     new TreeNode('d', NULL, NULL),
                                     new TreeNode('e', NULL, NULL)),
                        new TreeNode('c',
                                     new TreeNode('f', NULL, NULL),
                                     new TreeNode('g', NULL, NULL)));
}

void BinaryTree::findoradd(char data)
{
    TreeNode* &node = root;
    TreeNode* &retnode = find(root, data, 0);

    if(retnode == NULL){
        cout << data << " not found" << endl;
        cout << data << " added consequently" << endl;
        retnode = new TreeNode(data, NULL, NULL);
    }
}

TreeNode* &BinaryTree::find(TreeNode* &node, char data, int depth)
{
    if(node == NULL){
        return node;
    }
    if(node->data == data){
        cout << data << " found at depth: " << depth << endl;
        return node;
    }
    TreeNode* &leftnode = find(node->left, data, depth + 1);
    if(leftnode != NULL){
        return leftnode;
    }
    else{
        return find(node->right, data, depth + 1);

    }
}

void BinaryTree::printPreorder(ostream& out, TreeNode* node) const
{
    if(node != NULL){
        out << node->data << " ";
        printPreorder(out, node->left);
        printPreorder(out, node->right);
    }
}

void BinaryTree::printPostorder(ostream& out, TreeNode* node) const
{
    if(node != NULL){
        printPostorder(out, node->left);
        printPostorder(out, node->right);
        out << node->data << " ";
    }
}

void BinaryTree::printInorder(ostream& out, TreeNode* node) const
{
    if(node != NULL){
        printInorder(out, node->left);
        out << node->data << " ";
        printInorder(out, node->right);
    }
}

ostream& operator<<(ostream& out, const BinaryTree& tree)
{
    out << "PreOrder:" << endl;
    tree.printPreorder(out, tree.root);
    out << endl;
    out << "InOrder:" << endl;
    tree.printInorder(out, tree.root);
    out << endl;
    out << "PostOrder:" << endl;
    tree.printPostorder(out, tree.root);
    return out;
}

BinaryTree::~BinaryTree()
{

}
