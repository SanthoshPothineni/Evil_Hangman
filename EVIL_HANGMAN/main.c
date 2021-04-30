#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<time.h>
#include"my_string.h"
#include"generic_vector.h"
#include "Tree.h"


void clear_keyboard_buffer(void);
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);
Boolean alreadyGuessed(MY_STRING previous_guesses, char guess);
Boolean has_won(MY_STRING key, int word_size);

int main(int argc, char* argv[])
{
	const int MAX_WORD_LEN = 29;
	int i = 0;
	int len = 0;
	int word_length = 4;
	int noc;
   	int correctGuessCount = 0;
	char replay = 'y';
	FILE* fp;
	MY_STRING hString = my_string_init_default();
	GENERIC_VECTOR arr[30];

	for(i = 0; i <= MAX_WORD_LEN; i++)
	{
		arr[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
	}

	fp = fopen("dictionary.txt", "r");
	if(fp == NULL)
	{
		printf("Failed to open file\n");
		exit(1);
	}
	
	i = 0;
	while(my_string_extraction(hString, fp) == SUCCESS)
	{

		len = my_string_get_size(hString);
		if(0 < len && len <= MAX_WORD_LEN && hString != NULL)
		{
            generic_vector_push_back(arr[len], hString);
		}
	}

    printf("\n");
	/*for(i = 1; i <= MAX_WORD_LEN; i++) //Prints out how many of each word length there are
	{
		printf("%d: %d\n", i, generic_vector_get_size(arr[i]));
	}*/
	fclose(fp);
    

	do
	{
		srand((unsigned)(time(NULL)));
		printf("-= Evil Hangman =-\n");
		printf("What word length would you like to play with: ");
		noc = fscanf(stdin, "%d", &word_length);
		clear_keyboard_buffer();

		while (word_length == 0 ||word_length < 2 || word_length >29 || word_length == 27 || word_length == 26 || word_length == 23 || word_length == 25)
		{
			printf("Invalid word length.  Choose again: ");
			noc = fscanf(stdin, "%d", &word_length);
			clear_keyboard_buffer();
		}

        MY_STRING chosenLetters = my_string_init_default();
        MY_STRING key_initial = my_string_init_default();

        MY_STRING word_current = NULL;
        MY_STRING key_current = NULL;

        GENERIC_VECTOR wordListVector = generic_vector_init_default(my_string_assignment, my_string_destroy);
        
        TREE word_sets = NULL;

        Status status = SUCCESS;
        Boolean check_win = FALSE;

        int random = 0;
        int word_list_size = 0;
        int num_of_guess = 0;

        char guess = ' ';

        for (i = 0; i < word_length; i++)
        {
            my_string_push_back(key_initial, '-');
        }

        for (i = 0; i < generic_vector_get_size(arr[word_length]); i++)
        {
            generic_vector_push_back(wordListVector, generic_vector_at(arr[word_length], i));
        }

        printf("How many guesses would you like?\n");
        noc = scanf("%d", &num_of_guess);
        clear_keyboard_buffer();
        while (num_of_guess <= 0 || noc < 1)
        {
            printf("Invalid amount of guesses.  Enter a different number: \n");
            noc = scanf("%d", &num_of_guess);
            clear_keyboard_buffer();
        }
        while (num_of_guess > 0)
        {
            
            word_list_size = generic_vector_get_size(wordListVector);
            
            
            //printf("Words remaining: %d\n\n", word_list_size);//debug statement

            printf("Guesses Remaining: %d\n", num_of_guess);
            printf("Letters Chosen So Far: %s\n", my_string_c_str(chosenLetters));
            printf("Word: %s\n", my_string_c_str(key_initial));

            printf("\nEnter your guess: ");
            noc = fscanf(stdin, "%c", &guess);

            clear_keyboard_buffer();

            while (noc < 1 || !isalpha(guess))
            {
                printf("Error:  Invalid input\n");
                printf("Enter your guess: ");
                noc = fscanf(stdin, "%c", &guess);
                clear_keyboard_buffer();
            }

            printf("\n");
            guess = tolower(guess);

            if(!(alreadyGuessed(chosenLetters, guess)))
            {
                my_string_push_back(chosenLetters, guess);
                my_string_push_back(chosenLetters, ' ');
            }
            else
            {
                correctGuessCount = -1;
            }
            
            //create new tree to populate with based off guesses
            word_sets = tree_init_default();

            for (i = 0; i < word_list_size; i++)
            {
                key_current = my_string_init_default();
                word_current = generic_vector_at(wordListVector, i);
                get_word_key_value(key_initial, key_current, word_current, guess);
                status = tree_insert(word_sets, key_current, word_current);
                if (status == FAILURE)
                {
                    printf("Failed to insert word into Tree.\n");
                    exit(1);
                }
               my_string_destroy(&key_current);
               key_current = NULL;
            }
           // tree_print(word_sets);  //debug statement
            
            generic_vector_destroy(&wordListVector);  //destroy current word list
            my_tree_find_largest_vector(word_sets, &key_current);
            //printf("\n%s\n", my_string_c_str(key_current));//debug statement
            largest_vector(&word_sets, key_current, &wordListVector);
     
            random = rand() % generic_vector_get_size(wordListVector);
            word_current = generic_vector_at(wordListVector, random);  // select a random word from the new list
            key_current = my_string_init_default();
            get_word_key_value(key_initial, key_current, word_current, guess);  //generate a key based off the new word list

            my_string_assignment(&key_initial, key_current);//set initial to new key

            my_string_destroy(&key_current);

            tree_destroy(&word_sets); // destroy the game tree
            
            for (i = 0; i < word_length; i++)
            {
                if (*(my_string_at(key_initial, i)) == guess)
                {
                    correctGuessCount++;
                }
            }

               
            if (correctGuessCount > 0)
            {
                printf("\nLucky guess! There's a \'%c\' in the word!\n\n", guess);
            }
            else if (correctGuessCount < 0)
            {
                printf("\nLetter '%c' has already been played.  Choose again.\n\n", guess);
            }
            else
            {
                printf("\nBad choice!.\nThe letter \'%c\' is not in the selected word!\n\n", guess);
                num_of_guess--;
            }
            correctGuessCount = 0;

            check_win = has_won(key_initial, word_length);

            if (check_win == TRUE)
            {
                printf("Congratulations!, You definitely cheated!\n");
                printf("The word was: %s\n\n", my_string_c_str(word_current));
                break;
            }
            else if (num_of_guess <= 0)
            {
                random = rand() % generic_vector_get_size(wordListVector);
                printf("YOU LOSE! HA HA HA!\n");
                printf("The word was: %s\n\n", my_string_c_str((generic_vector_at(wordListVector, random))));
            }
        }
        my_string_destroy(&key_initial);
        my_string_destroy(&chosenLetters);
        generic_vector_destroy(&wordListVector);

		printf("Would you like to play again (y/n): ");
		noc = fscanf(stdin, " %c", &replay);

		while (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N')
		{
			printf("Would you like to play again (y/n): ");
			noc = fscanf(stdin, " %c", &replay);
		}
		printf("\n\n\n\n\n");

	} while (replay == 'y' || replay == 'Y');


	for(i = 0; i <= MAX_WORD_LEN; i++)
	{
		generic_vector_destroy(&arr[i]);
	}

	my_string_destroy(&hString);
	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;
	noc = scanf("%c", &c);
	while (c != '\n' && noc == 1)
	{
		noc = scanf("%c", &c);
	}
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    int word_length = my_string_get_size(word);
    int i;
    for (i = 0; i < word_length; i++)
    {
        if (*(my_string_at(word, i)) == guess)
        {
            my_string_push_back(new_key, guess);
        }

        else
        {
            my_string_push_back(new_key, *(my_string_at(current_word_family, i)));
        }

    }

    return SUCCESS;
}

Boolean alreadyGuessed(MY_STRING previous_guesses, char guess)
{
    int i;
    for (i = 0; i < my_string_get_size(previous_guesses); i++)
    {
        if (*(my_string_at(previous_guesses, i)) == guess)
        {
            return TRUE;
        }
    }
    return FALSE;
}

Boolean has_won(MY_STRING key, int word_size)
{
    int i = 0;
    int remainingLetters = 0;

    for (i = 0; i < word_size; i++)
        if (*(my_string_at(key, i)) == '-') remainingLetters++;

    return (remainingLetters == 0) ? TRUE : FALSE;
}

