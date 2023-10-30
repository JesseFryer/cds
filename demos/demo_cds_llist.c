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
    for (int i = 0; i < 100; i++) {
        cds_llist_push(&ints, &i);
    }

    // now lets remove some
    int toRemove1 = 10;
    int toRemove2 = 45;
    int toRemove3 = -10;
    // the first two are in the list, so we need to free the data returned
    free(cds_llist_remove(&ints, &toRemove1));
    free(cds_llist_remove(&ints, &toRemove2)); 
    // this returns NULL
    cds_llist_remove(&ints, &toRemove3); 

    // print out all the elements
    cdsLNode* curr = ints.head;
    while (curr) {
        // using void to value function (vtvi) from cds_utils to cast and 
        // dereference the void pointer curr->data to an int
        printf("element: %d\n", cds_vtvi(curr->data));
        curr = curr->next;
    }

    // lets print the length of the list now
    printf("list size after adding 100 then removing 2 elements: %zu\n", 
            cds_llist_len(&ints));

    // if ints was a dynamically allocated pointer, we would also need to free
    // it, otherwise the rest is taken care of below
    cds_llist_destroy(&ints);

    return 0;
}
