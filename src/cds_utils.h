#pragma once

#include <stdlib.h>

/* cds_cmp
 * -------
 * Compare two generic data types.
 * Below are some predefined functions for basic data types. 
 * Any custom data types will need their own function created by the user.
 *
 * return:
 *      1 if 1st > 2nd
 *     -1 if 1st < 2nd
 *      0 if 1st = 2nd
 */
typedef int(*cdsCmp)(void*, void*);

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
 */
char cds_vtvc(void*);         // extract a char 
int cds_vtvi(void*);          // extract an int
unsigned int cds_vtvu(void*); // extract an unsigned int
float cds_vtvf(void*);        // extract a float
double cds_vtvd(void*);       // extract a double
