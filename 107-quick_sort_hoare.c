#include "sort.h"

/**
 * swap - swaps two values
 * @a: 1st value
 * @b: 2nd value
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * partition_hoare - partitions array between low and high index
 * @array: input array
 * @low: index of start of array
 * @high: index of end of array
 * @size: length of array
 * Return: starting index plus one
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j = high + 1;

while (i < j)
{
do
i++;
while (array[i] < pivot);
do
j--;
while (array[j] > pivot);
if (i < j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
return (i);
}

/**
 * quicks - quick sort with extra parameter size
 * @array: input array
 * @low: index of start of array
 * @high: index of end of array
 * @size: length of array
 */
void quicks(int *array, int low, int high, size_t size)
{
int hoare;

if (low < high)
{
hoare = partition_hoare(array, low, high, size);
quicks(array, low, hoare - 1, size);
quicks(array, hoare, high, size);
}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: input array
 * @size: length of array
 */
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;

quicks(array, 0, size - 1, size);
}
