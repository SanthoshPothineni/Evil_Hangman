#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	hString = my_string_init_default();

	if(hString == NULL)
	{
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
				"my_string_init_default returns NULL", length);
		return FAIL;
	}

	else
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString)!=0)
	{
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not recieve 0 from get_size after init_default\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_get_size_on_init_default_returns_0\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_spothine_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_capacity(hString)!=7)
	{
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not recieve 7 from get_capacity after init_default\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_get_capacity_on_init_default_returns_7\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_spothine_push_back_adds_char(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING TestString = NULL;
	Status status;

	hString = my_string_init_c_string("test");
	TestString = my_string_init_c_string("testing");
	my_string_push_back(hString, 'i');
	my_string_push_back(hString, 'n');
	my_string_push_back(hString, 'g');

	if(my_string_compare(hString, TestString) !=  0)
	{
		printf("Expected string testing but got %s\n", my_string_c_str(hString));
		strncpy(buffer, "test_spothine_push_back_adds_char\n"
				"Did not recieve appended string from push_back after init_default\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_push_back_adds_char\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString);
	my_string_destroy(&TestString);
	return status;
}

Status test_spothine_pop_back_removes_char(char* buffer, int length)
{
	
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	my_string_push_back(hString, 'T');
	my_string_push_back(hString, 'E');
	my_string_push_back(hString, 'S');
	my_string_push_back(hString, 'T');

	my_string_pop_back(hString);
	my_string_pop_back(hString);
	my_string_pop_back(hString);
	my_string_pop_back(hString);

	if(my_string_empty(hString) == 0)
	{
		printf("Expected string to be empty after pop back");
		strncpy(buffer, "test_spothine_pop_back_removes_char\n"
				"Did not recieve changed  string from pop_back after init_default\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_pop_back_removes_char\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString);
	return status;
}

Status test_spothine_concat_size_is_str1_plus_str2(char* buffer, int length)
{
	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	int test_size;
	Status status;

	hString1 = my_string_init_c_string("test");
	hString2 = my_string_init_c_string("worked");
	
	test_size = my_string_get_size(hString1) + my_string_get_size(hString2);
	my_string_concat(hString1, hString2);

	if(my_string_get_size(hString1) != test_size)
	{
		printf("Expected concatanated string to have size %d  but got %d\n",test_size,  my_string_get_size(hString1));
		strncpy(buffer, "test_spothine_concat_size_is_str1_plus_str2\n"
				"Size of string recieved from concat is not sames as strings combined\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_concat_size_is_str1_plus_str2\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;

}

Status test_spothine_string_at_negitive_is_NULL(char* buffer, int length)
{

	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Test");
	if(my_string_at(hString, -1) != NULL)
	{
		printf("Expected string at negative index to be NULL");
		strncpy(buffer, "test_spothine_string_at_negative_is_NULL\n"
				"Did not recieve NULL from my_string_at negative index\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_string_at_negative_is_NULL\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;

}

Status test_spothine_compare_str1_bigger_str2_returns_num_greater_than_0(char* buffer, int length)
{
	
	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_c_string("Testing");
	hString2 = my_string_init_c_string("Test");
	if(my_string_compare(hString1, hString2) <= 0)
	{
		printf("Expected number greater than 0 to be returned when str1 is bigger than str2");
		strncpy(buffer, "test_spothine_str1_bigger_str2_returns_num_greater_than_0\n"
				"Did not recieve positive from my_string_compare when str1 is bigger than str2\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_str1_bigger_str2_returns_num_greater_than_0\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test_spothine_compare_Str1_same_as_str2_returns_0(char* buffer, int length)
{

	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_c_string("Test");
	hString2 = my_string_init_c_string("Test");
	if(my_string_compare(hString1, hString2) != 0)
	{
		printf("Expected 0 to be returned when str1 is same as str2");
		strncpy(buffer, "test_spothine_compare_Str1_same_as_str2_returns_0\n"
				"Did not recieve 0 from my_string_compare when str1 is same as str2\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_compare_Str1_same_as_str2_returns_0\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test_spothine_init_c_string_is_NULL_terminated(char* buffer, int length)
{

	
	MY_STRING hString = NULL;
	Status status;
	char c;

	hString = my_string_init_c_string("Test");
	c = *my_string_at(hString, 4);

	if(c != '\0')
	{
		printf("c-String is not NULL terminated");
		strncpy(buffer, "test_spothine_init_c_string_is_NULL_terminated\n"
				"Did not recieve NULL terminator from my_string_at size plus 1\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_init_c_string_is_NULL_terminated\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}

Status test_spothine_string_at_returns_correct_letter_at_index(char* buffer, int length)
{

	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Test");
	if(*(my_string_at(hString, 0)) != 'T')
	{
		printf("Expected char T at 0 index of Test string but got %c", *(my_string_at(hString, 0)));
		strncpy(buffer, "test_spothine_string_at_returns_correct_letter_at_index\n"
				"Did not recieve T from my_string_at 0 index\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_string_at_returns_correct_letter_at_index\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;

}

Status test_spothine_string_empty_returns_false_for_non_empty_string(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Test");
	if(my_string_empty(hString) == 1)
	{
		
		printf("Expected false for is the string empty but got true");
		strncpy(buffer, "test_spothine_string_empty_returns_false_for_non_empty_string\n"
				"Did not recieve false from my_string_is_empty for a test string\n", length);
		status = FAIL;
	}
	else
	{
		strncpy(buffer, "test_spothine_string_empty_returns_false_for_non_empty_string\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}
Status test_spothine_get_size_returns_correct_size_of_c_string(char* buffer, int length)
{

	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("test");

	if(my_string_get_size(hString)!= 4)
	{
		printf("Expected a size of 4 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_spothine_get_size_returns_correct_size_of_c_string\n"
				"Did not recieve correct size from get_size after init_c_string\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_get_size_returns_correct_size_of_c_string\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString);
	return status;
}
Status test_spothine_extraction_extracts_first_string_from_file(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString1 = NULL;
	hString = my_string_init_default();
	hString1 = my_string_init_c_string("test");
	Status status;
	FILE* fp;
	fp = fopen("test.txt", "r");
	if(fp == NULL)
	{
		printf("Failed to open file");
		return FAIL;
	}
	my_string_extraction(hString, fp);
	hString = my_string_c_str(hString);

	if(0)
	{
		printf("Expected correct string from file but got wrong string");
		strncpy(buffer, "test_spothine_extraction_extracts_first_string_from_file\n"
				"Did not recieve correct string from file\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_extraction_extracts_first_string_from_file\n", length);
		status = SUCCESS;
	}

	fclose(fp);
	fp = NULL;
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	return status;
}
Status test_spothine_insertion_inserts_correct_string_into_file(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString1 = NULL;
	hString = my_string_init_default();
	hString1 = my_string_init_c_string("test");
	Status status;
	FILE* fp;
	fp = fopen("test.txt", "r");
	if(fp == NULL)
	{
		printf("Failed to open file");
		return FAIL;
	}
	my_string_extraction(hString, fp);

	if(0)
	{
		printf("Expected correct string from file but got wrong string\n");
		strncpy(buffer, "test_spothine_extraction_extracts_first_string_from_file\n"
				"Did not recieve correct string from file\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_insertion_inserts_correct_string_into_file\n", length);
		status = SUCCESS;
	}

	fclose(fp);
	fp = NULL;
	my_string_destroy(&hString);
	my_string_destroy(&hString1);
	return status;
}

Status test_spothine_concat_when_str2_is_empty_returns_fail(char* buffer, int length)
{

	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_default();
	hString2 = my_string_init_c_string("worked");

	if(my_string_concat(hString2, hString1) == SUCCESS)
	{
		printf("Expected concatanated string to fail when first str is empty");
		strncpy(buffer, "test_spothine_concat_when_str2_is_empty_returns_fail\n"
				"Concat when str1 is empty does not return fail\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_concat_when_str2_is_empty_returns_fail\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;

}

Status test_spothine_concat_when_str2_is_empty_does_not_change_str1(char* buffer, int length)
{

	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_default();
	hString2 = my_string_init_c_string("worked");
	
	my_string_concat(hString2, hString1);

	if(my_string_compare(hString2,hString2) != 0)
	{
		printf("Expected concatanated string to be same when second string is empty\n");
		strncpy(buffer, "test_spothine_concat_when_str2_is_empty_does_not_change_str1\n"
				"Concat when str2 is empty does not change str1\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_concat_when_str2_is_empty_does_not_change_str1\n", length);
		status = SUCCESS;
	}

	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;

}

Status test_spothine_compare_str1_str2_returns_positive_when_str1_is_bigger(char* buffer, int length)
{
	
	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_c_string("Testing");
	hString2 = my_string_init_c_string("Test");
	if(my_string_compare(hString1, hString2) <= 0)
	{
		printf("Expected positive number to be returned when str1 is bigger than str2");
		strncpy(buffer, "test_spothine_str1_str2_returns_positive_when_str1_is_bigger\n"
				"Did not recieve positive from my_string_compare when str1 is bigger than str2\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_compare_str1_str2_returns_positive_when_str1_is_bigger\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}

Status test_spothine_compare_str1_str2_returns_negative_when_str2_is_bigger(char* buffer, int length)
{
	
	MY_STRING hString1 = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString1 = my_string_init_c_string("Testing");
	hString2 = my_string_init_c_string("Test");
	if(my_string_compare(hString2, hString1) >= 0)
	{
		printf("Expected negative number to be returned when str2 is bigger than str1");
		strncpy(buffer, "test_spothine_compare_str1_str2_returns_negative_when_str2_is_bigger\n"
				"Did not recieve negative from my_string_compare when str2 is bigger than str1\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_compare_str1_str2_returns_negative_when_str2_is_bigger\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}
Status test_spothine_my_c_string_returns_a_c_string(char* buffer, int length)
{	
	MY_STRING hString = NULL;
	Status status;
	char* ch;

	hString = my_string_init_default();
	my_string_push_back(hString,'T');
	ch = my_string_c_str(hString);
	if(ch[1] != '\0')
	{
		printf("c-String is not returned");
		strncpy(buffer, "test_spothine_my_c_string_returns_a_c_string\n"
				"Did not recieve NULL terminated c_string from c_string function\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_my_c_string_returns_a_c_string\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}
Status test_spothine_my_string_at_index_of_more_than_string_returns_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Test");
	if(my_string_at(hString, 5) != NULL)
	{
		printf("Expected string at more than max index to be NULL");
		strncpy(buffer, "test_spothine_string_at_index_of_more_than_string_returns_NULL\n"
				"Did not recieve NULL from my_string_at ove max index\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_string_at_index_of_more_than_string_returns_NULL\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
	
}
Status test_spothine_my_string_at_for_empty_string_returns_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	if(my_string_at(hString, 0) != NULL)
	{
		printf("Expected empty string to be NULL\n");
		strncpy(buffer, "test_spothine_my_string_at_for_empty_string_returns_NULL\n"
				"Did not recieve NULL from my_string_at when string is empty\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_string_at_for_empty_string_returns_NULL\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
	
}

Status test_spothine_pop_back_for_empty_string_fails(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	if(my_string_pop_back(hString) != 0)
	{
		printf("Expected empty string to fail pop back\n");
		strncpy(buffer, "test_spothine_pop_back_for_empty_string_fails\n"
				"Did not recieve FAIL from my_string_pop_back when string is empty\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_pop_back_for_empty_string_fails\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}

Status test_spothine_string_get_capacity_for_c_string_is_one_more_than_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Test");
	if(my_string_get_capacity(hString) < my_string_get_size(hString) + 1)
	{
		printf("Capcity is not greater than size");
		strncpy(buffer, "test_spothine_string_get_capacity_for_c_string_is_one_more_than_size\n"
				"Capacity for c_string was not grater than size\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_get_capcity_for_c_string_is_one_more_than_size\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}


Status test_spothine_destroy_destroys_my_string(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("test");
	my_string_destroy(&hString);

	if(hString != NULL)
	{
		printf("Expected string to be destroyed\n");
		strncpy(buffer, "test_spothine_destroy_destroys_my_string\n"
				"Destroy did not destroy my string\n", length);
		status = FAIL;
	}

	else
	{
		strncpy(buffer, "\ttest_spothine_destroy_destroys_my_string\n", length);
		status = SUCCESS;
	}

	
	return status;
}
