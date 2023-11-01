#include <stdio.h>
#include <cds_exlist.h>
#include <cds_utils.h>

int main(int argc, char* argv[]) {
    // lets make a list!
    cdsExList ints;

    // must call the init function, we need to pass it the size of the datatype
    // we will be storing in the list and a cmp function. In this case since 
    // we're using a basic datatype we can use the integer compare function
    // (one of many defined in cds_utils.h)
    cds_exlist_init(&ints, sizeof(int), cds_cmpi);

    // lets add some integers to our list
    printf("adding 20 elements...\n");
    for (int i = 0; i < 20; i++) {
        cds_exlist_push(&ints, &i);
    }

    // lets print the values
    for (int i = 0; i < 20; i++) {
        printf("%d ", cds_vtvi(cds_exlist_get(&ints, i)));
    }

    // lets pop 10 elements
    printf("\n\nremoving 10 elements...\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", cds_vtvi(cds_exlist_pop(&ints)));
    }

    // lets print the values again
    printf("\n\nelements after adding 20 and removing 10\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", cds_vtvi(cds_exlist_get(&ints, i)));
    }

    // lets see the len and capacity
    printf("\n\nlen: %zu capacity: %zu\n", ints.len, ints.capacity);

    cds_exlist_destroy(&ints);

    return 0;
}
