#pragma once

/* cds_llist.h
 *
 * A generic linked list 
 *
 * written by Jesse Fryer
 */

#include "cds_utils.h"

typedef struct cdsLNode {
    void*            data;
    struct cdsLNode* next;
    struct cdsLNode* prev;
} cdsLNode;

typedef struct {
    cdsLNode* head;
    cdsLNode* tail;
    size_t    len;
    size_t    dataSize;
    cdsCmp    cmp;
} cdsLList;

/* cds_llist_init
 * --------------
 * Create a new linked list.
 *
 * dataSize: size (in bytes) of data type to be stored in the list 
 * cmp: function pointer to a compare function for the data type being stored
 *      in the list. See cds_utils.h for basic type implementations or make
 *      your own if you're using a custom data type.
 */
cdsLList* cds_llist_create(size_t dataSize, cdsCmp cmp);

/* cds_llist_destroy
 * -----------------
 * If you are using a custom datatype with dynamically allocated
 * member variables, this destructor will not free those members. You will 
 * need to make your own custom destructor.
 *
 * list: pointer to a cdsLList
 */
void cds_llist_destroy(cdsLList* list);

/* cds_llist_push
 * --------------
 * Push an element to the end of the list.
 *
 * list: pointer to a cdsLList
 * data: data to add to list
 */
void cds_llist_push(cdsLList* list, void* data);

/* cds_llist_pop_front
 * -------------------
 * Remove and return the first element in the list, NULL if empty.
 */
void* cds_llist_pop_front(cdsLList* list);

/* cds_llist_pop_back
 * -------------------
 * Remove and return the last element in the list, NULL if empty.
 */
void* cds_llist_pop_back(cdsLList* list);

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
