#ifndef CDS_UTILS_H
#define CDS_UTILS_H

/* cds_cmp<type>
 * -------------
 * Compare two generic data types. This is a dummy function meant to be 
 * overriden by the user in various data structures for sorting and other 
 * functionality. Below are some predefined functions for basic data types. 
 * Any custom data types will need their own function created by the user.
 *
 * Feel free to add more for any custom datatypes!
 *
 * return:
 *      1 if 1st > 2nd
 *     -1 if 1st < 2nd
 *      0 if 1st = 2nd
 */
int cds_cmpc(void*, void*); // compare char
int cds_cmpi(void*, void*); // compare int
int cds_cmpu(void*, void*); // compare unsigned int
int cds_cmpf(void*, void*); // compare float
int cds_cmpd(void*, void*); // compare double

/* cds_vtv<type>
 * -------------
 * vtv stands for void to value.
 * Helper functions to cast and dereference a void poniter. Only use if you
 * know the pointer holds <type> data. Just decluters all the casting and 
 * dereferencing for readability sake. 
 *
 * Feel free to add some more for any custom datatypes!
 */
char cds_vtvc(void*);         // extract a char 
int cds_vtvi(void*);          // extract an int
unsigned int cds_vtvu(void*); // extract an unsigned int
float cds_vtvf(void*);        // extract a float
double cds_vtvd(void*);       // extract a double

#endif
