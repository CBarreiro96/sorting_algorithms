#include "sort.h"
/**
 * swap - swaps to variable values
 * @a: 1st value
 * @b: 2nd value
 * Return: void
 **/
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * partition - itererates the partition and call swap
 * @array: array of the partition
 * @low: 1st value of the array
 * @high: last value of the array
 * @size: size of the array
 * Return: i + 1
 **/
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high], i = low - 1, j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
if ((i + 1) != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}
/**
 * quicks - recursive call to creates partitions
 * @array: array of the partition
 * @low: 1st value of the array
 * @high: last value of the array
 * @size: size of the array
 * Return: Void
 **/
void quicks(int array[], int low, int high, size_t size)
{
int lomuto;

if (low < high)
{
lomuto = partition(array, low, high, size);

quicks(array, low, lomuto - 1, size);
quicks(array, lomuto + 1, high, size);
}
}
/**
 * quick_sort - calls quicks with all parameters
 * @array: array of the partition
 * @size: size of the array
 * Return: Void
 **/
void quick_sort(int *array, size_t size)
{

if (array == NULL || size < 2)
return;

quicks(array, 0, size - 1, size);
}
