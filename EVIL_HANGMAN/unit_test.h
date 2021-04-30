#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_spothine_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_spothine_push_back_adds_char(char* buffer, int length);
Status test_spothine_pop_back_removes_char(char* buffer, int length);
Status test_spothine_concat_size_is_str1_plus_str2(char* buffer, int length);
Status test_spothine_string_at_negitive_is_NULL(char* buffer, int length);
Status test_spothine_compare_str1_bigger_str2_returns_num_greater_than_0(char* buffer, int length);
Status test_spothine_compare_Str1_same_as_str2_returns_0(char* buffer, int length);
Status test_spothine_init_c_string_is_NULL_terminated(char* buffer, int length);
Status test_spothine_string_at_returns_correct_letter_at_index(char* buffer, int length);
Status test_spothine_string_empty_returns_false_for_non_empty_string(char* buffer, int length);
Status test_spothine_get_size_returns_correct_size_of_c_string(char* buffer, int length);
Status test_spothine_extraction_extracts_first_string_from_file(char* buffer, int length);
Status test_spothine_insertion_inserts_correct_string_into_file(char* buffer, int length);
Status test_spothine_concat_when_str2_is_empty_returns_fail(char* buffer, int length);
Status test_spothine_concat_when_str2_is_empty_does_not_change_str1(char* buffer, int length);
Status test_spothine_compare_str1_str2_returns_positive_when_str1_is_bigger(char* buffer, int length);
Status test_spothine_compare_str1_str2_returns_negative_when_str2_is_bigger(char* buffer, int length);
Status test_spothine_my_c_string_returns_a_c_string(char* buffer, int length);
Status test_spothine_my_string_at_index_of_more_than_string_returns_NULL(char* buffer, int length);
Status test_spothine_my_string_at_for_empty_string_returns_NULL(char* buffer, int length);
Status test_spothine_pop_back_for_empty_string_fails(char* buffer, int length);
Status test_spothine_string_get_capacity_for_c_string_is_one_more_than_size(char* buffer, int length);
Status test_spothine_destroy_destroys_my_string(char* buffer, int length);

#endif
