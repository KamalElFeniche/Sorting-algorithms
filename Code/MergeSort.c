/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */


#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "Sort.h"



static void merge(int* array, size_t lo, size_t mid, size_t hi){

	if (array == NULL)
		exit(-1);
	
	size_t p = mid - lo + 1;
	size_t q = hi - mid;

	int* left = malloc((p + 1) * sizeof(int));
	if (left == NULL)
		exit(-1);

	int* right = malloc((q + 1) * sizeof(int));
	if (right == NULL)
		exit(-1);

	
	size_t i = 0;
	size_t j = 0;
	
	for (i = 0; i < p; i++)
		left[i] = array[lo + i];
	left[p] = INT_MAX; // Sentinel

	for (j = 0; j < q; j++)
		right[j] = array[mid + j + 1];
	right[q] = INT_MAX; // Seninel

	i = 0;
	j = 0;

	
	for (size_t k = lo; k <= hi; k++){
		if (left[i] <= right[j]){
			array[k] = left[i];
			i++;
		}else{
			if (left[i] > right[j]){
				array[k] = right[j];
				j++;
			}
		}
	}

	free(left);
	free(right);	
}

static void recurMergeSort(int* array, size_t lo, size_t hi){
	
	if (array == NULL)
		exit(-1);

	if (lo < hi){
		size_t mid = lo + (hi -lo) / 2;
		
		recurMergeSort(array, lo, mid);
		recurMergeSort(array, mid + 1, hi);
		merge(array, lo, mid, hi);

	}
}


static void mergeSort(int* array, size_t length){
	
	if (array == NULL)
		exit(-1);

	recurMergeSort(array, 0, length - 1);
}



void sort (int* array, size_t length){

	if (array == NULL || length <= 0)
		exit(-1);

	mergeSort(array, length);
}
