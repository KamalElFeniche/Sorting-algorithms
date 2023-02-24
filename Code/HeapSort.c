/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
 * ========================================================================= */


#include <stdlib.h>
#include <stddef.h>
#include "Sort.h"


static void maxHeapify(int* array, size_t k, size_t heapSize){
	if (array == NULL)
		exit(-1);

	size_t left = 2 * k;
	size_t right = (2 * k) + 1;
	size_t largest;
	int tmp;

	if ((left < heapSize) && (array[left] > array[k]))
		largest = left;
	else
		largest = k;

	if ((right < heapSize) && (array[right] > array[largest]))
		largest = right;

	if (largest != k){
		tmp = array[k];
		array[k] = array[largest];
		array[largest] = tmp;
		maxHeapify(array, largest, heapSize);
	}
}


static void buildMaxHeap(int* array, size_t length){
	if (array == NULL)
		exit(-1);
	
	for (int i = (length / 2) - 1; i >= 0; i--)
		maxHeapify(array, i, length);
}


static void heapSort(int* array, size_t length){
	if (array == NULL)
		exit(-1);

	buildMaxHeap(array, length);
	size_t heapSize = length;
	int tmp;
	
	for (int i = length - 1; i >= 0; i--){
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		heapSize--;
		maxHeapify(array, 0, heapSize);
	}	

}


void sort (int* array, size_t length){

	if (array == NULL || length <= 0)
		exit(-1);

	heapSort(array, length);
}