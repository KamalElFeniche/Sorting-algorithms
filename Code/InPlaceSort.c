/* ========================================================================= *
 * InPlaceSort
 * Implementation of the InPlaceSort algorithm which is the in place version
 * of the MergeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include "Sort.h"


static void inPlaceMerge(int* array, size_t lo, size_t mid, size_t hi){

	if (array == NULL)
		exit(-1);

	size_t indexLeft = lo;
	size_t indexRight = mid + 1;

	while (indexLeft <= mid && indexRight <= hi){

		if (array[indexLeft] <= array[indexRight]){
			indexLeft++;
		
		}else{

			int value = array[indexRight];
			
			for (size_t k = indexRight; k != indexLeft; k--)
				// Shift the sub-array[indexLeft... indexRight-1] one position to the right.
				array[k] = array[k - 1];
			
			array[indexLeft] = value;
			indexRight++;
			indexLeft++;
			mid++;
		}
	}
}



static void recurInPlaceMerge(int* array, size_t lo, size_t hi){

	if (array == NULL)
		exit(-1);

	if (lo < hi){
		size_t mid = lo + (hi - lo) / 2;
		
		recurInPlaceMerge(array, lo, mid);
		recurInPlaceMerge(array, mid + 1, hi);
		inPlaceMerge(array, lo, mid, hi);
	}
}


static void inPlaceSort(int* array, size_t length){

	if (array == NULL)
		exit(-1);

	recurInPlaceMerge(array, 0, length - 1);
}


void sort (int* array, size_t length){

	if (array == NULL || length <= 0)
		exit(-1);

	inPlaceSort(array, length);
}