#include "sort.h"
/**
 *  _swap - change number of position
 * @head: NUmber to indicate to change
 * @list: doubly linked list
 * Return - Not return
 */

void _swap(listint_t **head, listint_t **list)
{
	listint_t *tmp_Head, *tmp_Head_next, *tmp_node;

	if (!(*head)->prev)
		*list = (*head)->next;

	tmp_Head = tmp_node = *head;
	tmp_Head_next = tmp_Head->next;

	tmp_Head->next = tmp_Head_next->next;
	tmp_node = tmp_Head->prev;
	tmp_Head->prev = tmp_Head_next;
	tmp_Head_next->next = tmp_Head;
	tmp_Head_next->prev = tmp_node;

	if (tmp_Head_next->prev)
		tmp_Head_next->prev->next = tmp_Head_next;


	if (tmp_Head->next)
		tmp_Head->next->prev = tmp_Head;

	*head = tmp_Head_next;

}


/**
 * insertion_sort_list - orts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: Not return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *head, *List_back, *current;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			current = head;

			_swap(&current, list);
			print_list(*list);
			head = current;
			List_back = current;

			while (List_back && List_back->prev)
			{

				if (List_back->n < List_back->prev->n)
				{
					current = List_back->prev;

					_swap(&(current), list);

					print_list(*list);
					List_back = current->next;
				}

				List_back = List_back->prev;
			}

		}
		head = head->next;
	}
}
