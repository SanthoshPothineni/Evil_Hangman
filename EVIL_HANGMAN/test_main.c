#include<stdio.h>
#include<stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
	MY_STRING hMy_string1 = NULL;
	MY_STRING hMy_string2 = NULL;

	hMy_string1 = my_string_init_c_string("Banana");
	hMy_string2 = my_string_init_c_string("Apple");

	int i;
	char* c;
	char ch;
	for(i = 0; i <= my_string_get_size(hMy_string1); i++)
	{
		c = my_string_c_str(hMy_string1);
		printf("%c", c[i]);
	}
	printf("\n");
	my_string_push_back(hMy_string1, 's');


	for(i = 0; i <= my_string_get_size(hMy_string1); i++)
	{
		c = my_string_c_str(hMy_string1);
		printf("%c", c[i]);
	}
	printf("\n");


	for(i = 0; i <= my_string_get_size(hMy_string2); i++)
	{
		ch = *(my_string_at(hMy_string2, i));
		printf("%c", ch);
	}
	printf("\n");

	my_string_pop_back(hMy_string2);

	for(i = 0; i <= my_string_get_size(hMy_string2); i++)
	{
		c = my_string_c_str(hMy_string2);
		printf("%c", c[i]);
	}
	printf("\n");

	my_string_concat(hMy_string1, hMy_string2);

	for(i = 0; i <= my_string_get_size(hMy_string1); i++)
	{
		c = my_string_c_str(hMy_string1);
		printf("%c", c[i]);
	}
	printf("\n");



	
	my_string_destroy(&hMy_string1);
	my_string_destroy(&hMy_string2);
	return 0;
}	


