/* cds_llist.h
 *
 * A generic linked list 
 *
 * written by Jesse Fryer
 */

#ifndef CDS_LLIST_H
#define CDS_LLIST_H

#include <stdlib.h>

typedef struct cdsLNode {
    void* data;
    struct cdsLNode* next;
} cdsLNode;

typedef struct cdsLList {
    cdsLNode* head;
    cdsLNode* tail;
    size_t len;
    size_t dataSize;
    int(*cmp)(void*, void*);
} cdsLList;

/* cds_llist_init
 * --------------
 * Initialise a linked list. Must be called before any other function.
 *
 * list: pointer to a cdsLList
 * dataSize: size (in bytes) of data type to be stored in the list 
 * cmp: function pointer to a compare function for the data type being stored
 *      in the list. See cds_utils.h for basic type implementations or make
 *      your own if you're using a custom data type.
 */
void cds_llist_init(cdsLList* list, size_t dataSize, int(*cmp)(void*, void*));

/* cds_llist_destroy
 * -----------------
 * Free memory used by a cdsLList. If list points to dynamically allocated
 * memory, the user is responsible for calling free on it. This is a default
 * destructor, if you are using a custom datatype with dynamically allocated
 * member variables, this destructor will not free those members. You will 
 * need to make your own custom destructor.
 *
 * list: pointer to a cdsLList
 */
void cds_llist_destroy(cdsLList* list);

/* cds_llist_push
 * --------------
 * Push data to the end of the list. Assumes data is of size
 * list->dataSize which must be set in cds_llist_init.
 *
 * list: pointer to a cdsLList
 * data: data to add to list
 */
void cds_llist_push(cdsLList* list, void* data);

/* cds_llist_remove
 * ----------------
 * Remove node identified by its data. The user is responsible for calling 
 * free on the data returned (if return is not NULL).
 *
 * list: pointer to a cdsLList
 * data: identifying data to remove
 *
 * return: data removed as a void pointer, NULL if data was not found
 */
void* cds_llist_remove(cdsLList* list, void* data);

/* cds_llist_len
 * -------------
 * Get the length of a list.
 *
 * return: number of elements in the list
 */
size_t cds_llist_len(cdsLList* list);

#endif
