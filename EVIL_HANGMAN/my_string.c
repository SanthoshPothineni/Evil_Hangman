#include<stdio.h>
#include<stdlib.h>
#include "my_string.h"
#include "generic.h"

struct my_string
{
	int size;
	int capacity;
	char* data;
};

typedef struct  my_string My_string;

MY_STRING my_string_init_default()
{
	My_string* pMy_string;
	pMy_string = (My_string*)malloc(sizeof(My_string));

	if(pMy_string != NULL)
	{
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);
		if(pMy_string->data == NULL)
		{
			free(pMy_string);
			return NULL;
		}
	}
	return pMy_string;
}

void my_string_destroy(ITEM* pItem)
{
	My_string* pMy_string = (My_string*) *pItem;
	if(*pItem != NULL)
	{
		free(pMy_string->data);
		free(pMy_string);
		*pItem = NULL;
	}
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	My_string* pMy_string;
	pMy_string = (My_string*)malloc(sizeof(My_string));

	int size = 0;
	while(c_string[size] != '\0')
	{
		size ++;
	}

	if(pMy_string != NULL)
	{
		pMy_string->size = size;
		pMy_string->capacity = size + 5;
		pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);

		if(pMy_string->data == NULL)
		{
			free(pMy_string->data);
			return NULL;
		}

		for(int i = 0; i <= pMy_string->size; i++)
		{
			pMy_string->data[i] = c_string[i];
		}
	}

	return pMy_string;
}


int my_string_get_capacity(MY_STRING hMy_string)
{	
	My_string* pMy_string;
	pMy_string = (My_string*)hMy_string;

	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pMy_string;
	pMy_string = (My_string*)hMy_string;

	return pMy_string->size;
}

