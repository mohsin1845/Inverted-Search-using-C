#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "colors.h"

/* MACRO definitions */
#define SUCCESS  1
#define FAILURE -1
#define DATA_NOT_FOUND 0

#define NAMELENGTH 50
#define SIZE 26


/* Typedefs definition */

//used for storing filenames as a list
typedef struct filename
{
    char filename[NAMELENGTH];
    struct filename *link;
}Slist;

//structure to store word details
typedef struct word
{
    int file_count;
    char word[NAMELENGTH];
    struct word *mainlink;
    struct file *sublink;
}main_node;

//structure to store filename
typedef struct file
{
    int word_count;
    char f_name[NAMELENGTH];
    struct file *sublink;
}sub_node;


/* Function Declarations for all the Operations */

/* File Validation */
int read_and_validate(Slist **head, int argc,char **argv);

/* Create hash table Database */
int create_hash_table(Slist *head,main_node **hash);

/* Display Database */
void display(main_node **hash);

/* Search Database */
int search(main_node **hash);

/* Save Database */
int save(main_node **hash);

/* Update Database */
int update(main_node **hash, Slist *head);

#endif

