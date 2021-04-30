#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "my_string.h"
#include "generic_vector.h"

typedef struct my_tree *TREE;

TREE tree_init_default(void);
Status tree_insert(TREE hTree, MY_STRING key, MY_STRING temp_word);
Boolean tree_search(TREE hTree, MY_STRING key);
void tree_print(TREE hTree);
//GENERIC_VECTOR largest_vector(TREE* phTree, MY_STRING hMy_string);
void largest_vector(TREE* phTree, MY_STRING hMy_string, GENERIC_VECTOR* hVector);
void my_tree_find_largest_vector(TREE hTree, MY_STRING* input);
void tree_destroy(TREE* phTree);



#endif

