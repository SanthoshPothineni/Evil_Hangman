#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
	Status(*test[])(char*, int)=
	 {
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_spothine_get_capacity_on_init_default_returns_7,
		test_spothine_push_back_adds_char,
		test_spothine_pop_back_removes_char,
		test_spothine_concat_size_is_str1_plus_str2,
		test_spothine_destroy_destroys_my_string,
		test_spothine_string_at_negitive_is_NULL,
		test_spothine_compare_str1_bigger_str2_returns_num_greater_than_0,
		test_spothine_compare_Str1_same_as_str2_returns_0,
		test_spothine_init_c_string_is_NULL_terminated,
		test_spothine_string_at_returns_correct_letter_at_index,
		test_spothine_string_empty_returns_false_for_non_empty_string,
		test_spothine_get_size_returns_correct_size_of_c_string,
		test_spothine_extraction_extracts_first_string_from_file,
		test_spothine_insertion_inserts_correct_string_into_file,
		test_spothine_concat_when_str2_is_empty_returns_fail,
		test_spothine_concat_when_str2_is_empty_does_not_change_str1,
		test_spothine_compare_str1_str2_returns_positive_when_str1_is_bigger,
		test_spothine_compare_str1_str2_returns_negative_when_str2_is_bigger,
		test_spothine_my_c_string_returns_a_c_string,
		test_spothine_my_string_at_index_of_more_than_string_returns_NULL,
		test_spothine_my_string_at_for_empty_string_returns_NULL,
		test_spothine_pop_back_for_empty_string_fails,
		test_spothine_string_get_capacity_for_c_string_is_one_more_than_size
	 };
	
	int number_of_functions = sizeof(test)/sizeof(test[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;


	for(i = 0; i < number_of_functions; i++)
	{
		if(test[i](buffer, 500) == FAIL)
		{
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else
		{
			printf("PASS: Test %d passed\n", i);
			printf("\t%s\n", buffer);
			success_count++;
		}
	}
	printf("Total number of tests:%d\n", number_of_functions);
	printf("%d/%d pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
	return 0;
}

