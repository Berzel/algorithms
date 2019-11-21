#include <stdio.h>

/**
 * Search for an item in an array using linear search
 * 
 * @param int *arr  The array that is being searched
 * @param int size  The size of the array that is being searched
 * @param int val The value we are searching for
 * @return int  The index position of the element if it is found otherwise -1 if not found
 **/
int search(int *arr, int size, int val){
  for (int i = 0; i < size; ++i){
    if (arr[i] == val){
      return i;
    }
  }

  return -1;
}


/**
 * Run some tests
 **/
int main(int argc, char const *argv[]){
  int A[] = {100,230,13,54,15,46,75,8,90,10}, n = 10;
  int val = 13;

  int found = search(A, n, val);

  if (found > 0) {
    printf("Value %d found at position %d.\n", val, found);
  }

  return 0;
}
