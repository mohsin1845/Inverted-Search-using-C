#include "main.h"

void display(main_node **hash) {
      printf (CYAN "\n-----------------------------------------------------------------------\n" RESET);
    printf(YELLOW"%-8s %-15s %-15s %-15s %-10s\n", "Index", "Word", "Filecount", "Files Name", "Wordcount"RESET);
    printf (CYAN "-----------------------------------------------------------------------\n" RESET);
    

    for (int i = 0; i < SIZE; i++) {
        if (hash[i] != NULL) {
            main_node *temp = hash[i];
            while (temp) {
                // Print the main node details
                printf(GREEN "[%02d]     %-19s %-11d" RESET, i, temp->word, temp->file_count);

                sub_node *subtemp = temp->sublink;
                if (subtemp) {
                    // Print the first sub-node inline with the main node
                    printf(GREEN" %-15s %-10d\n"RESET, subtemp->f_name, subtemp->word_count);
                    printf (CYAN "-----------------------------------------------------------------------\n" RESET);
                    subtemp = subtemp->sublink;
                    
                } else {
                    printf("\n");
                }

                // Print remaining sub-nodes, properly aligned
                while (subtemp) {
                    printf(WHITE"%-40s %-15s %-10d\n"RESET, "", subtemp->f_name, subtemp->word_count);
                    printf (CYAN "-----------------------------------------------------------------------\n" RESET);
                    subtemp = subtemp->sublink;
                }
                temp = temp->mainlink;
            }
        }
    }
}

