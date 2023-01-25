#include "sort.h"
#include <stdlib.h>

/**
 * partition - The Lamuto partition scheme
 * @array: the array
 * @size: the size of the array
 * @pivot: the pivot
 * Return: 0 Always Succesful
 */
size_t partition(int *array, size_t size, int pivot)
{
	int temp;
	size_t i, j;

	for (i = 0, j = 0; j < size; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	return (i);
}

/**
 * quick_sort - sorts an array of integers using the Quick Sort Algorithm
 * @array: the array of integers
 * @size: the size of the array
 * Return: the sorted array
 */
void quick_sort(int *array, size_t size)
{
	int pivot = array[size - 1];
	size_t p = partition(array, size, pivot);

	if (size < 2)
	{
		return;
	}
	quick_sort(array, p);
	quick_sort(array + p + 1, size - p - 1);
}
