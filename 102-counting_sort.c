#include "sort.h"

/**
 * counting_sort - sort array using counting sort
 * @array: an array to sort
 * @size: size of an array
 * Return: void
*/

void counting_sort(int *array, size_t size) {
        int *counting_array, *sorted_array, k = 0, j = 0, l = 1, n = size - 1;
        size_t i = 0, z = 0, h = 0;
        if (size <= 1) 
        {
                return;
        }

        while (i < size) 
        {
                if (array[i] > k) 
                {
                        k = array[i];
                }
                i++;
        }

        sorted_array = malloc(size * sizeof(int));
        if (sorted_array == NULL) 
        {
                return;
        }

        counting_array = malloc((k + 1) * sizeof(int));
        if (counting_array == NULL) 
        {
                free(sorted_array);
                return;
        }
 
        while (j <= k) 
        {
                counting_array[j] = 0;
                j++;
        }

        while (z < size) 
        {
                counting_array[array[z]]++;
                z++;
        }

        while (l <= k) 
        {
                counting_array[l] += counting_array[l - 1];
                l++;
        }
        print_array(counting_array, k + 1);

        while (n >= 0) 
        {
                sorted_array[counting_array[array[n]] - 1] = array[n];
                counting_array[array[n]]--;
                n--;
        }

        while (h < size)
        {
                array[h] = sorted_array[h];
                h++;
        }

        free(counting_array);
        free(sorted_array);
}
