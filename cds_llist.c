#include "cds_llist.h"

void cds_llist_init(cdsLList* list, size_t dataSize, int(*cmp)(void*, void*)) {
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    list->dataSize = dataSize;
    list->cmp = cmp;
}

void cds_llist_destroy(cdsLList* list) {
    cdsLNode* curr = list->head;
    while (curr) {
        cdsLNode* tmp = curr;
        curr = curr->next;
        free(tmp->data);
        free(tmp);
    }
}

void cds_llist_push(cdsLList* list, void* data) {
    cdsLNode* newNode = (cdsLNode*)  malloc(sizeof(cdsLNode));
    newNode->next = NULL;
    newNode->data = malloc(list->dataSize);
    // copy bytes into newNode->data
    for (int offset = 0; offset < list->dataSize; offset++) { 
        *(((char*) newNode->data) + offset) = *(((char*) data) + offset);
    }

    if (list->len) {
        list->tail->next = newNode;
        list->tail = newNode;
    } else {
        list->head = newNode;
        list->tail = newNode;
    }

    list->len++;
}

void* cds_llist_remove(cdsLList* list, void* data) {
    cdsLNode* curr = list->head;
    cdsLNode* prev = curr;
    while (curr) {
        if (!list->cmp(data, curr->data)) {
            prev->next = curr->next;
            void* removed = curr->data;
            free(curr);
            list->len--;
            return removed;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

size_t cds_llist_len(cdsLList* list) {
    size_t len = list->len; // so we can't accidently overwrite
    return len;
}
