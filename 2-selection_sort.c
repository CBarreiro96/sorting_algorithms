#include "sort.h"
/**
 * swap - function that swap two values
 * @a: first value
 * @b: second value
 * Return: void function
 **/
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * selection_sort - algoriths that sort an array using selection method
 * @array: array of int given to sort
 * @size: size of the array
 * @Return: void
 **/
void selection_sort(int *array, size_t size)
{
    unsigned int i, j, min_val = 0;
    if (array == NULL)
        return;
    for (i = 0; i < size - 1; i++)
    {
        min_val = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[min_val] > array[j])
                min_val = j;
        }
        if (i != min_val)
        {
            swap(&array[i], &array[min_val]);
            print_array(array, size);
        }
    }
}
