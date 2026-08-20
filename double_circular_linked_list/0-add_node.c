#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - adds a new node at the end of a circular doubly linked list
 * @list: pointer to the head of the list
 * @str: string to duplicate into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->prev = last;
	new->next = *list;
	last->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - adds a node at the beginning of a circular doubly linked list
 * @list: pointer to the head of the list
 * @str: string to duplicate into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
