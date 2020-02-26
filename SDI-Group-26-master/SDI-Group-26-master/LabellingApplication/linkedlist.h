#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

/**
 * @brief
 *
 */
struct node
{
    int data; /**< TODO: describe */
    node *next; /**< TODO: describe */
};

/**
 * @brief
 *
 */
class LinkedList
{
private:
    double data; /**< TODO: describe */
    node* next; /**< TODO: describe */
    node* head; /**< TODO: describe */

public:
    /**
     * @brief
     *
     */
    LinkedList(void);
    /**
     * @brief
     *
     */
    ~LinkedList(void);
    /**
     * @brief
     *
     * @param
     */
    void InsertionSort(struct node**);
    /**
     * @brief
     *
     * @param
     * @param
     */
    void SortedInsert(struct node**, struct node*);
    /**
     * @brief
     *
     * @param index
     * @param x
     * @return node
     */
    node* InsertNode(int index, double x);
    /**
     * @brief
     *
     * @param x
     * @return int
     */
    int FindNode(double x);
    /**
     * @brief
     *
     * @param x
     * @return int
     */
    int DeleteNode(double x);

};

#endif // LINKEDLIST_H
