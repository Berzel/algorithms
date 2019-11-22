#include <stdio.h>

/**
 * Maintains the max-heap property of an array
 **/
int *heapify(int *arr, int i, int heapsize){
  int left = 2*i + 1;
  int right = left + 1;

  int largest = (left < heapsize && arr[left] > arr[i]) ? left : i;
  largest = (right < heapsize && arr[right] > arr[largest]) ? right : largest;

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, largest, heapsize);
  }

  return arr;
}

/**
 * 
 **/
int *buildMaxHeap(int *arr, int size){
  int heapsize = size;

  for (int i = (size/2) - 1; i >= 0; --i) {
    heapify(arr, i, heapsize);
  }

  return arr;
}


/**
 * 
 **/
int *heapsort(int *arr, int size){
  int *maxHeap = buildMaxHeap(arr, size), heapsize = size - 1;

  for (int i = size - 1; i > 0; --i, --heapsize){
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    heapify(arr, 0, heapsize);
  }

  return arr;
}


/**
 * Run some tests
 **/
int main(){
  int arr[] = {19,81,17,62,54,45,34,23,41}, size = 9;
  int *sorted = heapsort(arr, size);

  for (int i = 0; i < size; ++i){
    printf("%d ", sorted[i]);
  }

  printf("\n");
  return 0;
}