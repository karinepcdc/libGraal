#ifndef GRAAL_H
#define GRAAL_H

// generic pointer to function of binary comparison
using Compare = bool (*)( const void *, const void * );

// useful alias to be use in void pointer arithmetics
using byte = unsigned char;


/// Finds and return the first occurrence of the smallest element in a range devined over a generic array
/**
 *
 */
const void * min( const void *first, const void *last, size_t size, Compare cmp );





#endif
