#include "sort.h"
#include <stdlib.h>

/**
 * selection_sort - sorts an array with Selection Sorting Algorithm
 * @array: the array of unsorted integers
 * @size: size of the array
 * Return: the sorted array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, jMin;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
