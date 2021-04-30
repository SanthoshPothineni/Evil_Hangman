#include <stdio.h>
#include "unit_test02.h"
#include <string.h>
Status test_init_default_returns_nonNULL(char* buffer, int length){
    MY_STRING hString = NULL;

    hString = my_string_init_default();

    if(hString == NULL){
        strncpy(buffer, "test_init_default_returns_nonNULL\n \tmy_string_init_default returns NULL", length);
        return FAILURE;
    }
    else{
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n \tDid not receive 0 from get_size after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_get_capacity_on_init_default_returns_7(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_get_capacity(hString) != 7){
        status = FAILURE;
        printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_nwright_get_size_on_init_default_returns_7\n \tDid not receive 7 from get_capacity after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_get_size_on_init_default_returns_7\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_compare_on_init_default_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_compare(hString, hString) != 0){
        status = FAILURE;
        printf("Expected a result or 0 but got %d\n", my_string_compare(hString, hString));
        strncpy(buffer, "test_nwright_compare_on_init_default_returns_0\n \tDid not receive 0 from compare after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_compare_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_init_c_string_with_string_Hello(char* buffer, int length){
    MY_STRING hString = NULL;

    hString = my_string_init_c_string("Hello");

    if(hString == NULL){
        strncpy(buffer, "test_nwright_my_string_init_c_string_with_string_Hello\n \ttest_nwright_my_string_init_c_string_with_string_Hello returns NULL", length);
        return FAILURE;
    }
    else{
        my_string_destroy(&hString);
        strncpy(buffer, "\test_nwright_my_string_init_c_string_with_string_Hello\n", length);
        return SUCCESS;
    }
}
Status test_nwright_size_with_string_Hello_returns_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected a size of 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_size_with_string_Hello_returns_5\n \tDid not receive 5 from get_size with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_size_with_string_Hello_returns_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_capacity_with_string_Hello_returns_6(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");

    if(my_string_get_capacity(hString) == 6){
        status = FAILURE;
        printf("Expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_nwright_capacity_with_string_Hello_returns_6\n \tDid not receive 6 from get_capacity with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_capacity_with_string_Hello_returns_6\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_compare_with_string_Hello_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("Hello");

    if(my_string_compare(hString, hString) != 0){
        status = FAILURE;
        printf("Expected a result of 0 but got %d\n", my_string_compare(hString, hString));
        strncpy(buffer, "test_nwright_compare_with_string_Hello_returns_0\n \tDid not receive 0 from compare with string Hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_compare_with_string_Hello_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_extraction_and_insertion_using_simple(char* buffer, int length){
    MY_STRING hMy_string = NULL;
    FILE* fp;

    hMy_string = my_string_init_default();
    fp = fopen("simple.txt", "r");

    while(my_string_extraction(hMy_string, fp)){
        if(my_string_insertion(hMy_string, stdout) == FAILURE){
            return FAILURE;
        }
        printf(" ");
    }
    printf("\n");
    my_string_destroy(&hMy_string);
    fclose(fp);

    return SUCCESS;
}
Status test_nwright_push_back_with_init_default_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();

    if(my_string_push_back(hString, 'a') == FAILURE){
        status = FAILURE;
        printf("Expected SUCCESS but got FAILURE");
        strncpy(buffer, "test_nwright_push_back_with_init_default_returns_SUCCESS\n \tDid not receive SUCCESS with init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_push_back_with_init_default_returns_SUCCESS\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_push_back_with_init_default_updates_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');

    if(my_string_get_size(hString) != 1){
        status = FAILURE;
        printf("Expected a result of 1 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_push_back_with_init_default_updates_size\n \tDid not receive 1 from size with letter a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_push_back_with_init_default_updates_size\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');

    if(my_string_pop_back(hString) != 1){
        status = FAILURE;
        printf("Expected a result of SUCCESS but got FAILURE\n");
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success\n \tDid not receive SUCCESS from pop back with push back a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_returns_success\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_push_back(hString, 'a');
    my_string_pop_back(hString);

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected a result of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size\n \tDid not receive 0 from get size after pop back with push back a and init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_init_default_and_push_back_char_a_updates_size\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    my_string_push_back(hString, 'a');

    if(my_string_pop_back(hString) != 1){
        status = FAILURE;
        printf("Expected a result of SUCCESS but got FAILURE\n");
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success\n \tDid not receive SUCCESS from pop back with push back a and string of hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_success\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    my_string_push_back(hString, 'a');
    my_string_pop_back(hString);

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected a result of 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5\n \tDid not receive 5 from pop back with push back a and string of hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_pop_back_with_string_hello_and_push_back_char_a_returns_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_my_string_at_0_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, 0);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_0_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and 0\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_0_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_negative_1_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and -1\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_10_with_init_default_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_10_with_init_default_returns_NULL\n \tDid not receive Null from my string at with init default and 10\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_10_with_init_default_returns_NULL\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_0_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, 0);
    


    if(*c != 'h'){
        status = FAILURE;
        printf("Expected a result of h\n");
        strncpy(buffer, "test_nwright_my_string_at_0_with_string_hello\n \tDid not receive h from my string at with string hello and 0\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_0_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_my_string_at_negative_1_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, -1);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_string_hello\n \tDid not receive Null from my string at with string hello and -1\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_negative_1_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_my_string_at_10_with_string_hello(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_at(hString, 10);


    if(c != NULL){
        status = FAILURE;
        printf("Expected a result of Null\n");
        strncpy(buffer, "test_nwright_my_string_at_10_with_string_hello\n \tDid not receive Null from my_string_at with string hello and 10\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_my_string_at_10_with_string_hello\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_init_defaults_returns_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    char* c = my_string_c_str(hString);

    if(c == NULL){
        status = FAILURE;
        printf("Expected a string but got NULL\n");
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_returns_string\n \tDid not receive a string from my_string_c_str with init defaults\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_returns_string\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_init_defaults_has_size_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
   // char* c = my_string_c_str(hString);

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected size to be zero but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_has_size_0\n \tDid not receive a size of 0 from my_string_get_size after my_string_c_str with init defaults\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_init_defaults_has_size_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
Status test_nwright_c_str_with_string_hello_returns_string(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
    char* c = my_string_c_str(hString);

    if(c == NULL){
        status = FAILURE;
        printf("Expected a string but got NULL\n");
        strncpy(buffer, "test_nwright_c_str_with_string_hello_returns_string\n \tDid not receive a string from my_string_c_str with string hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_string_hello_returns_string\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_nwright_c_str_with_string_hello_has_size_5(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("hello");
   // char* c = my_string_c_str(hString);
   // c = NULL;

    if(my_string_get_size(hString) != 5){
        status = FAILURE;
        printf("Expected size to be 5 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_nwright_c_str_with_string_hello_has_size_5\n \tDid not receive a size of 5 from my_string_get_size after my_string_c_str with string hello\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_nwright_c_str_with_string_hello_has_size_5\n", length);
    }

    my_string_destroy(&hString);
    return status;
}