int my_string_compare(MY_STRING left, MY_STRING right)
{
	int i;
	My_string* real_left = (My_string*)left;
	My_string* real_right = (My_string*)right;
	if (left == NULL && right != NULL)
	{
		return 1;
	}
	if (left != NULL && right == NULL)
	{
		return -1;
	}
	if (left == NULL && right == NULL)
	{
		return 0;
	}
	if (real_left->size == real_right->size)
	{
		for (i = 0; i < real_left->size; i++)
		{
			if (real_left->data[i] != real_right->data[i])
			{
				//return real_left->data[i] - real_right->data[i];
				return real_right->data[i] - real_left->data[i];
			}
		}
		return 0;
	}
	else if (real_left->size > real_right->size)
	{
		for (i = 0; i < real_right->size; i++)
		{
			if (real_left->data[i] != real_right->data[i])
			{
				return real_right->data[i] - real_left->data[i];
			}
		}
		return 1;
	}
	else if (real_left->size < real_right->size)
	{
		for (i = 0; i < real_left->size; i++)
		{
			if (real_left->data[i] != real_right->data[i])
			{
				return real_right->data[i] - real_left->data[i];
			}
		}
		return -1;
	}
	return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*)hMy_string;
	pMy_string->size = 0;
	char c;
	char* temp;
	int i = 0;
	int j = 0;
	
	c = fgetc(fp);
	if( c == ' ')
	{
		c = fgetc(fp);
	}
	while( c != EOF  && c != ' ' && c != '\n')
	{
		if(pMy_string->size >= pMy_string->capacity)
		{
			temp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
			if(temp == NULL)
			{
				return FAILURE;
			}

			pMy_string->capacity = pMy_string->capacity * 2;

			for(j = 0; j < pMy_string->size; j++)
			{
				temp[j] = pMy_string->data[j];
			}

			free(pMy_string->data);
			pMy_string->data = temp;
		}



		pMy_string->data[i] = c;
		c = fgetc(fp);
		i++;
		pMy_string->size++;
	}

	if(c == ' ' && pMy_string->size != 0)
	{
		ungetc(c, fp);
	}
	
	else if(pMy_string->size == 0)
	{
		return FAILURE;
	}

	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*)hMy_string;
	int i = 0;
	if(pMy_string->size == 0)
	{
		return FAILURE;
	}
	
	for(i = 0; i < pMy_string->size; i++)
	{
		fputc(pMy_string->data[i], fp);
	}

	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pMy_string = (My_string*)hMy_string;
	char* temp;
	int i;

	if(pMy_string->size >= pMy_string->capacity)
	{
		temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
		if(temp == NULL)
		{
			return FAILURE;
		}
		for(i = 0; i < pMy_string->size; i++)
		{
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity = pMy_string->capacity * 2;
	}

	pMy_string->data[pMy_string->size] = item;
	pMy_string->size++;

	return SUCCESS;
}
Status my_string_pop_back(MY_STRING hMy_string)
{

	My_string* pMy_string = (My_string*)hMy_string;
	if(my_string_empty(hMy_string))
	{
		return FAILURE;
	}
	pMy_string->size--;
	return SUCCESS;
}
char* my_string_at(MY_STRING hMy_string, int index)
{
	char* value = NULL;

	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size == 0)
	{
		return NULL;
	}
	if(index >=  0 &&  index <=  pMy_string->size)
	{
		value = &(pMy_string->data[index]);
	}

	return value;
}
char* my_string_c_str(MY_STRING hMy_string)
{
	char* temp;
	int i;
	My_string* pMy_string = (My_string*)hMy_string;

	if(pMy_string->size + 1 >= pMy_string->capacity)
	{
		temp = (char*)malloc(sizeof(char)*(pMy_string->capacity + 1));
		if(temp == NULL)
		{
			return NULL;
		}
		for(i = 0; i < pMy_string->size; i++)
		{
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity = pMy_string->capacity + 1;
	}

	pMy_string->data[pMy_string->size] = '\0';
	return pMy_string->data;

}
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{	
	My_string* pResult = (My_string*)hResult;
	My_string* pAppend = (My_string*)hAppend;
	int i = 0;
	int total_size = pResult->size + pAppend->size + 1;
	int total_capacity = total_size + 1;
	int j = pResult->size + 1;
	char* temp;

	if(my_string_empty(hAppend))
	{
		return FAILURE;
	}

	else if(my_string_empty(hResult))
	{
		if(pAppend->size > pResult->size)
		{	
			temp = (char*)malloc(sizeof(char)*(pAppend->capacity));
			if(temp == NULL)
			{	
				return FAILURE;
			}	
			for(i = 0; i < pResult->size; i++)
			{	
				temp[i] = pResult->data[i];
			}
			free(pResult->data);
			pResult->data = temp;
			pResult->capacity = pAppend->capacity;
		}

		for(i = 0; i < pAppend->size; i++)
		{
			pResult->data[i] = pAppend->data[i];
		}
		pResult->size = pAppend->size;
		pResult->capacity = pResult->size + 1;
	}

	else
	{
		temp = (char*)malloc(sizeof(char) * total_capacity + 1);
		if(temp != NULL)
		{
			for(i = 0; i < pResult->size; i++)
			{
				temp[i] = pResult->data[i];
			}

			for(i = 0; i < pAppend->size; i++)
			{
				temp[i + j] = pAppend->data[i];
			}

			temp[total_size + 1] = '\0';
			free(pResult->data);
			pResult->data = temp;
			pResult->capacity = total_capacity;
			pResult->size = total_size;

		}
		else 
		{
			free(temp);
			return FAILURE;
		}
		
	}

	return SUCCESS;
}


Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if(pMy_string->size <= 0)
	{
		return TRUE;
	}
	return FALSE;
}

Status my_string_assignment(ITEM* pLeft, ITEM Right)
{
	int i;
	My_string* phLeft = (My_string*)*pLeft;
	My_string* pRight = (My_string*)Right;

	if (phLeft == NULL)
	{
		phLeft = (My_string*)my_string_init_default();
	}
	if (phLeft != NULL && pRight != NULL)
	{

		if (my_string_get_capacity((MY_STRING)phLeft) < pRight->size) //make sure we have room
		{
			phLeft->capacity = pRight->size;
			char* temp = (char*)malloc(sizeof(char) * phLeft->capacity);
			if(temp == NULL)
			{
				return FAILURE;
			}
			free(phLeft->data);
			phLeft->data = temp;
		}

		phLeft->size = pRight->size;

		for (i = 0; i < phLeft->size; i++)
		{
			phLeft->data[i] = pRight->data[i];
		}
		*pLeft = phLeft;

		return SUCCESS;
	}
	return FAILURE;
}

