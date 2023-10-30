#ifndef CDS_UTILS_H
#define CDS_UTILS_H

/* cds_cmp()
 * ---------
 * Compare two generic data types. This is a dummy function meant to be 
 * overriden by the user in various data structures for sorting and other 
 * functionality. Below are some predefined functions for basic data types. 
 * Any custom data types will need their own function created by the user.
 *
 * return:
 *      1 if 1st > 2nd
 *     -1 if 1st < 2nd
 *      0 if 1st = 2nd
 */
int cds_cmp(void*, void*);

// cmp functions for basic types
int cds_cmpc(void*, void*); // compare chars
int cds_cmpi(void*, void*); // compare int
int cds_cmpu(void*, void*); // compare unsigned int
int cds_cmpf(void*, void*); // compare float
int cds_cmpd(void*, void*); // compare double
// TODO implement and add more

#endif
