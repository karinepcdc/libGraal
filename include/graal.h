#ifndef GRAAL_H
#define GRAAL_H

// generic pointer to function of binary comparison
using Compare = bool (*)( const void *, const void * );

// generic pointer to function of binary equivalence
using Equal = bool (*)(const void *, const void *);

// generic pointer to function of a predicate
using Predicate = bool (*)(const void *);


// useful alias to be use in void pointer arithmetics
using byte = unsigned char;


namespace graal{

  /// Finds and return the first occurrence of the smallest element in a range devined over a generic array
  /**
   *
   */
  const void * min( const void *first, const void *last, size_t size, Compare cmp );

  void reverse( void * first, void * last, size_t size );

  void * copy( const void * first, const void * last, const void * d_first, size_t size );

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
