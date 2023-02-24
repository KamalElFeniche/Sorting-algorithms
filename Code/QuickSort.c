/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm with a non-random pivot.
 * ========================================================================= */


#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "Sort.h"


static int partition(int* array, int lo, int hi){

	if (array == NULL)
		exit(-1);
	
	int pivot = array[hi];
	int i = lo - 1;
	int tmp;

	for (int j = lo; j < hi; j++){

		if (array[j] <= pivot){
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}

	tmp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = tmp;

	return (i + 1);
}


static void recurQuickSort(int* array, int lo, int hi){
	if (array == NULL)
		exit(-1);

	if (lo < hi){
		int pos = partition(array, lo, hi);
		recurQuickSort(array, lo, pos - 1);
		recurQuickSort(array, pos + 1, hi);
	}
}


static void quickSort(int* array, size_t length){
	
	if (array == NULL)
		exit(-1);

	recurQuickSort(array, 0, length - 1);
}



 void sort (int* array, size_t length){

	if (array == NULL || length <= 0)
		exit(-1);

	quickSort(array, length);
}
