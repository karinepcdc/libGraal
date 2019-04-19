#include "../include/graal.h"
#include <iostream>

bool compare_ints( const void *a, const void *b)
{
  return *( static_cast<const int*>(a) ) < *( static_cast<const int*>(b) );
}

void printArray( int *Vec , int size ){

  std::cout << "[ ";
  for( int i = 0; i < size; i++ ){
    std::cout << Vec[i] << ", ";
      }
  std::cout << " ]";


}

int main()
{
  //  float B[]{2.3, 5.8, -2.1, 10.3, -5};
  int A[]{ 1, 2, 3, -2, 0, 10, -1 };

  std::cout << ">>> Array A: ";
  printArray( A, 7);
  std::cout << std::endl;

  auto result =  (const int *) graal::min( std::begin(A), std::end(A), sizeof(int), compare_ints );
  
  
  std::cout << "min: " << *result << std::endl;

  graal::reverse( std::begin(A), std::end(A), sizeof(A[0]) );  

  std::cout << ">>> Array A after reverse: ";
  printArray( A, 7);
  std::cout << std::endl;


  return 0;
}
