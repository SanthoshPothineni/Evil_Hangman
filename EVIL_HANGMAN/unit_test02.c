#include <stdio.h>
#include "unit_test02.h"

int main(void){
    Status(*tests[])(char*, int) =
    {
        test_init_default_returns_nonNULL,
        test_get_size_on_init_default_returns_0,
        test_nwright_get_capacity_on_init_default_returns_7,
        test_nwright_compare_on_init_default_returns_0,
        test_nwright_my_string_init_c_string_with_string_Hello,
        test_nwright_size_with_string_Hello_returns_5,
       	test_nwright_capacity_with_string_Hello_returns_6,
        test_nwright_compare_with_string_Hello_returns_0,
        test_nwright_extraction_and_insertion_using_simple,
        test_nwright_push_back_with_init_default_returns_SUCCESS,
        test_nwright_push_back_with_init_default_updates_size,
        test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success,
        test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size,
        test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success,
        test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5,
        test_nwright_my_string_at_0_with_init_default_returns_NULL,
        test_nwright_my_string_at_negative_1_with_init_default_returns_NULL,
        test_nwright_my_string_at_10_with_init_default_returns_NULL,
        test_nwright_my_string_at_0_with_string_hello,
        test_nwright_my_string_at_negative_1_with_string_hello,
        test_nwright_my_string_at_10_with_string_hello,
        test_nwright_c_str_with_init_defaults_returns_string,
        test_nwright_c_str_with_init_defaults_has_size_0,
        test_nwright_c_str_with_string_hello_returns_string,
        test_nwright_c_str_with_string_hello_has_size_5
    };
    int number_of_functions = sizeof(tests)/sizeof(tests[0]);
    int i;
    char buffer[500];
    int success_count = 0;
    int failure_count = 0;

    for(i=0; i<number_of_functions; i++){
        if(tests[i](buffer, 500) == FAILURE){
            printf("FAILED: Test %d failed miserably\n", i);
            printf("\t%s\n", buffer);
            failure_count++;
            }
        else{
            // printf("PASS: Test %d passed\n", i);
            // printf("\t%s\n", buffer);
            success_count++;
            }
    }
    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count,
    number_of_functions, failure_count, number_of_functions);
    return 0;

}
