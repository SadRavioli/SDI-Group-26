#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

/**
 * @brief Defines a node to be used.
 *
 */
struct node
{
    QString data; /**< Where information in node is stored. */
    node *next; /**< Pointer to the next node. */
};

/**
 * @brief Defines the linked list class. Can be used to insert, remove, and find items by index or find the index of an item.
 *
 */
class LinkedList
{
private:
    QString data; /**< Stores information. */
    node* next; /**< Pointer to next node. */
    node* head; /**< Pointer to head. */

public:
    /**
     * @brief Constructor for Linked List.
     *
     */
    LinkedList(void);
    /**
     * @brief Destructor for Linked List.
     *
     */
    ~LinkedList(void);
    /**
     * @brief Function to sort the Linked List by means of insertion sort.
     *
     * @param node**
     */
    void InsertionSort(struct node**);
    /**
     * @brief Function to insert newly sorted node.
     *
     * @param node**
     * @param node*
     */
    void SortedInsert(struct node**, struct node*);
    /**
     * @brief Function to insert node into Linked List.
     *
     * @param index
     * @param x
     * @return node
     */
    node* InsertNode(int index, QString x);
    /**
     * @brief Finds node that contains x and returns index of said node.
     *
     * @param x
     * @return int
     */
    int FindNode(QString x);
    /**
    * @brief Retrieves item from node with index x
    *
    * @param index
    * @return data
    */
    QString FindItem(int index);
    /**
     * @brief 
     *
     * @param x
     * @return int
     */
    int DeleteNode(QString x);

};

#endif // LINKEDLIST_H
