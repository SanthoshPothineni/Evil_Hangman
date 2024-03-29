#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "my_string.h"

struct generic_vector  //the known type
{
	int size;
	int capacity;
	ITEM* data;
	void (*item_destroy)(ITEM* phItem);
	Status (*item_assignment)(ITEM* pLeft, ITEM right);

};
typedef struct generic_vector Generic_vector;

GENERIC_VECTOR generic_vector_init_default(
	Status(*item_assignment)(ITEM* pLeft, ITEM right),
	void (*item_destroy)(ITEM* phItem))
{
	int i;
	Generic_vector* pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
		for (i = 0; i < pVector->capacity; i++)
		{
			pVector->data[i] = NULL;
		}
		pVector->item_assignment = item_assignment;
		pVector->item_destroy = item_destroy;
	}
	return (GENERIC_VECTOR)pVector;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->capacity;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	ITEM* temp;
	int i;

	//if there is not enough room then make room.
	if (pVector->size >= pVector->capacity)
	{
		temp = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		//the rest of the thing...
		pVector->capacity *= 2;
		for (;i<pVector->capacity;i++)
		{
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}
	//BROKEN
	//pVector->data[pVector->size] = value;
	pVector->item_assignment(&(pVector->data[pVector->size]), value);
	pVector->size++;
	return SUCCESS;
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (generic_vector_empty(hVector))
	{
		return FAILURE;
	}
	pVector->item_destroy(&(pVector->data[pVector->size - 1]));
	pVector->size--;
	return SUCCESS;
}

Boolean generic_vector_empty(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (pVector->size <= 0)
	{
		return TRUE;
	}
	return FALSE;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	//is it out of bounds?
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}

	return (pVector->data[index]);
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
	Generic_vector* pVector = (Generic_vector*)*phVector;
	int i;
	//destroy all of the objects in the vector
	for (i = 0; i < pVector->size; i++)
	{
		pVector->item_destroy(&(pVector->data[i]));
	}

	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

Status generic_vector_assignment(ITEM* pLeft, ITEM Right)
{
	int i;
	ITEM* temp;
	Generic_vector* phLeft = (Generic_vector*)*pLeft;
	Generic_vector* pRight = (Generic_vector*)Right;

	if (phLeft == NULL && pRight != NULL)
	{
		phLeft = (Generic_vector*)generic_vector_init_default(my_string_assignment, my_string_destroy);
		if (phLeft == NULL)
		{
			return FAILURE;
		}
	}
	if (pRight == NULL)
	{
		return FAILURE;
	}

	if (phLeft->capacity < pRight->size) //make sure we have room
	{
		
		phLeft->capacity = pRight->size;
		temp = (ITEM*)malloc(sizeof(ITEM) * phLeft->capacity);

		if (temp == NULL)
		{
			fprintf(stderr, "I ran out of memory and I give up...\n");
			exit(1);
		}
		for (i = 0; i < phLeft->capacity; i++)
		{
			temp[i] = NULL;
		}
		free(phLeft->data);
		phLeft->data = temp;

	}

	phLeft->size = pRight->size;

	for (i = 0; i < phLeft->size; i++)
	{
		phLeft->item_assignment(&(phLeft->data[i]), pRight->data[i]);
	}
	*pLeft = phLeft;

	return SUCCESS;
}

