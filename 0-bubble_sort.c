#include "sort.h"

/**
 * bubble_sort - Sort a array by bubble sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{

	size_t i, j;
	int tmp;
	int swip;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swip = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);
			}
			swip = 1;
		}

		if (swip == 0)
		{
			break;
		}
	}
}
