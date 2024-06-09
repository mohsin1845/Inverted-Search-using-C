#include "main.h"

int read_and_validate(Slist **head, int argc, char **argv) {
    FILE *fptr;
    for (int i = 1; i < argc; i++) {
        if (strstr(argv[i], ".txt") != NULL) {
            fptr = fopen(argv[i], "r");
            if (fptr == NULL) {
                printf("ERROR: Could not open file %s\n", argv[i]);
                continue; // Skip this file and move to the next
            }
            fseek(fptr, 0, SEEK_END);
            if (ftell(fptr) > 0) {
                rewind(fptr); // Rewind the file pointer for future use
                Slist *new = malloc(sizeof(Slist));
                if (new == NULL) {
                    fclose(fptr);
                    printf("ERROR: Memory allocation failed\n");
                    continue; // Skip this file and move to the next
                }
                strcpy(new->filename, argv[i]);
                new->link = NULL;
                if (*head == NULL) {
                    *head = new;
                } else {
                    Slist *temp = *head;
                    int file_already_present = 0;
                    while (temp->link != NULL) {
                        if (strcmp(temp->filename, argv[i]) == 0) {
                            printf(RED "INFO: %s is already present"RESET, argv[i]);
                            free(new); // Free the allocated memory for new node
                            file_already_present = 1;
                            break;
                        }
                        temp = temp->link;
                    }
                    if (!file_already_present) {
                        if (strcmp(temp->filename, argv[i]) == 0) {
                            printf(RED "INFO: %s is already present"RESET, argv[i]);
                            free(new); // Free the allocated memory for new node
                        } else {
                            temp->link = new;
                        }
                    }
                }
            } else {
                printf(RED"INFO : %s File is empty\n", argv[i]);
            }
            fclose(fptr); // Close the file pointer here
        } else {
            printf(RED"INFO: %s is not a '.txt' file\n"RESET, argv[i]);
        }
    }
    return SUCCESS;
}

