#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_nwright_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_nwright_compare_on_init_default_returns_0(char* buffer, int length);
Status test_nwright_my_string_init_c_string_with_string_Hello(char* buffer, int length);
Status test_nwright_size_with_string_Hello_returns_5(char* buffer, int length);
Status test_nwright_capacity_with_string_Hello_returns_6(char* buffer, int length);
Status test_nwright_compare_with_string_Hello_returns_0(char* buffer, int length);
Status test_nwright_extraction_and_insertion_using_simple(char* buffer, int length);
Status test_nwright_push_back_with_init_default_returns_SUCCESS(char* buffer, int length);
Status test_nwright_push_back_with_init_default_updates_size(char* buffer, int length);
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success(char* buffer, int length);
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size(char* buffer, int length);
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success(char* buffer, int length);
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5(char* buffer, int length);
Status test_nwright_my_string_at_0_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_negative_1_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_10_with_init_default_returns_NULL(char* buffer, int length);
Status test_nwright_my_string_at_0_with_string_hello(char* buffer, int length);
Status test_nwright_my_string_at_negative_1_with_string_hello(char* buffer, int length);
Status test_nwright_my_string_at_10_with_string_hello(char* buffer, int length);
Status test_nwright_c_str_with_init_defaults_returns_string(char* buffer, int length);
Status test_nwright_c_str_with_init_defaults_has_size_0(char* buffer, int length);
Status test_nwright_c_str_with_string_hello_returns_string(char* buffer, int length);
Status test_nwright_c_str_with_string_hello_has_size_5(char* buffer, int length);

#endif
