/* cds_exlist.c
 *
 * Written by Jesse Fryer
 */

#include <string.h>
#include "cds_exlist.h"

void cds_exlist_init(
        cdsExList* list, 
        size_t dataSize,
        int(*cmp)(void*, void*)) {
    list->capacity = CDS_EL_INIT_CAP;
    list->len = 0;
    list->dataSize = dataSize;
    list->cmp = cmp;
    list->data = malloc(list->capacity * dataSize);
}

void cds_exlist_push(cdsExList* list, void* data) {
    // resize if necessary
    if (list->len == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * list->dataSize);
    }
    // copy bytes from data to next position in the list
    void* dest = ((char*) list->data) + (list->len * list->dataSize);
    memcpy(dest, data, list->dataSize);
    list->len++;
}

void* cds_exlist_pop(cdsExList* list) {
    if (!list->len) {
        return NULL;
    }
    void* removed = ((char*) list->data) + ((list->len - 1) * list->dataSize);
    list->len--;
    return removed;
}

void* cds_exlist_get(cdsExList* list, size_t idx) {
    if (idx >= list->len || idx < 0) {
        return NULL;
    }
    return ((char*) list->data) + (idx * list->dataSize);
}

void cds_exlist_destroy(cdsExList* list) {
    free(list->data);
}
