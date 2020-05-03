#include "binarytree.h"

//Constructor, initialises
BinaryTree::BinaryTree()
{
    //Creates root
    TreeNode *root;
}


void BinaryTree::insertNode(QString string, QString dateTime)
{
    //Pointer to newNode and nodePtr
    TreeNode *newNode, *nodePtr;
    
    //newNode initialised
    newNode = new TreeNode;
    //Add date
    newNode->data = string;
    newNode->date = dateTime;
    //Add null child nodes
    newNode->left = newNode->right = NULL;
    
    //If no root the newNode becomes the root
    //Otherwise nodePtr takes root value
    if (!root)
        root = newNode;
    else
    {
        nodePtr = root;
    }
    //While nodePtr exists
    while (nodePtr != NULL)
    {
        //if string < current node data
        if (string < nodePtr->data)
        {
            //if current node has a left child node
            //Sets current node to the left child node
            if (nodePtr->left)
                nodePtr = nodePtr->left;
            //Otherwise sets the left child to newNode and breaks
            else
            {
                nodePtr->left = newNode;
                break;
            }
        }
        //Otherwise if string is > etc
        else if (string > nodePtr->data)
        {
            if (nodePtr->right)
                nodePtr = nodePtr->right;
            else
            {
                nodePtr->right = newNode;
                break;
            }
        }
        //Otherwise breaks
        else
        {
            break;
        }
    }
}

void BinaryTree::remove(QString string)
{
    //Calls deleteNode with string and tree root
    deleteNode(string, root);
}

void BinaryTree::deleteNode(QString string, TreeNode *&nodePtr)
{
    //if string < current node data
    //calls deleteNode for left child node
    if (string < nodePtr->data)
        deleteNode(string, nodePtr->left);
    //else deleteNode for right child node
    else if (string > nodePtr->data)
        deleteNode(string, nodePtr->right);
    //Otherwise calls makeDeletion for node
    else
        makeDeletion(nodePtr);
}

void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    //creates temporary nodePtr
    TreeNode *tempNodePtr;
    
    //Output message if node is empty
    if (nodePtr == NULL)
        QMessageBox::information(0,"Error","Cannot delete empty node.\n");
    
    //if right child node null      
    else if (nodePtr->right == NULL)
    {
        //nodePtr assigned to temp node
        tempNodePtr = nodePtr;
        //left child node made current node
        nodePtr = nodePtr->left;
        //delete temp node
        delete tempNodePtr;
    }
    //opposite for left child node
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //otherwise
    else
    {
        //right child node assigned to temp node
        tempNodePtr = nodePtr->right;
        //while left child node of temp node exists
        while (tempNodePtr->left)
            //temp node left child becomes new temp node
            tempNodePtr = tempNodePtr->left;
        //current left child node assigned to temp left child node
        tempNodePtr->left = nodePtr->left;
        //current node assigned to temp node
        tempNodePtr = nodePtr;
        //right child node becomes new current node
        nodePtr = nodePtr->right;
        //deletes temp node
        delete tempNodePtr;
    }
}

void BinaryTree::showNodeInOrder(void)
{
    //clears traversal list
    traversal.clear();
    //calls displayInOrder function using root
    displayInOrder(root);
}

void BinaryTree::showNodeInReverseOrder(void)
{
    //clears traversal list
    traversal.clear();
    //calls reverseInOrder function using root
    reverseInOrder(root);
}

void BinaryTree::displayInOrder(TreeNode *nodePtr)
{
    //if current node exists
    if (nodePtr)
    {
        //calls function with current nodes left child
        displayInOrder(nodePtr->left);
        //appends current nodes data to traversal list
        traversal.append(nodePtr->data);
        //calls function with current nodes right child
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::reverseInOrder(TreeNode *nodePtr)
{
    //if current node exists
    if (nodePtr)
    {
        //calls function with current nodes right child
        reverseInOrder(nodePtr->right);
        //appends current nodes data to traversal list
        traversal.append(nodePtr->data);
        //calls function with current nodes left child
        reverseInOrder(nodePtr->left);

    }
}

bool BinaryTree::searchNode(QString string)
{
    //points to root as current node
    TreeNode *nodePtr = root;
    //while current node exists
    while (nodePtr)
    {
        //current node contains data returns true
        if (nodePtr->data == string)
            return true;
        //if less will move to left child node
        else if (string < nodePtr->data)
            nodePtr = nodePtr->left;
        //else will move to right child node
        else
            nodePtr = nodePtr->right;
    }
}

QStringList BinaryTree::returnTraversal(void)
{
    //returns traversal list
    return traversal;
}

