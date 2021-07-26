
#include "dict1.h"
#include <string.h>
#include <stdio.h>

void construct_node(char *curr, record *current_athlete, int row_index);
record *insert(record *root, record *curr_node, int is_linked);
void traverse_tree(record *root);
void print_node(record *node, FILE *output_file);
void search_tree(record *node, char *string, FILE *output_file, int comparisons, int found);
void copy_node(record *node1, record *node2);
record *new_node(record *old_node);

record *insert(record *root, record *curr_node, int is_linked){
    if(root == NULL){
        root = new_node(curr_node);
        return root;
    } else if (strcmp(curr_node->Name, root->Name) > 0){
        root->right = insert(root->right, curr_node, is_linked);
    } else {
        /* Add linked logic */
        if((strcmp(curr_node->Name, root->Name) == 0) && (is_linked == 1) ){
            /* Create the minified linked list */
            printf("linked\n");

        }
        root->left = insert(root->left, curr_node, is_linked);
    }
    return root;
}

void search_tree(record *root, char *string, FILE *output_file, int comparisons, int found){
    if(root == NULL){
        printf("%s --> %d\n", string, comparisons);
        if(found == 0){
            fprintf(output_file, "%s --> NOTFOUND\n", string);
        }
        return;
    }
    if(strcmp(root->Name, string) == 0){
        print_node(root, output_file);
        found = 1;
        comparisons++;
        search_tree(root->left, string, output_file, comparisons, found);
    } else if(strcmp(root->Name, string) > 0){
        comparisons++;
        search_tree(root->left, string, output_file, comparisons, found);
    } else {
        comparisons++;
        search_tree(root->right, string, output_file, comparisons, found);
    }
}

record *new_node(record *old_node){
    record *new_node = (record*)malloc(sizeof(record));
    copy_node(new_node, old_node);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}



void print_node(record *node, FILE *output_file){
    fprintf(output_file, "%s --> ID: %s || Age: %s || Sex: %s || Height: %s || Weight: %s || \
     Team: %s || NOC: %s || Games: %s || Year: %s || Season: %s || City: %s || \
     Sport: %s || Event: %s || Medal: %s ||\n ",
        node->Name,
        node->ID,
        node->Age,
        node->Sex,
        node->Height,
        node->Weight,
        node->TeamName,
        node->NOC,
        node->YearAndSeason,
        node->Year,
        node->Season,
        node->City,
        node->Sport,
        node->Event,
        node->Medal
    );
}

void copy_node(record *copy_to, record *copy_from){
    copy_to->ID = copy_from->ID;
    copy_to->Name = copy_from->Name;
    copy_to->Sex = copy_from->Sex;
    copy_to->Age = copy_from->Age;
    copy_to->Height = copy_from->Height;
    copy_to->Weight = copy_from->Weight;
    copy_to->TeamName = copy_from->TeamName;
    copy_to->NOC = copy_from->NOC;
    copy_to->YearAndSeason = copy_from->YearAndSeason;
    copy_to->Year = copy_from->Year;
    copy_to->Season = copy_from->Season;
    copy_to->City = copy_from->City;
    copy_to->Sport = copy_from->Sport;
    copy_to->Event = copy_from->Event;
    copy_to->Medal = copy_from->Medal;
}

void construct_node(char *curr, record *current_athlete, int row_index){
    switch(row_index){
        case 0:
            current_athlete->ID = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->ID, curr);
            break;
        case 1:
            current_athlete->Name = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Name, curr);
            break;
        case 2:
            current_athlete->Sex = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Sex, curr);
            break;
        case 3:
            current_athlete->Age = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Age, curr);
            break;
        case 4:
            current_athlete->Height = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Height, curr);
            break;
        case 5:
            current_athlete->Weight = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Weight, curr);
            break;
        case 6:
            current_athlete->TeamName = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->TeamName, curr);
            break;
        case 7:
            current_athlete->NOC = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->NOC, curr);
            break;
        case 8:
            current_athlete->YearAndSeason = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->YearAndSeason, curr);
            break;
        case 9:
            current_athlete->Year = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Year, curr);
            break;
        case 10:
            current_athlete->Season = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Season, curr);
            break;
        case 11:
            current_athlete->City = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->City, curr);
            break;
        case 12:
            current_athlete->Sport = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Sport, curr);
            break;
        case 13:
            current_athlete->Event = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Event, curr);
            break;
        case 14:
            current_athlete->Medal = (char*)malloc(sizeof(char)*(strlen(curr)+1));
            strcpy(current_athlete->Medal, curr);
            break;
    }
}
