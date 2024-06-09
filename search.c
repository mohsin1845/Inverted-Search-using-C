#include "main.h"
int search(main_node **hash)
{
    char word[20];
    printf(GREEN "Enter the word you want to search : " RESET);
    getchar();
    scanf("%[^\n]",word);
    int index= (toupper(word[0]) % 65);
    main_node *temp= hash[index];
    if(temp == NULL)
    {
	return FAILURE;
    }
    while(temp != NULL)
    {
	//check if words match or not
	if(strcmp(temp -> word, word) == 0)
	{  
            printf("-----------------------------------------\n");
            printf("The " YELLOW "'%s'" RESET " is present in  " YELLOW "'(%d)'"RESET "files\n", temp->word, temp->file_count);
	    sub_node *stemp= temp -> sublink;
	    while(stemp != NULL)
	    {
		printf("" YELLOW "%s " RESET "-> " YELLOW " %d " RESET "times\n", stemp->f_name, stemp->word_count);
		stemp = stemp->sublink;
	    }
	    printf("----------------------------------------\n" RESET);
	    return SUCCESS;
	}
	temp= temp -> mainlink;
    }
    return FAILURE;
}


