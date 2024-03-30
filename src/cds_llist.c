#include "cds_llist.h"

#include <string.h>

cdsLList* cds_llist_create(size_t dataSize, cdsCmp cmp) {
    cdsLList* list = (cdsLList*) malloc(sizeof(cdsLList));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    list->dataSize = dataSize;
    list->cmp = cmp;
    return list;
}

void cds_llist_destroy(cdsLList* list) {
    cdsLNode* curr = list->head;
    while (curr) {
        cdsLNode* tmp = curr;
        curr = curr->next;
        free(tmp->data);
        free(tmp);
    }
    free(list);
}

void cds_llist_push(cdsLList* list, void* data) {
    cdsLNode* newNode = (cdsLNode*) malloc(sizeof(cdsLNode));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = malloc(list->dataSize);

    memcpy(newNode->data, data, list->dataSize);

    if (list->len) {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    } else {
        list->head = newNode;
        list->tail = newNode;
    }

    list->len++;
}

void* cds_llist_pop_front(cdsLList* list) {
    if (!list->len) {
        return NULL;
    }
    void* removed = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->len--;
    return removed;
}

void* cds_llist_pop_back(cdsLList* list) {
    if (!list->len) {
        return NULL;
    }
    void* removed = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->len--;
    return removed;
}

void* cds_llist_remove(cdsLList* list, void* data) {
    cdsLNode* curr = list->head;
    cdsLNode* prev = curr;
    size_t count = 0;
    while (curr) {
        if (!list->cmp(data, curr->data)) {
            if (count) {
                prev->next = curr->next;
            } else {
                list->head = curr->next;
            }
            void* removed = curr->data;
            list->len--;
            free(curr);
            return removed;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
    return NULL;
}

size_t cds_llist_len(cdsLList* list) {
    return list->len; 
}
