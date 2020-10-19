#inculde "sort.h"




void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*list = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;

}
