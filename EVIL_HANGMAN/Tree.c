#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "my_string.h"
#include "generic_vector.h"

#define max(a,b) ((a)>(b) ? (a) : (b))

struct node;
typedef struct node Node;

struct node
{
	Node* left;
	Node* right;
	int height;
	MY_STRING key;
	GENERIC_VECTOR bin;
};

struct tree
{
	Node* root;
};

typedef struct tree Tree;

int height(Node* N);
Node* newNode(MY_STRING key, MY_STRING word);
Node* rightRotate(Node* head);
Node* leftRotate(Node* head);
void getLargestVector(Node* head, Node** big, int biggest);
//void getLargestVector(Node* head, int biggest, MY_STRING* input);
int vectorSize(Node* head);
int getBalance(Node* node);
Node* insert(Node* node, MY_STRING key, MY_STRING temp_word);
void print(Node* root);
Node* search(Node* root, MY_STRING key);
int maxthree(int a, int b, int c);
void destroy(Node* root);

TREE tree_init_default(void)
{
	Tree* pTree = (Tree*)malloc(sizeof(Tree));
	if (pTree != NULL)
	{
		pTree->root = NULL;
	}
	return (TREE)pTree;
}

Boolean tree_search(TREE hTree, MY_STRING key)
{
	Tree* pTree = (Tree*)hTree;
	Node* temp = search(pTree->root, key);
	if (temp != NULL)
	{
		return TRUE;
	}
	return FALSE;
}

Status tree_insert(TREE hTree, MY_STRING key, MY_STRING temp_word)
{
	Tree* pTree = (Tree*)hTree;
	Node* temp;
	Boolean found = tree_search(hTree, key);
	if (pTree != NULL && found)
	{
		temp = (Node*)search(pTree->root, key);
		return generic_vector_push_back(temp->bin, temp_word);
	}
	if (pTree != NULL && !found)
	{
		pTree->root = insert(pTree->root, key, temp_word);
		if (pTree->root != NULL)
		{
			return SUCCESS;
		}
		return FAILURE;
	}
	return FAILURE;
	
}

void tree_print(TREE hTree)
{
	Tree* pTree = (Tree*)hTree;
	print(pTree->root);
}

void largest_vector(TREE* phTree , MY_STRING hMy_string, GENERIC_VECTOR* hVector)
{
	GENERIC_VECTOR largest;
	Node* temp;
	//GENERIC_VECTOR new_word_list = NULL;

	Tree* pTree = (Tree*)*phTree;
	//int i;

	temp = search(pTree->root, hMy_string);
	largest = temp->bin;
	generic_vector_assignment(hVector, largest);
		
	//new_word_list = generic_vector_init_default(my_string_assignment, my_string_destroy);
	/*for (i = 0; i < generic_vector_get_size(largest); i++)
	{
		generic_vector_push_back(new_word_list, generic_vector_at(largest, i));
	}*/
	//return new_word_list;
}

void tree_destroy(TREE* phTree)
{
	Tree* pTree = (Tree*)*phTree;
	if (pTree != NULL)
	{
		destroy(pTree->root);
		free(pTree);
		*phTree = NULL;
	}
}

void destroy(Node* root)
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		my_string_destroy(&(root->key));
		generic_vector_destroy(&(root->bin));
		free(root);
	}
}

int height(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}

	return node->height;
}

int getBalance(Node* node)
{
	if (node == NULL) 
	{
		return 0;
	}

	return height(node->left) - height(node->right);
}

Node* newNode(MY_STRING key, MY_STRING word)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp != NULL)
	{
		temp->key = NULL;
		my_string_assignment(&temp->key, key);
		temp->bin = generic_vector_init_default(my_string_assignment, my_string_destroy);
		generic_vector_push_back(temp->bin, word);
		temp->left = NULL;
		temp->right = NULL;
		temp->height = 1;
	}
		return temp;
}

Node* leftRotate(Node* head)
{
	Node* temp = (Node*)head;
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->right == NULL)
	{
		return NULL;
	}
	else
	{
		temp = head->right;
		head->right = temp->left;
		temp->left = head;
		head->height = max(height(head->left), height(head->right)) + 1;
		temp->height = max(height(temp->left), height(temp->right)) + 1;
	}
	return temp;
}

Node* rightRotate(Node* head)
{
	Node* temp = (Node*)head;
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->left == NULL)
	{
		return NULL;
	}
	else
	{
		temp = head->left;
		head->left = temp->right;
		temp->right = head;
		head->height = max(height(head->left), height(head->right)) + 1;
		temp->height = max(height(temp->left), height(temp->right)) + 1;
	}
	return temp;
}

Node* insert(Node* node, MY_STRING key, MY_STRING temp_word)
{

	//Insert into BST as usual
	if (node == NULL) {
		return(newNode(key, temp_word));
	}

	if (my_string_compare(key, node->key) < 0) 
	{
		node->left = insert(node->left, key, temp_word);
	}
	else if (my_string_compare(key, node->key) > 0)
	{
		node->right = insert(node->right, key, temp_word);
	}

	//Update height
	node->height = max(height(node->left), height(node->right)) + 1;

	//Get balance factor
	int balance = getBalance(node);

	if (balance > 1 && my_string_compare(key, node->key) < 0) 
	{
		return rightRotate(node);
	}

	if (balance < -1 && my_string_compare(key, node->key) > 0) 
	{
		return leftRotate(node);
	}


	if (balance > 1 && my_string_compare(key, node->key) > 0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}


	if (balance < -1 && my_string_compare(key, node->key) < 0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void print(Node* root)
{
	if (root != NULL)
	{
		printf("%s\t%d\t%d\n", my_string_c_str(root->key), generic_vector_get_size(root->bin), root->height);
		print(root->left);
		print(root->right);
	}
}

Node* search(Node* root, MY_STRING key)
{
	if (root == NULL) 
	{
		return NULL;
	}

	else if (my_string_compare(key, root->key) < 0)
	{
		return search(root->left, key);
	}
	else if (my_string_compare(key, root->key) > 0)
	{
		return search(root->right, key);
	}
	else if(my_string_compare(key, root->key) == 0)
	{
		return root;
	}
	return root;
}

int maxthree(int a, int b, int c)
{
	int maximum = a;
	if (b > maximum)
	{
		maximum = b;
	}
	if (c > maximum)
	{
		maximum = c;
	}
	return maximum;
}

int vectorSize(Node* head)
{
	int left, right, current;
	if (head == NULL)
	{
		return 0;
	}
	left = vectorSize(head->left);
	current = generic_vector_get_size(head->bin);
	right = vectorSize(head->right);
	return maxthree(left, right, current);
}

void my_tree_find_largest_vector(TREE hTree, MY_STRING* input)
{
	Tree* pTree = (Tree*)hTree;
	Node* temp;
	int biggest;
	if (pTree != NULL)
	{
		biggest = vectorSize(pTree->root);
		getLargestVector(pTree->root, &temp, biggest);
		*input = temp->key;
	}
}

void getLargestVector(Node* head, Node** big, int biggest)
{
	if (head == NULL)
	{
		return;
	}
	getLargestVector(head->left, big, biggest);
	if (generic_vector_get_size(head->bin) == biggest)
	{
		*big = head;
	}
	getLargestVector(head->right, big, biggest);
}

