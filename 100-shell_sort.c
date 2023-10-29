#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			j = i;
			tmp = array[i];
			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
