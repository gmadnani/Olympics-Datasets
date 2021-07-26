#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/***************************************************************************/
int main(int argc, char **argv){

    FILE *input_file;
    char ch;
    int row_index;
    int data_index;
    int row_number;

    record *current_athlete = (record*)malloc(sizeof(record));
    char *curr = (char*)malloc(sizeof(char)*128);

    input_file = fopen("athlete_events_filtered_alternative.csv", "r");
    ch = fgetc(input_file);

    row_index = 0;
    data_index = 0;
    row_number = 0;

    while (row_number<10){
        if(ch == ',' || ch == '\n'){
            *(curr + data_index) = '\0';
            current_athlete->right = NULL;
            current_athlete->left = NULL;
            construct_node(curr, current_athlete, row_index);
            curr = realloc(curr, sizeof(char)*128);
            data_index = 0;

            if(ch == '\n'){
                printf("%s\n", current_athlete->Name);
                row_number++;
                row_index = 0;
                current_athlete = realloc(current_athlete, sizeof(record));
            } else {
                row_index++;
            }
        }
        else {
            *(curr + data_index) = ch;
            data_index++;
        }
        ch = fgetc(input_file);
    };


    fclose(input_file);
}
