#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QtCore/QDateTime>

class BinaryTree
{
public:

    QStringList traversal;

    struct TreeNode
    {
        QString data;
        QString date;
        struct TreeNode *left;
        struct TreeNode *right;
    };

    TreeNode *root;

    BinaryTree();

    void insertNode(QString, QString);
    void remove(QString);
    void deleteNode(QString, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void showNodeInOrder(void);
    void showNodeInReverseOrder(void);
    void displayInOrder(TreeNode *);
    void reverseInOrder(TreeNode *);
    bool searchNode(QString);
    QStringList returnTraversal(void);

};

#endif // BINARYTREE_H
