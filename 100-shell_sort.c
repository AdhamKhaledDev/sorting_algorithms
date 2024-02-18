#include "sort.h"
/*
 * shell_sort - Sorts an array of integers using the Shell Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, outer, inner;
	int value;

	gap = 1;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			value = array[outer];
			for (inner = outer; inner >= gap && array[inner - gap] > value; inner -= gap)
				array[inner] = array[inner - gap];
			array[inner] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
