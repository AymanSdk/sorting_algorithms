#include "sort.h"

/**
 * selection_sort - sorting an array using selection sort
 * @array: an array to sort
 * @size: size of the array
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
        int swap = 0;

        size_t i, j;

        if (size < 2)
	{
		return;
	}

        for (i = 0; i < size - 1; i++)
        {
                size_t min_idx = i;
                swap = 0;
                for (j = i + 1; j < size; j++)
                {
                if (array[j] < array[min_idx])
                        min_idx = j;
                }

                if (min_idx != i)
                {
                        int temp = array[i];
                        array[i] = array[min_idx];
                        array[min_idx] = temp;
                        print_array(array, size);
                }
                swap = 1;
                if (swap == 0)
		{
			break;
		}
        }
}
