#ifndef GRAAL_H
#define GRAAL_H

using Compare = bool (*)( const void *, const void * );

using byte = unsigned char;

bool cmp( const void *, const void * );

/// Finds and return the first occurrence of the smallest element in a range devined over a generic array
/**
 *
 */
const void * min( const void *first, const void *last, size_t size, Compare cmp );

#endif
