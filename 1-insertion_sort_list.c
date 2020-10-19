#include "sort.h"
/*
*insertion_sort_list- ascending order using the Insertion sort algorithm
*list - Pointer of kind of struct
*Return: there are not return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t  *head, *aux;

	head = *list;

	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			tmp = head;
			printf("%d", head);
			_swap(&aux, list);
			print_list(*list);
			head = tmp
		}
	}
}
