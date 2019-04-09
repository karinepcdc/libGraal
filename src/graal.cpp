#include <cstring> //memcpy

#include "../include/graal.h"



/*bool cmp( const void *a, const void *b)
{


}*/


const void * min( const void *first, const void *last, size_t size, Compare cmp )
{

  // Supose that the first is the smallest 
  const byte *smallest = (const byte *) first; // const int *smallest = first;
  
  while( first != last ){
    if( cmp( first, menor ) ){ // first < smallest?

      // update smallest
      smallest = (const byte *) first;
    }

    first = first + size; // first++;
  }

  return smallest;

};
