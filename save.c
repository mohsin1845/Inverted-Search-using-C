#include "main.h"
int save(main_node **hash)
{
    char str[30];
    printf(GREEN"Please enter the file name: "RESET);
    scanf(" %[^\n]", str);
    //check if file has ".txt" extension
   // if(strcmp(str, ".txt") != 0)
    char *dot = strstr(str, ".");
    if (dot == NULL || strcmp(dot, ".txt") != 0) {
        printf(RED"INFO : Only '.txt' files are allowed\n"RESET);
        return FAILURE;
    }
    //open file in write mode
    FILE *fptr=fopen(str, "w");
    for(int i=0;i<26;i++)
    {
	if(hash[i] != NULL)
	{
	    main_node *main_temp=hash[i];
	    while(main_temp != NULL)
	    {
		fprintf(fptr, "#"); // Write the # character
		fprintf(fptr, "%d;", i); // Write the hash index
		fprintf(fptr, "%s;", main_temp -> word); //write the word
		fprintf(fptr, "%d;", main_temp -> file_count);// write the file count for word
		
		sub_node *sub_temp=main_temp -> sublink;
		while(sub_temp)
		{
		    fprintf(fptr, "%s;",sub_temp -> f_name);// write the file name
		    fprintf(fptr, "%d;", sub_temp -> word_count);// write the word count in the file
		    sub_temp =sub_temp -> sublink; // Traverse to next sub node
		}
		main_temp = main_temp -> mainlink; //Traverse to next main node
		fprintf(fptr, "#\n"); // Add a separator and move to the next line
	    }
	}
	
    }
    fclose(fptr);
    return SUCCESS;
}
