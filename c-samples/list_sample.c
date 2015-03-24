#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int value;
	struct element *next;
} Element;

typedef Element* List;

/*
	Checks whether value is in list
	
	list is the starting point from which the function looks for the value
*/
int contains(List list, int value)
{
	
	if (list == NULL)
		return -1;
		
	while (list != NULL)
	{
		if (list->value == value)
			return 1;
		
		list = list->next;
	}
	
	return -1;
}

/*
	returns the size of the list with starting point as the param "list"
*/
int listSize(List list)
{
	int i;
	
	if (list == NULL)
		return 0;
	
	for (i = 0; list != NULL; i++)
		list = list->next;
		
	return i;
}

/*
	automatically deletes all elements of the list after param "list"
*/
void deleteList(List *list)
{
	List temp;
	
	if (*list == NULL)
		return;
	
	else
	{
		while (*list != NULL)
		{
			temp = (*list)->next;
			free(*list);
			*list = temp;
		}
	}
}

/*
	prints all elements of the list after param "list"
*/
void printList(List list)
{
	if (list == NULL)
		return;
	
	else
	{
		while(list != NULL)
		{
			printf("%d\n", list->value);
			list = list->next;
		}
	}
}

/*
	inserts an element in front of "list"
*/
void insert_start(List *list, int value)
{
	List new = (List) malloc(sizeof(Element));
	
	new->value = value;
	new->next = NULL;
	
	if (*list == NULL)
		*list = new;
		
	else
	{
		new->next = *list;
		*list = new;
	}
}

/*
	inserts an at the end of "list"
*/
void insert_end(List *list, int value)
{
	List temp = *list;
	
	List new = (List) malloc(sizeof(Element));
	
	new->value = value;
	new->next = NULL;
	
	if (*list == NULL)
		*list = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
			
		temp->next = new;
	}
}

/*
	inserts and element at the right place from starting point "list"
*/
void sort_insert(List *list, int value)
{
	List temp = *list;
	List temp2 = temp;
	
	if (*list == NULL)
	{
		insert_start(list, value);
		return;	
	}
	
	while (temp != NULL && (temp->value < value))
		temp=temp->next;
		
	if (temp == NULL)
	{
		add_end(list, value);
		return;
	}
	
	List new = (List) malloc(sizeof(Element));
	new->value = value;
	new->next = NULL;
	
	if (temp == *list)
	{
		new->next = temp;
		*list = new;
	}
	
	else
	{
		while (temp2->next != temp)
			temp2 = temp2->next;
			
		new->next = temp;
		temp2->next = new;
	}
}
