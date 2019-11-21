#include <stdio.h>
#include <stdlib.h>

/**
 * Merge two sorted arrays together
 * 
 * @param int *left The left array to be merged
 * @param int left_size The size of the left array
 * @param int *right  The right array to be merged
 * @param int right_size  The size of the right array
 * @returns int *result A sorted array, which is a result of combining two sorted arrays
 **/
int *merge(int *left, int left_size, int *right, int right_size){
  int size = left_size + right_size;
  int *result = (int *)malloc(sizeof(int) * size);

  int left_index = 0, right_index = 0;

  for (int i = 0; i < size; ++i){
    if (left_index < left_size && right_index < right_size){
      result[i] = left[left_index] < right[right_index] ? left[left_index] : right[right_index];

      if (left[left_index] < right[right_index]){
        ++left_index;
        continue;
      } else {
        ++right_index;
        continue;
      }
    }

    if (left_index < left_size){
      result[i] = left[left_index];
      ++left_index;
      continue;
    }

    if (right_index < right_size){
      result[i] = right[right_index];
      ++right_index;
      continue;
    }
  }

  return result;
}

/**
 * Sort an array using merge sort algorithm
 * 
 * @param int *unsorted The unsorted array that needs to be sorted
 * @param int size  The size of the array that needs to be sorted
 **/
int *sort(int *unsorted, int size){

  if (size == 1){
    return unsorted;
  }

  int left_size = size - (size / 2);
  int right_size = size - left_size;

  int *left = (int *) malloc(sizeof(int) * left_size);
  int *right = (int *) malloc(sizeof(int) * right_size);

  for (int i = 0; i < left_size; ++i){
    left[i] = unsorted[i];
  }

  for (int i = 0; i < right_size; ++i){
    right[i] = unsorted[i + left_size];
  }

  return merge(
      sort(left, left_size), left_size,
      sort(right, right_size), right_size);
}


/**
 * Run some tests
 * 
 **/
int main(int argc, char const *argv[]){
  int A[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, n = 13;

  int *sorted = sort(A, n);

  for (int i = 0; i < n; ++i){
    printf("%d\n", sorted[i]);
  }

  return 0;
}
