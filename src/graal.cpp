#include <cstring> //memcpy

#include "../include/graal.h"


const void * min( const void *first, const void *last, size_t size, Compare cmp )
{

  // Supose that the first is the smallest 
  const void *smallest = first; // const int *smallest = first;

  first = static_cast<const byte *> first + size; // first++;
  
  while( first != last ){
    if( cmp( first, smallest ) ){ // first < smallest?

      // update smallest
      smallest = first;
    }

    first = static_cast<const byte *> first + size; // first++;
  }

  return smallest;

};
