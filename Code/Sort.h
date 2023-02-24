/* ========================================================================= *
 * Sort
 * ========================================================================= */

#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Sort an array of integers.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void sort(int* array, size_t length);


/* ------------------------------------------------------------------------- *
 * Sort an array of integers following the HeapSort algorithm.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void heapSort(int* array, size_t length);


/* ------------------------------------------------------------------------- *
 * Sort an array of integers following the InPlaceSort algorithm.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void inPlaceSort(int* array, size_t length);


/* ------------------------------------------------------------------------- *
 * Sort an array of integers following the MergeSort algorithm.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void mergeSort(int* array, size_t length);


/* ------------------------------------------------------------------------- *
 * Sort an array of integers following the QuickSort algorithm.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void quickSort(int* array, size_t length);

#endif // !_SORT_H_
