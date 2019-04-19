#ifndef GRAAL_H
#define GRAAL_H

#include <cstring> // size_t

// generic pointer to function of binary comparison
using Compare = bool (*)( const void *, const void * );

// generic pointer to function of binary equivalence
using Equal = bool (*)(const void *, const void *);

// generic pointer to function of a predicate
using Predicate = bool (*)(const void *);


// useful alias to be use in void pointer arithmetics
using byte = unsigned char;


namespace graal{

  /// Finds and return the first occurrence of the smallest element in a range defined over a generic array.
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param cmp binary functin that returns true if the element is less than the seccond element, or false otherwise
   * \return pointer to the smallest element of the range
   */
  const void * min( const void *first, const void *last, size_t size, Compare cmp );

    /// Reverses the order of the elements located in a range devined over a generic array.
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   */
  void reverse( void * first, void * last, size_t size );

  /// Copy received range [first;last) defined over an array into a new range beginning at d_first.
  /***
   * \param first pointer to the first array element.
   * \param last pointer to past last array element.
   * \param d_first pointer to the first element of the array to be copied.
   * \param size size of each element in the array in bytes.
   * \return pointer to the address just past the last element of the destination range.
   */   
  void * copy( const void * first, const void * last, void * d_first, size_t size );

  /// Receive a range [first;last) defined over an array and return a new array containing a copy of the original range
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \return pointer to the memory area that contains the copy of the original range.
   */ 
  void * clone( const void * first, const void * last, size_t size );

  const void * find_if( const void * first, const void * last, size_t size, Predicate p );

  const void * find( const void * first, const void * last, size_t size, const void * value, Equal eq );

  bool all_of( const void * first, const void * last, size_t size, Predicate p );

  bool any_of( const void * first, const void * last, size_t size, Predicate p );

  bool none_of( const void * first, const void * last, size_t size, Predicate p );

  bool equal( const void *first1, const void *last1, const void *first2 );

  bool equal( const void *first1, const void *last1, const void *first2, size_t size, Equal eq );

  void * unique( void * first, void * last, size_t size, Equal eq );

  void * partition( void * first, void * last, size_t size, Predicate p );
 
  //  sort(  );
}

#endif
