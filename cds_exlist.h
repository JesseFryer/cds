#ifndef CDS_EXLIST_H
#define CDS_EXLIST_H

/* cds_exlist.h
 *
 * A generic extensible list
 *
 * Written by Jesse Fryer
 */

#include <stdlib.h>

#define CDS_EL_INIT_CAP 4 // initial capacity for an extensible list

typedef struct cdsExList {
    void* data;
    size_t dataSize;
    size_t len;
    size_t capacity;
    int(*cmp)(void*, void*);
} cdsExList;

/* cds_exlist_init
 * ---------------
 * Initialise an extensible list. Must be called before any other function.
 *
 * list: pointer to a cdsExList
 * dataSize: size (in bytes) of data type to be stored in the list 
 * cmp: function pointer to a compare function for the data type being stored
 *      in the list. See cds_utils.h for basic type implementations or make
 *      your own if you're using a custom data type.
 */
void cds_exlist_init(cdsExList* list, size_t dataSize, int(*cmp)(void*, void*));

/* cds_exlist_push
 * ---------------
 * Insert an item to the back of the list.
 *
 * list: pointer to a cdsExList
 * data: pointer to data to add, casted as a void pointer
 */
void cds_exlist_push(cdsExList* list, void* data);

/* cds_exlist_pop
 * --------------
 * Remove and return the last element from the list
 *
 * list: pointer to a cdsExList
 *
 * return: data removed casted as a void pointer, NULL if the list was empty
 */
void* cds_exlist_pop(cdsExList* list);

/* cds_exlist_get
 * --------------
 * Return an element at index idx in a list
 *
 * list: pointer to a cdsExList
 * idx: index of element in the list
 *
 * return: the element at index idx in the list, NULL if out of bounds
 */
void* cds_exlist_get(cdsExList* list, size_t idx);

/* cds_exlist_destroy
 * ------------------
 * Free underlying array used by list. This will not free dynamically allocated
 * member variables of custom datatypes, a custom destructor will need to be
 * implemented in that case.
 *
 * list: pointer to a cdsExList
 */
void cds_exlist_destroy(cdsExList* list);

#endif
