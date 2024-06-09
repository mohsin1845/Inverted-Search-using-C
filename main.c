/*
Name: Mohsin Mohiuddin
Date: 10 june 2024
Description: An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at the cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.
*/
#include "main.h"
int main(int argc, char *argv[])
{
    //array of pointers
    main_node *hash[SIZE]={NULL};
    //to store filenames as a list
    Slist *head=NULL;
    //checking for minimum arguments
    if(argc <= 1)
    {
	printf(RED "ERROR: Please Enter the Minimum arguments\n" RESET);
        printf (YELLOW "INFO: Usage ./inverted_search <file.txt> <file1.txt> ...\n" RESET);
	return 0;
    }
    // Validating file input

    if(read_and_validate(&head,argc,argv)== SUCCESS)
    {
        printf (CYAN "\n-------------------------------------------------------------\n" RESET);
	printf(GREEN "INFO  : File Validation Successful\n" RESET);
	int choice,flag=0;
	char ch;

	do
	{
            printf (CYAN "-------------------------------------------------------------\n" RESET);
	    printf(GREEN "Please choose the option\n1. Create Hash Table \n2. Display \n3. Search \n4. Save \n5. Update\n" RESET);
	    printf(GREEN "Please Enter the Choice :  "RESET);
	    scanf("%d",&choice);
            /* Create Database Operation for all the Files passed in the Command Line. */
	    switch(choice)
	    {
		case 1:
		    {
		    	//call create Hash Table function
	    	   	 if(flag == 0)
		         {
				if(create_hash_table(head,hash) == SUCCESS)
				{
                                   printf (CYAN "\n-------------------------------------------------------------\n" RESET);
			    	   printf(GREEN "INFO : Hash table created successfully\n"RESET);
                                   printf (CYAN "-------------------------------------------------------------\n" RESET);
			           flag=1; 
				}
		    	 }
			 else
			 {
                             printf (CYAN "\n-------------------------------------------------------------\n" RESET);
			     printf("INFO : HASH TABLE is already created\n");
                             printf (CYAN "-------------------------------------------------------------\n" RESET);
			 }


			 
		    	break;
		    }
		    
		case 2:
		    {
		    	//call Display Hash Table function
		    	display(hash);
		    	break;
		    }
		case 3:
		    {
		    	//call Search function
			 if(search(hash)== FAILURE)
			 {
                             printf (CYAN "\n-------------------------------------------------------------\n" RESET);
    			     printf(RED "INFO : No such word is present \n" RESET);
                             printf (CYAN "-------------------------------------------------------------\n" RESET);
                         }

		   	 break;
		    }
		case 4:
		    {
			//call save function
                        if(save(hash) == SUCCESS)
			{
                            printf (CYAN "\n-------------------------------------------------------------\n" RESET);
			    printf(CYAN "INFO : Database successfully saved\n" RESET);
                            printf (CYAN "-------------------------------------------------------------\n" RESET);
			}
			else
			{
			    printf(RED "INFO : Failed in saving database\n" RESET);
			}
			break;
		    }
		case 5: 
		    {
			//call update function
			if(update(hash,head) == SUCCESS)
                        {
                            printf (CYAN "\n-------------------------------------------------------------\n" RESET);
                            printf("INFO : Added Database successfully saved\n");
                            printf (CYAN "-------------------------------------------------------------\n" RESET);
                        }
			break;
		    }
		default:
		    printf(" Invalid Option \n");
	    }
	    printf(BLUE "Do you want to continue? press(Y/y)\n" RESET);
	    printf("Enter your choice: ");
            getchar();
	    scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
    }
}










