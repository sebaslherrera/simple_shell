#include "holberton.h"

/**
 * free_list - Free the all the nodes in the list
 * @head: Pointer to the linked list
 *
 * Return: nothing.
 */
void free_list(Node *head)
{
	Node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}

}

/**
 * print_list - Print all the elements of the list
 * @h: Linked list data
 *
 * Return: Number of elements in the list
 */
size_t print_list(const Node *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
			printf("%s\n", h->str);
		else
			printf("%s\n", "(nil)");

		h = h->next;
		i++;
	}

	return (i);
}
