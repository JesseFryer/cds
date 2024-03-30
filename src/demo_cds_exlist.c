#include <stdio.h>
#include "cds_utils.h"
#include "cds_exlist.h"

int main(int argc, char* argv[]) {
    // make a list
    cdsExList* ints = cds_exlist_create(sizeof(int), cds_cmpi);

    // add some integers to our list.
    printf("adding 20 elements...\n");
    for (int i = 0; i < 20; i++) {
        cds_exlist_push(ints, &i);
    }

    // print the values
    for (int i = 0; i < 20; i++) {
        printf("%d ", cds_vtvi(cds_exlist_get(ints, i)));
    }

    // pop 10 elements
    printf("\n\nremoving 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", cds_vtvi(cds_exlist_pop(ints)));
    }

    // print the values again
    printf("\n\nelements after adding 20 and removing 10\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", cds_vtvi(cds_exlist_get(ints, i)));
    }

    // push and pop 10
    printf("\n\npopping and pushing 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        void* popped = cds_exlist_pop(ints);
        printf("popped: %d\n", cds_vtvi(popped));
        free(popped);
        cds_exlist_push(ints, &i);
    }

    // Insert an element.
    int tmp = 40;
    cds_exlist_insert(ints, &tmp, 4);
    tmp = 27;
    cds_exlist_insert(ints, &tmp, 2);

    // Sort the list
    cds_exlist_sort(ints);

    // print the values again
    printf("\n\nelements after adding 20 and removing 10\n");
    for (int i = 0; i < cds_exlist_len(ints); i++) {
        printf("%d ", cds_vtvi(cds_exlist_get(ints, i)));
    }

    // see the len and capacity
    printf("\n\nlen: %zu capacity: %zu\n", 
            cds_exlist_len(ints), cds_exlist_capacity(ints));

    cds_exlist_destroy(ints);

    return 0;
}
