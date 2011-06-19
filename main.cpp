

#include "biTree.h"
#include "StringList.h"


int main()
{
    /* Hint 4:
     * Since all c-string allocation is done in the main program
     * we do not need any limits */
    char word1[] = "Knüppel";
    char word2[] = "Baum";
    char word3[] = "Masche";
    char word4[] = "Kreuz";
    char word5[] = "XXX";
    char word6[] = "Arabisch";
    char word7[] = "Ball";
    char word8[] = "Alaun";

    biTree_t t;
    t.insert(word1);
    t.insert(word2);
    t.insert(word3);
    t.insert(word4);
    t.insert(word5);
    t.insert(word6);
    t.insert(word7);
    t.insert(word8);

    t.print();

#ifdef VERBOSE
    char checked_key1 = 'B';
    char checked_key2 = 'X';
    
    char searched_string1[] = "Alaun";
    char searched_string2[] = "nix";

    printf("Stringcount in key %c: %d\n", checked_key1, t.count(checked_key1));
    printf("Stringcount in key %c: %d\n", checked_key2, t.count(checked_key2));
    
    printf("String %s is in tree: %d\n", searched_string1, t.exists(searched_string1));
    printf("String %s is in tree: %d\n", searched_string2, t.exists(searched_string2));

#endif


    StringList sl;
    

    sl.append(word1);
    sl.append(word2);
    sl.append(word3);

    sl.print();
    
    
}
