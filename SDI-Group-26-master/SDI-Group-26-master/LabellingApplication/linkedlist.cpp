#include "linkedlist.h"
#include <iostream>




LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::InsertionSort(struct node **head_ref)
{
    // Initialize sorted linked list
    struct node *sorted = NULL;

    // Traverse the given linked list and insert every
    // node to sorted
    struct node *current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration
        struct node *next = current->next;

        // insert current in sorted linked list
        SortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted linked list
    *head_ref = sorted;
}

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void LinkedList::SortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

node* LinkedList::InsertNode(int index, double x)
{

    if (index < 0) return NULL;

        int currIndex = 1;
        node* currNode = head;
        while (currNode && index > currIndex) {
            currNode = currNode->next;
            currIndex++;
        }
        if (index > 0 && currNode == NULL) return NULL;

        node* newNode = new node;
        newNode->data = x;
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        return newNode;

}

int LinkedList::DeleteNode(double x) {
    node* prevNode = NULL;
    node* currNode = head;
    int currIndex = 1;
    while (currNode && currNode->data != x) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode) {
        if (prevNode) {
            prevNode->next = currNode->next;
            delete currNode;
        }
        else {
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }
    return 0;
}

int LinkedList::FindNode(double x) {
    node* currNode = head;
    int currIndex =	1;
    while (currNode && currNode->data != x) {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode) return currIndex;
    return 0;
}

LinkedList::~LinkedList(void) {
   node* currNode = head, *nextNode = NULL;
   while (currNode != NULL)
   {
    nextNode	=	currNode->next;
    // destroy the current node
    delete currNode;
    currNode	=	nextNode;
   }
}

