
/* StringList.cc<++>
 * @Author:      The Sighter (sighter@resource-dnb.de)
 * @License:     GPL
 * @Created:     2011-06-16.
 * @Editor:      Vim
 */

#include "StringList.h"


/////////////////////////////// PUBLIC ///////////////////////////////////////

/*============================= LIFECYCLE ==================================*/

/* constructor */
StringList::StringList()
:   mpHead(NULL),
    mpTail(NULL),
    mLen(0)
{
}

/* destructor */
StringList::~StringList()
{
    Node* p_walker = mpHead;
    while (p_walker != NULL)
    {
        Node* p_del = p_walker;
        p_walker = p_walker->pNext;
        delete p_del;
    }
}

/*============================= OPERATORS ==================================*/

/*============================= OPERATIONS =================================*/

/* append a string to a stringlist */
void StringList::append(char *pString)
{
    if (mpHead == NULL)
    {
        mpHead = new Node;
        mpHead->pString = pString;
        mpTail = mpHead;
        mLen++;
        return;
    }
    
    mpTail->pNext = new Node;
    mpTail->pNext->pString = pString;
    mpTail = mpTail->pNext;
    mLen++;

    return;
}

/* simple print function */
void StringList::print()
{
#ifdef VERBOSE
    Node* p_walker = mpHead;
    printf("SL: ");
    
    while (p_walker != NULL)
    {
        printf("%s, ", p_walker->pString);
        p_walker = p_walker->pNext;
    }
#endif
}

/*============================= ACESS      =================================*/

/* return the lenqth */
int StringList::len() {return mLen;}

/*============================= INQUIRY    =================================*/

/* This method checks for precence of a string in the list
 *
 * @param the searched String
 *
 * @return on success true otherwise false
 */
bool StringList::stringExists(char *pString)
{
    Node* p_walker = mpHead;

    while (p_walker != NULL)
    {
        int i = 0;

        while (p_walker->pString[i] == pString[i])
        {
            /* if we find the end the strings a equal*/
            if (p_walker->pString[i] == '\0')
                return true;
            
            i++;
        }
        
        /* string on current list position doesnt match */
        p_walker = p_walker->pNext;
    }
    return false;
}

/////////////////////////////// PROTECTED  ///////////////////////////////////
/////////////////////////////// PRIVATE    ///////////////////////////////////
