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
    int (*cmp)(void*, void*);
} cdsLList;

/* cds_llist_init()
 * ----------------
 * Initialise a linked list. Must be called before any other function.
 *
 * list: pointer to a cdsLList
 * dataSize: size of data type in bytes to be stored in the list 
 */
void cds_llist_init(cdsLList* list, size_t dataSize);

/* cds_llist_destroy()
 * -------------------
 * Free memory used by a cdsLList.
 *
 * list: pointer to a cdsLList
 */
void cds_llist_destroy(cdsLList* list);

/* cds_llist_push()
 * ----------------
 * Push data to the end of the list. Assumes data is of size
 * dataSize which must be set in cds_llist_init.
 *
 * list: pointer to a cdsLList
 * data: generic data type to add to list
 * size: size of data type in bytes to be stored in the list 
 */
void cds_llist_push(cdsLList* list, void* data);

/* cds_llist_remove()
 * Remove node identified by its data. cmp must be implemented
 *
 * list: pointer to a cdsLList
 * data: identifying data to Remove
 *
 * returns: data removed as a void pointer, NULL if data was not found
 */
void* cds_llist_remove(cdsLList* list, void* data);

#endif
