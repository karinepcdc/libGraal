#include <cstring> // std::memcpy; std::memmove; std::memset;
#include <iostream> // std::cout; std::endl; 
#include <vector> // iterator

#include "../include/graal.h"

namespace graal
{

  const void * min( const void *first, const void *last, size_t size, Compare comp )
  {

    // Supose that the first is the smallest 
    const void *smallest = first; 

    first = static_cast<const byte *>(first) + size; // first++;
  
    while( first != last ){
      if( comp( first, smallest ) ){ // first < smallest?
	
	// update smallest
	smallest = first;
      }

      first = static_cast<const byte *>(first) + size; // first++;
    }

    return smallest;

  }

  void reverse( void *first, void *last, size_t size )
  {
    byte temp[size];
  
    // make last point to the last element in the array
    last = static_cast< byte *>(last) - size; // last--;
  
    while( first < last ){

      // swap first and last using auxiar pointer temp
      memcpy( &temp, first , size ); // temp = *first    
      memcpy( first, last, size );  // *first = *last
      memcpy( last, &temp, size );  // *last = temp

      first = static_cast< byte *>(first) + size; // first++;
      last = static_cast< byte *>(last) - size; // last--;
    }
  
  }

  void * copy( const void * first, const void * last, void * d_first, size_t size ){

    // loop through original range
    while( first != last ){
      memcpy( d_first, first, size );  // *d_first = *first

      first = static_cast< const byte * >(first) + size; // first++;
      d_first = static_cast< byte * >(d_first) + size; // d_first++;

    }


      return d_first;
  }

  void * clone( const void * first, const void * last, size_t size ){
    // last - first
    size_t length = ( static_cast< const byte *>(last) - static_cast< const byte *>(first) )/size; 
    // allocate clone array
    void * clone_first = new void*[ length ];
    void * clone_array = clone_first;

    // loop through original range
    while( first != last ){
      memcpy( clone_array, first, size );  // *clone_array = *first

      first = static_cast< const byte * >(first) + size; // first++;
      clone_array = static_cast< byte * >(clone_array) + size; // clone_array++;

    }

      return clone_first;
  }

  const void * find_if( const void * first, const void * last, size_t size, Predicate p ){
    
    while( first != last ){
      if( p( first ) ){ // return first element for which p returns true 
	return first;
      }

      first = static_cast< const byte * >(first) + size; // first++;
      
      }

    return first;
  }

  const void * find( const void * first, const void * last, size_t size, const void * value, Equal eq ){
    while( first != last ){
      if( eq( value, first ) ){ // return first element equal to value
	return first;
      }

      first = static_cast< const byte * >(first) + size; // first++;
      
      }

    return first;
  }

  bool all_of( const void * first, const void * last, size_t size, Predicate p ){

    while( first != last ){
      if( !p( first ) ){ // return false if any element returns p false 
	return false;
      }

      first = static_cast< const byte * >(first) + size; // first++;
      
      }

    return true;
  }

  bool any_of( const void * first, const void * last, size_t size, Predicate p ){

    // if range is empty return true
    if( first == last ){ return true; }

    while( first != last ){
      if( p( first ) ){ // return true if any element returns p true 
	return true;
      }

      first = static_cast< const byte * >(first) + size; // first++;
      
      }

    return false;
  }

  bool none_of( const void * first, const void * last, size_t size, Predicate p ){

    while( first != last ){
      if( p( first ) ){ // return false if any element returns p true  
	return false;
      }

      first = static_cast< const byte * >(first) + size; // first++;
      
      }

    return true;
  }

  bool equal( const void *first1, const void *last1, const void *first2, size_t size, Equal eq ){

    while( first1 != last1 ){
      // check if any element is different
      if( !eq( first1, first2 ) ){
	return false;
      }

      first1 = static_cast< const byte * >(first1) + size; // first1++;
      first2 = static_cast< const byte * >(first2) + size; // first2++;
    }

    // if all elements are equal
    return true;
  }

  bool equal( const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq ){

    while( first1 != last1 && first2 != last2 ){
      // check if any element is different
      if( !eq( first1, first2 ) ){
	return false;
      }

      first1 = static_cast< const byte * >(first1) + size; // first1++;
      first2 = static_cast< const byte * >(first2) + size; // first2++;
    }

    if( first1 != last1 || first2 != last2 ){ // check if both range have reach the end
      return false;
    } else { // if all elements are equal
      return true;
    }

  }

  void * unique( void * first, void * last, size_t size, Equal eq ){
    void * slow = first;
    void * fast = first;
    const void * find_ret; 

    while( fast != last ){
      // search if element alread is in range [first; slow)
      find_ret = find( first, slow, size, fast, eq );

      // if *fast was not found in [first; slow)
      if( find_ret == slow ){
	// copy *fast to slow* 
	memcpy( slow, fast, size );  // *slow = *fast

	slow = static_cast< byte * >(slow) + size; // slow++
      } 

      fast = static_cast< byte * >(fast) + size; // fast++
    }

    return slow;
  }

  void * partition( void * first, void * last, size_t size, Predicate p ){
    void * slow = first;
    void * fast = first;
    byte temp[size];

    while( fast != last ){
      
      // if p is true swap fast and slow
      if( p(fast) ){
	memcpy( &temp, fast , size ); // temp = *fast    
	memcpy( fast, slow, size );  // *fast = *slow
	memcpy( slow, &temp, size );  // *slow = temp

	slow = static_cast< byte * >(slow) + size; // slow++
      } 

      fast = static_cast< byte * >(fast) + size; // fast++
    }

    return slow;

  }

  // selection sort algorithm
  void qsort( void * first, size_t n, size_t size, Compare comp ){
    void * last = static_cast< byte * >(first) + n*size;
    void * sel_min;
    byte temp[size];

    while( first != last ){
      // select the smaller elements accordingly with comp
      sel_min =(void *)  min( first, last, size, comp );
      
      // swap first with min
      memcpy( &temp, first , size ); // temp = *first    
      memcpy( first, sel_min, size );  // *first = *min
      memcpy( sel_min, &temp, size );  // *min = temp

      first = static_cast< byte * >(first) + size; // first++;
	
    }
  }



} // end namespace graal
