

#ifndef BITREE_H
#define BITREE_H

#ifdef VERBOSE
#include <stdio.h>
#endif

#include "StringList.h"

#ifndef NULL
#define NULL 0
#endif


typedef char elem_t;


/* Exercise A:
 * This is the node type for the tree
 * Here it is important to recognize the StringList declared in every node
 */
struct node_t
{
    elem_t data;
    
    node_t* pLeft;
    node_t* pRight;

    StringList mStringList;

    node_t()
    :   data(0),
        pLeft(NULL),
        pRight(NULL)
    {
    }

};


/* Exercise A:
 * This is the main datastructure to handle the tree management,
 * To manage the string lists in every key look at the StringList class
 * in StringList.cc
 */
class biTree_t
{
    node_t* m_pRoot;

    void    print_rek(node_t* pWalker);
    void    print_level_order();
    void    delete_rek(node_t* pWalker);
    node_t* getNode(node_t* pWalker, char key);

    public:
    
    biTree_t();
    ~biTree_t();

    

    bool insertIter(elem_t);
    void insert(char* pString);
    node_t* insertRek(elem_t v, node_t * pTreePart);
    void print();

    void insertString(char* pString);
    bool exists(char* pString);
    int count(char key);
};


struct qnode_t
{
    qnode_t* pNext;
    node_t* pData;
    
    qnode_t()
    :   pNext(NULL),
        pData(NULL)
    {
    }
};


class nodeQueue_t
{
    qnode_t* m_pHead;
    qnode_t* m_pTail;

    public:

    nodeQueue_t();
    //~nodeQueue_t();

    bool is_empty() {return (m_pHead == NULL);};
    
    bool enqueue(node_t* pN);
    node_t* dequeue();
};

#endif
