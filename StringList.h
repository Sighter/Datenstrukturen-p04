
/* sList.h
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2011-06-16.
 * @Editor:      Vim
 */

#ifndef SLIST_H
#define SLIST_H

#ifndef NULL
#define NULL 0
#endif

//#define VERBOSE

#ifdef VERBOSE 
#include <stdio.h>
#endif


/* this is the node struct for the stringlist */
struct Node
{
    char* pString;
    Node* pNext;

    Node()
    :   pString(NULL),
        pNext(NULL)
    {
    }
};
    

/* class for managing strings in a list */
class StringList
{
    Node* mpHead;
    Node* mpTail;

    int mLen;

    public:

    StringList();
    ~StringList();
    
    void print();
    void append(char* pString);
    bool stringExists(char* pString);
    
    int len();
};

#endif
