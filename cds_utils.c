#include "cds_utils.h"

// dummy function
int cds_cmp(void* beevus, void* butthead) {
    return -1;
}

int cds_cmpi(void* first, void* second) {
    int firsti = *((int*) first);
    int secondi = *((int*) second);
    if (firsti > secondi) {
        return 1;
    } 
    if (firsti < secondi) {
        return -1;
    }
    return 0;
}

int cds_cmpu(void* first, void* second) {
    unsigned int firstu = *((unsigned int*) first);
    unsigned int secondu = *((unsigned int*) second);
    if (firstu > secondu) {
        return 1;
    } 
    if (firstu < secondu) {
        return -1;
    }
    return 0;
}

int cds_cmpf(void* first, void* second) {
    float firstf = *((float*) first);
    float secondf = *((float*) second);
    if (firstf > secondf) {
        return 1;
    } 
    if (firstf < secondf) {
        return -1;
    }
    return 0;
}

int cds_cmpd(void* first, void* second) {
    double firstd = *((double*) first);
    double secondd = *((double*) second);
    if (firstd > secondd) {
        return 1;
    } 
    if (firstd < secondd) {
        return -1;
    }
    return 0;
}
