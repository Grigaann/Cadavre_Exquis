//
// Created by Fenrisúlfr on 30/10/2022.
//
#include "node.h"


//NODE PART

int exists(t_node* node){
    return node != NULL;
}

//function that initialize a node and returns a pointer this one
p_node create_node(char character) {
    p_node ptr_node = malloc(sizeof(t_node));
    ptr_node->character = character;
    ptr_node->word = NULL;
    ptr_node->children = create_list();

    return ptr_node;
}


// LIST PART

//function to initialize a std_list with a first = NULL
t_std_list create_list() {
    t_std_list list;
    list.first = NULL;
    return list;
}


//function to add a cell at the end of a given std_list
p_cell add_cell(t_std_list list, char character) {

    //these 3 lines initialize the cell
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->character = character;
    new_cell->next = NULL;
    new_cell->next_node = create_node(character);


    //the following lines permits to add the brand-new cell at the end of the given std_list
    if (list.first != NULL) {
        p_cell current_cell = list.first;
        while (current_cell->next != NULL) {
            current_cell = current_cell->next;
        }
        current_cell->next = new_cell;
    } else {
        list.first = new_cell;
    }

    return new_cell;
}

// Function that finds the number of cells in a given list
int get_length(t_std_list list){
    int cpt = 0;
    p_cell cell = list.first;
    while (cell){
        cell = cell->next;
        cpt++;
    }
    return cpt;
}