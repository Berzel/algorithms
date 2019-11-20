#include <stdio.h>
#include <stdlib.h>

/**
 * Sort an array of integers in ascending order using insertion sort algorithm
 * 
 * @param int *unsorted  The array to be sorted
 * @param int size  The size of the array to be sorted
 * @return int *sorted  The sorted array in ascending order
 **/
int *sort(int *unsorted, int size){
  int *sorted = (int *) malloc(sizeof(int) * size), temp;

  for (int i = 0; i < size; ++i){
    sorted[i] = unsorted[i];

    for (int j = i; j > 0 && sorted[j] < sorted[j - 1]; --j){
      temp = sorted[j - 1];
      sorted[j - 1] = sorted[j];
      sorted[j] = temp;
    }
  }

  return sorted;
}

/**
 * Run some tests
 * 
 **/
int main(){
  int n = 10, A[] = {800, 5, 4, 3, 9, 20, 1, 7, 6, 2};
  int *sorted = sort(A, n);

  for (int i = 0; i < n; i++){
    printf("%d\n", sorted[i]);
  }

  return 0;
}