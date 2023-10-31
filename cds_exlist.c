/* cds_exlist.c
 *
 * Written by Jesse Fryer
 */

#include "cds_exlist.h"

void _cds_exlist_resize(cdsExList* list) {
    list->capacity *= 2;
    list->data = realloc(list->data, list->capacity * list->dataSize);
}

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
    if (list->len == list->capacity) {
        _cds_exlist_resize(list);
    }
    char* startPtr = ((char*) list->data) + (list->len * list->dataSize);
    for (int offset = 0; offset < list->dataSize; offset++) { 
        *(startPtr + offset) = *(((char*) data) + offset);
    }
    list->len++;
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

