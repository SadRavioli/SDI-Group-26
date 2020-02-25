#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

struct node
{
    int data;
    node *next;
};

class LinkedList
{
private:
    double data;
    node* next;
    node* head;

public:
    LinkedList(void);
    ~LinkedList(void);
    void InsertionSort(struct node**);
    void SortedInsert(struct node**, struct node*);
    node* InsertNode(int index, double x);
    int FindNode(double x);
    int DeleteNode(double x);

};

#endif // LINKEDLIST_H
