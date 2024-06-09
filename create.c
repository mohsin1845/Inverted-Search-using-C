#include "main.h"
int create_hash_table(Slist *head,main_node **hash)
{
     int i=0;
    //Slist *temp=head;
    while(head != NULL)
    {
	FILE *fptr=fopen(head -> filename,"r");
        //printf("FILE %d is opened\n",i++);
	char word[20];
	while(fscanf(fptr,"%s",word) != EOF)
	{
	    //generate index
	    int ind=(toupper(word[0] ) % 65);
	   // printf("%d\n",ind);//----------------------------------
	    if(hash[ind] == NULL)
	    {
		main_node *main_new=malloc(sizeof(main_node));
		if(main_new == NULL)
		    return FAILURE;
		//copy word to main node member 
		strcpy(main_new -> word,word);
		main_new -> file_count=1;
		main_new -> mainlink=NULL;
		sub_node *snew=malloc(sizeof(sub_node));
		if(snew == NULL)
		    return FAILURE;
		snew -> word_count = 1;
		strcpy(snew -> f_name,head -> filename);
		snew -> sublink= NULL;
		main_new -> sublink = snew;
		hash[ind] = main_new;
               // printf("%ld\n",hash[ind]);
	    }
	    else
	    {
		main_node *MT= hash[ind];
		main_node *prev_main=NULL;
                int flag=0;
		while(MT != NULL)
		{
                      
		    //check if words are same
		     if(strcmp(MT->word,word) == 0)
	             {
                         flag=1;
			 sub_node *ST=MT -> sublink;
			 sub_node *prev_ST=NULL;
			 while(ST != NULL)
			 {
			     //check matched words are in same file or not
			     if(strcmp(head -> filename, ST -> f_name) == 0)
			     {
				 ST -> word_count++;
				 break;
			     }
			     //travese till it reaches null
			     prev_ST=ST;
			     ST=ST -> sublink;
			 }
			 //check matched  words are in different files
			 if(ST == NULL)
			 {
			     sub_node *snew=malloc(sizeof(sub_node));
			     snew -> word_count =1;
			     strcpy(snew -> f_name,head -> filename);
			     snew -> sublink =NULL;
			     MT -> file_count++;
			     prev_ST -> sublink =snew;
			 }

		     }
		         prev_main=MT;
		         MT=MT -> mainlink;
		}
		// if words are different
		if(flag==0)
		{
		    //create main node
		    main_node *Mnew=malloc(sizeof(main_node));
		    //validate main node is created or not
		    if(Mnew == NULL)
			return FAILURE;
		    //create subnode
		    sub_node *snew=malloc(sizeof(sub_node));
		    //validate sub node is created or not
		    if(snew == NULL)
			return FAILURE;
		    Mnew ->file_count=1;
		    strcpy(Mnew -> word,word);
		    Mnew -> mainlink =NULL;
		    Mnew -> sublink =snew;
		    snew -> word_count =1;
		    strcpy(snew -> f_name, head -> filename);
		    snew -> sublink =NULL;
		    prev_main -> mainlink =Mnew;
		}
   
	    }
	}
        fclose(fptr);
        head=head->link;
    }
    return SUCCESS;
}




