#include <cstring> // std::memcpy; std::memmove; std::memset;

#include "../include/graal.h"

namespace graal{

  const void * min( const void *first, const void *last, size_t size, Compare cmp )
  {

    // Supose that the first is the smallest 
    const void *smallest = first; 

    first = static_cast<const byte *>(first) + size; // first++;
  
    while( first != last ){
      if( cmp( first, smallest ) ){ // first < smallest?
	
	// update smallest
	smallest = first;
      }

      first = static_cast<const byte *>(first) + size; // first++;
    }

    return smallest;

  }

}


void reverse( void * first, void * last, size_t size ){
  byte temp;

  // make last point to the last element in the array
  last = static_cast<const byte *>(last) - size; // last--;
  
  while( first < last ){

    // swap first and last using auxiar pointer temp
    memcpy(&temp, first, size); //????????????
    memcpy(first, last, size); //????????????
    last = *temp;
    
    first = static_cast<const byte *>(first) + size; // first++;
    last = static_cast<const byte *>(last) - size; // last--;
  }
  
}

void * copy( const void * first, const void * last, const void * d_first, size_t size ){
  void * tmp = NULL;
  return tmp;
}

void * clone( const void * first, const void * last, size_t size ){
  void * tmp = NULL;
  return tmp;
}

const void * find_if( const void * first, const void * last, size_t size, Predicate p ){

  return first;
}

const void * find( const void * first, const void * last, size_t size, const void * value, Equal eq ){

  return first;
}

bool all_of( const void * first, const void * last, size_t size, Predicate p ){

  return false;
}

bool any_of( const void * first, const void * last, size_t size, Predicate p ){

  return false;
}

bool none_of( const void * first, const void * last, size_t size, Predicate p ){
  return false;
}

bool equal( const void *first1, const void *last1, const void *first2 ){
  return false;
}

bool equal( const void *first1, const void *last1, const void *first2, size_t size, Equal eq ){
  return false;
}

void * unique( void * first, void * last, size_t size, Equal eq ){
  return first;
}

void * partition( void * first, void * last, size_t size, Predicate p ){
  return first;
}
