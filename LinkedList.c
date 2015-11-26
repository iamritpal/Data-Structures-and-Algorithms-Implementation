/*
	Simple Linked List implimentation in C programming language.
	Software Engineer - Amritpal Singh
	Website - http://amritpal.net
	Date - 11/25/2015
	Simple linked list of integer values, it can be easily modified to have additional properties in the node structure.
*/

#include <stdio.h>
#include <stdlib.h>


struct Node		/* Each node of the linked list has a value and referece to next node */
{
	int value;
	struct Node *nextNode;		// Referencing pointer to the address of another node
};

/* Create two referencing pointer variables */
struct Node *head = NULL;
struct Node *current = NULL;

struct Node* createNewNode(void);		// Creates a new node
int addToList(struct Node* nodePtr);
void printList(void);
int deleteFromList(int value);
int findInList(int value, struct Node** prevNodePtr);

int main(void)
{
	int i=0;
	struct Node temp;
	while (i < 100)
	{
		if ((i%2) == 0)		// Add all even numbers to the list from 0-99
		{
			temp.value = i;
			addToList(&temp);
		}
		i++;
	}

	if (deleteFromList(98) != 0)
		printf("deleted successfully\n");
	else
		printf("couldn't delete\n");

	printList();

	return 0;
}

/*
	Returns reference to the address of newly created node
*/

struct Node* createNewNode(void)
{
	return((struct Node*)malloc(sizeof(struct Node)));
}

/*
	Argument: Referencing pointer to the address of node to add to list
	Returns: 0=Couldn't add new node to the list
			 1=Successfully added new node to the list
*/

int addToList(struct Node* nodePtr)
{
	struct Node *newNode = createNewNode();
	if (newNode != NULL)
	{
		if (head == NULL)
			head = newNode;
		else
			current->nextNode = newNode;
		newNode->value = nodePtr->value;
		newNode->nextNode = NULL;
		current = newNode;
		return(1);
	}
	return(0);
}

/*
	Argument: value = Integer value to delete from list if it exists
	Returns: 0=couldn't delete the value from list
			 1=successfully deleted the value from list
*/

int deleteFromList(int value)
{
	struct Node *prevNode = NULL;
	struct Node *delNode = NULL;

	if (findInList(value,&prevNode) != 0)
	{
		if (prevNode == NULL)		 // Special case when head was found as the node to delete
		{
			delNode = head;
			head = head->nextNode;
			if (delNode == current)
				current = NULL;
		}
		else
		{
			delNode = prevNode->nextNode;
			prevNode->nextNode = delNode->nextNode;
			if (delNode == current)
				current = prevNode->nextNode;
		}
		free(delNode);
		return(1);
	}
	return(0);
}

/*
	Argument: value = Integer value to find in the list
			  prevNodePtr = Referencing pointer gets set to address of the previous node's address if exists
	Returns: 0=value not found in list
			 1=value found in the list
*/

int findInList(int value, struct Node** prevNodePtr)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		temp = head;
		while (temp != NULL)		
		{
			if (temp->value == value)
				return(1);
			*prevNodePtr = temp;
			temp = temp->nextNode;
		}
	}
	return(0);
}

/*
	Traverse through the list and print out values
*/

void printList(void)
{
	struct Node *temp = head;
	
	if (head != NULL)
	{
		temp = head;
		while (temp != NULL)
		{
			printf("%d \n", temp->value);
			temp = temp->nextNode;
		}
	}
}



