/* demo_cds_llist.c
 *
 * A little demo for how to use cds_llist in conjuction with cds_utils.
 *
 * Written by Jesse Fryer
 */

#include <stdio.h>
#include <cds_llist.h>
#include <cds_utils.h>

int main(int argc, char* argv[]) {
    // initialise a list of integers
    cdsLList ints;

    // must call the init function, we need to pass it the size of the datatype
    // we will be storing in the list and a cmp function. In this case since 
    // we're using a basic datatype we can use the integer compare function
    // (one of many defined in cds_utils.h)
    cds_llist_init(&ints, sizeof(int), cds_cmpi);

    // lets add some integers to our list
    printf("adding 20 elements...\n");
    for (int i = 0; i < 20; i++) {
        cds_llist_push(&ints, &i);
    }

    // print out all the elements
    cdsLNode* curr = ints.head;
    while (curr) {
        printf("%d ", cds_vtvi(curr->data));
        curr = curr->next;
    }

    // lets remove 10 elements
    printf("\n\nremoving 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        void* dataRemoved = cds_llist_remove(&ints, &i);
        // using void to value function (vtvi) from cds_utils to cast and 
        // dereference the void pointer curr->data to an int
        int removed = cds_vtvi(dataRemoved);
        free(dataRemoved);
        printf("%d ", removed);
    }

    // print out all the elements
    printf("\n\nelements after adding 20 and removing 10...\n");
    curr = ints.head;
    while (curr) {
        printf("%d ", cds_vtvi(curr->data));
        curr = curr->next;
    }

    // lets see the len
    printf("\n\nlen: %zu\n", ints.len);

    cds_llist_destroy(&ints);

    return 0;
}
