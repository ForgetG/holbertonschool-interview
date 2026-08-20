#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to the first node of the list
 *
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *previous;
	listint_t *next;

	previous = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = previous;
		previous = head;
		head = next;
	}

	return (previous);
}

/**
 * compare_lists - compares two linked list portions
 * @first: pointer to the first list
 * @second: pointer to the second list
 *
 * Return: 1 if both portions contain the same values, otherwise 0
 */
int compare_lists(listint_t *first, listint_t *second)
{
	while (second != NULL)
	{
		if (first->n != second->n)
			return (0);

		first = first->next;
		second = second->next;
	}

	return (1);
}

/**
 * is_palindrome - checks whether a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *second;
	int result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
		slow = slow->next;

	second = reverse_list(slow);
	result = compare_lists(*head, second);
	reverse_list(second);

	return (result);
}
