#include "main.h"
int update(main_node **hash,Slist *head)
{
    char newfile[100], c;
    int index;
    printf(GREEN"Enter the file name to update : "RESET);
    scanf("%s", newfile); // reading the new file from user
    FILE *fptr = fopen(newfile, "r");
    // if check file is exist or not
    if (fptr == NULL)
    {
        printf(RED"INFO: File not found\n"RESET);
        return FAILURE;
    }
    // Check if the file already exists in the list
    Slist *temp = head;
    while (temp != NULL)
    {
        if (strcmp(newfile, temp->filename) == 0)
        {
            printf(RED"INFO: The file '%s' is already in the database\n"RESET,newfile);
            return FAILURE;
        }
        temp = temp->link;
    }
     // Create a new node for the file and add it to the list
    Slist *new_node = (Slist *)malloc(sizeof(Slist));
    if (new_node == NULL)
    {
        printf("ERROR: Memory allocation failed\n");
        return FAILURE;
    }
    strcpy(new_node->filename, newfile);
    new_node -> link = NULL;
    head = new_node;
       // Update the hash table with the new file
    if (create_hash_table(new_node, hash) == FAILURE)
    {
        printf(RED"ERROR: Failed to update the hash table\n"RESET);
        return FAILURE;
    }

    printf(""GREEN"INFO: Database updated with the file "RESET""YELLOW"'%s'"RESET"\n", newfile);
    return SUCCESS;
}





