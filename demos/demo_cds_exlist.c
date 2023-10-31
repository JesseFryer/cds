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
    for (int i = 0; i < 100; i++) {
        cds_exlist_push(&ints, &i);
    }

    // lets print the values
    for (int i = 0; i < 100; i++) {
        printf("%d\n", cds_vtvi(cds_exlist_get(&ints, i)));
    }

    return 0;
}
