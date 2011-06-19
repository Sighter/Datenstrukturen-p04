
#include "biTree.h"


/* constructor for the queue */
nodeQueue_t::nodeQueue_t()
:   m_pHead(NULL),
    m_pTail(NULL)
{
}


/* enqueue a node_t* pointer */
bool nodeQueue_t::enqueue(node_t* pN)
{
    qnode_t* pOldTail = m_pTail;
    m_pTail = new qnode_t;
    if (m_pTail == NULL)
        return false;

    m_pTail->pData = pN;
    
    if (m_pHead == NULL)
        m_pHead = m_pTail;
    else
        pOldTail->pNext = m_pTail;

    return true;
}


/* dequeue a node_t* pointer */
node_t* nodeQueue_t::dequeue()
{
    if (m_pHead == NULL)
        return NULL;
    else
    {
        node_t* pRet = m_pHead->pData;
        qnode_t* pDel = m_pHead;
        
        m_pHead = m_pHead->pNext;

        delete pDel;
        return pRet;
    }
}
        
        
/* constructor for the binary tree
 */
biTree_t::biTree_t()
:   m_pRoot(NULL)
{
}


/* rec function for deletion
 *
 * this method is called by the destructor to use
 * recusion
 *
 * @param a node_t pointer to traverse the tree
 */
void biTree_t::delete_rek(node_t* pWalker)
{
    if (pWalker != NULL)
    {
        delete_rek(pWalker->pLeft);
        delete_rek(pWalker->pRight);
        delete pWalker;
    }
}


/* destructor for the binary tree, we need post order traversal
 */
biTree_t::~biTree_t()
{
    delete_rek(m_pRoot);
}


/* Exercise D:
 * this method inserts a string in the binary tree
 *
 * This is the caller for the recursive insert function.
 * The method first inserts the first character of the given string
 * in the tree. After that it uses the returned pointer to append
 * the given string to StringList by means of the append method.
 * 
 * @param the string
 */
void biTree_t::insert(char* pString)
{
    node_t* inserted_node = insertRek(pString[0], m_pRoot);
    
    inserted_node->mStringList.append(pString);
}


/* this inserts a given element in the tree. This is done
 * in a sorted way. Method is recursive
 *
 * @param value to be inserted
 * @param node_t pointer for the tree part
 *
 * @return pointer to the inserted or found node
 */
node_t* biTree_t::insertRek(elem_t v, node_t* pTreePart)
{
    node_t* p_temp;
    if (pTreePart != NULL)
    {
        /* Hint 1:
         * As we see in this condition, the method returns if 
         * the key which should be insered is still in the tree.
         *
         * So it is not possible that keys appears twice in the tree.
         */
        if (pTreePart->data == v)
            return pTreePart;
        
        if (v < pTreePart->data)
        {
            if (pTreePart->pLeft != NULL)
                return insertRek(v, pTreePart->pLeft);
            else
            {
                pTreePart->pLeft = new node_t;
                p_temp = pTreePart->pLeft;
            }
        }
        else
        {
            if (pTreePart->pRight != NULL)
                return insertRek(v, pTreePart->pRight);
            else
            {
                pTreePart->pRight = new node_t;
                p_temp = pTreePart->pRight;
            }
        }
    }
    else
    {
        /* case where root was NULL */
        p_temp = new node_t;
        m_pRoot = p_temp;
    }
    
    /* insert the given value */
    p_temp->data = v;
    return p_temp;
}


/* search for a key
 * 
 * @param a tree node (for recursion)
 * @param a key to search
 *
 * @return a node pointer or NULL
 */
node_t* biTree_t::getNode(node_t *pWalker, char key)
{
    if (pWalker != NULL)
    {
        if (pWalker->data == key)
            return pWalker;
        else if(key < pWalker->data)
            return getNode(pWalker->pLeft, key);
        else
            return getNode(pWalker->pRight, key);
    }
    else
        return NULL;
}
    

/* Exercise C:
 * count the words for a given tree key
 *
 * This method first looks for the given key. If it is not
 * found it returns 0. Otherwise the method calls the len()
 * method of the StringList.
 * 
 * The len() method simply returns the len member of the StringList
 * instance. The len member is changed then inserting a string to
 * the StringList.
 *
 * @param the key
 *
 * @return the count of strings for a given key
 */
int biTree_t::count(char key)
{
    node_t* p_temp = getNode(m_pRoot, key);

    if (p_temp == NULL)
        return 0;
    else
        return p_temp->mStringList.len();
}


/* Exercise B:
 * this method reports the existance of a given string
 * in the tree
 *
 * it simply calls the getNode method and uses the returned
 * pointer to search the string in the corresponding StringList
 *
 * @param the string
 *
 * @return true if string is found in the tree otherwise false
 */
bool biTree_t::exists(char *pString)
{
    /* look for the key */
    node_t* p_temp = getNode(m_pRoot, pString[0]);
    
    if (p_temp == NULL)
        return false;
    else
        return p_temp->mStringList.stringExists(pString);
}


/* rec function for printing */
void biTree_t::print_rek(node_t* pWalker)
{
#ifdef VERBOSE
    if (pWalker != NULL)
    {
        printf("%c |", pWalker->data);
        print_rek(pWalker->pLeft);
        print_rek(pWalker->pRight);
    }
#endif
}


/* print tree in level order */
void biTree_t::print_level_order()
{
#ifdef VERBOSE
    if (m_pRoot == NULL)
        return;

    nodeQueue_t q;
    q.enqueue(m_pRoot);

    int iNodesCurrentLevel = 1;
    int iNodesNextLevel = 0;
    
    while (q.is_empty() != true)
    {
        node_t* pTemp = q.dequeue();
        
        printf("| %c ", pTemp->data);
        pTemp->mStringList.print();

        iNodesCurrentLevel--;

        if (pTemp->pLeft != NULL)
        {
            q.enqueue(pTemp->pLeft);
            iNodesNextLevel++;
        }

        if (pTemp->pRight != NULL)
        {
            q.enqueue(pTemp->pRight);
            iNodesNextLevel++;
        }

        if (iNodesCurrentLevel == 0)
        {
            printf("|\n");
            iNodesCurrentLevel = iNodesNextLevel;
            iNodesNextLevel = 0;
        }
    }
#endif
}


/* print */
void biTree_t::print()
{
#ifdef VERBOSE
    print_level_order();
    printf("\n");
#endif
}
    
    
