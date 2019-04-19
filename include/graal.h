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
  const void * min( const void *first, const void *last, size_t size, Compare comp );

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

  /// Do a linear search in a range [first;last) over an array and returns a pointer (iterator) to the first element in the range for which a given predicate returns true.
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param p pointer to a unary predicate which return true for the required element.
   * \return Pointer to the first element satisfying the condition or last if no such element is found.
   */ 
  const void * find_if( const void * first, const void * last, size_t size, Predicate p );

  /// Do a linear search in a range [first;last) over an array and returns a pointer (iterator) to the first element in the range that is equal to the value passed to the function.
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param value value to compare the elements to.
   * \param eq pointer to a binary function that returns true if the elements are equal, or false otherwise.
   * \return Pointer to the first element equal to value or last if no such element is found.
   */ 
  const void * find( const void * first, const void * last, size_t size, const void * value, Equal eq );

  /// Checks if the predicate p returns true for all elements in a generic range [first; last).
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param p pointer to a unary predicate which return true for the required element.
   * \return Returns true if the predicate p returns true for all elements in the range, returns false otherwise. Returns true if the range is empty.
   */ 
  bool all_of( const void * first, const void * last, size_t size, Predicate p );

  /// Checks if the predicate p returns true for at least one element in a generic range [first; last).
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param p pointer to a unary predicate which return true for the required element.
   * \return Returns true if the predicate p returns true for at least one element in the range, returns false otherwise. Returns true if the range is empty.
   */ 
  bool any_of( const void * first, const void * last, size_t size, Predicate p );

  /// Checks if the predicate p returns false for all elements in a generic range [first; last).
  /***
   * \param first pointer to the first array element
   * \param last pointer to past last array element
   * \param size size of each element in the array in bytes
   * \param p pointer to a unary predicate which return true for the required element.
   * \return Returns true if the predicate p returns false for all elements in the range, returns false otherwise. Returns true if the range is empty.
   */ 
  bool none_of( const void * first, const void * last, size_t size, Predicate p );

  /// Verify if all elements in a generic range [first1; last1) are equal to the elements in an range that start at first2
  /***
   * \param first1 pointer to the first array element.
   * \param last1 pointer to past last array element.
   * \param first2 pointer to the first element of another range.
   * \param size size of each element in the array in bytes.
   * \param eq pointer to a binary function that returns true if the elements are equal, or false otherwise.
   * \return Return true, if the first range if equal to the seccond range, or false otherwise.
   */   
  bool equal( const void *first1, const void *last1, const void *first2, size_t size, Equal eq );

  /// Verify if a generic range [first1; last1) are equal to the generic range [first2; last2).
  /***
   * \param first1 pointer to the first array element of range1.
   * \param last1 pointer to past last array element of range1.
   * \param first2 pointer to the first element of range2.
   * \param last2 pointer to past last array element of range2.
   * \param size size of each element in the array in bytes.
   * \param eq pointer to a binary function that returns true if the elements are equal, or false otherwise.
   * \return Return true, if the first range if equal to the seccond range, or false otherwise.
   */   
  bool equal( const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq );

  /// Reorders the elements in the range [first, last) in such a way that all unique elements should appear at the beginning of the range preserving relative order.
  /***
   * \param first pointer to the first array element.
   * \param last pointer to past last array element.
   * \param size size of each element in the array in bytes.
   * \param eq pointer to a binary function that returns true if the elements are equal, or false otherwise.
   * \return A pointer to the address just past the last element of the range with unique elements.
   */  
  void * unique( void * first, void * last, size_t size, Equal eq );

  /// Reorders the elements in the range [first, last) in such a way that all elements for which a given predicate p returns true precede the elements for which predicate p returns false.
  /***
   * \param first pointer to the first array element.
   * \param last pointer to past last array element.
   * \param size size of each element in the array in bytes.
   * \param p pointer to a unary predicate which return true for the required element.
   * \return A pointer to the begining of the range for which predicate p return false.
   */  
  void * partition( void * first, void * last, size_t size, Predicate p );
 
  /// Receives and sorts the elements in ascending order. The order of equal elements is not guaranteed to be preserved.
/***
   * \param first pointer to the first array element.
   * \param number of elements in the array.
   * \param size size of each element in the array in bytes.
   * \param cmp binary functin that returns true if the element is less than the seccond element, or false otherwise
   */  
  void qsort( void * first, size_t n, size_t size, Compare comp );

}

#endif
